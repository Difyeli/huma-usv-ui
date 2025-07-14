#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCharts/QChartView>
#include <QtCharts/QValueAxis>
#include <QtSerialPort/QSerialPort>      // <--- Ekleyin
#include <QtSerialPort/QSerialPortInfo>  // isteğe bağlı
#include <QPainter>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    elapsedTime(0)
{
    ui->setupUi(this);

    // --- Chart & Series Setup ---
    setPointSeries = new QLineSeries();  setPointSeries->setName("Set Point Hız");
    actualSeries   = new QLineSeries();  actualSeries->setName("Mevcut Hız");

    speedChart = new QChart();
    speedChart->addSeries(setPointSeries);
    speedChart->addSeries(actualSeries);
    speedChart->legend()->setAlignment(Qt::AlignBottom);

    auto *axisX = new QValueAxis(); axisX->setTitleText("Zaman (s)");
    auto *axisY = new QValueAxis(); axisY->setTitleText("Hız (m/s)");

    speedChart->addAxis(axisX, Qt::AlignBottom);
    speedChart->addAxis(axisY, Qt::AlignLeft);
    setPointSeries->attachAxis(axisX);  setPointSeries->attachAxis(axisY);
    actualSeries->attachAxis(axisX);    actualSeries->attachAxis(axisY);

    ui->SpeedGraph->setChart(speedChart);
    ui->SpeedGraph->setRenderHint(QPainter::Antialiasing);

    // --- Serial Port Setup ---
    serial = new QSerialPort(this);
    serial->setPortName("COM3");                     // portu kendi ayarınıza göre değiştirin
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->open(QIODevice::ReadOnly);

    connect(serial, &QSerialPort::readyRead,
            this,   &MainWindow::handleSerialData);
}

MainWindow::~MainWindow()
{
    if(serial->isOpen()) serial->close();
    delete ui;
}

void MainWindow::handleSerialData()
{
    static QByteArray buffer;
    buffer.append(serial->readAll());

    // Satır sonuna kadar oku
    while (buffer.contains('\n')) {
        int idx = buffer.indexOf('\n');
        QByteArray line = buffer.left(idx).trimmed();
        buffer.remove(0, idx + 1);

        // Virgülle ayır
        QList<QByteArray> parts = line.split(',');
        if (parts.size() >= 11) {
            // 1) Verileri double/int olarak al
            qreal pitch        = parts[0].toDouble();
            qreal roll         = parts[1].toDouble();
            qreal yaw          = parts[2].toDouble();
            qreal heading      = parts[3].toDouble();
            qreal longitude    = parts[4].toDouble();
            qreal latitude     = parts[5].toDouble();
            qreal voltage      = parts[6].toDouble();
            qreal temperature  = parts[7].toDouble();
            int   questNo      = parts[8].toInt();
            qreal setPoint     = parts[9].toDouble();
            qreal currentSpeed = parts[10].toDouble();

            // 2) Grafiğe nokta ekle
            setPointSeries->append(elapsedTime,     setPoint);
            actualSeries  ->append(elapsedTime, currentSpeed);
            elapsedTime += 1;

            // 3) QLabel’lara yaz
            ui->Pitch_Data     ->setText(QString::number(pitch,       'f', 2) + " °");
            ui->Roll_Data      ->setText(QString::number(roll,        'f', 2) + " °");
            ui->Yaw_Data       ->setText(QString::number(yaw,         'f', 2) + " °");
            ui->Yon_Data       ->setText(QString::number(heading,     'f', 2) + " °");
            ui->Longtitute     ->setText(QString::number(longitude,   'f', 2));
            ui->Lattitute      ->setText(QString::number(latitude,    'f', 2));
            ui->Voltage_Data   ->setText(QString::number(voltage,     'f', 1) + " V");
            ui->Sicaklik_Data  ->setText(QString::number(temperature, 'f', 1) + " °C");
            ui->QuestNo        ->setText(QString::number(questNo));
            ui->SetPoint_Data  ->setText(QString::number(setPoint,    'f', 2) + " m/s");
            ui->Speed_Data     ->setText(QString::number(currentSpeed,'f', 2) + " m/s");
        }
    }
}

