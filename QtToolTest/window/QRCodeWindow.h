#pragma once

#include <QMainWindow>
#include "ui_QRCodeWindow.h"
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
#include "../detect/QRCodeDetect.h"


class QRCodeWindow : public QMainWindow
{
	Q_OBJECT

public:
	QRCodeWindow(QWidget *parent = nullptr);
	QRCodeWindow(HObject image, int _processID, int modubleID, std::string _modubleName, std::string configPath);
	~QRCodeWindow();
private:
	//初始化显示窗口
	void InitWindow();
	//显示图片(hv_FillType 可以选择margin或者fill)
	void showImg(const HObject &ho_Img, HTuple hv_FillType, HTuple hv_Color);
	//给窗口刷新图像传递参数(主要作用是为了滚轮缩放时显示图形)
	void GiveParameterToWindow();
	//**********************************************************************************************
	//初始化二维码结果显示表格
	void IniTableData_Code2d();
	//二维码类对象初始化
	void IniCode2dClassObject();
	//运行查找二维码结构体参数赋值函数
	void SetRunParams_Code2d(RunParamsStruct_Code2d &runParams);
	//设置二维码结果显示表格数据
	void SetTableData_Code2d(const ResultParamsStruct_Code2d &resultStruct, qint64 Ct);
	//更新二维码检测运行参数到窗口
	void UpdateCode2dDataWindow(const RunParamsStruct_Code2d &runParams);
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
		//二维码检测槽函数
	void on_btn_FindCode2d_clicked();
	//绘制二维码搜索区域
	void on_btn_DrawRoi_Code2d_clicked();
	//保存二维码检测参数
	void on_btn_SaveCode2dData_clicked();
	//读取二维码检测参数
	void on_btn_LoadCode2dData_clicked();
	//清空ROI
	void on_btn_ClearRoi_Code2d_clicked();
	//**************************************************************************
	//检测二维码槽函数
	int slot_FindCode2d(ResultParamsStruct_Code2d &resultParams);
private:
	Ui::Code2dWindowClass ui;
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
		//二维码检测参数变量
	QRCodeDetect *code2dParams1;         //二维码检测类指针对象1
	QVector<HObject> ho_Code2dRegions;   //二维码搜索区域集合
	HObject SearchRoi_Code2d;     //二维码搜索区域
	RunParamsStruct_Code2d hv_RunParamsCode2d;  //二维码运行参数
	//****************************************************************************
public:
	std::string nodeName = "";
	int processModbuleID = -1;
	int processID = -1;
	std::string XMLPath = "";
	std::string configPath = "";
};
