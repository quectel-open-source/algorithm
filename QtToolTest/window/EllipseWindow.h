#pragma once
#pragma execution_character_set("utf-8")

#include <QMainWindow>
#include "ui_EllipseWindow.h"
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
#include "../detect/EllipseDetect.h"

class EllipseWindow : public QMainWindow
{
	Q_OBJECT

public:
	EllipseWindow(QWidget *parent = nullptr);
	EllipseWindow(HObject image, int _processID, int modubleID, std::string _modubleName, std::string configPath);
	~EllipseWindow();
private:
	//初始化显示窗口
	void InitWindow();
	//显示图片(hv_FillType 可以选择margin或者fill)
	void showImg(const HObject &ho_Img, HTuple hv_FillType, HTuple hv_Color);
	//给窗口刷新图像传递参数(主要作用是为了滚轮缩放时显示图形)
	void GiveParameterToWindow();
	//**********************************************************************************************
	//椭圆结果表格初始化
	void IniTableData_Ellipse();
	//更新椭圆检测运行参数到窗口
	void UpdateEllipseDataWindow(const RunParamsStruct_Ellipse &RunParams);
	//运行查找椭圆结构体参数赋值函数
	void SetRunParams_Ellipse(RunParamsStruct_Ellipse &RunParams);
	//设置椭圆结果显示表格数据
	void SetTableData_Ellipse(const ResultParamsStruct_Ellipse &resultParams, qint64 Ct);
	//Exe路径
	string FolderPath();
	//返回一个不含strOld
	string strReplaceAll(const string& strResource, const string& strOld, const string& strNew);
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
	//**************************************************************************
	//椭圆检测函数
	//绘制椭圆
	void on_btn_DrawEllipse_Ellipse_clicked();
	//检测椭圆
	void on_btn_DetectEllipse_Ellipse_clicked();
	//清除ROI
	void on_btn_ClearRoi_Ellipse_clicked();
	//保存椭圆参数
	void on_btn_SaveData_Ellipse_clicked();
	//加载椭圆参数
	void on_btn_LoadData_Ellipse_clicked();
	//***************************************************************************
	//检测椭圆槽函数
	int slot_FindEllipse(ResultParamsStruct_Ellipse &resultParams);
private:
	Ui::EllipseWindowClass ui;
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
	//****************************************************************************
		//椭圆检测
	EllipseDetect *EllipseDetect1;//椭圆检测指针
	RunParamsStruct_Ellipse hv_RunParamsEllipse;
	//*****************************************************************************
public:
	int processID = -1;	//流程ID
	string nodeName = "";	//模块名称
	int processModbuleID = -1;	//模块ID
	string configPath = "";	//配置文件夹路径
	string XMLPath = "";	//XML路径
};
