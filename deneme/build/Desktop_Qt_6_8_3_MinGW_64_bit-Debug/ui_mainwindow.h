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
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAyarlar;
    QWidget *centralwidget;
    QPushButton *StartButton;
    QLabel *ImageLogo;
    QLabel *telemetriLabel;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *Pitch;
    QLabel *Roll;
    QLabel *Yaw;
    QLabel *GPS_Label1;
    QLabel *GPS_Label2;
    QLabel *Voltage;
    QLabel *SicaklikLabel;
    QLabel *Quest;
    QLabel *Yon;
    QLabel *SetPointLabel;
    QLabel *Speed;
    QLabel *Pitch_Data;
    QLabel *Roll_Data;
    QLabel *Yaw_Data;
    QLabel *Yon_Data;
    QLabel *Longtitute;
    QLabel *Lattitute;
    QLabel *Voltage_Data;
    QLabel *Sicaklik_Data;
    QLabel *QuestNo;
    QLabel *SetPoint_Data;
    QLabel *Speed_Data;
    QLabel *SpeedFrame;
    QLabel *label;
    QChartView *SpeedGraph;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QWidget *widget;
    QWidget *widget_2;
    QWidget *formLayoutWidget_2;
    QFormLayout *formLayout_2;
    QLabel *Pitch_2;
    QLabel *Pitch_Data_2;
    QLabel *Roll_2;
    QLabel *Roll_Data_2;
    QLabel *Yaw_2;
    QLabel *Yaw_Data_2;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QMenu *menuMenu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1540, 800);
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(225, 225, 225, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(255, 255, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(240, 240, 240, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(112, 112, 112, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(150, 150, 150, 255));
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
        QBrush brush8(QColor(112, 112, 112, 127));
        brush8.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush8);
#endif
#if QT_VERSION >= QT_VERSION_CHECK(6, 6, 0)
        palette.setBrush(QPalette::Disabled, QPalette::Accent, brush2);
#endif
        MainWindow->setPalette(palette);
        MainWindow->setAutoFillBackground(true);
        actionAyarlar = new QAction(MainWindow);
        actionAyarlar->setObjectName("actionAyarlar");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setEnabled(true);
        centralwidget->setAutoFillBackground(true);
        StartButton = new QPushButton(centralwidget);
        StartButton->setObjectName("StartButton");
        StartButton->setGeometry(QRect(1349, 30, 91, 29));
        StartButton->setMaximumSize(QSize(100, 16777215));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush9(QColor(57, 170, 85, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush9);
        QBrush brush10(QColor(85, 255, 128, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush10);
        QBrush brush11(QColor(71, 212, 106, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush11);
        QBrush brush12(QColor(28, 85, 43, 255));
        brush12.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush12);
        QBrush brush13(QColor(38, 113, 57, 255));
        brush13.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush13);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush9);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush14(QColor(156, 212, 170, 255));
        brush14.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush14);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Active, QPalette::PlaceholderText, brush7);
#endif
#if QT_VERSION >= QT_VERSION_CHECK(6, 6, 0)
        palette1.setBrush(QPalette::Active, QPalette::Accent, brush2);
#endif
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush9);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush10);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush11);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush12);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush13);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush9);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush14);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush7);
#endif
#if QT_VERSION >= QT_VERSION_CHECK(6, 6, 0)
        palette1.setBrush(QPalette::Inactive, QPalette::Accent, brush2);
#endif
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush12);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush9);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush10);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush11);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush12);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush13);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush12);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush12);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush9);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush9);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush9);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        QBrush brush15(QColor(28, 85, 43, 127));
        brush15.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush15);
#endif
        QBrush brush16(QColor(74, 221, 111, 255));
        brush16.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(6, 6, 0)
        palette1.setBrush(QPalette::Disabled, QPalette::Accent, brush16);
