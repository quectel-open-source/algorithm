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
	//��ʼ����ʾ����
	void InitWindow();
	//��ʾͼƬ(hv_FillType ����ѡ��margin����fill)
	void showImg(const HObject &ho_Img, HTuple hv_FillType, HTuple hv_Color);
	//������ˢ��ͼ�񴫵ݲ���(��Ҫ������Ϊ�˹�������ʱ��ʾͼ��)
	void GiveParameterToWindow();
	//**********************************************************************************************
	//���ν������ʼ��
	void IniTableData_Rectangle();
	//���¾��μ�����в���������
	void UpdateRectangleDataWindow(const RunParamsStruct_Rectangle &RunParams);
	//���в��Ҿ��νṹ�������ֵ����
	void SetRunParams_Rectangle(RunParamsStruct_Rectangle &RunParams);
	//���þ��ν����ʾ�������
	void SetTableData_Rectangle(const ResultParamsStruct_Rectangle &resultParams, qint64 Ct);
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
	//���μ�⺯��
	//���ƾ���
	void on_btn_DrawRectangle_Rectangle_clicked();
	//������
	void on_btn_DetectRectangle_Rectangle_clicked();
	//���ROI
	void on_btn_ClearRoi_Rectangle_clicked();
	//��������β���
	void on_btn_SaveData_Rectangle_clicked();
	//��ȡ�����β���
	void on_btn_LoadData_Rectangle_clicked();
	//**************************************************************************
	//�����βۺ���
	int slot_FindRectangle(ResultParamsStruct_Rectangle &resultParams);
private:
	Ui::RectangleWindowClass ui;
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
	//���μ��
	RectangleDetect *RectangleDetect1;//���μ��ָ��
	RunParamsStruct_Rectangle hv_RunParamsRectangle;
	//****************************************************************************
public:
	int processID = -1;	//����ID
	string nodeName = "";	//ģ������
	int processModbuleID = -1;	//ģ��ID
	string configPath = "";	//�����ļ���·��
	string XMLPath = "";	//XML·��
};
