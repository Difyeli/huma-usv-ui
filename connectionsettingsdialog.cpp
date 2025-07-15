#include "connectionsettingsdialog.h"
#include "ui_connectionsettingsdialog.h"

ConnectionSettingsDialog::ConnectionSettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConnectionSettingsDialog)
{
    ui->setupUi(this);

    // 1) Portları ekle: COM1..COM8
    for (int i = 1; i <= 9; ++i)
        ui->portComboBox->addItem(QString("COM%1").arg(i));

    // 2) Baud rate’leri ekle
    const QList<qint32> bauds = {2400, 4800, 9600, 14400, 19200};
    for (auto b : bauds)
        ui->baudComboBox->addItem(QString::number(b), b);

    // 3) Varsayılan seçimler
    ui->portComboBox->setCurrentText("COM9");
    ui->baudComboBox->setCurrentText("9600");
}

ConnectionSettingsDialog::~ConnectionSettingsDialog()
{
    delete ui;
}

QString ConnectionSettingsDialog::portName() const
{
    return ui->portComboBox->currentText();
}

qint32 ConnectionSettingsDialog::baudRate() const
{
    return ui->baudComboBox->currentData().toInt();
}
