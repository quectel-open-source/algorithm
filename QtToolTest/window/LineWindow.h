#pragma once
#pragma execution_character_set("utf-8")

#include <QMainWindow>
#include "ui_LineWindow.h"
#include <QSettings>
#include <QVector>
#include <QDebug>
#include <QMessageBox>
#include <QFileDialog>
#include <QFileInfo>
//#include <QtConcurrent>
#include <qdatetime.h>
#include "../detect/DataIO.h"
#include <Halcon.h>
#include <halconcpp/HalconCpp.h>
#include "../detect/LineDetect.h"

using namespace HalconCpp;

class LineWindow : public QMainWindow
{
	Q_OBJECT

public:
	LineWindow(QWidget *parent = nullptr);
	LineWindow(HObject image1, int processID, int modubleID, std::string _modubleName, std::string configPath);
	~LineWindow();
private:
	//初始化显示窗口
	void InitWindow();
	//显示图片(hv_FillType 可以选择margin或者fill)
	void showImg(const HObject &ho_Img, HTuple hv_FillType, HTuple hv_Color);
	//给窗口刷新图像传递参数(主要作用是为了滚轮缩放时显示图形)
	void GiveParameterToWindow();
	//**********************************************************************************************
		//抓边用函数
	//绘制箭头(根据绘制直线的坐标计算)
	void ShowArrow_Line(HTuple windowId, HTuple LineRow1, HTuple LineCol1, HTuple LineRow2, HTuple LineCol2);
	//直线类对象初始化
	void IniLineClassObject();
	//运行查找直线结构体参数赋值函数
	void SetRunParams_Line(RunParamsStruct_Line &runParams);
	//初始化直线结果显示表格
	void IniTableData_Line();
	//设置直线结果显示表格数据
	void SetTableData_Line(const ResultParamsStruct_Line &resultParams, qint64 Ct);
	//更新直线检测运行参数到窗口
	void UpdateLineDataWindow(const RunParamsStruct_Line &RunParams);
	//Exe路径
	string FolderPath();
	//返回一个不含strOld
	string strReplaceAll(const string& strResource, const string& strOld, const string& strNew);
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
	//抓边用槽函数
	//绘制直线
	void on_btn_DrawLine_Line_clicked();
	//检测直线
	void on_btn_DetectLine_Line_clicked();
	//保存直线检测参数
	void on_btn_SaveLineData_clicked();
	//读取直线检测参数
	void on_btn_LoadLineData_clicked();
	//清除直线ROI
	void on_btn_ClearRoi_Line_clicked();

	//*****************************************************************************
	//检测直线槽函数
	int slot_FindLine(ResultParamsStruct_Line &resultParams);
private:
	Ui::LineWindowClass ui;
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
		//抓边参数变量
	LineDetect *LineDetect1;        //抓边类指针对象1
	RunParamsStruct_Line hv_RunParamsLine;  //找边运行参数
	//****************************************************************************
public:
	std::string nodeName = "";
	int processModbuleID = -1;
	int processID = -1;
	std::string XMLPath = "";
	std::string configPath = "";

};
