#pragma once
#pragma execution_character_set("utf-8")
#include <qtWidgets/QMainWindow>
#include "ui_BarcodeClass.h"
#include <Halcon.h>
#include "halconcpp/HalconCpp.h"
#include <halconcpp/HDevThread.h>
#include<QDir>
#include<qtWidgets/QFileDialog>
#include<QFileInfoList>
#include<QFileInfo>
#include<QTextCodec>
#include <QDateTime>


#include "../detect/dataDetect.h"
#include "../QtToolTest/drawroi.h"
#include "../detect/DataIO.h"
#include "../detect/BarCodeDetect.h"

using namespace HalconCpp;

class BarcodeClass : public QMainWindow {
	Q_OBJECT

public:
	BarcodeClass(HObject image, int processID,int modubleID, std::string _nodeName, std::string xmlPath, QWidget* parent = nullptr);
	BarcodeClass(std::string _nodeName, int processModbuleID, int processID, std::string xmlPath);

	~BarcodeClass();

	void updataUIData();
	void run(ResultParamsStruct_BarCode& _resultParams);
	QPoint whereismouse;
	BOOL keypoint = 0;
	BOOL onebarcode = 0;
	BOOL twobarcode = 0;
	void getmessage(QString value);
	void Displyimage(HObject image, Hlong MainWndID, int labHeight, int labWidth);
	void DisplyRegionImage(HObject image, HObject TempRoi, Hlong MainWndID, int labHeight, int labWidth);
	void DisplyRegion(HObject image, HObject TempRoi, Hlong MainWndID, int labHeight, int labWidth);
	HTuple   hv_WindowHandle, region_WindowHandle, hv_Width, hv_Height;
	Hlong  MainWndID; Hlong  MainWndROI;
	QTextCodec* code;           // 字符转码
	drawroi* roi;
	QString FlowName;
	//******************************************************************************************************
	//一维码用函数
		//一维码类对象初始化
	void IniBarCodeClassObject();
	//运行查找一维码结构体参数赋值函数
	void SetRunParams_BarCode(RunParamsStruct_BarCode& runParams);
	void readRunParams_BarCode(RunParamsStruct_BarCode& runParams);
	//初始化一维码结果显示表格
	void IniTableData_BarCode();
	//设置一维码结果显示表格数据
	void SetTableData_BarCode(const ResultParamsStruct_BarCode& resultStruct);
	//更新一维码检测运行参数到窗口
	void UpdateBarCodeDataWindow(const RunParamsStruct_BarCode& runParams);
	//******************************************************************************************************
	//二维码用函数
			//二维码类对象初始化
	void IniCode2dClassObject();

	//初始化二值化显示表格
	void IniTableData_Binarization();

private slots:
	void on_toolButton_clicked();
	void on_toolButton_2_clicked();
	void on_toolButton_3_clicked();
	void mousePressEvent(QMouseEvent* event);
	void mouseMoveEvent(QMouseEvent* event);
	void on_pushButton_save_clicked();
	void on_cmb_BarCodeImage_currentIndexChanged(int index);
	//**************************************************************************
//一维码，二维码槽函数
//一维码检测槽函数
	void on_btn_FindBarCode_clicked();
	//绘制一维码搜索区域
	void on_btn_DrawRoi_BarCode_clicked();
	void on_btn_ClearRoi_BarCode_clicked();

public slots:
	void getimage(HObject);
	void gettitle(QString);

private:
	Ui::BarcodeClassClass ui;
	DataIO dataIOC;//参数存取对象
	QVector<HObject> ho_ImageList;   //图形变量集合
	//****************************************************************************
//条码检测参数变量
	BarCodeDetect* barCodeParams1;        //一维码检测类指针对象1
	QVector<HObject> ho_BarCodeRegions;   //一维码搜索区域集合
	HObject SearchRoi_BarCode;     //一维码搜索区域
	RunParamsStruct_BarCode RunParams_BarCode;  //一维码运行参数
	//****************************************************************************
	//二维码检测参数变量

	std::string nodeName = "";
	int processID = -1;
	int processModbuleID = -1;
	std::string XMLPath = "";
	std::string configPath = "";

	HObject ho_Image;
	HObject result_DisplyResion;

};
