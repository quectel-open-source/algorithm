/********************************************************************************
** Form generated from reading UI file 'projectClass.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROJECTCLASS_H
#define UI_PROJECTCLASS_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_projectClassClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_15;
    QVBoxLayout *verticalLayout_3;
    QFrame *frame_3;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_18;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_10;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_28;
    QToolButton *toolButton_4;
    QToolButton *toolButton_5;
    QToolButton *toolButton_6;
    QToolButton *toolButton_7;
    QSpacerItem *horizontalSpacer_2;
    QToolButton *toolButton_addTab;
    QToolButton *toolButton_match_13;
    QToolButton *toolButton_match_14;
    QToolButton *toolButton_run;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout_10;
    QToolButton *toolButton;
    QToolButton *toolButton_2;
    QToolButton *toolButton_3;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QToolBox *toolBox;
    QWidget *page;
    QGridLayout *gridLayout_2;
    QFrame *frame_2;
    QGridLayout *gridLayout_12;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QToolButton *toolButton_camera;
    QToolButton *toolButton_iamge;
    QToolButton *toolButton_SaveImage;
    QSpacerItem *verticalSpacer;
    QWidget *page_2;
    QGridLayout *gridLayout_3;
    QFrame *frame_4;
    QGridLayout *gridLayout_17;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_6;
    QToolButton *toolButton_Threshold;
    QToolButton *toolButton_ImageConvert;
    QToolButton *toolButton_morphology;
    QHBoxLayout *horizontalLayout_11;
    QToolButton *toolButton_Enhancement;
    QToolButton *toolButton_PolarCoordinate;
    QToolButton *toolButton_homography;
    QHBoxLayout *horizontalLayout_12;
    QToolButton *toolButton_affine;
    QToolButton *toolButton_clipping;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer_3;
    QWidget *page_3;
    QGridLayout *gridLayout_4;
    QFrame *frame_5;
    QGridLayout *gridLayout_16;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_8;
    QToolButton *toolButton_match;
    QToolButton *toolButton_line;
    QToolButton *toolButton_circle;
    QHBoxLayout *horizontalLayout_9;
    QToolButton *toolButton_rectangle;
    QToolButton *toolButton_ellipse;
    QToolButton *toolButton_blob;
    QSpacerItem *verticalSpacer_2;
    QWidget *page_4;
    QGridLayout *gridLayout_5;
    QFrame *frame_6;
    QToolButton *toolButton_barcode;
    QToolButton *toolButton_OCR;
    QToolButton *toolButton_color;
    QToolButton *QRCodeButton;
    QWidget *page_5;
    QGridLayout *gridLayout_6;
    QFrame *frame_7;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_7;
    QToolButton *toolButton_CreatRoi;
    QToolButton *toolButton_cross;
    QToolButton *toolButton_measurement;
    QToolButton *toolButton_crossCC;
    QWidget *page_6;
    QGridLayout *gridLayout_7;
    QFrame *frame_8;
    QToolButton *toolButton_calibrate;
    QWidget *page_7;
    QGridLayout *gridLayout_8;
    QFrame *frame_9;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout_5;
    QToolButton *toolButton_ErrorDetection;
    QToolButton *toolButton_PositiveSamples;
    QToolButton *toolButton_SmallSample;
    QWidget *layoutWidget_4;
    QHBoxLayout *horizontalLayout_4;
    QToolButton *toolButton_ObjectDetect;
    QToolButton *toolButton_imagesegmentation;
    QToolButton *toolButton_ImageClassification;
    QWidget *page_8;
    QGridLayout *gridLayout_9;
    QFrame *frame_10;
    QToolButton *toolButton_handEye;
    QToolButton *toolButton_Position;
    QToolButton *toolButton_Positioncompensation;
    QWidget *page_9;
    QGridLayout *gridLayout_10;
    QFrame *frame_11;
    QWidget *page_10;
    QGridLayout *gridLayout_11;
    QFrame *frame_12;
    QGridLayout *gridLayout_18;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_13;
    QToolButton *toolButton_SerialPort;
    QToolButton *toolButton_NetWork;
    QToolButton *toolButton_SendTxt;
    QHBoxLayout *horizontalLayout_14;
    QToolButton *toolButton_GetTxt;
    QToolButton *toolButton_CameraIo;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_4;
    QTabWidget *tabWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_image;
    QTabWidget *tabWidget_result;
    QWidget *tab_3;
    QGridLayout *gridLayout_14;
    QTableWidget *tablewidget_Results;
    QWidget *tab_4;
    QGridLayout *gridLayout_13;
    QPlainTextEdit *plainTextEdit;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *projectClassClass)
    {
        if (projectClassClass->objectName().isEmpty())
            projectClassClass->setObjectName(QString::fromUtf8("projectClassClass"));
        projectClassClass->resize(1335, 900);
        projectClassClass->setStyleSheet(QString::fromUtf8("background-color: rgb(24, 32, 45);"));
        centralWidget = new QWidget(projectClassClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_15 = new QGridLayout(centralWidget);
        gridLayout_15->setSpacing(2);
        gridLayout_15->setContentsMargins(11, 11, 11, 11);
        gridLayout_15->setObjectName(QString::fromUtf8("gridLayout_15"));
        gridLayout_15->setContentsMargins(2, 2, 2, 2);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        frame_3 = new QFrame(centralWidget);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame_3);
        gridLayout->setSpacing(2);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(2, 2, 2, 2);
        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setSpacing(6);
        horizontalLayout_18->setObjectName(QString::fromUtf8("horizontalLayout_18"));
        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setSpacing(6);
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        label_10 = new QLabel(frame_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy);
        label_10->setMaximumSize(QSize(100, 30));
        label_10->setPixmap(QPixmap(QString::fromUtf8("../../../MatchTest/Resources/Quectel LOGO-20220215.png")));
        label_10->setScaledContents(true);

        horizontalLayout_17->addWidget(label_10);

        horizontalSpacer_6 = new QSpacerItem(638, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_17->addItem(horizontalSpacer_6);

        horizontalLayout_17->setStretch(0, 1);
        horizontalLayout_17->setStretch(1, 10);

        horizontalLayout_18->addLayout(horizontalLayout_17);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_18->addItem(horizontalSpacer_4);

        horizontalLayout_28 = new QHBoxLayout();
        horizontalLayout_28->setSpacing(20);
        horizontalLayout_28->setObjectName(QString::fromUtf8("horizontalLayout_28"));
        toolButton_4 = new QToolButton(frame_3);
        toolButton_4->setObjectName(QString::fromUtf8("toolButton_4"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        toolButton_4->setFont(font);
        toolButton_4->setLayoutDirection(Qt::LeftToRight);
        toolButton_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 0);"));
        toolButton_4->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        toolButton_4->setAutoRaise(true);

        horizontalLayout_28->addWidget(toolButton_4);

        toolButton_5 = new QToolButton(frame_3);
        toolButton_5->setObjectName(QString::fromUtf8("toolButton_5"));
        toolButton_5->setFont(font);
        toolButton_5->setLayoutDirection(Qt::LeftToRight);
        toolButton_5->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 0);"));
        toolButton_5->setToolButtonStyle(Qt::ToolButtonTextOnly);
        toolButton_5->setAutoRaise(true);

        horizontalLayout_28->addWidget(toolButton_5);

        toolButton_6 = new QToolButton(frame_3);
        toolButton_6->setObjectName(QString::fromUtf8("toolButton_6"));
        toolButton_6->setFont(font);
        toolButton_6->setLayoutDirection(Qt::LeftToRight);
        toolButton_6->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 0);"));
        toolButton_6->setToolButtonStyle(Qt::ToolButtonTextOnly);
        toolButton_6->setAutoRaise(true);

        horizontalLayout_28->addWidget(toolButton_6);

        toolButton_7 = new QToolButton(frame_3);
        toolButton_7->setObjectName(QString::fromUtf8("toolButton_7"));
        toolButton_7->setFont(font);
        toolButton_7->setLayoutDirection(Qt::LeftToRight);
        toolButton_7->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 0);"));
        toolButton_7->setToolButtonStyle(Qt::ToolButtonTextOnly);
        toolButton_7->setAutoRaise(true);

        horizontalLayout_28->addWidget(toolButton_7);

        horizontalLayout_28->setStretch(0, 1);
        horizontalLayout_28->setStretch(1, 1);
        horizontalLayout_28->setStretch(2, 1);
        horizontalLayout_28->setStretch(3, 1);

        horizontalLayout_18->addLayout(horizontalLayout_28);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_18->addItem(horizontalSpacer_2);

        toolButton_addTab = new QToolButton(frame_3);
        toolButton_addTab->setObjectName(QString::fromUtf8("toolButton_addTab"));
        toolButton_addTab->setFont(font);
        toolButton_addTab->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../../MatchTest/Resources/\346\267\273\345\212\240.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_addTab->setIcon(icon);
        toolButton_addTab->setIconSize(QSize(30, 30));
        toolButton_addTab->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_18->addWidget(toolButton_addTab);

        toolButton_match_13 = new QToolButton(frame_3);
        toolButton_match_13->setObjectName(QString::fromUtf8("toolButton_match_13"));
        toolButton_match_13->setFont(font);
        toolButton_match_13->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../../../MatchTest/Resources/\345\257\274\345\207\272.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_match_13->setIcon(icon1);
        toolButton_match_13->setIconSize(QSize(30, 30));
        toolButton_match_13->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_18->addWidget(toolButton_match_13);

        toolButton_match_14 = new QToolButton(frame_3);
        toolButton_match_14->setObjectName(QString::fromUtf8("toolButton_match_14"));
        toolButton_match_14->setFont(font);
        toolButton_match_14->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("../../../MatchTest/Resources/\350\277\220\350\241\214\344\270\200\346\254\241.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_match_14->setIcon(icon2);
        toolButton_match_14->setIconSize(QSize(30, 30));
        toolButton_match_14->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_18->addWidget(toolButton_match_14);

        toolButton_run = new QToolButton(frame_3);
        toolButton_run->setObjectName(QString::fromUtf8("toolButton_run"));
        toolButton_run->setFont(font);
        toolButton_run->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("../../../MatchTest/Resources/\350\277\236\347\273\255\350\277\220\350\241\214.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_run->setIcon(icon3);
        toolButton_run->setIconSize(QSize(30, 30));
        toolButton_run->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_18->addWidget(toolButton_run);

        horizontalSpacer_7 = new QSpacerItem(678, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_18->addItem(horizontalSpacer_7);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        toolButton = new QToolButton(frame_3);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setAutoFillBackground(false);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("../../../MatchTest/Resources/\347\252\227\345\217\243\346\234\200\345\260\217\345\214\226.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon4);
        toolButton->setIconSize(QSize(25, 25));

        horizontalLayout_10->addWidget(toolButton);

        toolButton_2 = new QToolButton(frame_3);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8("../../../MatchTest/Resources/expand-\345\205\250\345\261\217\345\214\226.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_2->setIcon(icon5);
        toolButton_2->setIconSize(QSize(25, 25));

        horizontalLayout_10->addWidget(toolButton_2);

        toolButton_3 = new QToolButton(frame_3);
        toolButton_3->setObjectName(QString::fromUtf8("toolButton_3"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8("../../../MatchTest/Resources/\345\205\263\351\227\255.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_3->setIcon(icon6);
        toolButton_3->setIconSize(QSize(25, 25));

        horizontalLayout_10->addWidget(toolButton_3);

        horizontalLayout_10->setStretch(0, 1);
        horizontalLayout_10->setStretch(1, 11);

        horizontalLayout_18->addLayout(horizontalLayout_10);

        horizontalLayout_18->setStretch(0, 2);
        horizontalLayout_18->setStretch(1, 1);
        horizontalLayout_18->setStretch(2, 3);
        horizontalLayout_18->setStretch(3, 1);
        horizontalLayout_18->setStretch(4, 1);
        horizontalLayout_18->setStretch(5, 1);
        horizontalLayout_18->setStretch(6, 1);
        horizontalLayout_18->setStretch(7, 1);
        horizontalLayout_18->setStretch(8, 15);
        horizontalLayout_18->setStretch(9, 1);

        gridLayout->addLayout(horizontalLayout_18, 0, 0, 1, 1);


        verticalLayout_3->addWidget(frame_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(5, 5, 5, 5);
        toolBox = new QToolBox(centralWidget);
        toolBox->setObjectName(QString::fromUtf8("toolBox"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Times New Roman"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        toolBox->setFont(font1);
        toolBox->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"selection-color: rgb(0, 0, 0);\n"
"background-color: rgb(12, 34, 56);\n"
"icon-size: 25px;"));
        toolBox->setLineWidth(1);
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        page->setGeometry(QRect(0, 0, 219, 83));
        gridLayout_2 = new QGridLayout(page);
        gridLayout_2->setSpacing(1);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(1, 1, 1, 1);
        frame_2 = new QFrame(page);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setMaximumSize(QSize(16777215, 16777215));
        frame_2->setStyleSheet(QString::fromUtf8("background-color: rgb(24, 32, 46);"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_12 = new QGridLayout(frame_2);
        gridLayout_12->setSpacing(1);
        gridLayout_12->setContentsMargins(11, 11, 11, 11);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        gridLayout_12->setContentsMargins(1, 1, 1, 1);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(25);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        toolButton_camera = new QToolButton(frame_2);
        toolButton_camera->setObjectName(QString::fromUtf8("toolButton_camera"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(10);
        font2.setBold(false);
        font2.setWeight(50);
        toolButton_camera->setFont(font2);
        toolButton_camera->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8("../../../MatchTest/Resources/\346\213\215\347\205\247.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_camera->setIcon(icon7);
        toolButton_camera->setIconSize(QSize(30, 30));
        toolButton_camera->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout->addWidget(toolButton_camera);

        toolButton_iamge = new QToolButton(frame_2);
        toolButton_iamge->setObjectName(QString::fromUtf8("toolButton_iamge"));
        toolButton_iamge->setFont(font2);
        toolButton_iamge->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8("../../../MatchTest/Resources/\345\233\276\345\203\217.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_iamge->setIcon(icon8);
        toolButton_iamge->setIconSize(QSize(35, 35));
        toolButton_iamge->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout->addWidget(toolButton_iamge);

        toolButton_SaveImage = new QToolButton(frame_2);
        toolButton_SaveImage->setObjectName(QString::fromUtf8("toolButton_SaveImage"));
        toolButton_SaveImage->setFont(font2);
        QIcon icon9;
        icon9.addFile(QString::fromUtf8("../../../MatchTest/Resources/\344\277\235\345\255\230\345\233\276\347\211\207.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_SaveImage->setIcon(icon9);
        toolButton_SaveImage->setIconSize(QSize(35, 35));
        toolButton_SaveImage->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout->addWidget(toolButton_SaveImage);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 1);

        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 8);

        gridLayout_12->addLayout(verticalLayout, 0, 0, 1, 1);


        gridLayout_2->addWidget(frame_2, 0, 1, 1, 1);

        QIcon icon10;
        icon10.addFile(QString::fromUtf8("../../../MatchTest/Resources/\350\260\203\347\204\246\345\233\276\346\240\207-\346\224\276\345\244\247.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolBox->addItem(page, icon10, QString::fromUtf8("\345\233\276\345\203\217\351\207\207\351\233\206"));
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        page_2->setGeometry(QRect(0, 0, 243, 217));
        gridLayout_3 = new QGridLayout(page_2);
        gridLayout_3->setSpacing(2);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(2, 2, 2, 2);
        frame_4 = new QFrame(page_2);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setStyleSheet(QString::fromUtf8("background-color: rgb(24, 32, 46);"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        gridLayout_17 = new QGridLayout(frame_4);
        gridLayout_17->setSpacing(2);
        gridLayout_17->setContentsMargins(11, 11, 11, 11);
        gridLayout_17->setObjectName(QString::fromUtf8("gridLayout_17"));
        gridLayout_17->setContentsMargins(2, 2, 2, 2);
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(5);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        toolButton_Threshold = new QToolButton(frame_4);
        toolButton_Threshold->setObjectName(QString::fromUtf8("toolButton_Threshold"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Times New Roman"));
        font3.setPointSize(9);
        font3.setBold(true);
        font3.setWeight(75);
        toolButton_Threshold->setFont(font3);
        toolButton_Threshold->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8("../../../MatchTest/Resources/\346\240\207\347\255\276\344\272\214\345\200\274\345\214\226.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_Threshold->setIcon(icon11);
        toolButton_Threshold->setIconSize(QSize(30, 30));
        toolButton_Threshold->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_6->addWidget(toolButton_Threshold);

        toolButton_ImageConvert = new QToolButton(frame_4);
        toolButton_ImageConvert->setObjectName(QString::fromUtf8("toolButton_ImageConvert"));
        toolButton_ImageConvert->setFont(font3);
        toolButton_ImageConvert->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8("../../../MatchTest/Resources/\345\233\276\345\275\242\345\233\276\345\203\217\345\244\204\347\220\206.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_ImageConvert->setIcon(icon12);
        toolButton_ImageConvert->setIconSize(QSize(30, 30));
        toolButton_ImageConvert->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_6->addWidget(toolButton_ImageConvert);

        toolButton_morphology = new QToolButton(frame_4);
        toolButton_morphology->setObjectName(QString::fromUtf8("toolButton_morphology"));
        toolButton_morphology->setFont(font3);
        toolButton_morphology->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8("../../../MatchTest/Resources/\345\275\242\346\200\201\345\255\246\346\243\200\351\252\214.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_morphology->setIcon(icon13);
        toolButton_morphology->setIconSize(QSize(40, 40));
        toolButton_morphology->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_6->addWidget(toolButton_morphology);

        horizontalLayout_6->setStretch(0, 1);
        horizontalLayout_6->setStretch(1, 1);

        verticalLayout_5->addLayout(horizontalLayout_6);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        toolButton_Enhancement = new QToolButton(frame_4);
        toolButton_Enhancement->setObjectName(QString::fromUtf8("toolButton_Enhancement"));
        toolButton_Enhancement->setFont(font3);
        toolButton_Enhancement->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8("../../../MatchTest/Resources/\345\233\276\345\203\217\345\210\206\346\236\220.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_Enhancement->setIcon(icon14);
        toolButton_Enhancement->setIconSize(QSize(30, 30));
        toolButton_Enhancement->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_11->addWidget(toolButton_Enhancement);

        toolButton_PolarCoordinate = new QToolButton(frame_4);
        toolButton_PolarCoordinate->setObjectName(QString::fromUtf8("toolButton_PolarCoordinate"));
        toolButton_PolarCoordinate->setFont(font3);
        toolButton_PolarCoordinate->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        QIcon icon15;
        icon15.addFile(QString::fromUtf8("../../../MatchTest/Resources/\346\236\201\345\235\220\346\240\207\345\240\206\345\217\240\346\237\261\347\212\266\345\233\276.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_PolarCoordinate->setIcon(icon15);
        toolButton_PolarCoordinate->setIconSize(QSize(30, 30));
        toolButton_PolarCoordinate->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_11->addWidget(toolButton_PolarCoordinate);

        toolButton_homography = new QToolButton(frame_4);
        toolButton_homography->setObjectName(QString::fromUtf8("toolButton_homography"));
        toolButton_homography->setFont(font3);
        toolButton_homography->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        QIcon icon16;
        icon16.addFile(QString::fromUtf8("../../../MatchTest/Resources/\346\212\225\345\275\261\350\275\254\346\215\242.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_homography->setIcon(icon16);
        toolButton_homography->setIconSize(QSize(30, 30));
        toolButton_homography->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_11->addWidget(toolButton_homography);

        horizontalLayout_11->setStretch(0, 1);
        horizontalLayout_11->setStretch(1, 1);
        horizontalLayout_11->setStretch(2, 1);

        verticalLayout_5->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        toolButton_affine = new QToolButton(frame_4);
        toolButton_affine->setObjectName(QString::fromUtf8("toolButton_affine"));
        toolButton_affine->setFont(font3);
        toolButton_affine->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        QIcon icon17;
        icon17.addFile(QString::fromUtf8("../../../MatchTest/Resources/tx-\345\271\263\350\241\214\345\233\233\350\276\271\345\275\242.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_affine->setIcon(icon17);
        toolButton_affine->setIconSize(QSize(30, 30));
        toolButton_affine->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_12->addWidget(toolButton_affine);

        toolButton_clipping = new QToolButton(frame_4);
        toolButton_clipping->setObjectName(QString::fromUtf8("toolButton_clipping"));
        toolButton_clipping->setFont(font3);
        toolButton_clipping->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        QIcon icon18;
        icon18.addFile(QString::fromUtf8("../../../MatchTest/Resources/\350\243\201\345\211\252.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_clipping->setIcon(icon18);
        toolButton_clipping->setIconSize(QSize(30, 30));
        toolButton_clipping->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_12->addWidget(toolButton_clipping);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer);

        horizontalLayout_12->setStretch(0, 1);
        horizontalLayout_12->setStretch(1, 1);
        horizontalLayout_12->setStretch(2, 1);

        verticalLayout_5->addLayout(horizontalLayout_12);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_3);

        verticalLayout_5->setStretch(0, 1);
        verticalLayout_5->setStretch(1, 1);
        verticalLayout_5->setStretch(2, 1);
        verticalLayout_5->setStretch(3, 2);

        gridLayout_17->addLayout(verticalLayout_5, 0, 0, 1, 1);


        gridLayout_3->addWidget(frame_4, 0, 0, 1, 1);

        QIcon icon19;
        icon19.addFile(QString::fromUtf8("../../../MatchTest/Resources/\344\272\247\345\223\201\345\233\276\346\241\210.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolBox->addItem(page_2, icon19, QString::fromUtf8("\345\233\276\345\203\217\351\242\204\345\244\204\347\220\206"));
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        page_3->setGeometry(QRect(0, 0, 266, 160));
        gridLayout_4 = new QGridLayout(page_3);
        gridLayout_4->setSpacing(1);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(1, 1, 1, 1);
        frame_5 = new QFrame(page_3);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        frame_5->setStyleSheet(QString::fromUtf8("background-color: rgb(24, 32, 46);"));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        gridLayout_16 = new QGridLayout(frame_5);
        gridLayout_16->setSpacing(1);
        gridLayout_16->setContentsMargins(11, 11, 11, 11);
        gridLayout_16->setObjectName(QString::fromUtf8("gridLayout_16"));
        gridLayout_16->setContentsMargins(1, 1, 1, 1);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(20);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        toolButton_match = new QToolButton(frame_5);
        toolButton_match->setObjectName(QString::fromUtf8("toolButton_match"));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Times New Roman"));
        font4.setPointSize(10);
        font4.setBold(true);
        font4.setWeight(75);
        toolButton_match->setFont(font4);
        toolButton_match->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        QIcon icon20;
        icon20.addFile(QString::fromUtf8("../../../MatchTest/Resources/\345\256\232\344\275\215.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_match->setIcon(icon20);
        toolButton_match->setIconSize(QSize(40, 40));
        toolButton_match->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_8->addWidget(toolButton_match);

        toolButton_line = new QToolButton(frame_5);
        toolButton_line->setObjectName(QString::fromUtf8("toolButton_line"));
        toolButton_line->setFont(font4);
        toolButton_line->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        QIcon icon21;
        icon21.addFile(QString::fromUtf8("../../../MatchTest/Resources/\347\233\264\347\272\277.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_line->setIcon(icon21);
        toolButton_line->setIconSize(QSize(40, 40));
        toolButton_line->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_8->addWidget(toolButton_line);

        toolButton_circle = new QToolButton(frame_5);
        toolButton_circle->setObjectName(QString::fromUtf8("toolButton_circle"));
        toolButton_circle->setFont(font4);
        toolButton_circle->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        QIcon icon22;
        icon22.addFile(QString::fromUtf8("../../../MatchTest/Resources/\345\234\206\345\275\242\346\234\252\351\200\211\344\270\255.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_circle->setIcon(icon22);
        toolButton_circle->setIconSize(QSize(40, 40));
        toolButton_circle->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_8->addWidget(toolButton_circle);

        horizontalLayout_8->setStretch(0, 1);
        horizontalLayout_8->setStretch(1, 1);
        horizontalLayout_8->setStretch(2, 1);

        verticalLayout_4->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(20);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        toolButton_rectangle = new QToolButton(frame_5);
        toolButton_rectangle->setObjectName(QString::fromUtf8("toolButton_rectangle"));
        toolButton_rectangle->setFont(font4);
        toolButton_rectangle->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        QIcon icon23;
        icon23.addFile(QString::fromUtf8("../../../MatchTest/Resources/\347\237\251\345\275\242\346\243\200\346\265\213.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_rectangle->setIcon(icon23);
        toolButton_rectangle->setIconSize(QSize(40, 40));
        toolButton_rectangle->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_9->addWidget(toolButton_rectangle);

        toolButton_ellipse = new QToolButton(frame_5);
        toolButton_ellipse->setObjectName(QString::fromUtf8("toolButton_ellipse"));
        toolButton_ellipse->setFont(font4);
        toolButton_ellipse->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        QIcon icon24;
        icon24.addFile(QString::fromUtf8("../../../MatchTest/Resources/\346\244\255\345\234\206\345\275\242.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_ellipse->setIcon(icon24);
        toolButton_ellipse->setIconSize(QSize(40, 40));
        toolButton_ellipse->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_9->addWidget(toolButton_ellipse);

        toolButton_blob = new QToolButton(frame_5);
        toolButton_blob->setObjectName(QString::fromUtf8("toolButton_blob"));
        toolButton_blob->setFont(font4);
        toolButton_blob->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        QIcon icon25;
        icon25.addFile(QString::fromUtf8("../../../MatchTest/Resources/mine_img.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_blob->setIcon(icon25);
        toolButton_blob->setIconSize(QSize(40, 40));
        toolButton_blob->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_9->addWidget(toolButton_blob);

        horizontalLayout_9->setStretch(0, 1);
        horizontalLayout_9->setStretch(1, 1);
        horizontalLayout_9->setStretch(2, 1);

        verticalLayout_4->addLayout(horizontalLayout_9);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_2);

        verticalLayout_4->setStretch(0, 1);
        verticalLayout_4->setStretch(1, 1);
        verticalLayout_4->setStretch(2, 5);

        gridLayout_16->addLayout(verticalLayout_4, 0, 0, 1, 1);


        gridLayout_4->addWidget(frame_5, 0, 0, 1, 1);

        QIcon icon26;
        icon26.addFile(QString::fromUtf8("../../../MatchTest/Resources/\346\250\241\346\235\277\345\214\271\351\205\215.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolBox->addItem(page_3, icon26, QString::fromUtf8("\350\247\206\350\247\211\345\256\232\344\275\215"));
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        page_4->setGeometry(QRect(0, 0, 229, 454));
        gridLayout_5 = new QGridLayout(page_4);
        gridLayout_5->setSpacing(1);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(1, 1, 1, 1);
        frame_6 = new QFrame(page_4);
        frame_6->setObjectName(QString::fromUtf8("frame_6"));
        frame_6->setStyleSheet(QString::fromUtf8("background-color: rgb(24, 32, 46);"));
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        toolButton_barcode = new QToolButton(frame_6);
        toolButton_barcode->setObjectName(QString::fromUtf8("toolButton_barcode"));
        toolButton_barcode->setGeometry(QRect(0, 10, 81, 62));
        toolButton_barcode->setFont(font4);
        toolButton_barcode->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        QIcon icon27;
        icon27.addFile(QString::fromUtf8("../../../MatchTest/Resources/\346\235\241\347\240\201\346\237\245\350\257\242.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_barcode->setIcon(icon27);
        toolButton_barcode->setIconSize(QSize(40, 40));
        toolButton_barcode->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        toolButton_OCR = new QToolButton(frame_6);
        toolButton_OCR->setObjectName(QString::fromUtf8("toolButton_OCR"));
        toolButton_OCR->setGeometry(QRect(80, 10, 81, 71));
        toolButton_OCR->setFont(font4);
        toolButton_OCR->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        QIcon icon28;
        icon28.addFile(QString::fromUtf8("../../../MatchTest/Resources/OCR.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_OCR->setIcon(icon28);
        toolButton_OCR->setIconSize(QSize(35, 35));
        toolButton_OCR->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        toolButton_color = new QToolButton(frame_6);
        toolButton_color->setObjectName(QString::fromUtf8("toolButton_color"));
        toolButton_color->setGeometry(QRect(170, 10, 81, 71));
        toolButton_color->setFont(font4);
        toolButton_color->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        QIcon icon29;
        icon29.addFile(QString::fromUtf8("../../../MatchTest/Resources/\351\242\234\350\211\262.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_color->setIcon(icon29);
        toolButton_color->setIconSize(QSize(35, 35));
        toolButton_color->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        QRCodeButton = new QToolButton(frame_6);
        QRCodeButton->setObjectName(QString::fromUtf8("QRCodeButton"));
        QRCodeButton->setGeometry(QRect(10, 90, 61, 61));
        QFont font5;
        font5.setPointSize(10);
        QRCodeButton->setFont(font5);

        gridLayout_5->addWidget(frame_6, 0, 0, 1, 1);

        QIcon icon30;
        icon30.addFile(QString::fromUtf8("../../../MatchTest/Resources/\350\247\206\350\247\211\350\257\206\345\210\253.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolBox->addItem(page_4, icon30, QString::fromUtf8("\350\247\206\350\247\211\350\257\206\345\210\253"));
        page_5 = new QWidget();
        page_5->setObjectName(QString::fromUtf8("page_5"));
        page_5->setGeometry(QRect(0, 0, 229, 454));
        gridLayout_6 = new QGridLayout(page_5);
        gridLayout_6->setSpacing(1);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(1, 1, 1, 1);
        frame_7 = new QFrame(page_5);
        frame_7->setObjectName(QString::fromUtf8("frame_7"));
        frame_7->setStyleSheet(QString::fromUtf8("background-color: rgb(24, 32, 46);"));
        frame_7->setFrameShape(QFrame::StyledPanel);
        frame_7->setFrameShadow(QFrame::Raised);
        layoutWidget_2 = new QWidget(frame_7);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(0, 10, 278, 74));
        horizontalLayout_7 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        toolButton_CreatRoi = new QToolButton(layoutWidget_2);
        toolButton_CreatRoi->setObjectName(QString::fromUtf8("toolButton_CreatRoi"));
        toolButton_CreatRoi->setFont(font);
        toolButton_CreatRoi->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        QIcon icon31;
        icon31.addFile(QString::fromUtf8("../../../MatchTest/Resources/shape.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_CreatRoi->setIcon(icon31);
        toolButton_CreatRoi->setIconSize(QSize(35, 35));
        toolButton_CreatRoi->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_7->addWidget(toolButton_CreatRoi);

        toolButton_cross = new QToolButton(layoutWidget_2);
        toolButton_cross->setObjectName(QString::fromUtf8("toolButton_cross"));
        toolButton_cross->setFont(font);
        toolButton_cross->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        QIcon icon32;
        icon32.addFile(QString::fromUtf8("../../../MatchTest/Resources/cross.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_cross->setIcon(icon32);
        toolButton_cross->setIconSize(QSize(35, 35));
        toolButton_cross->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_7->addWidget(toolButton_cross);

        toolButton_measurement = new QToolButton(layoutWidget_2);
        toolButton_measurement->setObjectName(QString::fromUtf8("toolButton_measurement"));
        toolButton_measurement->setFont(font);
        toolButton_measurement->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        QIcon icon33;
        icon33.addFile(QString::fromUtf8("../../../MatchTest/Resources/\350\267\235\347\246\273\346\265\213\351\207\217.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_measurement->setIcon(icon33);
        toolButton_measurement->setIconSize(QSize(35, 35));
        toolButton_measurement->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_7->addWidget(toolButton_measurement);

        horizontalLayout_7->setStretch(0, 1);
        horizontalLayout_7->setStretch(1, 1);
        horizontalLayout_7->setStretch(2, 1);
        toolButton_crossCC = new QToolButton(frame_7);
        toolButton_crossCC->setObjectName(QString::fromUtf8("toolButton_crossCC"));
        toolButton_crossCC->setGeometry(QRect(0, 110, 71, 61));

        gridLayout_6->addWidget(frame_7, 0, 0, 1, 1);

        QIcon icon34;
        icon34.addFile(QString::fromUtf8("../../../MatchTest/Resources/\346\265\213\351\207\217.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolBox->addItem(page_5, icon34, QString::fromUtf8("\350\247\206\350\247\211\346\265\213\351\207\217"));
        page_6 = new QWidget();
        page_6->setObjectName(QString::fromUtf8("page_6"));
        page_6->setGeometry(QRect(0, 0, 100, 30));
        gridLayout_7 = new QGridLayout(page_6);
        gridLayout_7->setSpacing(1);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setContentsMargins(1, 1, 1, 1);
        frame_8 = new QFrame(page_6);
        frame_8->setObjectName(QString::fromUtf8("frame_8"));
        frame_8->setStyleSheet(QString::fromUtf8("background-color: rgb(24, 32, 46);"));
        frame_8->setFrameShape(QFrame::StyledPanel);
        frame_8->setFrameShadow(QFrame::Raised);
        toolButton_calibrate = new QToolButton(frame_8);
        toolButton_calibrate->setObjectName(QString::fromUtf8("toolButton_calibrate"));
        toolButton_calibrate->setGeometry(QRect(20, 10, 81, 62));
        toolButton_calibrate->setFont(font);
        toolButton_calibrate->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        QIcon icon35;
        icon35.addFile(QString::fromUtf8("../../../MatchTest/Resources/\350\241\250\346\240\274.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_calibrate->setIcon(icon35);
        toolButton_calibrate->setIconSize(QSize(30, 30));
        toolButton_calibrate->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout_7->addWidget(frame_8, 0, 0, 1, 1);

        QIcon icon36;
        icon36.addFile(QString::fromUtf8("../../../MatchTest/Resources/\346\240\207\345\256\232\346\235\277.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolBox->addItem(page_6, icon36, QString::fromUtf8("\350\247\206\350\247\211\346\240\207\345\256\232"));
        page_7 = new QWidget();
        page_7->setObjectName(QString::fromUtf8("page_7"));
        page_7->setGeometry(QRect(0, 0, 100, 30));
        gridLayout_8 = new QGridLayout(page_7);
        gridLayout_8->setSpacing(1);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        gridLayout_8->setContentsMargins(1, 1, 1, 1);
        frame_9 = new QFrame(page_7);
        frame_9->setObjectName(QString::fromUtf8("frame_9"));
        frame_9->setStyleSheet(QString::fromUtf8("background-color: rgb(24, 32, 46);"));
        frame_9->setFrameShape(QFrame::StyledPanel);
        frame_9->setFrameShadow(QFrame::Raised);
        layoutWidget_3 = new QWidget(frame_9);
        layoutWidget_3->setObjectName(QString::fromUtf8("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(0, 100, 251, 79));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget_3);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        toolButton_ErrorDetection = new QToolButton(layoutWidget_3);
        toolButton_ErrorDetection->setObjectName(QString::fromUtf8("toolButton_ErrorDetection"));
        toolButton_ErrorDetection->setFont(font);
        toolButton_ErrorDetection->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        QIcon icon37;
        icon37.addFile(QString::fromUtf8("../../../MatchTest/Resources/errordetect.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_ErrorDetection->setIcon(icon37);
        toolButton_ErrorDetection->setIconSize(QSize(40, 40));
        toolButton_ErrorDetection->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_5->addWidget(toolButton_ErrorDetection);

        toolButton_PositiveSamples = new QToolButton(layoutWidget_3);
        toolButton_PositiveSamples->setObjectName(QString::fromUtf8("toolButton_PositiveSamples"));
        toolButton_PositiveSamples->setFont(font);
        toolButton_PositiveSamples->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        QIcon icon38;
        icon38.addFile(QString::fromUtf8("../../../MatchTest/Resources/\345\275\261\345\203\217\346\240\267\346\234\254\347\256\241\347\220\206.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_PositiveSamples->setIcon(icon38);
        toolButton_PositiveSamples->setIconSize(QSize(40, 40));
        toolButton_PositiveSamples->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_5->addWidget(toolButton_PositiveSamples);

        toolButton_SmallSample = new QToolButton(layoutWidget_3);
        toolButton_SmallSample->setObjectName(QString::fromUtf8("toolButton_SmallSample"));
        toolButton_SmallSample->setFont(font);
        toolButton_SmallSample->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        QIcon icon39;
        icon39.addFile(QString::fromUtf8("../../../MatchTest/Resources/\346\240\267\346\234\254\346\225\260\346\215\256.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_SmallSample->setIcon(icon39);
        toolButton_SmallSample->setIconSize(QSize(40, 40));
        toolButton_SmallSample->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_5->addWidget(toolButton_SmallSample);

        horizontalLayout_5->setStretch(0, 1);
        horizontalLayout_5->setStretch(1, 1);
        horizontalLayout_5->setStretch(2, 1);
        layoutWidget_4 = new QWidget(frame_9);
        layoutWidget_4->setObjectName(QString::fromUtf8("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(0, 10, 280, 79));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget_4);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        toolButton_ObjectDetect = new QToolButton(layoutWidget_4);
        toolButton_ObjectDetect->setObjectName(QString::fromUtf8("toolButton_ObjectDetect"));
        toolButton_ObjectDetect->setFont(font);
        toolButton_ObjectDetect->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        QIcon icon40;
        icon40.addFile(QString::fromUtf8("../../../MatchTest/Resources/\347\233\256\346\240\207.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_ObjectDetect->setIcon(icon40);
        toolButton_ObjectDetect->setIconSize(QSize(40, 40));
        toolButton_ObjectDetect->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_4->addWidget(toolButton_ObjectDetect);

        toolButton_imagesegmentation = new QToolButton(layoutWidget_4);
        toolButton_imagesegmentation->setObjectName(QString::fromUtf8("toolButton_imagesegmentation"));
        toolButton_imagesegmentation->setFont(font);
        toolButton_imagesegmentation->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        QIcon icon41;
        icon41.addFile(QString::fromUtf8("../../../MatchTest/Resources/\345\261\217\345\271\225\345\210\206\345\211\262.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_imagesegmentation->setIcon(icon41);
        toolButton_imagesegmentation->setIconSize(QSize(40, 40));
        toolButton_imagesegmentation->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_4->addWidget(toolButton_imagesegmentation);

        toolButton_ImageClassification = new QToolButton(layoutWidget_4);
        toolButton_ImageClassification->setObjectName(QString::fromUtf8("toolButton_ImageClassification"));
        toolButton_ImageClassification->setFont(font);
        toolButton_ImageClassification->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        QIcon icon42;
        icon42.addFile(QString::fromUtf8("../../../MatchTest/Resources/\345\210\206\347\261\273.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_ImageClassification->setIcon(icon42);
        toolButton_ImageClassification->setIconSize(QSize(40, 40));
        toolButton_ImageClassification->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_4->addWidget(toolButton_ImageClassification);

        horizontalLayout_4->setStretch(0, 1);
        horizontalLayout_4->setStretch(1, 1);
        horizontalLayout_4->setStretch(2, 1);

        gridLayout_8->addWidget(frame_9, 0, 0, 1, 1);

        QIcon icon43;
        icon43.addFile(QString::fromUtf8("../../../MatchTest/Resources/\346\267\261\345\272\246\345\255\246\344\271\240.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolBox->addItem(page_7, icon43, QString::fromUtf8("\346\267\261\345\272\246\345\255\246\344\271\240"));
        page_8 = new QWidget();
        page_8->setObjectName(QString::fromUtf8("page_8"));
        page_8->setGeometry(QRect(0, 0, 100, 30));
        gridLayout_9 = new QGridLayout(page_8);
        gridLayout_9->setSpacing(1);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        gridLayout_9->setContentsMargins(1, 1, 1, 1);
        frame_10 = new QFrame(page_8);
        frame_10->setObjectName(QString::fromUtf8("frame_10"));
        frame_10->setStyleSheet(QString::fromUtf8("background-color: rgb(24, 32, 46);"));
        frame_10->setFrameShape(QFrame::StyledPanel);
        frame_10->setFrameShadow(QFrame::Raised);
        toolButton_handEye = new QToolButton(frame_10);
        toolButton_handEye->setObjectName(QString::fromUtf8("toolButton_handEye"));
        toolButton_handEye->setGeometry(QRect(0, 10, 70, 72));
        toolButton_handEye->setFont(font);
        toolButton_handEye->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        QIcon icon44;
        icon44.addFile(QString::fromUtf8("../../../MatchTest/Resources/\345\256\232\344\275\215 2.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_handEye->setIcon(icon44);
        toolButton_handEye->setIconSize(QSize(40, 40));
        toolButton_handEye->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        toolButton_Position = new QToolButton(frame_10);
        toolButton_Position->setObjectName(QString::fromUtf8("toolButton_Position"));
        toolButton_Position->setGeometry(QRect(90, 10, 70, 72));
        toolButton_Position->setFont(font);
        toolButton_Position->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        QIcon icon45;
        icon45.addFile(QString::fromUtf8("../../../MatchTest/Resources/\346\263\250\346\262\271\344\275\215\347\275\256-01.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_Position->setIcon(icon45);
        toolButton_Position->setIconSize(QSize(40, 40));
        toolButton_Position->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        toolButton_Positioncompensation = new QToolButton(frame_10);
        toolButton_Positioncompensation->setObjectName(QString::fromUtf8("toolButton_Positioncompensation"));
        toolButton_Positioncompensation->setGeometry(QRect(180, 10, 70, 72));
        toolButton_Positioncompensation->setFont(font);
        toolButton_Positioncompensation->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        QIcon icon46;
        icon46.addFile(QString::fromUtf8("../../../MatchTest/Resources/\346\212\230\345\274\257\350\241\245\345\201\277.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_Positioncompensation->setIcon(icon46);
        toolButton_Positioncompensation->setIconSize(QSize(40, 40));
        toolButton_Positioncompensation->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout_9->addWidget(frame_10, 0, 0, 1, 1);

        QIcon icon47;
        icon47.addFile(QString::fromUtf8("../../../MatchTest/Resources/\346\234\272\346\242\260\350\207\202.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolBox->addItem(page_8, icon47, QString::fromUtf8("\350\247\206\350\247\211\345\274\225\345\257\274"));
        page_9 = new QWidget();
        page_9->setObjectName(QString::fromUtf8("page_9"));
        page_9->setGeometry(QRect(0, 0, 100, 30));
        gridLayout_10 = new QGridLayout(page_9);
        gridLayout_10->setSpacing(1);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        gridLayout_10->setContentsMargins(1, 1, 1, 1);
        frame_11 = new QFrame(page_9);
        frame_11->setObjectName(QString::fromUtf8("frame_11"));
        frame_11->setStyleSheet(QString::fromUtf8("background-color: rgb(24, 32, 46);"));
        frame_11->setFrameShape(QFrame::StyledPanel);
        frame_11->setFrameShadow(QFrame::Raised);

        gridLayout_10->addWidget(frame_11, 0, 0, 1, 1);

        QIcon icon48;
        icon48.addFile(QString::fromUtf8("../../../MatchTest/Resources/\350\256\241\347\256\227.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolBox->addItem(page_9, icon48, QString::fromUtf8("\345\217\230\351\207\217\350\256\241\347\256\227"));
        page_10 = new QWidget();
        page_10->setObjectName(QString::fromUtf8("page_10"));
        page_10->setGeometry(QRect(0, 0, 232, 168));
        gridLayout_11 = new QGridLayout(page_10);
        gridLayout_11->setSpacing(1);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        gridLayout_11->setContentsMargins(1, 1, 1, 1);
        frame_12 = new QFrame(page_10);
        frame_12->setObjectName(QString::fromUtf8("frame_12"));
        frame_12->setStyleSheet(QString::fromUtf8("background-color: rgb(24, 32, 46);"));
        frame_12->setFrameShape(QFrame::StyledPanel);
        frame_12->setFrameShadow(QFrame::Raised);
        gridLayout_18 = new QGridLayout(frame_12);
        gridLayout_18->setSpacing(1);
        gridLayout_18->setContentsMargins(11, 11, 11, 11);
        gridLayout_18->setObjectName(QString::fromUtf8("gridLayout_18"));
        gridLayout_18->setContentsMargins(1, 1, 1, 1);
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        toolButton_SerialPort = new QToolButton(frame_12);
        toolButton_SerialPort->setObjectName(QString::fromUtf8("toolButton_SerialPort"));
        toolButton_SerialPort->setFont(font);
        toolButton_SerialPort->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        QIcon icon49;
        icon49.addFile(QString::fromUtf8("../../../MatchTest/Resources/\344\270\262\345\217\243\350\256\276\347\275\256.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_SerialPort->setIcon(icon49);
        toolButton_SerialPort->setIconSize(QSize(40, 40));
        toolButton_SerialPort->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_13->addWidget(toolButton_SerialPort);

        toolButton_NetWork = new QToolButton(frame_12);
        toolButton_NetWork->setObjectName(QString::fromUtf8("toolButton_NetWork"));
        toolButton_NetWork->setFont(font);
        toolButton_NetWork->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        QIcon icon50;
        icon50.addFile(QString::fromUtf8("../../../MatchTest/Resources/\347\275\221\347\273\234-1.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_NetWork->setIcon(icon50);
        toolButton_NetWork->setIconSize(QSize(40, 40));
        toolButton_NetWork->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_13->addWidget(toolButton_NetWork);

        toolButton_SendTxt = new QToolButton(frame_12);
        toolButton_SendTxt->setObjectName(QString::fromUtf8("toolButton_SendTxt"));
        toolButton_SendTxt->setFont(font);
        toolButton_SendTxt->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        QIcon icon51;
        icon51.addFile(QString::fromUtf8("../../../MatchTest/Resources/XML\346\212\245\346\226\207.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_SendTxt->setIcon(icon51);
        toolButton_SendTxt->setIconSize(QSize(40, 40));
        toolButton_SendTxt->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_13->addWidget(toolButton_SendTxt);

        horizontalLayout_13->setStretch(0, 1);
        horizontalLayout_13->setStretch(1, 1);
        horizontalLayout_13->setStretch(2, 1);

        verticalLayout_6->addLayout(horizontalLayout_13);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        toolButton_GetTxt = new QToolButton(frame_12);
        toolButton_GetTxt->setObjectName(QString::fromUtf8("toolButton_GetTxt"));
        toolButton_GetTxt->setFont(font);
        toolButton_GetTxt->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        QIcon icon52;
        icon52.addFile(QString::fromUtf8("../../../MatchTest/Resources/F\346\212\245\346\226\207.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_GetTxt->setIcon(icon52);
        toolButton_GetTxt->setIconSize(QSize(40, 40));
        toolButton_GetTxt->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_14->addWidget(toolButton_GetTxt);

        toolButton_CameraIo = new QToolButton(frame_12);
        toolButton_CameraIo->setObjectName(QString::fromUtf8("toolButton_CameraIo"));
        toolButton_CameraIo->setFont(font);
        toolButton_CameraIo->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        QIcon icon53;
        icon53.addFile(QString::fromUtf8("../../../MatchTest/Resources/\345\233\264\347\273\225\347\233\270\346\234\272\346\227\213\350\275\254.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_CameraIo->setIcon(icon53);
        toolButton_CameraIo->setIconSize(QSize(40, 40));
        toolButton_CameraIo->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_14->addWidget(toolButton_CameraIo);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_3);

        horizontalLayout_14->setStretch(0, 2);
        horizontalLayout_14->setStretch(1, 2);
        horizontalLayout_14->setStretch(2, 1);

        verticalLayout_6->addLayout(horizontalLayout_14);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_4);

        verticalLayout_6->setStretch(0, 1);
        verticalLayout_6->setStretch(1, 1);
        verticalLayout_6->setStretch(2, 5);

        gridLayout_18->addLayout(verticalLayout_6, 0, 0, 1, 1);


        gridLayout_11->addWidget(frame_12, 0, 0, 1, 1);

        QIcon icon54;
        icon54.addFile(QString::fromUtf8("../../../MatchTest/Resources/\351\200\232\344\277\241.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolBox->addItem(page_10, icon54, QString::fromUtf8("\351\200\232\344\277\241\345\267\245\345\205\267"));

        horizontalLayout_2->addWidget(toolBox);

        horizontalLayout_2->setStretch(0, 1);

        horizontalLayout_3->addLayout(horizontalLayout_2);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QFont font6;
        font6.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font6.setPointSize(12);
        font6.setBold(false);
        font6.setWeight(50);
        tabWidget->setFont(font6);

        horizontalLayout_3->addWidget(tabWidget);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_image = new QLabel(centralWidget);
        label_image->setObjectName(QString::fromUtf8("label_image"));
        label_image->setMinimumSize(QSize(596, 590));
        label_image->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));

        verticalLayout_2->addWidget(label_image);

        tabWidget_result = new QTabWidget(centralWidget);
        tabWidget_result->setObjectName(QString::fromUtf8("tabWidget_result"));
        tabWidget_result->setFont(font2);
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        gridLayout_14 = new QGridLayout(tab_3);
        gridLayout_14->setSpacing(2);
        gridLayout_14->setContentsMargins(11, 11, 11, 11);
        gridLayout_14->setObjectName(QString::fromUtf8("gridLayout_14"));
        gridLayout_14->setContentsMargins(2, 2, 2, 2);
        tablewidget_Results = new QTableWidget(tab_3);
        tablewidget_Results->setObjectName(QString::fromUtf8("tablewidget_Results"));

        gridLayout_14->addWidget(tablewidget_Results, 0, 0, 1, 1);

        tabWidget_result->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        gridLayout_13 = new QGridLayout(tab_4);
        gridLayout_13->setSpacing(2);
        gridLayout_13->setContentsMargins(11, 11, 11, 11);
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        gridLayout_13->setContentsMargins(2, 2, 2, 2);
        plainTextEdit = new QPlainTextEdit(tab_4);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(13, 34, 56);"));

        gridLayout_13->addWidget(plainTextEdit, 0, 0, 1, 1);

        tabWidget_result->addTab(tab_4, QString());

        verticalLayout_2->addWidget(tabWidget_result);

        verticalLayout_2->setStretch(0, 3);
        verticalLayout_2->setStretch(1, 1);

        horizontalLayout_3->addLayout(verticalLayout_2);

        horizontalLayout_3->setStretch(0, 2);
        horizontalLayout_3->setStretch(1, 4);
        horizontalLayout_3->setStretch(2, 5);

        verticalLayout_3->addLayout(horizontalLayout_3);

        verticalLayout_3->setStretch(0, 1);
        verticalLayout_3->setStretch(1, 15);

        gridLayout_15->addLayout(verticalLayout_3, 0, 0, 1, 1);

        projectClassClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(projectClassClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        projectClassClass->setStatusBar(statusBar);

        retranslateUi(projectClassClass);

        toolBox->setCurrentIndex(4);
        toolBox->layout()->setSpacing(0);
        tabWidget->setCurrentIndex(-1);
        tabWidget_result->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(projectClassClass);
    } // setupUi

    void retranslateUi(QMainWindow *projectClassClass)
    {
        projectClassClass->setWindowTitle(QApplication::translate("projectClassClass", "projectClass", nullptr));
        label_10->setText(QString());
        toolButton_4->setText(QApplication::translate("projectClassClass", "\350\256\276\347\275\256", nullptr));
        toolButton_5->setText(QApplication::translate("projectClassClass", "\346\227\245\345\277\227", nullptr));
        toolButton_6->setText(QApplication::translate("projectClassClass", "\350\257\255\350\250\200", nullptr));
        toolButton_7->setText(QApplication::translate("projectClassClass", "\345\270\256\345\212\251", nullptr));
        toolButton_addTab->setText(QApplication::translate("projectClassClass", "\346\267\273\345\212\240\346\265\201\347\250\213", nullptr));
        toolButton_match_13->setText(QApplication::translate("projectClassClass", "\345\257\274\345\207\272\346\265\201\347\250\213", nullptr));
        toolButton_match_14->setText(QApplication::translate("projectClassClass", "\350\277\220\350\241\214\344\270\200\346\254\241", nullptr));
        toolButton_run->setText(QApplication::translate("projectClassClass", "\350\277\236\347\273\255\350\277\220\350\241\214", nullptr));
        toolButton->setText(QString());
        toolButton_2->setText(QString());
        toolButton_3->setText(QString());
        toolButton_camera->setText(QApplication::translate("projectClassClass", "\347\233\270\346\234\272", nullptr));
        toolButton_iamge->setText(QApplication::translate("projectClassClass", "\345\233\276\347\211\207", nullptr));
        toolButton_SaveImage->setText(QApplication::translate("projectClassClass", "\344\277\235\345\255\230\345\233\276\345\203\217", nullptr));
        toolBox->setItemText(toolBox->indexOf(page), QApplication::translate("projectClassClass", "\345\233\276\345\203\217\351\207\207\351\233\206", nullptr));
        toolButton_Threshold->setText(QApplication::translate("projectClassClass", "\344\272\214\345\200\274\345\214\226", nullptr));
        toolButton_ImageConvert->setText(QApplication::translate("projectClassClass", "\345\233\276\345\203\217\350\275\254\346\215\242", nullptr));
        toolButton_morphology->setText(QApplication::translate("projectClassClass", "\345\275\242\346\200\201\345\255\246", nullptr));
        toolButton_Enhancement->setText(QApplication::translate("projectClassClass", "\345\233\276\345\203\217\345\242\236\345\274\272", nullptr));
        toolButton_PolarCoordinate->setText(QApplication::translate("projectClassClass", "\346\236\201\345\235\220\346\240\207\345\217\230\346\215\242", nullptr));
        toolButton_homography->setText(QApplication::translate("projectClassClass", "\346\212\225\345\275\261\345\217\230\346\215\242", nullptr));
        toolButton_affine->setText(QApplication::translate("projectClassClass", "\344\273\277\345\260\204\345\217\230\346\215\242", nullptr));
        toolButton_clipping->setText(QApplication::translate("projectClassClass", "\345\233\276\345\203\217\350\243\201\345\211\252", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_2), QApplication::translate("projectClassClass", "\345\233\276\345\203\217\351\242\204\345\244\204\347\220\206", nullptr));
        toolButton_match->setText(QApplication::translate("projectClassClass", "\346\250\241\346\235\277\345\214\271\351\205\215", nullptr));
        toolButton_line->setText(QApplication::translate("projectClassClass", "\347\233\264\347\272\277\346\243\200\346\265\213", nullptr));
        toolButton_circle->setText(QApplication::translate("projectClassClass", "\345\234\206\345\275\242\346\243\200\346\265\213", nullptr));
        toolButton_rectangle->setText(QApplication::translate("projectClassClass", "\347\237\251\345\275\242\346\243\200\346\265\213", nullptr));
        toolButton_ellipse->setText(QApplication::translate("projectClassClass", "\346\244\255\345\234\206\346\243\200\346\265\213", nullptr));
        toolButton_blob->setText(QApplication::translate("projectClassClass", "\345\214\272\345\237\237\345\210\206\346\236\220", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_3), QApplication::translate("projectClassClass", "\350\247\206\350\247\211\345\256\232\344\275\215", nullptr));
        toolButton_barcode->setText(QApplication::translate("projectClassClass", "\346\235\241\347\240\201\350\257\206\345\210\253", nullptr));
        toolButton_OCR->setText(QApplication::translate("projectClassClass", "\345\255\227\347\254\246\350\257\206\345\210\253", nullptr));
        toolButton_color->setText(QApplication::translate("projectClassClass", "\351\242\234\350\211\262\350\257\206\345\210\253", nullptr));
        QRCodeButton->setText(QApplication::translate("projectClassClass", "\344\272\214\347\273\264\347\240\201\350\257\206\345\210\253", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_4), QApplication::translate("projectClassClass", "\350\247\206\350\247\211\350\257\206\345\210\253", nullptr));
        toolButton_CreatRoi->setText(QApplication::translate("projectClassClass", "\345\210\233\345\273\272ROI", nullptr));
        toolButton_cross->setText(QApplication::translate("projectClassClass", "\344\272\244\347\202\271\350\256\241\347\256\227", nullptr));
        toolButton_measurement->setText(QApplication::translate("projectClassClass", "\345\260\272\345\257\270\346\265\213\351\207\217", nullptr));
        toolButton_crossCC->setText(QApplication::translate("projectClassClass", "\344\272\244\347\202\271\345\234\206\345\234\206", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_5), QApplication::translate("projectClassClass", "\350\247\206\350\247\211\346\265\213\351\207\217", nullptr));
        toolButton_calibrate->setText(QApplication::translate("projectClassClass", "\345\233\276\345\203\217\346\240\207\345\256\232", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_6), QApplication::translate("projectClassClass", "\350\247\206\350\247\211\346\240\207\345\256\232", nullptr));
        toolButton_ErrorDetection->setText(QApplication::translate("projectClassClass", "\345\274\202\345\270\270\346\243\200\346\265\213", nullptr));
        toolButton_PositiveSamples->setText(QApplication::translate("projectClassClass", "\346\255\243\346\240\267\346\234\254", nullptr));
        toolButton_SmallSample->setText(QApplication::translate("projectClassClass", "\345\260\217\346\240\267\346\234\254", nullptr));
        toolButton_ObjectDetect->setText(QApplication::translate("projectClassClass", "\347\233\256\346\240\207\350\257\206\345\210\253", nullptr));
        toolButton_imagesegmentation->setText(QApplication::translate("projectClassClass", "\345\233\276\345\203\217\345\210\206\345\211\262", nullptr));
        toolButton_ImageClassification->setText(QApplication::translate("projectClassClass", "\345\233\276\345\203\217\345\210\206\347\261\273", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_7), QApplication::translate("projectClassClass", "\346\267\261\345\272\246\345\255\246\344\271\240", nullptr));
        toolButton_handEye->setText(QApplication::translate("projectClassClass", "\346\211\213\347\234\274\346\240\207\345\256\232", nullptr));
        toolButton_Position->setText(QApplication::translate("projectClassClass", "\344\275\215\347\275\256\350\256\241\347\256\227", nullptr));
        toolButton_Positioncompensation->setText(QApplication::translate("projectClassClass", "\344\275\215\347\275\256\350\241\245\345\201\277", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_8), QApplication::translate("projectClassClass", "\350\247\206\350\247\211\345\274\225\345\257\274", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_9), QApplication::translate("projectClassClass", "\345\217\230\351\207\217\350\256\241\347\256\227", nullptr));
        toolButton_SerialPort->setText(QApplication::translate("projectClassClass", "\344\270\262\345\217\243\351\205\215\347\275\256", nullptr));
        toolButton_NetWork->setText(QApplication::translate("projectClassClass", "\347\275\221\347\273\234\351\205\215\347\275\256", nullptr));
        toolButton_SendTxt->setText(QApplication::translate("projectClassClass", "\346\212\245\346\226\207\345\217\221\351\200\201", nullptr));
        toolButton_GetTxt->setText(QApplication::translate("projectClassClass", "\346\212\245\346\226\207\346\216\245\346\224\266", nullptr));
        toolButton_CameraIo->setText(QApplication::translate("projectClassClass", "\347\233\270\346\234\272IO", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_10), QApplication::translate("projectClassClass", "\351\200\232\344\277\241\345\267\245\345\205\267", nullptr));
        label_image->setText(QString());
        tabWidget_result->setTabText(tabWidget_result->indexOf(tab_3), QApplication::translate("projectClassClass", "\347\273\223\346\236\234", nullptr));
        tabWidget_result->setTabText(tabWidget_result->indexOf(tab_4), QApplication::translate("projectClassClass", "\346\227\245\345\277\227", nullptr));
    } // retranslateUi

};

namespace Ui {
    class projectClassClass: public Ui_projectClassClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROJECTCLASS_H
