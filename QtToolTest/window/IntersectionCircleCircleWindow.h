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
	//��ʼ����ʾ����
	void InitWindow();
	//��ʾͼƬ(hv_FillType ����ѡ��margin����fill)
	void showImg(const HObject &ho_Img, HTuple hv_FillType, HTuple hv_Color);
	//������ˢ��ͼ�񴫵ݲ���(��Ҫ������Ϊ�˹�������ʱ��ʾͼ��)
	void GiveParameterToWindow();
	//**********************************************************************************************
	//ˢ�����в���
	void SetRunParams_IntersectCircleCircle(const ResultParamsStruct_Circle &Circle1, const ResultParamsStruct_Circle &Circle2);
	//ˢ�½��
	void SetTableData_IntersectCircleCircle(const ResultParamsStruct_Circle &Circle1, const ResultParamsStruct_Circle &Circle2, HTuple hv_Row1, HTuple hv_Col1, HTuple hv_Row2, HTuple hv_Col2, int Ret, qint64 Ct);
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
	//���а�ť
	void on_pb_Run_clicked();
private:
	Ui::IntersectionCircleCircleWindowClass ui;
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
	//ԲԲ�ཻ
	IntersectionDetect *CircleCircleIntersect1;
public:
	ResultParamsStruct_Circle CircleA;	//�����ԲA
	ResultParamsStruct_Circle CircleB;	//�����ԲB
};
