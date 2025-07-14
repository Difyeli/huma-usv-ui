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

    // Ayarlar diyalog açma
    connect(ui->settingsButton, &QPushButton::clicked,
            this, &MainWindow::on_settingsButton_clicked);

    // Seri porttan veri okuma
    connect(serial, &QSerialPort::readyRead,
            this, &MainWindow::handleSerialData);
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

        if (serial->open(QIODevice::ReadOnly)) {
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
        setPointSeries->append(elapsedTime, setPoint);
        actualSeries->append(elapsedTime, currentSpeed);
        elapsedTime += 1.0;
        axisX->setRange(0, elapsedTime);

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


void MainWindow::addWaypoint(double lat, double lon)
{
    qDebug() << "Waypoint:" << lat << lon;
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