#endif
        StartButton->setPalette(palette1);
        QFont font;
        font.setBold(true);
        StartButton->setFont(font);
        StartButton->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        ImageLogo = new QLabel(centralwidget);
        ImageLogo->setObjectName("ImageLogo");
        ImageLogo->setGeometry(QRect(690, 10, 151, 71));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(10);
        sizePolicy.setVerticalStretch(10);
        sizePolicy.setHeightForWidth(ImageLogo->sizePolicy().hasHeightForWidth());
        ImageLogo->setSizePolicy(sizePolicy);
        ImageLogo->setMaximumSize(QSize(200, 200));
        ImageLogo->setAutoFillBackground(true);
        ImageLogo->setPixmap(QPixmap(QString::fromUtf8(":/images/Huma3.png")));
        ImageLogo->setScaledContents(true);
        ImageLogo->setWordWrap(false);
        telemetriLabel = new QLabel(centralwidget);
        telemetriLabel->setObjectName("telemetriLabel");
        telemetriLabel->setGeometry(QRect(1190, 150, 291, 421));
        telemetriLabel->setPixmap(QPixmap(QString::fromUtf8(":/images/GraphRect.png")));
        telemetriLabel->setScaledContents(true);
        formLayoutWidget = new QWidget(centralwidget);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(1200, 170, 271, 392));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setHorizontalSpacing(100);
        formLayout->setVerticalSpacing(15);
        formLayout->setContentsMargins(0, 0, 0, 0);
        Pitch = new QLabel(formLayoutWidget);
        Pitch->setObjectName("Pitch");
        Pitch->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, Pitch);

        Roll = new QLabel(formLayoutWidget);
        Roll->setObjectName("Roll");
        Roll->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, Roll);

        Yaw = new QLabel(formLayoutWidget);
        Yaw->setObjectName("Yaw");
        Yaw->setFont(font);

        formLayout->setWidget(2, QFormLayout::LabelRole, Yaw);

        GPS_Label1 = new QLabel(formLayoutWidget);
        GPS_Label1->setObjectName("GPS_Label1");
        GPS_Label1->setFont(font);

        formLayout->setWidget(4, QFormLayout::LabelRole, GPS_Label1);

        GPS_Label2 = new QLabel(formLayoutWidget);
        GPS_Label2->setObjectName("GPS_Label2");
        GPS_Label2->setFont(font);

        formLayout->setWidget(5, QFormLayout::LabelRole, GPS_Label2);

        Voltage = new QLabel(formLayoutWidget);
        Voltage->setObjectName("Voltage");
        Voltage->setFont(font);

        formLayout->setWidget(6, QFormLayout::LabelRole, Voltage);

        SicaklikLabel = new QLabel(formLayoutWidget);
        SicaklikLabel->setObjectName("SicaklikLabel");
        SicaklikLabel->setFont(font);

        formLayout->setWidget(7, QFormLayout::LabelRole, SicaklikLabel);

        Quest = new QLabel(formLayoutWidget);
        Quest->setObjectName("Quest");
        Quest->setFont(font);

        formLayout->setWidget(8, QFormLayout::LabelRole, Quest);

        Yon = new QLabel(formLayoutWidget);
        Yon->setObjectName("Yon");
        Yon->setFont(font);

        formLayout->setWidget(3, QFormLayout::LabelRole, Yon);

        SetPointLabel = new QLabel(formLayoutWidget);
        SetPointLabel->setObjectName("SetPointLabel");
        SetPointLabel->setFont(font);

        formLayout->setWidget(9, QFormLayout::LabelRole, SetPointLabel);

        Speed = new QLabel(formLayoutWidget);
        Speed->setObjectName("Speed");
        Speed->setFont(font);

        formLayout->setWidget(10, QFormLayout::LabelRole, Speed);

        Pitch_Data = new QLabel(formLayoutWidget);
        Pitch_Data->setObjectName("Pitch_Data");
        Pitch_Data->setFont(font);
        Pitch_Data->setAlignment(Qt::AlignmentFlag::AlignCenter);

        formLayout->setWidget(0, QFormLayout::FieldRole, Pitch_Data);

        Roll_Data = new QLabel(formLayoutWidget);
        Roll_Data->setObjectName("Roll_Data");
        Roll_Data->setFont(font);
        Roll_Data->setAlignment(Qt::AlignmentFlag::AlignCenter);

        formLayout->setWidget(1, QFormLayout::FieldRole, Roll_Data);

        Yaw_Data = new QLabel(formLayoutWidget);
        Yaw_Data->setObjectName("Yaw_Data");
        Yaw_Data->setFont(font);
        Yaw_Data->setAlignment(Qt::AlignmentFlag::AlignCenter);

        formLayout->setWidget(2, QFormLayout::FieldRole, Yaw_Data);

        Yon_Data = new QLabel(formLayoutWidget);
        Yon_Data->setObjectName("Yon_Data");
        Yon_Data->setFont(font);
        Yon_Data->setAlignment(Qt::AlignmentFlag::AlignCenter);

        formLayout->setWidget(3, QFormLayout::FieldRole, Yon_Data);

        Longtitute = new QLabel(formLayoutWidget);
        Longtitute->setObjectName("Longtitute");
        Longtitute->setFont(font);
        Longtitute->setAlignment(Qt::AlignmentFlag::AlignCenter);

        formLayout->setWidget(4, QFormLayout::FieldRole, Longtitute);

        Lattitute = new QLabel(formLayoutWidget);
        Lattitute->setObjectName("Lattitute");
        Lattitute->setFont(font);
        Lattitute->setAlignment(Qt::AlignmentFlag::AlignCenter);

        formLayout->setWidget(5, QFormLayout::FieldRole, Lattitute);

        Voltage_Data = new QLabel(formLayoutWidget);
        Voltage_Data->setObjectName("Voltage_Data");
        Voltage_Data->setFont(font);
        Voltage_Data->setAlignment(Qt::AlignmentFlag::AlignCenter);

        formLayout->setWidget(6, QFormLayout::FieldRole, Voltage_Data);

        Sicaklik_Data = new QLabel(formLayoutWidget);
        Sicaklik_Data->setObjectName("Sicaklik_Data");
        Sicaklik_Data->setFont(font);
        Sicaklik_Data->setAlignment(Qt::AlignmentFlag::AlignCenter);

        formLayout->setWidget(7, QFormLayout::FieldRole, Sicaklik_Data);

        QuestNo = new QLabel(formLayoutWidget);
        QuestNo->setObjectName("QuestNo");
        QuestNo->setFont(font);
        QuestNo->setAlignment(Qt::AlignmentFlag::AlignCenter);

        formLayout->setWidget(8, QFormLayout::FieldRole, QuestNo);

        SetPoint_Data = new QLabel(formLayoutWidget);
        SetPoint_Data->setObjectName("SetPoint_Data");
        SetPoint_Data->setFont(font);
        SetPoint_Data->setAlignment(Qt::AlignmentFlag::AlignCenter);

        formLayout->setWidget(9, QFormLayout::FieldRole, SetPoint_Data);

        Speed_Data = new QLabel(formLayoutWidget);
        Speed_Data->setObjectName("Speed_Data");
        Speed_Data->setFont(font);
        Speed_Data->setAlignment(Qt::AlignmentFlag::AlignCenter);

        formLayout->setWidget(10, QFormLayout::FieldRole, Speed_Data);

        SpeedFrame = new QLabel(centralwidget);
        SpeedFrame->setObjectName("SpeedFrame");
        SpeedFrame->setGeometry(QRect(440, 400, 701, 301));
        SpeedFrame->setPixmap(QPixmap(QString::fromUtf8(":/images/Graph.png")));
        SpeedFrame->setScaledContents(true);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(720, 389, 141, 31));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        label->setFont(font1);
        label->setTextFormat(Qt::TextFormat::RichText);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        SpeedGraph = new QChartView(centralwidget);
        SpeedGraph->setObjectName("SpeedGraph");
        SpeedGraph->setGeometry(QRect(460, 430, 661, 251));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(1300, 140, 71, 20));
        label_2->setFont(font);
        label_2->setTextFormat(Qt::TextFormat::RichText);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(440, 150, 341, 231));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/images/GraphSquare.png")));
        label_3->setScaledContents(true);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(800, 150, 341, 231));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/images/GraphSquare.png")));
        label_4->setScaledContents(true);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(70, 150, 341, 231));
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/images/GraphSquare.png")));
        label_5->setScaledContents(true);
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(70, 400, 341, 301));
        label_6->setPixmap(QPixmap(QString::fromUtf8(":/images/GraphSquare.png")));
        label_6->setScaledContents(true);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(900, 130, 141, 31));
        label_7->setFont(font1);
        label_7->setTextFormat(Qt::TextFormat::RichText);
        label_7->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(540, 130, 141, 31));
        label_8->setFont(font1);
        label_8->setTextFormat(Qt::TextFormat::RichText);
        label_8->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(170, 130, 141, 31));
        label_9->setFont(font1);
        label_9->setTextFormat(Qt::TextFormat::RichText);
        label_9->setAlignment(Qt::AlignmentFlag::AlignCenter);
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(460, 170, 301, 191));
        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(820, 170, 301, 191));
        formLayoutWidget_2 = new QWidget(centralwidget);
        formLayoutWidget_2->setObjectName("formLayoutWidget_2");
        formLayoutWidget_2->setGeometry(QRect(110, 180, 269, 101));
        formLayout_2 = new QFormLayout(formLayoutWidget_2);
        formLayout_2->setObjectName("formLayout_2");
        formLayout_2->setHorizontalSpacing(100);
        formLayout_2->setVerticalSpacing(15);
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        Pitch_2 = new QLabel(formLayoutWidget_2);
        Pitch_2->setObjectName("Pitch_2");
        Pitch_2->setFont(font);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, Pitch_2);

        Pitch_Data_2 = new QLabel(formLayoutWidget_2);
        Pitch_Data_2->setObjectName("Pitch_Data_2");
        Pitch_Data_2->setFont(font);
        Pitch_Data_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, Pitch_Data_2);

        Roll_2 = new QLabel(formLayoutWidget_2);
        Roll_2->setObjectName("Roll_2");
        Roll_2->setFont(font);

        formLayout_2->setWidget(1, QFormLayout::LabelRole, Roll_2);

        Roll_Data_2 = new QLabel(formLayoutWidget_2);
        Roll_Data_2->setObjectName("Roll_Data_2");
        Roll_Data_2->setFont(font);
        Roll_Data_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, Roll_Data_2);

        Yaw_2 = new QLabel(formLayoutWidget_2);
        Yaw_2->setObjectName("Yaw_2");
        Yaw_2->setFont(font);

        formLayout_2->setWidget(2, QFormLayout::LabelRole, Yaw_2);

        Yaw_Data_2 = new QLabel(formLayoutWidget_2);
        Yaw_Data_2->setObjectName("Yaw_Data_2");
        Yaw_Data_2->setFont(font);
        Yaw_Data_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        formLayout_2->setWidget(2, QFormLayout::FieldRole, Yaw_Data_2);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(110, 310, 271, 31));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush17(QColor(154, 18, 13, 255));
        brush17.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush17);
        QBrush brush18(QColor(231, 27, 19, 255));
        brush18.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Light, brush18);
        QBrush brush19(QColor(192, 22, 16, 255));
        brush19.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Midlight, brush19);
        QBrush brush20(QColor(77, 9, 6, 255));
        brush20.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Dark, brush20);
        QBrush brush21(QColor(103, 12, 9, 255));
        brush21.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Mid, brush21);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        palette2.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush17);
        palette2.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush22(QColor(204, 136, 134, 255));
        brush22.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::AlternateBase, brush22);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Active, QPalette::PlaceholderText, brush7);
