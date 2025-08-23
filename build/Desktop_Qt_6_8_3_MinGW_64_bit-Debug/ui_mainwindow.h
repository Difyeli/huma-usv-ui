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
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
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
    QLabel *Yaw;
    QLabel *Yaw_Data;
    QLabel *Direction;
    QLabel *Direction_Data;
    QLabel *GPS_Label2_2;
    QLabel *Longitude;
    QLabel *GPS_Label2;
    QLabel *Latitude;
    QLabel *SicaklikLabel;
    QLabel *RemoteActive_Data;
    QLabel *label_20;
    QLabel *Failsafe_Data;
    QLabel *SetPointLabel;
    QLabel *SetPoint_Data;
    QLabel *Speed;
    QLabel *Speed_Data;
    QLabel *label_21;
    QLabel *SetPoint_Data2;
    QLabel *label_23;
    QLabel *Speed_Data2;
    QLabel *label_5;
    QLabel *SetPoint_DataR;
    QLabel *label_15;
    QLabel *Speed_DataR;
    QLabel *SpeedFrame;
    QLabel *label;
    QChartView *SpeedGraph;
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
    QLabel *ConnectionLogo;
    QLabel *label_9;
    QLabel *label_8;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QQuickWidget *mapQuickWidget;
    QTableWidget *questTable;
    QPushButton *sendButton;
    QPushButton *emergencyButton;
    QLabel *label_17;
    QChartView *PRYGraph;
    QChartView *SpeedGraph2;
    QLabel *Setpoint_txt_2;
    QLabel *ConnectionLogo_2;
    QLabel *label_19;
    QLabel *label_18;
    QChartView *ThrusterChart;
    QFrame *remoteLamp;
    QFrame *failsafeLamp;
    QLabel *label_22;
    QLabel *Voltage;
    QLabel *SIV_Data;
    QLabel *label_16;
    QLabel *label_24;
    QLabel *label_25;
    QLabel *label_26;
    QLabel *label_27;
    QPlainTextEdit *textLog;
    QLabel *label_28;
    QLabel *label_29;
    QPushButton *addButton;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1920, 1080);
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
        formLayoutWidget->setGeometry(QRect(845, 50, 201, 434));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setHorizontalSpacing(30);
        formLayout->setVerticalSpacing(16);
        formLayout->setContentsMargins(0, 0, 0, 0);
        Yaw = new QLabel(formLayoutWidget);
        Yaw->setObjectName("Yaw");
        QFont font;
        font.setBold(true);
        Yaw->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, Yaw);

        Yaw_Data = new QLabel(formLayoutWidget);
        Yaw_Data->setObjectName("Yaw_Data");
        Yaw_Data->setFont(font);
        Yaw_Data->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        formLayout->setWidget(0, QFormLayout::FieldRole, Yaw_Data);

        Direction = new QLabel(formLayoutWidget);
        Direction->setObjectName("Direction");
        Direction->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, Direction);

        Direction_Data = new QLabel(formLayoutWidget);
        Direction_Data->setObjectName("Direction_Data");
        Direction_Data->setFont(font);
        Direction_Data->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        formLayout->setWidget(1, QFormLayout::FieldRole, Direction_Data);

        GPS_Label2_2 = new QLabel(formLayoutWidget);
        GPS_Label2_2->setObjectName("GPS_Label2_2");
        GPS_Label2_2->setFont(font);

        formLayout->setWidget(2, QFormLayout::LabelRole, GPS_Label2_2);

        Longitude = new QLabel(formLayoutWidget);
        Longitude->setObjectName("Longitude");
        Longitude->setFont(font);
        Longitude->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        formLayout->setWidget(2, QFormLayout::FieldRole, Longitude);

        GPS_Label2 = new QLabel(formLayoutWidget);
        GPS_Label2->setObjectName("GPS_Label2");
        GPS_Label2->setFont(font);

        formLayout->setWidget(3, QFormLayout::LabelRole, GPS_Label2);

        Latitude = new QLabel(formLayoutWidget);
        Latitude->setObjectName("Latitude");
        Latitude->setFont(font);
        Latitude->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        formLayout->setWidget(3, QFormLayout::FieldRole, Latitude);

        SicaklikLabel = new QLabel(formLayoutWidget);
        SicaklikLabel->setObjectName("SicaklikLabel");
        SicaklikLabel->setFont(font);

        formLayout->setWidget(4, QFormLayout::LabelRole, SicaklikLabel);

        RemoteActive_Data = new QLabel(formLayoutWidget);
        RemoteActive_Data->setObjectName("RemoteActive_Data");
        RemoteActive_Data->setFont(font);
        RemoteActive_Data->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        formLayout->setWidget(4, QFormLayout::FieldRole, RemoteActive_Data);

        label_20 = new QLabel(formLayoutWidget);
        label_20->setObjectName("label_20");
        label_20->setFont(font);

        formLayout->setWidget(5, QFormLayout::LabelRole, label_20);

        Failsafe_Data = new QLabel(formLayoutWidget);
        Failsafe_Data->setObjectName("Failsafe_Data");
        Failsafe_Data->setFont(font);
        Failsafe_Data->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        formLayout->setWidget(5, QFormLayout::FieldRole, Failsafe_Data);

        SetPointLabel = new QLabel(formLayoutWidget);
        SetPointLabel->setObjectName("SetPointLabel");
        SetPointLabel->setFont(font);

        formLayout->setWidget(6, QFormLayout::LabelRole, SetPointLabel);

        SetPoint_Data = new QLabel(formLayoutWidget);
        SetPoint_Data->setObjectName("SetPoint_Data");
        SetPoint_Data->setFont(font);
        SetPoint_Data->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        formLayout->setWidget(6, QFormLayout::FieldRole, SetPoint_Data);

        Speed = new QLabel(formLayoutWidget);
        Speed->setObjectName("Speed");
        Speed->setFont(font);

        formLayout->setWidget(7, QFormLayout::LabelRole, Speed);

        Speed_Data = new QLabel(formLayoutWidget);
        Speed_Data->setObjectName("Speed_Data");
        Speed_Data->setFont(font);
        Speed_Data->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        formLayout->setWidget(7, QFormLayout::FieldRole, Speed_Data);

        label_21 = new QLabel(formLayoutWidget);
        label_21->setObjectName("label_21");
        label_21->setFont(font);

        formLayout->setWidget(8, QFormLayout::LabelRole, label_21);

        SetPoint_Data2 = new QLabel(formLayoutWidget);
        SetPoint_Data2->setObjectName("SetPoint_Data2");
        SetPoint_Data2->setFont(font);
        SetPoint_Data2->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        formLayout->setWidget(8, QFormLayout::FieldRole, SetPoint_Data2);

        label_23 = new QLabel(formLayoutWidget);
        label_23->setObjectName("label_23");
        label_23->setFont(font);

        formLayout->setWidget(9, QFormLayout::LabelRole, label_23);

        Speed_Data2 = new QLabel(formLayoutWidget);
        Speed_Data2->setObjectName("Speed_Data2");
        Speed_Data2->setFont(font);
        Speed_Data2->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        formLayout->setWidget(9, QFormLayout::FieldRole, Speed_Data2);

        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName("label_5");
        label_5->setFont(font);

        formLayout->setWidget(10, QFormLayout::LabelRole, label_5);

        SetPoint_DataR = new QLabel(formLayoutWidget);
        SetPoint_DataR->setObjectName("SetPoint_DataR");
        SetPoint_DataR->setFont(font);
        SetPoint_DataR->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        formLayout->setWidget(10, QFormLayout::FieldRole, SetPoint_DataR);

        label_15 = new QLabel(formLayoutWidget);
        label_15->setObjectName("label_15");
        label_15->setFont(font);

        formLayout->setWidget(11, QFormLayout::LabelRole, label_15);

        Speed_DataR = new QLabel(formLayoutWidget);
        Speed_DataR->setObjectName("Speed_DataR");
        Speed_DataR->setFont(font);
        Speed_DataR->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        formLayout->setWidget(11, QFormLayout::FieldRole, Speed_DataR);

        SpeedFrame = new QLabel(centralwidget);
        SpeedFrame->setObjectName("SpeedFrame");
        SpeedFrame->setGeometry(QRect(10, 460, 411, 311));
        SpeedFrame->setPixmap(QPixmap(QString::fromUtf8(":/images/Background2.png")));
        SpeedFrame->setScaledContents(true);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(160, 470, 123, 28));
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
        SpeedGraph->setGeometry(QRect(10, 490, 401, 291));
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
        Setpoint_txt = new QLabel(SpeedGraph);
        Setpoint_txt->setObjectName("Setpoint_txt");
        Setpoint_txt->setGeometry(QRect(310, 295, 61, 20));
        QPalette palette3;
        QBrush brush13(QColor(255, 140, 0, 255));
        brush13.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush13);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush13);
        Setpoint_txt->setPalette(palette3);
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(true);
        Setpoint_txt->setFont(font2);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(323, 8, 511, 461));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/images/Background5.png")));
        label_4->setScaledContents(true);
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(10, 9, 321, 271));
        label_6->setPixmap(QPixmap(QString::fromUtf8(":/images/Background5.png")));
        label_6->setScaledContents(true);
        MapLabel = new QLabel(centralwidget);
        MapLabel->setObjectName("MapLabel");
        MapLabel->setGeometry(QRect(560, 15, 45, 28));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        MapLabel->setPalette(palette4);
        MapLabel->setFont(font1);
        MapLabel->setTextFormat(Qt::TextFormat::RichText);
        MapLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        formLayoutWidget_2 = new QWidget(centralwidget);
        formLayoutWidget_2->setObjectName("formLayoutWidget_2");
        formLayoutWidget_2->setGeometry(QRect(1314, 60, 181, 101));
        formLayout_2 = new QFormLayout(formLayoutWidget_2);
        formLayout_2->setObjectName("formLayout_2");
        formLayout_2->setHorizontalSpacing(15);
        formLayout_2->setVerticalSpacing(15);
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        ConStat_2 = new QLabel(formLayoutWidget_2);
        ConStat_2->setObjectName("ConStat_2");
        ConStat_2->setFont(font);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, ConStat_2);

        statusValueLabel = new QLabel(formLayoutWidget_2);
        statusValueLabel->setObjectName("statusValueLabel");
        statusValueLabel->setFont(font);
        statusValueLabel->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, statusValueLabel);

        Port = new QLabel(formLayoutWidget_2);
        Port->setObjectName("Port");
        Port->setFont(font);

        formLayout_2->setWidget(1, QFormLayout::LabelRole, Port);

        portValueLabel = new QLabel(formLayoutWidget_2);
        portValueLabel->setObjectName("portValueLabel");
        portValueLabel->setFont(font);
        portValueLabel->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, portValueLabel);

        Baud = new QLabel(formLayoutWidget_2);
        Baud->setObjectName("Baud");
        Baud->setFont(font);

        formLayout_2->setWidget(2, QFormLayout::LabelRole, Baud);

        baudValueLabel = new QLabel(formLayoutWidget_2);
        baudValueLabel->setObjectName("baudValueLabel");
        baudValueLabel->setFont(font);
        baudValueLabel->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        formLayout_2->setWidget(2, QFormLayout::FieldRole, baudValueLabel);

        connectButton = new QPushButton(centralwidget);
        connectButton->setObjectName("connectButton");
        connectButton->setGeometry(QRect(1314, 160, 180, 41));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette5.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette5.setBrush(QPalette::Active, QPalette::Midlight, brush2);
        palette5.setBrush(QPalette::Active, QPalette::Dark, brush10);
        palette5.setBrush(QPalette::Active, QPalette::Mid, brush11);
        palette5.setBrush(QPalette::Active, QPalette::Text, brush);
        palette5.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette5.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette5.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette5.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette5.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette5.setBrush(QPalette::Active, QPalette::AlternateBase, brush2);
        palette5.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette5.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Active, QPalette::PlaceholderText, brush7);
