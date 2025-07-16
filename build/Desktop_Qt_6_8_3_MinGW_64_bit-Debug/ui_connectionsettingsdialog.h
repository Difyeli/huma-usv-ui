/********************************************************************************
** Form generated from reading UI file 'connectionsettingsdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNECTIONSETTINGSDIALOG_H
#define UI_CONNECTIONSETTINGSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConnectionSettingsDialog
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QComboBox *portComboBox;
    QComboBox *baudComboBox;
    QLabel *label_2;

    void setupUi(QDialog *ConnectionSettingsDialog)
    {
        if (ConnectionSettingsDialog->objectName().isEmpty())
            ConnectionSettingsDialog->setObjectName("ConnectionSettingsDialog");
        ConnectionSettingsDialog->resize(387, 263);
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Light, brush1);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush1);
        QBrush brush2(QColor(127, 127, 127, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush2);
        QBrush brush3(QColor(170, 170, 170, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
        QBrush brush4(QColor(255, 255, 220, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        QBrush brush5(QColor(0, 0, 0, 127));
        brush5.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
#if QT_VERSION >= QT_VERSION_CHECK(6, 6, 0)
        palette.setBrush(QPalette::Active, QPalette::Accent, brush1);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
#if QT_VERSION >= QT_VERSION_CHECK(6, 6, 0)
        palette.setBrush(QPalette::Inactive, QPalette::Accent, brush1);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        QBrush brush6(QColor(127, 127, 127, 127));
        brush6.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush6);
#endif
#if QT_VERSION >= QT_VERSION_CHECK(6, 6, 0)
        palette.setBrush(QPalette::Disabled, QPalette::Accent, brush1);
#endif
        ConnectionSettingsDialog->setPalette(palette);
        buttonBox = new QDialogButtonBox(ConnectionSettingsDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(10, 220, 351, 32));
        buttonBox->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        formLayoutWidget = new QWidget(ConnectionSettingsDialog);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(90, 60, 211, 96));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(11);
        label->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        portComboBox = new QComboBox(formLayoutWidget);
        portComboBox->setObjectName("portComboBox");
        portComboBox->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        formLayout->setWidget(0, QFormLayout::FieldRole, portComboBox);

        baudComboBox = new QComboBox(formLayoutWidget);
        baudComboBox->setObjectName("baudComboBox");
        baudComboBox->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        formLayout->setWidget(1, QFormLayout::FieldRole, baudComboBox);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName("label_2");
        label_2->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);


        retranslateUi(ConnectionSettingsDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, ConnectionSettingsDialog, qOverload<>(&QDialog::reject));
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, ConnectionSettingsDialog, qOverload<>(&QDialog::accept));

        QMetaObject::connectSlotsByName(ConnectionSettingsDialog);
    } // setupUi

    void retranslateUi(QDialog *ConnectionSettingsDialog)
    {
        ConnectionSettingsDialog->setWindowTitle(QCoreApplication::translate("ConnectionSettingsDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("ConnectionSettingsDialog", "Port :", nullptr));
        label_2->setText(QCoreApplication::translate("ConnectionSettingsDialog", "Baud Rate :", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ConnectionSettingsDialog: public Ui_ConnectionSettingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECTIONSETTINGSDIALOG_H
