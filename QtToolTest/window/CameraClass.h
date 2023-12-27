#pragma once
#pragma execution_character_set("utf-8")
#include <qtWidgets/QMainWindow>
#include "ui_CameraClass.h"
#include<QDir>
#include<qtWidgets/QFileDialog>
#include<QFileInfoList>
#include<QFileInfo>
#include<QTextStream>
#include <QDateTime>

#include <QStandardItemModel>
#include "../QtToolTest/hikcamera.h"
#include "E:/Program Files (x86)/MVS/MVS/Development/Includes/CameraParams.h"
#include "../detect/DataIO.h"


class CameraClass : public QMainWindow
{
	Q_OBJECT

public:
	CameraClass(QWidget *parent = nullptr);
	CameraClass(std::string _nodeName, int _processModbuleID, int _processID, std::string xmlPath);
	~CameraClass();
	 //hikvision camera paramater
	QStandardItemModel *model;
	hikcamera *hikcam;
	int index;

	MV_CC_DEVICE_INFO_LIST  m_stDevList;
	bool                    m_bGrabbing;   // 是否开始抓图
	void enumhikcamera();
	QString cameraname;
	QStringList CameraList;
	void getcameraptr();
	HTuple   hv_WindowHandle, region_WindowHandle, hv_Width, hv_Height;
	HObject image; Hlong  MainWndID; Hlong  MainWndROI;
	void Displyimage(HObject ho_Image);
	QPoint whereismouse;
	HObject ho_Image;
	
	int nFrameCount = 0;
	float fps;

public slots:
	void on_pushButton_Open_clicked();
	void on_pushButton_Close_clicked();
	void on_pushButton_reflash_clicked();
	void on_toolButton_clicked();
	void on_toolButton_2_clicked();
	void on_toolButton_3_clicked();
	void on_toolButton_trigger_clicked();
	void on_toolButton_Saveparamater_clicked();
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void getmessage(QString y);
	void getimage(HObject);
	void enumcamera(QString);
	void on_treeView_doubleClicked(const QModelIndex &index);
	void on_treeView_Clicked(const QModelIndex &index);
	void on_spinBox_valueChanged(int arg1);
	void on_spinBoxgain_valueChanged(int arg1);
	void on_comboBox_2_currentIndexChanged(int index);
	void on_comboBox_3_currentIndexChanged(int index);
	void resizeEvent(QResizeEvent *event);
signals:
	void sendimage(HObject);
	void initcamera(QString t);

private:
	Ui::CameraClassClass ui;
	DataIO dataIOC;//参数存取对象

	std::string nodeName = "";
	int processModbuleID = -1;
	int processID = -1;
	std::string XMLPath = "";
	std::string configPath = "";
};
