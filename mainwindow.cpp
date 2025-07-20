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
#include <QColor>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    serial(new QSerialPort(this)),
    speedChart(new QChart),
    setPointSeries(new QSplineSeries),
    actualSeries(new QSplineSeries),
    axisX(new QValueAxis),
    axisY(new QValueAxis),
    pryChart(new QChart),
    yawSeries(new QSplineSeries),
    axisX_pry(new QValueAxis),
    axisY_pry(new QValueAxis),
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
    setPointSeries->setColor(QColor("#40e0d0"));
    actualSeries  ->setColor(QColor("#ff8c00"));

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

    speedChart->setBackgroundVisible(false);
    // Çerçeveyi kaldır
    ui->SpeedGraph->setFrameStyle(QFrame::NoFrame);

    // View’in arka planını şeffaf yap (hiçbir fırça kullanma)
    ui->SpeedGraph->setStyleSheet("background-color: transparent; border: none;");
    speedChart->setPlotAreaBackgroundVisible(false);
    speedChart->setPlotAreaBackgroundBrush(Qt::NoBrush);


    ui->SpeedGraph->setChart(speedChart);
    ui->SpeedGraph->setRenderHint(QPainter::Antialiasing);

    connect(setPointSeries, &QXYSeries::hovered,
            this, &MainWindow::showDataPoint);
    connect(actualSeries, &QXYSeries::hovered,
            this, &MainWindow::showDataPoint);




    // --- Pitch–Yaw–Roll Graph Setup ---

    yawSeries  ->setName("Yaw");

    pryChart->addSeries(yawSeries);   
    pryChart->legend()->setAlignment(Qt::AlignBottom);

    axisX_pry->setTitleText("Zaman (s)");
    axisX_pry->setLabelFormat("%.1f");


    axisY_pry->setTitleText("Derece (°)");
    axisY_pry->setLabelFormat("%.1f");
    axisY_pry->setRange(-45, 45);             // <-- burayı bu şekilde ayarlıyoruz
    axisY_pry->setGridLinePen(QPen(QColor(200,200,200,100), 1, Qt::DashLine));

    pryChart->addAxis(axisX_pry, Qt::AlignBottom);
    pryChart->addAxis(axisY_pry, Qt::AlignLeft);



    pryChart->setBackgroundVisible(false);
    ui->PRYGraph->setFrameStyle(QFrame::NoFrame);
    ui->PRYGraph->setStyleSheet("background-color: transparent; border: none;");
    pryChart->setPlotAreaBackgroundVisible(false);
    pryChart->setPlotAreaBackgroundBrush(Qt::NoBrush);

    yawSeries  ->attachAxis(axisX_pry);
    yawSeries  ->attachAxis(axisY_pry);
    yawSeries  ->setColor(QColor("#ff8c00"));



    // QChartView: Designer’da bir QChartView @ ui->PRYGraph olarak yerleştirin
    ui->PRYGraph->setChart(pryChart);
    ui->PRYGraph->setRenderHint(QPainter::Antialiasing);
    connect(yawSeries,   &QXYSeries::hovered, this, &MainWindow::showDataPoint);

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
        // 1) Seçilen port ve baud‑rate’i uygula
        serial->setPortName(currentPortName);
        // QSerialPort::setBaudRate(int) overload’u var, ama enum kullanmak daha güvenli:
        serial->setBaudRate(static_cast<QSerialPort::BaudRate>(currentBaudRate));
        serial->setDataBits(QSerialPort::Data8);
        serial->setParity  (QSerialPort::NoParity);
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
            // Eğer açılmazsa kısa bir hata mesajı
            QMessageBox::critical(this, "Bağlantı Hatası",
                                  QString("“%1” portu açılamadı!").arg(currentPortName));
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

    // Mevcut port listesini yeniden doldur
    {
        auto *cb = dlg.findChild<QComboBox*>("portComboBox");
        if (cb) {
            cb->clear();
            for (const auto &info : QSerialPortInfo::availablePorts())
                cb->addItem(info.portName());
            // ve eski seçimi koru
            cb->setCurrentText(currentPortName);
        }
    }

    // Baud listesi zaten dialog ctor’da doluyor, burda sadece seçimi yansıt
    {
        auto *cb = dlg.findChild<QComboBox*>("baudComboBox");
        if (cb)
            cb->setCurrentText(QString::number(currentBaudRate));
    }

    if (dlg.exec() == QDialog::Accepted) {
        // Yeni ayarları al
        currentPortName = dlg.portName();
        currentBaudRate = dlg.baudRate();
        ui->portValueLabel->setText(currentPortName);
        ui->baudValueLabel->setText(QString::number(currentBaudRate));
    }
}