#endif
#if QT_VERSION >= QT_VERSION_CHECK(6, 6, 0)
        palette5.setBrush(QPalette::Active, QPalette::Accent, brush2);
#endif
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette5.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette5.setBrush(QPalette::Inactive, QPalette::Midlight, brush2);
        palette5.setBrush(QPalette::Inactive, QPalette::Dark, brush10);
        palette5.setBrush(QPalette::Inactive, QPalette::Mid, brush11);
        palette5.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette5.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette5.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette5.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush2);
        palette5.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette5.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush7);
#endif
#if QT_VERSION >= QT_VERSION_CHECK(6, 6, 0)
        palette5.setBrush(QPalette::Inactive, QPalette::Accent, brush2);
#endif
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush10);
        palette5.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette5.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette5.setBrush(QPalette::Disabled, QPalette::Midlight, brush2);
        palette5.setBrush(QPalette::Disabled, QPalette::Dark, brush10);
        palette5.setBrush(QPalette::Disabled, QPalette::Mid, brush11);
        palette5.setBrush(QPalette::Disabled, QPalette::Text, brush10);
        palette5.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette5.setBrush(QPalette::Disabled, QPalette::ButtonText, brush10);
        palette5.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette5.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        palette5.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush2);
        palette5.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette5.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush12);
