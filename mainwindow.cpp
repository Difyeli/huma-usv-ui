#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connectionsettingsdialog.h"

#include <QtCharts/QChartView>
#include <QtCharts/QSplineSeries>
#include <QtCharts/QValueAxis>
#include <QToolTip>
#include <QCursor>
#include <QPainter>
#include <QComboBox>
#include <QDateTime>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QQuickItem>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QLabel>
#include <QTableWidgetItem>
#include <QDebug>
#include <QMetaObject>
#include <QVariantMap>
#include <QVariant>
#include <QMessageBox>
#include <QThread>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    serial(new QSerialPort(this)),
    speedChart(new QChart),
    setPointSeries(new QSplineSeries),
    actualSeries(new QSplineSeries),
    axisX(new QValueAxis),
    axisY(new QValueAxis),
    elapsedTime(0),
    currentPortName("COM8"),
    currentBaudRate(QSerialPort::Baud9600),
    csvFile(nullptr),
    csvStream(nullptr),
    recording(false)

{
    ui->setupUi(this);


    // — QML Harita
    ui->mapQuickWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);
    ui->mapQuickWidget->rootContext()->setContextProperty("backend", this);
    ui->mapQuickWidget->setSource(QUrl(QStringLiteral("qrc:/MapView.qml")));
    if (ui->mapQuickWidget->status() != QQuickWidget::Ready)
        qWarning() << ui->mapQuickWidget->errors();


    // mainwindow.cpp, QQuickWidget’i ayarladıktan sonra:
    QObject *root = ui->mapQuickWidget->rootObject();
    m_waypointModel = root->findChild<QObject*>("waypointModel");
    if (!m_waypointModel)
        qWarning() << "waypointModel bulunamadı!";



    // İlk durum
    ui->statusValueLabel->setText("Pasif");
    ui->portValueLabel->clear();
    ui->baudValueLabel->clear();

    // Speed Graph
    setPointSeries->setName("Set Point Hız");
    actualSeries->setName("Mevcut Hız");
    speedChart->addSeries(setPointSeries);
    speedChart->addSeries(actualSeries);
    speedChart->legend()->setAlignment(Qt::AlignBottom);

    axisX->setTitleText("Zaman (s)");
    axisX->setLabelFormat("%.1f");
    axisX->setRange(0, 0);
    speedChart->addAxis(axisX, Qt::AlignBottom);
    setPointSeries->attachAxis(axisX);
    actualSeries->attachAxis(axisX);

    axisY->setTitleText("Hız (m/s)");
    axisY->setLabelFormat("%.2f");
    axisY->setRange(0, 2);
    speedChart->addAxis(axisY, Qt::AlignLeft);
    setPointSeries->attachAxis(axisY);
    actualSeries->attachAxis(axisY);

    ui->SpeedGraph->setChart(speedChart);
    ui->SpeedGraph->setRenderHint(QPainter::Antialiasing);

    connect(setPointSeries, &QXYSeries::hovered,
            this, &MainWindow::showDataPoint);
    connect(actualSeries, &QXYSeries::hovered,
            this, &MainWindow::showDataPoint);



    // Seri porttan veri okuma
    connect(serial, &QSerialPort::readyRead,
            this, &MainWindow::handleSerialData);

    connect(this, &MainWindow::addWaypoint, this, &MainWindow::addWaypoint);


}

MainWindow::~MainWindow()
{
    if (recording) {
        csvFile->close();
        delete csvStream;
        delete csvFile;
    }
    if (serial->isOpen())
        serial->close();

      qDeleteAll(m_waypointRows);

    delete ui;
}

