/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCharts/QChartView>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtQuickWidgets/QQuickWidget>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionMainMenu;
    QAction *actionSettings;
    QWidget *centralwidget;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *Pitch;
    QLabel *Pitch_Data;
    QLabel *Roll;
    QLabel *Roll_Data;
    QLabel *Yaw;
    QLabel *Yaw_Data;
    QLabel *Yon;
    QLabel *Yon_Data;
    QLabel *GPS_Label1;
    QLabel *Longitude;
    QLabel *GPS_Label2;
    QLabel *Latitude;
    QLabel *Voltage;
    QLabel *Voltage_Data;
    QLabel *SicaklikLabel;
    QLabel *Sicaklik_Data;
    QLabel *Quest;
    QLabel *QuestNo;
    QLabel *SetPointLabel;
    QLabel *SetPoint_Data;
    QLabel *Speed;
    QLabel *Speed_Data;
    QLabel *SpeedFrame;
    QLabel *label;
    QChartView *SpeedGraph;
    QLabel *Speed_txt;
    QLabel *Setpoint_txt;
    QLabel *label_4;
    QLabel *label_6;
    QLabel *MapLabel;
    QWidget *formLayoutWidget_2;
    QFormLayout *formLayout_2;
    QLabel *ConStat_2;
    QLabel *statusValueLabel;
    QLabel *Port;
    QLabel *portValueLabel;
    QLabel *Baud;
    QLabel *baudValueLabel;
    QPushButton *connectButton;
    QLabel *label_7;
    QPushButton *settingsButton;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label_5;
    QLabel *ConnectionLogo;
    QLabel *label_9;
    QLabel *label_8;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *PID_frame;
    QLabel *label_15;
    QQuickWidget *mapQuickWidget;
    QTableWidget *questTable;
    QPushButton *sendButton;
    QPushButton *emergencyButton;
    QTableWidget *parametersTable;
    QPushButton *sendParamButton;
    QLabel *label_16;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1540, 900);
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(229, 229, 229, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(255, 255, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(242, 242, 242, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(114, 114, 114, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(153, 153, 153, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush3);
        QBrush brush6(QColor(255, 255, 220, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        QBrush brush7(QColor(0, 0, 0, 127));
        brush7.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush7);
#endif
#if QT_VERSION >= QT_VERSION_CHECK(6, 6, 0)
        palette.setBrush(QPalette::Active, QPalette::Accent, brush2);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush7);
#endif
#if QT_VERSION >= QT_VERSION_CHECK(6, 6, 0)
        palette.setBrush(QPalette::Inactive, QPalette::Accent, brush2);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        QBrush brush8(QColor(114, 114, 114, 127));
        brush8.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush8);
#endif
#if QT_VERSION >= QT_VERSION_CHECK(6, 6, 0)
        palette.setBrush(QPalette::Disabled, QPalette::Accent, brush2);
#endif
        MainWindow->setPalette(palette);
        MainWindow->setAutoFillBackground(true);
        actionMainMenu = new QAction(MainWindow);
        actionMainMenu->setObjectName("actionMainMenu");
        actionSettings = new QAction(MainWindow);
        actionSettings->setObjectName("actionSettings");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setEnabled(true);
        centralwidget->setAutoFillBackground(true);
        formLayoutWidget = new QWidget(centralwidget);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(930, 150, 221, 401));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setHorizontalSpacing(67);
        formLayout->setVerticalSpacing(17);
        formLayout->setContentsMargins(0, 0, 0, 0);
        Pitch = new QLabel(formLayoutWidget);
        Pitch->setObjectName("Pitch");
        QFont font;
        font.setBold(true);
        Pitch->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, Pitch);

        Pitch_Data = new QLabel(formLayoutWidget);
        Pitch_Data->setObjectName("Pitch_Data");
        Pitch_Data->setFont(font);
        Pitch_Data->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        formLayout->setWidget(0, QFormLayout::FieldRole, Pitch_Data);

        Roll = new QLabel(formLayoutWidget);
        Roll->setObjectName("Roll");
        Roll->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, Roll);

        Roll_Data = new QLabel(formLayoutWidget);
        Roll_Data->setObjectName("Roll_Data");
        Roll_Data->setFont(font);
        Roll_Data->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        formLayout->setWidget(1, QFormLayout::FieldRole, Roll_Data);

        Yaw = new QLabel(formLayoutWidget);
        Yaw->setObjectName("Yaw");
        Yaw->setFont(font);

        formLayout->setWidget(2, QFormLayout::LabelRole, Yaw);

        Yaw_Data = new QLabel(formLayoutWidget);
        Yaw_Data->setObjectName("Yaw_Data");
        Yaw_Data->setFont(font);
        Yaw_Data->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        formLayout->setWidget(2, QFormLayout::FieldRole, Yaw_Data);

        Yon = new QLabel(formLayoutWidget);
        Yon->setObjectName("Yon");
        Yon->setFont(font);

        formLayout->setWidget(3, QFormLayout::LabelRole, Yon);

        Yon_Data = new QLabel(formLayoutWidget);
        Yon_Data->setObjectName("Yon_Data");
        Yon_Data->setFont(font);
        Yon_Data->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        formLayout->setWidget(3, QFormLayout::FieldRole, Yon_Data);

        GPS_Label1 = new QLabel(formLayoutWidget);
        GPS_Label1->setObjectName("GPS_Label1");
        GPS_Label1->setFont(font);

        formLayout->setWidget(4, QFormLayout::LabelRole, GPS_Label1);

        Longitude = new QLabel(formLayoutWidget);
        Longitude->setObjectName("Longitude");
        Longitude->setFont(font);
        Longitude->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        formLayout->setWidget(4, QFormLayout::FieldRole, Longitude);

        GPS_Label2 = new QLabel(formLayoutWidget);
        GPS_Label2->setObjectName("GPS_Label2");
        GPS_Label2->setFont(font);

        formLayout->setWidget(5, QFormLayout::LabelRole, GPS_Label2);

        Latitude = new QLabel(formLayoutWidget);
        Latitude->setObjectName("Latitude");
        Latitude->setFont(font);
        Latitude->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        formLayout->setWidget(5, QFormLayout::FieldRole, Latitude);

        Voltage = new QLabel(formLayoutWidget);
        Voltage->setObjectName("Voltage");
        Voltage->setFont(font);

        formLayout->setWidget(6, QFormLayout::LabelRole, Voltage);

        Voltage_Data = new QLabel(formLayoutWidget);
        Voltage_Data->setObjectName("Voltage_Data");
        Voltage_Data->setFont(font);
        Voltage_Data->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        formLayout->setWidget(6, QFormLayout::FieldRole, Voltage_Data);

        SicaklikLabel = new QLabel(formLayoutWidget);
        SicaklikLabel->setObjectName("SicaklikLabel");
        SicaklikLabel->setFont(font);

        formLayout->setWidget(7, QFormLayout::LabelRole, SicaklikLabel);

        Sicaklik_Data = new QLabel(formLayoutWidget);
        Sicaklik_Data->setObjectName("Sicaklik_Data");
        Sicaklik_Data->setFont(font);
        Sicaklik_Data->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        formLayout->setWidget(7, QFormLayout::FieldRole, Sicaklik_Data);

        Quest = new QLabel(formLayoutWidget);
        Quest->setObjectName("Quest");
        Quest->setFont(font);

        formLayout->setWidget(8, QFormLayout::LabelRole, Quest);

        QuestNo = new QLabel(formLayoutWidget);
        QuestNo->setObjectName("QuestNo");
        QuestNo->setFont(font);
        QuestNo->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        formLayout->setWidget(8, QFormLayout::FieldRole, QuestNo);

        SetPointLabel = new QLabel(formLayoutWidget);
        SetPointLabel->setObjectName("SetPointLabel");
        SetPointLabel->setFont(font);

        formLayout->setWidget(9, QFormLayout::LabelRole, SetPointLabel);

        SetPoint_Data = new QLabel(formLayoutWidget);
        SetPoint_Data->setObjectName("SetPoint_Data");
        SetPoint_Data->setFont(font);
        SetPoint_Data->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        formLayout->setWidget(9, QFormLayout::FieldRole, SetPoint_Data);

        Speed = new QLabel(formLayoutWidget);
        Speed->setObjectName("Speed");
        Speed->setFont(font);

        formLayout->setWidget(10, QFormLayout::LabelRole, Speed);

        Speed_Data = new QLabel(formLayoutWidget);
        Speed_Data->setObjectName("Speed_Data");
        Speed_Data->setFont(font);
        Speed_Data->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        formLayout->setWidget(10, QFormLayout::FieldRole, Speed_Data);

        SpeedFrame = new QLabel(centralwidget);
        SpeedFrame->setObjectName("SpeedFrame");
        SpeedFrame->setGeometry(QRect(350, 440, 551, 334));
        SpeedFrame->setPixmap(QPixmap(QString::fromUtf8(":/images/Background2.png")));
        SpeedFrame->setScaledContents(true);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(570, 450, 123, 28));
        QPalette palette1;
        QBrush brush9(QColor(45, 55, 72, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush9);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush9);
        label->setPalette(palette1);
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        label->setFont(font1);
        label->setTextFormat(Qt::TextFormat::RichText);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        SpeedGraph = new QChartView(centralwidget);
        SpeedGraph->setObjectName("SpeedGraph");
        SpeedGraph->setGeometry(QRect(360, 456, 531, 297));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette2.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette2.setBrush(QPalette::Active, QPalette::Midlight, brush2);
        QBrush brush10(QColor(127, 127, 127, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Dark, brush10);
        QBrush brush11(QColor(170, 170, 170, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Mid, brush11);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        palette2.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette2.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Active, QPalette::AlternateBase, brush2);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Active, QPalette::PlaceholderText, brush7);
