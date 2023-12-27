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
	//��ʼ����ʾ����
	void InitWindow();
	//��ʾͼƬ(hv_FillType ����ѡ��margin����fill)
	void showImg(const HObject &ho_Img, HTuple hv_FillType, HTuple hv_Color);
	//������ˢ��ͼ�񴫵ݲ���(��Ҫ������Ϊ�˹�������ʱ��ʾͼ��)
	void GiveParameterToWindow();
	//**********************************************************************************************
		//ץԲ�ú���
	//���Ƽ�ͷ(���ݻ���Բ���������)
	void ShowArrow_Circle(HTuple windowId, HTuple CircleRow, HTuple CircleCol, HTuple CircleRadius);
	//Բ������ʼ��
	void IniCircleClassObject();
	//���в���Բ�ṹ�������ֵ����
	void SetRunParams_Circle(RunParamsStruct_Circle &runParams);
	//��ʼ��Բ�����ʾ���
	void IniTableData_Circle();
	//����Բ�����ʾ�������
	void SetTableData_Circle(const ResultParamsStruct_Circle &resultParams, qint64 Ct);
	//����Բ������в���������
	void UpdateCircleDataWindow(const RunParamsStruct_Circle &RunParams);
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
	//***************************************************************************
	//ץԲ�òۺ���
	//����Բ
	void on_btn_DrawCircle_Circle_clicked();
	//���Բ
	void on_btn_DetectCircle_Circle_clicked();
	//����Բ������
	void on_btn_SaveCircleData_clicked();
	//��ȡԲ����������
	void on_btn_LoadCircleData_clicked();
	//���ԲROI
	void on_btn_ClearRoi_Circle_clicked();
	//���Բ�ۺ���
	int slot_FindCircle(ResultParamsStruct_Circle &resultParams);

private:
	Ui::CircleWindowClass ui;
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
		//ץԲ��������
	CircleDetect *CircleDetect1;        //ץԲ��ָ�����1
	RunParamsStruct_Circle hv_RunParamsCircle;  //��Բ���в���
	//****************************************************************************
public:
	std::string nodeName = "";
	int processModbuleID = -1;
	int processID = -1;
	std::string XMLPath = "";
	std::string configPath = "";
};
