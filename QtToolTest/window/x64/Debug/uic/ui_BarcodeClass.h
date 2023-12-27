/********************************************************************************
** Form generated from reading UI file 'BarcodeClass.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BARCODECLASS_H
#define UI_BARCODECLASS_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BarcodeClassClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_11;
    QFrame *frame_5;
    QGridLayout *gridLayout_14;
    QVBoxLayout *verticalLayout_5;
    QFrame *frame;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_18;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_10;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_28;
    QToolButton *toolButton_4;
    QToolButton *toolButton_5;
    QToolButton *toolButton_6;
    QToolButton *toolButton_7;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_title;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout_10;
    QToolButton *toolButton;
    QToolButton *toolButton_2;
    QToolButton *toolButton_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_image;
    QPlainTextEdit *plainTextEdit;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_5;
    QFrame *frame_2;
    QGridLayout *gridLayout_8;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_22;
    QLabel *label_12;
    QSpacerItem *horizontalSpacer_10;
    QComboBox *cmb_BarCodeImage;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *btn_DrawRoi_BarCode;
    QPushButton *btn_ClearRoi_BarCode;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_31;
    QLabel *label_21;
    QSpinBox *spb_CodeNum_BarCode;
    QHBoxLayout *horizontalLayout_20;
    QLabel *label_11;
    QSpacerItem *horizontalSpacer_8;
    QComboBox *cmb_Tolerance_BarCode;
    QHBoxLayout *horizontalLayout_32;
    QLabel *label_28;
    QSpinBox *spb_TimeOut_BarCode;
    QVBoxLayout *verticalLayout;
    QFrame *frame_6;
    QGridLayout *gridLayout_3;
    QLabel *label_4;
    QGroupBox *groupBox_1D;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout_9;
    QVBoxLayout *verticalLayout_14;
    QCheckBox *ckb_CODE128_BarCode;
    QCheckBox *ckb_EAN13_BarCode;
    QCheckBox *ckb_CODE93_BarCode;
    QCheckBox *ckb_UPCA_BarCode;
    QCheckBox *ckb_CODABAR_BarCode;
    QVBoxLayout *verticalLayout_15;
    QCheckBox *ckb_CODE39_BarCode;
    QCheckBox *ckb_EAN8_BarCode;
    QCheckBox *ckb_ITF25_BarCode;
    QCheckBox *ckb_UPCE_BarCode;
    QCheckBox *ckb_PHARMACODE_BarCode;
    QGroupBox *groupBox_2D;
    QGridLayout *gridLayout_10;
    QGridLayout *gridLayout_12;
    QVBoxLayout *verticalLayout_22;
    QCheckBox *ckb_DM_Code2d;
    QCheckBox *ckb_Aztec_Code2d;
    QCheckBox *ckb_GS1DM_Code2d;
    QCheckBox *checkBox;
    QCheckBox *ckb_MicroQR_Code2d;
    QVBoxLayout *verticalLayout_23;
    QCheckBox *ckb_QR_Code2d;
    QCheckBox *ckb_GS1Aztec_Code2d;
    QCheckBox *ckb_GS1QR_Code2d;
    QCheckBox *ckb_PDF417_Code2d;
    QVBoxLayout *verticalLayout_3;
    QFrame *frame_7;
    QGridLayout *gridLayout_4;
    QLabel *label_5;
    QVBoxLayout *verticalLayout_17;
    QHBoxLayout *horizontalLayout_21;
    QLabel *label_59;
    QLineEdit *txt_HeadChar_BarCode;
    QHBoxLayout *horizontalLayout_26;
    QLabel *label_60;
    QLineEdit *txt_EndChar_BarCode;
    QHBoxLayout *horizontalLayout_27;
    QLabel *label_61;
    QLineEdit *txt_ContainChar_BarCode;
    QHBoxLayout *horizontalLayout_29;
    QLabel *label_62;
    QLineEdit *txt_NotContainChar_BarCode;
    QHBoxLayout *horizontalLayout_30;
    QLabel *label_63;
    QLineEdit *txt_CodeLength_BarCode;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *btn_FindBarCode;
    QSpacerItem *horizontalSpacer_16;
    QPushButton *pushButton_save;
    QWidget *tab_2;
    QGridLayout *gridLayout_6;
    QFrame *frame_3;
    QGridLayout *gridLayout_7;
    QTableWidget *tablewidget_Results_BarCode;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *BarcodeClassClass)
    {
        if (BarcodeClassClass->objectName().isEmpty())
            BarcodeClassClass->setObjectName(QString::fromUtf8("BarcodeClassClass"));
        BarcodeClassClass->resize(1329, 912);
        centralWidget = new QWidget(BarcodeClassClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_11 = new QGridLayout(centralWidget);
        gridLayout_11->setSpacing(2);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        gridLayout_11->setContentsMargins(2, 2, 2, 2);
        frame_5 = new QFrame(centralWidget);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        frame_5->setStyleSheet(QString::fromUtf8("background-color: rgb(12, 34, 56);"));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        gridLayout_14 = new QGridLayout(frame_5);
        gridLayout_14->setSpacing(1);
        gridLayout_14->setContentsMargins(11, 11, 11, 11);
        gridLayout_14->setObjectName(QString::fromUtf8("gridLayout_14"));
        gridLayout_14->setContentsMargins(1, 1, 1, 1);
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        frame = new QFrame(frame_5);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame);
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
        label_10 = new QLabel(frame);
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

        horizontalLayout_28 = new QHBoxLayout();
        horizontalLayout_28->setSpacing(20);
        horizontalLayout_28->setObjectName(QString::fromUtf8("horizontalLayout_28"));
        toolButton_4 = new QToolButton(frame);
        toolButton_4->setObjectName(QString::fromUtf8("toolButton_4"));
        QFont font;
        font.setFamily(QString::fromUtf8("Times New Roman"));
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        toolButton_4->setFont(font);
        toolButton_4->setLayoutDirection(Qt::LeftToRight);
        toolButton_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 0);"));
        toolButton_4->setToolButtonStyle(Qt::ToolButtonTextOnly);
        toolButton_4->setAutoRaise(true);

        horizontalLayout_28->addWidget(toolButton_4);

        toolButton_5 = new QToolButton(frame);
        toolButton_5->setObjectName(QString::fromUtf8("toolButton_5"));
        toolButton_5->setFont(font);
        toolButton_5->setLayoutDirection(Qt::LeftToRight);
        toolButton_5->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 0);"));
        toolButton_5->setToolButtonStyle(Qt::ToolButtonTextOnly);
        toolButton_5->setAutoRaise(true);

        horizontalLayout_28->addWidget(toolButton_5);

        toolButton_6 = new QToolButton(frame);
        toolButton_6->setObjectName(QString::fromUtf8("toolButton_6"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Liberation Serif"));
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setWeight(75);
        toolButton_6->setFont(font1);
        toolButton_6->setLayoutDirection(Qt::LeftToRight);
        toolButton_6->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 0);"));
        toolButton_6->setToolButtonStyle(Qt::ToolButtonTextOnly);
        toolButton_6->setAutoRaise(true);

        horizontalLayout_28->addWidget(toolButton_6);

        toolButton_7 = new QToolButton(frame);
        toolButton_7->setObjectName(QString::fromUtf8("toolButton_7"));
        toolButton_7->setFont(font1);
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

        label_title = new QLabel(frame);
        label_title->setObjectName(QString::fromUtf8("label_title"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(14);
        font2.setBold(true);
        font2.setWeight(75);
        label_title->setFont(font2);
        label_title->setAlignment(Qt::AlignCenter);

        horizontalLayout_18->addWidget(label_title);

        horizontalSpacer_7 = new QSpacerItem(678, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_18->addItem(horizontalSpacer_7);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        toolButton = new QToolButton(frame);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setAutoFillBackground(false);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../../MatchTest/Resources/\347\252\227\345\217\243\346\234\200\345\260\217\345\214\226.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon);
        toolButton->setIconSize(QSize(25, 25));

        horizontalLayout_10->addWidget(toolButton);

        toolButton_2 = new QToolButton(frame);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../../../MatchTest/Resources/expand-\345\205\250\345\261\217\345\214\226.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_2->setIcon(icon1);
        toolButton_2->setIconSize(QSize(25, 25));

        horizontalLayout_10->addWidget(toolButton_2);

        toolButton_3 = new QToolButton(frame);
        toolButton_3->setObjectName(QString::fromUtf8("toolButton_3"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("../../../MatchTest/Resources/\345\205\263\351\227\255.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_3->setIcon(icon2);
        toolButton_3->setIconSize(QSize(25, 25));

        horizontalLayout_10->addWidget(toolButton_3);

        horizontalLayout_10->setStretch(0, 1);
        horizontalLayout_10->setStretch(1, 11);

        horizontalLayout_18->addLayout(horizontalLayout_10);

        horizontalLayout_18->setStretch(0, 1);
        horizontalLayout_18->setStretch(1, 2);
        horizontalLayout_18->setStretch(2, 2);
        horizontalLayout_18->setStretch(3, 4);
        horizontalLayout_18->setStretch(4, 6);
        horizontalLayout_18->setStretch(5, 1);

        gridLayout->addLayout(horizontalLayout_18, 0, 0, 1, 1);


        verticalLayout_5->addWidget(frame);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        label_image = new QLabel(frame_5);
        label_image->setObjectName(QString::fromUtf8("label_image"));
        label_image->setMinimumSize(QSize(981, 703));
        label_image->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));

        verticalLayout_7->addWidget(label_image);

        plainTextEdit = new QPlainTextEdit(frame_5);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(13, 34, 56);"));

        verticalLayout_7->addWidget(plainTextEdit);

        verticalLayout_7->setStretch(0, 6);
        verticalLayout_7->setStretch(1, 1);

        horizontalLayout->addLayout(verticalLayout_7);

        tabWidget = new QTabWidget(frame_5);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(12);
        font3.setBold(false);
        font3.setWeight(50);
        tabWidget->setFont(font3);
        tabWidget->setAutoFillBackground(false);
        tabWidget->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setMovable(false);
        tabWidget->setTabBarAutoHide(true);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout_5 = new QGridLayout(tab);
        gridLayout_5->setSpacing(2);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(2, 2, 2, 2);
        frame_2 = new QFrame(tab);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_8 = new QGridLayout(frame_2);
        gridLayout_8->setSpacing(2);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        gridLayout_8->setContentsMargins(2, 2, 2, 2);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, 6, -1, -1);
        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setSpacing(6);
        horizontalLayout_22->setObjectName(QString::fromUtf8("horizontalLayout_22"));
        label_12 = new QLabel(frame_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font4.setPointSize(11);
        label_12->setFont(font4);
        label_12->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);"));

        horizontalLayout_22->addWidget(label_12);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_22->addItem(horizontalSpacer_10);

        cmb_BarCodeImage = new QComboBox(frame_2);
        cmb_BarCodeImage->setObjectName(QString::fromUtf8("cmb_BarCodeImage"));
        cmb_BarCodeImage->setFont(font4);
        cmb_BarCodeImage->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);\n"
"background-color: rgb(14, 34, 59);"));

        horizontalLayout_22->addWidget(cmb_BarCodeImage);

        horizontalLayout_22->setStretch(0, 2);
        horizontalLayout_22->setStretch(1, 3);
        horizontalLayout_22->setStretch(2, 5);

        verticalLayout_2->addLayout(horizontalLayout_22);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_3 = new QLabel(frame_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font5;
        font5.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font5.setPointSize(11);
        font5.setBold(false);
        font5.setWeight(50);
        label_3->setFont(font5);
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);"));

        horizontalLayout_4->addWidget(label_3);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_9);

        btn_DrawRoi_BarCode = new QPushButton(frame_2);
        btn_DrawRoi_BarCode->setObjectName(QString::fromUtf8("btn_DrawRoi_BarCode"));
        btn_DrawRoi_BarCode->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);\n"
"background-color: rgb(27, 46, 71);"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("../../../MatchTest/Resources/\347\237\251\345\275\242.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_DrawRoi_BarCode->setIcon(icon3);
        btn_DrawRoi_BarCode->setIconSize(QSize(20, 20));

        horizontalLayout_4->addWidget(btn_DrawRoi_BarCode);

        btn_ClearRoi_BarCode = new QPushButton(frame_2);
        btn_ClearRoi_BarCode->setObjectName(QString::fromUtf8("btn_ClearRoi_BarCode"));
        btn_ClearRoi_BarCode->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);\n"
"background-color: rgb(27, 46, 71);"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("../../../MatchTest/Resources/\345\244\215\344\275\215 (1).png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_ClearRoi_BarCode->setIcon(icon4);
        btn_ClearRoi_BarCode->setIconSize(QSize(20, 20));

        horizontalLayout_4->addWidget(btn_ClearRoi_BarCode);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        horizontalLayout_4->setStretch(0, 1);
        horizontalLayout_4->setStretch(1, 2);
        horizontalLayout_4->setStretch(2, 1);
        horizontalLayout_4->setStretch(3, 1);

        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_31 = new QHBoxLayout();
        horizontalLayout_31->setSpacing(6);
        horizontalLayout_31->setObjectName(QString::fromUtf8("horizontalLayout_31"));
        label_21 = new QLabel(frame_2);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        sizePolicy.setHeightForWidth(label_21->sizePolicy().hasHeightForWidth());
        label_21->setSizePolicy(sizePolicy);
        label_21->setFont(font4);
        label_21->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);"));

        horizontalLayout_31->addWidget(label_21);

        spb_CodeNum_BarCode = new QSpinBox(frame_2);
        spb_CodeNum_BarCode->setObjectName(QString::fromUtf8("spb_CodeNum_BarCode"));
        spb_CodeNum_BarCode->setFont(font4);
        spb_CodeNum_BarCode->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);\n"
"background-color: rgb(30, 50, 77);"));
        spb_CodeNum_BarCode->setMinimum(1);
        spb_CodeNum_BarCode->setMaximum(100);
        spb_CodeNum_BarCode->setValue(5);

        horizontalLayout_31->addWidget(spb_CodeNum_BarCode);

        horizontalLayout_31->setStretch(0, 1);
        horizontalLayout_31->setStretch(1, 1);

        verticalLayout_2->addLayout(horizontalLayout_31);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setSpacing(6);
        horizontalLayout_20->setObjectName(QString::fromUtf8("horizontalLayout_20"));
        label_11 = new QLabel(frame_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setFont(font4);
        label_11->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);"));

        horizontalLayout_20->addWidget(label_11);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_20->addItem(horizontalSpacer_8);

        cmb_Tolerance_BarCode = new QComboBox(frame_2);
        cmb_Tolerance_BarCode->addItem(QString());
        cmb_Tolerance_BarCode->addItem(QString());
        cmb_Tolerance_BarCode->setObjectName(QString::fromUtf8("cmb_Tolerance_BarCode"));
        cmb_Tolerance_BarCode->setFont(font4);
        cmb_Tolerance_BarCode->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);\n"
"background-color: rgb(14, 34, 59);"));

        horizontalLayout_20->addWidget(cmb_Tolerance_BarCode);

        horizontalLayout_20->setStretch(0, 2);
        horizontalLayout_20->setStretch(1, 3);
        horizontalLayout_20->setStretch(2, 5);

        verticalLayout_2->addLayout(horizontalLayout_20);

        horizontalLayout_32 = new QHBoxLayout();
        horizontalLayout_32->setSpacing(6);
        horizontalLayout_32->setObjectName(QString::fromUtf8("horizontalLayout_32"));
        label_28 = new QLabel(frame_2);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        sizePolicy.setHeightForWidth(label_28->sizePolicy().hasHeightForWidth());
        label_28->setSizePolicy(sizePolicy);
        label_28->setFont(font4);
        label_28->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);"));

        horizontalLayout_32->addWidget(label_28);

        spb_TimeOut_BarCode = new QSpinBox(frame_2);
        spb_TimeOut_BarCode->setObjectName(QString::fromUtf8("spb_TimeOut_BarCode"));
        spb_TimeOut_BarCode->setFont(font4);
        spb_TimeOut_BarCode->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);\n"
"background-color: rgb(30, 50, 77);"));
        spb_TimeOut_BarCode->setMaximum(9999);
        spb_TimeOut_BarCode->setSingleStep(10);
        spb_TimeOut_BarCode->setValue(300);

        horizontalLayout_32->addWidget(spb_TimeOut_BarCode);

        horizontalLayout_32->setStretch(0, 1);
        horizontalLayout_32->setStretch(1, 1);

        verticalLayout_2->addLayout(horizontalLayout_32);

        verticalLayout_2->setStretch(0, 2);
        verticalLayout_2->setStretch(1, 1);
        verticalLayout_2->setStretch(2, 1);
        verticalLayout_2->setStretch(3, 1);
        verticalLayout_2->setStretch(4, 1);

        verticalLayout_4->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        frame_6 = new QFrame(frame_2);
        frame_6->setObjectName(QString::fromUtf8("frame_6"));
        frame_6->setStyleSheet(QString::fromUtf8("background-color: rgb(36, 46, 58);"));
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(frame_6);
        gridLayout_3->setSpacing(1);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(1, 1, 1, 1);
        label_4 = new QLabel(frame_6);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font5);
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        gridLayout_3->addWidget(label_4, 0, 0, 1, 1);


        verticalLayout->addWidget(frame_6);

        groupBox_1D = new QGroupBox(frame_2);
        groupBox_1D->setObjectName(QString::fromUtf8("groupBox_1D"));
        QFont font6;
        font6.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font6.setPointSize(11);
        font6.setBold(true);
        font6.setWeight(75);
        groupBox_1D->setFont(font6);
        groupBox_1D->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        groupBox_1D->setCheckable(true);
        groupBox_1D->setChecked(false);
        gridLayout_2 = new QGridLayout(groupBox_1D);
        gridLayout_2->setSpacing(2);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(2, 10, 2, 2);
        gridLayout_9 = new QGridLayout();
        gridLayout_9->setSpacing(6);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        verticalLayout_14 = new QVBoxLayout();
        verticalLayout_14->setSpacing(6);
        verticalLayout_14->setObjectName(QString::fromUtf8("verticalLayout_14"));
        ckb_CODE128_BarCode = new QCheckBox(groupBox_1D);
        ckb_CODE128_BarCode->setObjectName(QString::fromUtf8("ckb_CODE128_BarCode"));
        QFont font7;
        font7.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font7.setPointSize(9);
        ckb_CODE128_BarCode->setFont(font7);
        ckb_CODE128_BarCode->setChecked(true);

        verticalLayout_14->addWidget(ckb_CODE128_BarCode);

        ckb_EAN13_BarCode = new QCheckBox(groupBox_1D);
        ckb_EAN13_BarCode->setObjectName(QString::fromUtf8("ckb_EAN13_BarCode"));
        ckb_EAN13_BarCode->setFont(font7);
        ckb_EAN13_BarCode->setChecked(false);

        verticalLayout_14->addWidget(ckb_EAN13_BarCode);

        ckb_CODE93_BarCode = new QCheckBox(groupBox_1D);
        ckb_CODE93_BarCode->setObjectName(QString::fromUtf8("ckb_CODE93_BarCode"));
        ckb_CODE93_BarCode->setFont(font7);
        ckb_CODE93_BarCode->setChecked(false);

        verticalLayout_14->addWidget(ckb_CODE93_BarCode);

        ckb_UPCA_BarCode = new QCheckBox(groupBox_1D);
        ckb_UPCA_BarCode->setObjectName(QString::fromUtf8("ckb_UPCA_BarCode"));
        ckb_UPCA_BarCode->setFont(font7);
        ckb_UPCA_BarCode->setChecked(false);

        verticalLayout_14->addWidget(ckb_UPCA_BarCode);

        ckb_CODABAR_BarCode = new QCheckBox(groupBox_1D);
        ckb_CODABAR_BarCode->setObjectName(QString::fromUtf8("ckb_CODABAR_BarCode"));
        ckb_CODABAR_BarCode->setFont(font7);
        ckb_CODABAR_BarCode->setChecked(false);

        verticalLayout_14->addWidget(ckb_CODABAR_BarCode);

        verticalLayout_14->setStretch(0, 1);
        verticalLayout_14->setStretch(1, 1);
        verticalLayout_14->setStretch(2, 1);
        verticalLayout_14->setStretch(3, 1);
        verticalLayout_14->setStretch(4, 1);

        gridLayout_9->addLayout(verticalLayout_14, 0, 0, 1, 1);

        verticalLayout_15 = new QVBoxLayout();
        verticalLayout_15->setSpacing(6);
        verticalLayout_15->setObjectName(QString::fromUtf8("verticalLayout_15"));
        ckb_CODE39_BarCode = new QCheckBox(groupBox_1D);
        ckb_CODE39_BarCode->setObjectName(QString::fromUtf8("ckb_CODE39_BarCode"));
        ckb_CODE39_BarCode->setFont(font7);
        ckb_CODE39_BarCode->setChecked(false);

        verticalLayout_15->addWidget(ckb_CODE39_BarCode);

        ckb_EAN8_BarCode = new QCheckBox(groupBox_1D);
        ckb_EAN8_BarCode->setObjectName(QString::fromUtf8("ckb_EAN8_BarCode"));
        ckb_EAN8_BarCode->setFont(font7);
        ckb_EAN8_BarCode->setChecked(false);

        verticalLayout_15->addWidget(ckb_EAN8_BarCode);

        ckb_ITF25_BarCode = new QCheckBox(groupBox_1D);
        ckb_ITF25_BarCode->setObjectName(QString::fromUtf8("ckb_ITF25_BarCode"));
        ckb_ITF25_BarCode->setFont(font7);
        ckb_ITF25_BarCode->setChecked(false);

        verticalLayout_15->addWidget(ckb_ITF25_BarCode);

        ckb_UPCE_BarCode = new QCheckBox(groupBox_1D);
        ckb_UPCE_BarCode->setObjectName(QString::fromUtf8("ckb_UPCE_BarCode"));
        ckb_UPCE_BarCode->setFont(font7);
        ckb_UPCE_BarCode->setChecked(false);

        verticalLayout_15->addWidget(ckb_UPCE_BarCode);

        ckb_PHARMACODE_BarCode = new QCheckBox(groupBox_1D);
        ckb_PHARMACODE_BarCode->setObjectName(QString::fromUtf8("ckb_PHARMACODE_BarCode"));
        ckb_PHARMACODE_BarCode->setFont(font7);
        ckb_PHARMACODE_BarCode->setChecked(false);

        verticalLayout_15->addWidget(ckb_PHARMACODE_BarCode);

        verticalLayout_15->setStretch(0, 1);
        verticalLayout_15->setStretch(1, 1);
        verticalLayout_15->setStretch(2, 1);
        verticalLayout_15->setStretch(3, 1);
        verticalLayout_15->setStretch(4, 1);

        gridLayout_9->addLayout(verticalLayout_15, 0, 1, 1, 1);

        gridLayout_9->setColumnMinimumWidth(0, 1);
        gridLayout_9->setColumnMinimumWidth(1, 1);

        gridLayout_2->addLayout(gridLayout_9, 0, 0, 1, 1);


        verticalLayout->addWidget(groupBox_1D);

        groupBox_2D = new QGroupBox(frame_2);
        groupBox_2D->setObjectName(QString::fromUtf8("groupBox_2D"));
        groupBox_2D->setFont(font6);
        groupBox_2D->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        groupBox_2D->setCheckable(true);
        groupBox_2D->setChecked(false);
        gridLayout_10 = new QGridLayout(groupBox_2D);
        gridLayout_10->setSpacing(1);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        gridLayout_10->setContentsMargins(1, 10, 1, 1);
        gridLayout_12 = new QGridLayout();
        gridLayout_12->setSpacing(1);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        gridLayout_12->setContentsMargins(1, 1, 1, 1);
        verticalLayout_22 = new QVBoxLayout();
        verticalLayout_22->setSpacing(6);
        verticalLayout_22->setObjectName(QString::fromUtf8("verticalLayout_22"));
        ckb_DM_Code2d = new QCheckBox(groupBox_2D);
        ckb_DM_Code2d->setObjectName(QString::fromUtf8("ckb_DM_Code2d"));
        QFont font8;
        font8.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        ckb_DM_Code2d->setFont(font8);
        ckb_DM_Code2d->setChecked(false);

        verticalLayout_22->addWidget(ckb_DM_Code2d);

        ckb_Aztec_Code2d = new QCheckBox(groupBox_2D);
        ckb_Aztec_Code2d->setObjectName(QString::fromUtf8("ckb_Aztec_Code2d"));
        ckb_Aztec_Code2d->setFont(font8);
        ckb_Aztec_Code2d->setChecked(false);

        verticalLayout_22->addWidget(ckb_Aztec_Code2d);

        ckb_GS1DM_Code2d = new QCheckBox(groupBox_2D);
        ckb_GS1DM_Code2d->setObjectName(QString::fromUtf8("ckb_GS1DM_Code2d"));
        ckb_GS1DM_Code2d->setFont(font8);
        ckb_GS1DM_Code2d->setChecked(false);

        verticalLayout_22->addWidget(ckb_GS1DM_Code2d);

        checkBox = new QCheckBox(groupBox_2D);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setFont(font8);
        checkBox->setStyleSheet(QString::fromUtf8("selection-background-color: rgb(255, 255, 255);"));

        verticalLayout_22->addWidget(checkBox);

        ckb_MicroQR_Code2d = new QCheckBox(groupBox_2D);
        ckb_MicroQR_Code2d->setObjectName(QString::fromUtf8("ckb_MicroQR_Code2d"));
        ckb_MicroQR_Code2d->setFont(font8);
        ckb_MicroQR_Code2d->setChecked(false);

        verticalLayout_22->addWidget(ckb_MicroQR_Code2d);

        verticalLayout_22->setStretch(0, 1);
        verticalLayout_22->setStretch(1, 1);
        verticalLayout_22->setStretch(2, 1);
        verticalLayout_22->setStretch(3, 1);
        verticalLayout_22->setStretch(4, 1);

        gridLayout_12->addLayout(verticalLayout_22, 0, 0, 1, 1);

        verticalLayout_23 = new QVBoxLayout();
        verticalLayout_23->setSpacing(6);
        verticalLayout_23->setObjectName(QString::fromUtf8("verticalLayout_23"));
        ckb_QR_Code2d = new QCheckBox(groupBox_2D);
        ckb_QR_Code2d->setObjectName(QString::fromUtf8("ckb_QR_Code2d"));
        ckb_QR_Code2d->setFont(font8);
        ckb_QR_Code2d->setChecked(true);

        verticalLayout_23->addWidget(ckb_QR_Code2d);

        ckb_GS1Aztec_Code2d = new QCheckBox(groupBox_2D);
        ckb_GS1Aztec_Code2d->setObjectName(QString::fromUtf8("ckb_GS1Aztec_Code2d"));
        ckb_GS1Aztec_Code2d->setFont(font8);
        ckb_GS1Aztec_Code2d->setCheckable(true);
        ckb_GS1Aztec_Code2d->setChecked(false);

        verticalLayout_23->addWidget(ckb_GS1Aztec_Code2d);

        ckb_GS1QR_Code2d = new QCheckBox(groupBox_2D);
        ckb_GS1QR_Code2d->setObjectName(QString::fromUtf8("ckb_GS1QR_Code2d"));
        ckb_GS1QR_Code2d->setFont(font8);
        ckb_GS1QR_Code2d->setChecked(false);

        verticalLayout_23->addWidget(ckb_GS1QR_Code2d);

        ckb_PDF417_Code2d = new QCheckBox(groupBox_2D);
        ckb_PDF417_Code2d->setObjectName(QString::fromUtf8("ckb_PDF417_Code2d"));
        ckb_PDF417_Code2d->setFont(font8);
        ckb_PDF417_Code2d->setChecked(false);

        verticalLayout_23->addWidget(ckb_PDF417_Code2d);

        verticalLayout_23->setStretch(0, 1);
        verticalLayout_23->setStretch(1, 1);
        verticalLayout_23->setStretch(2, 1);
        verticalLayout_23->setStretch(3, 1);

        gridLayout_12->addLayout(verticalLayout_23, 0, 1, 1, 1);

        gridLayout_12->setColumnMinimumWidth(0, 1);
        gridLayout_12->setColumnMinimumWidth(1, 1);

        gridLayout_10->addLayout(gridLayout_12, 0, 0, 1, 1);


        verticalLayout->addWidget(groupBox_2D);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 10);
        verticalLayout->setStretch(2, 10);

        verticalLayout_4->addLayout(verticalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        frame_7 = new QFrame(frame_2);
        frame_7->setObjectName(QString::fromUtf8("frame_7"));
        frame_7->setStyleSheet(QString::fromUtf8("background-color: rgb(36, 46, 58);"));
        frame_7->setFrameShape(QFrame::StyledPanel);
        frame_7->setFrameShadow(QFrame::Raised);
        gridLayout_4 = new QGridLayout(frame_7);
        gridLayout_4->setSpacing(1);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(1, 1, 1, 1);
        label_5 = new QLabel(frame_7);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font5);
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        gridLayout_4->addWidget(label_5, 0, 0, 1, 1);


        verticalLayout_3->addWidget(frame_7);

        verticalLayout_17 = new QVBoxLayout();
        verticalLayout_17->setSpacing(6);
        verticalLayout_17->setObjectName(QString::fromUtf8("verticalLayout_17"));
        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setSpacing(6);
        horizontalLayout_21->setObjectName(QString::fromUtf8("horizontalLayout_21"));
        label_59 = new QLabel(frame_2);
        label_59->setObjectName(QString::fromUtf8("label_59"));
        label_59->setFont(font4);
        label_59->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        horizontalLayout_21->addWidget(label_59);

        txt_HeadChar_BarCode = new QLineEdit(frame_2);
        txt_HeadChar_BarCode->setObjectName(QString::fromUtf8("txt_HeadChar_BarCode"));
        txt_HeadChar_BarCode->setFont(font4);
        txt_HeadChar_BarCode->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        horizontalLayout_21->addWidget(txt_HeadChar_BarCode);


        verticalLayout_17->addLayout(horizontalLayout_21);

        horizontalLayout_26 = new QHBoxLayout();
        horizontalLayout_26->setSpacing(6);
        horizontalLayout_26->setObjectName(QString::fromUtf8("horizontalLayout_26"));
        label_60 = new QLabel(frame_2);
        label_60->setObjectName(QString::fromUtf8("label_60"));
        label_60->setFont(font4);
        label_60->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        horizontalLayout_26->addWidget(label_60);

        txt_EndChar_BarCode = new QLineEdit(frame_2);
        txt_EndChar_BarCode->setObjectName(QString::fromUtf8("txt_EndChar_BarCode"));
        txt_EndChar_BarCode->setFont(font4);
        txt_EndChar_BarCode->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        horizontalLayout_26->addWidget(txt_EndChar_BarCode);


        verticalLayout_17->addLayout(horizontalLayout_26);

        horizontalLayout_27 = new QHBoxLayout();
        horizontalLayout_27->setSpacing(6);
        horizontalLayout_27->setObjectName(QString::fromUtf8("horizontalLayout_27"));
        label_61 = new QLabel(frame_2);
        label_61->setObjectName(QString::fromUtf8("label_61"));
        label_61->setFont(font4);
        label_61->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        horizontalLayout_27->addWidget(label_61);

        txt_ContainChar_BarCode = new QLineEdit(frame_2);
        txt_ContainChar_BarCode->setObjectName(QString::fromUtf8("txt_ContainChar_BarCode"));
        txt_ContainChar_BarCode->setFont(font4);
        txt_ContainChar_BarCode->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        horizontalLayout_27->addWidget(txt_ContainChar_BarCode);


        verticalLayout_17->addLayout(horizontalLayout_27);

        horizontalLayout_29 = new QHBoxLayout();
        horizontalLayout_29->setSpacing(6);
        horizontalLayout_29->setObjectName(QString::fromUtf8("horizontalLayout_29"));
        label_62 = new QLabel(frame_2);
        label_62->setObjectName(QString::fromUtf8("label_62"));
        label_62->setFont(font4);
        label_62->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        horizontalLayout_29->addWidget(label_62);

        txt_NotContainChar_BarCode = new QLineEdit(frame_2);
        txt_NotContainChar_BarCode->setObjectName(QString::fromUtf8("txt_NotContainChar_BarCode"));
        txt_NotContainChar_BarCode->setFont(font4);
        txt_NotContainChar_BarCode->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        horizontalLayout_29->addWidget(txt_NotContainChar_BarCode);


        verticalLayout_17->addLayout(horizontalLayout_29);

        horizontalLayout_30 = new QHBoxLayout();
        horizontalLayout_30->setSpacing(6);
        horizontalLayout_30->setObjectName(QString::fromUtf8("horizontalLayout_30"));
        label_63 = new QLabel(frame_2);
        label_63->setObjectName(QString::fromUtf8("label_63"));
        label_63->setFont(font4);
        label_63->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        horizontalLayout_30->addWidget(label_63);

        txt_CodeLength_BarCode = new QLineEdit(frame_2);
        txt_CodeLength_BarCode->setObjectName(QString::fromUtf8("txt_CodeLength_BarCode"));
        txt_CodeLength_BarCode->setFont(font4);
        txt_CodeLength_BarCode->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        horizontalLayout_30->addWidget(txt_CodeLength_BarCode);


        verticalLayout_17->addLayout(horizontalLayout_30);

        verticalLayout_17->setStretch(0, 1);
        verticalLayout_17->setStretch(1, 1);
        verticalLayout_17->setStretch(2, 1);
        verticalLayout_17->setStretch(3, 1);
        verticalLayout_17->setStretch(4, 1);

        verticalLayout_3->addLayout(verticalLayout_17);

        verticalLayout_3->setStretch(0, 1);
        verticalLayout_3->setStretch(1, 10);

        verticalLayout_4->addLayout(verticalLayout_3);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        btn_FindBarCode = new QPushButton(frame_2);
        btn_FindBarCode->setObjectName(QString::fromUtf8("btn_FindBarCode"));
        QFont font9;
        font9.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font9.setPointSize(12);
        font9.setBold(true);
        font9.setWeight(75);
        btn_FindBarCode->setFont(font9);
        btn_FindBarCode->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);\n"
"background-color: rgb(3, 184, 2);"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8("../../../MatchTest/Resources/\350\277\220\350\241\214.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_FindBarCode->setIcon(icon5);
        btn_FindBarCode->setIconSize(QSize(25, 25));

        horizontalLayout_6->addWidget(btn_FindBarCode);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_16);

        pushButton_save = new QPushButton(frame_2);
        pushButton_save->setObjectName(QString::fromUtf8("pushButton_save"));
        pushButton_save->setFont(font9);
        pushButton_save->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);\n"
"background-color: rgb(21, 155, 211);"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8("../../../MatchTest/Resources/\345\257\274\345\205\245 (2).png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_save->setIcon(icon6);
        pushButton_save->setIconSize(QSize(25, 25));

        horizontalLayout_6->addWidget(pushButton_save);

        horizontalLayout_6->setStretch(0, 3);
        horizontalLayout_6->setStretch(1, 1);
        horizontalLayout_6->setStretch(2, 3);

        verticalLayout_4->addLayout(horizontalLayout_6);

        verticalLayout_4->setStretch(0, 5);
        verticalLayout_4->setStretch(1, 10);
        verticalLayout_4->setStretch(2, 5);
        verticalLayout_4->setStretch(3, 1);

        gridLayout_8->addLayout(verticalLayout_4, 0, 0, 1, 1);


        gridLayout_5->addWidget(frame_2, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayout_6 = new QGridLayout(tab_2);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        frame_3 = new QFrame(tab_2);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        gridLayout_7 = new QGridLayout(frame_3);
        gridLayout_7->setSpacing(2);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setContentsMargins(2, 2, 2, 2);
        tablewidget_Results_BarCode = new QTableWidget(frame_3);
        tablewidget_Results_BarCode->setObjectName(QString::fromUtf8("tablewidget_Results_BarCode"));

        gridLayout_7->addWidget(tablewidget_Results_BarCode, 0, 0, 1, 1);


        gridLayout_6->addWidget(frame_3, 0, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());

        horizontalLayout->addWidget(tabWidget);

        horizontalLayout->setStretch(0, 3);
        horizontalLayout->setStretch(1, 1);

        verticalLayout_5->addLayout(horizontalLayout);

        verticalLayout_5->setStretch(0, 1);
        verticalLayout_5->setStretch(1, 20);

        gridLayout_14->addLayout(verticalLayout_5, 0, 0, 1, 1);


        gridLayout_11->addWidget(frame_5, 0, 0, 1, 1);

        BarcodeClassClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(BarcodeClassClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        BarcodeClassClass->setStatusBar(statusBar);

        retranslateUi(BarcodeClassClass);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(BarcodeClassClass);
    } // setupUi

    void retranslateUi(QMainWindow *BarcodeClassClass)
    {
        BarcodeClassClass->setWindowTitle(QApplication::translate("BarcodeClassClass", "BarcodeClass", nullptr));
        label_10->setText(QString());
        toolButton_4->setText(QApplication::translate("BarcodeClassClass", "\350\256\276\347\275\256", nullptr));
        toolButton_5->setText(QApplication::translate("BarcodeClassClass", "\346\227\245\345\277\227", nullptr));
        toolButton_6->setText(QApplication::translate("BarcodeClassClass", "\350\257\255\350\250\200", nullptr));
        toolButton_7->setText(QApplication::translate("BarcodeClassClass", "\345\270\256\345\212\251", nullptr));
        label_title->setText(QString());
        toolButton->setText(QString());
        toolButton_2->setText(QString());
        toolButton_3->setText(QString());
        label_image->setText(QString());
        label_12->setText(QApplication::translate("BarcodeClassClass", "\350\276\223\345\205\245\346\272\220\357\274\232", nullptr));
        label_3->setText(QApplication::translate("BarcodeClassClass", "\346\220\234\347\264\242\345\214\272\345\237\237\357\274\232", nullptr));
        btn_DrawRoi_BarCode->setText(QString());
        btn_ClearRoi_BarCode->setText(QString());
        label_21->setText(QApplication::translate("BarcodeClassClass", "\346\235\241\347\240\201\344\270\252\346\225\260\357\274\232", nullptr));
        label_11->setText(QApplication::translate("BarcodeClassClass", "\350\247\243\347\240\201\346\250\241\345\274\217", nullptr));
        cmb_Tolerance_BarCode->setItemText(0, QApplication::translate("BarcodeClassClass", "\346\240\207\345\207\206", nullptr));
        cmb_Tolerance_BarCode->setItemText(1, QApplication::translate("BarcodeClassClass", "\345\242\236\345\274\272", nullptr));

        label_28->setText(QApplication::translate("BarcodeClassClass", "\347\256\227\346\263\225\350\266\205\346\227\266\357\274\232", nullptr));
        label_4->setText(QApplication::translate("BarcodeClassClass", "\350\257\206\345\210\253\345\217\202\346\225\260\357\274\232", nullptr));
        groupBox_1D->setTitle(QApplication::translate("BarcodeClassClass", "\344\270\200\347\273\264\347\240\201\347\261\273\345\236\213", nullptr));
        ckb_CODE128_BarCode->setText(QApplication::translate("BarcodeClassClass", "CODE128", nullptr));
        ckb_EAN13_BarCode->setText(QApplication::translate("BarcodeClassClass", "EAN13", nullptr));
        ckb_CODE93_BarCode->setText(QApplication::translate("BarcodeClassClass", "CODE93", nullptr));
        ckb_UPCA_BarCode->setText(QApplication::translate("BarcodeClassClass", "UPCA", nullptr));
        ckb_CODABAR_BarCode->setText(QApplication::translate("BarcodeClassClass", "CODABAR", nullptr));
        ckb_CODE39_BarCode->setText(QApplication::translate("BarcodeClassClass", "CODE39", nullptr));
        ckb_EAN8_BarCode->setText(QApplication::translate("BarcodeClassClass", "EAN8", nullptr));
        ckb_ITF25_BarCode->setText(QApplication::translate("BarcodeClassClass", "ITF25", nullptr));
        ckb_UPCE_BarCode->setText(QApplication::translate("BarcodeClassClass", "UPCE", nullptr));
        ckb_PHARMACODE_BarCode->setText(QApplication::translate("BarcodeClassClass", "PHARMACODE", nullptr));
        groupBox_2D->setTitle(QApplication::translate("BarcodeClassClass", "\344\272\214\347\273\264\347\240\201\347\261\273\345\236\213", nullptr));
        ckb_DM_Code2d->setText(QApplication::translate("BarcodeClassClass", "DM", nullptr));
        ckb_Aztec_Code2d->setText(QApplication::translate("BarcodeClassClass", "Aztec", nullptr));
        ckb_GS1DM_Code2d->setText(QApplication::translate("BarcodeClassClass", "GS1DM", nullptr));
        checkBox->setText(QApplication::translate("BarcodeClassClass", "CheckBox", nullptr));
        ckb_MicroQR_Code2d->setText(QApplication::translate("BarcodeClassClass", "MicroQR", nullptr));
        ckb_QR_Code2d->setText(QApplication::translate("BarcodeClassClass", "QR", nullptr));
        ckb_GS1Aztec_Code2d->setText(QApplication::translate("BarcodeClassClass", "GS1Aztec", nullptr));
        ckb_GS1QR_Code2d->setText(QApplication::translate("BarcodeClassClass", "GS1QR", nullptr));
        ckb_PDF417_Code2d->setText(QApplication::translate("BarcodeClassClass", "PDF417", nullptr));
        label_5->setText(QApplication::translate("BarcodeClassClass", "\346\235\241\347\240\201\350\277\207\346\273\244\357\274\232", nullptr));
        label_59->setText(QApplication::translate("BarcodeClassClass", "\347\211\271\345\256\232\345\255\227\347\254\246\345\274\200\345\244\264\357\274\232", nullptr));
        label_60->setText(QApplication::translate("BarcodeClassClass", "\347\211\271\345\256\232\345\255\227\347\254\246\347\273\223\345\260\276\357\274\232", nullptr));
        label_61->setText(QApplication::translate("BarcodeClassClass", "\345\214\205\345\220\253\347\211\271\345\256\232\345\255\227\347\254\246\357\274\232", nullptr));
        label_62->setText(QApplication::translate("BarcodeClassClass", "\344\270\215\345\214\205\345\220\253\347\211\271\345\256\232\345\255\227\347\254\246\357\274\232", nullptr));
        label_63->setText(QApplication::translate("BarcodeClassClass", "\346\235\241\347\240\201\346\234\200\345\260\217\351\225\277\345\272\246\357\274\232", nullptr));
        btn_FindBarCode->setText(QApplication::translate("BarcodeClassClass", "\346\265\213\350\257\225\350\277\220\350\241\214", nullptr));
        pushButton_save->setText(QApplication::translate("BarcodeClassClass", "\344\277\235\345\255\230", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("BarcodeClassClass", "\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("BarcodeClassClass", "\350\257\206\345\210\253\347\273\223\346\236\234", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BarcodeClassClass: public Ui_BarcodeClassClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BARCODECLASS_H
