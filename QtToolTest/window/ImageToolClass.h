#pragma once
#pragma execution_character_set("utf-8")
#include <qtWidgets/QMainWindow>
#include "ui_ImageToolClass.h"
#include <Halcon.h>
#include <halconcpp/HalconCpp.h>
#include <halconcpp/HDevThread.h>
#include<QDir>
#include<qtWidgets/QFileDialog>
#include<QFileInfoList>
#include<QFileInfo>
#include<QTextCodec>
#include <QDateTime>
#include <QMouseEvent>
#include <qtWidgets/qmessagebox.h>
#include <qtWidgets/QListWidgetItem>
#include <qtWidgets/QListWidget>
#include <qstandarditemmodel.h>

using namespace HalconCpp;

class ImageToolClass : public QMainWindow
{
	Q_OBJECT

public:
	ImageToolClass(std::string _nodeName, int _processModbuleID, int _processID, std::string xmlPath, QWidget *parent = nullptr);
	~ImageToolClass();




	QPoint whereismouse;
	BOOL keypoint = 0;
	QTextCodec *code;           // �ַ�ת��
	void getmessage(QString value);
	void Displyimage(HObject image);
	HTuple   hv_WindowHandle, region_WindowHandle, hv_Width, hv_Height;
	Hlong  MainWndID; Hlong  MainWndROI;

	int imageindex;
	QStandardItemModel *m_listviewmodel;
	//���ź��ͼ��
	HObject m_hResizedImg;
	//����ϵ��
	HTuple m_hvScaledRate;
	//���ź�ͼ��Ĵ�С
	HTuple m_scaledHeight, m_scaledWidth;

private:
	int processModbuleID = -1;
	int processID = -1;
	std::string nodeName = "";
	std::string XMLPath="";
	QFileInfoList imagelist;
	HObject ho_Image;

private slots:
	void on_toolButton_clicked();
	void on_toolButton_2_clicked();
	void on_toolButton_3_clicked();
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void on_btn_openImage_clicked();
	void on_btn_imagefiles_clicked();
	void on_btn_deleteImage_clicked();
	void on_toolButton_provious_clicked();
	void on_toolButton_next_clicked();
	void slot_itemClicked(QListWidgetItem * item);

signals:
	void sendimage(HObject);
	void sendimageList(QFileInfoList);


private:
	Ui::ImageToolClassClass ui;
};
