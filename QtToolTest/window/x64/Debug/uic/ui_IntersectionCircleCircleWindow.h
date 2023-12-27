/********************************************************************************
** Form generated from reading UI file 'IntersectionCircleCircleWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTERSECTIONCIRCLECIRCLEWINDOW_H
#define UI_INTERSECTIONCIRCLECIRCLEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "cmylabel.h"

QT_BEGIN_NAMESPACE

class Ui_IntersectionCircleCircleWindowClass
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
    QGroupBox *groupBox_2;
    QTabWidget *tabWidget_4;
    QWidget *tab_14;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_3;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QDoubleSpinBox *dspb_Row1_CircleA;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QDoubleSpinBox *dspb_Col1_CircleA;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QDoubleSpinBox *dspb_Radius_CircleA;
    QGroupBox *groupBox_4;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QDoubleSpinBox *dspb_Row1_CircleB;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QDoubleSpinBox *dspb_Col1_CircleB;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QDoubleSpinBox *dspb_Radius_CircleB;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_11;
    QPushButton *pb_Run;
    QLabel *lbl_IntersectCircleCircleCT;
    QWidget *tab_15;
    QWidget *layoutWidget4;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_9;
    QLineEdit *lineEdit_Row1_ResultCircleCircle;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_10;
    QLineEdit *lineEdit_Col1_ResultCircleCircle;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_11;
    QLineEdit *lineEdit_Row2_ResultCircleCircle;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_12;
    QLineEdit *lineEdit_Col2_ResultCircleCircle;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *IntersectionCircleCircleWindowClass)
    {
        if (IntersectionCircleCircleWindowClass->objectName().isEmpty())
            IntersectionCircleCircleWindowClass->setObjectName(QString::fromUtf8("IntersectionCircleCircleWindowClass"));
        IntersectionCircleCircleWindowClass->resize(1225, 894);
        centralWidget = new QWidget(IntersectionCircleCircleWindowClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 20, 621, 806));
        lbl_Window = new CMyLabel(groupBox);
        lbl_Window->setObjectName(QString::fromUtf8("lbl_Window"));
        lbl_Window->setGeometry(QRect(10, 20, 601, 501));
        lbl_Window->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        pBtn_ReadImage = new QPushButton(groupBox);
        pBtn_ReadImage->setObjectName(QString::fromUtf8("pBtn_ReadImage"));
        pBtn_ReadImage->setGeometry(QRect(10, 650, 111, 91));
        pBtn_FitImage = new QPushButton(groupBox);
        pBtn_FitImage->setObjectName(QString::fromUtf8("pBtn_FitImage"));
        pBtn_FitImage->setGeometry(QRect(140, 650, 111, 91));
        lbl_Status = new QLabel(groupBox);
        lbl_Status->setObjectName(QString::fromUtf8("lbl_Status"));
        lbl_Status->setGeometry(QRect(20, 550, 591, 18));
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
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(670, 20, 541, 801));
        tabWidget_4 = new QTabWidget(groupBox_2);
        tabWidget_4->setObjectName(QString::fromUtf8("tabWidget_4"));
        tabWidget_4->setGeometry(QRect(20, 20, 501, 761));
        tab_14 = new QWidget();
        tab_14->setObjectName(QString::fromUtf8("tab_14"));
        layoutWidget = new QWidget(tab_14);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 30, 471, 531));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        groupBox_3 = new QGroupBox(layoutWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        layoutWidget1 = new QWidget(groupBox_3);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(40, 30, 401, 211));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(layoutWidget1);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        dspb_Row1_CircleA = new QDoubleSpinBox(layoutWidget1);
        dspb_Row1_CircleA->setObjectName(QString::fromUtf8("dspb_Row1_CircleA"));
        dspb_Row1_CircleA->setDecimals(4);
        dspb_Row1_CircleA->setMaximum(999999999.000000000000000);
        dspb_Row1_CircleA->setSingleStep(0.000100000000000);

        horizontalLayout->addWidget(dspb_Row1_CircleA);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        dspb_Col1_CircleA = new QDoubleSpinBox(layoutWidget1);
        dspb_Col1_CircleA->setObjectName(QString::fromUtf8("dspb_Col1_CircleA"));
        dspb_Col1_CircleA->setDecimals(4);
        dspb_Col1_CircleA->setMaximum(999999999.000000000000000);
        dspb_Col1_CircleA->setSingleStep(0.000100000000000);

        horizontalLayout_2->addWidget(dspb_Col1_CircleA);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        dspb_Radius_CircleA = new QDoubleSpinBox(layoutWidget1);
        dspb_Radius_CircleA->setObjectName(QString::fromUtf8("dspb_Radius_CircleA"));
        dspb_Radius_CircleA->setDecimals(4);
        dspb_Radius_CircleA->setMaximum(999999999.000000000000000);
        dspb_Radius_CircleA->setSingleStep(0.000100000000000);

        horizontalLayout_3->addWidget(dspb_Radius_CircleA);


        verticalLayout_2->addLayout(horizontalLayout_3);


        verticalLayout->addWidget(groupBox_3);

        groupBox_4 = new QGroupBox(layoutWidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        layoutWidget2 = new QWidget(groupBox_4);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(40, 30, 401, 211));
        verticalLayout_3 = new QVBoxLayout(layoutWidget2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_5 = new QLabel(layoutWidget2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_5->addWidget(label_5);

        dspb_Row1_CircleB = new QDoubleSpinBox(layoutWidget2);
        dspb_Row1_CircleB->setObjectName(QString::fromUtf8("dspb_Row1_CircleB"));
        dspb_Row1_CircleB->setDecimals(4);
        dspb_Row1_CircleB->setMaximum(999999999.000000000000000);
        dspb_Row1_CircleB->setSingleStep(0.000100000000000);

        horizontalLayout_5->addWidget(dspb_Row1_CircleB);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_6 = new QLabel(layoutWidget2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_6->addWidget(label_6);

        dspb_Col1_CircleB = new QDoubleSpinBox(layoutWidget2);
        dspb_Col1_CircleB->setObjectName(QString::fromUtf8("dspb_Col1_CircleB"));
        dspb_Col1_CircleB->setDecimals(4);
        dspb_Col1_CircleB->setMaximum(999999999.000000000000000);
        dspb_Col1_CircleB->setSingleStep(0.000100000000000);

        horizontalLayout_6->addWidget(dspb_Col1_CircleB);


        verticalLayout_3->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_7 = new QLabel(layoutWidget2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_7->addWidget(label_7);

        dspb_Radius_CircleB = new QDoubleSpinBox(layoutWidget2);
        dspb_Radius_CircleB->setObjectName(QString::fromUtf8("dspb_Radius_CircleB"));
        dspb_Radius_CircleB->setDecimals(4);
        dspb_Radius_CircleB->setMaximum(999999999.000000000000000);
        dspb_Radius_CircleB->setSingleStep(0.000100000000000);

        horizontalLayout_7->addWidget(dspb_Radius_CircleB);


        verticalLayout_3->addLayout(horizontalLayout_7);


        verticalLayout->addWidget(groupBox_4);

        layoutWidget3 = new QWidget(tab_14);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(20, 590, 381, 71));
        horizontalLayout_11 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(0, 0, 0, 0);
        pb_Run = new QPushButton(layoutWidget3);
        pb_Run->setObjectName(QString::fromUtf8("pb_Run"));

        horizontalLayout_11->addWidget(pb_Run);

        lbl_IntersectCircleCircleCT = new QLabel(layoutWidget3);
        lbl_IntersectCircleCircleCT->setObjectName(QString::fromUtf8("lbl_IntersectCircleCircleCT"));

        horizontalLayout_11->addWidget(lbl_IntersectCircleCircleCT);

        tabWidget_4->addTab(tab_14, QString());
        tab_15 = new QWidget();
        tab_15->setObjectName(QString::fromUtf8("tab_15"));
        layoutWidget4 = new QWidget(tab_15);
        layoutWidget4->setObjectName(QString::fromUtf8("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(20, 20, 461, 421));
        verticalLayout_6 = new QVBoxLayout(layoutWidget4);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_9 = new QLabel(layoutWidget4);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_10->addWidget(label_9);

        lineEdit_Row1_ResultCircleCircle = new QLineEdit(layoutWidget4);
        lineEdit_Row1_ResultCircleCircle->setObjectName(QString::fromUtf8("lineEdit_Row1_ResultCircleCircle"));

        horizontalLayout_10->addWidget(lineEdit_Row1_ResultCircleCircle);


        verticalLayout_4->addLayout(horizontalLayout_10);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_10 = new QLabel(layoutWidget4);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_9->addWidget(label_10);

        lineEdit_Col1_ResultCircleCircle = new QLineEdit(layoutWidget4);
        lineEdit_Col1_ResultCircleCircle->setObjectName(QString::fromUtf8("lineEdit_Col1_ResultCircleCircle"));

        horizontalLayout_9->addWidget(lineEdit_Col1_ResultCircleCircle);


        verticalLayout_4->addLayout(horizontalLayout_9);


        verticalLayout_6->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label_11 = new QLabel(layoutWidget4);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout_12->addWidget(label_11);

        lineEdit_Row2_ResultCircleCircle = new QLineEdit(layoutWidget4);
        lineEdit_Row2_ResultCircleCircle->setObjectName(QString::fromUtf8("lineEdit_Row2_ResultCircleCircle"));

        horizontalLayout_12->addWidget(lineEdit_Row2_ResultCircleCircle);


        verticalLayout_5->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        label_12 = new QLabel(layoutWidget4);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_13->addWidget(label_12);

        lineEdit_Col2_ResultCircleCircle = new QLineEdit(layoutWidget4);
        lineEdit_Col2_ResultCircleCircle->setObjectName(QString::fromUtf8("lineEdit_Col2_ResultCircleCircle"));

        horizontalLayout_13->addWidget(lineEdit_Col2_ResultCircleCircle);


        verticalLayout_5->addLayout(horizontalLayout_13);


        verticalLayout_6->addLayout(verticalLayout_5);

        tabWidget_4->addTab(tab_15, QString());
        IntersectionCircleCircleWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(IntersectionCircleCircleWindowClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1225, 23));
        IntersectionCircleCircleWindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(IntersectionCircleCircleWindowClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        IntersectionCircleCircleWindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(IntersectionCircleCircleWindowClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        IntersectionCircleCircleWindowClass->setStatusBar(statusBar);

        retranslateUi(IntersectionCircleCircleWindowClass);

        tabWidget_4->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(IntersectionCircleCircleWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *IntersectionCircleCircleWindowClass)
    {
        IntersectionCircleCircleWindowClass->setWindowTitle(QApplication::translate("IntersectionCircleCircleWindowClass", "IntersectionCircleCircleWindow", nullptr));
        groupBox->setTitle(QApplication::translate("IntersectionCircleCircleWindowClass", "\346\230\276\347\244\272\347\252\227\345\217\243", nullptr));
        lbl_Window->setText(QString());
        pBtn_ReadImage->setText(QApplication::translate("IntersectionCircleCircleWindowClass", "\346\211\223\345\274\200\345\233\276\347\211\207", nullptr));
        pBtn_FitImage->setText(QApplication::translate("IntersectionCircleCircleWindowClass", "\350\207\252\351\200\202\345\272\224", nullptr));
        lbl_Status->setText(QApplication::translate("IntersectionCircleCircleWindowClass", "\345\235\220\346\240\207\347\201\260\345\272\246\344\277\241\346\201\257", nullptr));
        btn_ClearWindow->setText(QApplication::translate("IntersectionCircleCircleWindowClass", "\346\270\205\347\251\272\347\252\227\345\217\243", nullptr));
        ckb_ShowObj->setText(QApplication::translate("IntersectionCircleCircleWindowClass", "\347\274\251\346\224\276\346\227\266\346\230\276\347\244\272\345\233\276\345\275\242", nullptr));
        btn_Hide->setText(QApplication::translate("IntersectionCircleCircleWindowClass", "\345\205\263\351\227\255", nullptr));
        groupBox_2->setTitle(QApplication::translate("IntersectionCircleCircleWindowClass", "\346\223\215\344\275\234\347\252\227\345\217\243", nullptr));
        groupBox_3->setTitle(QApplication::translate("IntersectionCircleCircleWindowClass", "\345\234\206A", nullptr));
        label->setText(QApplication::translate("IntersectionCircleCircleWindowClass", "Row:", nullptr));
        label_2->setText(QApplication::translate("IntersectionCircleCircleWindowClass", "Col:", nullptr));
        label_3->setText(QApplication::translate("IntersectionCircleCircleWindowClass", "Radius:", nullptr));
        groupBox_4->setTitle(QApplication::translate("IntersectionCircleCircleWindowClass", "\345\234\206B", nullptr));
        label_5->setText(QApplication::translate("IntersectionCircleCircleWindowClass", "Row:", nullptr));
        label_6->setText(QApplication::translate("IntersectionCircleCircleWindowClass", "Col:", nullptr));
        label_7->setText(QApplication::translate("IntersectionCircleCircleWindowClass", "Radius:", nullptr));
        pb_Run->setText(QApplication::translate("IntersectionCircleCircleWindowClass", "\350\277\220\350\241\214", nullptr));
        lbl_IntersectCircleCircleCT->setText(QApplication::translate("IntersectionCircleCircleWindowClass", "\350\277\220\350\241\214\346\227\266\351\227\264", nullptr));
        tabWidget_4->setTabText(tabWidget_4->indexOf(tab_14), QApplication::translate("IntersectionCircleCircleWindowClass", "\350\276\223\345\205\245", nullptr));
        label_9->setText(QApplication::translate("IntersectionCircleCircleWindowClass", "Row1:", nullptr));
        label_10->setText(QApplication::translate("IntersectionCircleCircleWindowClass", "Col1:", nullptr));
        label_11->setText(QApplication::translate("IntersectionCircleCircleWindowClass", "Row2:", nullptr));
        label_12->setText(QApplication::translate("IntersectionCircleCircleWindowClass", "Col2:", nullptr));
        tabWidget_4->setTabText(tabWidget_4->indexOf(tab_15), QApplication::translate("IntersectionCircleCircleWindowClass", "\347\273\223\346\236\234", nullptr));
    } // retranslateUi

};

namespace Ui {
    class IntersectionCircleCircleWindowClass: public Ui_IntersectionCircleCircleWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERSECTIONCIRCLECIRCLEWINDOW_H
