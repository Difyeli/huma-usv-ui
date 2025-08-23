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
#include <QScrollBar>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    serial(new QSerialPort(this)),
    speedChart(new QChart),
    setPointSeries(new QSplineSeries),
    actualSeries(new QSplineSeries),
    axisX(new QValueAxis),
    axisY(new QValueAxis),

    speedChart2(new QChart),
    setPointSeries2(new QSplineSeries),
    actualSeries2(new QSplineSeries),
    axisX_2(new QValueAxis),
    axisY_2(new QValueAxis),

    ThrusterChart(new QChart),
    setPointSeriesR(new QSplineSeries),
    actualSeriesR(new QSplineSeries),
    axisX_R(new QValueAxis),
    axisY_R(new QValueAxis),

    pryChart(new QChart),
    yawSeries(new QSplineSeries),
    setPointYaw(new QSplineSeries),
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


    // Designer’da eklediğiniz frame’leri pointer’a atıyoruz
    remoteLamp   = ui->remoteLamp;
    failsafeLamp = ui->failsafeLamp;

    // Başlangıç rengi: gri (pasif)
    remoteLamp->setStyleSheet("background-color: lightgray; border:1px solid #555; border-radius:3px;");
    failsafeLamp->setStyleSheet("background-color: lightgray; border:1px solid #555; border-radius:3px;");



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
    setPointSeries->setName("Left Set Point");
    actualSeries->setName("Actual Speed");
    speedChart->addSeries(setPointSeries);
    speedChart->addSeries(actualSeries);
    setPointSeries->setColor(QColor("#40e0d0"));
    actualSeries  ->setColor(QColor("#ff8c00"));

    speedChart->legend()->setAlignment(Qt::AlignBottom);

    axisX->setTitleText("Time (s)");
    axisX->setLabelFormat("%.1f");
    axisX->setRange(0, 30);
    speedChart->addAxis(axisX, Qt::AlignBottom);
    setPointSeries->attachAxis(axisX);
    actualSeries->attachAxis(axisX);

    axisY->setTitleText("Speed (m/s)");
    axisY->setLabelFormat("%.2f");
    axisY->setRange(0, 1.5);
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


    // --- İkinci Speed Graph Setup (aynı mantık) ---
    //
    setPointSeries2->setName("Setpoint PWM");
    actualSeries2 ->setName("Left PWM");
    speedChart2->addSeries(setPointSeries2);
    speedChart2->addSeries(actualSeries2);
    speedChart2->legend()->setAlignment(Qt::AlignBottom);
    setPointSeries2->setColor(QColor("#40e0d0"));
    actualSeries2  ->setColor(QColor("#ff8c00"));

    axisX_2->setTitleText("Time (s)");
    axisX_2->setLabelFormat("%.1f");
    axisX_2->setRange(0, 30);
    speedChart2->addAxis(axisX_2, Qt::AlignBottom);
    setPointSeries2->attachAxis(axisX_2);
    actualSeries2->attachAxis(axisX_2);

    axisY_2->setTitleText("Left PWM ");
    axisY_2->setLabelFormat("%.2f");
    axisY_2->setRange(0, 1600);
    speedChart2->addAxis(axisY_2, Qt::AlignLeft);
    setPointSeries2->attachAxis(axisY_2);
    actualSeries2->attachAxis(axisY_2);

    speedChart2->setBackgroundVisible(false);
    // Çerçeveyi kaldır
    ui->SpeedGraph2->setFrameStyle(QFrame::NoFrame);

    // View’in arka planını şeffaf yap (hiçbir fırça kullanma)
    ui->SpeedGraph2->setStyleSheet("background-color: transparent; border: none;");
    speedChart2->setPlotAreaBackgroundVisible(false);
    speedChart2->setPlotAreaBackgroundBrush(Qt::NoBrush);



    ui->SpeedGraph2->setChart(speedChart2);
    ui->SpeedGraph2->setRenderHint(QPainter::Antialiasing);

    connect(setPointSeries2, &QXYSeries::hovered,
            this, &MainWindow::showDataPoint);
    connect(actualSeries2, &QXYSeries::hovered,
            this, &MainWindow::showDataPoint);


    //RightThrusters

    setPointSeriesR->setName("Setpoint PWM");
    actualSeriesR ->setName("Right PWM");
    ThrusterChart->addSeries(setPointSeriesR);
    ThrusterChart->addSeries(actualSeriesR);
    ThrusterChart->legend()->setAlignment(Qt::AlignBottom);


    axisX_R->setTitleText("Time(s)");
    axisX_R->setLabelFormat("%.1f");
    axisX_R->setRange(0, 0);
    ThrusterChart->addAxis(axisX_R, Qt::AlignBottom);
    setPointSeriesR->attachAxis(axisX_R);
    actualSeriesR->attachAxis(axisX_R);

    axisY_R->setTitleText("Right PWM");
    axisY_R->setLabelFormat("%.2f");
    axisY_R->setRange(0, 1600);
    ThrusterChart->addAxis(axisY_R, Qt::AlignLeft);
    setPointSeriesR->attachAxis(axisY_R);
    actualSeriesR->attachAxis(axisY_R);

    ThrusterChart->setBackgroundVisible(false);
    // Çerçeveyi kaldır
    ui->ThrusterChart->setFrameStyle(QFrame::NoFrame);

    // View’in arka planını şeffaf yap (hiçbir fırça kullanma)
    ui->ThrusterChart->setStyleSheet("background-color: transparent; border: none;");
    ThrusterChart->setPlotAreaBackgroundVisible(false);
    ThrusterChart->setPlotAreaBackgroundBrush(Qt::NoBrush);



    ui->ThrusterChart->setChart(ThrusterChart);
    ui->ThrusterChart->setRenderHint(QPainter::Antialiasing);

    connect(setPointSeriesR, &QXYSeries::hovered,
            this, &MainWindow::showDataPoint);
    connect(actualSeriesR, &QXYSeries::hovered,
            this, &MainWindow::showDataPoint);





    // --- Pitch–Yaw–Roll Graph Setup ---
    yawSeries   ->setName("Yaw");
    setPointYaw ->setName("Setpoint Yaw");

    pryChart->addSeries(yawSeries);
    pryChart->addSeries(setPointYaw);
    pryChart->legend()->setAlignment(Qt::AlignBottom);

    // X ekseni
    axisX_pry->setTitleText("Zaman (s)");
    axisX_pry->setLabelFormat("%.1f");

    // Y ekseni
    axisY_pry->setTitleText("Derece (°)");
    axisY_pry->setLabelFormat("%.1f");
    axisY_pry->setRange(0, 360);
    axisY_pry->setGridLinePen(QPen(QColor(200,200,200,100), 1, Qt::DashLine));

    // Eksenleri ekle
    pryChart->addAxis(axisX_pry, Qt::AlignBottom);
    pryChart->addAxis(axisY_pry, Qt::AlignLeft);

    // yawSeries’i eksenlere tak
    yawSeries->attachAxis(axisX_pry);
    yawSeries->attachAxis(axisY_pry);
    yawSeries->setColor(QColor("#ff8c00"));  // turuncu
    connect(yawSeries, &QXYSeries::hovered, this, &MainWindow::showDataPoint);

    // setPointYaw’i de aynı eksenlere tak
    setPointYaw->attachAxis(axisX_pry);
    setPointYaw->attachAxis(axisY_pry);
    setPointYaw->setColor(QColor("#008B8B")); // deniz mavisi gibi bir renk
    connect(setPointYaw, &QXYSeries::hovered, this, &MainWindow::showDataPoint);

    // ChartView ayarları
    pryChart->setBackgroundVisible(false);
    ui->PRYGraph->setFrameStyle(QFrame::NoFrame);
    ui->PRYGraph->setStyleSheet("background-color: transparent; border: none;");
    pryChart->setPlotAreaBackgroundVisible(false);
    pryChart->setPlotAreaBackgroundBrush(Qt::NoBrush);

    ui->PRYGraph->setChart(pryChart);
    ui->PRYGraph->setRenderHint(QPainter::Antialiasing);

    connect(yawSeries,   &QXYSeries::hovered, this, &MainWindow::showDataPoint);

    // Seri porttan veri okuma
    connect(serial, &QSerialPort::readyRead,
            this, &MainWindow::handleSerialData);

    connect(this, &MainWindow::addWaypoint, this, &MainWindow::addWaypoint);

    addLogMessage("Sistem başlatıldı");
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
    QString payload = "?" + pairs.join(';');
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