#endif
#if QT_VERSION >= QT_VERSION_CHECK(6, 6, 0)
        palette2.setBrush(QPalette::Active, QPalette::Accent, brush2);
#endif
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush17);
        palette2.setBrush(QPalette::Inactive, QPalette::Light, brush18);
        palette2.setBrush(QPalette::Inactive, QPalette::Midlight, brush19);
        palette2.setBrush(QPalette::Inactive, QPalette::Dark, brush20);
        palette2.setBrush(QPalette::Inactive, QPalette::Mid, brush21);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush17);
        palette2.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush22);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush7);
#endif
#if QT_VERSION >= QT_VERSION_CHECK(6, 6, 0)
        palette2.setBrush(QPalette::Inactive, QPalette::Accent, brush2);
#endif
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush20);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush17);
        palette2.setBrush(QPalette::Disabled, QPalette::Light, brush18);
        palette2.setBrush(QPalette::Disabled, QPalette::Midlight, brush19);
        palette2.setBrush(QPalette::Disabled, QPalette::Dark, brush20);
        palette2.setBrush(QPalette::Disabled, QPalette::Mid, brush21);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush20);
        palette2.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush20);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush17);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush17);
        palette2.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush17);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        QBrush brush23(QColor(77, 9, 6, 127));
        brush23.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush23);
