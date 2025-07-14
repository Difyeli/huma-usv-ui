#include "mapwidget.h"

#include <QQuickWidget>
#include <QQmlContext>
#include <QVBoxLayout>
#include <QDebug>
#include <QtMath>

MapWidget::MapWidget(QWidget *parent)
    : QWidget(parent),
    m_mainLayout(new QVBoxLayout(this)),
    m_controlLayout(new QHBoxLayout),
    m_mapWidget(new QQuickWidget(this)),
    m_zoomInBtn(new QPushButton("+", this)),
    m_zoomOutBtn(new QPushButton("−", this)),
    m_centerBtn(new QPushButton("O", this)),
    m_simulationBtn(new QPushButton("Sim", this)),
    m_statusLabel(new QLabel("Pasif", this)),
    m_coordLabel(new QLabel("0, 0", this)),
    m_simulationTimer(new QTimer(this)),
    m_tcpServer(new QTcpServer(this)),
    m_tcpSocket(nullptr),
    m_currentZoom(14.0),
    m_simulationActive(false),
    m_simAngle(0.0)
{
    // ➊ UI Kurulumu
    setupUI();

    // ➋ QML Harita Yükle
    m_mapWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);
    m_mapWidget->rootContext()->setContextProperty("mapBackend", this);
    m_mapWidget->setSource(QUrl(QStringLiteral("qrc:/qml/MapView.qml")));
    connect(m_mapWidget, &QQuickWidget::statusChanged, this, [&](QQuickWidget::Status st){
        if (st == QQuickWidget::Error) {
            qWarning() << "Map load errors:" << m_mapWidget->errors();
        }
    });

    // ➌ TCP Server Başlat (opsiyonel)
    if (!m_tcpServer->listen(QHostAddress::Any, 5000))
        qWarning() << "TCP Server error:" << m_tcpServer->errorString();
    connect(m_tcpServer, &QTcpServer::newConnection,
            this, &MapWidget::onNewConnection);

    // ➍ Simülasyon Timer
    connect(m_simulationTimer, &QTimer::timeout,
            this, &MapWidget::simulateMovement);
}

MapWidget::~MapWidget()
{
    // Qt parent-child mekaniği çocukları siler
}

void MapWidget::setupUI()
{
    // Buton boyutları
    m_zoomInBtn->setFixedSize(24,24);
    m_zoomOutBtn->setFixedSize(24,24);
    m_centerBtn->setFixedSize(24,24);
    m_simulationBtn->setFixedSize(50,24);

    // Kontrol satırı
    m_controlLayout->addWidget(m_zoomInBtn);
    m_controlLayout->addWidget(m_zoomOutBtn);
    m_controlLayout->addWidget(m_centerBtn);
    m_controlLayout->addWidget(m_simulationBtn);
    m_controlLayout->addStretch();
    m_controlLayout->addWidget(m_statusLabel);
    m_controlLayout->addWidget(m_coordLabel);

    // Ana layout: önce kontrol satırı, sonra harita
    m_mainLayout->addLayout(m_controlLayout);
    m_mainLayout->addWidget(m_mapWidget);
    setLayout(m_mainLayout);

    // Sinyal-slot bağlantıları
    connect(m_zoomInBtn,     &QPushButton::clicked, this, &MapWidget::onZoomInClicked);
    connect(m_zoomOutBtn,    &QPushButton::clicked, this, &MapWidget::onZoomOutClicked);
    connect(m_centerBtn,     &QPushButton::clicked, this, &MapWidget::onCenterOnVehicle);
    connect(m_simulationBtn, &QPushButton::clicked, this, &MapWidget::onToggleSimulation);
}

void MapWidget::onNewConnection()
{
    m_tcpSocket = m_tcpServer->nextPendingConnection();
    connect(m_tcpSocket, &QTcpSocket::readyRead,    this, &MapWidget::onReadyRead);
    connect(m_tcpSocket, &QTcpSocket::disconnected, this, &MapWidget::onDisconnected);
    setConnectionStatus(true);
}

void MapWidget::onReadyRead()
{
    auto data = m_tcpSocket->readAll();
    QJsonDocument doc = QJsonDocument::fromJson(data);
    if (doc.isObject()) processGPSData(doc.object());
}

void MapWidget::onDisconnected()
{
    m_tcpSocket->deleteLater();
    m_tcpSocket = nullptr;
    setConnectionStatus(false);
}

void MapWidget::processGPSData(const QJsonObject &obj)
{
    if (obj.contains("latitude") && obj.contains("longitude")) {
        double lat = obj["latitude"].toDouble();
        double lon = obj["longitude"].toDouble();
        double hdg = obj.value("heading").toDouble();
        updateVehiclePosition(lat, lon, hdg);
    }
    if (obj.contains("speed")) {
        updateVehicleData(0,0,0, obj["speed"].toDouble());
    }
}

void MapWidget::updateVehiclePosition(double latitude, double longitude, double heading)
{
    // Koordinat etiketi güncelle
    m_coordLabel->setText(
        QString("%1, %2").arg(latitude,0,'f',6).arg(longitude,0,'f',6));

    m_vehiclePosition = QGeoCoordinate(latitude, longitude);
    m_vehicleHeading  = heading;

    // QML tarafını güncelle
    if (auto root = m_mapWidget->rootObject()) {
        root->setProperty("vehicleLat",     latitude);
        root->setProperty("vehicleLon",     longitude);
        root->setProperty("vehicleHeading", heading);
    }
}

void MapWidget::updateVehicleData(double pitch, double roll, double yaw, double speed)
{
    m_vehiclePitch = pitch;
    m_vehicleRoll  = roll;
    m_vehicleYaw   = yaw;
    m_vehicleSpeed = speed;
    // İstersen burada da bir hız etiketi güncelle
}

void MapWidget::setConnectionStatus(bool connected)
{
    m_isConnected = connected;
    m_statusLabel->setText(connected ? "Bağlı" : "Pasif");
    m_statusLabel->setStyleSheet(connected ? "color:green;" : "color:red;");
}

void MapWidget::onZoomInClicked()
{
    m_currentZoom = qMin(m_currentZoom + 1.0, 20.0);
    if (auto r = m_mapWidget->rootObject())
        r->setProperty("currentZoom", m_currentZoom);
}

void MapWidget::onZoomOutClicked()
{
    m_currentZoom = qMax(m_currentZoom - 1.0, 1.0);
    if (auto r = m_mapWidget->rootObject())
        r->setProperty("currentZoom", m_currentZoom);
}

void MapWidget::onCenterOnVehicle()
{
    if (auto r = m_mapWidget->rootObject())
        QMetaObject::invokeMethod(r, "centerOnVehicle");
}

void MapWidget::onToggleSimulation()
{
    m_simulationActive = !m_simulationActive;
    if (m_simulationActive) {
        m_simulationBtn->setText("Stop");
        m_simulationTimer->start(500);
    } else {
        m_simulationBtn->setText("Sim");
        m_simulationTimer->stop();
    }
}

void MapWidget::simulateMovement()
{
    m_simAngle += 10.0;
    double lat = m_vehiclePosition.latitude()
                 + 0.0001 * qCos(qDegreesToRadians(m_simAngle));
    double lon = m_vehiclePosition.longitude()
                 + 0.0001 * qSin(qDegreesToRadians(m_simAngle));
    updateVehiclePosition(lat, lon, m_simAngle);
}