#endif
#if QT_VERSION >= QT_VERSION_CHECK(6, 6, 0)
        palette5.setBrush(QPalette::Disabled, QPalette::Accent, brush2);
#endif
        connectButton->setPalette(palette5);
        connectButton->setFont(font);
        connectButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/ConnectButton.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        icon.addFile(QString::fromUtf8(":/images/DisconnectButton.png"), QSize(), QIcon::Mode::Active, QIcon::State::On);
        connectButton->setIcon(icon);
        connectButton->setIconSize(QSize(200, 33));
        connectButton->setCheckable(true);
        connectButton->setChecked(false);
        connectButton->setFlat(true);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(130, 15, 101, 31));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        label_7->setPalette(palette6);
        label_7->setFont(font1);
        label_7->setTextFormat(Qt::TextFormat::RichText);
        label_7->setAlignment(Qt::AlignmentFlag::AlignCenter);
        settingsButton = new QPushButton(centralwidget);
        settingsButton->setObjectName("settingsButton");
        settingsButton->setGeometry(QRect(1314, 200, 180, 41));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Active, QPalette::Button, brush2);
        QBrush brush14(QColor(143, 225, 255, 255));
        brush14.setStyle(Qt::SolidPattern);
        palette7.setBrush(QPalette::Active, QPalette::Light, brush14);
        QBrush brush15(QColor(79, 208, 255, 255));
        brush15.setStyle(Qt::SolidPattern);
        palette7.setBrush(QPalette::Active, QPalette::Midlight, brush15);
        QBrush brush16(QColor(8, 95, 127, 255));
        brush16.setStyle(Qt::SolidPattern);
        palette7.setBrush(QPalette::Active, QPalette::Dark, brush16);
        QBrush brush17(QColor(11, 127, 170, 255));
        brush17.setStyle(Qt::SolidPattern);
        palette7.setBrush(QPalette::Active, QPalette::Mid, brush17);
        palette7.setBrush(QPalette::Active, QPalette::Text, brush);
        palette7.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette7.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette7.setBrush(QPalette::Active, QPalette::Base, brush2);
        QBrush brush18(QColor(16, 191, 255, 255));
        brush18.setStyle(Qt::SolidPattern);
        palette7.setBrush(QPalette::Active, QPalette::Window, brush18);
        palette7.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush19(QColor(135, 223, 255, 255));
        brush19.setStyle(Qt::SolidPattern);
        palette7.setBrush(QPalette::Active, QPalette::AlternateBase, brush19);
        palette7.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette7.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette7.setBrush(QPalette::Active, QPalette::PlaceholderText, brush7);
