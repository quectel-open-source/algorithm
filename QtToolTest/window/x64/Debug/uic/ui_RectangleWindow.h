/********************************************************************************
** Form generated from reading UI file 'RectangleWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECTANGLEWINDOW_H
#define UI_RECTANGLEWINDOW_H

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

class Ui_RectangleWindowClass
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
    QTabWidget *tabWidget_9;
    QWidget *tab_36;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_172;
    QDoubleSpinBox *dspb_CenterRow_Rectangle;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_173;
    QDoubleSpinBox *dspb_CenterCol_Rectangle;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_174;
    QDoubleSpinBox *dspb_Angle_Rectangle;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_175;
    QDoubleSpinBox *dspb_Len1_Rectangle;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_176;
    QDoubleSpinBox *dspb_Len2_Rectangle;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_157;
    QSpinBox *spb_MeasureNum_Rectangle;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_158;
    QSpinBox *spb_MeasureLength1_Rectangle;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_159;
    QSpinBox *spb_MeasureLength2_Rectangle;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_160;
    QDoubleSpinBox *dspb_MeasureSigma_Rectangle;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_161;
    QSpinBox *spb_MeasureThreshold_Rectangle;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_162;
    QComboBox *cmb_MeasureTransition_Rectangle;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_163;
    QComboBox *cmb_MeasureSelect_Rectangle;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_164;
    QDoubleSpinBox *dspb_MinScore_Rectangle;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_165;
    QDoubleSpinBox *dspb_DistanceThreshold_Rectangle;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_166;
    QComboBox *cmb_MeasureInterpolation_Rectangle;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_167;
    QComboBox *cmb_IsFollow_Rectangle;
    QSpacerItem *verticalSpacer_10;
    QHBoxLayout *horizontalLayout_132;
    QPushButton *btn_DrawRectangle_Rectangle;
    QPushButton *btn_DetectRectangle_Rectangle;
    QPushButton *btn_ClearRoi_Rectangle;
    QWidget *tab_37;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_133;
    QHBoxLayout *horizontalLayout_134;
    QPushButton *btn_SaveData_Rectangle;
    QPushButton *btn_LoadData_Rectangle;
    QLabel *lbl_RunCT_Rectangle;
    QSpacerItem *verticalSpacer_11;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_168;
    QLabel *label_169;
    QLabel *label_170;
    QLabel *label_171;
    QLabel *label_187;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *txt_Col_Rectangle;
    QLineEdit *txt_Row_Rectangle;
    QLineEdit *txt_Angle_Rectangle;
    QLineEdit *txt_Len1_Rectangle;
    QLineEdit *txt_Len2_Rectangle;
    QWidget *tab_38;
    QTableWidget *tablewidget_PointsResult_Rectangle;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *RectangleWindowClass)
    {
        if (RectangleWindowClass->objectName().isEmpty())
            RectangleWindowClass->setObjectName(QString::fromUtf8("RectangleWindowClass"));
        RectangleWindowClass->resize(1218, 880);
        centralWidget = new QWidget(RectangleWindowClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 20, 591, 751));
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
        tabWidget_9 = new QTabWidget(centralWidget);
        tabWidget_9->setObjectName(QString::fromUtf8("tabWidget_9"));
        tabWidget_9->setGeometry(QRect(610, 30, 581, 731));
        tab_36 = new QWidget();
        tab_36->setObjectName(QString::fromUtf8("tab_36"));
        gridLayout = new QGridLayout(tab_36);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_172 = new QLabel(tab_36);
        label_172->setObjectName(QString::fromUtf8("label_172"));

        horizontalLayout->addWidget(label_172);

        dspb_CenterRow_Rectangle = new QDoubleSpinBox(tab_36);
        dspb_CenterRow_Rectangle->setObjectName(QString::fromUtf8("dspb_CenterRow_Rectangle"));
        dspb_CenterRow_Rectangle->setEnabled(false);
        dspb_CenterRow_Rectangle->setDecimals(4);
        dspb_CenterRow_Rectangle->setMinimum(0.000000000000000);
        dspb_CenterRow_Rectangle->setMaximum(999999999.000000000000000);
        dspb_CenterRow_Rectangle->setSingleStep(0.000100000000000);

        horizontalLayout->addWidget(dspb_CenterRow_Rectangle);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_173 = new QLabel(tab_36);
        label_173->setObjectName(QString::fromUtf8("label_173"));

        horizontalLayout_3->addWidget(label_173);

        dspb_CenterCol_Rectangle = new QDoubleSpinBox(tab_36);
        dspb_CenterCol_Rectangle->setObjectName(QString::fromUtf8("dspb_CenterCol_Rectangle"));
        dspb_CenterCol_Rectangle->setEnabled(false);
        dspb_CenterCol_Rectangle->setDecimals(4);
        dspb_CenterCol_Rectangle->setMinimum(0.000000000000000);
        dspb_CenterCol_Rectangle->setMaximum(999999999.000000000000000);
        dspb_CenterCol_Rectangle->setSingleStep(0.000100000000000);

        horizontalLayout_3->addWidget(dspb_CenterCol_Rectangle);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_174 = new QLabel(tab_36);
        label_174->setObjectName(QString::fromUtf8("label_174"));

        horizontalLayout_4->addWidget(label_174);

        dspb_Angle_Rectangle = new QDoubleSpinBox(tab_36);
        dspb_Angle_Rectangle->setObjectName(QString::fromUtf8("dspb_Angle_Rectangle"));
        dspb_Angle_Rectangle->setEnabled(false);
        dspb_Angle_Rectangle->setDecimals(4);
        dspb_Angle_Rectangle->setMinimum(-99999.000000000000000);
        dspb_Angle_Rectangle->setMaximum(99999.000000000000000);
        dspb_Angle_Rectangle->setSingleStep(0.000100000000000);

        horizontalLayout_4->addWidget(dspb_Angle_Rectangle);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_175 = new QLabel(tab_36);
        label_175->setObjectName(QString::fromUtf8("label_175"));

        horizontalLayout_5->addWidget(label_175);

        dspb_Len1_Rectangle = new QDoubleSpinBox(tab_36);
        dspb_Len1_Rectangle->setObjectName(QString::fromUtf8("dspb_Len1_Rectangle"));
        dspb_Len1_Rectangle->setEnabled(false);
        dspb_Len1_Rectangle->setDecimals(4);
        dspb_Len1_Rectangle->setMinimum(0.000000000000000);
        dspb_Len1_Rectangle->setMaximum(999999999.000000000000000);
        dspb_Len1_Rectangle->setSingleStep(0.000100000000000);

        horizontalLayout_5->addWidget(dspb_Len1_Rectangle);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_176 = new QLabel(tab_36);
        label_176->setObjectName(QString::fromUtf8("label_176"));

        horizontalLayout_6->addWidget(label_176);

        dspb_Len2_Rectangle = new QDoubleSpinBox(tab_36);
        dspb_Len2_Rectangle->setObjectName(QString::fromUtf8("dspb_Len2_Rectangle"));
        dspb_Len2_Rectangle->setEnabled(false);
        dspb_Len2_Rectangle->setDecimals(4);
        dspb_Len2_Rectangle->setMinimum(0.000000000000000);
        dspb_Len2_Rectangle->setMaximum(999999999.000000000000000);
        dspb_Len2_Rectangle->setSingleStep(0.000100000000000);

        horizontalLayout_6->addWidget(dspb_Len2_Rectangle);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_157 = new QLabel(tab_36);
        label_157->setObjectName(QString::fromUtf8("label_157"));

        horizontalLayout_7->addWidget(label_157);

        spb_MeasureNum_Rectangle = new QSpinBox(tab_36);
        spb_MeasureNum_Rectangle->setObjectName(QString::fromUtf8("spb_MeasureNum_Rectangle"));
        spb_MeasureNum_Rectangle->setMaximum(999999);
        spb_MeasureNum_Rectangle->setValue(40);

        horizontalLayout_7->addWidget(spb_MeasureNum_Rectangle);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_158 = new QLabel(tab_36);
        label_158->setObjectName(QString::fromUtf8("label_158"));

        horizontalLayout_8->addWidget(label_158);

        spb_MeasureLength1_Rectangle = new QSpinBox(tab_36);
        spb_MeasureLength1_Rectangle->setObjectName(QString::fromUtf8("spb_MeasureLength1_Rectangle"));
        spb_MeasureLength1_Rectangle->setMaximum(999999);
        spb_MeasureLength1_Rectangle->setValue(20);

        horizontalLayout_8->addWidget(spb_MeasureLength1_Rectangle);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_159 = new QLabel(tab_36);
        label_159->setObjectName(QString::fromUtf8("label_159"));

        horizontalLayout_9->addWidget(label_159);

        spb_MeasureLength2_Rectangle = new QSpinBox(tab_36);
        spb_MeasureLength2_Rectangle->setObjectName(QString::fromUtf8("spb_MeasureLength2_Rectangle"));
        spb_MeasureLength2_Rectangle->setMaximum(999999);
        spb_MeasureLength2_Rectangle->setValue(2);

        horizontalLayout_9->addWidget(spb_MeasureLength2_Rectangle);


        verticalLayout->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_160 = new QLabel(tab_36);
        label_160->setObjectName(QString::fromUtf8("label_160"));

        horizontalLayout_10->addWidget(label_160);

        dspb_MeasureSigma_Rectangle = new QDoubleSpinBox(tab_36);
        dspb_MeasureSigma_Rectangle->setObjectName(QString::fromUtf8("dspb_MeasureSigma_Rectangle"));
        dspb_MeasureSigma_Rectangle->setDecimals(1);
        dspb_MeasureSigma_Rectangle->setMinimum(0.400000000000000);
        dspb_MeasureSigma_Rectangle->setSingleStep(0.100000000000000);

        horizontalLayout_10->addWidget(dspb_MeasureSigma_Rectangle);


        verticalLayout->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_161 = new QLabel(tab_36);
        label_161->setObjectName(QString::fromUtf8("label_161"));

        horizontalLayout_11->addWidget(label_161);

        spb_MeasureThreshold_Rectangle = new QSpinBox(tab_36);
        spb_MeasureThreshold_Rectangle->setObjectName(QString::fromUtf8("spb_MeasureThreshold_Rectangle"));
        spb_MeasureThreshold_Rectangle->setMaximum(255);
        spb_MeasureThreshold_Rectangle->setValue(10);

        horizontalLayout_11->addWidget(spb_MeasureThreshold_Rectangle);


        verticalLayout->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label_162 = new QLabel(tab_36);
        label_162->setObjectName(QString::fromUtf8("label_162"));

        horizontalLayout_12->addWidget(label_162);

        cmb_MeasureTransition_Rectangle = new QComboBox(tab_36);
        cmb_MeasureTransition_Rectangle->addItem(QString());
        cmb_MeasureTransition_Rectangle->addItem(QString());
        cmb_MeasureTransition_Rectangle->addItem(QString());
        cmb_MeasureTransition_Rectangle->addItem(QString());
        cmb_MeasureTransition_Rectangle->setObjectName(QString::fromUtf8("cmb_MeasureTransition_Rectangle"));

        horizontalLayout_12->addWidget(cmb_MeasureTransition_Rectangle);


        verticalLayout->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        label_163 = new QLabel(tab_36);
        label_163->setObjectName(QString::fromUtf8("label_163"));

        horizontalLayout_13->addWidget(label_163);

        cmb_MeasureSelect_Rectangle = new QComboBox(tab_36);
        cmb_MeasureSelect_Rectangle->addItem(QString());
        cmb_MeasureSelect_Rectangle->addItem(QString());
        cmb_MeasureSelect_Rectangle->addItem(QString());
        cmb_MeasureSelect_Rectangle->setObjectName(QString::fromUtf8("cmb_MeasureSelect_Rectangle"));

        horizontalLayout_13->addWidget(cmb_MeasureSelect_Rectangle);


        verticalLayout->addLayout(horizontalLayout_13);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        label_164 = new QLabel(tab_36);
        label_164->setObjectName(QString::fromUtf8("label_164"));

        horizontalLayout_14->addWidget(label_164);

        dspb_MinScore_Rectangle = new QDoubleSpinBox(tab_36);
        dspb_MinScore_Rectangle->setObjectName(QString::fromUtf8("dspb_MinScore_Rectangle"));
        dspb_MinScore_Rectangle->setDecimals(2);
        dspb_MinScore_Rectangle->setMaximum(1.000000000000000);
        dspb_MinScore_Rectangle->setSingleStep(0.010000000000000);
        dspb_MinScore_Rectangle->setValue(0.550000000000000);

        horizontalLayout_14->addWidget(dspb_MinScore_Rectangle);


        verticalLayout->addLayout(horizontalLayout_14);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        label_165 = new QLabel(tab_36);
        label_165->setObjectName(QString::fromUtf8("label_165"));

        horizontalLayout_15->addWidget(label_165);

        dspb_DistanceThreshold_Rectangle = new QDoubleSpinBox(tab_36);
        dspb_DistanceThreshold_Rectangle->setObjectName(QString::fromUtf8("dspb_DistanceThreshold_Rectangle"));
        dspb_DistanceThreshold_Rectangle->setDecimals(1);
        dspb_DistanceThreshold_Rectangle->setMaximum(100.000000000000000);
        dspb_DistanceThreshold_Rectangle->setSingleStep(0.100000000000000);
        dspb_DistanceThreshold_Rectangle->setValue(3.500000000000000);

        horizontalLayout_15->addWidget(dspb_DistanceThreshold_Rectangle);


        verticalLayout->addLayout(horizontalLayout_15);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        label_166 = new QLabel(tab_36);
        label_166->setObjectName(QString::fromUtf8("label_166"));

        horizontalLayout_16->addWidget(label_166);

        cmb_MeasureInterpolation_Rectangle = new QComboBox(tab_36);
        cmb_MeasureInterpolation_Rectangle->addItem(QString());
        cmb_MeasureInterpolation_Rectangle->addItem(QString());
        cmb_MeasureInterpolation_Rectangle->addItem(QString());
        cmb_MeasureInterpolation_Rectangle->setObjectName(QString::fromUtf8("cmb_MeasureInterpolation_Rectangle"));

        horizontalLayout_16->addWidget(cmb_MeasureInterpolation_Rectangle);


        verticalLayout->addLayout(horizontalLayout_16);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setSpacing(6);
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        label_167 = new QLabel(tab_36);
        label_167->setObjectName(QString::fromUtf8("label_167"));

        horizontalLayout_17->addWidget(label_167);

        cmb_IsFollow_Rectangle = new QComboBox(tab_36);
        cmb_IsFollow_Rectangle->addItem(QString());
        cmb_IsFollow_Rectangle->addItem(QString());
        cmb_IsFollow_Rectangle->setObjectName(QString::fromUtf8("cmb_IsFollow_Rectangle"));

        horizontalLayout_17->addWidget(cmb_IsFollow_Rectangle);


        verticalLayout->addLayout(horizontalLayout_17);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        verticalSpacer_10 = new QSpacerItem(20, 204, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_10, 1, 0, 1, 1);

        horizontalLayout_132 = new QHBoxLayout();
        horizontalLayout_132->setSpacing(6);
        horizontalLayout_132->setObjectName(QString::fromUtf8("horizontalLayout_132"));
        btn_DrawRectangle_Rectangle = new QPushButton(tab_36);
        btn_DrawRectangle_Rectangle->setObjectName(QString::fromUtf8("btn_DrawRectangle_Rectangle"));

        horizontalLayout_132->addWidget(btn_DrawRectangle_Rectangle);

        btn_DetectRectangle_Rectangle = new QPushButton(tab_36);
        btn_DetectRectangle_Rectangle->setObjectName(QString::fromUtf8("btn_DetectRectangle_Rectangle"));

        horizontalLayout_132->addWidget(btn_DetectRectangle_Rectangle);

        btn_ClearRoi_Rectangle = new QPushButton(tab_36);
        btn_ClearRoi_Rectangle->setObjectName(QString::fromUtf8("btn_ClearRoi_Rectangle"));

        horizontalLayout_132->addWidget(btn_ClearRoi_Rectangle);


        gridLayout->addLayout(horizontalLayout_132, 2, 0, 1, 1);

        tabWidget_9->addTab(tab_36, QString());
        tab_37 = new QWidget();
        tab_37->setObjectName(QString::fromUtf8("tab_37"));
        widget = new QWidget(tab_37);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(12, 28, 541, 651));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_133 = new QHBoxLayout();
        horizontalLayout_133->setSpacing(6);
        horizontalLayout_133->setObjectName(QString::fromUtf8("horizontalLayout_133"));
        horizontalLayout_134 = new QHBoxLayout();
        horizontalLayout_134->setSpacing(6);
        horizontalLayout_134->setObjectName(QString::fromUtf8("horizontalLayout_134"));
        btn_SaveData_Rectangle = new QPushButton(widget);
        btn_SaveData_Rectangle->setObjectName(QString::fromUtf8("btn_SaveData_Rectangle"));

        horizontalLayout_134->addWidget(btn_SaveData_Rectangle);

        btn_LoadData_Rectangle = new QPushButton(widget);
        btn_LoadData_Rectangle->setObjectName(QString::fromUtf8("btn_LoadData_Rectangle"));

        horizontalLayout_134->addWidget(btn_LoadData_Rectangle);


        horizontalLayout_133->addLayout(horizontalLayout_134);

        lbl_RunCT_Rectangle = new QLabel(widget);
        lbl_RunCT_Rectangle->setObjectName(QString::fromUtf8("lbl_RunCT_Rectangle"));

        horizontalLayout_133->addWidget(lbl_RunCT_Rectangle);


        verticalLayout_2->addLayout(horizontalLayout_133);

        verticalSpacer_11 = new QSpacerItem(20, 428, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_11);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_168 = new QLabel(widget);
        label_168->setObjectName(QString::fromUtf8("label_168"));

        verticalLayout_4->addWidget(label_168);

        label_169 = new QLabel(widget);
        label_169->setObjectName(QString::fromUtf8("label_169"));

        verticalLayout_4->addWidget(label_169);

        label_170 = new QLabel(widget);
        label_170->setObjectName(QString::fromUtf8("label_170"));

        verticalLayout_4->addWidget(label_170);

        label_171 = new QLabel(widget);
        label_171->setObjectName(QString::fromUtf8("label_171"));

        verticalLayout_4->addWidget(label_171);

        label_187 = new QLabel(widget);
        label_187->setObjectName(QString::fromUtf8("label_187"));

        verticalLayout_4->addWidget(label_187);


        horizontalLayout_2->addLayout(verticalLayout_4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        txt_Col_Rectangle = new QLineEdit(widget);
        txt_Col_Rectangle->setObjectName(QString::fromUtf8("txt_Col_Rectangle"));
        txt_Col_Rectangle->setReadOnly(true);

        verticalLayout_3->addWidget(txt_Col_Rectangle);

        txt_Row_Rectangle = new QLineEdit(widget);
        txt_Row_Rectangle->setObjectName(QString::fromUtf8("txt_Row_Rectangle"));
        txt_Row_Rectangle->setReadOnly(true);

        verticalLayout_3->addWidget(txt_Row_Rectangle);

        txt_Angle_Rectangle = new QLineEdit(widget);
        txt_Angle_Rectangle->setObjectName(QString::fromUtf8("txt_Angle_Rectangle"));
        txt_Angle_Rectangle->setReadOnly(true);

        verticalLayout_3->addWidget(txt_Angle_Rectangle);

        txt_Len1_Rectangle = new QLineEdit(widget);
        txt_Len1_Rectangle->setObjectName(QString::fromUtf8("txt_Len1_Rectangle"));
        txt_Len1_Rectangle->setReadOnly(true);

        verticalLayout_3->addWidget(txt_Len1_Rectangle);

        txt_Len2_Rectangle = new QLineEdit(widget);
        txt_Len2_Rectangle->setObjectName(QString::fromUtf8("txt_Len2_Rectangle"));
        txt_Len2_Rectangle->setReadOnly(true);

        verticalLayout_3->addWidget(txt_Len2_Rectangle);


        horizontalLayout_2->addLayout(verticalLayout_3);


        verticalLayout_2->addLayout(horizontalLayout_2);

        tabWidget_9->addTab(tab_37, QString());
        tab_38 = new QWidget();
        tab_38->setObjectName(QString::fromUtf8("tab_38"));
        tablewidget_PointsResult_Rectangle = new QTableWidget(tab_38);
        tablewidget_PointsResult_Rectangle->setObjectName(QString::fromUtf8("tablewidget_PointsResult_Rectangle"));
        tablewidget_PointsResult_Rectangle->setGeometry(QRect(10, 10, 561, 671));
        tabWidget_9->addTab(tab_38, QString());
        RectangleWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(RectangleWindowClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1218, 23));
        RectangleWindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(RectangleWindowClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        RectangleWindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(RectangleWindowClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        RectangleWindowClass->setStatusBar(statusBar);

        retranslateUi(RectangleWindowClass);

        tabWidget_9->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(RectangleWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *RectangleWindowClass)
    {
        RectangleWindowClass->setWindowTitle(QApplication::translate("RectangleWindowClass", "RectangleWindow", nullptr));
        groupBox->setTitle(QApplication::translate("RectangleWindowClass", "\346\230\276\347\244\272\347\252\227\345\217\243", nullptr));
        lbl_Window->setText(QString());
        pBtn_ReadImage->setText(QApplication::translate("RectangleWindowClass", "\346\211\223\345\274\200\345\233\276\347\211\207", nullptr));
        pBtn_FitImage->setText(QApplication::translate("RectangleWindowClass", "\350\207\252\351\200\202\345\272\224", nullptr));
        lbl_Status->setText(QApplication::translate("RectangleWindowClass", "\345\235\220\346\240\207\347\201\260\345\272\246\344\277\241\346\201\257", nullptr));
        btn_ClearWindow->setText(QApplication::translate("RectangleWindowClass", "\346\270\205\347\251\272\347\252\227\345\217\243", nullptr));
        ckb_ShowObj->setText(QApplication::translate("RectangleWindowClass", "\347\274\251\346\224\276\346\227\266\346\230\276\347\244\272\345\233\276\345\275\242", nullptr));
        btn_Hide->setText(QApplication::translate("RectangleWindowClass", "\345\205\263\351\227\255", nullptr));
        label_172->setText(QApplication::translate("RectangleWindowClass", "\344\270\255\345\277\203Row", nullptr));
        label_173->setText(QApplication::translate("RectangleWindowClass", "\344\270\255\345\277\203Col", nullptr));
        label_174->setText(QApplication::translate("RectangleWindowClass", "\350\247\222\345\272\246", nullptr));
        label_175->setText(QApplication::translate("RectangleWindowClass", "\345\215\212\351\225\277", nullptr));
        label_176->setText(QApplication::translate("RectangleWindowClass", "\345\215\212\345\256\275", nullptr));
        label_157->setText(QApplication::translate("RectangleWindowClass", "\345\215\241\345\260\272\346\225\260\351\207\217", nullptr));
        label_158->setText(QApplication::translate("RectangleWindowClass", "\346\220\234\347\264\242\351\225\277\345\272\246", nullptr));
        label_159->setText(QApplication::translate("RectangleWindowClass", "\346\212\225\345\275\261\351\225\277\345\272\246", nullptr));
        label_160->setText(QApplication::translate("RectangleWindowClass", "\345\271\263\346\273\221(Sigma)", nullptr));
        label_161->setText(QApplication::translate("RectangleWindowClass", "\351\230\210\345\200\274", nullptr));
        label_162->setText(QApplication::translate("RectangleWindowClass", "\346\236\201\346\200\247", nullptr));
        cmb_MeasureTransition_Rectangle->setItemText(0, QApplication::translate("RectangleWindowClass", "positive", nullptr));
        cmb_MeasureTransition_Rectangle->setItemText(1, QApplication::translate("RectangleWindowClass", "negative", nullptr));
        cmb_MeasureTransition_Rectangle->setItemText(2, QApplication::translate("RectangleWindowClass", "all", nullptr));
        cmb_MeasureTransition_Rectangle->setItemText(3, QApplication::translate("RectangleWindowClass", "uniform", nullptr));

        label_163->setText(QApplication::translate("RectangleWindowClass", "\350\276\271\347\274\230\351\200\211\345\217\226", nullptr));
        cmb_MeasureSelect_Rectangle->setItemText(0, QApplication::translate("RectangleWindowClass", "first", nullptr));
        cmb_MeasureSelect_Rectangle->setItemText(1, QApplication::translate("RectangleWindowClass", "last", nullptr));
        cmb_MeasureSelect_Rectangle->setItemText(2, QApplication::translate("RectangleWindowClass", "all", nullptr));

        label_164->setText(QApplication::translate("RectangleWindowClass", "\346\234\200\345\260\217\345\276\227\345\210\206", nullptr));
        label_165->setText(QApplication::translate("RectangleWindowClass", "\350\267\235\347\246\273\345\211\224\351\231\244", nullptr));
        label_166->setText(QApplication::translate("RectangleWindowClass", "\346\217\222\345\200\274\347\256\227\346\263\225", nullptr));
        cmb_MeasureInterpolation_Rectangle->setItemText(0, QApplication::translate("RectangleWindowClass", "nearest_neighbor", nullptr));
        cmb_MeasureInterpolation_Rectangle->setItemText(1, QApplication::translate("RectangleWindowClass", "bilinear", nullptr));
        cmb_MeasureInterpolation_Rectangle->setItemText(2, QApplication::translate("RectangleWindowClass", "bicubic", nullptr));

        label_167->setText(QApplication::translate("RectangleWindowClass", "\346\230\257\345\220\246\350\267\237\351\232\217", nullptr));
        cmb_IsFollow_Rectangle->setItemText(0, QApplication::translate("RectangleWindowClass", "No", nullptr));
        cmb_IsFollow_Rectangle->setItemText(1, QApplication::translate("RectangleWindowClass", "Yes", nullptr));

        btn_DrawRectangle_Rectangle->setText(QApplication::translate("RectangleWindowClass", "\347\273\230\345\210\266\347\237\251\345\275\242", nullptr));
        btn_DetectRectangle_Rectangle->setText(QApplication::translate("RectangleWindowClass", "\346\243\200\346\265\213\347\237\251\345\275\242", nullptr));
        btn_ClearRoi_Rectangle->setText(QApplication::translate("RectangleWindowClass", "\346\270\205\351\231\244ROI", nullptr));
        tabWidget_9->setTabText(tabWidget_9->indexOf(tab_36), QApplication::translate("RectangleWindowClass", "\345\215\241\345\260\272\350\256\276\347\275\256", nullptr));
        btn_SaveData_Rectangle->setText(QApplication::translate("RectangleWindowClass", "\345\217\202\346\225\260\344\277\235\345\255\230", nullptr));
        btn_LoadData_Rectangle->setText(QApplication::translate("RectangleWindowClass", "\345\217\202\346\225\260\345\212\240\350\275\275", nullptr));
        lbl_RunCT_Rectangle->setText(QApplication::translate("RectangleWindowClass", "\350\277\220\350\241\214\346\227\266\351\227\264", nullptr));
        label_168->setText(QApplication::translate("RectangleWindowClass", "\344\270\255\347\202\271X:", nullptr));
        label_169->setText(QApplication::translate("RectangleWindowClass", "\344\270\255\347\202\271Y:", nullptr));
        label_170->setText(QApplication::translate("RectangleWindowClass", "\346\227\213\350\275\254\350\247\222\345\272\246:", nullptr));
        label_171->setText(QApplication::translate("RectangleWindowClass", "\345\215\212\351\225\277:", nullptr));
        label_187->setText(QApplication::translate("RectangleWindowClass", "\345\215\212\345\256\275:", nullptr));
        tabWidget_9->setTabText(tabWidget_9->indexOf(tab_37), QApplication::translate("RectangleWindowClass", "\347\273\223\346\236\234", nullptr));
        tabWidget_9->setTabText(tabWidget_9->indexOf(tab_38), QApplication::translate("RectangleWindowClass", "\347\202\271\347\273\223\346\236\234", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RectangleWindowClass: public Ui_RectangleWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECTANGLEWINDOW_H
