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
	//��ʼ����ʾ����
	void InitWindow();
	//��ʾͼƬ(hv_FillType ����ѡ��margin����fill)
	void showImg(const HObject &ho_Img, HTuple hv_FillType, HTuple hv_Color);
	//������ˢ��ͼ�񴫵ݲ���(��Ҫ������Ϊ�˹�������ʱ��ʾͼ��)
	void GiveParameterToWindow();
	//**********************************************************************************************
	//��ʼ����ά������ʾ���
	void IniTableData_Code2d();
	//��ά��������ʼ��
	void IniCode2dClassObject();
	//���в��Ҷ�ά��ṹ�������ֵ����
	void SetRunParams_Code2d(RunParamsStruct_Code2d &runParams);
	//���ö�ά������ʾ�������
	void SetTableData_Code2d(const ResultParamsStruct_Code2d &resultStruct, qint64 Ct);
	//���¶�ά�������в���������
	void UpdateCode2dDataWindow(const RunParamsStruct_Code2d &runParams);
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
		//��ά����ۺ���
	void on_btn_FindCode2d_clicked();
	//���ƶ�ά����������
	void on_btn_DrawRoi_Code2d_clicked();
	//�����ά�������
	void on_btn_SaveCode2dData_clicked();
	//��ȡ��ά�������
	void on_btn_LoadCode2dData_clicked();
	//���ROI
	void on_btn_ClearRoi_Code2d_clicked();
	//**************************************************************************
	//����ά��ۺ���
	int slot_FindCode2d(ResultParamsStruct_Code2d &resultParams);
private:
	Ui::Code2dWindowClass ui;
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
		//��ά�����������
	QRCodeDetect *code2dParams1;         //��ά������ָ�����1
	QVector<HObject> ho_Code2dRegions;   //��ά���������򼯺�
	HObject SearchRoi_Code2d;     //��ά����������
	RunParamsStruct_Code2d hv_RunParamsCode2d;  //��ά�����в���
	//****************************************************************************
public:
	std::string nodeName = "";
	int processModbuleID = -1;
	int processID = -1;
	std::string XMLPath = "";
	std::string configPath = "";
};