#endif
#if QT_VERSION >= QT_VERSION_CHECK(6, 6, 0)
        palette7.setBrush(QPalette::Active, QPalette::Accent, brush2);
#endif
        palette7.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette7.setBrush(QPalette::Inactive, QPalette::Light, brush14);
        palette7.setBrush(QPalette::Inactive, QPalette::Midlight, brush15);
        palette7.setBrush(QPalette::Inactive, QPalette::Dark, brush16);
        palette7.setBrush(QPalette::Inactive, QPalette::Mid, brush17);
        palette7.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette7.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette7.setBrush(QPalette::Inactive, QPalette::Window, brush18);
        palette7.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush19);
        palette7.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette7.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette7.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush7);
#endif
#if QT_VERSION >= QT_VERSION_CHECK(6, 6, 0)
        palette7.setBrush(QPalette::Inactive, QPalette::Accent, brush2);
#endif
        palette7.setBrush(QPalette::Disabled, QPalette::WindowText, brush16);
        palette7.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette7.setBrush(QPalette::Disabled, QPalette::Light, brush14);
        palette7.setBrush(QPalette::Disabled, QPalette::Midlight, brush15);
        palette7.setBrush(QPalette::Disabled, QPalette::Dark, brush16);
        palette7.setBrush(QPalette::Disabled, QPalette::Mid, brush17);
        palette7.setBrush(QPalette::Disabled, QPalette::Text, brush16);
        palette7.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette7.setBrush(QPalette::Disabled, QPalette::ButtonText, brush16);
        palette7.setBrush(QPalette::Disabled, QPalette::Base, brush18);
        palette7.setBrush(QPalette::Disabled, QPalette::Window, brush18);
        palette7.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette7.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush18);
        palette7.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette7.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        QBrush brush20(QColor(8, 95, 127, 127));
        brush20.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette7.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush20);
#endif
        QBrush brush21(QColor(92, 211, 255, 255));
        brush21.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(6, 6, 0)
        palette7.setBrush(QPalette::Disabled, QPalette::Accent, brush21);
