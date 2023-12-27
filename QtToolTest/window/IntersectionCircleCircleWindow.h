#pragma once

#include <QMainWindow>
#include "ui_IntersectionCircleCircleWindow.h"
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
#include "../detect/IntersectionDetect.h"

class IntersectionCircleCircleWindow : public QMainWindow
{
	Q_OBJECT

public:
	IntersectionCircleCircleWindow(QWidget *parent = nullptr);
	IntersectionCircleCircleWindow(HObject image, ParamsStruct_Circle circle1, ParamsStruct_Circle circle2);
	~IntersectionCircleCircleWindow();
private:
	//初始化显示窗口
	void InitWindow();
	//显示图片(hv_FillType 可以选择margin或者fill)
	void showImg(const HObject &ho_Img, HTuple hv_FillType, HTuple hv_Color);
	//给窗口刷新图像传递参数(主要作用是为了滚轮缩放时显示图形)
	void GiveParameterToWindow();
	//**********************************************************************************************
	//刷新运行参数
	void SetRunParams_IntersectCircleCircle(const ResultParamsStruct_Circle &Circle1, const ResultParamsStruct_Circle &Circle2);
	//刷新结果
	void SetTableData_IntersectCircleCircle(const ResultParamsStruct_Circle &Circle1, const ResultParamsStruct_Circle &Circle2, HTuple hv_Row1, HTuple hv_Col1, HTuple hv_Row2, HTuple hv_Col2, int Ret, qint64 Ct);
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
	//运行按钮
	void on_pb_Run_clicked();
private:
	Ui::IntersectionCircleCircleWindowClass ui;
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
	//圆圆相交
	IntersectionDetect *CircleCircleIntersect1;
public:
	ResultParamsStruct_Circle CircleA;	//传入的圆A
	ResultParamsStruct_Circle CircleB;	//传入的圆B
};