#endif
#if QT_VERSION >= QT_VERSION_CHECK(6, 6, 0)
        palette2.setBrush(QPalette::Active, QPalette::Accent, brush2);
#endif
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Midlight, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Dark, brush10);
        palette2.setBrush(QPalette::Inactive, QPalette::Mid, brush11);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush7);
#endif
#if QT_VERSION >= QT_VERSION_CHECK(6, 6, 0)
        palette2.setBrush(QPalette::Inactive, QPalette::Accent, brush2);
#endif
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush10);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Midlight, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Dark, brush10);
        palette2.setBrush(QPalette::Disabled, QPalette::Mid, brush11);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush10);
        palette2.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush10);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        QBrush brush12(QColor(127, 127, 127, 127));
        brush12.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush12);
#endif
#if QT_VERSION >= QT_VERSION_CHECK(6, 6, 0)
        palette2.setBrush(QPalette::Disabled, QPalette::Accent, brush2);
#endif
        SpeedGraph->setPalette(palette2);
        Speed_txt = new QLabel(SpeedGraph);
        Speed_txt->setObjectName("Speed_txt");
        Speed_txt->setGeometry(QRect(200, 260, 61, 20));
        QPalette palette3;
        QBrush brush13(QColor(0, 154, 250, 255));
        brush13.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush13);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush13);
        Speed_txt->setPalette(palette3);
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(true);
        Speed_txt->setFont(font2);
        Setpoint_txt = new QLabel(SpeedGraph);
        Setpoint_txt->setObjectName("Setpoint_txt");
        Setpoint_txt->setGeometry(QRect(280, 260, 61, 20));
        QPalette palette4;
        QBrush brush14(QColor(0, 170, 0, 255));
        brush14.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush14);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush14);
        Setpoint_txt->setPalette(palette4);
        Setpoint_txt->setFont(font2);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(350, 90, 551, 351));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/images/Background2.png")));
        label_4->setScaledContents(true);
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(20, 90, 331, 351));
        label_6->setPixmap(QPixmap(QString::fromUtf8(":/images/Background3.png")));
        label_6->setScaledContents(true);
        MapLabel = new QLabel(centralwidget);
        MapLabel->setObjectName("MapLabel");
        MapLabel->setGeometry(QRect(610, 100, 45, 28));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        MapLabel->setPalette(palette5);
        MapLabel->setFont(font1);
        MapLabel->setTextFormat(Qt::TextFormat::RichText);
        MapLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        formLayoutWidget_2 = new QWidget(centralwidget);
        formLayoutWidget_2->setObjectName("formLayoutWidget_2");
        formLayoutWidget_2->setGeometry(QRect(1200, 144, 221, 121));
        formLayout_2 = new QFormLayout(formLayoutWidget_2);
        formLayout_2->setObjectName("formLayout_2");
        formLayout_2->setHorizontalSpacing(60);
        formLayout_2->setVerticalSpacing(15);
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        ConStat_2 = new QLabel(formLayoutWidget_2);
        ConStat_2->setObjectName("ConStat_2");
        ConStat_2->setFont(font);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, ConStat_2);

        statusValueLabel = new QLabel(formLayoutWidget_2);
        statusValueLabel->setObjectName("statusValueLabel");
        statusValueLabel->setFont(font);
        statusValueLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, statusValueLabel);

        Port = new QLabel(formLayoutWidget_2);
        Port->setObjectName("Port");
        Port->setFont(font);

        formLayout_2->setWidget(1, QFormLayout::LabelRole, Port);

        portValueLabel = new QLabel(formLayoutWidget_2);
        portValueLabel->setObjectName("portValueLabel");
        portValueLabel->setFont(font);
        portValueLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, portValueLabel);

        Baud = new QLabel(formLayoutWidget_2);
        Baud->setObjectName("Baud");
        Baud->setFont(font);

        formLayout_2->setWidget(2, QFormLayout::LabelRole, Baud);

        baudValueLabel = new QLabel(formLayoutWidget_2);
        baudValueLabel->setObjectName("baudValueLabel");
        baudValueLabel->setFont(font);
        baudValueLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        formLayout_2->setWidget(2, QFormLayout::FieldRole, baudValueLabel);

        connectButton = new QPushButton(centralwidget);
        connectButton->setObjectName("connectButton");
        connectButton->setGeometry(QRect(1220, 244, 180, 30));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette6.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette6.setBrush(QPalette::Active, QPalette::Midlight, brush2);
        palette6.setBrush(QPalette::Active, QPalette::Dark, brush10);
        palette6.setBrush(QPalette::Active, QPalette::Mid, brush11);
        palette6.setBrush(QPalette::Active, QPalette::Text, brush);
        palette6.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette6.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette6.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette6.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette6.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette6.setBrush(QPalette::Active, QPalette::AlternateBase, brush2);
        palette6.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette6.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette6.setBrush(QPalette::Active, QPalette::PlaceholderText, brush7);