#endif
        settingsButton->setPalette(palette7);
        settingsButton->setFont(font);
        settingsButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/SettingsButton.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        settingsButton->setIcon(icon1);
        settingsButton->setIconSize(QSize(200, 33));
        settingsButton->setCheckable(true);
        settingsButton->setFlat(true);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(1290, 10, 231, 451));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/images/Background1.png")));
        label_3->setScaledContents(true);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(830, 10, 231, 451));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/images/Background1.png")));
        label_2->setScaledContents(true);
        ConnectionLogo = new QLabel(centralwidget);
        ConnectionLogo->setObjectName("ConnectionLogo");
        ConnectionLogo->setGeometry(QRect(1329, 20, 28, 28));
        ConnectionLogo->setPixmap(QPixmap(QString::fromUtf8(":/images/ConnectionLogo.png")));
        ConnectionLogo->setScaledContents(true);
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(1351, 23, 111, 20));
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        palette8.setBrush(QPalette::Active, QPalette::Text, brush9);
        palette8.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        palette8.setBrush(QPalette::Inactive, QPalette::Text, brush9);
        label_9->setPalette(palette8);
        label_9->setFont(font1);
        label_9->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(140, 470, 28, 28));
        label_8->setPixmap(QPixmap(QString::fromUtf8(":/images/SpeedLogo.png")));
        label_8->setScaledContents(true);
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(900, 15, 96, 29));
        QPalette palette9;
        palette9.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        palette9.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        label_10->setPalette(palette9);
        label_10->setFont(font1);
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(530, 15, 28, 28));
        label_11->setPixmap(QPixmap(QString::fromUtf8(":/images/MapLogo.png")));
        label_11->setScaledContents(true);
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(110, 17, 28, 28));
        label_12->setPixmap(QPixmap(QString::fromUtf8(":/images/QuestLogo.png")));
        label_12->setScaledContents(true);
        label_13 = new QLabel(centralwidget);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(880, 15, 28, 28));
        label_13->setPixmap(QPixmap(QString::fromUtf8(":/images/IDALogo.png")));
        label_13->setScaledContents(true);
        label_14 = new QLabel(centralwidget);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(840, 42, 211, 401));
        label_14->setPixmap(QPixmap(QString::fromUtf8(":/images/Background4.png")));
        label_14->setScaledContents(true);
        mapQuickWidget = new QQuickWidget(centralwidget);
        mapQuickWidget->setObjectName("mapQuickWidget");
        mapQuickWidget->setGeometry(QRect(343, 43, 471, 401));
        mapQuickWidget->setCursor(QCursor(Qt::CursorShape::CrossCursor));
        mapQuickWidget->setResizeMode(QQuickWidget::ResizeMode::SizeRootObjectToView);
        questTable = new QTableWidget(centralwidget);
        if (questTable->columnCount() < 4)
            questTable->setColumnCount(4);
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
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        questTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        questTable->setObjectName("questTable");
        questTable->setGeometry(QRect(25, 50, 291, 178));
        QPalette palette10;
        QBrush brush22(QColor(113, 226, 217, 255));
        brush22.setStyle(Qt::SolidPattern);
        palette10.setBrush(QPalette::Active, QPalette::Button, brush22);
        palette10.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette10.setBrush(QPalette::Active, QPalette::Window, brush22);
        palette10.setBrush(QPalette::Active, QPalette::AlternateBase, brush22);
        palette10.setBrush(QPalette::Inactive, QPalette::Button, brush22);
        palette10.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette10.setBrush(QPalette::Inactive, QPalette::Window, brush22);
        palette10.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush22);
        palette10.setBrush(QPalette::Disabled, QPalette::Button, brush22);
        palette10.setBrush(QPalette::Disabled, QPalette::Base, brush22);
        palette10.setBrush(QPalette::Disabled, QPalette::Window, brush22);
        palette10.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush22);
        questTable->setPalette(palette10);
        questTable->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CursorShape::ArrowCursor)));
        questTable->horizontalHeader()->setVisible(true);
        questTable->horizontalHeader()->setCascadingSectionResizes(true);
        questTable->horizontalHeader()->setMinimumSectionSize(36);
        questTable->horizontalHeader()->setDefaultSectionSize(86);
        questTable->horizontalHeader()->setStretchLastSection(false);
        sendButton = new QPushButton(centralwidget);
        sendButton->setObjectName("sendButton");
        sendButton->setGeometry(QRect(80, 230, 180, 40));
        QPalette palette11;
        palette11.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette11.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette11.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        sendButton->setPalette(palette11);
        sendButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/sendButton.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        sendButton->setIcon(icon2);
        sendButton->setIconSize(QSize(220, 33));
        sendButton->setFlat(true);
        emergencyButton = new QPushButton(centralwidget);
        emergencyButton->setObjectName("emergencyButton");
        emergencyButton->setGeometry(QRect(1314, 240, 180, 41));
        QPalette palette12;
        palette12.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette12.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette12.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette12.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette12.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette12.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette12.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        emergencyButton->setPalette(palette12);
        emergencyButton->setCursor(QCursor(Qt::CursorShape::OpenHandCursor));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/EmergencyButton.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        emergencyButton->setIcon(icon3);
        emergencyButton->setIconSize(QSize(200, 33));
        emergencyButton->setFlat(true);
        label_17 = new QLabel(centralwidget);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(1090, 460, 441, 311));
        label_17->setPixmap(QPixmap(QString::fromUtf8(":/images/Background3.png")));
        label_17->setScaledContents(true);
        PRYGraph = new QChartView(centralwidget);
        PRYGraph->setObjectName("PRYGraph");
        PRYGraph->setGeometry(QRect(1100, 490, 421, 281));
        SpeedGraph2 = new QChartView(centralwidget);
        SpeedGraph2->setObjectName("SpeedGraph2");
        SpeedGraph2->setGeometry(QRect(410, 490, 351, 281));
        QPalette palette13;
        palette13.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette13.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette13.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette13.setBrush(QPalette::Active, QPalette::Midlight, brush2);
        palette13.setBrush(QPalette::Active, QPalette::Dark, brush10);
        palette13.setBrush(QPalette::Active, QPalette::Mid, brush11);
        palette13.setBrush(QPalette::Active, QPalette::Text, brush);
        palette13.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette13.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette13.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette13.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette13.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette13.setBrush(QPalette::Active, QPalette::AlternateBase, brush2);
        palette13.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette13.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette13.setBrush(QPalette::Active, QPalette::PlaceholderText, brush7);
