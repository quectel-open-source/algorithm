/********************************************************************************
** Form generated from reading UI file 'LineWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LINEWINDOW_H
#define UI_LINEWINDOW_H

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

class Ui_LineWindowClass
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
    QTabWidget *tabWidget_3;
    QWidget *tab_11;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_38;
    QDoubleSpinBox *dspb_RowBegin_Line;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_39;
    QDoubleSpinBox *dspb_ColBegin_Line;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_40;
    QDoubleSpinBox *dspb_RowEnd_Line;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_41;
    QDoubleSpinBox *dspb_ColEnd_Line;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_31;
    QSpinBox *spb_MeasureNum_Line;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_29;
    QSpinBox *spb_MeasureLength1_Line;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_30;
    QSpinBox *spb_MeasureLength2_Line;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_32;
    QDoubleSpinBox *dspb_MeasureSigma_Line;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_33;
    QSpinBox *spb_MeasureThreshold_Line;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_34;
    QComboBox *cmb_MeasureTransition_Line;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_35;
    QComboBox *cmb_MeasureSelect_Line;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_36;
    QDoubleSpinBox *dspb_MinScore_Line;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_47;
    QDoubleSpinBox *dspb_DistanceThreshold_Line;
    QHBoxLayout *horizontalLayout_18;
    QLabel *label_37;
    QComboBox *cmb_MeasureInterpolation_Line;
    QHBoxLayout *horizontalLayout_19;
    QLabel *label_49;
    QComboBox *cmb_IsFollow_Line;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *btn_DrawLine_Line;
    QPushButton *btn_DetectLine_Line;
    QPushButton *btn_ClearRoi_Line;
    QWidget *tab_12;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_14;
    QHBoxLayout *horizontalLayout_11;
    QPushButton *btn_SaveLineData;
    QPushButton *btn_LoadLineData;
    QLabel *lbl_RunLineCT;
    QSpacerItem *verticalSpacer_6;
    QHBoxLayout *horizontalLayout_10;
    QVBoxLayout *verticalLayout_11;
    QLabel *label_50;
    QLabel *label_51;
    QLabel *label_52;
    QLabel *label_53;
    QVBoxLayout *verticalLayout_12;
    QLineEdit *txt_Col1_Line;
    QLineEdit *txt_Row1_Line;
    QLineEdit *txt_Col2_Line;
    QLineEdit *txt_Row2_Line;
    QWidget *tab_13;
    QTableWidget *tablewidget_PointsResult_Line;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *LineWindowClass)
    {
        if (LineWindowClass->objectName().isEmpty())
            LineWindowClass->setObjectName(QString::fromUtf8("LineWindowClass"));
        LineWindowClass->resize(1242, 890);
        centralWidget = new QWidget(LineWindowClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(9, 9, 609, 815));
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
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(624, 9, 609, 815));
        tabWidget_3 = new QTabWidget(groupBox_2);
        tabWidget_3->setObjectName(QString::fromUtf8("tabWidget_3"));
        tabWidget_3->setGeometry(QRect(10, 30, 571, 771));
        tab_11 = new QWidget();
        tab_11->setObjectName(QString::fromUtf8("tab_11"));
        gridLayout = new QGridLayout(tab_11);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_38 = new QLabel(tab_11);
        label_38->setObjectName(QString::fromUtf8("label_38"));

        horizontalLayout->addWidget(label_38);

        dspb_RowBegin_Line = new QDoubleSpinBox(tab_11);
        dspb_RowBegin_Line->setObjectName(QString::fromUtf8("dspb_RowBegin_Line"));
        dspb_RowBegin_Line->setEnabled(false);
        dspb_RowBegin_Line->setDecimals(4);
        dspb_RowBegin_Line->setMaximum(999999999.000000000000000);
        dspb_RowBegin_Line->setSingleStep(0.000100000000000);

        horizontalLayout->addWidget(dspb_RowBegin_Line);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_39 = new QLabel(tab_11);
        label_39->setObjectName(QString::fromUtf8("label_39"));

        horizontalLayout_2->addWidget(label_39);

        dspb_ColBegin_Line = new QDoubleSpinBox(tab_11);
        dspb_ColBegin_Line->setObjectName(QString::fromUtf8("dspb_ColBegin_Line"));
        dspb_ColBegin_Line->setEnabled(false);
        dspb_ColBegin_Line->setDecimals(4);
        dspb_ColBegin_Line->setMaximum(999999999.000000000000000);
        dspb_ColBegin_Line->setSingleStep(0.000100000000000);

        horizontalLayout_2->addWidget(dspb_ColBegin_Line);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_40 = new QLabel(tab_11);
        label_40->setObjectName(QString::fromUtf8("label_40"));

        horizontalLayout_3->addWidget(label_40);

        dspb_RowEnd_Line = new QDoubleSpinBox(tab_11);
        dspb_RowEnd_Line->setObjectName(QString::fromUtf8("dspb_RowEnd_Line"));
        dspb_RowEnd_Line->setEnabled(false);
        dspb_RowEnd_Line->setDecimals(4);
        dspb_RowEnd_Line->setMaximum(999999999.000000000000000);
        dspb_RowEnd_Line->setSingleStep(0.000100000000000);

        horizontalLayout_3->addWidget(dspb_RowEnd_Line);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_41 = new QLabel(tab_11);
        label_41->setObjectName(QString::fromUtf8("label_41"));

        horizontalLayout_4->addWidget(label_41);

        dspb_ColEnd_Line = new QDoubleSpinBox(tab_11);
        dspb_ColEnd_Line->setObjectName(QString::fromUtf8("dspb_ColEnd_Line"));
        dspb_ColEnd_Line->setEnabled(false);
        dspb_ColEnd_Line->setDecimals(4);
        dspb_ColEnd_Line->setMaximum(999999999.000000000000000);
        dspb_ColEnd_Line->setSingleStep(0.000100000000000);

        horizontalLayout_4->addWidget(dspb_ColEnd_Line);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_31 = new QLabel(tab_11);
        label_31->setObjectName(QString::fromUtf8("label_31"));

        horizontalLayout_5->addWidget(label_31);

        spb_MeasureNum_Line = new QSpinBox(tab_11);
        spb_MeasureNum_Line->setObjectName(QString::fromUtf8("spb_MeasureNum_Line"));
        spb_MeasureNum_Line->setMaximum(999999);
        spb_MeasureNum_Line->setValue(10);

        horizontalLayout_5->addWidget(spb_MeasureNum_Line);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_29 = new QLabel(tab_11);
        label_29->setObjectName(QString::fromUtf8("label_29"));

        horizontalLayout_6->addWidget(label_29);

        spb_MeasureLength1_Line = new QSpinBox(tab_11);
        spb_MeasureLength1_Line->setObjectName(QString::fromUtf8("spb_MeasureLength1_Line"));
        spb_MeasureLength1_Line->setMaximum(999999);
        spb_MeasureLength1_Line->setValue(100);

        horizontalLayout_6->addWidget(spb_MeasureLength1_Line);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_30 = new QLabel(tab_11);
        label_30->setObjectName(QString::fromUtf8("label_30"));

        horizontalLayout_8->addWidget(label_30);

        spb_MeasureLength2_Line = new QSpinBox(tab_11);
        spb_MeasureLength2_Line->setObjectName(QString::fromUtf8("spb_MeasureLength2_Line"));
        spb_MeasureLength2_Line->setMaximum(999999);
        spb_MeasureLength2_Line->setValue(10);

        horizontalLayout_8->addWidget(spb_MeasureLength2_Line);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_32 = new QLabel(tab_11);
        label_32->setObjectName(QString::fromUtf8("label_32"));

        horizontalLayout_9->addWidget(label_32);

        dspb_MeasureSigma_Line = new QDoubleSpinBox(tab_11);
        dspb_MeasureSigma_Line->setObjectName(QString::fromUtf8("dspb_MeasureSigma_Line"));
        dspb_MeasureSigma_Line->setDecimals(1);
        dspb_MeasureSigma_Line->setMinimum(0.400000000000000);
        dspb_MeasureSigma_Line->setSingleStep(0.100000000000000);

        horizontalLayout_9->addWidget(dspb_MeasureSigma_Line);


        verticalLayout->addLayout(horizontalLayout_9);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label_33 = new QLabel(tab_11);
        label_33->setObjectName(QString::fromUtf8("label_33"));

        horizontalLayout_12->addWidget(label_33);

        spb_MeasureThreshold_Line = new QSpinBox(tab_11);
        spb_MeasureThreshold_Line->setObjectName(QString::fromUtf8("spb_MeasureThreshold_Line"));
        spb_MeasureThreshold_Line->setMaximum(255);
        spb_MeasureThreshold_Line->setValue(20);

        horizontalLayout_12->addWidget(spb_MeasureThreshold_Line);


        verticalLayout->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        label_34 = new QLabel(tab_11);
        label_34->setObjectName(QString::fromUtf8("label_34"));

        horizontalLayout_13->addWidget(label_34);

        cmb_MeasureTransition_Line = new QComboBox(tab_11);
        cmb_MeasureTransition_Line->addItem(QString());
        cmb_MeasureTransition_Line->addItem(QString());
        cmb_MeasureTransition_Line->addItem(QString());
        cmb_MeasureTransition_Line->addItem(QString());
        cmb_MeasureTransition_Line->setObjectName(QString::fromUtf8("cmb_MeasureTransition_Line"));

        horizontalLayout_13->addWidget(cmb_MeasureTransition_Line);


        verticalLayout->addLayout(horizontalLayout_13);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        label_35 = new QLabel(tab_11);
        label_35->setObjectName(QString::fromUtf8("label_35"));

        horizontalLayout_15->addWidget(label_35);

        cmb_MeasureSelect_Line = new QComboBox(tab_11);
        cmb_MeasureSelect_Line->addItem(QString());
        cmb_MeasureSelect_Line->addItem(QString());
        cmb_MeasureSelect_Line->addItem(QString());
        cmb_MeasureSelect_Line->setObjectName(QString::fromUtf8("cmb_MeasureSelect_Line"));

        horizontalLayout_15->addWidget(cmb_MeasureSelect_Line);


        verticalLayout->addLayout(horizontalLayout_15);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        label_36 = new QLabel(tab_11);
        label_36->setObjectName(QString::fromUtf8("label_36"));

        horizontalLayout_16->addWidget(label_36);

        dspb_MinScore_Line = new QDoubleSpinBox(tab_11);
        dspb_MinScore_Line->setObjectName(QString::fromUtf8("dspb_MinScore_Line"));
        dspb_MinScore_Line->setDecimals(2);
        dspb_MinScore_Line->setMaximum(1.000000000000000);
        dspb_MinScore_Line->setSingleStep(0.010000000000000);
        dspb_MinScore_Line->setValue(0.550000000000000);

        horizontalLayout_16->addWidget(dspb_MinScore_Line);


        verticalLayout->addLayout(horizontalLayout_16);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setSpacing(6);
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        label_47 = new QLabel(tab_11);
        label_47->setObjectName(QString::fromUtf8("label_47"));

        horizontalLayout_17->addWidget(label_47);

        dspb_DistanceThreshold_Line = new QDoubleSpinBox(tab_11);
        dspb_DistanceThreshold_Line->setObjectName(QString::fromUtf8("dspb_DistanceThreshold_Line"));
        dspb_DistanceThreshold_Line->setDecimals(1);
        dspb_DistanceThreshold_Line->setMaximum(100.000000000000000);
        dspb_DistanceThreshold_Line->setSingleStep(0.100000000000000);
        dspb_DistanceThreshold_Line->setValue(3.500000000000000);

        horizontalLayout_17->addWidget(dspb_DistanceThreshold_Line);


        verticalLayout->addLayout(horizontalLayout_17);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setSpacing(6);
        horizontalLayout_18->setObjectName(QString::fromUtf8("horizontalLayout_18"));
        label_37 = new QLabel(tab_11);
        label_37->setObjectName(QString::fromUtf8("label_37"));

        horizontalLayout_18->addWidget(label_37);

        cmb_MeasureInterpolation_Line = new QComboBox(tab_11);
        cmb_MeasureInterpolation_Line->addItem(QString());
        cmb_MeasureInterpolation_Line->addItem(QString());
        cmb_MeasureInterpolation_Line->addItem(QString());
        cmb_MeasureInterpolation_Line->setObjectName(QString::fromUtf8("cmb_MeasureInterpolation_Line"));

        horizontalLayout_18->addWidget(cmb_MeasureInterpolation_Line);


        verticalLayout->addLayout(horizontalLayout_18);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setSpacing(6);
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));
        label_49 = new QLabel(tab_11);
        label_49->setObjectName(QString::fromUtf8("label_49"));

        horizontalLayout_19->addWidget(label_49);

        cmb_IsFollow_Line = new QComboBox(tab_11);
        cmb_IsFollow_Line->addItem(QString());
        cmb_IsFollow_Line->addItem(QString());
        cmb_IsFollow_Line->setObjectName(QString::fromUtf8("cmb_IsFollow_Line"));

        horizontalLayout_19->addWidget(cmb_IsFollow_Line);


        verticalLayout->addLayout(horizontalLayout_19);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 272, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_4, 1, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        btn_DrawLine_Line = new QPushButton(tab_11);
        btn_DrawLine_Line->setObjectName(QString::fromUtf8("btn_DrawLine_Line"));

        horizontalLayout_7->addWidget(btn_DrawLine_Line);

        btn_DetectLine_Line = new QPushButton(tab_11);
        btn_DetectLine_Line->setObjectName(QString::fromUtf8("btn_DetectLine_Line"));

        horizontalLayout_7->addWidget(btn_DetectLine_Line);

        btn_ClearRoi_Line = new QPushButton(tab_11);
        btn_ClearRoi_Line->setObjectName(QString::fromUtf8("btn_ClearRoi_Line"));

        horizontalLayout_7->addWidget(btn_ClearRoi_Line);


        gridLayout->addLayout(horizontalLayout_7, 2, 0, 1, 1);

        tabWidget_3->addTab(tab_11, QString());
        tab_12 = new QWidget();
        tab_12->setObjectName(QString::fromUtf8("tab_12"));
        widget = new QWidget(tab_12);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(14, 27, 531, 641));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        btn_SaveLineData = new QPushButton(widget);
        btn_SaveLineData->setObjectName(QString::fromUtf8("btn_SaveLineData"));

        horizontalLayout_11->addWidget(btn_SaveLineData);

        btn_LoadLineData = new QPushButton(widget);
        btn_LoadLineData->setObjectName(QString::fromUtf8("btn_LoadLineData"));

        horizontalLayout_11->addWidget(btn_LoadLineData);


        horizontalLayout_14->addLayout(horizontalLayout_11);

        lbl_RunLineCT = new QLabel(widget);
        lbl_RunLineCT->setObjectName(QString::fromUtf8("lbl_RunLineCT"));

        horizontalLayout_14->addWidget(lbl_RunLineCT);


        verticalLayout_2->addLayout(horizontalLayout_14);

        verticalSpacer_6 = new QSpacerItem(20, 288, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_6);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        label_50 = new QLabel(widget);
        label_50->setObjectName(QString::fromUtf8("label_50"));

        verticalLayout_11->addWidget(label_50);

        label_51 = new QLabel(widget);
        label_51->setObjectName(QString::fromUtf8("label_51"));

        verticalLayout_11->addWidget(label_51);

        label_52 = new QLabel(widget);
        label_52->setObjectName(QString::fromUtf8("label_52"));

        verticalLayout_11->addWidget(label_52);

        label_53 = new QLabel(widget);
        label_53->setObjectName(QString::fromUtf8("label_53"));

        verticalLayout_11->addWidget(label_53);


        horizontalLayout_10->addLayout(verticalLayout_11);

        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setSpacing(6);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        txt_Col1_Line = new QLineEdit(widget);
        txt_Col1_Line->setObjectName(QString::fromUtf8("txt_Col1_Line"));
        txt_Col1_Line->setReadOnly(true);

        verticalLayout_12->addWidget(txt_Col1_Line);

        txt_Row1_Line = new QLineEdit(widget);
        txt_Row1_Line->setObjectName(QString::fromUtf8("txt_Row1_Line"));
        txt_Row1_Line->setReadOnly(true);

        verticalLayout_12->addWidget(txt_Row1_Line);

        txt_Col2_Line = new QLineEdit(widget);
        txt_Col2_Line->setObjectName(QString::fromUtf8("txt_Col2_Line"));
        txt_Col2_Line->setReadOnly(true);

        verticalLayout_12->addWidget(txt_Col2_Line);

        txt_Row2_Line = new QLineEdit(widget);
        txt_Row2_Line->setObjectName(QString::fromUtf8("txt_Row2_Line"));
        txt_Row2_Line->setReadOnly(true);

        verticalLayout_12->addWidget(txt_Row2_Line);


        horizontalLayout_10->addLayout(verticalLayout_12);


        verticalLayout_2->addLayout(horizontalLayout_10);

        tabWidget_3->addTab(tab_12, QString());
        tab_13 = new QWidget();
        tab_13->setObjectName(QString::fromUtf8("tab_13"));
        tablewidget_PointsResult_Line = new QTableWidget(tab_13);
        tablewidget_PointsResult_Line->setObjectName(QString::fromUtf8("tablewidget_PointsResult_Line"));
        tablewidget_PointsResult_Line->setGeometry(QRect(10, 10, 561, 671));
        tabWidget_3->addTab(tab_13, QString());
        LineWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(LineWindowClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1242, 23));
        LineWindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(LineWindowClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        LineWindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(LineWindowClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        LineWindowClass->setStatusBar(statusBar);

        retranslateUi(LineWindowClass);

        tabWidget_3->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(LineWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *LineWindowClass)
    {
        LineWindowClass->setWindowTitle(QApplication::translate("LineWindowClass", "LineWindow", nullptr));
        groupBox->setTitle(QApplication::translate("LineWindowClass", "\346\230\276\347\244\272\347\252\227\345\217\243", nullptr));
        lbl_Window->setText(QString());
        pBtn_ReadImage->setText(QApplication::translate("LineWindowClass", "\346\211\223\345\274\200\345\233\276\347\211\207", nullptr));
        pBtn_FitImage->setText(QApplication::translate("LineWindowClass", "\350\207\252\351\200\202\345\272\224", nullptr));
        lbl_Status->setText(QApplication::translate("LineWindowClass", "\345\235\220\346\240\207\347\201\260\345\272\246\344\277\241\346\201\257", nullptr));
        btn_ClearWindow->setText(QApplication::translate("LineWindowClass", "\346\270\205\347\251\272\347\252\227\345\217\243", nullptr));
        ckb_ShowObj->setText(QApplication::translate("LineWindowClass", "\347\274\251\346\224\276\346\227\266\346\230\276\347\244\272\345\233\276\345\275\242", nullptr));
        btn_Hide->setText(QApplication::translate("LineWindowClass", "\345\205\263\351\227\255", nullptr));
        groupBox_2->setTitle(QApplication::translate("LineWindowClass", "\346\223\215\344\275\234\347\252\227\345\217\243", nullptr));
        label_38->setText(QApplication::translate("LineWindowClass", "\350\265\267\347\202\271Row", nullptr));
        label_39->setText(QApplication::translate("LineWindowClass", "\350\265\267\347\202\271Col", nullptr));
        label_40->setText(QApplication::translate("LineWindowClass", "\347\273\210\347\202\271Row", nullptr));
        label_41->setText(QApplication::translate("LineWindowClass", "\347\273\210\347\202\271Col", nullptr));
        label_31->setText(QApplication::translate("LineWindowClass", "\345\215\241\345\260\272\346\225\260\351\207\217", nullptr));
        label_29->setText(QApplication::translate("LineWindowClass", "\346\220\234\347\264\242\351\225\277\345\272\246", nullptr));
        label_30->setText(QApplication::translate("LineWindowClass", "\346\212\225\345\275\261\351\225\277\345\272\246", nullptr));
        label_32->setText(QApplication::translate("LineWindowClass", "\345\271\263\346\273\221(Sigma)", nullptr));
        label_33->setText(QApplication::translate("LineWindowClass", "\351\230\210\345\200\274", nullptr));
        label_34->setText(QApplication::translate("LineWindowClass", "\346\236\201\346\200\247", nullptr));
        cmb_MeasureTransition_Line->setItemText(0, QApplication::translate("LineWindowClass", "positive", nullptr));
        cmb_MeasureTransition_Line->setItemText(1, QApplication::translate("LineWindowClass", "negative", nullptr));
        cmb_MeasureTransition_Line->setItemText(2, QApplication::translate("LineWindowClass", "all", nullptr));
        cmb_MeasureTransition_Line->setItemText(3, QApplication::translate("LineWindowClass", "uniform", nullptr));

        label_35->setText(QApplication::translate("LineWindowClass", "\350\276\271\347\274\230\351\200\211\345\217\226", nullptr));
        cmb_MeasureSelect_Line->setItemText(0, QApplication::translate("LineWindowClass", "first", nullptr));
        cmb_MeasureSelect_Line->setItemText(1, QApplication::translate("LineWindowClass", "last", nullptr));
        cmb_MeasureSelect_Line->setItemText(2, QApplication::translate("LineWindowClass", "all", nullptr));

        label_36->setText(QApplication::translate("LineWindowClass", "\346\234\200\345\260\217\345\276\227\345\210\206", nullptr));
        label_47->setText(QApplication::translate("LineWindowClass", "\350\267\235\347\246\273\345\211\224\351\231\244", nullptr));
        label_37->setText(QApplication::translate("LineWindowClass", "\346\217\222\345\200\274\347\256\227\346\263\225", nullptr));
        cmb_MeasureInterpolation_Line->setItemText(0, QApplication::translate("LineWindowClass", "nearest_neighbor", nullptr));
        cmb_MeasureInterpolation_Line->setItemText(1, QApplication::translate("LineWindowClass", "bilinear", nullptr));
        cmb_MeasureInterpolation_Line->setItemText(2, QApplication::translate("LineWindowClass", "bicubic", nullptr));

        label_49->setText(QApplication::translate("LineWindowClass", "\346\230\257\345\220\246\350\267\237\351\232\217", nullptr));
        cmb_IsFollow_Line->setItemText(0, QApplication::translate("LineWindowClass", "No", nullptr));
        cmb_IsFollow_Line->setItemText(1, QApplication::translate("LineWindowClass", "Yes", nullptr));

        btn_DrawLine_Line->setText(QApplication::translate("LineWindowClass", "\347\273\230\345\210\266\347\233\264\347\272\277", nullptr));
        btn_DetectLine_Line->setText(QApplication::translate("LineWindowClass", "\346\243\200\346\265\213\347\233\264\347\272\277", nullptr));
        btn_ClearRoi_Line->setText(QApplication::translate("LineWindowClass", "\346\270\205\351\231\244ROI", nullptr));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_11), QApplication::translate("LineWindowClass", "\345\215\241\345\260\272\350\256\276\347\275\256", nullptr));
        btn_SaveLineData->setText(QApplication::translate("LineWindowClass", "\345\217\202\346\225\260\344\277\235\345\255\230", nullptr));
        btn_LoadLineData->setText(QApplication::translate("LineWindowClass", "\345\217\202\346\225\260\345\212\240\350\275\275", nullptr));
        lbl_RunLineCT->setText(QApplication::translate("LineWindowClass", "\350\277\220\350\241\214\346\227\266\351\227\264", nullptr));
        label_50->setText(QApplication::translate("LineWindowClass", "\350\265\267\347\202\271X:", nullptr));
        label_51->setText(QApplication::translate("LineWindowClass", "\350\265\267\347\202\271Y:", nullptr));
        label_52->setText(QApplication::translate("LineWindowClass", "\347\273\210\347\202\271X:", nullptr));
        label_53->setText(QApplication::translate("LineWindowClass", "\347\273\210\347\202\271Y:", nullptr));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_12), QApplication::translate("LineWindowClass", "\347\273\223\346\236\234", nullptr));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_13), QApplication::translate("LineWindowClass", "\347\202\271\347\273\223\346\236\234", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LineWindowClass: public Ui_LineWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LINEWINDOW_H
