#pragma once
#pragma execution_character_set("utf-8")

#include <QMainWindow>
#include "ui_RectangleWindow.h"
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
#include "../detect/rectangleDetect.h"

class RectangleWindow : public QMainWindow
{
	Q_OBJECT

public:
	RectangleWindow(QWidget *parent = nullptr);
	RectangleWindow(HObject image, int _processID, int modubleID, std::string _modubleName, std::string configPath);
	~RectangleWindow();
private:
	//初始化显示窗口
	void InitWindow();
	//显示图片(hv_FillType 可以选择margin或者fill)
	void showImg(const HObject &ho_Img, HTuple hv_FillType, HTuple hv_Color);
	//给窗口刷新图像传递参数(主要作用是为了滚轮缩放时显示图形)
	void GiveParameterToWindow();
	//**********************************************************************************************
	//矩形结果表格初始化
	void IniTableData_Rectangle();
	//更新矩形检测运行参数到窗口
	void UpdateRectangleDataWindow(const RunParamsStruct_Rectangle &RunParams);
	//运行查找矩形结构体参数赋值函数
	void SetRunParams_Rectangle(RunParamsStruct_Rectangle &RunParams);
	//设置矩形结果显示表格数据
	void SetTableData_Rectangle(const ResultParamsStruct_Rectangle &resultParams, qint64 Ct);
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
	//矩形检测函数
	//绘制矩形
	void on_btn_DrawRectangle_Rectangle_clicked();
	//检测矩形
	void on_btn_DetectRectangle_Rectangle_clicked();
	//清除ROI
	void on_btn_ClearRoi_Rectangle_clicked();
	//保存检测矩形参数
	void on_btn_SaveData_Rectangle_clicked();
	//读取检测矩形参数
	void on_btn_LoadData_Rectangle_clicked();
	//**************************************************************************
	//检测矩形槽函数
	int slot_FindRectangle(ResultParamsStruct_Rectangle &resultParams);
private:
	Ui::RectangleWindowClass ui;
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
	//矩形检测
	RectangleDetect *RectangleDetect1;//矩形检测指针
	RunParamsStruct_Rectangle hv_RunParamsRectangle;
	//****************************************************************************
public:
	int processID = -1;	//流程ID
	string nodeName = "";	//模块名称
	int processModbuleID = -1;	//模块ID
	string configPath = "";	//配置文件夹路径
	string XMLPath = "";	//XML路径
};