#endif
#if QT_VERSION >= QT_VERSION_CHECK(6, 6, 0)
        palette13.setBrush(QPalette::Active, QPalette::Accent, brush2);
#endif
        palette13.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette13.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette13.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette13.setBrush(QPalette::Inactive, QPalette::Midlight, brush2);
        palette13.setBrush(QPalette::Inactive, QPalette::Dark, brush10);
        palette13.setBrush(QPalette::Inactive, QPalette::Mid, brush11);
        palette13.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette13.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette13.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette13.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette13.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette13.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette13.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush2);
        palette13.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette13.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette13.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush7);
#endif
#if QT_VERSION >= QT_VERSION_CHECK(6, 6, 0)
        palette13.setBrush(QPalette::Inactive, QPalette::Accent, brush2);
#endif
        palette13.setBrush(QPalette::Disabled, QPalette::WindowText, brush10);
        palette13.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette13.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette13.setBrush(QPalette::Disabled, QPalette::Midlight, brush2);
        palette13.setBrush(QPalette::Disabled, QPalette::Dark, brush10);
        palette13.setBrush(QPalette::Disabled, QPalette::Mid, brush11);
        palette13.setBrush(QPalette::Disabled, QPalette::Text, brush10);
        palette13.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette13.setBrush(QPalette::Disabled, QPalette::ButtonText, brush10);
        palette13.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette13.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        palette13.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette13.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush2);
        palette13.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette13.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette13.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush12);
#endif
#if QT_VERSION >= QT_VERSION_CHECK(6, 6, 0)
        palette13.setBrush(QPalette::Disabled, QPalette::Accent, brush2);