#endif
#if QT_VERSION >= QT_VERSION_CHECK(6, 6, 0)
        palette6.setBrush(QPalette::Active, QPalette::Accent, brush2);
#endif
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette6.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette6.setBrush(QPalette::Inactive, QPalette::Midlight, brush2);
        palette6.setBrush(QPalette::Inactive, QPalette::Dark, brush10);
        palette6.setBrush(QPalette::Inactive, QPalette::Mid, brush11);
        palette6.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette6.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette6.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette6.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush2);
        palette6.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette6.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette6.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush7);
#endif
#if QT_VERSION >= QT_VERSION_CHECK(6, 6, 0)
        palette6.setBrush(QPalette::Inactive, QPalette::Accent, brush2);
#endif
        palette6.setBrush(QPalette::Disabled, QPalette::WindowText, brush10);
        palette6.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette6.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette6.setBrush(QPalette::Disabled, QPalette::Midlight, brush2);
        palette6.setBrush(QPalette::Disabled, QPalette::Dark, brush10);
        palette6.setBrush(QPalette::Disabled, QPalette::Mid, brush11);
        palette6.setBrush(QPalette::Disabled, QPalette::Text, brush10);
        palette6.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette6.setBrush(QPalette::Disabled, QPalette::ButtonText, brush10);
        palette6.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette6.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        palette6.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush2);
        palette6.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette6.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette6.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush12);
