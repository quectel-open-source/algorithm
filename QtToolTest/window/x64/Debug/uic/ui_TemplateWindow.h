/********************************************************************************
** Form generated from reading UI file 'TemplateWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEMPLATEWINDOW_H
#define UI_TEMPLATEWINDOW_H

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

class Ui_TemplateWindowClass
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
    QTabWidget *tabWidget_2;
    QWidget *tab_10;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_28;
    QComboBox *cmb_RoiShape_Template;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_5;
    QPushButton *btn_DrawTrainRoi_Template;
    QPushButton *btn_DrawSearchRoi_Template;
    QPushButton *btn_DrawShaddowRoi_Template;
    QPushButton *btn_UnionRoi_Template;
    QPushButton *btn_ClearRoi_Template;
    QPushButton *btn_Train_Template;
    QSpacerItem *verticalSpacer_2;
    QWidget *tab_7;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_22;
    QLabel *label_23;
    QLabel *label_24;
    QLabel *label_25;
    QLabel *label_27;
    QVBoxLayout *verticalLayout;
    QComboBox *cmb_MatchMethod_Train;
    QSpinBox *spb_NumLevels_Train;
    QDoubleSpinBox *dspb_AngleStart_Train;
    QDoubleSpinBox *dspb_AngleExtent_Train;
    QDoubleSpinBox *dspb_AngleStep_Train;
    QDoubleSpinBox *dspb_ScaleRMin_Train;
    QDoubleSpinBox *dspb_ScaleRMax_Train;
    QDoubleSpinBox *dspb_ScaleRStep_Train;
    QDoubleSpinBox *dspb_ScaleCMin_Train;
    QDoubleSpinBox *dspb_ScaleCMax_Train;
    QDoubleSpinBox *dspb_ScaleCStep_Train;
    QComboBox *cmb_Optimization_Train;
    QComboBox *cmb_Metric_Train;
    QSpinBox *spb_Contrast_Train;
    QSpinBox *spb_MinContrast_Train;
    QDoubleSpinBox *dspb_MinScore_Run;
    QSpinBox *spb_NumMatches_Run;
    QDoubleSpinBox *dspb_MaxOverlap_Run;
    QComboBox *cmb_SubPixel_Run;
    QDoubleSpinBox *dspb_Greediness_Run;
    QWidget *tab_9;
    QWidget *layoutWidget_3;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *btn_FindTemplate;
    QPushButton *btn_SaveTemplateData;
    QPushButton *btn_ReadTemplateData;
    QLabel *lbl_RunTemplateCT;
    QHBoxLayout *horizontalLayout_153;
    QHBoxLayout *horizontalLayout_124;
    QSpacerItem *verticalSpacer_3;
    QTableWidget *tablewidget_Result_Template;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TemplateWindowClass)
    {
        if (TemplateWindowClass->objectName().isEmpty())
            TemplateWindowClass->setObjectName(QString::fromUtf8("TemplateWindowClass"));
        TemplateWindowClass->resize(1249, 825);
        centralWidget = new QWidget(TemplateWindowClass);
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
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(619, 19, 611, 751));
        tabWidget_2 = new QTabWidget(groupBox_2);
        tabWidget_2->setObjectName(QString::fromUtf8("tabWidget_2"));
        tabWidget_2->setGeometry(QRect(10, 20, 591, 721));
        tab_10 = new QWidget();
        tab_10->setObjectName(QString::fromUtf8("tab_10"));
        layoutWidget = new QWidget(tab_10);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 22, 341, 651));
        verticalLayout_6 = new QVBoxLayout(layoutWidget);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_28 = new QLabel(layoutWidget);
        label_28->setObjectName(QString::fromUtf8("label_28"));

        horizontalLayout_5->addWidget(label_28);

        cmb_RoiShape_Template = new QComboBox(layoutWidget);
        cmb_RoiShape_Template->addItem(QString());
        cmb_RoiShape_Template->addItem(QString());
        cmb_RoiShape_Template->addItem(QString());
        cmb_RoiShape_Template->addItem(QString());
        cmb_RoiShape_Template->addItem(QString());
        cmb_RoiShape_Template->setObjectName(QString::fromUtf8("cmb_RoiShape_Template"));

        horizontalLayout_5->addWidget(cmb_RoiShape_Template);


        verticalLayout_6->addLayout(horizontalLayout_5);

        verticalSpacer = new QSpacerItem(20, 78, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        btn_DrawTrainRoi_Template = new QPushButton(layoutWidget);
        btn_DrawTrainRoi_Template->setObjectName(QString::fromUtf8("btn_DrawTrainRoi_Template"));

        verticalLayout_5->addWidget(btn_DrawTrainRoi_Template);

        btn_DrawSearchRoi_Template = new QPushButton(layoutWidget);
        btn_DrawSearchRoi_Template->setObjectName(QString::fromUtf8("btn_DrawSearchRoi_Template"));

        verticalLayout_5->addWidget(btn_DrawSearchRoi_Template);

        btn_DrawShaddowRoi_Template = new QPushButton(layoutWidget);
        btn_DrawShaddowRoi_Template->setObjectName(QString::fromUtf8("btn_DrawShaddowRoi_Template"));

        verticalLayout_5->addWidget(btn_DrawShaddowRoi_Template);

        btn_UnionRoi_Template = new QPushButton(layoutWidget);
        btn_UnionRoi_Template->setObjectName(QString::fromUtf8("btn_UnionRoi_Template"));

        verticalLayout_5->addWidget(btn_UnionRoi_Template);

        btn_ClearRoi_Template = new QPushButton(layoutWidget);
        btn_ClearRoi_Template->setObjectName(QString::fromUtf8("btn_ClearRoi_Template"));

        verticalLayout_5->addWidget(btn_ClearRoi_Template);

        btn_Train_Template = new QPushButton(layoutWidget);
        btn_Train_Template->setObjectName(QString::fromUtf8("btn_Train_Template"));

        verticalLayout_5->addWidget(btn_Train_Template);


        verticalLayout_6->addLayout(verticalLayout_5);

        verticalSpacer_2 = new QSpacerItem(20, 58, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_2);

        tabWidget_2->addTab(tab_10, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName(QString::fromUtf8("tab_7"));
        layoutWidget_2 = new QWidget(tab_7);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(22, 12, 531, 661));
        horizontalLayout = new QHBoxLayout(layoutWidget_2);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(layoutWidget_2);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_2->addWidget(label);

        label_2 = new QLabel(layoutWidget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        label_3 = new QLabel(layoutWidget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_2->addWidget(label_3);

        label_4 = new QLabel(layoutWidget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_2->addWidget(label_4);

        label_5 = new QLabel(layoutWidget_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_2->addWidget(label_5);

        label_6 = new QLabel(layoutWidget_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_2->addWidget(label_6);

        label_7 = new QLabel(layoutWidget_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout_2->addWidget(label_7);

        label_8 = new QLabel(layoutWidget_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout_2->addWidget(label_8);

        label_9 = new QLabel(layoutWidget_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        verticalLayout_2->addWidget(label_9);

        label_10 = new QLabel(layoutWidget_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        verticalLayout_2->addWidget(label_10);

        label_11 = new QLabel(layoutWidget_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        verticalLayout_2->addWidget(label_11);

        label_12 = new QLabel(layoutWidget_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        verticalLayout_2->addWidget(label_12);

        label_13 = new QLabel(layoutWidget_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        verticalLayout_2->addWidget(label_13);

        label_14 = new QLabel(layoutWidget_2);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        verticalLayout_2->addWidget(label_14);

        label_15 = new QLabel(layoutWidget_2);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        verticalLayout_2->addWidget(label_15);

        label_22 = new QLabel(layoutWidget_2);
        label_22->setObjectName(QString::fromUtf8("label_22"));

        verticalLayout_2->addWidget(label_22);

        label_23 = new QLabel(layoutWidget_2);
        label_23->setObjectName(QString::fromUtf8("label_23"));

        verticalLayout_2->addWidget(label_23);

        label_24 = new QLabel(layoutWidget_2);
        label_24->setObjectName(QString::fromUtf8("label_24"));

        verticalLayout_2->addWidget(label_24);

        label_25 = new QLabel(layoutWidget_2);
        label_25->setObjectName(QString::fromUtf8("label_25"));

        verticalLayout_2->addWidget(label_25);

        label_27 = new QLabel(layoutWidget_2);
        label_27->setObjectName(QString::fromUtf8("label_27"));

        verticalLayout_2->addWidget(label_27);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        cmb_MatchMethod_Train = new QComboBox(layoutWidget_2);
        cmb_MatchMethod_Train->addItem(QString());
        cmb_MatchMethod_Train->addItem(QString());
        cmb_MatchMethod_Train->addItem(QString());
        cmb_MatchMethod_Train->addItem(QString());
        cmb_MatchMethod_Train->addItem(QString());
        cmb_MatchMethod_Train->addItem(QString());
        cmb_MatchMethod_Train->addItem(QString());
        cmb_MatchMethod_Train->addItem(QString());
        cmb_MatchMethod_Train->setObjectName(QString::fromUtf8("cmb_MatchMethod_Train"));

        verticalLayout->addWidget(cmb_MatchMethod_Train);

        spb_NumLevels_Train = new QSpinBox(layoutWidget_2);
        spb_NumLevels_Train->setObjectName(QString::fromUtf8("spb_NumLevels_Train"));
        spb_NumLevels_Train->setMinimum(-1);
        spb_NumLevels_Train->setMaximum(10);
        spb_NumLevels_Train->setValue(-1);

        verticalLayout->addWidget(spb_NumLevels_Train);

        dspb_AngleStart_Train = new QDoubleSpinBox(layoutWidget_2);
        dspb_AngleStart_Train->setObjectName(QString::fromUtf8("dspb_AngleStart_Train"));
        dspb_AngleStart_Train->setDecimals(2);
        dspb_AngleStart_Train->setMinimum(-180.000000000000000);
        dspb_AngleStart_Train->setMaximum(0.000000000000000);
        dspb_AngleStart_Train->setSingleStep(0.010000000000000);
        dspb_AngleStart_Train->setValue(-30.000000000000000);

        verticalLayout->addWidget(dspb_AngleStart_Train);

        dspb_AngleExtent_Train = new QDoubleSpinBox(layoutWidget_2);
        dspb_AngleExtent_Train->setObjectName(QString::fromUtf8("dspb_AngleExtent_Train"));
        dspb_AngleExtent_Train->setDecimals(2);
        dspb_AngleExtent_Train->setMaximum(180.000000000000000);
        dspb_AngleExtent_Train->setSingleStep(0.010000000000000);
        dspb_AngleExtent_Train->setValue(30.000000000000000);

        verticalLayout->addWidget(dspb_AngleExtent_Train);

        dspb_AngleStep_Train = new QDoubleSpinBox(layoutWidget_2);
        dspb_AngleStep_Train->setObjectName(QString::fromUtf8("dspb_AngleStep_Train"));
        dspb_AngleStep_Train->setDecimals(4);
        dspb_AngleStep_Train->setMaximum(0.196300000000000);
        dspb_AngleStep_Train->setSingleStep(0.000100000000000);
        dspb_AngleStep_Train->setValue(0.000000000000000);

        verticalLayout->addWidget(dspb_AngleStep_Train);

        dspb_ScaleRMin_Train = new QDoubleSpinBox(layoutWidget_2);
        dspb_ScaleRMin_Train->setObjectName(QString::fromUtf8("dspb_ScaleRMin_Train"));
        dspb_ScaleRMin_Train->setDecimals(1);
        dspb_ScaleRMin_Train->setMaximum(1.000000000000000);
        dspb_ScaleRMin_Train->setSingleStep(0.100000000000000);
        dspb_ScaleRMin_Train->setValue(1.000000000000000);

        verticalLayout->addWidget(dspb_ScaleRMin_Train);

        dspb_ScaleRMax_Train = new QDoubleSpinBox(layoutWidget_2);
        dspb_ScaleRMax_Train->setObjectName(QString::fromUtf8("dspb_ScaleRMax_Train"));
        dspb_ScaleRMax_Train->setDecimals(1);
        dspb_ScaleRMax_Train->setMinimum(1.000000000000000);
        dspb_ScaleRMax_Train->setMaximum(2.000000000000000);
        dspb_ScaleRMax_Train->setSingleStep(0.100000000000000);

        verticalLayout->addWidget(dspb_ScaleRMax_Train);

        dspb_ScaleRStep_Train = new QDoubleSpinBox(layoutWidget_2);
        dspb_ScaleRStep_Train->setObjectName(QString::fromUtf8("dspb_ScaleRStep_Train"));
        dspb_ScaleRStep_Train->setMaximum(1.000000000000000);
        dspb_ScaleRStep_Train->setSingleStep(0.010000000000000);
        dspb_ScaleRStep_Train->setValue(0.000000000000000);

        verticalLayout->addWidget(dspb_ScaleRStep_Train);

        dspb_ScaleCMin_Train = new QDoubleSpinBox(layoutWidget_2);
        dspb_ScaleCMin_Train->setObjectName(QString::fromUtf8("dspb_ScaleCMin_Train"));
        dspb_ScaleCMin_Train->setDecimals(1);
        dspb_ScaleCMin_Train->setMaximum(1.000000000000000);
        dspb_ScaleCMin_Train->setSingleStep(0.100000000000000);
        dspb_ScaleCMin_Train->setValue(1.000000000000000);

        verticalLayout->addWidget(dspb_ScaleCMin_Train);

        dspb_ScaleCMax_Train = new QDoubleSpinBox(layoutWidget_2);
        dspb_ScaleCMax_Train->setObjectName(QString::fromUtf8("dspb_ScaleCMax_Train"));
        dspb_ScaleCMax_Train->setDecimals(1);
        dspb_ScaleCMax_Train->setMinimum(1.000000000000000);
        dspb_ScaleCMax_Train->setMaximum(2.000000000000000);
        dspb_ScaleCMax_Train->setSingleStep(0.100000000000000);

        verticalLayout->addWidget(dspb_ScaleCMax_Train);

        dspb_ScaleCStep_Train = new QDoubleSpinBox(layoutWidget_2);
        dspb_ScaleCStep_Train->setObjectName(QString::fromUtf8("dspb_ScaleCStep_Train"));
        dspb_ScaleCStep_Train->setMaximum(1.000000000000000);
        dspb_ScaleCStep_Train->setSingleStep(0.010000000000000);
        dspb_ScaleCStep_Train->setValue(0.000000000000000);

        verticalLayout->addWidget(dspb_ScaleCStep_Train);

        cmb_Optimization_Train = new QComboBox(layoutWidget_2);
        cmb_Optimization_Train->addItem(QString());
        cmb_Optimization_Train->addItem(QString());
        cmb_Optimization_Train->addItem(QString());
        cmb_Optimization_Train->addItem(QString());
        cmb_Optimization_Train->addItem(QString());
        cmb_Optimization_Train->addItem(QString());
        cmb_Optimization_Train->addItem(QString());
        cmb_Optimization_Train->setObjectName(QString::fromUtf8("cmb_Optimization_Train"));

        verticalLayout->addWidget(cmb_Optimization_Train);

        cmb_Metric_Train = new QComboBox(layoutWidget_2);
        cmb_Metric_Train->addItem(QString());
        cmb_Metric_Train->addItem(QString());
        cmb_Metric_Train->addItem(QString());
        cmb_Metric_Train->addItem(QString());
        cmb_Metric_Train->setObjectName(QString::fromUtf8("cmb_Metric_Train"));

        verticalLayout->addWidget(cmb_Metric_Train);

        spb_Contrast_Train = new QSpinBox(layoutWidget_2);
        spb_Contrast_Train->setObjectName(QString::fromUtf8("spb_Contrast_Train"));
        spb_Contrast_Train->setMaximum(255);
        spb_Contrast_Train->setValue(50);

        verticalLayout->addWidget(spb_Contrast_Train);

        spb_MinContrast_Train = new QSpinBox(layoutWidget_2);
        spb_MinContrast_Train->setObjectName(QString::fromUtf8("spb_MinContrast_Train"));
        spb_MinContrast_Train->setMaximum(255);
        spb_MinContrast_Train->setValue(20);

        verticalLayout->addWidget(spb_MinContrast_Train);

        dspb_MinScore_Run = new QDoubleSpinBox(layoutWidget_2);
        dspb_MinScore_Run->setObjectName(QString::fromUtf8("dspb_MinScore_Run"));
        dspb_MinScore_Run->setMaximum(1.000000000000000);
        dspb_MinScore_Run->setSingleStep(0.010000000000000);
        dspb_MinScore_Run->setValue(0.500000000000000);

        verticalLayout->addWidget(dspb_MinScore_Run);

        spb_NumMatches_Run = new QSpinBox(layoutWidget_2);
        spb_NumMatches_Run->setObjectName(QString::fromUtf8("spb_NumMatches_Run"));
        spb_NumMatches_Run->setMaximum(100);
        spb_NumMatches_Run->setValue(1);

        verticalLayout->addWidget(spb_NumMatches_Run);

        dspb_MaxOverlap_Run = new QDoubleSpinBox(layoutWidget_2);
        dspb_MaxOverlap_Run->setObjectName(QString::fromUtf8("dspb_MaxOverlap_Run"));
        dspb_MaxOverlap_Run->setMaximum(1.000000000000000);
        dspb_MaxOverlap_Run->setSingleStep(0.010000000000000);
        dspb_MaxOverlap_Run->setValue(0.500000000000000);

        verticalLayout->addWidget(dspb_MaxOverlap_Run);

        cmb_SubPixel_Run = new QComboBox(layoutWidget_2);
        cmb_SubPixel_Run->addItem(QString());
        cmb_SubPixel_Run->addItem(QString());
        cmb_SubPixel_Run->addItem(QString());
        cmb_SubPixel_Run->addItem(QString());
        cmb_SubPixel_Run->addItem(QString());
        cmb_SubPixel_Run->setObjectName(QString::fromUtf8("cmb_SubPixel_Run"));

        verticalLayout->addWidget(cmb_SubPixel_Run);

        dspb_Greediness_Run = new QDoubleSpinBox(layoutWidget_2);
        dspb_Greediness_Run->setObjectName(QString::fromUtf8("dspb_Greediness_Run"));
        dspb_Greediness_Run->setMaximum(1.000000000000000);
        dspb_Greediness_Run->setSingleStep(0.010000000000000);
        dspb_Greediness_Run->setValue(0.900000000000000);

        verticalLayout->addWidget(dspb_Greediness_Run);


        horizontalLayout->addLayout(verticalLayout);

        tabWidget_2->addTab(tab_7, QString());
        tab_9 = new QWidget();
        tab_9->setObjectName(QString::fromUtf8("tab_9"));
        layoutWidget_3 = new QWidget(tab_9);
        layoutWidget_3->setObjectName(QString::fromUtf8("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(11, 19, 571, 661));
        gridLayout_2 = new QGridLayout(layoutWidget_3);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        btn_FindTemplate = new QPushButton(layoutWidget_3);
        btn_FindTemplate->setObjectName(QString::fromUtf8("btn_FindTemplate"));

        horizontalLayout_3->addWidget(btn_FindTemplate);

        btn_SaveTemplateData = new QPushButton(layoutWidget_3);
        btn_SaveTemplateData->setObjectName(QString::fromUtf8("btn_SaveTemplateData"));

        horizontalLayout_3->addWidget(btn_SaveTemplateData);

        btn_ReadTemplateData = new QPushButton(layoutWidget_3);
        btn_ReadTemplateData->setObjectName(QString::fromUtf8("btn_ReadTemplateData"));

        horizontalLayout_3->addWidget(btn_ReadTemplateData);


        horizontalLayout_4->addLayout(horizontalLayout_3);

        lbl_RunTemplateCT = new QLabel(layoutWidget_3);
        lbl_RunTemplateCT->setObjectName(QString::fromUtf8("lbl_RunTemplateCT"));

        horizontalLayout_4->addWidget(lbl_RunTemplateCT);


        gridLayout_2->addLayout(horizontalLayout_4, 0, 0, 1, 1);

        horizontalLayout_153 = new QHBoxLayout();
        horizontalLayout_153->setSpacing(6);
        horizontalLayout_153->setObjectName(QString::fromUtf8("horizontalLayout_153"));
        horizontalLayout_124 = new QHBoxLayout();
        horizontalLayout_124->setSpacing(6);
        horizontalLayout_124->setObjectName(QString::fromUtf8("horizontalLayout_124"));

        horizontalLayout_153->addLayout(horizontalLayout_124);


        gridLayout_2->addLayout(horizontalLayout_153, 1, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 88, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_3, 2, 0, 1, 1);

        tablewidget_Result_Template = new QTableWidget(layoutWidget_3);
        tablewidget_Result_Template->setObjectName(QString::fromUtf8("tablewidget_Result_Template"));

        gridLayout_2->addWidget(tablewidget_Result_Template, 3, 0, 1, 1);

        tabWidget_2->addTab(tab_9, QString());
        TemplateWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(TemplateWindowClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1249, 23));
        TemplateWindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TemplateWindowClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        TemplateWindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(TemplateWindowClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        TemplateWindowClass->setStatusBar(statusBar);

        retranslateUi(TemplateWindowClass);

        tabWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(TemplateWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *TemplateWindowClass)
    {
        TemplateWindowClass->setWindowTitle(QApplication::translate("TemplateWindowClass", "TemplateWindow", nullptr));
        groupBox->setTitle(QApplication::translate("TemplateWindowClass", "\346\230\276\347\244\272\347\252\227\345\217\243", nullptr));
        lbl_Window->setText(QString());
        pBtn_ReadImage->setText(QApplication::translate("TemplateWindowClass", "\346\211\223\345\274\200\345\233\276\347\211\207", nullptr));
        pBtn_FitImage->setText(QApplication::translate("TemplateWindowClass", "\350\207\252\351\200\202\345\272\224", nullptr));
        lbl_Status->setText(QApplication::translate("TemplateWindowClass", "\345\235\220\346\240\207\347\201\260\345\272\246\344\277\241\346\201\257", nullptr));
        btn_ClearWindow->setText(QApplication::translate("TemplateWindowClass", "\346\270\205\347\251\272\347\252\227\345\217\243", nullptr));
        ckb_ShowObj->setText(QApplication::translate("TemplateWindowClass", "\347\274\251\346\224\276\346\227\266\346\230\276\347\244\272\345\233\276\345\275\242", nullptr));
        btn_Hide->setText(QApplication::translate("TemplateWindowClass", "\345\205\263\351\227\255", nullptr));
        groupBox_2->setTitle(QApplication::translate("TemplateWindowClass", "\346\223\215\344\275\234\347\252\227\345\217\243", nullptr));
        label_28->setText(QApplication::translate("TemplateWindowClass", "ROI\345\275\242\347\212\266", nullptr));
        cmb_RoiShape_Template->setItemText(0, QApplication::translate("TemplateWindowClass", "rectangle1", nullptr));
        cmb_RoiShape_Template->setItemText(1, QApplication::translate("TemplateWindowClass", "rectangle2", nullptr));
        cmb_RoiShape_Template->setItemText(2, QApplication::translate("TemplateWindowClass", "circle", nullptr));
        cmb_RoiShape_Template->setItemText(3, QApplication::translate("TemplateWindowClass", "ellipse", nullptr));
        cmb_RoiShape_Template->setItemText(4, QApplication::translate("TemplateWindowClass", "polygon", nullptr));

        btn_DrawTrainRoi_Template->setText(QApplication::translate("TemplateWindowClass", "\347\273\230\345\210\266\350\256\255\347\273\203\345\214\272\345\237\237", nullptr));
        btn_DrawSearchRoi_Template->setText(QApplication::translate("TemplateWindowClass", "\347\273\230\345\210\266\346\220\234\347\264\242\345\214\272\345\237\237(\344\270\215\347\273\230\345\210\266\351\273\230\350\256\244\345\205\250\345\233\276\346\220\234\347\264\242)", nullptr));
        btn_DrawShaddowRoi_Template->setText(QApplication::translate("TemplateWindowClass", "\347\273\230\345\210\266\346\216\251\346\250\241\345\214\272\345\237\237(\344\270\215\347\273\230\345\210\266\351\273\230\350\256\244\346\227\240\346\216\251\346\250\241)", nullptr));
        btn_UnionRoi_Template->setText(QApplication::translate("TemplateWindowClass", "\345\220\210\345\271\266ROI", nullptr));
        btn_ClearRoi_Template->setText(QApplication::translate("TemplateWindowClass", "\346\270\205\351\231\244ROI", nullptr));
        btn_Train_Template->setText(QApplication::translate("TemplateWindowClass", "\350\256\255\347\273\203\346\250\241\346\235\277", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_10), QApplication::translate("TemplateWindowClass", "\347\273\230\345\210\266ROI", nullptr));
        label->setText(QApplication::translate("TemplateWindowClass", "\345\214\271\351\205\215\346\226\271\345\274\217", nullptr));
        label_2->setText(QApplication::translate("TemplateWindowClass", "\351\207\221\345\255\227\345\241\224(-1\351\273\230\350\256\244auto)", nullptr));
        label_3->setText(QApplication::translate("TemplateWindowClass", "\350\265\267\345\247\213\350\247\222\345\272\246", nullptr));
        label_4->setText(QApplication::translate("TemplateWindowClass", "\347\273\210\346\255\242\350\247\222\345\272\246", nullptr));
        label_5->setText(QApplication::translate("TemplateWindowClass", "\350\247\222\345\272\246\346\255\245\351\225\277(0\351\273\230\350\256\244auto)", nullptr));
        label_6->setText(QApplication::translate("TemplateWindowClass", "\346\234\200\345\260\217\350\241\214\347\274\251\346\224\276", nullptr));
        label_7->setText(QApplication::translate("TemplateWindowClass", "\346\234\200\345\244\247\350\241\214\347\274\251\346\224\276", nullptr));
        label_8->setText(QApplication::translate("TemplateWindowClass", "\350\241\214\346\226\271\345\220\221\347\274\251\346\224\276\346\255\245\351\225\277(0\351\273\230\350\256\244auto)", nullptr));
        label_9->setText(QApplication::translate("TemplateWindowClass", "\346\234\200\345\260\217\345\210\227\347\274\251\346\224\276", nullptr));
        label_10->setText(QApplication::translate("TemplateWindowClass", "\346\234\200\345\244\247\345\210\227\347\274\251\346\224\276", nullptr));
        label_11->setText(QApplication::translate("TemplateWindowClass", "\345\210\227\346\226\271\345\220\221\347\274\251\346\224\276\346\255\245\351\225\277(0\351\273\230\350\256\244auto)", nullptr));
        label_12->setText(QApplication::translate("TemplateWindowClass", "\344\274\230\345\214\226\347\256\227\346\263\225", nullptr));
        label_13->setText(QApplication::translate("TemplateWindowClass", "\346\236\201\346\200\247", nullptr));
        label_14->setText(QApplication::translate("TemplateWindowClass", "\345\257\271\346\257\224\345\272\246(0\351\273\230\350\256\244auto)", nullptr));
        label_15->setText(QApplication::translate("TemplateWindowClass", "\346\234\200\345\260\217\345\257\271\346\257\224\345\272\246(0\351\273\230\350\256\244auto)", nullptr));
        label_22->setText(QApplication::translate("TemplateWindowClass", "\346\234\200\345\260\217\345\210\206\346\225\260", nullptr));
        label_23->setText(QApplication::translate("TemplateWindowClass", "\345\214\271\351\205\215\344\270\252\346\225\260", nullptr));
        label_24->setText(QApplication::translate("TemplateWindowClass", "\346\234\200\345\244\247\351\207\215\345\217\240", nullptr));
        label_25->setText(QApplication::translate("TemplateWindowClass", "\344\272\232\345\203\217\347\264\240", nullptr));
        label_27->setText(QApplication::translate("TemplateWindowClass", "\350\264\252\345\251\252\347\263\273\346\225\260", nullptr));
        cmb_MatchMethod_Train->setItemText(0, QApplication::translate("TemplateWindowClass", "\345\237\272\344\272\216\345\275\242\347\212\266\346\227\240\347\274\251\346\224\276", nullptr));
        cmb_MatchMethod_Train->setItemText(1, QApplication::translate("TemplateWindowClass", "\345\237\272\344\272\216\345\275\242\347\212\266\346\227\240\347\274\251\346\224\276\350\207\252\345\212\250\345\217\202\346\225\260", nullptr));
        cmb_MatchMethod_Train->setItemText(2, QApplication::translate("TemplateWindowClass", "\345\237\272\344\272\216\345\275\242\347\212\266\345\220\214\346\255\245\347\274\251\346\224\276", nullptr));
        cmb_MatchMethod_Train->setItemText(3, QApplication::translate("TemplateWindowClass", "\345\237\272\344\272\216\345\275\242\347\212\266\345\220\214\346\255\245\347\274\251\346\224\276\350\207\252\345\212\250\345\217\202\346\225\260", nullptr));
        cmb_MatchMethod_Train->setItemText(4, QApplication::translate("TemplateWindowClass", "\345\237\272\344\272\216\345\275\242\347\212\266\345\274\202\346\255\245\347\274\251\346\224\276", nullptr));
        cmb_MatchMethod_Train->setItemText(5, QApplication::translate("TemplateWindowClass", "\345\237\272\344\272\216\345\275\242\347\212\266\345\274\202\346\255\245\347\274\251\346\224\276\350\207\252\345\212\250\345\217\202\346\225\260", nullptr));
        cmb_MatchMethod_Train->setItemText(6, QApplication::translate("TemplateWindowClass", "\345\237\272\344\272\216\344\272\222\347\233\270\345\205\263", nullptr));
        cmb_MatchMethod_Train->setItemText(7, QApplication::translate("TemplateWindowClass", "\345\237\272\344\272\216\344\272\222\347\233\270\345\205\263\350\207\252\345\212\250\345\217\202\346\225\260", nullptr));

        cmb_Optimization_Train->setItemText(0, QApplication::translate("TemplateWindowClass", "auto", nullptr));
        cmb_Optimization_Train->setItemText(1, QApplication::translate("TemplateWindowClass", "no_pregeneration", nullptr));
        cmb_Optimization_Train->setItemText(2, QApplication::translate("TemplateWindowClass", "none", nullptr));
        cmb_Optimization_Train->setItemText(3, QApplication::translate("TemplateWindowClass", "point_reduction_high", nullptr));
        cmb_Optimization_Train->setItemText(4, QApplication::translate("TemplateWindowClass", "point_reduction_low", nullptr));
        cmb_Optimization_Train->setItemText(5, QApplication::translate("TemplateWindowClass", "point_reduction_medium", nullptr));
        cmb_Optimization_Train->setItemText(6, QApplication::translate("TemplateWindowClass", "pregeneration", nullptr));

        cmb_Metric_Train->setItemText(0, QApplication::translate("TemplateWindowClass", "use_polarity", nullptr));
        cmb_Metric_Train->setItemText(1, QApplication::translate("TemplateWindowClass", "ignore_color_polarity", nullptr));
        cmb_Metric_Train->setItemText(2, QApplication::translate("TemplateWindowClass", "ignore_global_polarity", nullptr));
        cmb_Metric_Train->setItemText(3, QApplication::translate("TemplateWindowClass", "ignore_local_polarity", nullptr));

        cmb_SubPixel_Run->setItemText(0, QApplication::translate("TemplateWindowClass", "none", nullptr));
        cmb_SubPixel_Run->setItemText(1, QApplication::translate("TemplateWindowClass", "interpolation", nullptr));
        cmb_SubPixel_Run->setItemText(2, QApplication::translate("TemplateWindowClass", "least_squares", nullptr));
        cmb_SubPixel_Run->setItemText(3, QApplication::translate("TemplateWindowClass", "least_squares_high", nullptr));
        cmb_SubPixel_Run->setItemText(4, QApplication::translate("TemplateWindowClass", "least_squares_very_high", nullptr));

        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_7), QApplication::translate("TemplateWindowClass", "\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        btn_FindTemplate->setText(QApplication::translate("TemplateWindowClass", "\346\237\245\346\211\276\346\250\241\346\235\277", nullptr));
        btn_SaveTemplateData->setText(QApplication::translate("TemplateWindowClass", "\345\217\202\346\225\260\344\277\235\345\255\230", nullptr));
        btn_ReadTemplateData->setText(QApplication::translate("TemplateWindowClass", "\345\217\202\346\225\260\345\212\240\350\275\275", nullptr));
        lbl_RunTemplateCT->setText(QApplication::translate("TemplateWindowClass", "\350\277\220\350\241\214\346\227\266\351\227\264", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_9), QApplication::translate("TemplateWindowClass", "\347\273\223\346\236\234", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TemplateWindowClass: public Ui_TemplateWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEMPLATEWINDOW_H
