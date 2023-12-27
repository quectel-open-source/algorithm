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
	//��ʼ����ʾ����
	void InitWindow();
	//��ʾͼƬ(hv_FillType ����ѡ��margin����fill)
	void showImg(const HObject &ho_Img, HTuple hv_FillType, HTuple hv_Color);
	//������ˢ��ͼ�񴫵ݲ���(��Ҫ������Ϊ�˹�������ʱ��ʾͼ��)
	void GiveParameterToWindow();
	//**********************************************************************************************
	//��Բ�������ʼ��
	void IniTableData_Ellipse();
	//������Բ������в���������
	void UpdateEllipseDataWindow(const RunParamsStruct_Ellipse &RunParams);
	//���в�����Բ�ṹ�������ֵ����
	void SetRunParams_Ellipse(RunParamsStruct_Ellipse &RunParams);
	//������Բ�����ʾ�������
	void SetTableData_Ellipse(const ResultParamsStruct_Ellipse &resultParams, qint64 Ct);
	//Exe·��
	string FolderPath();
	//����һ������strOld
	string strReplaceAll(const string& strResource, const string& strOld, const string& strNew);
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
	//**************************************************************************
	//��Բ��⺯��
	//������Բ
	void on_btn_DrawEllipse_Ellipse_clicked();
	//�����Բ
	void on_btn_DetectEllipse_Ellipse_clicked();
	//���ROI
	void on_btn_ClearRoi_Ellipse_clicked();
	//������Բ����
	void on_btn_SaveData_Ellipse_clicked();
	//������Բ����
	void on_btn_LoadData_Ellipse_clicked();
	//***************************************************************************
	//�����Բ�ۺ���
	int slot_FindEllipse(ResultParamsStruct_Ellipse &resultParams);
private:
	Ui::EllipseWindowClass ui;
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
	//****************************************************************************
		//��Բ���
	EllipseDetect *EllipseDetect1;//��Բ���ָ��
	RunParamsStruct_Ellipse hv_RunParamsEllipse;
	//*****************************************************************************
public:
	int processID = -1;	//����ID
	string nodeName = "";	//ģ������
	int processModbuleID = -1;	//ģ��ID
	string configPath = "";	//�����ļ���·��
	string XMLPath = "";	//XML·��
};
