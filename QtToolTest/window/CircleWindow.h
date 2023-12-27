#pragma once
#pragma execution_character_set("utf-8")

#include <QMainWindow>
#include "ui_CircleWindow.h"
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

#include "../detect/CircleDetect.h"

using namespace std;

class CircleWindow : public QMainWindow
{
	Q_OBJECT

public:
	CircleWindow(QWidget *parent = nullptr);
	CircleWindow(HObject image, int _processID, int modubleID, std::string _modubleName, std::string configPath);
	~CircleWindow();
private:
	//初始化显示窗口
	void InitWindow();
	//显示图片(hv_FillType 可以选择margin或者fill)
	void showImg(const HObject &ho_Img, HTuple hv_FillType, HTuple hv_Color);
	//给窗口刷新图像传递参数(主要作用是为了滚轮缩放时显示图形)
	void GiveParameterToWindow();
	//**********************************************************************************************
		//抓圆用函数
	//绘制箭头(根据绘制圆的坐标计算)
	void ShowArrow_Circle(HTuple windowId, HTuple CircleRow, HTuple CircleCol, HTuple CircleRadius);
	//圆类对象初始化
	void IniCircleClassObject();
	//运行查找圆结构体参数赋值函数
	void SetRunParams_Circle(RunParamsStruct_Circle &runParams);
	//初始化圆结果显示表格
	void IniTableData_Circle();
	//设置圆结果显示表格数据
	void SetTableData_Circle(const ResultParamsStruct_Circle &resultParams, qint64 Ct);
	//更新圆检测运行参数到窗口
	void UpdateCircleDataWindow(const RunParamsStruct_Circle &RunParams);
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
	//***************************************************************************
	//抓圆用槽函数
	//绘制圆
	void on_btn_DrawCircle_Circle_clicked();
	//检测圆
	void on_btn_DetectCircle_Circle_clicked();
	//保存圆检测参数
	void on_btn_SaveCircleData_clicked();
	//读取圆检测参数参数
	void on_btn_LoadCircleData_clicked();
	//清除圆ROI
	void on_btn_ClearRoi_Circle_clicked();
	//检测圆槽函数
	int slot_FindCircle(ResultParamsStruct_Circle &resultParams);

private:
	Ui::CircleWindowClass ui;
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
		//抓圆参数变量
	CircleDetect *CircleDetect1;        //抓圆类指针对象1
	RunParamsStruct_Circle hv_RunParamsCircle;  //找圆运行参数
	//****************************************************************************
public:
	std::string nodeName = "";
	int processModbuleID = -1;
	int processID = -1;
	std::string XMLPath = "";
	std::string configPath = "";
};