#endif
#if QT_VERSION >= QT_VERSION_CHECK(6, 6, 0)
        palette6.setBrush(QPalette::Disabled, QPalette::Accent, brush2);
#endif
        connectButton->setPalette(palette6);
        connectButton->setFont(font);
        connectButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/ConnectButton.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        icon.addFile(QString::fromUtf8(":/images/DisconnectButton.png"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        icon.addFile(QString::fromUtf8(":/images/DisconnectButton.png"), QSize(), QIcon::Mode::Active, QIcon::State::On);
        icon.addFile(QString::fromUtf8(":/images/DisconnectButton.png"), QSize(), QIcon::Mode::Selected, QIcon::State::On);
        connectButton->setIcon(icon);
        connectButton->setIconSize(QSize(250, 34));
        connectButton->setCheckable(true);
        connectButton->setChecked(false);
        connectButton->setFlat(true);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(140, 95, 101, 31));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        palette7.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        label_7->setPalette(palette7);
        label_7->setFont(font1);
        label_7->setTextFormat(Qt::TextFormat::RichText);
        label_7->setAlignment(Qt::AlignmentFlag::AlignCenter);
        settingsButton = new QPushButton(centralwidget);
        settingsButton->setObjectName("settingsButton");
        settingsButton->setGeometry(QRect(1220, 280, 180, 30));
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush15(QColor(16, 191, 255, 255));
        brush15.setStyle(Qt::SolidPattern);
        palette8.setBrush(QPalette::Active, QPalette::Button, brush15);
        QBrush brush16(QColor(143, 225, 255, 255));
        brush16.setStyle(Qt::SolidPattern);
        palette8.setBrush(QPalette::Active, QPalette::Light, brush16);
        QBrush brush17(QColor(79, 208, 255, 255));
        brush17.setStyle(Qt::SolidPattern);
        palette8.setBrush(QPalette::Active, QPalette::Midlight, brush17);
        QBrush brush18(QColor(8, 95, 127, 255));
        brush18.setStyle(Qt::SolidPattern);
        palette8.setBrush(QPalette::Active, QPalette::Dark, brush18);
        QBrush brush19(QColor(11, 127, 170, 255));
        brush19.setStyle(Qt::SolidPattern);
        palette8.setBrush(QPalette::Active, QPalette::Mid, brush19);
        palette8.setBrush(QPalette::Active, QPalette::Text, brush);
        palette8.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette8.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette8.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette8.setBrush(QPalette::Active, QPalette::Window, brush15);
        palette8.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush20(QColor(135, 223, 255, 255));
        brush20.setStyle(Qt::SolidPattern);
        palette8.setBrush(QPalette::Active, QPalette::AlternateBase, brush20);
        palette8.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette8.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette8.setBrush(QPalette::Active, QPalette::PlaceholderText, brush7);
#endif
#if QT_VERSION >= QT_VERSION_CHECK(6, 6, 0)
        palette8.setBrush(QPalette::Active, QPalette::Accent, brush2);
#endif
        palette8.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::Button, brush15);
        palette8.setBrush(QPalette::Inactive, QPalette::Light, brush16);
        palette8.setBrush(QPalette::Inactive, QPalette::Midlight, brush17);
        palette8.setBrush(QPalette::Inactive, QPalette::Dark, brush18);
        palette8.setBrush(QPalette::Inactive, QPalette::Mid, brush19);
        palette8.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette8.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette8.setBrush(QPalette::Inactive, QPalette::Window, brush15);
        palette8.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush20);
        palette8.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette8.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette8.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush7);
