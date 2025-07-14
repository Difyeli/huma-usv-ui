#ifndef MAPWIDGET_H
#define MAPWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QQuickWidget>
#include <QQmlContext>
#include <QTimer>
#include <QTcpServer>
#include <QTcpSocket>
#include <QJsonDocument>
#include <QJsonObject>
#include <QGeoCoordinate>

class MapWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MapWidget(QWidget *parent = nullptr);
    ~MapWidget();

    // Telemetri verileri için API
    void updateVehiclePosition(double latitude, double longitude, double heading = 0.0);
    void updateVehicleData(double pitch, double roll, double yaw, double speed);
    void setConnectionStatus(bool connected);

private slots:
    // UI kontrolleri
    void onZoomInClicked();
    void onZoomOutClicked();
    void onCenterOnVehicle();
    void onToggleSimulation();
    void simulateMovement();

    // TCP server
    void onNewConnection();
    void onReadyRead();
    void onDisconnected();

private:
    void setupUI();
    void setupQMLMap();
    void startTCPServer();
    void processGPSData(const QJsonObject &data);

    // Layout ve widget’lar
    QVBoxLayout *m_mainLayout;
    QHBoxLayout *m_controlLayout;
    QQuickWidget *m_mapWidget;

    // Kontrol butonları + durum
    QPushButton *m_zoomInBtn;
    QPushButton *m_zoomOutBtn;
    QPushButton *m_centerBtn;
    QPushButton *m_simulationBtn;
    QLabel      *m_statusLabel;
    QLabel      *m_coordLabel;

    // Araç verileri
    QGeoCoordinate m_vehiclePosition;
    double         m_vehicleHeading;
    double         m_vehiclePitch;
    double         m_vehicleRoll;
    double         m_vehicleYaw;
    double         m_vehicleSpeed;
    bool           m_isConnected;

    // Simülasyon
    QTimer *m_simulationTimer;
    bool    m_simulationActive;
    double  m_simAngle;

    // TCP Server (opsiyonel)
    QTcpServer *m_tcpServer;
    QTcpSocket *m_tcpSocket;

    // Map zoom seviyesi
    double m_currentZoom;
};

#endif // MAPWIDGET_H
