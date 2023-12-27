#pragma once
#pragma execution_character_set("utf-8")

#include <QMainWindow>
#include "ui_TemplateWindow.h"
#include <QSettings>
#include <QVector>
#include <QDebug>
#include <QMessageBox>
#include <QFileDialog>
#include <QFileInfo>
//#include <QtConcurrent>
#include <qdatetime.h>
#include <Halcon.h>
#include <halconcpp/HalconCpp.h>
#include "../detect/TemplateDetect.h"

class TemplateWindow : public QMainWindow
{
	Q_OBJECT

public:
	TemplateWindow(QWidget *parent = nullptr);
	TemplateWindow(HObject image, int _processID, int modubleID, std::string _modubleName, std::string configPath);
	~TemplateWindow();

private:
	//初始化显示窗口
	void InitWindow();
	//显示图片(hv_FillType 可以选择margin或者fill)
	void showImg(const HObject &ho_Img, HTuple hv_FillType, HTuple hv_Color);
	//给窗口刷新图像传递参数(主要作用是为了滚轮缩放时显示图形)
	void GiveParameterToWindow();
	//**********************************************************************************************
	//模板匹配用函数
	//模板类对象初始化
	void IniTemplateClassObject();
	//模板匹配参数结构体参数赋值函数
	void SetRunParams_Template(RunParamsStruct_Template &runParams);

	//初始化模板显示表格
	void IniTableData_Template();
	//设置模板显示表格数据
	void SetTableData_Template(const ResultParamsStruct_Template &resultStruct, qint64 Ct);
	//更新模板训练参数和运行参数窗口
	void UpdateTemplateDataWindow(const RunParamsStruct_Template &RunParams);
	//******************************************************************************************************

private slots:
	//打开图片
	void on_pBtn_ReadImage_clicked();
	//图像自适应
	void on_pBtn_FitImage_clicked();
	//清空窗口
	void on_btn_ClearWindow_clicked();
	//是否显示图形复选框
	void on_ckb_ShowObj_stateChanged(int arg1);
	//关闭窗口
	void on_btn_Hide_clicked();
	//***************************************************************************
	//模板匹配用槽函数
	//Roi区域形状选择
	void on_cmb_RoiShape_Template_activated(const QString &arg1);
	//模板匹配类型选择
	void on_cmb_MatchMethod_Train_activated(const QString &arg1);
	//绘制模板训练区域
	void on_btn_DrawTrainRoi_Template_clicked();
	//绘制模板搜索区域
	void on_btn_DrawSearchRoi_Template_clicked();
	//绘制掩模区域
	void on_btn_DrawShaddowRoi_Template_clicked();
	//合并模板区域Roi
	void on_btn_UnionRoi_Template_clicked();
	//清除模板区域Roi
	void on_btn_ClearRoi_Template_clicked();
	//训练模板
	void on_btn_Train_Template_clicked();
	//查找模板
	void on_btn_FindTemplate_clicked();
	//模板参数保存
	void on_btn_SaveTemplateData_clicked();
	//模板参数读取
	void on_btn_ReadTemplateData_clicked();
	//*****************************************************************************
	//查找模板槽函数
	int slot_FindTemplate(ResultParamsStruct_Template &resultParams);
	//训练模板槽函数
	int slot_CreateTemplate(RunParamsStruct_Template &runParams);
private:
	Ui::TemplateWindowClass ui;
	DataIO dataIOC;//参数存取对象

//刷图变量*****************************************************************
//显示图像的控件id
	HTuple m_hLabelID;            //QLabel控件句柄
	HTuple m_hHalconID;            //Halcon显示窗口句柄
	//原始图像的尺寸
	HTuple m_imgWidth, m_imgHeight;
	//图片路径列表
	HTuple m_imgFiles;

	//需要刷新到窗口的图形
	HObject ho_ShowObj;
	//是否显示图形
	bool isShowObj = true;
	//当前图像
	HObject ho_Image;
	//缩放后的图像
	HObject m_hResizedImg;
	//缩放系数
	HTuple m_hvScaledRate;
	//缩放后图像的大小
	HTuple m_scaledHeight, m_scaledWidth;
	//*****************************************************
	//模板匹配变量***************************************************************
	TemplateDetect *TemplateDetect1;     //模板类指针对象1

	QVector<HObject> ho_TemplateRegions;   //模板训练区域集合
	QVector<HObject> ho_SearchRegions;   //模板搜索区域集合
	QVector<HObject> ho_ShadowRegions;   //掩膜区域集合

	HObject TrainRoi_Template;     //模板训练区域
	HObject SearchRoi_Template;     //模板搜索区域
	HObject ShadowRoi_Template;        //掩模区域
	QString RoiShape = "rectangle1";
	RunParamsStruct_Template hv_RunParamsTemplate;
	//**************************************************************************
public:
	std::string nodeName = "";
	int processModbuleID = -1;
	int processID = -1;
	std::string XMLPath = "";
	std::string configPath = "";
};