void MainWindow::on_connectButton_clicked()
{
    if (!serial->isOpen()) {
        // Seri ayarları
        serial->setPortName(currentPortName);
        serial->setBaudRate(currentBaudRate);
        serial->setDataBits(QSerialPort::Data8);
        serial->setParity(QSerialPort::NoParity);
        serial->setStopBits(QSerialPort::OneStop);

        if (serial->open(QIODevice::ReadWrite)) {
            ui->statusValueLabel->setText("Aktif");
            ui->portValueLabel->setText(currentPortName);
            ui->baudValueLabel->setText(QString::number(currentBaudRate));

            // CSV dosyasını aç ve başlık satırını yaz
            QString fileName = QDateTime::currentDateTime()
                                   .toString("yyyyMMdd_HHmmss_telemetry") + ".csv";
            csvFile   = new QFile(fileName, this);
            if (csvFile->open(QIODevice::WriteOnly | QIODevice::Text)) {
                csvStream = new QTextStream(csvFile);
                *csvStream << "timestamp,pitch,roll,yaw,heading,longitude,latitude,"
                              "voltage,temperature,questNo,setPoint,currentSpeed\n";
                recording = true;
            }
        } else {
            ui->statusValueLabel->setText("Hata");
        }
    } else {
        // CSV kaydını sonlandır
        if (recording) {
            csvFile->close();
            delete csvStream;  csvStream = nullptr;
            delete csvFile;    csvFile   = nullptr;
            recording = false;
        }
        // Seri bağlantıyı kapat
        serial->close();
        ui->statusValueLabel->setText("Pasif");
        ui->portValueLabel->clear();
        ui->baudValueLabel->clear();
    }
}

void MainWindow::on_settingsButton_clicked()
{
    ConnectionSettingsDialog dlg(this);
    // mevcut değerleri dialoga yansıt
    if (auto cb = dlg.findChild<QComboBox*>("portComboBox"))
        cb->setCurrentText(currentPortName);
    if (auto cb = dlg.findChild<QComboBox*>("baudComboBox"))
        cb->setCurrentText(QString::number(currentBaudRate));

    if (dlg.exec() == QDialog::Accepted) {
        currentPortName = dlg.portName();
        currentBaudRate = dlg.baudRate();
        ui->portValueLabel->setText(currentPortName);
        ui->baudValueLabel->setText(QString::number(currentBaudRate));
    }

    QStringList ports;
    for (const QSerialPortInfo &info : QSerialPortInfo::availablePorts()) {
        ports << info.portName();
        qDebug() << "Found serial port:" << info.portName();
    }
    if (ports.isEmpty()) {
        qWarning() << "Hiç seri port bulunamadı!";
    } else {
        // defaults
        currentPortName = ports.first();
    }
}

void MainWindow::on_sendButton_clicked()
{
    if (!serial->isOpen()) {
        QMessageBox::warning(this, tr("Gönderilemedi"),
                             tr("Önce Bağlan butonuna basarak seri portu açmalısınız."));
        return;
    }

    auto *tbl = ui->questTable;
    int rows = tbl->rowCount();
    if (rows == 0) {
        QMessageBox::information(this, tr("Gönderildi"),
                                 tr("Gönderecek waypoint yok."));
        return;
    }

    // 1) lat,lon çiftlerini topla
    QStringList pairs;
    for (int r = 0; r < rows; ++r) {
        QString lat = tbl->item(r, 1)->text();
        QString lon = tbl->item(r, 2)->text();
        pairs << QString("%1,%2").arg(lat, lon);
    }
    // "/" ile birleştir, sonuna newline ekle
    QByteArray packet = pairs.join('/').toUtf8() + '\n';

    // 2) Yaz ve kontrol et
    qint64 written = serial->write(packet);
    if (written != packet.size()) {
        QMessageBox::critical(this, tr("Hata"),
                              tr("Waypoint verisi gönderilirken hata oluştu:\n%1")
                                  .arg(serial->errorString()));
        return;
    }

    serial->flush();
    QThread::msleep(10);

    qDebug() << "[SEND-ALL]" << packet.trimmed();

    QMessageBox::information(this, tr("Gönderildi"),
                             tr("%1 waypoint verisi gönderildi.").arg(rows));
}

void MainWindow::on_emergencyButton_clicked()
{
    // Seri portun bağlı olup olmadığını kontrol edin
    if (!serial->isOpen()) {
        QMessageBox::warning(this,
                             tr("Acil Durdurma"),
                             tr("Lütfen önce bağlantıyı açın!"));
        return;
    }

    // Gönderilecek durdurma komutu
    // (Aracınızın protokolüne göre düzenleyin)
    const QByteArray stopCmd = "STOP\n";

    qint64 bytes = serial->write(stopCmd);
    if (bytes == stopCmd.size()) {
        QMessageBox::information(this,
                                 tr("Acil Durdurma"),
                                 tr("Acil durdurma komutu gönderildi."));
        ui->statusValueLabel->setText(tr("DURDURULDU"));
    } else {
        QMessageBox::critical(this,
                              tr("Acil Durdurma Hatası"),
                              tr("Komut gönderilemedi:\n%1")
                                  .arg(serial->errorString()));
    }
}


