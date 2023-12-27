/********************************************************************************
** Form generated from reading UI file 'QtToolTest.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTTOOLTEST_H
#define UI_QTTOOLTEST_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qchartview.h>

QT_BEGIN_NAMESPACE

class Ui_QtToolTestClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout_13;
    QVBoxLayout *verticalLayout_12;
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
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout_10;
    QToolButton *toolButton;
    QToolButton *toolButton_2;
    QToolButton *toolButton_3;
    QFrame *frame_4;
    QGridLayout *gridLayout_4;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_openProject;
    QPushButton *pushButton_saveProject;
    QPushButton *pushButton_camerasetting;
    QPushButton *pushButton_5;
    QPushButton *pushButton_project;
    QToolButton *toolButton_dataCheck;
    QSpacerItem *horizontalSpacer_3;
    QFrame *frame_2;
    QGridLayout *gridLayout_10;
    QHBoxLayout *horizontalLayout_22;
    QVBoxLayout *verticalLayout_5;
    QFrame *frame;
    QPlainTextEdit *plainTextEdit;
    QVBoxLayout *verticalLayout_11;
    QVBoxLayout *verticalLayout_8;
    QFrame *frame_7;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_result;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_8;
    QLineEdit *lineEdit_title;
    QToolButton *toolButton_reSet;
    QToolButton *toolButton_Edit;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout;
    QLabel *label_9;
    QLabel *label_NG;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_15;
    QLabel *label_OKrate;
    QHBoxLayout *horizontalLayout_7;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_17;
    QLabel *label_AllCount;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_19;
    QLabel *label_costTime;
    QHBoxLayout *horizontalLayout_29;
    QPushButton *pushButton_run;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_stop;
    QVBoxLayout *verticalLayout_9;
    QFrame *frame_9;
    QGridLayout *gridLayout_7;
    QLabel *label_20;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_10;
    QFrame *frame_10;
    QGridLayout *gridLayout_8;
    QLabel *label_23;
    QtCharts::QChartView *widget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtToolTestClass)
    {
        if (QtToolTestClass->objectName().isEmpty())
            QtToolTestClass->setObjectName(QString::fromUtf8("QtToolTestClass"));
        QtToolTestClass->resize(1344, 889);
        centralWidget = new QWidget(QtToolTestClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_3 = new QGridLayout(centralWidget);
        gridLayout_3->setSpacing(2);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(2, 2, 2, 2);
        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setSpacing(0);
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setSpacing(1);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
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
        label_10->setPixmap(QPixmap(QString::fromUtf8("../../../robert/MatchTest/Resources/Quectel LOGO-20220215.png")));
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
        font.setBold(true);
        font.setWeight(75);
        toolButton_4->setFont(font);
        toolButton_4->setLayoutDirection(Qt::LeftToRight);
        toolButton_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 0);"));
        toolButton_4->setToolButtonStyle(Qt::ToolButtonTextOnly);
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

        horizontalSpacer_7 = new QSpacerItem(678, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_18->addItem(horizontalSpacer_7);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        toolButton = new QToolButton(frame_3);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setAutoFillBackground(false);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../../robert/MatchTest/Resources/\347\252\227\345\217\243\346\234\200\345\260\217\345\214\226.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon);
        toolButton->setIconSize(QSize(25, 25));

        horizontalLayout_10->addWidget(toolButton);

        toolButton_2 = new QToolButton(frame_3);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../../../robert/MatchTest/Resources/expand-\345\205\250\345\261\217\345\214\226.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_2->setIcon(icon1);
        toolButton_2->setIconSize(QSize(25, 25));

        horizontalLayout_10->addWidget(toolButton_2);

        toolButton_3 = new QToolButton(frame_3);
        toolButton_3->setObjectName(QString::fromUtf8("toolButton_3"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("../../../robert/MatchTest/Resources/\345\205\263\351\227\255.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_3->setIcon(icon2);
        toolButton_3->setIconSize(QSize(25, 25));

        horizontalLayout_10->addWidget(toolButton_3);

        horizontalLayout_10->setStretch(0, 1);
        horizontalLayout_10->setStretch(1, 11);

        horizontalLayout_18->addLayout(horizontalLayout_10);

        horizontalLayout_18->setStretch(0, 1);
        horizontalLayout_18->setStretch(1, 1);
        horizontalLayout_18->setStretch(2, 2);
        horizontalLayout_18->setStretch(3, 20);
        horizontalLayout_18->setStretch(4, 1);

        gridLayout->addLayout(horizontalLayout_18, 0, 0, 1, 1);


        verticalLayout_12->addWidget(frame_3);

        frame_4 = new QFrame(centralWidget);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setStyleSheet(QString::fromUtf8("background-color: rgb(32, 56, 67);"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        gridLayout_4 = new QGridLayout(frame_4);
        gridLayout_4->setSpacing(1);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(1, 1, 1, 1);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(25, -1, 25, -1);
        pushButton_openProject = new QPushButton(frame_4);
        pushButton_openProject->setObjectName(QString::fromUtf8("pushButton_openProject"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Times New Roman"));
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setWeight(75);
        pushButton_openProject->setFont(font1);
        pushButton_openProject->setAutoFillBackground(false);
        pushButton_openProject->setStyleSheet(QString::fromUtf8("color: rgb(255, 255,255);\n"
"selection-background-color: rgb(145, 145, 145);\n"
"background-color: rgb(47, 64, 69);"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("../../../robert/MatchTest/Resources/\346\211\223\345\274\200.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_openProject->setIcon(icon3);
        pushButton_openProject->setIconSize(QSize(25, 25));
        pushButton_openProject->setFlat(true);

        horizontalLayout_4->addWidget(pushButton_openProject);

        pushButton_saveProject = new QPushButton(frame_4);
        pushButton_saveProject->setObjectName(QString::fromUtf8("pushButton_saveProject"));
        pushButton_saveProject->setFont(font1);
        pushButton_saveProject->setAutoFillBackground(false);
        pushButton_saveProject->setStyleSheet(QString::fromUtf8("color: rgb(255, 255,255);\n"
"selection-background-color: rgb(145, 145, 145);\n"
"background-color: rgb(47, 64, 69);"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("../../../robert/MatchTest/Resources/\344\277\235\345\255\230.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_saveProject->setIcon(icon4);
        pushButton_saveProject->setIconSize(QSize(25, 25));
        pushButton_saveProject->setFlat(true);

        horizontalLayout_4->addWidget(pushButton_saveProject);

        pushButton_camerasetting = new QPushButton(frame_4);
        pushButton_camerasetting->setObjectName(QString::fromUtf8("pushButton_camerasetting"));
        pushButton_camerasetting->setFont(font1);
        pushButton_camerasetting->setAutoFillBackground(false);
        pushButton_camerasetting->setStyleSheet(QString::fromUtf8("color: rgb(255, 255,255);\n"
"selection-background-color: rgb(145, 145, 145);\n"
"background-color: rgb(47, 64, 69);"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8("../../../robert/MatchTest/Resources/\346\213\215\347\205\247.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_camerasetting->setIcon(icon5);
        pushButton_camerasetting->setIconSize(QSize(25, 25));
        pushButton_camerasetting->setFlat(true);

        horizontalLayout_4->addWidget(pushButton_camerasetting);

        pushButton_5 = new QPushButton(frame_4);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setFont(font1);
        pushButton_5->setAutoFillBackground(false);
        pushButton_5->setStyleSheet(QString::fromUtf8("color: rgb(255, 255,255);\n"
"selection-background-color: rgb(145, 145, 145);\n"
"background-color: rgb(47, 64, 69);"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8("../../../robert/MatchTest/Resources/\351\200\232\344\277\241\347\256\241\347\220\206.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_5->setIcon(icon6);
        pushButton_5->setIconSize(QSize(25, 25));
        pushButton_5->setFlat(true);

        horizontalLayout_4->addWidget(pushButton_5);

        pushButton_project = new QPushButton(frame_4);
        pushButton_project->setObjectName(QString::fromUtf8("pushButton_project"));
        pushButton_project->setFont(font1);
        pushButton_project->setAutoFillBackground(false);
        pushButton_project->setStyleSheet(QString::fromUtf8("color: rgb(255, 255,255);\n"
"selection-background-color: rgb(145, 145, 145);\n"
"background-color: rgb(47, 64, 69);"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8("../../../robert/MatchTest/Resources/\346\226\271\346\241\210\347\256\241\347\220\206.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_project->setIcon(icon7);
        pushButton_project->setIconSize(QSize(25, 25));
        pushButton_project->setFlat(true);

        horizontalLayout_4->addWidget(pushButton_project);

        toolButton_dataCheck = new QToolButton(frame_4);
        toolButton_dataCheck->setObjectName(QString::fromUtf8("toolButton_dataCheck"));
        toolButton_dataCheck->setFont(font1);
        toolButton_dataCheck->setStyleSheet(QString::fromUtf8("color: rgb(255, 255,255);\n"
"selection-background-color: rgb(145, 145, 145);\n"
"background-color: rgb(47, 64, 69);"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8("../../../robert/MatchTest/Resources/\346\225\260\346\215\256\346\237\245\350\257\242.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_dataCheck->setIcon(icon8);
        toolButton_dataCheck->setIconSize(QSize(25, 25));
        toolButton_dataCheck->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_4->addWidget(toolButton_dataCheck);

        horizontalSpacer_3 = new QSpacerItem(98, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        horizontalLayout_4->setStretch(0, 1);
        horizontalLayout_4->setStretch(1, 1);
        horizontalLayout_4->setStretch(2, 1);
        horizontalLayout_4->setStretch(3, 1);
        horizontalLayout_4->setStretch(4, 1);
        horizontalLayout_4->setStretch(5, 1);
        horizontalLayout_4->setStretch(6, 6);

        gridLayout_4->addLayout(horizontalLayout_4, 0, 0, 1, 1);


        verticalLayout_12->addWidget(frame_4);

        verticalLayout_12->setStretch(0, 1);
        verticalLayout_12->setStretch(1, 2);

        verticalLayout_13->addLayout(verticalLayout_12);

        frame_2 = new QFrame(centralWidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setStyleSheet(QString::fromUtf8("background-color: rgb(13, 34, 56);"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_10 = new QGridLayout(frame_2);
        gridLayout_10->setSpacing(1);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        gridLayout_10->setContentsMargins(1, 1, 1, 1);
        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setSpacing(6);
        horizontalLayout_22->setObjectName(QString::fromUtf8("horizontalLayout_22"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        frame = new QFrame(frame_2);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);

        verticalLayout_5->addWidget(frame);

        plainTextEdit = new QPlainTextEdit(frame_2);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(13, 34, 56);"));

        verticalLayout_5->addWidget(plainTextEdit);

        verticalLayout_5->setStretch(0, 5);
        verticalLayout_5->setStretch(1, 1);

        horizontalLayout_22->addLayout(verticalLayout_5);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        verticalLayout_11->setContentsMargins(-1, 5, -1, 5);
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(12);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        frame_7 = new QFrame(frame_2);
        frame_7->setObjectName(QString::fromUtf8("frame_7"));
        frame_7->setStyleSheet(QString::fromUtf8("background-color: rgb(33, 54, 65);"));
        frame_7->setFrameShape(QFrame::StyledPanel);
        frame_7->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame_7);
        gridLayout_2->setSpacing(1);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(1, 1, 1, 1);
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_result = new QLabel(frame_7);
        label_result->setObjectName(QString::fromUtf8("label_result"));
        sizePolicy.setHeightForWidth(label_result->sizePolicy().hasHeightForWidth());
        label_result->setSizePolicy(sizePolicy);
        label_result->setMaximumSize(QSize(100, 100));
        label_result->setPixmap(QPixmap(QString::fromUtf8("../../../robert/MatchTest/Resources/ok.png")));
        label_result->setScaledContents(true);

        horizontalLayout_9->addWidget(label_result);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        lineEdit_title = new QLineEdit(frame_7);
        lineEdit_title->setObjectName(QString::fromUtf8("lineEdit_title"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        lineEdit_title->setFont(font2);
        lineEdit_title->setStyleSheet(QString::fromUtf8("color: rgb(129, 211, 248);\n"
"background-color: rgb(33, 54, 65);\n"
"gridline-color: rgb(33, 54, 65);"));
        lineEdit_title->setFrame(false);
        lineEdit_title->setReadOnly(true);

        horizontalLayout_8->addWidget(lineEdit_title);

        toolButton_reSet = new QToolButton(frame_7);
        toolButton_reSet->setObjectName(QString::fromUtf8("toolButton_reSet"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8("../../../robert/MatchTest/Resources/\345\244\215\344\275\2151.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_reSet->setIcon(icon9);
        toolButton_reSet->setIconSize(QSize(15, 15));

        horizontalLayout_8->addWidget(toolButton_reSet);

        toolButton_Edit = new QToolButton(frame_7);
        toolButton_Edit->setObjectName(QString::fromUtf8("toolButton_Edit"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8("../../../robert/MatchTest/Resources/\347\274\226\350\276\221.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_Edit->setIcon(icon10);
        toolButton_Edit->setIconSize(QSize(15, 15));

        horizontalLayout_8->addWidget(toolButton_Edit);

        horizontalLayout_8->setStretch(1, 1);
        horizontalLayout_8->setStretch(2, 1);

        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_9 = new QLabel(frame_7);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(10);
        font3.setBold(true);
        font3.setWeight(75);
        label_9->setFont(font3);
        label_9->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(label_9);

        label_NG = new QLabel(frame_7);
        label_NG->setObjectName(QString::fromUtf8("label_NG"));
        label_NG->setFont(font2);
        label_NG->setStyleSheet(QString::fromUtf8("color: rgb(255, 111, 118);"));

        horizontalLayout->addWidget(label_NG);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 1);

        horizontalLayout_6->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_15 = new QLabel(frame_7);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setFont(font3);
        label_15->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        horizontalLayout_2->addWidget(label_15);

        label_OKrate = new QLabel(frame_7);
        label_OKrate->setObjectName(QString::fromUtf8("label_OKrate"));
        label_OKrate->setFont(font2);
        label_OKrate->setStyleSheet(QString::fromUtf8("color: rgb(0, 255, 0);"));

        horizontalLayout_2->addWidget(label_OKrate);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 1);

        horizontalLayout_6->addLayout(horizontalLayout_2);

        horizontalLayout_6->setStretch(0, 1);
        horizontalLayout_6->setStretch(1, 1);

        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_17 = new QLabel(frame_7);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setFont(font3);
        label_17->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        horizontalLayout_3->addWidget(label_17);

        label_AllCount = new QLabel(frame_7);
        label_AllCount->setObjectName(QString::fromUtf8("label_AllCount"));
        label_AllCount->setFont(font2);
        label_AllCount->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        horizontalLayout_3->addWidget(label_AllCount);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 1);

        horizontalLayout_7->addLayout(horizontalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_19 = new QLabel(frame_7);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setFont(font3);
        label_19->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        horizontalLayout_5->addWidget(label_19);

        label_costTime = new QLabel(frame_7);
        label_costTime->setObjectName(QString::fromUtf8("label_costTime"));
        label_costTime->setFont(font2);
        label_costTime->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 0);"));

        horizontalLayout_5->addWidget(label_costTime);

        horizontalLayout_5->setStretch(0, 1);
        horizontalLayout_5->setStretch(1, 1);

        horizontalLayout_7->addLayout(horizontalLayout_5);

        horizontalLayout_7->setStretch(0, 1);
        horizontalLayout_7->setStretch(1, 1);

        verticalLayout->addLayout(horizontalLayout_7);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 1);
        verticalLayout->setStretch(2, 1);

        horizontalLayout_9->addLayout(verticalLayout);

        horizontalLayout_9->setStretch(0, 1);
        horizontalLayout_9->setStretch(1, 6);

        gridLayout_2->addLayout(horizontalLayout_9, 0, 0, 1, 1);


        verticalLayout_8->addWidget(frame_7);

        horizontalLayout_29 = new QHBoxLayout();
        horizontalLayout_29->setSpacing(6);
        horizontalLayout_29->setObjectName(QString::fromUtf8("horizontalLayout_29"));
        pushButton_run = new QPushButton(frame_2);
        pushButton_run->setObjectName(QString::fromUtf8("pushButton_run"));
        pushButton_run->setFont(font3);
        pushButton_run->setStyleSheet(QString::fromUtf8("background-color: rgb(23, 157, 213);\n"
"color: rgb(255, 255, 255);"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8("../../../robert/MatchTest/Resources/\350\277\220\350\241\214.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_run->setIcon(icon11);
        pushButton_run->setIconSize(QSize(30, 30));

        horizontalLayout_29->addWidget(pushButton_run);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_29->addItem(horizontalSpacer_2);

        pushButton_stop = new QPushButton(frame_2);
        pushButton_stop->setObjectName(QString::fromUtf8("pushButton_stop"));
        pushButton_stop->setFont(font3);
        pushButton_stop->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(32, 193, 127);"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8("../../../robert/MatchTest/Resources/\345\201\234\346\255\242.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_stop->setIcon(icon12);
        pushButton_stop->setIconSize(QSize(30, 30));

        horizontalLayout_29->addWidget(pushButton_stop);

        horizontalLayout_29->setStretch(0, 3);
        horizontalLayout_29->setStretch(1, 1);
        horizontalLayout_29->setStretch(2, 3);

        verticalLayout_8->addLayout(horizontalLayout_29);

        verticalLayout_8->setStretch(0, 3);
        verticalLayout_8->setStretch(1, 1);

        verticalLayout_11->addLayout(verticalLayout_8);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        frame_9 = new QFrame(frame_2);
        frame_9->setObjectName(QString::fromUtf8("frame_9"));
        frame_9->setStyleSheet(QString::fromUtf8("background-color: rgb(36, 46, 58);"));
        frame_9->setFrameShape(QFrame::StyledPanel);
        frame_9->setFrameShadow(QFrame::Raised);
        gridLayout_7 = new QGridLayout(frame_9);
        gridLayout_7->setSpacing(1);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setContentsMargins(1, 1, 1, 1);
        label_20 = new QLabel(frame_9);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setFont(font3);
        label_20->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        gridLayout_7->addWidget(label_20, 0, 0, 1, 1);


        verticalLayout_9->addWidget(frame_9);

        scrollArea = new QScrollArea(frame_2);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setMinimumSize(QSize(0, 0));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 308, 500));
        scrollAreaWidgetContents->setMinimumSize(QSize(250, 500));
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_9->addWidget(scrollArea);

        verticalLayout_9->setStretch(0, 1);
        verticalLayout_9->setStretch(1, 8);

        verticalLayout_11->addLayout(verticalLayout_9);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        frame_10 = new QFrame(frame_2);
        frame_10->setObjectName(QString::fromUtf8("frame_10"));
        frame_10->setStyleSheet(QString::fromUtf8("background-color: rgb(36, 46, 58);"));
        frame_10->setFrameShape(QFrame::StyledPanel);
        frame_10->setFrameShadow(QFrame::Raised);
        gridLayout_8 = new QGridLayout(frame_10);
        gridLayout_8->setSpacing(1);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        gridLayout_8->setContentsMargins(1, 1, 1, 1);
        label_23 = new QLabel(frame_10);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setFont(font3);
        label_23->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        gridLayout_8->addWidget(label_23, 0, 0, 1, 1);


        verticalLayout_10->addWidget(frame_10);

        widget = new QtCharts::QChartView(frame_2);
        widget->setObjectName(QString::fromUtf8("widget"));

        verticalLayout_10->addWidget(widget);

        verticalLayout_10->setStretch(0, 1);
        verticalLayout_10->setStretch(1, 8);

        verticalLayout_11->addLayout(verticalLayout_10);

        verticalLayout_11->setStretch(0, 1);
        verticalLayout_11->setStretch(1, 3);
        verticalLayout_11->setStretch(2, 3);

        horizontalLayout_22->addLayout(verticalLayout_11);

        horizontalLayout_22->setStretch(0, 3);
        horizontalLayout_22->setStretch(1, 1);

        gridLayout_10->addLayout(horizontalLayout_22, 0, 0, 1, 1);


        verticalLayout_13->addWidget(frame_2);

        verticalLayout_13->setStretch(0, 1);
        verticalLayout_13->setStretch(1, 10);

        gridLayout_3->addLayout(verticalLayout_13, 0, 0, 1, 1);

        QtToolTestClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(QtToolTestClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QtToolTestClass->setStatusBar(statusBar);

        retranslateUi(QtToolTestClass);

        QMetaObject::connectSlotsByName(QtToolTestClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtToolTestClass)
    {
        QtToolTestClass->setWindowTitle(QApplication::translate("QtToolTestClass", "QtToolTest", nullptr));
        label_10->setText(QString());
        toolButton_4->setText(QApplication::translate("QtToolTestClass", "\350\256\276\347\275\256", nullptr));
        toolButton_5->setText(QApplication::translate("QtToolTestClass", "\346\227\245\345\277\227", nullptr));
        toolButton_6->setText(QApplication::translate("QtToolTestClass", "\350\257\255\350\250\200", nullptr));
        toolButton_7->setText(QApplication::translate("QtToolTestClass", "\345\270\256\345\212\251", nullptr));
        toolButton->setText(QString());
        toolButton_2->setText(QString());
        toolButton_3->setText(QString());
        pushButton_openProject->setText(QApplication::translate("QtToolTestClass", "\346\211\223\345\274\200\346\226\271\346\241\210", nullptr));
        pushButton_saveProject->setText(QApplication::translate("QtToolTestClass", "\344\277\235\345\255\230\346\226\271\346\241\210", nullptr));
        pushButton_camerasetting->setText(QApplication::translate("QtToolTestClass", "\347\233\270\346\234\272\350\256\276\347\275\256", nullptr));
        pushButton_5->setText(QApplication::translate("QtToolTestClass", "\351\200\232\350\256\257\347\256\241\347\220\206", nullptr));
        pushButton_project->setText(QApplication::translate("QtToolTestClass", "\346\226\271\346\241\210\351\205\215\347\275\256", nullptr));
        toolButton_dataCheck->setText(QApplication::translate("QtToolTestClass", "\346\225\260\346\215\256\346\237\245\350\257\242", nullptr));
        label_result->setText(QString());
        lineEdit_title->setText(QApplication::translate("QtToolTestClass", "\347\247\273\350\277\234AI\350\247\206\350\247\211\346\243\200\346\265\213\345\271\263\345\217\260", nullptr));
        toolButton_reSet->setText(QString());
        toolButton_Edit->setText(QString());
        label_9->setText(QApplication::translate("QtToolTestClass", "NG\346\225\260\351\207\217\357\274\232", nullptr));
        label_NG->setText(QApplication::translate("QtToolTestClass", "0", nullptr));
        label_15->setText(QApplication::translate("QtToolTestClass", "\345\220\210\346\240\274\347\216\207\357\274\232", nullptr));
        label_OKrate->setText(QApplication::translate("QtToolTestClass", "0%", nullptr));
        label_17->setText(QApplication::translate("QtToolTestClass", "\346\243\200\346\265\213\346\200\273\346\225\260\357\274\232", nullptr));
        label_AllCount->setText(QApplication::translate("QtToolTestClass", "0", nullptr));
        label_19->setText(QApplication::translate("QtToolTestClass", "\350\200\227\346\227\266(ms)\357\274\232", nullptr));
        label_costTime->setText(QApplication::translate("QtToolTestClass", "0", nullptr));
        pushButton_run->setText(QApplication::translate("QtToolTestClass", "\345\274\200\345\247\213\350\277\220\350\241\214", nullptr));
        pushButton_stop->setText(QApplication::translate("QtToolTestClass", "\345\201\234\346\255\242\350\277\220\350\241\214", nullptr));
        label_20->setText(QApplication::translate("QtToolTestClass", "\346\265\201\347\250\213\345\267\245\345\205\267\357\274\232", nullptr));
        label_23->setText(QApplication::translate("QtToolTestClass", "\345\220\210\346\240\274\347\216\207\350\266\213\345\212\277\345\233\276\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtToolTestClass: public Ui_QtToolTestClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTTOOLTEST_H