#endif
        SpeedGraph2->setPalette(palette13);
        Setpoint_txt_2 = new QLabel(SpeedGraph2);
        Setpoint_txt_2->setObjectName("Setpoint_txt_2");
        Setpoint_txt_2->setGeometry(QRect(310, 295, 61, 20));
        QPalette palette14;
        palette14.setBrush(QPalette::Active, QPalette::WindowText, brush13);
        palette14.setBrush(QPalette::Inactive, QPalette::WindowText, brush13);
        Setpoint_txt_2->setPalette(palette14);
        Setpoint_txt_2->setFont(font2);
        ConnectionLogo_2 = new QLabel(centralwidget);
        ConnectionLogo_2->setObjectName("ConnectionLogo_2");
        ConnectionLogo_2->setGeometry(QRect(1235, 470, 28, 28));
        ConnectionLogo_2->setPixmap(QPixmap(QString::fromUtf8(":/images/DirectionLogo.png")));
        ConnectionLogo_2->setScaledContents(true);
        label_19 = new QLabel(centralwidget);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(1250, 470, 151, 31));
        QPalette palette15;
        palette15.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        palette15.setBrush(QPalette::Active, QPalette::Text, brush9);
        palette15.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        palette15.setBrush(QPalette::Inactive, QPalette::Text, brush9);
        label_19->setPalette(palette15);
        label_19->setFont(font1);
        label_19->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_18 = new QLabel(centralwidget);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(417, 460, 681, 311));
        label_18->setPixmap(QPixmap(QString::fromUtf8(":/images/Background2.png")));
        label_18->setScaledContents(true);
        ThrusterChart = new QChartView(centralwidget);
        ThrusterChart->setObjectName("ThrusterChart");
        ThrusterChart->setGeometry(QRect(740, 490, 371, 281));
        remoteLamp = new QFrame(centralwidget);
        remoteLamp->setObjectName("remoteLamp");
        remoteLamp->setGeometry(QRect(630, 870, 180, 25));
        remoteLamp->setStyleSheet(QString::fromUtf8("background-color: lightgray;\n"
"border: 1px solid #555;\n"
"border-radius: 3px;\n"
""));
        remoteLamp->setFrameShape(QFrame::Shape::StyledPanel);
        remoteLamp->setFrameShadow(QFrame::Shadow::Raised);
        failsafeLamp = new QFrame(centralwidget);
        failsafeLamp->setObjectName("failsafeLamp");
        failsafeLamp->setGeometry(QRect(630, 900, 180, 25));
        failsafeLamp->setStyleSheet(QString::fromUtf8("background-color: lightgray;\n"
"border: 1px solid #555;\n"
"border-radius: 3px;\n"
""));
        failsafeLamp->setFrameShape(QFrame::Shape::StyledPanel);
        failsafeLamp->setFrameShadow(QFrame::Shadow::Raised);
        label_22 = new QLabel(centralwidget);
        label_22->setObjectName("label_22");
        label_22->setGeometry(QRect(700, 470, 151, 31));
        QPalette palette16;
        palette16.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        palette16.setBrush(QPalette::Active, QPalette::Text, brush9);
        palette16.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        palette16.setBrush(QPalette::Inactive, QPalette::Text, brush9);
        label_22->setPalette(palette16);
        label_22->setFont(font1);
        label_22->setAlignment(Qt::AlignmentFlag::AlignCenter);
        Voltage = new QLabel(centralwidget);
        Voltage->setObjectName("Voltage");
        Voltage->setGeometry(QRect(860, 870, 27, 20));
        Voltage->setFont(font);
        SIV_Data = new QLabel(centralwidget);
        SIV_Data->setObjectName("SIV_Data");
        SIV_Data->setGeometry(QRect(880, 870, 67, 20));
        SIV_Data->setFont(font);
        SIV_Data->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        label_16 = new QLabel(centralwidget);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(1060, 10, 231, 451));
        label_16->setPixmap(QPixmap(QString::fromUtf8(":/images/Background1.png")));
        label_16->setScaledContents(true);
        label_24 = new QLabel(centralwidget);
        label_24->setObjectName("label_24");
        label_24->setGeometry(QRect(1160, 14, 41, 29));
        QPalette palette17;
        palette17.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        palette17.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        label_24->setPalette(palette17);
        label_24->setFont(font1);
        label_24->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_25 = new QLabel(centralwidget);
        label_25->setObjectName("label_25");
        label_25->setGeometry(QRect(1134, 14, 28, 28));
        label_25->setPixmap(QPixmap(QString::fromUtf8(":/images/IHALogo.png")));
        label_25->setScaledContents(true);
        label_26 = new QLabel(centralwidget);
        label_26->setObjectName("label_26");
        label_26->setGeometry(QRect(1070, 42, 211, 401));
        label_26->setPixmap(QPixmap(QString::fromUtf8(":/images/Background4.png")));
        label_26->setScaledContents(true);
        label_27 = new QLabel(centralwidget);
        label_27->setObjectName("label_27");
        label_27->setGeometry(QRect(689, 470, 28, 28));
        label_27->setPixmap(QPixmap(QString::fromUtf8(":/images/PWMLogo.png")));
        label_27->setScaledContents(true);
        textLog = new QPlainTextEdit(centralwidget);
        textLog->setObjectName("textLog");
        textLog->setGeometry(QRect(24, 307, 293, 144));
        textLog->setFont(font2);
        textLog->setReadOnly(true);
        label_28 = new QLabel(centralwidget);
        label_28->setObjectName("label_28");
        label_28->setGeometry(QRect(10, 280, 321, 181));
        label_28->setPixmap(QPixmap(QString::fromUtf8(":/images/Background2.png")));
        label_28->setScaledContents(true);
        label_29 = new QLabel(centralwidget);
        label_29->setObjectName("label_29");
        label_29->setGeometry(QRect(120, 278, 101, 31));
        QPalette palette18;
        palette18.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        palette18.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        label_29->setPalette(palette18);
        label_29->setFont(font1);
        label_29->setTextFormat(Qt::TextFormat::RichText);
        label_29->setAlignment(Qt::AlignmentFlag::AlignCenter);
        addButton = new QPushButton(centralwidget);
        addButton->setObjectName("addButton");
        addButton->setGeometry(QRect(270, 234, 31, 29));
        MainWindow->setCentralWidget(centralwidget);
        label_3->raise();
        label_28->raise();
        label_16->raise();
        label_26->raise();
        label_6->raise();
        label_18->raise();
        label_17->raise();
        SpeedFrame->raise();
        label_2->raise();
        label_14->raise();
        formLayoutWidget->raise();
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
        mapQuickWidget->raise();
        questTable->raise();
        sendButton->raise();
        emergencyButton->raise();
        PRYGraph->raise();
        ConnectionLogo_2->raise();
        label_19->raise();
        ThrusterChart->raise();
        SpeedGraph2->raise();
        remoteLamp->raise();
        failsafeLamp->raise();
        label_22->raise();
        Voltage->raise();
        SIV_Data->raise();
        label_24->raise();
        label_25->raise();
        label_27->raise();
        textLog->raise();
        label_29->raise();
        addButton->raise();
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
        Yaw->setText(QCoreApplication::translate("MainWindow", "Yaw:", nullptr));
        Yaw_Data->setText(QCoreApplication::translate("MainWindow", "0.01 \302\260", nullptr));
        Direction->setText(QCoreApplication::translate("MainWindow", "SetPoint Yaw:", nullptr));
        Direction_Data->setText(QCoreApplication::translate("MainWindow", "0.01 \302\260", nullptr));
        GPS_Label2_2->setText(QCoreApplication::translate("MainWindow", "Longitute:", nullptr));
        Longitude->setText(QCoreApplication::translate("MainWindow", "0.01 ", nullptr));
        GPS_Label2->setText(QCoreApplication::translate("MainWindow", "Latitude:", nullptr));
        Latitude->setText(QCoreApplication::translate("MainWindow", "0.01 ", nullptr));
        SicaklikLabel->setText(QCoreApplication::translate("MainWindow", "RC Data:", nullptr));
        RemoteActive_Data->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "FailSafe", nullptr));
        Failsafe_Data->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        SetPointLabel->setText(QCoreApplication::translate("MainWindow", "Set Point:", nullptr));
        SetPoint_Data->setText(QCoreApplication::translate("MainWindow", "0.0 m/s", nullptr));
        Speed->setText(QCoreApplication::translate("MainWindow", "Speed:", nullptr));
        Speed_Data->setText(QCoreApplication::translate("MainWindow", "0.0 m/s", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "L_Setpoint", nullptr));
        SetPoint_Data2->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        label_23->setText(QCoreApplication::translate("MainWindow", "L_Thrusters", nullptr));
        Speed_Data2->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "R_Setpoint", nullptr));
        SetPoint_DataR->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "R_Thrusters", nullptr));
        Speed_DataR->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        SpeedFrame->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "Speed Graph", nullptr));
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
        ConnectionLogo->setText(QString());
        label_9->setText(QCoreApplication::translate("MainWindow", "Connection", nullptr));
        label_8->setText(QString());
        label_10->setText(QCoreApplication::translate("MainWindow", "Telemetry", nullptr));
        label_11->setText(QString());
        label_12->setText(QString());
        label_13->setText(QString());
        label_14->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = questTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Latitude", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = questTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Longitude", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = questTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = questTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        sendButton->setText(QString());
        emergencyButton->setText(QString());
        label_17->setText(QString());
        Setpoint_txt_2->setText(QCoreApplication::translate("MainWindow", "0 m/s", nullptr));
        ConnectionLogo_2->setText(QString());
        label_19->setText(QCoreApplication::translate("MainWindow", "Heading Graph", nullptr));
        label_18->setText(QString());
        label_22->setText(QCoreApplication::translate("MainWindow", "PWM Graphs", nullptr));
        Voltage->setText(QCoreApplication::translate("MainWindow", "SIV:", nullptr));
        SIV_Data->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        label_16->setText(QString());
        label_24->setText(QCoreApplication::translate("MainWindow", "\304\260HA", nullptr));
        label_25->setText(QString());
        label_26->setText(QString());
        label_27->setText(QString());
        label_28->setText(QString());
        label_29->setText(QCoreApplication::translate("MainWindow", "Text Log", nullptr));
        addButton->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