void MainWindow::handleSerialData()
{
    static QByteArray buffer;
    buffer.append(serial->readAll());

    while (buffer.contains('\n')) {
        int idx = buffer.indexOf('\n');
        QByteArray line = buffer.left(idx).trimmed();
        buffer.remove(0, idx + 1);

        auto parts = line.split(',');
        if (parts.size() < 11) continue;

        // parse telemetry
        qreal pitch        = parts[0].toDouble();
        qreal roll         = parts[1].toDouble();
        qreal yaw          = parts[2].toDouble();
        qreal heading      = parts[3].toDouble();
        qreal longitude    = parts[4].toFloat();
        qreal latitude     = parts[5].toFloat();
        qreal voltage      = parts[6].toDouble();
        qreal temperature  = parts[7].toDouble();
        int   questNo      = parts[8].toInt();
        qreal setPoint     = parts[9].toDouble();
        qreal currentSpeed = parts[10].toDouble();

        // UI güncelle
        ui->Pitch_Data   ->setText(QString::number(pitch, 'f', 2) + " °");
        ui->Roll_Data    ->setText(QString::number(roll,  'f', 2) + " °");
        ui->Yaw_Data     ->setText(QString::number(yaw,   'f', 2) + " °");
        ui->Yon_Data     ->setText(QString::number(heading,'f', 2) + " °");
        ui->Longitude   ->setText(QString::number(longitude,'f',5));
        ui->Latitude    ->setText(QString::number(latitude, 'f',5));
        ui->Voltage_Data ->setText(QString::number(voltage, 'f',1) + " V");
        ui->Sicaklik_Data->setText(QString::number(temperature,'f',1)+" °C");
        ui->QuestNo      ->setText(QString::number(questNo));
        ui->SetPoint_Data->setText(QString::number(setPoint,'f',2)+" m/s");
        ui->Speed_Data   ->setText(QString::number(currentSpeed,'f',2)+" m/s");
        ui->Setpoint_txt->setText(QString::number(setPoint,'f',2)+" m/s");
        ui->Speed_txt   ->setText(QString::number(currentSpeed,'f',2)+" m/s");


        updateMapPosition(latitude, longitude);
        updateMapHeading(heading);


        // grafiğe ekle
        actualSeries->append(elapsedTime, currentSpeed);
        elapsedTime += 1.0;
        axisX->setRange(0, elapsedTime);

        // --- Sliding window ekseni ayarı ---
        // pencere başı = elapsedTime - windowDuration, ama negatif olmasın
        qreal t0 = qMax<qreal>(0.0, elapsedTime - windowDuration);
        // ekseni [t0, t0+windowDuration] aralığında göster
        axisX->setRange(t0, t0 + windowDuration);

        // çok eski noktaları at (performans için)
        auto trim = [t0](QSplineSeries* s){
            // points() vektörünün ilk noktasının x()<t0 olduğu sürece sil
            while (!s->points().isEmpty() && s->points().first().x() < t0) {
                s->removePoints(0, 1);
            }
        };

        trim(actualSeries);

        setPointSeries->clear();
        setPointSeries->append(t0,              setPoint);
        setPointSeries->append(t0 + windowDuration, setPoint);

        // CSV kaydına yaz
        if (recording && csvStream) {
            QString ts = QDateTime::currentDateTime()
            .toString(Qt::ISODateWithMs);
            *csvStream << ts << ','
                       << pitch        << ','
                       << roll         << ','
                       << yaw          << ','
                       << heading      << ','
                       << longitude    << ','
                       << latitude     << ','
                       << voltage      << ','
                       << temperature  << ','
                       << questNo      << ','
                       << setPoint     << ','
                       << currentSpeed
                       << '\n';
            csvStream->flush();
        }

        ui->connectButton->setEnabled(true);
        ui->connectButton->setToolTip("");
    }
}

