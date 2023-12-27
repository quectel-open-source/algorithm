#pragma once
#pragma execution_character_set("utf-8")
#include <QMainWindow>
#include "ui_projectClass.h"
#include  <QMouseEvent>
#include <algorithmScene.h>
#include <QDateTime>
#include <QTextStream>
#include "qtimer.h"
#include "data.h"
#include <window.h>

static std::map<eModubleType, std::string > modubleNameTitleMap;
static std::map<eModubleType, std::map<std::string, portData>> portIn;
static std::map<eModubleType, std::map<std::string, portData>> portOut;
class modubleData {
public:
	int indexIn = 0;
	int indexOut = 0;
	modubleData(eModubleType _modubleName, std::string _modubleTitle) {
		modubleName = _modubleName;
		modubleNameTitleMap[modubleName] = _modubleTitle;
	}

	~modubleData() {};


	void addModublePortIn(eDataType modublePortName, bool isSelect, ePortType dataType) {
		portIn[modubleName][data::dataTypeToString(modublePortName)] = (setPortData(isSelect, dataType));
	}

	void addModublePortOut(eDataType modublePortName, bool isSelect, ePortType dataType) {
		portOut[modubleName][data::dataTypeToString(modublePortName)] = (setPortData(isSelect, dataType));
	}

	portData setPortData(bool isSelect, ePortType dataType) {
		portData portData1;
		portData1.isSelect = isSelect;
		portData1.dataType = dataType;
		return portData1;
	}

	static sceneModubleData getModubleData() {
		sceneModubleData sceneModubleData1;
		sceneModubleData1.modubleNameTitleMap = modubleNameTitleMap;
		sceneModubleData1.portIn = portIn;
		sceneModubleData1.portOut = portOut;
		return sceneModubleData1;
	}
private:
	eModubleType modubleName = eModubleType::Default;
};



class projectClass : public QMainWindow
{
	Q_OBJECT

public:
	projectClass(QWidget *parent = nullptr);
	~projectClass();

	void closeEvent(QCloseEvent* e);
	void getmessage(QString value);
	void addAlgorithmScene(QWidget* processWidget);
	void getClickModuble(int _processID, int _modubleID);
	void setCallback();
	void loadProcesses(std::string configPath);
	void saveProcesses();
	void clearProcesses();
	void addProcess();
	void loadProcesses(std::vector<int> processIDList);
	void loadScenes();
	void addModule(int positionX, int positionY);
	void loadProcessAddModule(std::string moduleName, int currentProcessID, int modubleID);
	void getSelectModubleData(int _processID, int _modubleID, std::string _modubleName, std::function<void(int processModubleID)>);

	void startProcesses(bool isStartContinus);
	void runProcesses();
	void runProcessesContinuous(bool isContinus);
	void runProcessContinuous(bool isContinus, bool isExistCamera, bool isExistImage);
	void endProcesses();
	int getCurrentProcessID();
private:
	Ui::projectClassClass ui;
	std::string processNamePrefix = "Á÷³Ì";
	int processID = 0;
	std::string configPath = "";
	QWidget* processWidget;
	QPoint whereismouse;
	std::map<int, algorithmScene* > algorithmSceneList;
	eModubleType moduleName;
	void setDefaultPath();
	Hlong windID;
	HTuple hv_WindowHandle;
	int showModubleID = -1;

	HObject showImage1;
	HObject showRegion1;
	QTimer* timer = new QTimer(this);

signals:

	void showImageS();
	void sendResultInformation(int,int, HObject,HObject,bool,int);
	void sendTotalTime(int);
private slots:
	void on_toolButton_clicked();
	void on_toolButton_2_clicked();
	void on_toolButton_3_clicked();
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void on_toolButton_addTab_clicked();
	void on_toolButton_camera_clicked();
	void on_toolButton_run_clicked();
	void on_toolButton_iamge_clicked();
	void on_toolButton_barcode_clicked();
	void on_toolButton_match_14_clicked();
	void on_toolButton_line_clicked();
	void on_toolButton_circle_clicked();
	void on_QRCodeButton_clicked();
	void on_toolButton_match_clicked();
	void on_toolButton_ellipse_clicked();
	void on_toolButton_rectangle_clicked();
	void on_toolButton_cross_clicked();
	void on_toolButton_crossCC_clicked();
	void showImage();
	void onTimeout();
};