/*void MainWindow::on_sendParamButton_clicked()
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
}*/

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
    const QByteArray stopCmd = "!failsafe\n";

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
        QByteArray rawLine = buffer.left(idx).trimmed();
        buffer.remove(0, idx + 1);


        QString line = QString::fromUtf8(rawLine);
        line = line.trimmed();

        // opsiyonel: süslü parantezleri at
        if (line.startsWith("{") && line.endsWith("}")) {
            line = line.mid(1, line.length()-2);
        }

        QStringList parts = line.split(',');
        if (parts.size() < 13)
            continue;

        double latitude     = parts[0].toFloat();
        double longitude    = parts[1].toFloat();
        int    SIV          = parts[2].toInt();
        bool   remoteActive = parts[3].compare("true", Qt::CaseInsensitive)==0;
        bool   failsafe     = (parts[4] == "FS1");
        qreal currentSpeed2 = parts[5].toDouble();
        qreal currentSpeedR = parts[6].toDouble();
        double yawDeg       = parts[7].toDouble();
        qreal currentSpeed  = parts[8].toDouble();
        qreal setPoint      = parts[9].toDouble();
        double yawSetpoint  = parts[10].toDouble();
        qreal setPoint2     = parts[11].toDouble();
        qreal setPointR     = parts[12].toDouble();

        // --- Özel Mesajı Ayıkla (Varsa) ---
        QString specialMessage;
        if (parts.size() >= 14) {
            QString msgField = parts[13].trimmed();
            if (msgField.startsWith("MSG:")) {
                specialMessage = msgField.mid(4); // "GOTO1", "ARR1", vs.
            }
        }

        if (!specialMessage.isEmpty()) {
            if      (specialMessage == "GOTO1")  addLogMessage("1. GPS noktasına yöneliniyor");
            else if (specialMessage == "ARR1")   addLogMessage("1. GPS noktasına ulaşıldı", "success");
            else if (specialMessage == "GOTO2")  addLogMessage("2. GPS noktasına yöneliniyor");
            else if (specialMessage == "ARR2")   addLogMessage("2. GPS noktasına ulaşıldı", "success");
            else if (specialMessage == "FINISH") addLogMessage("Görev tamamlandı", "success");
            else if (specialMessage == "CANCEL") addLogMessage("Görev iptal edildi", "warning");
            else if (specialMessage == "GPS_ERR") addLogMessage("GPS sinyal kaybı", "error");
            else if (specialMessage == "VOLT_ERR") addLogMessage("Pil voltajı düşük", "error");
            else if (specialMessage == "MOTOR_ERR") addLogMessage("Motor arızası", "error");
            else if (specialMessage == "SENSOR_ERR") addLogMessage("Sensör hatası", "error");
            else addLogMessage("Bilinmeyen mesaj: " + specialMessage, "warning");
        }



        // --- UI’ı güncelle ---

        // ui->GpsTimeLabel  ->setText(gpsTime);  // eğer bir etiket varsa
        ui->Latitude        ->setText(QString::number(latitude,  'f', 8));
        ui->Longitude       ->setText(QString::number(longitude, 'f', 8));
        ui->Yaw_Data        ->setText(QString::number(yawDeg,    'f', 2) + " °");
        ui->Direction_Data  ->setText(QString::number(yawSetpoint,    'f', 2) + " °");
        ui->SIV_Data        ->setText(QString::number(SIV));
        ui->RemoteActive_Data->setText(remoteActive ? "Yes" : "No");
        ui->Failsafe_Data   ->setText(failsafe ? "FS1" : "OK");
        ui->SetPoint_Data->setText(QString::number(setPoint,'f',2)+" m/s");
        ui->Speed_Data   ->setText(QString::number(currentSpeed,'f',2)+" m/s");
        ui->SetPoint_Data2->setText(QString::number(setPoint2,'f',2));
        ui->Speed_Data2   ->setText(QString::number(currentSpeed2,'f',2));
        ui->SetPoint_DataR->setText(QString::number(setPointR,'f',2));
        ui->Speed_DataR   ->setText(QString::number(currentSpeedR,'f',2));


        updateMapPosition(latitude, longitude);
        updateMapHeading(yawDeg);


        const double eps = 1e-5;
        for (int r = 0; r < ui->questTable->rowCount(); ++r) {
            bool okLat, okLon;
            double latRow = ui->questTable->item(r, 0)->text().toDouble(&okLat);
            double lonRow = ui->questTable->item(r, 1)->text().toDouble(&okLon);
            if (okLat && okLon) {
                bool match = qAbs(latRow  - latitude)  < eps
                             && qAbs(lonRow  - longitude) < eps;
                QColor color = match ? QColor(200, 255, 200) : Qt::white;
                // Hem latitude hem longitude hücresini renklendir
                ui->questTable->item(r, 0)->setBackground(color);
                ui->questTable->item(r, 1)->setBackground(color);
            }
        }


        // --- Zamanı al ve sayacı artır ---
        qreal t = elapsedTime;
        elapsedTime += 1.0;

        // --- Actual series’e ekle ---
        actualSeries ->append(t, currentSpeed);
        actualSeries2->append(t, currentSpeed2);
        actualSeriesR->append(t, currentSpeedR);
        yawSeries    ->append(t, yawDeg);
        setPointYaw ->append(t, yawSetpoint);

        // --- Sliding‐window ve setPoint çizgileri için ---
        const qreal window = windowDuration;  // mesela 30.0
        qreal t0 = qMax<qreal>(0.0, elapsedTime - window);

        // 1) Eski actual noktalarını kırp
        auto trim = [t0](QSplineSeries* s){
            while (!s->points().isEmpty() && s->points().first().x() < t0)
                s->removePoints(0,1);
        };
        trim(actualSeries);
        trim(actualSeries2);
        trim(actualSeriesR);
        trim(yawSeries);
        trim(setPointYaw);

        // 2) SetPoint serileri: önce temizle, sonra iki nokta ekle
        setPointSeries ->clear();
        setPointSeries ->append(t0,           setPoint);
        setPointSeries ->append(t0 + window,  setPoint);

        setPointSeries2->clear();
        setPointSeries2->append(t0,           setPoint2);
        setPointSeries2->append(t0 + window,  setPoint2);

        setPointSeriesR->clear();
        setPointSeriesR->append(t0,           setPointR);
        setPointSeriesR->append(t0 + window,  setPointR);

        setPointYaw->clear();
        setPointYaw->append(t0,           yawSetpoint);
        setPointYaw->append(t0 + window,  yawSetpoint);

        // 3) Eksen aralıklarını sabitle
        axisX  ->setRange(t0, t0 + window);
        axisX_2->setRange(t0, t0 + window);
        axisX_R->setRange(t0, t0 + window);
        axisX_pry->setRange(t0, t0 + window);


        // --- Remote lambasını yak/gizle ---
        if (remoteActive) {
            // remoteActive == true  → yeşil
             remoteLamp->setStyleSheet("background-color: green; border:1px solid #555; border-radius:3px;");
        } else {
            // remoteActive == false → sarı
            remoteLamp->setStyleSheet("background-color: yellow; border:1px solid #555; border-radius:3px;");
        }

        // --- Failsafe lambasını yak/gizle ---
        if (failsafe) {
            // failsafe == true  → kırmızı
            failsafeLamp->setStyleSheet("background-color: red; border:1px solid #555; border-radius:3px;");
        } else {
            // failsafe == false → gri
            failsafeLamp->setStyleSheet("background-color: lightgray; border:1px solid #555; border-radius:3px;");
        }

        // CSV kaydına yaz
       /* if (recording && csvStream) {
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
        }*/

        ui->connectButton->setEnabled(true);
        ui->connectButton->setToolTip("");
    }
}