#endif
#if QT_VERSION >= QT_VERSION_CHECK(6, 6, 0)
        palette8.setBrush(QPalette::Inactive, QPalette::Accent, brush2);
#endif
        palette8.setBrush(QPalette::Disabled, QPalette::WindowText, brush18);
        palette8.setBrush(QPalette::Disabled, QPalette::Button, brush15);
        palette8.setBrush(QPalette::Disabled, QPalette::Light, brush16);
        palette8.setBrush(QPalette::Disabled, QPalette::Midlight, brush17);
        palette8.setBrush(QPalette::Disabled, QPalette::Dark, brush18);
        palette8.setBrush(QPalette::Disabled, QPalette::Mid, brush19);
        palette8.setBrush(QPalette::Disabled, QPalette::Text, brush18);
        palette8.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette8.setBrush(QPalette::Disabled, QPalette::ButtonText, brush18);
        palette8.setBrush(QPalette::Disabled, QPalette::Base, brush15);
        palette8.setBrush(QPalette::Disabled, QPalette::Window, brush15);
        palette8.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette8.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush15);
        palette8.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette8.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        QBrush brush21(QColor(8, 95, 127, 127));
        brush21.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette8.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush21);
#endif
        QBrush brush22(QColor(92, 211, 255, 255));
        brush22.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(6, 6, 0)
        palette8.setBrush(QPalette::Disabled, QPalette::Accent, brush22);
