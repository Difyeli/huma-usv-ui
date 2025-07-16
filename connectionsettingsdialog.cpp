#include "connectionsettingsdialog.h"
#include "ui_connectionsettingsdialog.h"
#include <QtSerialPort/QSerialPortInfo>

ConnectionSettingsDialog::ConnectionSettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConnectionSettingsDialog)
{
    ui->setupUi(this);

    // --- Sadece mevcut portları listele ---
    ui->portComboBox->clear();
    const auto ports = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &info : ports) {
        ui->portComboBox->addItem(info.portName());
    }

    // İstersen baud rate listesini de böyle sabitle
    ui->baudComboBox->clear();
    ui->baudComboBox->addItems({ "2400", "4800", "9600", "19200", "38400", "57600", "115200" });
}

ConnectionSettingsDialog::~ConnectionSettingsDialog()
{
    delete ui;
}

QString ConnectionSettingsDialog::portName() const
{
    return ui->portComboBox->currentText();
}

int ConnectionSettingsDialog::baudRate() const
{
    return ui->baudComboBox->currentText().toInt();
}
