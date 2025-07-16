#ifndef CONNECTIONSETTINGSDIALOG_H
#define CONNECTIONSETTINGSDIALOG_H

#include <QDialog>

namespace Ui {
class ConnectionSettingsDialog;
}

class ConnectionSettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ConnectionSettingsDialog(QWidget *parent = nullptr);
    ~ConnectionSettingsDialog();

    QString portName() const;
    int     baudRate() const;

private:
    Ui::ConnectionSettingsDialog *ui;
};

#endif // CONNECTIONSETTINGSDIALOG_H
