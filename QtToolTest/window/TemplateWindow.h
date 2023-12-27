#pragma once
#pragma execution_character_set("utf-8")

#include <QMainWindow>
#include "ui_TemplateWindow.h"
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
#include "../detect/TemplateDetect.h"

class TemplateWindow : public QMainWindow
{
	Q_OBJECT

public:
	TemplateWindow(QWidget *parent = nullptr);
	TemplateWindow(HObject image, int _processID, int modubleID, std::string _modubleName, std::string configPath);
	~TemplateWindow();

private:
	//��ʼ����ʾ����
	void InitWindow();
	//��ʾͼƬ(hv_FillType ����ѡ��margin����fill)
	void showImg(const HObject &ho_Img, HTuple hv_FillType, HTuple hv_Color);
	//������ˢ��ͼ�񴫵ݲ���(��Ҫ������Ϊ�˹�������ʱ��ʾͼ��)
	void GiveParameterToWindow();
	//**********************************************************************************************
	//ģ��ƥ���ú���
	//ģ��������ʼ��
	void IniTemplateClassObject();
	//ģ��ƥ������ṹ�������ֵ����
	void SetRunParams_Template(RunParamsStruct_Template &runParams);

	//��ʼ��ģ����ʾ���
	void IniTableData_Template();
	//����ģ����ʾ�������
	void SetTableData_Template(const ResultParamsStruct_Template &resultStruct, qint64 Ct);
	//����ģ��ѵ�����������в�������
	void UpdateTemplateDataWindow(const RunParamsStruct_Template &RunParams);
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
	//ģ��ƥ���òۺ���
	//Roi������״ѡ��
	void on_cmb_RoiShape_Template_activated(const QString &arg1);
	//ģ��ƥ������ѡ��
	void on_cmb_MatchMethod_Train_activated(const QString &arg1);
	//����ģ��ѵ������
	void on_btn_DrawTrainRoi_Template_clicked();
	//����ģ����������
	void on_btn_DrawSearchRoi_Template_clicked();
	//������ģ����
	void on_btn_DrawShaddowRoi_Template_clicked();
	//�ϲ�ģ������Roi
	void on_btn_UnionRoi_Template_clicked();
	//���ģ������Roi
	void on_btn_ClearRoi_Template_clicked();
	//ѵ��ģ��
	void on_btn_Train_Template_clicked();
	//����ģ��
	void on_btn_FindTemplate_clicked();
	//ģ���������
	void on_btn_SaveTemplateData_clicked();
	//ģ�������ȡ
	void on_btn_ReadTemplateData_clicked();
	//*****************************************************************************
	//����ģ��ۺ���
	int slot_FindTemplate(ResultParamsStruct_Template &resultParams);
	//ѵ��ģ��ۺ���
	int slot_CreateTemplate(RunParamsStruct_Template &runParams);
private:
	Ui::TemplateWindowClass ui;
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
	//ģ��ƥ�����***************************************************************
	TemplateDetect *TemplateDetect1;     //ģ����ָ�����1

	QVector<HObject> ho_TemplateRegions;   //ģ��ѵ�����򼯺�
	QVector<HObject> ho_SearchRegions;   //ģ���������򼯺�
	QVector<HObject> ho_ShadowRegions;   //��Ĥ���򼯺�

	HObject TrainRoi_Template;     //ģ��ѵ������
	HObject SearchRoi_Template;     //ģ����������
	HObject ShadowRoi_Template;        //��ģ����
	QString RoiShape = "rectangle1";
	RunParamsStruct_Template hv_RunParamsTemplate;
	//**************************************************************************
public:
	std::string nodeName = "";
	int processModbuleID = -1;
	int processID = -1;
	std::string XMLPath = "";
	std::string configPath = "";
};