#endif
        settingsButton->setPalette(palette8);
        settingsButton->setFont(font);
        settingsButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/SettingsButton.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        settingsButton->setIcon(icon1);
        settingsButton->setIconSize(QSize(300, 34));
        settingsButton->setCheckable(true);
        settingsButton->setFlat(true);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(1170, 90, 281, 231));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/images/Background2.png")));
        label_3->setScaledContents(true);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(900, 90, 271, 431));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/images/Background1.png")));
        label_2->setScaledContents(true);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(0, 0, 1540, 900));
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/images/GrayBG.png")));
        label_5->setScaledContents(true);
        ConnectionLogo = new QLabel(centralwidget);
        ConnectionLogo->setObjectName("ConnectionLogo");
        ConnectionLogo->setGeometry(QRect(1240, 104, 28, 28));
        ConnectionLogo->setPixmap(QPixmap(QString::fromUtf8(":/images/ConnectionLogo.png")));
        ConnectionLogo->setScaledContents(true);
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(1260, 110, 111, 20));
        QPalette palette9;
        palette9.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        palette9.setBrush(QPalette::Active, QPalette::Text, brush9);
        palette9.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        palette9.setBrush(QPalette::Inactive, QPalette::Text, brush9);
        label_9->setPalette(palette9);
        label_9->setFont(font1);
        label_9->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(550, 450, 28, 28));
        label_8->setPixmap(QPixmap(QString::fromUtf8(":/images/SpeedLogo.png")));
        label_8->setScaledContents(true);
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(1000, 100, 96, 29));
        QPalette palette10;
        palette10.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        palette10.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        label_10->setPalette(palette10);
        label_10->setFont(font1);
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(580, 100, 28, 28));
        label_11->setPixmap(QPixmap(QString::fromUtf8(":/images/MapLogo.png")));
        label_11->setScaledContents(true);
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(110, 98, 28, 28));
        label_12->setPixmap(QPixmap(QString::fromUtf8(":/images/QuestLogo.png")));
        label_12->setScaledContents(true);
        label_13 = new QLabel(centralwidget);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(970, 100, 28, 28));
        label_13->setPixmap(QPixmap(QString::fromUtf8(":/images/TelemetryLogo.png")));
        label_13->setScaledContents(true);
        label_14 = new QLabel(centralwidget);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(912, 133, 246, 373));
        label_14->setPixmap(QPixmap(QString::fromUtf8(":/images/Background4.png")));
        label_14->setScaledContents(true);
        PID_frame = new QLabel(centralwidget);
        PID_frame->setObjectName("PID_frame");
        PID_frame->setGeometry(QRect(20, 439, 331, 331));
        PID_frame->setPixmap(QPixmap(QString::fromUtf8(":/images/Background3.png")));
        PID_frame->setScaledContents(true);
        label_15 = new QLabel(centralwidget);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(110, 440, 151, 28));
        QPalette palette11;
        palette11.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        palette11.setBrush(QPalette::Active, QPalette::Text, brush9);
        palette11.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        palette11.setBrush(QPalette::Inactive, QPalette::Text, brush9);
        label_15->setPalette(palette11);
        label_15->setFont(font1);
        label_15->setTextFormat(Qt::TextFormat::RichText);
        label_15->setAlignment(Qt::AlignmentFlag::AlignCenter);
        mapQuickWidget = new QQuickWidget(centralwidget);
        mapQuickWidget->setObjectName("mapQuickWidget");
        mapQuickWidget->setGeometry(QRect(370, 130, 511, 291));
        mapQuickWidget->setCursor(QCursor(Qt::CursorShape::CrossCursor));
        mapQuickWidget->setResizeMode(QQuickWidget::ResizeMode::SizeRootObjectToView);
        questTable = new QTableWidget(centralwidget);
        if (questTable->columnCount() < 3)
            questTable->setColumnCount(3);
        QFont font3;
        font3.setBold(true);
        font3.setItalic(true);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font3);
        __qtablewidgetitem->setBackground(QColor(113, 226, 217));
        questTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font3);
        __qtablewidgetitem1->setBackground(QColor(113, 226, 217));
        questTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font3);
        __qtablewidgetitem2->setBackground(QColor(113, 226, 217));
        questTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        questTable->setObjectName("questTable");
        questTable->setGeometry(QRect(35, 130, 301, 261));
        QPalette palette12;
        QBrush brush23(QColor(113, 226, 217, 255));
        brush23.setStyle(Qt::SolidPattern);
        palette12.setBrush(QPalette::Active, QPalette::Button, brush23);
        palette12.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette12.setBrush(QPalette::Active, QPalette::Window, brush23);
        palette12.setBrush(QPalette::Active, QPalette::AlternateBase, brush23);
        palette12.setBrush(QPalette::Inactive, QPalette::Button, brush23);
        palette12.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette12.setBrush(QPalette::Inactive, QPalette::Window, brush23);
        palette12.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush23);
        palette12.setBrush(QPalette::Disabled, QPalette::Button, brush23);
        palette12.setBrush(QPalette::Disabled, QPalette::Base, brush23);
        palette12.setBrush(QPalette::Disabled, QPalette::Window, brush23);
        palette12.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush23);
        questTable->setPalette(palette12);
        questTable->horizontalHeader()->setVisible(true);
        questTable->horizontalHeader()->setCascadingSectionResizes(true);
        questTable->horizontalHeader()->setDefaultSectionSize(92);
        questTable->horizontalHeader()->setStretchLastSection(false);
        sendButton = new QPushButton(centralwidget);
        sendButton->setObjectName("sendButton");
        sendButton->setGeometry(QRect(110, 396, 151, 31));
        QPalette palette13;
        palette13.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette13.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette13.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        sendButton->setPalette(palette13);
        sendButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/sendButton.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        sendButton->setIcon(icon2);
        sendButton->setIconSize(QSize(220, 28));
        sendButton->setFlat(true);
        emergencyButton = new QPushButton(centralwidget);
        emergencyButton->setObjectName("emergencyButton");
        emergencyButton->setGeometry(QRect(1220, 460, 181, 51));
        QPalette palette14;
        palette14.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette14.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette14.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette14.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette14.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette14.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette14.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        emergencyButton->setPalette(palette14);
        emergencyButton->setCursor(QCursor(Qt::CursorShape::OpenHandCursor));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/EmergencyButton.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        emergencyButton->setIcon(icon3);
        emergencyButton->setIconSize(QSize(200, 33));
        emergencyButton->setFlat(true);
        parametersTable = new QTableWidget(centralwidget);
        if (parametersTable->columnCount() < 1)
            parametersTable->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        parametersTable->setHorizontalHeaderItem(0, __qtablewidgetitem3);
        if (parametersTable->rowCount() < 6)
            parametersTable->setRowCount(6);
        parametersTable->setObjectName("parametersTable");
        parametersTable->setGeometry(QRect(40, 470, 301, 241));
        QPalette palette15;
        palette15.setBrush(QPalette::Active, QPalette::Button, brush23);
        palette15.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette15.setBrush(QPalette::Active, QPalette::Window, brush23);
        palette15.setBrush(QPalette::Inactive, QPalette::Button, brush23);
        palette15.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette15.setBrush(QPalette::Inactive, QPalette::Window, brush23);
        palette15.setBrush(QPalette::Disabled, QPalette::Button, brush23);
        palette15.setBrush(QPalette::Disabled, QPalette::Base, brush23);
        palette15.setBrush(QPalette::Disabled, QPalette::Window, brush23);
        parametersTable->setPalette(palette15);
        parametersTable->horizontalHeader()->setDefaultSectionSize(269);
        sendParamButton = new QPushButton(centralwidget);
        sendParamButton->setObjectName("sendParamButton");
        sendParamButton->setGeometry(QRect(130, 720, 111, 29));
        QPalette palette16;
        palette16.setBrush(QPalette::Active, QPalette::Button, brush23);
        palette16.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette16.setBrush(QPalette::Inactive, QPalette::Button, brush23);
        palette16.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette16.setBrush(QPalette::Disabled, QPalette::Button, brush23);
        sendParamButton->setPalette(palette16);
        sendParamButton->setFont(font);
        label_16 = new QLabel(centralwidget);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(1170, 320, 281, 201));
        label_16->setPixmap(QPixmap(QString::fromUtf8(":/images/Background2.png")));
        label_16->setScaledContents(true);
        MainWindow->setCentralWidget(centralwidget);
        label_5->raise();
        label_16->raise();
        PID_frame->raise();
        label_2->raise();
        label_14->raise();
        label_6->raise();
        label_3->raise();
        formLayoutWidget->raise();
        SpeedFrame->raise();
        SpeedGraph->raise();
        label_4->raise();
        MapLabel->raise();
        formLayoutWidget_2->raise();
        connectButton->raise();
        label_7->raise();
        settingsButton->raise();
        label->raise();
        ConnectionLogo->raise();
        label_9->raise();
        label_8->raise();
        label_10->raise();
        label_11->raise();
        label_12->raise();
        label_13->raise();
        label_15->raise();
        mapQuickWidget->raise();
        questTable->raise();
        sendButton->raise();
        emergencyButton->raise();
        parametersTable->raise();
        sendParamButton->raise();
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionMainMenu->setText(QCoreApplication::translate("MainWindow", "Main Menu", nullptr));
        actionSettings->setText(QCoreApplication::translate("MainWindow", "Settings", nullptr));
        Pitch->setText(QCoreApplication::translate("MainWindow", "Pitch:", nullptr));
        Pitch_Data->setText(QCoreApplication::translate("MainWindow", "0.01 \302\260", nullptr));
        Roll->setText(QCoreApplication::translate("MainWindow", "Roll:", nullptr));
        Roll_Data->setText(QCoreApplication::translate("MainWindow", "0.01 \302\260", nullptr));
        Yaw->setText(QCoreApplication::translate("MainWindow", "Yaw:", nullptr));
        Yaw_Data->setText(QCoreApplication::translate("MainWindow", "0.01 \302\260", nullptr));
        Yon->setText(QCoreApplication::translate("MainWindow", "Direction:", nullptr));
        Yon_Data->setText(QCoreApplication::translate("MainWindow", "0.01 \302\260", nullptr));
        GPS_Label1->setText(QCoreApplication::translate("MainWindow", "Longtitute:", nullptr));
        Longitude->setText(QCoreApplication::translate("MainWindow", "0.01 ", nullptr));
        GPS_Label2->setText(QCoreApplication::translate("MainWindow", "Lattitude:", nullptr));
        Latitude->setText(QCoreApplication::translate("MainWindow", "0.01 ", nullptr));
        Voltage->setText(QCoreApplication::translate("MainWindow", "Bat. Voltage:", nullptr));
        Voltage_Data->setText(QCoreApplication::translate("MainWindow", "12.6 V", nullptr));
        SicaklikLabel->setText(QCoreApplication::translate("MainWindow", "Heat:", nullptr));
        Sicaklik_Data->setText(QCoreApplication::translate("MainWindow", "22.7 \302\260C", nullptr));
        Quest->setText(QCoreApplication::translate("MainWindow", "Quest No:", nullptr));
        QuestNo->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        SetPointLabel->setText(QCoreApplication::translate("MainWindow", "Set Point:", nullptr));
        SetPoint_Data->setText(QCoreApplication::translate("MainWindow", "0.0 m/s", nullptr));
        Speed->setText(QCoreApplication::translate("MainWindow", "Speed:", nullptr));
        Speed_Data->setText(QCoreApplication::translate("MainWindow", "0.0 m/s", nullptr));
        SpeedFrame->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "Speed Graph", nullptr));
        Speed_txt->setText(QCoreApplication::translate("MainWindow", "0 m/s", nullptr));
        Setpoint_txt->setText(QCoreApplication::translate("MainWindow", "0 m/s", nullptr));
        label_4->setText(QString());
        label_6->setText(QString());
        MapLabel->setText(QCoreApplication::translate("MainWindow", "Map", nullptr));
        ConStat_2->setText(QCoreApplication::translate("MainWindow", "Ba\304\237lant\304\261 Durumu:", nullptr));
        statusValueLabel->setText(QCoreApplication::translate("MainWindow", "Pasif", nullptr));
        Port->setText(QCoreApplication::translate("MainWindow", "Port:", nullptr));
        portValueLabel->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        Baud->setText(QCoreApplication::translate("MainWindow", "Baud Rate", nullptr));
        baudValueLabel->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        connectButton->setText(QString());
        label_7->setText(QCoreApplication::translate("MainWindow", " Quest Log", nullptr));
        settingsButton->setText(QString());
        label_3->setText(QString());
        label_2->setText(QString());
        label_5->setText(QString());
        ConnectionLogo->setText(QString());
        label_9->setText(QCoreApplication::translate("MainWindow", "Connection", nullptr));
        label_8->setText(QString());
        label_10->setText(QCoreApplication::translate("MainWindow", "Telemetry", nullptr));
        label_11->setText(QString());
        label_12->setText(QString());
        label_13->setText(QString());
        label_14->setText(QString());
        PID_frame->setText(QString());
        label_15->setText(QCoreApplication::translate("MainWindow", "Parameters", nullptr));
        QTableWidgetItem *___qtablewidgetitem = questTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Latitude", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = questTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Longitude", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = questTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Sil", nullptr));
        sendButton->setText(QString());
        emergencyButton->setText(QString());
        QTableWidgetItem *___qtablewidgetitem3 = parametersTable->horizontalHeaderItem(0);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "#", nullptr));
        sendParamButton->setText(QCoreApplication::translate("MainWindow", "SEND PARAM", nullptr));
        label_16->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
