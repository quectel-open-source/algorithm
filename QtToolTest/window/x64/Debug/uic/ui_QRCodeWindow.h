/********************************************************************************
** Form generated from reading UI file 'QRCodeWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QRCODEWINDOW_H
#define UI_QRCODEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "cmylabel.h"

QT_BEGIN_NAMESPACE

class Ui_Code2dWindowClass
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox;
    CMyLabel *lbl_Window;
    QPushButton *pBtn_ReadImage;
    QPushButton *pBtn_FitImage;
    QLabel *lbl_Status;
    QPushButton *btn_ClearWindow;
    QCheckBox *ckb_ShowObj;
    QPushButton *btn_Hide;
    QTabWidget *tabWidget_5;
    QWidget *tab_17;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_11;
    QVBoxLayout *verticalLayout_16;
    QPushButton *btn_DrawRoi_Code2d;
    QPushButton *btn_ClearRoi_Code2d;
    QHBoxLayout *horizontalLayout_29;
    QLabel *label_58;
    QSpinBox *spb_CodeNum_Code2d;
    QHBoxLayout *horizontalLayout_33;
    QLabel *label_65;
    QHBoxLayout *horizontalLayout_32;
    QSpinBox *spb_TimeOut_Code2d;
    QLabel *label_66;
    QHBoxLayout *horizontalLayout_18;
    QLabel *label_64;
    QComboBox *cmb_Tolerance_Code2d;
    QSpacerItem *verticalSpacer_8;
    QHBoxLayout *horizontalLayout_30;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_9;
    QGridLayout *gridLayout_10;
    QVBoxLayout *verticalLayout_22;
    QCheckBox *ckb_DM_Code2d;
    QCheckBox *ckb_Aztec_Code2d;
    QCheckBox *ckb_GS1DM_Code2d;
    QCheckBox *ckb_MicroQR_Code2d;
    QVBoxLayout *verticalLayout_23;
    QCheckBox *ckb_QR_Code2d;
    QCheckBox *ckb_GS1Aztec_Code2d;
    QCheckBox *ckb_GS1QR_Code2d;
    QCheckBox *ckb_PDF417_Code2d;
    QWidget *tab_18;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_59;
    QVBoxLayout *verticalLayout_17;
    QHBoxLayout *horizontalLayout_19;
    QLabel *label_59;
    QLineEdit *txt_HeadChar_Code2d;
    QHBoxLayout *horizontalLayout_20;
    QLabel *label_60;
    QLineEdit *txt_EndChar_Code2d;
    QHBoxLayout *horizontalLayout_21;
    QLabel *label_61;
    QLineEdit *txt_ContainChar_Code2d;
    QHBoxLayout *horizontalLayout_22;
    QLabel *label_62;
    QLineEdit *txt_NotContainChar_Code2d;
    QHBoxLayout *horizontalLayout_23;
    QLabel *label_63;
    QSpinBox *spb_CodeLength_Code2d;
    QSpacerItem *verticalSpacer_9;
    QHBoxLayout *horizontalLayout_165;
    QHBoxLayout *horizontalLayout_28;
    QVBoxLayout *verticalLayout_24;
    QPushButton *btn_LoadCode2dData;
    QPushButton *btn_SaveCode2dData;
    QVBoxLayout *verticalLayout_25;
    QHBoxLayout *horizontalLayout_31;
    QPushButton *btn_FindCode2d;
    QLabel *lbl_CT_Code2d;
    QWidget *tab_19;
    QTableWidget *tablewidget_Results_Code2d;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Code2dWindowClass)
    {
        if (Code2dWindowClass->objectName().isEmpty())
            Code2dWindowClass->setObjectName(QString::fromUtf8("Code2dWindowClass"));
        Code2dWindowClass->resize(1200, 872);
        centralWidget = new QWidget(Code2dWindowClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 591, 751));
        lbl_Window = new CMyLabel(groupBox);
        lbl_Window->setObjectName(QString::fromUtf8("lbl_Window"));
        lbl_Window->setGeometry(QRect(10, 20, 571, 501));
        lbl_Window->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        pBtn_ReadImage = new QPushButton(groupBox);
        pBtn_ReadImage->setObjectName(QString::fromUtf8("pBtn_ReadImage"));
        pBtn_ReadImage->setGeometry(QRect(10, 650, 111, 91));
        pBtn_FitImage = new QPushButton(groupBox);
        pBtn_FitImage->setObjectName(QString::fromUtf8("pBtn_FitImage"));
        pBtn_FitImage->setGeometry(QRect(140, 650, 111, 91));
        lbl_Status = new QLabel(groupBox);
        lbl_Status->setObjectName(QString::fromUtf8("lbl_Status"));
        lbl_Status->setGeometry(QRect(20, 550, 561, 18));
        btn_ClearWindow = new QPushButton(groupBox);
        btn_ClearWindow->setObjectName(QString::fromUtf8("btn_ClearWindow"));
        btn_ClearWindow->setGeometry(QRect(270, 650, 111, 91));
        ckb_ShowObj = new QCheckBox(groupBox);
        ckb_ShowObj->setObjectName(QString::fromUtf8("ckb_ShowObj"));
        ckb_ShowObj->setGeometry(QRect(20, 600, 131, 31));
        ckb_ShowObj->setChecked(true);
        btn_Hide = new QPushButton(groupBox);
        btn_Hide->setObjectName(QString::fromUtf8("btn_Hide"));
        btn_Hide->setGeometry(QRect(410, 650, 111, 91));
        tabWidget_5 = new QTabWidget(centralWidget);
        tabWidget_5->setObjectName(QString::fromUtf8("tabWidget_5"));
        tabWidget_5->setGeometry(QRect(610, 10, 561, 751));
        tab_17 = new QWidget();
        tab_17->setObjectName(QString::fromUtf8("tab_17"));
        layoutWidget = new QWidget(tab_17);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 28, 521, 681));
        gridLayout_11 = new QGridLayout(layoutWidget);
        gridLayout_11->setSpacing(6);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        gridLayout_11->setContentsMargins(0, 0, 0, 0);
        verticalLayout_16 = new QVBoxLayout();
        verticalLayout_16->setSpacing(6);
        verticalLayout_16->setObjectName(QString::fromUtf8("verticalLayout_16"));
        btn_DrawRoi_Code2d = new QPushButton(layoutWidget);
        btn_DrawRoi_Code2d->setObjectName(QString::fromUtf8("btn_DrawRoi_Code2d"));

        verticalLayout_16->addWidget(btn_DrawRoi_Code2d);

        btn_ClearRoi_Code2d = new QPushButton(layoutWidget);
        btn_ClearRoi_Code2d->setObjectName(QString::fromUtf8("btn_ClearRoi_Code2d"));

        verticalLayout_16->addWidget(btn_ClearRoi_Code2d);

        horizontalLayout_29 = new QHBoxLayout();
        horizontalLayout_29->setSpacing(6);
        horizontalLayout_29->setObjectName(QString::fromUtf8("horizontalLayout_29"));
        label_58 = new QLabel(layoutWidget);
        label_58->setObjectName(QString::fromUtf8("label_58"));

        horizontalLayout_29->addWidget(label_58);

        spb_CodeNum_Code2d = new QSpinBox(layoutWidget);
        spb_CodeNum_Code2d->setObjectName(QString::fromUtf8("spb_CodeNum_Code2d"));
        spb_CodeNum_Code2d->setMaximum(9999);
        spb_CodeNum_Code2d->setValue(1);

        horizontalLayout_29->addWidget(spb_CodeNum_Code2d);


        verticalLayout_16->addLayout(horizontalLayout_29);

        horizontalLayout_33 = new QHBoxLayout();
        horizontalLayout_33->setSpacing(6);
        horizontalLayout_33->setObjectName(QString::fromUtf8("horizontalLayout_33"));
        label_65 = new QLabel(layoutWidget);
        label_65->setObjectName(QString::fromUtf8("label_65"));

        horizontalLayout_33->addWidget(label_65);

        horizontalLayout_32 = new QHBoxLayout();
        horizontalLayout_32->setSpacing(6);
        horizontalLayout_32->setObjectName(QString::fromUtf8("horizontalLayout_32"));
        spb_TimeOut_Code2d = new QSpinBox(layoutWidget);
        spb_TimeOut_Code2d->setObjectName(QString::fromUtf8("spb_TimeOut_Code2d"));
        spb_TimeOut_Code2d->setMaximum(99999);
        spb_TimeOut_Code2d->setValue(100);

        horizontalLayout_32->addWidget(spb_TimeOut_Code2d);

        label_66 = new QLabel(layoutWidget);
        label_66->setObjectName(QString::fromUtf8("label_66"));

        horizontalLayout_32->addWidget(label_66);


        horizontalLayout_33->addLayout(horizontalLayout_32);


        verticalLayout_16->addLayout(horizontalLayout_33);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setSpacing(6);
        horizontalLayout_18->setObjectName(QString::fromUtf8("horizontalLayout_18"));
        label_64 = new QLabel(layoutWidget);
        label_64->setObjectName(QString::fromUtf8("label_64"));

        horizontalLayout_18->addWidget(label_64);

        cmb_Tolerance_Code2d = new QComboBox(layoutWidget);
        cmb_Tolerance_Code2d->addItem(QString());
        cmb_Tolerance_Code2d->addItem(QString());
        cmb_Tolerance_Code2d->setObjectName(QString::fromUtf8("cmb_Tolerance_Code2d"));

        horizontalLayout_18->addWidget(cmb_Tolerance_Code2d);


        verticalLayout_16->addLayout(horizontalLayout_18);


        gridLayout_11->addLayout(verticalLayout_16, 0, 0, 1, 1);

        verticalSpacer_8 = new QSpacerItem(20, 268, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_11->addItem(verticalSpacer_8, 1, 0, 1, 1);

        horizontalLayout_30 = new QHBoxLayout();
        horizontalLayout_30->setSpacing(6);
        horizontalLayout_30->setObjectName(QString::fromUtf8("horizontalLayout_30"));
        groupBox_4 = new QGroupBox(layoutWidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        gridLayout_9 = new QGridLayout(groupBox_4);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        gridLayout_10 = new QGridLayout();
        gridLayout_10->setSpacing(6);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        verticalLayout_22 = new QVBoxLayout();
        verticalLayout_22->setSpacing(6);
        verticalLayout_22->setObjectName(QString::fromUtf8("verticalLayout_22"));
        ckb_DM_Code2d = new QCheckBox(groupBox_4);
        ckb_DM_Code2d->setObjectName(QString::fromUtf8("ckb_DM_Code2d"));
        ckb_DM_Code2d->setChecked(false);

        verticalLayout_22->addWidget(ckb_DM_Code2d);

        ckb_Aztec_Code2d = new QCheckBox(groupBox_4);
        ckb_Aztec_Code2d->setObjectName(QString::fromUtf8("ckb_Aztec_Code2d"));
        ckb_Aztec_Code2d->setChecked(false);

        verticalLayout_22->addWidget(ckb_Aztec_Code2d);

        ckb_GS1DM_Code2d = new QCheckBox(groupBox_4);
        ckb_GS1DM_Code2d->setObjectName(QString::fromUtf8("ckb_GS1DM_Code2d"));
        ckb_GS1DM_Code2d->setChecked(false);

        verticalLayout_22->addWidget(ckb_GS1DM_Code2d);

        ckb_MicroQR_Code2d = new QCheckBox(groupBox_4);
        ckb_MicroQR_Code2d->setObjectName(QString::fromUtf8("ckb_MicroQR_Code2d"));
        ckb_MicroQR_Code2d->setChecked(false);

        verticalLayout_22->addWidget(ckb_MicroQR_Code2d);


        gridLayout_10->addLayout(verticalLayout_22, 0, 0, 1, 1);

        verticalLayout_23 = new QVBoxLayout();
        verticalLayout_23->setSpacing(6);
        verticalLayout_23->setObjectName(QString::fromUtf8("verticalLayout_23"));
        ckb_QR_Code2d = new QCheckBox(groupBox_4);
        ckb_QR_Code2d->setObjectName(QString::fromUtf8("ckb_QR_Code2d"));
        ckb_QR_Code2d->setChecked(true);

        verticalLayout_23->addWidget(ckb_QR_Code2d);

        ckb_GS1Aztec_Code2d = new QCheckBox(groupBox_4);
        ckb_GS1Aztec_Code2d->setObjectName(QString::fromUtf8("ckb_GS1Aztec_Code2d"));
        ckb_GS1Aztec_Code2d->setChecked(false);

        verticalLayout_23->addWidget(ckb_GS1Aztec_Code2d);

        ckb_GS1QR_Code2d = new QCheckBox(groupBox_4);
        ckb_GS1QR_Code2d->setObjectName(QString::fromUtf8("ckb_GS1QR_Code2d"));
        ckb_GS1QR_Code2d->setChecked(false);

        verticalLayout_23->addWidget(ckb_GS1QR_Code2d);

        ckb_PDF417_Code2d = new QCheckBox(groupBox_4);
        ckb_PDF417_Code2d->setObjectName(QString::fromUtf8("ckb_PDF417_Code2d"));
        ckb_PDF417_Code2d->setChecked(false);

        verticalLayout_23->addWidget(ckb_PDF417_Code2d);


        gridLayout_10->addLayout(verticalLayout_23, 0, 1, 1, 1);


        gridLayout_9->addLayout(gridLayout_10, 0, 0, 1, 1);


        horizontalLayout_30->addWidget(groupBox_4);


        gridLayout_11->addLayout(horizontalLayout_30, 2, 0, 1, 1);

        tabWidget_5->addTab(tab_17, QString());
        tab_18 = new QWidget();
        tab_18->setObjectName(QString::fromUtf8("tab_18"));
        layoutWidget_2 = new QWidget(tab_18);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(20, 20, 521, 681));
        verticalLayout_59 = new QVBoxLayout(layoutWidget_2);
        verticalLayout_59->setSpacing(6);
        verticalLayout_59->setContentsMargins(11, 11, 11, 11);
        verticalLayout_59->setObjectName(QString::fromUtf8("verticalLayout_59"));
        verticalLayout_59->setContentsMargins(0, 0, 0, 0);
        verticalLayout_17 = new QVBoxLayout();
        verticalLayout_17->setSpacing(6);
        verticalLayout_17->setObjectName(QString::fromUtf8("verticalLayout_17"));
        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setSpacing(6);
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));
        label_59 = new QLabel(layoutWidget_2);
        label_59->setObjectName(QString::fromUtf8("label_59"));

        horizontalLayout_19->addWidget(label_59);

        txt_HeadChar_Code2d = new QLineEdit(layoutWidget_2);
        txt_HeadChar_Code2d->setObjectName(QString::fromUtf8("txt_HeadChar_Code2d"));

        horizontalLayout_19->addWidget(txt_HeadChar_Code2d);


        verticalLayout_17->addLayout(horizontalLayout_19);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setSpacing(6);
        horizontalLayout_20->setObjectName(QString::fromUtf8("horizontalLayout_20"));
        label_60 = new QLabel(layoutWidget_2);
        label_60->setObjectName(QString::fromUtf8("label_60"));

        horizontalLayout_20->addWidget(label_60);

        txt_EndChar_Code2d = new QLineEdit(layoutWidget_2);
        txt_EndChar_Code2d->setObjectName(QString::fromUtf8("txt_EndChar_Code2d"));

        horizontalLayout_20->addWidget(txt_EndChar_Code2d);


        verticalLayout_17->addLayout(horizontalLayout_20);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setSpacing(6);
        horizontalLayout_21->setObjectName(QString::fromUtf8("horizontalLayout_21"));
        label_61 = new QLabel(layoutWidget_2);
        label_61->setObjectName(QString::fromUtf8("label_61"));

        horizontalLayout_21->addWidget(label_61);

        txt_ContainChar_Code2d = new QLineEdit(layoutWidget_2);
        txt_ContainChar_Code2d->setObjectName(QString::fromUtf8("txt_ContainChar_Code2d"));

        horizontalLayout_21->addWidget(txt_ContainChar_Code2d);


        verticalLayout_17->addLayout(horizontalLayout_21);

        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setSpacing(6);
        horizontalLayout_22->setObjectName(QString::fromUtf8("horizontalLayout_22"));
        label_62 = new QLabel(layoutWidget_2);
        label_62->setObjectName(QString::fromUtf8("label_62"));

        horizontalLayout_22->addWidget(label_62);

        txt_NotContainChar_Code2d = new QLineEdit(layoutWidget_2);
        txt_NotContainChar_Code2d->setObjectName(QString::fromUtf8("txt_NotContainChar_Code2d"));

        horizontalLayout_22->addWidget(txt_NotContainChar_Code2d);


        verticalLayout_17->addLayout(horizontalLayout_22);

        horizontalLayout_23 = new QHBoxLayout();
        horizontalLayout_23->setSpacing(6);
        horizontalLayout_23->setObjectName(QString::fromUtf8("horizontalLayout_23"));
        label_63 = new QLabel(layoutWidget_2);
        label_63->setObjectName(QString::fromUtf8("label_63"));

        horizontalLayout_23->addWidget(label_63);

        spb_CodeLength_Code2d = new QSpinBox(layoutWidget_2);
        spb_CodeLength_Code2d->setObjectName(QString::fromUtf8("spb_CodeLength_Code2d"));
        spb_CodeLength_Code2d->setMinimum(2);
        spb_CodeLength_Code2d->setMaximum(999);

        horizontalLayout_23->addWidget(spb_CodeLength_Code2d);


        verticalLayout_17->addLayout(horizontalLayout_23);


        verticalLayout_59->addLayout(verticalLayout_17);

        verticalSpacer_9 = new QSpacerItem(20, 198, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_59->addItem(verticalSpacer_9);

        horizontalLayout_165 = new QHBoxLayout();
        horizontalLayout_165->setSpacing(6);
        horizontalLayout_165->setObjectName(QString::fromUtf8("horizontalLayout_165"));
        horizontalLayout_28 = new QHBoxLayout();
        horizontalLayout_28->setSpacing(6);
        horizontalLayout_28->setObjectName(QString::fromUtf8("horizontalLayout_28"));
        verticalLayout_24 = new QVBoxLayout();
        verticalLayout_24->setSpacing(6);
        verticalLayout_24->setObjectName(QString::fromUtf8("verticalLayout_24"));
        btn_LoadCode2dData = new QPushButton(layoutWidget_2);
        btn_LoadCode2dData->setObjectName(QString::fromUtf8("btn_LoadCode2dData"));

        verticalLayout_24->addWidget(btn_LoadCode2dData);

        btn_SaveCode2dData = new QPushButton(layoutWidget_2);
        btn_SaveCode2dData->setObjectName(QString::fromUtf8("btn_SaveCode2dData"));

        verticalLayout_24->addWidget(btn_SaveCode2dData);


        horizontalLayout_28->addLayout(verticalLayout_24);


        horizontalLayout_165->addLayout(horizontalLayout_28);

        verticalLayout_25 = new QVBoxLayout();
        verticalLayout_25->setSpacing(6);
        verticalLayout_25->setObjectName(QString::fromUtf8("verticalLayout_25"));
        horizontalLayout_31 = new QHBoxLayout();
        horizontalLayout_31->setSpacing(6);
        horizontalLayout_31->setObjectName(QString::fromUtf8("horizontalLayout_31"));
        btn_FindCode2d = new QPushButton(layoutWidget_2);
        btn_FindCode2d->setObjectName(QString::fromUtf8("btn_FindCode2d"));

        horizontalLayout_31->addWidget(btn_FindCode2d);

        lbl_CT_Code2d = new QLabel(layoutWidget_2);
        lbl_CT_Code2d->setObjectName(QString::fromUtf8("lbl_CT_Code2d"));

        horizontalLayout_31->addWidget(lbl_CT_Code2d);


        verticalLayout_25->addLayout(horizontalLayout_31);


        horizontalLayout_165->addLayout(verticalLayout_25);


        verticalLayout_59->addLayout(horizontalLayout_165);

        tabWidget_5->addTab(tab_18, QString());
        tab_19 = new QWidget();
        tab_19->setObjectName(QString::fromUtf8("tab_19"));
        tablewidget_Results_Code2d = new QTableWidget(tab_19);
        tablewidget_Results_Code2d->setObjectName(QString::fromUtf8("tablewidget_Results_Code2d"));
        tablewidget_Results_Code2d->setGeometry(QRect(20, 20, 521, 691));
        tabWidget_5->addTab(tab_19, QString());
        Code2dWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Code2dWindowClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1200, 23));
        Code2dWindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Code2dWindowClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Code2dWindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Code2dWindowClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Code2dWindowClass->setStatusBar(statusBar);

        retranslateUi(Code2dWindowClass);

        tabWidget_5->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Code2dWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *Code2dWindowClass)
    {
        Code2dWindowClass->setWindowTitle(QApplication::translate("Code2dWindowClass", "Code2dWindow", nullptr));
        groupBox->setTitle(QApplication::translate("Code2dWindowClass", "\346\230\276\347\244\272\347\252\227\345\217\243", nullptr));
        lbl_Window->setText(QString());
        pBtn_ReadImage->setText(QApplication::translate("Code2dWindowClass", "\346\211\223\345\274\200\345\233\276\347\211\207", nullptr));
        pBtn_FitImage->setText(QApplication::translate("Code2dWindowClass", "\350\207\252\351\200\202\345\272\224", nullptr));
        lbl_Status->setText(QApplication::translate("Code2dWindowClass", "\345\235\220\346\240\207\347\201\260\345\272\246\344\277\241\346\201\257", nullptr));
        btn_ClearWindow->setText(QApplication::translate("Code2dWindowClass", "\346\270\205\347\251\272\347\252\227\345\217\243", nullptr));
        ckb_ShowObj->setText(QApplication::translate("Code2dWindowClass", "\347\274\251\346\224\276\346\227\266\346\230\276\347\244\272\345\233\276\345\275\242", nullptr));
        btn_Hide->setText(QApplication::translate("Code2dWindowClass", "\345\205\263\351\227\255", nullptr));
        btn_DrawRoi_Code2d->setText(QApplication::translate("Code2dWindowClass", "\347\273\230\345\210\266\350\257\206\345\210\253\345\214\272\345\237\237(\344\270\215\347\273\230\345\210\266\351\273\230\350\256\244\345\205\250\345\233\276\346\220\234\347\264\242)", nullptr));
        btn_ClearRoi_Code2d->setText(QApplication::translate("Code2dWindowClass", "\346\270\205\347\251\272ROI", nullptr));
        label_58->setText(QApplication::translate("Code2dWindowClass", "\344\272\214\347\273\264\347\240\201\344\270\252\346\225\260\357\274\232", nullptr));
        label_65->setText(QApplication::translate("Code2dWindowClass", "\350\266\205\346\227\266\346\227\266\351\227\264\357\274\232", nullptr));
        label_66->setText(QApplication::translate("Code2dWindowClass", "ms", nullptr));
        label_64->setText(QApplication::translate("Code2dWindowClass", "\350\247\243\347\240\201\346\250\241\345\274\217\357\274\232", nullptr));
        cmb_Tolerance_Code2d->setItemText(0, QApplication::translate("Code2dWindowClass", "\346\240\207\345\207\206", nullptr));
        cmb_Tolerance_Code2d->setItemText(1, QApplication::translate("Code2dWindowClass", "\345\242\236\345\274\272", nullptr));

        groupBox_4->setTitle(QApplication::translate("Code2dWindowClass", "\344\272\214\347\273\264\347\240\201\347\261\273\345\236\213", nullptr));
        ckb_DM_Code2d->setText(QApplication::translate("Code2dWindowClass", "DM", nullptr));
        ckb_Aztec_Code2d->setText(QApplication::translate("Code2dWindowClass", "Aztec", nullptr));
        ckb_GS1DM_Code2d->setText(QApplication::translate("Code2dWindowClass", "GS1DM", nullptr));
        ckb_MicroQR_Code2d->setText(QApplication::translate("Code2dWindowClass", "MicroQR", nullptr));
        ckb_QR_Code2d->setText(QApplication::translate("Code2dWindowClass", "QR", nullptr));
        ckb_GS1Aztec_Code2d->setText(QApplication::translate("Code2dWindowClass", "GS1Aztec", nullptr));
        ckb_GS1QR_Code2d->setText(QApplication::translate("Code2dWindowClass", "GS1QR", nullptr));
        ckb_PDF417_Code2d->setText(QApplication::translate("Code2dWindowClass", "PDF417", nullptr));
        tabWidget_5->setTabText(tabWidget_5->indexOf(tab_17), QApplication::translate("Code2dWindowClass", "\345\217\202\346\225\260", nullptr));
        label_59->setText(QApplication::translate("Code2dWindowClass", "\347\211\271\345\256\232\345\255\227\347\254\246\345\274\200\345\244\264\357\274\232", nullptr));
        label_60->setText(QApplication::translate("Code2dWindowClass", "\347\211\271\345\256\232\345\255\227\347\254\246\347\273\223\345\260\276\357\274\232", nullptr));
        label_61->setText(QApplication::translate("Code2dWindowClass", "\345\214\205\345\220\253\347\211\271\345\256\232\345\255\227\347\254\246\357\274\232", nullptr));
        label_62->setText(QApplication::translate("Code2dWindowClass", "\344\270\215\345\214\205\345\220\253\347\211\271\345\256\232\345\255\227\347\254\246\357\274\232", nullptr));
        label_63->setText(QApplication::translate("Code2dWindowClass", "\346\235\241\347\240\201\346\234\200\345\260\217\351\225\277\345\272\246\357\274\232", nullptr));
        btn_LoadCode2dData->setText(QApplication::translate("Code2dWindowClass", "\345\217\202\346\225\260\345\212\240\350\275\275", nullptr));
        btn_SaveCode2dData->setText(QApplication::translate("Code2dWindowClass", "\345\217\202\346\225\260\344\277\235\345\255\230", nullptr));
        btn_FindCode2d->setText(QApplication::translate("Code2dWindowClass", "\350\277\220\350\241\214", nullptr));
        lbl_CT_Code2d->setText(QApplication::translate("Code2dWindowClass", "\350\277\220\350\241\214\346\227\266\351\227\264", nullptr));
        tabWidget_5->setTabText(tabWidget_5->indexOf(tab_18), QApplication::translate("Code2dWindowClass", "\350\277\207\346\273\244", nullptr));
        tabWidget_5->setTabText(tabWidget_5->indexOf(tab_19), QApplication::translate("Code2dWindowClass", "\347\273\223\346\236\234", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Code2dWindowClass: public Ui_Code2dWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QRCODEWINDOW_H
