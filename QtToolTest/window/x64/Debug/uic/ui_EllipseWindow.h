/********************************************************************************
** Form generated from reading UI file 'EllipseWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ELLIPSEWINDOW_H
#define UI_ELLIPSEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
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

class Ui_EllipseWindowClass
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
    QTabWidget *tabWidget_10;
    QWidget *tab_39;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_187;
    QDoubleSpinBox *dspb_CenterRow_Ellipse;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_189;
    QDoubleSpinBox *dspb_CenterCol_Ellipse;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_190;
    QDoubleSpinBox *dspb_Angle_Ellipse;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_191;
    QDoubleSpinBox *dspb_Radius1_Ellipse;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_192;
    QDoubleSpinBox *dspb_Radius2_Ellipse;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_172;
    QSpinBox *spb_MeasureNum_Ellipse;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_173;
    QSpinBox *spb_MeasureLength1_Ellipse;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_174;
    QSpinBox *spb_MeasureLength2_Ellipse;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_175;
    QDoubleSpinBox *dspb_MeasureSigma_Ellipse;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_176;
    QSpinBox *spb_MeasureThreshold_Ellipse;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_177;
    QComboBox *cmb_MeasureTransition_Ellipse;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_178;
    QComboBox *cmb_MeasureSelect_Ellipse;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_179;
    QDoubleSpinBox *dspb_MinScore_Ellipse;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_180;
    QDoubleSpinBox *dspb_DistanceThreshold_Ellipse;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_181;
    QComboBox *cmb_MeasureInterpolation_Ellipse;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_182;
    QComboBox *cmb_IsFollow_Ellipse;
    QSpacerItem *verticalSpacer_12;
    QHBoxLayout *horizontalLayout_137;
    QPushButton *btn_DrawEllipse_Ellipse;
    QPushButton *btn_DetectEllipse_Ellipse;
    QPushButton *btn_ClearRoi_Ellipse;
    QWidget *tab_40;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_138;
    QHBoxLayout *horizontalLayout_139;
    QPushButton *btn_SaveData_Ellipse;
    QPushButton *btn_LoadData_Ellipse;
    QLabel *lbl_RunCT_Ellipse;
    QSpacerItem *verticalSpacer_13;
    QHBoxLayout *horizontalLayout_141;
    QVBoxLayout *verticalLayout_54;
    QLabel *label_183;
    QLabel *label_184;
    QLabel *label_185;
    QLabel *label_186;
    QLabel *label_188;
    QVBoxLayout *verticalLayout_55;
    QLineEdit *txt_Col_Ellipse;
    QLineEdit *txt_Row_Ellipse;
    QLineEdit *txt_Angle_Ellipse;
    QLineEdit *txt_Radius1_Ellipse;
    QLineEdit *txt_Radius2_Ellipse;
    QWidget *tab_41;
    QTableWidget *tablewidget_PointsResult_Ellipse;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *EllipseWindowClass)
    {
        if (EllipseWindowClass->objectName().isEmpty())
            EllipseWindowClass->setObjectName(QString::fromUtf8("EllipseWindowClass"));
        EllipseWindowClass->resize(1230, 879);
        centralWidget = new QWidget(EllipseWindowClass);
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
        tabWidget_10 = new QTabWidget(centralWidget);
        tabWidget_10->setObjectName(QString::fromUtf8("tabWidget_10"));
        tabWidget_10->setGeometry(QRect(620, 20, 591, 741));
        tab_39 = new QWidget();
        tab_39->setObjectName(QString::fromUtf8("tab_39"));
        layoutWidget = new QWidget(tab_39);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(12, 20, 551, 671));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_187 = new QLabel(layoutWidget);
        label_187->setObjectName(QString::fromUtf8("label_187"));

        horizontalLayout->addWidget(label_187);

        dspb_CenterRow_Ellipse = new QDoubleSpinBox(layoutWidget);
        dspb_CenterRow_Ellipse->setObjectName(QString::fromUtf8("dspb_CenterRow_Ellipse"));
        dspb_CenterRow_Ellipse->setEnabled(false);
        dspb_CenterRow_Ellipse->setDecimals(4);
        dspb_CenterRow_Ellipse->setMinimum(0.000000000000000);
        dspb_CenterRow_Ellipse->setMaximum(999999999.000000000000000);
        dspb_CenterRow_Ellipse->setSingleStep(0.000100000000000);

        horizontalLayout->addWidget(dspb_CenterRow_Ellipse);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_189 = new QLabel(layoutWidget);
        label_189->setObjectName(QString::fromUtf8("label_189"));

        horizontalLayout_2->addWidget(label_189);

        dspb_CenterCol_Ellipse = new QDoubleSpinBox(layoutWidget);
        dspb_CenterCol_Ellipse->setObjectName(QString::fromUtf8("dspb_CenterCol_Ellipse"));
        dspb_CenterCol_Ellipse->setEnabled(false);
        dspb_CenterCol_Ellipse->setDecimals(4);
        dspb_CenterCol_Ellipse->setMinimum(0.000000000000000);
        dspb_CenterCol_Ellipse->setMaximum(999999999.000000000000000);
        dspb_CenterCol_Ellipse->setSingleStep(0.000100000000000);

        horizontalLayout_2->addWidget(dspb_CenterCol_Ellipse);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_190 = new QLabel(layoutWidget);
        label_190->setObjectName(QString::fromUtf8("label_190"));

        horizontalLayout_3->addWidget(label_190);

        dspb_Angle_Ellipse = new QDoubleSpinBox(layoutWidget);
        dspb_Angle_Ellipse->setObjectName(QString::fromUtf8("dspb_Angle_Ellipse"));
        dspb_Angle_Ellipse->setEnabled(false);
        dspb_Angle_Ellipse->setDecimals(4);
        dspb_Angle_Ellipse->setMinimum(-99999.000000000000000);
        dspb_Angle_Ellipse->setMaximum(99999.000000000000000);
        dspb_Angle_Ellipse->setSingleStep(0.000100000000000);

        horizontalLayout_3->addWidget(dspb_Angle_Ellipse);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_191 = new QLabel(layoutWidget);
        label_191->setObjectName(QString::fromUtf8("label_191"));

        horizontalLayout_4->addWidget(label_191);

        dspb_Radius1_Ellipse = new QDoubleSpinBox(layoutWidget);
        dspb_Radius1_Ellipse->setObjectName(QString::fromUtf8("dspb_Radius1_Ellipse"));
        dspb_Radius1_Ellipse->setEnabled(false);
        dspb_Radius1_Ellipse->setDecimals(4);
        dspb_Radius1_Ellipse->setMinimum(0.000000000000000);
        dspb_Radius1_Ellipse->setMaximum(999999999.000000000000000);
        dspb_Radius1_Ellipse->setSingleStep(0.000100000000000);

        horizontalLayout_4->addWidget(dspb_Radius1_Ellipse);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_192 = new QLabel(layoutWidget);
        label_192->setObjectName(QString::fromUtf8("label_192"));

        horizontalLayout_5->addWidget(label_192);

        dspb_Radius2_Ellipse = new QDoubleSpinBox(layoutWidget);
        dspb_Radius2_Ellipse->setObjectName(QString::fromUtf8("dspb_Radius2_Ellipse"));
        dspb_Radius2_Ellipse->setEnabled(false);
        dspb_Radius2_Ellipse->setDecimals(4);
        dspb_Radius2_Ellipse->setMinimum(0.000000000000000);
        dspb_Radius2_Ellipse->setMaximum(999999999.000000000000000);
        dspb_Radius2_Ellipse->setSingleStep(0.000100000000000);

        horizontalLayout_5->addWidget(dspb_Radius2_Ellipse);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_172 = new QLabel(layoutWidget);
        label_172->setObjectName(QString::fromUtf8("label_172"));

        horizontalLayout_6->addWidget(label_172);

        spb_MeasureNum_Ellipse = new QSpinBox(layoutWidget);
        spb_MeasureNum_Ellipse->setObjectName(QString::fromUtf8("spb_MeasureNum_Ellipse"));
        spb_MeasureNum_Ellipse->setMaximum(999999);
        spb_MeasureNum_Ellipse->setValue(30);

        horizontalLayout_6->addWidget(spb_MeasureNum_Ellipse);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_173 = new QLabel(layoutWidget);
        label_173->setObjectName(QString::fromUtf8("label_173"));

        horizontalLayout_7->addWidget(label_173);

        spb_MeasureLength1_Ellipse = new QSpinBox(layoutWidget);
        spb_MeasureLength1_Ellipse->setObjectName(QString::fromUtf8("spb_MeasureLength1_Ellipse"));
        spb_MeasureLength1_Ellipse->setMaximum(999999);
        spb_MeasureLength1_Ellipse->setValue(20);

        horizontalLayout_7->addWidget(spb_MeasureLength1_Ellipse);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_174 = new QLabel(layoutWidget);
        label_174->setObjectName(QString::fromUtf8("label_174"));

        horizontalLayout_8->addWidget(label_174);

        spb_MeasureLength2_Ellipse = new QSpinBox(layoutWidget);
        spb_MeasureLength2_Ellipse->setObjectName(QString::fromUtf8("spb_MeasureLength2_Ellipse"));
        spb_MeasureLength2_Ellipse->setMaximum(999999);
        spb_MeasureLength2_Ellipse->setValue(2);

        horizontalLayout_8->addWidget(spb_MeasureLength2_Ellipse);


        verticalLayout_2->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_175 = new QLabel(layoutWidget);
        label_175->setObjectName(QString::fromUtf8("label_175"));

        horizontalLayout_9->addWidget(label_175);

        dspb_MeasureSigma_Ellipse = new QDoubleSpinBox(layoutWidget);
        dspb_MeasureSigma_Ellipse->setObjectName(QString::fromUtf8("dspb_MeasureSigma_Ellipse"));
        dspb_MeasureSigma_Ellipse->setDecimals(1);
        dspb_MeasureSigma_Ellipse->setMinimum(0.400000000000000);
        dspb_MeasureSigma_Ellipse->setSingleStep(0.100000000000000);

        horizontalLayout_9->addWidget(dspb_MeasureSigma_Ellipse);


        verticalLayout_2->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_176 = new QLabel(layoutWidget);
        label_176->setObjectName(QString::fromUtf8("label_176"));

        horizontalLayout_10->addWidget(label_176);

        spb_MeasureThreshold_Ellipse = new QSpinBox(layoutWidget);
        spb_MeasureThreshold_Ellipse->setObjectName(QString::fromUtf8("spb_MeasureThreshold_Ellipse"));
        spb_MeasureThreshold_Ellipse->setMaximum(255);
        spb_MeasureThreshold_Ellipse->setValue(20);

        horizontalLayout_10->addWidget(spb_MeasureThreshold_Ellipse);


        verticalLayout_2->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_177 = new QLabel(layoutWidget);
        label_177->setObjectName(QString::fromUtf8("label_177"));

        horizontalLayout_11->addWidget(label_177);

        cmb_MeasureTransition_Ellipse = new QComboBox(layoutWidget);
        cmb_MeasureTransition_Ellipse->addItem(QString());
        cmb_MeasureTransition_Ellipse->addItem(QString());
        cmb_MeasureTransition_Ellipse->addItem(QString());
        cmb_MeasureTransition_Ellipse->addItem(QString());
        cmb_MeasureTransition_Ellipse->setObjectName(QString::fromUtf8("cmb_MeasureTransition_Ellipse"));

        horizontalLayout_11->addWidget(cmb_MeasureTransition_Ellipse);


        verticalLayout_2->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label_178 = new QLabel(layoutWidget);
        label_178->setObjectName(QString::fromUtf8("label_178"));

        horizontalLayout_12->addWidget(label_178);

        cmb_MeasureSelect_Ellipse = new QComboBox(layoutWidget);
        cmb_MeasureSelect_Ellipse->addItem(QString());
        cmb_MeasureSelect_Ellipse->addItem(QString());
        cmb_MeasureSelect_Ellipse->addItem(QString());
        cmb_MeasureSelect_Ellipse->setObjectName(QString::fromUtf8("cmb_MeasureSelect_Ellipse"));

        horizontalLayout_12->addWidget(cmb_MeasureSelect_Ellipse);


        verticalLayout_2->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        label_179 = new QLabel(layoutWidget);
        label_179->setObjectName(QString::fromUtf8("label_179"));

        horizontalLayout_13->addWidget(label_179);

        dspb_MinScore_Ellipse = new QDoubleSpinBox(layoutWidget);
        dspb_MinScore_Ellipse->setObjectName(QString::fromUtf8("dspb_MinScore_Ellipse"));
        dspb_MinScore_Ellipse->setDecimals(2);
        dspb_MinScore_Ellipse->setMaximum(1.000000000000000);
        dspb_MinScore_Ellipse->setSingleStep(0.010000000000000);
        dspb_MinScore_Ellipse->setValue(0.550000000000000);

        horizontalLayout_13->addWidget(dspb_MinScore_Ellipse);


        verticalLayout_2->addLayout(horizontalLayout_13);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        label_180 = new QLabel(layoutWidget);
        label_180->setObjectName(QString::fromUtf8("label_180"));

        horizontalLayout_14->addWidget(label_180);

        dspb_DistanceThreshold_Ellipse = new QDoubleSpinBox(layoutWidget);
        dspb_DistanceThreshold_Ellipse->setObjectName(QString::fromUtf8("dspb_DistanceThreshold_Ellipse"));
        dspb_DistanceThreshold_Ellipse->setDecimals(1);
        dspb_DistanceThreshold_Ellipse->setMaximum(100.000000000000000);
        dspb_DistanceThreshold_Ellipse->setSingleStep(0.100000000000000);
        dspb_DistanceThreshold_Ellipse->setValue(3.500000000000000);

        horizontalLayout_14->addWidget(dspb_DistanceThreshold_Ellipse);


        verticalLayout_2->addLayout(horizontalLayout_14);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        label_181 = new QLabel(layoutWidget);
        label_181->setObjectName(QString::fromUtf8("label_181"));

        horizontalLayout_15->addWidget(label_181);

        cmb_MeasureInterpolation_Ellipse = new QComboBox(layoutWidget);
        cmb_MeasureInterpolation_Ellipse->addItem(QString());
        cmb_MeasureInterpolation_Ellipse->addItem(QString());
        cmb_MeasureInterpolation_Ellipse->addItem(QString());
        cmb_MeasureInterpolation_Ellipse->setObjectName(QString::fromUtf8("cmb_MeasureInterpolation_Ellipse"));

        horizontalLayout_15->addWidget(cmb_MeasureInterpolation_Ellipse);


        verticalLayout_2->addLayout(horizontalLayout_15);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        label_182 = new QLabel(layoutWidget);
        label_182->setObjectName(QString::fromUtf8("label_182"));

        horizontalLayout_16->addWidget(label_182);

        cmb_IsFollow_Ellipse = new QComboBox(layoutWidget);
        cmb_IsFollow_Ellipse->addItem(QString());
        cmb_IsFollow_Ellipse->addItem(QString());
        cmb_IsFollow_Ellipse->setObjectName(QString::fromUtf8("cmb_IsFollow_Ellipse"));

        horizontalLayout_16->addWidget(cmb_IsFollow_Ellipse);


        verticalLayout_2->addLayout(horizontalLayout_16);


        verticalLayout_3->addLayout(verticalLayout_2);

        verticalSpacer_12 = new QSpacerItem(20, 128, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_12);

        horizontalLayout_137 = new QHBoxLayout();
        horizontalLayout_137->setSpacing(6);
        horizontalLayout_137->setObjectName(QString::fromUtf8("horizontalLayout_137"));
        btn_DrawEllipse_Ellipse = new QPushButton(layoutWidget);
        btn_DrawEllipse_Ellipse->setObjectName(QString::fromUtf8("btn_DrawEllipse_Ellipse"));

        horizontalLayout_137->addWidget(btn_DrawEllipse_Ellipse);

        btn_DetectEllipse_Ellipse = new QPushButton(layoutWidget);
        btn_DetectEllipse_Ellipse->setObjectName(QString::fromUtf8("btn_DetectEllipse_Ellipse"));

        horizontalLayout_137->addWidget(btn_DetectEllipse_Ellipse);

        btn_ClearRoi_Ellipse = new QPushButton(layoutWidget);
        btn_ClearRoi_Ellipse->setObjectName(QString::fromUtf8("btn_ClearRoi_Ellipse"));

        horizontalLayout_137->addWidget(btn_ClearRoi_Ellipse);


        verticalLayout_3->addLayout(horizontalLayout_137);

        tabWidget_10->addTab(tab_39, QString());
        tab_40 = new QWidget();
        tab_40->setObjectName(QString::fromUtf8("tab_40"));
        layoutWidget1 = new QWidget(tab_40);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(12, 28, 551, 661));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_138 = new QHBoxLayout();
        horizontalLayout_138->setSpacing(6);
        horizontalLayout_138->setObjectName(QString::fromUtf8("horizontalLayout_138"));
        horizontalLayout_139 = new QHBoxLayout();
        horizontalLayout_139->setSpacing(6);
        horizontalLayout_139->setObjectName(QString::fromUtf8("horizontalLayout_139"));
        btn_SaveData_Ellipse = new QPushButton(layoutWidget1);
        btn_SaveData_Ellipse->setObjectName(QString::fromUtf8("btn_SaveData_Ellipse"));

        horizontalLayout_139->addWidget(btn_SaveData_Ellipse);

        btn_LoadData_Ellipse = new QPushButton(layoutWidget1);
        btn_LoadData_Ellipse->setObjectName(QString::fromUtf8("btn_LoadData_Ellipse"));

        horizontalLayout_139->addWidget(btn_LoadData_Ellipse);


        horizontalLayout_138->addLayout(horizontalLayout_139);

        lbl_RunCT_Ellipse = new QLabel(layoutWidget1);
        lbl_RunCT_Ellipse->setObjectName(QString::fromUtf8("lbl_RunCT_Ellipse"));

        horizontalLayout_138->addWidget(lbl_RunCT_Ellipse);


        verticalLayout->addLayout(horizontalLayout_138);

        verticalSpacer_13 = new QSpacerItem(20, 428, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_13);

        horizontalLayout_141 = new QHBoxLayout();
        horizontalLayout_141->setSpacing(6);
        horizontalLayout_141->setObjectName(QString::fromUtf8("horizontalLayout_141"));
        verticalLayout_54 = new QVBoxLayout();
        verticalLayout_54->setSpacing(6);
        verticalLayout_54->setObjectName(QString::fromUtf8("verticalLayout_54"));
        label_183 = new QLabel(layoutWidget1);
        label_183->setObjectName(QString::fromUtf8("label_183"));

        verticalLayout_54->addWidget(label_183);

        label_184 = new QLabel(layoutWidget1);
        label_184->setObjectName(QString::fromUtf8("label_184"));

        verticalLayout_54->addWidget(label_184);

        label_185 = new QLabel(layoutWidget1);
        label_185->setObjectName(QString::fromUtf8("label_185"));

        verticalLayout_54->addWidget(label_185);

        label_186 = new QLabel(layoutWidget1);
        label_186->setObjectName(QString::fromUtf8("label_186"));

        verticalLayout_54->addWidget(label_186);

        label_188 = new QLabel(layoutWidget1);
        label_188->setObjectName(QString::fromUtf8("label_188"));

        verticalLayout_54->addWidget(label_188);


        horizontalLayout_141->addLayout(verticalLayout_54);

        verticalLayout_55 = new QVBoxLayout();
        verticalLayout_55->setSpacing(6);
        verticalLayout_55->setObjectName(QString::fromUtf8("verticalLayout_55"));
        txt_Col_Ellipse = new QLineEdit(layoutWidget1);
        txt_Col_Ellipse->setObjectName(QString::fromUtf8("txt_Col_Ellipse"));
        txt_Col_Ellipse->setReadOnly(true);

        verticalLayout_55->addWidget(txt_Col_Ellipse);

        txt_Row_Ellipse = new QLineEdit(layoutWidget1);
        txt_Row_Ellipse->setObjectName(QString::fromUtf8("txt_Row_Ellipse"));
        txt_Row_Ellipse->setReadOnly(true);

        verticalLayout_55->addWidget(txt_Row_Ellipse);

        txt_Angle_Ellipse = new QLineEdit(layoutWidget1);
        txt_Angle_Ellipse->setObjectName(QString::fromUtf8("txt_Angle_Ellipse"));
        txt_Angle_Ellipse->setReadOnly(true);

        verticalLayout_55->addWidget(txt_Angle_Ellipse);

        txt_Radius1_Ellipse = new QLineEdit(layoutWidget1);
        txt_Radius1_Ellipse->setObjectName(QString::fromUtf8("txt_Radius1_Ellipse"));
        txt_Radius1_Ellipse->setReadOnly(true);

        verticalLayout_55->addWidget(txt_Radius1_Ellipse);

        txt_Radius2_Ellipse = new QLineEdit(layoutWidget1);
        txt_Radius2_Ellipse->setObjectName(QString::fromUtf8("txt_Radius2_Ellipse"));
        txt_Radius2_Ellipse->setReadOnly(true);

        verticalLayout_55->addWidget(txt_Radius2_Ellipse);


        horizontalLayout_141->addLayout(verticalLayout_55);


        verticalLayout->addLayout(horizontalLayout_141);

        tabWidget_10->addTab(tab_40, QString());
        tab_41 = new QWidget();
        tab_41->setObjectName(QString::fromUtf8("tab_41"));
        tablewidget_PointsResult_Ellipse = new QTableWidget(tab_41);
        tablewidget_PointsResult_Ellipse->setObjectName(QString::fromUtf8("tablewidget_PointsResult_Ellipse"));
        tablewidget_PointsResult_Ellipse->setGeometry(QRect(10, 10, 561, 671));
        tabWidget_10->addTab(tab_41, QString());
        EllipseWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(EllipseWindowClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1230, 23));
        EllipseWindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(EllipseWindowClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        EllipseWindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(EllipseWindowClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        EllipseWindowClass->setStatusBar(statusBar);

        retranslateUi(EllipseWindowClass);

        tabWidget_10->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(EllipseWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *EllipseWindowClass)
    {
        EllipseWindowClass->setWindowTitle(QApplication::translate("EllipseWindowClass", "EllipseWindow", nullptr));
        groupBox->setTitle(QApplication::translate("EllipseWindowClass", "\346\230\276\347\244\272\347\252\227\345\217\243", nullptr));
        lbl_Window->setText(QString());
        pBtn_ReadImage->setText(QApplication::translate("EllipseWindowClass", "\346\211\223\345\274\200\345\233\276\347\211\207", nullptr));
        pBtn_FitImage->setText(QApplication::translate("EllipseWindowClass", "\350\207\252\351\200\202\345\272\224", nullptr));
        lbl_Status->setText(QApplication::translate("EllipseWindowClass", "\345\235\220\346\240\207\347\201\260\345\272\246\344\277\241\346\201\257", nullptr));
        btn_ClearWindow->setText(QApplication::translate("EllipseWindowClass", "\346\270\205\347\251\272\347\252\227\345\217\243", nullptr));
        ckb_ShowObj->setText(QApplication::translate("EllipseWindowClass", "\347\274\251\346\224\276\346\227\266\346\230\276\347\244\272\345\233\276\345\275\242", nullptr));
        btn_Hide->setText(QApplication::translate("EllipseWindowClass", "\345\205\263\351\227\255", nullptr));
        label_187->setText(QApplication::translate("EllipseWindowClass", "\344\270\255\345\277\203Row", nullptr));
        label_189->setText(QApplication::translate("EllipseWindowClass", "\344\270\255\345\277\203Col", nullptr));
        label_190->setText(QApplication::translate("EllipseWindowClass", "\350\247\222\345\272\246", nullptr));
        label_191->setText(QApplication::translate("EllipseWindowClass", "\351\225\277\345\215\212\350\275\264", nullptr));
        label_192->setText(QApplication::translate("EllipseWindowClass", "\347\237\255\345\215\212\350\275\264", nullptr));
        label_172->setText(QApplication::translate("EllipseWindowClass", "\345\215\241\345\260\272\346\225\260\351\207\217", nullptr));
        label_173->setText(QApplication::translate("EllipseWindowClass", "\346\220\234\347\264\242\351\225\277\345\272\246", nullptr));
        label_174->setText(QApplication::translate("EllipseWindowClass", "\346\212\225\345\275\261\351\225\277\345\272\246", nullptr));
        label_175->setText(QApplication::translate("EllipseWindowClass", "\345\271\263\346\273\221(Sigma)", nullptr));
        label_176->setText(QApplication::translate("EllipseWindowClass", "\351\230\210\345\200\274", nullptr));
        label_177->setText(QApplication::translate("EllipseWindowClass", "\346\236\201\346\200\247", nullptr));
        cmb_MeasureTransition_Ellipse->setItemText(0, QApplication::translate("EllipseWindowClass", "positive", nullptr));
        cmb_MeasureTransition_Ellipse->setItemText(1, QApplication::translate("EllipseWindowClass", "negative", nullptr));
        cmb_MeasureTransition_Ellipse->setItemText(2, QApplication::translate("EllipseWindowClass", "all", nullptr));
        cmb_MeasureTransition_Ellipse->setItemText(3, QApplication::translate("EllipseWindowClass", "uniform", nullptr));

        label_178->setText(QApplication::translate("EllipseWindowClass", "\350\276\271\347\274\230\351\200\211\345\217\226", nullptr));
        cmb_MeasureSelect_Ellipse->setItemText(0, QApplication::translate("EllipseWindowClass", "first", nullptr));
        cmb_MeasureSelect_Ellipse->setItemText(1, QApplication::translate("EllipseWindowClass", "last", nullptr));
        cmb_MeasureSelect_Ellipse->setItemText(2, QApplication::translate("EllipseWindowClass", "all", nullptr));

        label_179->setText(QApplication::translate("EllipseWindowClass", "\346\234\200\345\260\217\345\276\227\345\210\206", nullptr));
        label_180->setText(QApplication::translate("EllipseWindowClass", "\350\267\235\347\246\273\345\211\224\351\231\244", nullptr));
        label_181->setText(QApplication::translate("EllipseWindowClass", "\346\217\222\345\200\274\347\256\227\346\263\225", nullptr));
        cmb_MeasureInterpolation_Ellipse->setItemText(0, QApplication::translate("EllipseWindowClass", "nearest_neighbor", nullptr));
        cmb_MeasureInterpolation_Ellipse->setItemText(1, QApplication::translate("EllipseWindowClass", "bilinear", nullptr));
        cmb_MeasureInterpolation_Ellipse->setItemText(2, QApplication::translate("EllipseWindowClass", "bicubic", nullptr));

        label_182->setText(QApplication::translate("EllipseWindowClass", "\346\230\257\345\220\246\350\267\237\351\232\217", nullptr));
        cmb_IsFollow_Ellipse->setItemText(0, QApplication::translate("EllipseWindowClass", "No", nullptr));
        cmb_IsFollow_Ellipse->setItemText(1, QApplication::translate("EllipseWindowClass", "Yes", nullptr));

        btn_DrawEllipse_Ellipse->setText(QApplication::translate("EllipseWindowClass", "\347\273\230\345\210\266\346\244\255\345\234\206", nullptr));
        btn_DetectEllipse_Ellipse->setText(QApplication::translate("EllipseWindowClass", "\346\243\200\346\265\213\346\244\255\345\234\206", nullptr));
        btn_ClearRoi_Ellipse->setText(QApplication::translate("EllipseWindowClass", "\346\270\205\351\231\244ROI", nullptr));
        tabWidget_10->setTabText(tabWidget_10->indexOf(tab_39), QApplication::translate("EllipseWindowClass", "\345\215\241\345\260\272\350\256\276\347\275\256", nullptr));
        btn_SaveData_Ellipse->setText(QApplication::translate("EllipseWindowClass", "\345\217\202\346\225\260\344\277\235\345\255\230", nullptr));
        btn_LoadData_Ellipse->setText(QApplication::translate("EllipseWindowClass", "\345\217\202\346\225\260\345\212\240\350\275\275", nullptr));
        lbl_RunCT_Ellipse->setText(QApplication::translate("EllipseWindowClass", "\350\277\220\350\241\214\346\227\266\351\227\264", nullptr));
        label_183->setText(QApplication::translate("EllipseWindowClass", "\344\270\255\347\202\271X:", nullptr));
        label_184->setText(QApplication::translate("EllipseWindowClass", "\344\270\255\347\202\271Y:", nullptr));
        label_185->setText(QApplication::translate("EllipseWindowClass", "\346\227\213\350\275\254\350\247\222\345\272\246:", nullptr));
        label_186->setText(QApplication::translate("EllipseWindowClass", "\351\225\277\345\215\212\350\275\264:", nullptr));
        label_188->setText(QApplication::translate("EllipseWindowClass", "\347\237\255\345\215\212\350\275\264:", nullptr));
        tabWidget_10->setTabText(tabWidget_10->indexOf(tab_40), QApplication::translate("EllipseWindowClass", "\347\273\223\346\236\234", nullptr));
        tabWidget_10->setTabText(tabWidget_10->indexOf(tab_41), QApplication::translate("EllipseWindowClass", "\347\202\271\347\273\223\346\236\234", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EllipseWindowClass: public Ui_EllipseWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ELLIPSEWINDOW_H
