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
	//��ʼ����ʾ����
	void InitWindow();
	//��ʾͼƬ(hv_FillType ����ѡ��margin����fill)
	void showImg(const HObject &ho_Img, HTuple hv_FillType, HTuple hv_Color);
	//������ˢ��ͼ�񴫵ݲ���(��Ҫ������Ϊ�˹�������ʱ��ʾͼ��)
	void GiveParameterToWindow();
	//**********************************************************************************************
		//ץ���ú���
	//���Ƽ�ͷ(���ݻ���ֱ�ߵ��������)
	void ShowArrow_Line(HTuple windowId, HTuple LineRow1, HTuple LineCol1, HTuple LineRow2, HTuple LineCol2);
	//ֱ��������ʼ��
	void IniLineClassObject();
	//���в���ֱ�߽ṹ�������ֵ����
	void SetRunParams_Line(RunParamsStruct_Line &runParams);
	//��ʼ��ֱ�߽����ʾ���
	void IniTableData_Line();
	//����ֱ�߽����ʾ�������
	void SetTableData_Line(const ResultParamsStruct_Line &resultParams, qint64 Ct);
	//����ֱ�߼�����в���������
	void UpdateLineDataWindow(const RunParamsStruct_Line &RunParams);
	//Exe·��
	string FolderPath();
	//����һ������strOld
	string strReplaceAll(const string& strResource, const string& strOld, const string& strNew);
	//******************************************************************************************************

private slots:
	//��ͼƬ
	void on_pBtn_ReadImage_clicked();
	//ͼ������Ӧ
	void on_pBtn_FitImage_clicked();
	//��մ���
	void on_btn_ClearWindow_clicked();
	//�Ƿ���ʾͼ�θ�ѡ��
	void on_ckb_ShowObj_stateChanged(int arg1);
	//�رմ���
	void on_btn_Hide_clicked();
	//***************************************************************************
	//ץ���òۺ���
	//����ֱ��
	void on_btn_DrawLine_Line_clicked();
	//���ֱ��
	void on_btn_DetectLine_Line_clicked();
	//����ֱ�߼�����
	void on_btn_SaveLineData_clicked();
	//��ȡֱ�߼�����
	void on_btn_LoadLineData_clicked();
	//���ֱ��ROI
	void on_btn_ClearRoi_Line_clicked();

	//*****************************************************************************
	//���ֱ�߲ۺ���
	int slot_FindLine(ResultParamsStruct_Line &resultParams);
private:
	Ui::LineWindowClass ui;
	DataIO dataIOC;//������ȡ����

//ˢͼ����*****************************************************************
//��ʾͼ��Ŀؼ�id
	HTuple m_hLabelID;            //QLabel�ؼ����
	HTuple m_hHalconID;            //Halcon��ʾ���ھ��
	//ԭʼͼ��ĳߴ�
	HTuple m_imgWidth, m_imgHeight;
	//ͼƬ·���б�
	HTuple m_imgFiles;

	//��Ҫˢ�µ����ڵ�ͼ��
	HObject ho_ShowObj;
	//�Ƿ���ʾͼ��
	bool isShowObj = true;
	//��ǰͼ��
	HObject ho_Image;
	//���ź��ͼ��
	HObject m_hResizedImg;
	//����ϵ��
	HTuple m_hvScaledRate;
	//���ź�ͼ��Ĵ�С
	HTuple m_scaledHeight, m_scaledWidth;
	//*****************************************************
		//ץ�߲�������
	LineDetect *LineDetect1;        //ץ����ָ�����1
	RunParamsStruct_Line hv_RunParamsLine;  //�ұ����в���
	//****************************************************************************
public:
	std::string nodeName = "";
	int processModbuleID = -1;
	int processID = -1;
	std::string XMLPath = "";
	std::string configPath = "";

};