void MainWindow::on_sendButton_clicked()
{
    if (!serial->isOpen()) {
        QMessageBox::warning(this, "Gönderilemedi",
                             "Önce Bağlan butonuna basarak seri portu açmalısınız.");
        return;
    }

    auto *tbl = ui->questTable;
    int rows = tbl->rowCount();
    if (rows == 0) {
        QMessageBox::information(this, "Gönder", "Gönderecek waypoint yok.");
        return;
    }

    // Her satır için "lat,lon" çiftini oluşturup listeye ekleyelim
    QStringList pairs;
    for (int r = 0; r < rows; ++r) {
        // 0. sütun = Latitude, 1. sütun = Longitude
        QString lat = tbl->item(r, 0)->text().trimmed();
        QString lon = tbl->item(r, 1)->text().trimmed();
        if (lat.isEmpty() || lon.isEmpty())
            continue;
        pairs << QString("%1,%2").arg(lat, lon);
    }

    if (pairs.isEmpty()) {
        QMessageBox::information(this, "Gönder", "Geçerli bir latitude/longitude çifti yok.");
        return;
    }

    // Başına "$", satırları ";" ile ayır, sonuna "\n"
    QString payload = "$" + pairs.join(';');
    QByteArray packet = payload.toUtf8() + '\n';

    qint64 written = serial->write(packet);
    if (written != packet.size()) {
        QMessageBox::critical(this, "Hata",
                              "Waypoint paketi gönderilirken hata oluştu.");
    } else {
        qDebug() << "[SEND] Paket gönderildi:" << packet.trimmed();
        QMessageBox::information(this, "Gönderildi",
                                 QString("%1 waypoint içeren paket gönderildi.").arg(pairs.size()));
    }
}

void MainWindow::on_sendParamButton_clicked()
{
    // 1) Önce portun açık olup olmadığını kontrol edelim
    if (!serial->isOpen()) {
        QMessageBox::warning(this, "Gönderilemedi",
                             "Önce Bağlan butonuna basarak seri portu açmalısınız.");
        return;
    }

    auto *tbl = ui->parametersTable;     // Qt Designer'daki QTableWidget nesneniz
    int rows = tbl->rowCount();
    int cols = tbl->columnCount();

    // 2) Her satır için boş olmayan hücreleri bir araya toplayalım
    QStringList rowStrings;
    for (int r = 0; r < rows; ++r) {
        QStringList values;
        for (int c = 0; c < cols; ++c) {
            QTableWidgetItem *it = tbl->item(r, c);
            if (it) {
                QString txt = it->text().trimmed();
                if (!txt.isEmpty())
                    values << txt;
            }
        }
        if (!values.isEmpty()) {
            // Virgülle birleştir, örn. "12.34" tek sütun için,
            // birden fazla sütun varsa "val1,val2,..." olur.
            rowStrings << values.join(',');
        }
    }

    if (rowStrings.isEmpty()) {
        QMessageBox::information(this, "Gönder", "Gönderecek parametre yok.");
        return;
    }

    // 3) Başına '*' ekle, satırları ';' ile ayır, sonuna '\n'
    QString payload = "*" + rowStrings.join(';');
    QByteArray packet = payload.toUtf8() + '\n';

    // 4) Seri porta yaz
    qint64 written = serial->write(packet);
    if (written != packet.size()) {
        QMessageBox::critical(this, "Hata",
                              "Parametre paketi gönderilirken hata oluştu.");
    } else {
        qDebug() << "[SEND PARAM]" << packet.trimmed();
        QMessageBox::information(this, "Gönderildi",
                                 QString("%1 parametre satırı içeren paket gönderildi.")
                                     .arg(rowStrings.size()));
    }
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

        auto parts = line.split(';');
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
        ui->Speed_txt_2     ->setText(QString::number(yaw,   'f', 2) + " °");

        updateMapPosition(latitude, longitude);
        updateMapHeading(heading);


        // grafiğe ekle

        actualSeries->append(elapsedTime, currentSpeed);
        yawSeries  ->append(elapsedTime, yaw);


        elapsedTime += 1.0;
        axisX->setRange(0, elapsedTime);


        // --- Sliding window ekseni ayarı ---
        // pencere başı = elapsedTime - windowDuration, ama negatif olmasın
        qreal t0 = qMax<qreal>(0.0, elapsedTime - windowDuration);
        // ekseni [t0, t0+windowDuration] aralığında göster
        axisX->setRange(t0, t0 + windowDuration);
        axisX_pry  ->setRange(t0, t0 + windowDuration);


        // çok eski noktaları at (performans için)
        auto trim = [t0](QSplineSeries* s){
            // points() vektörünün ilk noktasının x()<t0 olduğu sürece sil
            while (!s->points().isEmpty() && s->points().first().x() < t0) {
                s->removePoints(0, 1);
            }
        };

        trim(actualSeries);
        trim(actualSeries);
        trim(yawSeries);

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

    // 2) Latitude
    tbl->setItem(row, 0,
                 new QTableWidgetItem(QString::number(lat, 'f', 6)));

    // 3) Longitude
    tbl->setItem(row, 1,
                 new QTableWidgetItem(QString::number(lon, 'f', 6)));

    // 4) Sil butonu

    QPushButton *del = new QPushButton("Sil");
    ui->questTable->setCellWidget(row, 2, del);
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
    if (col!=0 && col!=1) return;

    bool ok;
    double lat = ui->questTable->item(row,0)->text().toDouble(&ok);
    if (!ok) return;
    double lon = ui->questTable->item(row,1)->text().toDouble(&ok);
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