#endif
        QBrush brush24(QColor(200, 23, 17, 255));
        brush24.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(6, 6, 0)
        palette2.setBrush(QPalette::Disabled, QPalette::Accent, brush24);
#endif
        pushButton->setPalette(palette2);
        pushButton->setFont(font);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1540, 25));
        menuMenu = new QMenu(menubar);
        menuMenu->setObjectName("menuMenu");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuMenu->menuAction());
        menuMenu->addSeparator();
        menuMenu->addAction(actionAyarlar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionAyarlar->setText(QCoreApplication::translate("MainWindow", "Ayarlar", nullptr));
        StartButton->setText(QCoreApplication::translate("MainWindow", "Ba\305\237lat", nullptr));
        ImageLogo->setText(QString());
        telemetriLabel->setText(QString());
        Pitch->setText(QCoreApplication::translate("MainWindow", "Pitch:", nullptr));
        Roll->setText(QCoreApplication::translate("MainWindow", "Roll:", nullptr));
        Yaw->setText(QCoreApplication::translate("MainWindow", "Yaw:", nullptr));
        GPS_Label1->setText(QCoreApplication::translate("MainWindow", "Longtitute:", nullptr));
        GPS_Label2->setText(QCoreApplication::translate("MainWindow", "Lattitude:", nullptr));
        Voltage->setText(QCoreApplication::translate("MainWindow", "Bat. Voltage:", nullptr));
        SicaklikLabel->setText(QCoreApplication::translate("MainWindow", "Heat:", nullptr));
        Quest->setText(QCoreApplication::translate("MainWindow", "Quest No:", nullptr));
        Yon->setText(QCoreApplication::translate("MainWindow", "Y\303\266n:", nullptr));
        SetPointLabel->setText(QCoreApplication::translate("MainWindow", "Set Point:", nullptr));
        Speed->setText(QCoreApplication::translate("MainWindow", "Speed:", nullptr));
        Pitch_Data->setText(QCoreApplication::translate("MainWindow", "0.01 \302\260", nullptr));
        Roll_Data->setText(QCoreApplication::translate("MainWindow", "0.01 \302\260", nullptr));
        Yaw_Data->setText(QCoreApplication::translate("MainWindow", "0.01 \302\260", nullptr));
        Yon_Data->setText(QCoreApplication::translate("MainWindow", "0.01 \302\260", nullptr));
        Longtitute->setText(QCoreApplication::translate("MainWindow", "0.01 ", nullptr));
        Lattitute->setText(QCoreApplication::translate("MainWindow", "0.01 ", nullptr));
        Voltage_Data->setText(QCoreApplication::translate("MainWindow", "12.6 V", nullptr));
        Sicaklik_Data->setText(QCoreApplication::translate("MainWindow", "22.7 \302\260C", nullptr));
        QuestNo->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        SetPoint_Data->setText(QCoreApplication::translate("MainWindow", "0.0 m/s", nullptr));
        Speed_Data->setText(QCoreApplication::translate("MainWindow", "0.0 m/s", nullptr));
        SpeedFrame->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "H\304\261za Ba\304\237l\304\261 Grafik", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Telemetri", nullptr));
        label_3->setText(QString());
        label_4->setText(QString());
        label_5->setText(QString());
        label_6->setText(QString());
        label_7->setText(QCoreApplication::translate("MainWindow", "Costmap", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Kamera", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "\304\260DA Ba\304\237lant\304\261", nullptr));
        Pitch_2->setText(QCoreApplication::translate("MainWindow", "Ba\304\237lant\304\261 Durumu:", nullptr));
        Pitch_Data_2->setText(QCoreApplication::translate("MainWindow", "Aktif ", nullptr));
        Roll_2->setText(QCoreApplication::translate("MainWindow", "Port:", nullptr));
        Roll_Data_2->setText(QCoreApplication::translate("MainWindow", "COM4", nullptr));
        Yaw_2->setText(QCoreApplication::translate("MainWindow", "Baud Rate", nullptr));
        Yaw_Data_2->setText(QCoreApplication::translate("MainWindow", "9600", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Ba\304\237lant\304\261y\304\261 Kes", nullptr));
        menuMenu->setTitle(QCoreApplication::translate("MainWindow", "Menu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
