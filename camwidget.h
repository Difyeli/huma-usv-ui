// camwidget.h
#ifndef CAMWIDGET_H
#define CAMWIDGET_H

#include <QWidget>
#include <QTimer>
#include <QImage>
#include <QMutex>
#include <QtSerialPort/QSerialPort>
#include <opencv2/opencv.hpp>

class CamWidget : public QWidget {
    Q_OBJECT
public:
    explicit CamWidget(QWidget* parent = nullptr);
    ~CamWidget();

    /// Kamera kaynağını aç: "0","1",... veya rtsp URL
    bool startCamera(const QString &source = "0");
    void stopCamera();

    /// LoRa E22 için seri portu aç
    bool startLoRa(const QString &portName, int baudRate = 9600);
    void stopLoRa();

    /// Renk tespiti HSV aralığını değiştir
    void setColorRange(const cv::Scalar& lower, const cv::Scalar& upper);

protected:
    void paintEvent(QPaintEvent* event) override;

private slots:
    void grabFrame();

private:
    void processAndDetect(cv::Mat& mat);
    void sendLoRaMessage(const QString& msg);

    cv::VideoCapture cap;
    QTimer*        timer;
    QImage         frame;
    QMutex         mutex;

    // HSV renk tespiti
    cv::Scalar     hsvLower{0, 100, 100};
    cv::Scalar     hsvUpper{10, 255, 255};
    int            minContourArea{500};

    // LoRa portu
    QSerialPort*   loraPort{nullptr};
};

#endif // CAMWIDGET_H
