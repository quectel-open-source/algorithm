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
	QTextCodec* code;           // �ַ�ת��
	drawroi* roi;
	QString FlowName;
	//******************************************************************************************************
	//һά���ú���
		//һά��������ʼ��
	void IniBarCodeClassObject();
	//���в���һά��ṹ�������ֵ����
	void SetRunParams_BarCode(RunParamsStruct_BarCode& runParams);
	void readRunParams_BarCode(RunParamsStruct_BarCode& runParams);
	//��ʼ��һά������ʾ���
	void IniTableData_BarCode();
	//����һά������ʾ�������
	void SetTableData_BarCode(const ResultParamsStruct_BarCode& resultStruct);
	//����һά�������в���������
	void UpdateBarCodeDataWindow(const RunParamsStruct_BarCode& runParams);
	//******************************************************************************************************
	//��ά���ú���
			//��ά��������ʼ��
	void IniCode2dClassObject();

	//��ʼ����ֵ����ʾ���
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
//һά�룬��ά��ۺ���
//һά����ۺ���
	void on_btn_FindBarCode_clicked();
	//����һά����������
	void on_btn_DrawRoi_BarCode_clicked();
	void on_btn_ClearRoi_BarCode_clicked();

public slots:
	void getimage(HObject);
	void gettitle(QString);

private:
	Ui::BarcodeClassClass ui;
	DataIO dataIOC;//������ȡ����
	QVector<HObject> ho_ImageList;   //ͼ�α�������
	//****************************************************************************
//�������������
	BarCodeDetect* barCodeParams1;        //һά������ָ�����1
	QVector<HObject> ho_BarCodeRegions;   //һά���������򼯺�
	HObject SearchRoi_BarCode;     //һά����������
	RunParamsStruct_BarCode RunParams_BarCode;  //һά�����в���
	//****************************************************************************
	//��ά�����������

	std::string nodeName = "";
	int processID = -1;
	int processModbuleID = -1;
	std::string XMLPath = "";
	std::string configPath = "";

	HObject ho_Image;
	HObject result_DisplyResion;

};