void MainWindow::showDataPoint(const QPointF &point, bool state)
{
    if (!state) return;
    QString txt = QString("Zaman: %1 s\nHız: %2 m/s")
                      .arg(point.x(), 0, 'f', 2)
                      .arg(point.y(), 0, 'f', 2);
    QToolTip::showText(QCursor::pos(), txt);
}


void MainWindow::addWaypoint(double lat, double lon) {
    qDebug() << "Yeni waypoint eklendi:" << lat << lon;
    // Burada ileride listeye de ekleyebilirsin, CSV’ye yazabilirsin...
    auto *tbl = ui->questTable;
    int row = tbl->rowCount();
    tbl->insertRow(row);

    // 1) Sıra numarası
    auto *idxItem = new QTableWidgetItem(QString::number(row+1));
    idxItem->setFlags(idxItem->flags() & ~Qt::ItemIsEditable);
    tbl->setItem(row, 0, idxItem);

    // 2) Latitude
    tbl->setItem(row, 1,
                 new QTableWidgetItem(QString::number(lat, 'f', 6)));

    // 3) Longitude
    tbl->setItem(row, 2,
                 new QTableWidgetItem(QString::number(lon, 'f', 6)));

    // 4) Sil butonu

    QPushButton *del = new QPushButton("Sil");
    ui->questTable->setCellWidget(row, 3, del);
    connect(del, &QPushButton::clicked, this, &MainWindow::handleDeleteButton);
}

void MainWindow::handleDeleteButton()
{
    int row = ui->questTable->currentRow();
    if (row < 0) return;

    // 1) QML tarafındaki helper'ı çağır
    QObject *root = ui->mapQuickWidget->rootObject();
    if (root) {
        // QML fonksiyon imzası QVariant aldığı için
        QMetaObject::invokeMethod(
            root,
            "removeWaypointAt",
            // ---- Burayı şu şekilde değiştir ----
            Q_ARG(QVariant, QVariant(row))
            );
    }

    // 2) Tablo satırını sil
    ui->questTable->removeRow(row);

    // 3) Kalan satırları yeniden numaralandır
    for (int r = 0; r < ui->questTable->rowCount(); ++r) {
        ui->questTable->item(r, 0)
        ->setText(QString::number(r + 1));
    }
}



void MainWindow::handleItemChanged(QTableWidgetItem *item)
{
    int row = item->row();
    int col = item->column();
    // sadece lat(1) veya lon(2) için
    if (col!=1 && col!=2) return;

    bool ok;
    double lat = ui->questTable->item(row,1)->text().toDouble(&ok);
    if (!ok) return;
    double lon = ui->questTable->item(row,2)->text().toDouble(&ok);
    if (!ok) return;
    // model’de de güncelle
    updateWaypointAt(row, lat, lon);
}

void MainWindow::removeWaypointAt(int index)
{
    QObject *root = ui->mapQuickWidget->rootObject();
    if (!root) return;
    QObject *model = root->findChild<QObject*>("waypointModel");
    if (!model) {
        qWarning() << "waypointModel bulunamadı!";
        return;
    }
    // ListModel.remove(index, count=1)
    QMetaObject::invokeMethod(model,
                              "remove",
                              Q_ARG(int, index),
                              Q_ARG(int, 1)
                              );
}

void MainWindow::updateWaypointAt(int index, double lat, double lon)
{
    QObject *root = ui->mapQuickWidget->rootObject();
    if (!root) return;
    QObject *model = root->findChild<QObject*>("waypointModel");
    if (!model) {
        qWarning() << "waypointModel bulunamadı!";
        return;
    }
    QVariantMap props;
    props.insert("lat", lat);
    props.insert("lon", lon);
    // ListModel.set(index, props)
    QMetaObject::invokeMethod(model,
                              "set",
                              Q_ARG(int, index),
                              Q_ARG(QVariant, props)
                              );
}


void MainWindow::updateMapPosition(double latitude, double longitude)
{
    if (auto r = ui->mapQuickWidget->rootObject()) {
        r->setProperty("vehicleLat", latitude);
        r->setProperty("vehicleLon", longitude);
    }
}

void MainWindow::updateMapHeading(double heading)
{
    if (auto r = ui->mapQuickWidget->rootObject())
        r->setProperty("vehicleHeading", heading);
}

