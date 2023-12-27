#pragma once
#pragma execution_character_set("utf-8")
#include <QChartView>
#include <QChart>
#include <QtCharts>
QT_CHARTS_USE_NAMESPACE
#include <QtWidgets/QMainWindow>
#include "ui_QtToolTest.h"
#include <windows.h>
#include <Halcon.h>
#include <halconcpp/HalconCpp.h>
#include "testAlgorithm.h"
#include "projectClass.h"
//#include "CameraClass.h"
#include "data.h"
using namespace HalconCpp;


class QtToolTest : public QMainWindow
{
    Q_OBJECT

public:
    QtToolTest(QWidget *parent = nullptr);
    ~QtToolTest();
	projectClass* project;
	 Ui::QtToolTestClass ui;
	 
	 void closeEvent(QCloseEvent* e);

private:
	QPoint whereismouse;
	//CameraClass  *cameradlg = new CameraClass();
	projectClass *projectdlg = new projectClass();
	HTuple   hv_WindowHandle, region_WindowHandle, hv_Width, hv_Height;
	//缩放后的图像
	HObject m_hResizedImg;
	//缩放系数
	HTuple m_hvScaledRate;
	//缩放后图像的大小
	HTuple m_scaledHeight, m_scaledWidth;
	int NGNumber = 0;
	int AllNumber = 0;
	int AllResultNumber = 0;
	QLabel *labelImage;
	QMenu *WindowMenu; //窗口菜单
	QHBoxLayout *QHBoxLayout_image;
	QVBoxLayout *QVBoxLayout_image;
	QList<QLabel*> list_Windows;
	QList<QLabel*> list_CountNumber;
	QList<QLabel*> list_CostTime;
	QList<QLabel*> list_FlowToolResult;
	QList<int> list_ALLCount;
	QLabel *label;
	QList<HTuple>   hv_WindowHandleTemp;
	QList<Hlong>  MainWndIDTemp;
	int flowNumber;//流程数量
	QList<QString> list_result;
	QString projectName;//方案名
private slots:
	void on_toolButton_clicked();
	void on_toolButton_2_clicked();
	void on_toolButton_3_clicked();
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void on_pushButton_camerasetting_clicked();
	void on_pushButton_project_clicked();
	void on_treeView1_doubleClicked();
	void on_pushButton_run_clicked();
	void on_pushButton_stop_clicked();
	void on_toolButton_WindowChange_clicked();
	void on_toolButton_Edit_clicked();
	void on_toolButton_reSet_clicked();
	void on_toolButton_dataCheck_clicked();
	void on_pushButton_openProject_clicked();
	void on_pushButton_saveProject_clicked();
private:
	QChart *chart;
	QValueAxis *mAxY;
	QValueAxis *mAxX;
	QLineSeries  *mLineSeries;
	QLineSeries  *mLineSeries2;
	QMutex g_mutex_1;
	QMutex g_mutex_2;
	QMutex g_mutex_3;
	const int WindowMaxNum = 12;
	QString projectdir = "";
	QString projectdirTemp = "";
	int RunCount = 0;
	QLabel *labCellIndex;
	QLabel *labCellType;
	QLabel *labStudID;
	QLabel *labStg;
	QProgressBar * pProgressBar1 = new QProgressBar();
	QProgressBar * pProgressBar2 = new QProgressBar();
	QProgressBar * pProgressBar3 = new QProgressBar();


public slots:
	void getmessage(QString y);
	void InitializeChart();
	/*void Displyimage(int, HObject image);*/
	void DisplyRegion(int, HObject ho_Image, HObject TempRoi);
	void SetData(int currentID, double OKRate);
	void SetTime(int, qint64);
	void addWindows(int, int);
	void AddFlowTool(int value);
	bool copyDirectory(const QString& srcPath, const QString& dstPath, bool coverFileIfExist);
	void GetprojectPath(QString);
	void timerUpDate();
	int getCpu();
	bool GetMemUsage(double &nMemTotal, double &nMemUsed);
	bool GetSysDisk(double& nDiskTotal, double& nDiskUsed);
	void getResultInformation(int,int, HObject, HObject, bool,int);
	void getTotalTime(int);
	void setShowWidgets(int totalProcess);
signals:
	void sendResultImage(int, QString);
	void sendResultTime(int, qint64);
	void SendDisplyimage(int q, HObject image);
	void SendDisplyRegion(int q, HObject ho_Image, HObject TempRoi);


};
