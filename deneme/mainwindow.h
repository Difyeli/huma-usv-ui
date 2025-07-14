#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtSerialPort/QSerialPort>
#include <QMainWindow>
#include <QtCharts/QLineSeries>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void handleSerialData();

private:
    Ui::MainWindow *ui;
    QChart       *speedChart;
    QLineSeries  *setPointSeries;
    QLineSeries  *actualSeries;
    QSerialPort  *serial;
    qreal         elapsedTime;
};
#endif // MAINWINDOW_H
