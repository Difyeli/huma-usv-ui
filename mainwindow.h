    #ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QSerialPortInfo>
#include <QtSerialPort/QSerialPort>
#include <QMainWindow>
#include <QtCharts/QSplineSeries>
#include <QtCharts/QValueAxis>
#include <QToolTip>
#include <QCursor>
#include <QPainter>
#include <QQuickWidget>
#include <QQmlContext>
#include <QFile>
#include <QTextStream>
#include <QDateTime>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class QTableWidgetItem;
class QPushButton;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Q_INVOKABLE void addWaypoint(double lat, double lon);
    Q_INVOKABLE void removeWaypointAt(int index);
    Q_INVOKABLE void updateWaypointAt(int index, double lat, double lon);

private slots:
    void handleSerialData();
    void showDataPoint(const QPointF &point, bool state);
    void on_settingsButton_clicked();
    void on_sendButton_clicked();
    void on_emergencyButton_clicked();
    void on_connectButton_clicked();
    void on_sendParamButton_clicked();
    void handleDeleteButton();
    void handleItemChanged(QTableWidgetItem *item);

signals:
    void telemetryReceived(const QByteArray &data);
    void connectionStatusChanged(bool);

private:

    void updateMapPosition(double lat, double lon);
    void updateMapHeading(double heading);

    Ui::MainWindow *ui;
    QSerialPort  *serial;
    QChart       *speedChart;
    QSplineSeries *setPointSeries{nullptr};
    QSplineSeries *actualSeries{nullptr};
    QValueAxis    *axisX{nullptr};
    QValueAxis    *axisY{nullptr};
    qreal         elapsedTime;
    bool            idaConnected = false;
    QString         currentPortName = "COM8";
    qint32          currentBaudRate = QSerialPort::Baud9600;

    // --- CSV kaydıyla ilgili üyeler ---
    QFile          *csvFile    = nullptr;
    QTextStream    *csvStream  = nullptr;
    bool            recording  = false;

    QList<QWidget*>   m_waypointRows;
    // QML’den gelen tıklamaları yakalamak için slot

    QObject *m_waypointModel = nullptr;


    const qreal    windowDuration = 30.0;

};
#endif // MAINWINDOW_H
