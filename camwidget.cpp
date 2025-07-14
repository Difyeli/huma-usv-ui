// camwidget.cpp
#include "camwidget.h"
#include <QPainter>

CamWidget::CamWidget(QWidget* parent)
    : QWidget(parent)
    , timer(new QTimer(this))
{
    connect(timer, &QTimer::timeout, this, &CamWidget::grabFrame);
}

CamWidget::~CamWidget()
{
    stopCamera();
    stopLoRa();
}

bool CamWidget::startCamera(const QString &source)
{
    bool ok = false;
    bool isNum = false;
    int dev = source.toInt(&isNum);
    if (isNum)             ok = cap.open(dev);
    else                   ok = cap.open(source.toStdString());

    if (ok) {
        timer->start(30); // ~33 FPS
        return true;
    }
    return false;
}

void CamWidget::stopCamera()
{
    timer->stop();
    if (cap.isOpened()) cap.release();
}

bool CamWidget::startLoRa(const QString &portName, int baudRate)
{
    if (loraPort) stopLoRa();
    loraPort = new QSerialPort(this);
    loraPort->setPortName(portName);
    loraPort->setBaudRate   (baudRate);
    loraPort->setDataBits   (QSerialPort::Data8);
    loraPort->setParity     (QSerialPort::NoParity);
    loraPort->setStopBits   (QSerialPort::OneStop);
    if (!loraPort->open(QIODevice::WriteOnly)) {
        delete loraPort;
        loraPort = nullptr;
        return false;
    }
    return true;
}

void CamWidget::stopLoRa()
{
    if (!loraPort) return;
    if (loraPort->isOpen()) loraPort->close();
    delete loraPort;
    loraPort = nullptr;
}

void CamWidget::setColorRange(const cv::Scalar& lower, const cv::Scalar& upper)
{
    hsvLower = lower;
    hsvUpper = upper;
}

void CamWidget::grabFrame()
{
    cv::Mat mat;
    if (!cap.isOpened() || !cap.read(mat)) return;

    cv::cvtColor(mat, mat, cv::COLOR_BGR2RGB);
    processAndDetect(mat);

    QImage img((uchar*)mat.data, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
    {
        QMutexLocker lock(&mutex);
        frame = img.copy();
    }
    update();
}

void CamWidget::processAndDetect(cv::Mat& mat)
{
    cv::Mat hsv, mask;
    cv::cvtColor(mat, hsv, cv::COLOR_RGB2HSV);
    cv::inRange(hsv, hsvLower, hsvUpper, mask);

    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(mask, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

    int count = 0;
    for (auto &c : contours) {
        if (cv::contourArea(c) < minContourArea) continue;
        cv::Rect r = cv::boundingRect(c);
        cv::rectangle(mat, r, cv::Scalar(255,0,0), 2);
        ++count;
    }

    if (loraPort && count > 0) {
        sendLoRaMessage(QString("OBJ:%1").arg(count));
    }
}

void CamWidget::sendLoRaMessage(const QString& msg)
{
    if (!loraPort) return;
    QByteArray data = msg.toUtf8() + '\n';
    loraPort->write(data);
}

void CamWidget::paintEvent(QPaintEvent* ev)
{
    QWidget::paintEvent(ev);
    QPainter p(this);
    QMutexLocker lock(&mutex);
    if (!frame.isNull()) {
        QImage scaled = frame.scaled(size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
        int x = (width() - scaled.width())/2;
        int y = (height() - scaled.height())/2;
        p.drawImage(x, y, scaled);
    }
}