void MainWindow::showDataPoint(const QPointF &point, bool state)
{
    if (!state) return;
    QString txt = QString("Time: %1 s\n X-Axis: %2 m/s")
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

    QPushButton *del = new QPushButton("Delete");
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




void MainWindow::addLogMessage(const QString &message, const QString &type)
{
    if (!ui->textLog) return;

    QString timestamp = QDateTime::currentDateTime().toString("hh:mm:ss");
    QString formattedMessage;

    if (type == "error") {
        formattedMessage = QString("[%1] HATA: %2\n").arg(timestamp, message);
        // QPlainTextEdit için HTML yerine düz metin, renk için extra işlem gerekebilir
    } else if (type == "success") {
        formattedMessage = QString("[%1] ✓ %2\n").arg(timestamp, message);
    } else if (type == "warning") {
        formattedMessage = QString("[%1] UYARI: %2\n").arg(timestamp, message);
    } else {
        formattedMessage = QString("[%1] %2\n").arg(timestamp, message);
    }

    // QPlainTextEdit için append kullan
    ui->textLog->appendPlainText(formattedMessage);

    // Otomatik scroll
    QScrollBar *scrollbar = ui->textLog->verticalScrollBar();
    if (scrollbar) {
        scrollbar->setValue(scrollbar->maximum());
    }

    // Konsola da yaz (debug için)
    qDebug().noquote() << formattedMessage.trimmed();
}
