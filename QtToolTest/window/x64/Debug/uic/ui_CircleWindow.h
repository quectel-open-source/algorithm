/********************************************************************************
** Form generated from reading UI file 'CircleWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CIRCLEWINDOW_H
#define UI_CIRCLEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
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

class Ui_CircleWindowClass
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
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_47;
    QDoubleSpinBox *dspb_CenterRow_Circle;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_49;
    QDoubleSpinBox *dspb_CenterCol_Circle;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_50;
    QDoubleSpinBox *dspb_CenterRadius_Circle;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_38;
    QSpinBox *spb_MeasureNum_Circle;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_39;
    QSpinBox *spb_MeasureLength1_Circle;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_40;
    QSpinBox *spb_MeasureLength2_Circle;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_41;
    QDoubleSpinBox *dspb_MeasureSigma_Circle;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_42;
    QSpinBox *spb_MeasureThreshold_Circle;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_43;
    QComboBox *cmb_MeasureTransition_Circle;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_44;
    QComboBox *cmb_MeasureSelect_Circle;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_45;
    QDoubleSpinBox *dspb_MinScore_Circle;
    QHBoxLayout *horizontalLayout_18;
    QLabel *label_48;
    QDoubleSpinBox *dspb_DistanceThreshold_Circle;
    QHBoxLayout *horizontalLayout_19;
    QLabel *label_46;
    QComboBox *cmb_MeasureInterpolation_Circle;
    QHBoxLayout *horizontalLayout_20;
    QLabel *label_54;
    QComboBox *cmb_IsFollow_Circle;
    QSpacerItem *verticalSpacer_5;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *btn_DrawCircle_Circle;
    QPushButton *btn_DetectCircle_Circle;
    QPushButton *btn_ClearRoi_Circle;
    QWidget *tab_15;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_17;
    QHBoxLayout *horizontalLayout_16;
    QPushButton *btn_SaveCircleData;
    QPushButton *btn_LoadCircleData;
    QLabel *lbl_RunCircleCT;
    QSpacerItem *verticalSpacer_7;
    QVBoxLayout *verticalLayout_13;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_55;
    QLineEdit *txt_Col1_Circle;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_56;
    QLineEdit *txt_Row1_Circle;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_57;
    QLineEdit *txt_Radius_Circle;
    QWidget *tab_16;
    QTableWidget *tablewidget_PointsResult_Circle;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CircleWindowClass)
    {
        if (CircleWindowClass->objectName().isEmpty())
            CircleWindowClass->setObjectName(QString::fromUtf8("CircleWindowClass"));
        CircleWindowClass->resize(1249, 872);
        centralWidget = new QWidget(CircleWindowClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 621, 806));
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
        groupBox_2->setGeometry(QRect(640, 10, 591, 801));
        tabWidget_4 = new QTabWidget(groupBox_2);
        tabWidget_4->setObjectName(QString::fromUtf8("tabWidget_4"));
        tabWidget_4->setGeometry(QRect(10, 30, 561, 751));
        tab_14 = new QWidget();
        tab_14->setObjectName(QString::fromUtf8("tab_14"));
        gridLayout = new QGridLayout(tab_14);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_47 = new QLabel(tab_14);
        label_47->setObjectName(QString::fromUtf8("label_47"));

        horizontalLayout->addWidget(label_47);

        dspb_CenterRow_Circle = new QDoubleSpinBox(tab_14);
        dspb_CenterRow_Circle->setObjectName(QString::fromUtf8("dspb_CenterRow_Circle"));
        dspb_CenterRow_Circle->setEnabled(false);
        dspb_CenterRow_Circle->setDecimals(4);
        dspb_CenterRow_Circle->setMinimum(0.000000000000000);
        dspb_CenterRow_Circle->setMaximum(999999999.000000000000000);
        dspb_CenterRow_Circle->setSingleStep(0.000100000000000);

        horizontalLayout->addWidget(dspb_CenterRow_Circle);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_49 = new QLabel(tab_14);
        label_49->setObjectName(QString::fromUtf8("label_49"));

        horizontalLayout_2->addWidget(label_49);

        dspb_CenterCol_Circle = new QDoubleSpinBox(tab_14);
        dspb_CenterCol_Circle->setObjectName(QString::fromUtf8("dspb_CenterCol_Circle"));
        dspb_CenterCol_Circle->setEnabled(false);
        dspb_CenterCol_Circle->setDecimals(4);
        dspb_CenterCol_Circle->setMinimum(0.000000000000000);
        dspb_CenterCol_Circle->setMaximum(999999999.000000000000000);
        dspb_CenterCol_Circle->setSingleStep(0.000100000000000);

        horizontalLayout_2->addWidget(dspb_CenterCol_Circle);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_50 = new QLabel(tab_14);
        label_50->setObjectName(QString::fromUtf8("label_50"));

        horizontalLayout_3->addWidget(label_50);

        dspb_CenterRadius_Circle = new QDoubleSpinBox(tab_14);
        dspb_CenterRadius_Circle->setObjectName(QString::fromUtf8("dspb_CenterRadius_Circle"));
        dspb_CenterRadius_Circle->setEnabled(false);
        dspb_CenterRadius_Circle->setDecimals(4);
        dspb_CenterRadius_Circle->setMinimum(0.000000000000000);
        dspb_CenterRadius_Circle->setMaximum(999999999.000000000000000);
        dspb_CenterRadius_Circle->setSingleStep(0.000100000000000);

        horizontalLayout_3->addWidget(dspb_CenterRadius_Circle);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_38 = new QLabel(tab_14);
        label_38->setObjectName(QString::fromUtf8("label_38"));

        horizontalLayout_4->addWidget(label_38);

        spb_MeasureNum_Circle = new QSpinBox(tab_14);
        spb_MeasureNum_Circle->setObjectName(QString::fromUtf8("spb_MeasureNum_Circle"));
        spb_MeasureNum_Circle->setMaximum(999999);
        spb_MeasureNum_Circle->setValue(20);

        horizontalLayout_4->addWidget(spb_MeasureNum_Circle);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_39 = new QLabel(tab_14);
        label_39->setObjectName(QString::fromUtf8("label_39"));

        horizontalLayout_5->addWidget(label_39);

        spb_MeasureLength1_Circle = new QSpinBox(tab_14);
        spb_MeasureLength1_Circle->setObjectName(QString::fromUtf8("spb_MeasureLength1_Circle"));
        spb_MeasureLength1_Circle->setMaximum(999999);
        spb_MeasureLength1_Circle->setValue(20);

        horizontalLayout_5->addWidget(spb_MeasureLength1_Circle);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_40 = new QLabel(tab_14);
        label_40->setObjectName(QString::fromUtf8("label_40"));

        horizontalLayout_6->addWidget(label_40);

        spb_MeasureLength2_Circle = new QSpinBox(tab_14);
        spb_MeasureLength2_Circle->setObjectName(QString::fromUtf8("spb_MeasureLength2_Circle"));
        spb_MeasureLength2_Circle->setMaximum(999999);
        spb_MeasureLength2_Circle->setValue(2);

        horizontalLayout_6->addWidget(spb_MeasureLength2_Circle);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_41 = new QLabel(tab_14);
        label_41->setObjectName(QString::fromUtf8("label_41"));

        horizontalLayout_7->addWidget(label_41);

        dspb_MeasureSigma_Circle = new QDoubleSpinBox(tab_14);
        dspb_MeasureSigma_Circle->setObjectName(QString::fromUtf8("dspb_MeasureSigma_Circle"));
        dspb_MeasureSigma_Circle->setDecimals(1);
        dspb_MeasureSigma_Circle->setMinimum(0.400000000000000);
        dspb_MeasureSigma_Circle->setSingleStep(0.100000000000000);

        horizontalLayout_7->addWidget(dspb_MeasureSigma_Circle);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_42 = new QLabel(tab_14);
        label_42->setObjectName(QString::fromUtf8("label_42"));

        horizontalLayout_8->addWidget(label_42);

        spb_MeasureThreshold_Circle = new QSpinBox(tab_14);
        spb_MeasureThreshold_Circle->setObjectName(QString::fromUtf8("spb_MeasureThreshold_Circle"));
        spb_MeasureThreshold_Circle->setMaximum(255);
        spb_MeasureThreshold_Circle->setValue(10);

        horizontalLayout_8->addWidget(spb_MeasureThreshold_Circle);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_43 = new QLabel(tab_14);
        label_43->setObjectName(QString::fromUtf8("label_43"));

        horizontalLayout_10->addWidget(label_43);

        cmb_MeasureTransition_Circle = new QComboBox(tab_14);
        cmb_MeasureTransition_Circle->addItem(QString());
        cmb_MeasureTransition_Circle->addItem(QString());
        cmb_MeasureTransition_Circle->addItem(QString());
        cmb_MeasureTransition_Circle->addItem(QString());
        cmb_MeasureTransition_Circle->setObjectName(QString::fromUtf8("cmb_MeasureTransition_Circle"));

        horizontalLayout_10->addWidget(cmb_MeasureTransition_Circle);


        verticalLayout->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_44 = new QLabel(tab_14);
        label_44->setObjectName(QString::fromUtf8("label_44"));

        horizontalLayout_11->addWidget(label_44);

        cmb_MeasureSelect_Circle = new QComboBox(tab_14);
        cmb_MeasureSelect_Circle->addItem(QString());
        cmb_MeasureSelect_Circle->addItem(QString());
        cmb_MeasureSelect_Circle->addItem(QString());
        cmb_MeasureSelect_Circle->setObjectName(QString::fromUtf8("cmb_MeasureSelect_Circle"));

        horizontalLayout_11->addWidget(cmb_MeasureSelect_Circle);


        verticalLayout->addLayout(horizontalLayout_11);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        label_45 = new QLabel(tab_14);
        label_45->setObjectName(QString::fromUtf8("label_45"));

        horizontalLayout_14->addWidget(label_45);

        dspb_MinScore_Circle = new QDoubleSpinBox(tab_14);
        dspb_MinScore_Circle->setObjectName(QString::fromUtf8("dspb_MinScore_Circle"));
        dspb_MinScore_Circle->setMaximum(1.000000000000000);
        dspb_MinScore_Circle->setSingleStep(0.010000000000000);
        dspb_MinScore_Circle->setValue(0.550000000000000);

        horizontalLayout_14->addWidget(dspb_MinScore_Circle);


        verticalLayout->addLayout(horizontalLayout_14);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setSpacing(6);
        horizontalLayout_18->setObjectName(QString::fromUtf8("horizontalLayout_18"));
        label_48 = new QLabel(tab_14);
        label_48->setObjectName(QString::fromUtf8("label_48"));

        horizontalLayout_18->addWidget(label_48);

        dspb_DistanceThreshold_Circle = new QDoubleSpinBox(tab_14);
        dspb_DistanceThreshold_Circle->setObjectName(QString::fromUtf8("dspb_DistanceThreshold_Circle"));
        dspb_DistanceThreshold_Circle->setDecimals(1);
        dspb_DistanceThreshold_Circle->setSingleStep(0.100000000000000);
        dspb_DistanceThreshold_Circle->setValue(3.500000000000000);

        horizontalLayout_18->addWidget(dspb_DistanceThreshold_Circle);


        verticalLayout->addLayout(horizontalLayout_18);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setSpacing(6);
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));
        label_46 = new QLabel(tab_14);
        label_46->setObjectName(QString::fromUtf8("label_46"));

        horizontalLayout_19->addWidget(label_46);

        cmb_MeasureInterpolation_Circle = new QComboBox(tab_14);
        cmb_MeasureInterpolation_Circle->addItem(QString());
        cmb_MeasureInterpolation_Circle->addItem(QString());
        cmb_MeasureInterpolation_Circle->addItem(QString());
        cmb_MeasureInterpolation_Circle->setObjectName(QString::fromUtf8("cmb_MeasureInterpolation_Circle"));

        horizontalLayout_19->addWidget(cmb_MeasureInterpolation_Circle);


        verticalLayout->addLayout(horizontalLayout_19);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setSpacing(6);
        horizontalLayout_20->setObjectName(QString::fromUtf8("horizontalLayout_20"));
        label_54 = new QLabel(tab_14);
        label_54->setObjectName(QString::fromUtf8("label_54"));

        horizontalLayout_20->addWidget(label_54);

        cmb_IsFollow_Circle = new QComboBox(tab_14);
        cmb_IsFollow_Circle->addItem(QString());
        cmb_IsFollow_Circle->addItem(QString());
        cmb_IsFollow_Circle->setObjectName(QString::fromUtf8("cmb_IsFollow_Circle"));

        horizontalLayout_20->addWidget(cmb_IsFollow_Circle);


        verticalLayout->addLayout(horizontalLayout_20);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 280, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_5, 1, 0, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        btn_DrawCircle_Circle = new QPushButton(tab_14);
        btn_DrawCircle_Circle->setObjectName(QString::fromUtf8("btn_DrawCircle_Circle"));

        horizontalLayout_9->addWidget(btn_DrawCircle_Circle);

        btn_DetectCircle_Circle = new QPushButton(tab_14);
        btn_DetectCircle_Circle->setObjectName(QString::fromUtf8("btn_DetectCircle_Circle"));

        horizontalLayout_9->addWidget(btn_DetectCircle_Circle);

        btn_ClearRoi_Circle = new QPushButton(tab_14);
        btn_ClearRoi_Circle->setObjectName(QString::fromUtf8("btn_ClearRoi_Circle"));

        horizontalLayout_9->addWidget(btn_ClearRoi_Circle);


        gridLayout->addLayout(horizontalLayout_9, 2, 0, 1, 1);

        tabWidget_4->addTab(tab_14, QString());
        tab_15 = new QWidget();
        tab_15->setObjectName(QString::fromUtf8("tab_15"));
        widget = new QWidget(tab_15);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(12, 17, 521, 671));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setSpacing(6);
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        btn_SaveCircleData = new QPushButton(widget);
        btn_SaveCircleData->setObjectName(QString::fromUtf8("btn_SaveCircleData"));

        horizontalLayout_16->addWidget(btn_SaveCircleData);

        btn_LoadCircleData = new QPushButton(widget);
        btn_LoadCircleData->setObjectName(QString::fromUtf8("btn_LoadCircleData"));

        horizontalLayout_16->addWidget(btn_LoadCircleData);


        horizontalLayout_17->addLayout(horizontalLayout_16);

        lbl_RunCircleCT = new QLabel(widget);
        lbl_RunCircleCT->setObjectName(QString::fromUtf8("lbl_RunCircleCT"));

        horizontalLayout_17->addWidget(lbl_RunCircleCT);


        verticalLayout_2->addLayout(horizontalLayout_17);

        verticalSpacer_7 = new QSpacerItem(20, 298, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_7);

        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setSpacing(6);
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label_55 = new QLabel(widget);
        label_55->setObjectName(QString::fromUtf8("label_55"));

        horizontalLayout_12->addWidget(label_55);

        txt_Col1_Circle = new QLineEdit(widget);
        txt_Col1_Circle->setObjectName(QString::fromUtf8("txt_Col1_Circle"));
        txt_Col1_Circle->setReadOnly(true);

        horizontalLayout_12->addWidget(txt_Col1_Circle);


        verticalLayout_13->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        label_56 = new QLabel(widget);
        label_56->setObjectName(QString::fromUtf8("label_56"));

        horizontalLayout_13->addWidget(label_56);

        txt_Row1_Circle = new QLineEdit(widget);
        txt_Row1_Circle->setObjectName(QString::fromUtf8("txt_Row1_Circle"));
        txt_Row1_Circle->setReadOnly(true);

        horizontalLayout_13->addWidget(txt_Row1_Circle);


        verticalLayout_13->addLayout(horizontalLayout_13);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        label_57 = new QLabel(widget);
        label_57->setObjectName(QString::fromUtf8("label_57"));

        horizontalLayout_15->addWidget(label_57);

        txt_Radius_Circle = new QLineEdit(widget);
        txt_Radius_Circle->setObjectName(QString::fromUtf8("txt_Radius_Circle"));
        txt_Radius_Circle->setReadOnly(true);

        horizontalLayout_15->addWidget(txt_Radius_Circle);


        verticalLayout_13->addLayout(horizontalLayout_15);


        verticalLayout_2->addLayout(verticalLayout_13);

        tabWidget_4->addTab(tab_15, QString());
        tab_16 = new QWidget();
        tab_16->setObjectName(QString::fromUtf8("tab_16"));
        tablewidget_PointsResult_Circle = new QTableWidget(tab_16);
        tablewidget_PointsResult_Circle->setObjectName(QString::fromUtf8("tablewidget_PointsResult_Circle"));
        tablewidget_PointsResult_Circle->setGeometry(QRect(10, 20, 561, 671));
        tabWidget_4->addTab(tab_16, QString());
        CircleWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(CircleWindowClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1249, 23));
        CircleWindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(CircleWindowClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        CircleWindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(CircleWindowClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        CircleWindowClass->setStatusBar(statusBar);

        retranslateUi(CircleWindowClass);

        tabWidget_4->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(CircleWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *CircleWindowClass)
    {
        CircleWindowClass->setWindowTitle(QApplication::translate("CircleWindowClass", "CircleWindow", nullptr));
        groupBox->setTitle(QApplication::translate("CircleWindowClass", "\346\230\276\347\244\272\347\252\227\345\217\243", nullptr));
        lbl_Window->setText(QString());
        pBtn_ReadImage->setText(QApplication::translate("CircleWindowClass", "\346\211\223\345\274\200\345\233\276\347\211\207", nullptr));
        pBtn_FitImage->setText(QApplication::translate("CircleWindowClass", "\350\207\252\351\200\202\345\272\224", nullptr));
        lbl_Status->setText(QApplication::translate("CircleWindowClass", "\345\235\220\346\240\207\347\201\260\345\272\246\344\277\241\346\201\257", nullptr));
        btn_ClearWindow->setText(QApplication::translate("CircleWindowClass", "\346\270\205\347\251\272\347\252\227\345\217\243", nullptr));
        ckb_ShowObj->setText(QApplication::translate("CircleWindowClass", "\347\274\251\346\224\276\346\227\266\346\230\276\347\244\272\345\233\276\345\275\242", nullptr));
        btn_Hide->setText(QApplication::translate("CircleWindowClass", "\345\205\263\351\227\255", nullptr));
        groupBox_2->setTitle(QApplication::translate("CircleWindowClass", "\346\223\215\344\275\234\347\252\227\345\217\243", nullptr));
        label_47->setText(QApplication::translate("CircleWindowClass", "\345\234\206\345\277\203Row", nullptr));
        label_49->setText(QApplication::translate("CircleWindowClass", "\345\234\206\345\277\203Col", nullptr));
        label_50->setText(QApplication::translate("CircleWindowClass", "\345\234\206\345\215\212\345\276\204", nullptr));
        label_38->setText(QApplication::translate("CircleWindowClass", "\345\215\241\345\260\272\346\225\260\351\207\217", nullptr));
        label_39->setText(QApplication::translate("CircleWindowClass", "\346\220\234\347\264\242\351\225\277\345\272\246", nullptr));
        label_40->setText(QApplication::translate("CircleWindowClass", "\346\212\225\345\275\261\351\225\277\345\272\246", nullptr));
        label_41->setText(QApplication::translate("CircleWindowClass", "\345\271\263\346\273\221(Sigma)", nullptr));
        label_42->setText(QApplication::translate("CircleWindowClass", "\351\230\210\345\200\274", nullptr));
        label_43->setText(QApplication::translate("CircleWindowClass", "\346\236\201\346\200\247", nullptr));
        cmb_MeasureTransition_Circle->setItemText(0, QApplication::translate("CircleWindowClass", "positive", nullptr));
        cmb_MeasureTransition_Circle->setItemText(1, QApplication::translate("CircleWindowClass", "negative", nullptr));
        cmb_MeasureTransition_Circle->setItemText(2, QApplication::translate("CircleWindowClass", "all", nullptr));
        cmb_MeasureTransition_Circle->setItemText(3, QApplication::translate("CircleWindowClass", "uniform", nullptr));

        label_44->setText(QApplication::translate("CircleWindowClass", "\350\276\271\347\274\230\351\200\211\345\217\226", nullptr));
        cmb_MeasureSelect_Circle->setItemText(0, QApplication::translate("CircleWindowClass", "first", nullptr));
        cmb_MeasureSelect_Circle->setItemText(1, QApplication::translate("CircleWindowClass", "last", nullptr));
        cmb_MeasureSelect_Circle->setItemText(2, QApplication::translate("CircleWindowClass", "all", nullptr));

        label_45->setText(QApplication::translate("CircleWindowClass", "\346\234\200\345\260\217\345\276\227\345\210\206", nullptr));
        label_48->setText(QApplication::translate("CircleWindowClass", "\350\267\235\347\246\273\345\211\224\351\231\244", nullptr));
        label_46->setText(QApplication::translate("CircleWindowClass", "\346\217\222\345\200\274\347\256\227\346\263\225", nullptr));
        cmb_MeasureInterpolation_Circle->setItemText(0, QApplication::translate("CircleWindowClass", "nearest_neighbor", nullptr));
        cmb_MeasureInterpolation_Circle->setItemText(1, QApplication::translate("CircleWindowClass", "bilinear", nullptr));
        cmb_MeasureInterpolation_Circle->setItemText(2, QApplication::translate("CircleWindowClass", "bicubic", nullptr));

        label_54->setText(QApplication::translate("CircleWindowClass", "\346\230\257\345\220\246\350\267\237\351\232\217", nullptr));
        cmb_IsFollow_Circle->setItemText(0, QApplication::translate("CircleWindowClass", "No", nullptr));
        cmb_IsFollow_Circle->setItemText(1, QApplication::translate("CircleWindowClass", "Yes", nullptr));

        btn_DrawCircle_Circle->setText(QApplication::translate("CircleWindowClass", "\347\273\230\345\210\266\345\234\206", nullptr));
        btn_DetectCircle_Circle->setText(QApplication::translate("CircleWindowClass", "\346\243\200\346\265\213\345\234\206", nullptr));
        btn_ClearRoi_Circle->setText(QApplication::translate("CircleWindowClass", "\346\270\205\351\231\244ROI", nullptr));
        tabWidget_4->setTabText(tabWidget_4->indexOf(tab_14), QApplication::translate("CircleWindowClass", "\345\215\241\345\260\272\350\256\276\347\275\256", nullptr));
        btn_SaveCircleData->setText(QApplication::translate("CircleWindowClass", "\345\217\202\346\225\260\344\277\235\345\255\230", nullptr));
        btn_LoadCircleData->setText(QApplication::translate("CircleWindowClass", "\345\217\202\346\225\260\345\212\240\350\275\275", nullptr));
        lbl_RunCircleCT->setText(QApplication::translate("CircleWindowClass", "\350\277\220\350\241\214\346\227\266\351\227\264", nullptr));
        label_55->setText(QApplication::translate("CircleWindowClass", "\345\234\206\345\277\203X:", nullptr));
        label_56->setText(QApplication::translate("CircleWindowClass", "\345\234\206\345\277\203Y:", nullptr));
        label_57->setText(QApplication::translate("CircleWindowClass", "\345\215\212\345\276\204:", nullptr));
        tabWidget_4->setTabText(tabWidget_4->indexOf(tab_15), QApplication::translate("CircleWindowClass", "\347\273\223\346\236\234", nullptr));
        tabWidget_4->setTabText(tabWidget_4->indexOf(tab_16), QApplication::translate("CircleWindowClass", "\347\202\271\347\273\223\346\236\234", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CircleWindowClass: public Ui_CircleWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CIRCLEWINDOW_H
