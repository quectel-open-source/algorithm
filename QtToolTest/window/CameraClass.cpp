#include "CameraClass.h"

CameraClass::CameraClass(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	model = new QStandardItemModel();
	ui.treeView->setEditTriggers(QAbstractItemView::NoEditTriggers);//不可编辑
	setWindowFlags(Qt::FramelessWindowHint);//隐藏边框 
	qRegisterMetaType<HObject>("HObject");
	//hikcamera
	hikcam = new hikcamera();
	m_bGrabbing = false;
	////connect(hikcam, SIGNAL(sendmessage(QString)), this, SLOT(getmessage(QString)));
	//connect(hikcam, SIGNAL(initcamera(QString)), this, SLOT(enumcamera(QString)));
	connect(hikcam, &hikcamera::sendmessage, this, &CameraClass::getmessage);
	connect(hikcam, &hikcamera::initcamera, this, &CameraClass::enumcamera);
	connect(hikcam, &hikcamera::sendimage, this, &CameraClass::getimage);
	//connect(hikcam, SIGNAL(sendtime(int)), this, SLOT(gettime(int)));
	//connect(ui.treeView, &QTreeView::doubleClicked, this, &CameraClass::on_treeView_doubleClicked);
	connect(ui.treeView, &QTreeView::clicked, this, &CameraClass::on_treeView_Clicked);
	MainWndID = (Hlong)ui.label->winId();
}

CameraClass::CameraClass(std::string _nodeName, int _processModbuleID, int _processID, std::string configPath){
	ui.setupUi(this);
	model = new QStandardItemModel();
	ui.treeView->setEditTriggers(QAbstractItemView::NoEditTriggers);//不可编辑
	setWindowFlags(Qt::FramelessWindowHint);//隐藏边框 
	qRegisterMetaType<HObject>("HObject");
	//hikcamera
	hikcam = new hikcamera();
	m_bGrabbing = false;
	////connect(hikcam, SIGNAL(sendmessage(QString)), this, SLOT(getmessage(QString)));
	//connect(hikcam, SIGNAL(initcamera(QString)), this, SLOT(enumcamera(QString)));
	connect(hikcam, &hikcamera::sendmessage, this, &CameraClass::getmessage);
	connect(hikcam, &hikcamera::initcamera, this, &CameraClass::enumcamera);
	connect(hikcam, &hikcamera::sendimage, this, &CameraClass::getimage);
	//connect(hikcam, SIGNAL(sendtime(int)), this, SLOT(gettime(int)));
	//connect(ui.treeView, &QTreeView::doubleClicked, this, &CameraClass::on_treeView_doubleClicked);
	connect(ui.treeView, &QTreeView::clicked, this, &CameraClass::on_treeView_Clicked);
	MainWndID = (Hlong)ui.label->winId();

	nodeName = _nodeName;
	processModbuleID = _processModbuleID;
	processID = _processID;
	XMLPath = configPath + "/config.xml";
	this->configPath = configPath + "/";
	CameraList.clear();
	model->clear();
	hikcam->InitDevice();
}

CameraClass::~CameraClass()
{
	hikcam->stopCamera(index);
	hikcam->closeCamera(index);
}


void CameraClass::resizeEvent(QResizeEvent *event)
{
	if (hv_WindowHandle != NULL) {
		CloseWindow(hv_WindowHandle);
	}
	int width = ui.label->width();
	int height = ui.label->height();
	OpenWindow(0,
		0,
		(Hlong)width,
		(Hlong)height,
		MainWndID,
		"visible",
		"",
		&hv_WindowHandle);

}

void CameraClass::getmessage(QString value)
{
	QString currenttime = (QDateTime::currentDateTime()).toString("yyyy.MM.dd hh:mm:ss");
	ui.plainTextEdit->appendPlainText(currenttime + ": " + value);

}

void CameraClass::enumcamera(QString VALUE1)
{
	QStringList list = VALUE1.split(":");
	ui.label_42->setText(list[0]);
	ui.label_43->setText(list[2]);
	ui.label_44->setText(list[3]);
	ui.label_45->setText("V1");
	ui.label_46->setText(list[4]);
	//设置model
	ui.treeView->setModel(model);
	QString cameraName;
	if (list[0] == "HikCamera")
	{
		cameraName = "Hik:";
	}
	QStandardItem *item = new QStandardItem(cameraName +list[2]);
	model->setItem(model->rowCount(), 0, item);
	item->setIcon(QIcon("./Resources/12.png"));
	CameraList.append(VALUE1);
}
void CameraClass::Displyimage(HObject ho_Image)
{
	if (hv_WindowHandle == NULL) {
	
		int width = ui.label->width();
		int height = ui.label->height();
		OpenWindow(0, 0, (Hlong)width, (Hlong)height, MainWndID, "visible", "", &hv_WindowHandle);

	}

	HTuple x, y;
	if (ho_Image.Key() == nullptr)
	{
		return;
	}

	GetImageSize(ho_Image, &x, &y);
	int width = ui.label->width();
	int height = ui.label->height();
	OpenWindow(0, 0, (Hlong)width, (Hlong)height, MainWndID, "visible", "", &hv_WindowHandle);
	SetPart(hv_WindowHandle, 0, 0, y, x);

		DispObj(ho_Image, hv_WindowHandle);
	
}

#include <iostream> 
#include <sstream>
#include<iomanip>
auto start = std::chrono::high_resolution_clock::now();
void CameraClass::getimage(HObject value)
{


		nFrameCount++;
		if (nFrameCount >= 30) {
			auto end = std::chrono::high_resolution_clock::now();
			fps = nFrameCount * 1000.0 / std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
			nFrameCount = 0;
			start = std::chrono::high_resolution_clock::now();
		}
		if (fps > 0) {
			std::ostringstream fps_label;
			fps_label << std::fixed << std::setprecision(2);
			fps_label << "FPS: " << fps;
			std::string fps_label_str = fps_label.str();
		}
		int labHeight = (Hlong)ui.label->height();
		int labWidth = (Hlong)ui.label->width();
		Displyimage(value);
	

}
void CameraClass::on_pushButton_reflash_clicked()
{
	CameraList.clear();
	model->clear();
	hikcam->InitDevice();
}
void CameraClass::on_treeView_Clicked(const QModelIndex &index1)
{
	//int index3 = ui.treeView->selectionModel()->currentIndex().row();
	index = index1.row();
	QStringList list = CameraList[index].split(":");
	ui.label_42->setText(list[0]);
	ui.label_43->setText(list[2]);
	ui.label_44->setText(list[3]);
	ui.label_45->setText("V1");
	ui.label_46->setText(list[4]);

}
//int runcount = 0;
void CameraClass::on_treeView_doubleClicked(const QModelIndex &index1)
{
	//index = index1.row();
	//QString str = index1.data().toString();
	//if (str =="")
	//{
	//	getmessage("Please select device");
	//	return;
	//}
	//cameraname = str;
	//QStringList namecamera = cameraname.split(":");
	//cameraname = namecamera[0];
	//if(runcount>0)
	//{
	//	if (m_bGrabbing == true)
	//	{
	//		return;
	//	}
	//}
	//if (cameraname == "Hik")
	//{
	//	if (m_bGrabbing == false)
	//	{
	//		hikcam->indexcamera = index;
	//		// ch:由设备信息创建设备实例 | en:Device instance created by device information
	//		if (NULL == hikcam->pDeviceInfo)
	//		{
	//			getmessage("Device does not exist");
	//			return;
	//		}
	//		hikcam->connectCamera();
	//		hikcam->StartCamera();
	//		hikcam->m_bStartGrabbing[index] = true;
	//		//             getcameraptr();
	//		hikcam->ReadBuffer();
	//		m_bGrabbing = true;
	//		runcount++;
	//	}
	//	else
	//	{
	//		hikcam->m_bStartGrabbing[index] = false;
	//		hikcam->stopCamera(index);
	//		hikcam->closeCamera(index);
	//		runcount--;
	//	}
	//}

}
void CameraClass::getcameraptr()
{
	float gain = hikcam->GetGain(index);
	ui.spinBoxgain->setValue(gain);
	float ExposureTime = hikcam->GetExposureTime(index);
	ui.spinBox->setValue(ExposureTime);
	//float framerate=hikcam->GetFrameRate(index);
	//ui->textEdit_framerate->setText(QString::number(framerate, 'f', 0));
	int TriggerMode = hikcam->GetTriggerMode(index);
	ui.comboBox_2->setCurrentIndex(TriggerMode);
	int TriggerSource = hikcam->GetTriggerSource(index);
	ui.comboBox_3->setCurrentIndex(TriggerSource);
}
void CameraClass::on_pushButton_Open_clicked()
{
	QString str = ui.treeView->selectionModel()->currentIndex().data().toString();
	if (str == "")
	{
		getmessage("Please select device");
		return;
	}
	cameraname = str;
	QStringList namecamera = cameraname.split(":");
	cameraname = namecamera[0];
	if (cameraname == "Hik")
	{
		if (m_bGrabbing == false)
		{
			hikcam->indexcamera = index;
			// ch:由设备信息创建设备实例 | en:Device instance created by device information
			if (NULL == hikcam->pDeviceInfo)
			{
				getmessage("Device does not exist");
				return;
			}
			hikcam->connectCamera();
			hikcam->StartCamera();
			hikcam->m_bStartGrabbing[index] = true;
			getcameraptr();
			hikcam->ReadBuffer();
			m_bGrabbing = true;
		}
	}
}
void CameraClass::on_pushButton_Close_clicked()
{
	if (cameraname == "Hik")
	{
		hikcam->m_bStartGrabbing[index] = false;
		hikcam->stopCamera(index);
		hikcam->closeCamera(index);
		m_bGrabbing = false;
	}
}
void CameraClass::on_toolButton_clicked()
{
	CameraClass::showMinimized(); //最小化
}
void CameraClass::on_toolButton_2_clicked()
{
	if (CameraClass::isMaximized())
	{
		CameraClass::showNormal();//还原事件
		//ui.toolButton_2->setIcon(QIcon(":/img/max.png"));
	}
	else
	{
		CameraClass::showMaximized();//最大化事件
		//ui.toolButton_2->setIcon(QIcon(":/img/max.png"));
	}

}
void CameraClass::on_toolButton_3_clicked()
{
	emit sendimage(ho_Image);

	//保存xml
	int index = ui.treeView->selectionModel()->currentIndex().row();
	QStringList list = CameraList[index].split(":");

	std::string factory = list[0].toStdString();
	std::string equipment = list[2].toStdString();
	std::string SN = list[3].toStdString();
	std::string address = list[4].toStdString();

	float gain = hikcam->GetGain(index);
	float ExposureTime = hikcam->GetExposureTime(index);
	int TriggerMode = hikcam->GetTriggerMode(index);
	int TriggerSource = hikcam->GetTriggerSource(index);

	RunParamsStruct_Camera RunParamsStruct_Camera1;
	RunParamsStruct_Camera1.factory = factory;
	RunParamsStruct_Camera1.equipment = equipment;
	RunParamsStruct_Camera1.SN = SN;
	RunParamsStruct_Camera1.address = address;

	RunParamsStruct_Camera1.gain = ui.spinBoxgain->value();
	RunParamsStruct_Camera1.ExposureTime = ui.spinBox->value();
	RunParamsStruct_Camera1.TriggerMode = ui.comboBox_2->currentIndex();
	RunParamsStruct_Camera1.TriggerSource = ui.comboBox_3->currentIndex();

	dataIOC.WriteParams_Camera(configPath, XMLPath, RunParamsStruct_Camera1, processID, nodeName, processModbuleID);

	this->close();
}
void CameraClass::mousePressEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton)
	{
		whereismouse = event->pos();
	}
}
void CameraClass::mouseMoveEvent(QMouseEvent *event)
{
	if (event->buttons() == Qt::LeftButton)
	{
		//当窗口最大化或最小化时也不进行触发
		if (CameraClass::isMaximized() || CameraClass::isMinimized())
		{
			return;
		}
		else
		{
			//当在按钮之类需要鼠标操作的地方不进行触发(防误触)
			if (ui.toolButton->underMouse() || ui.toolButton_2->underMouse() || ui.toolButton_3->underMouse()|| ui.comboBox_2->underMouse()||ui.comboBox_3->underMouse() || ui.comboBox_4->underMouse() || ui.comboBox_5->underMouse())
			{
			}
			else
			{
				CameraClass::move(CameraClass::mapToGlobal(event->pos() - whereismouse));//移动
			}
		}
	}
	event->accept();
}
void CameraClass::on_spinBox_valueChanged(int arg1)
{
	if (cameraname == "Hik")
	{
		hikcam->SetExposureTime(index, arg1);
	}
	else if (cameraname == "DahuaCamera")
	{
		
	}
}

void CameraClass::on_spinBoxgain_valueChanged(int arg1)
{
	if (cameraname == "Hik")
	{
		hikcam->SetGain(index, arg1);
	}
	else if (cameraname == "DahuaCamera")
	{
		
	}
}

void CameraClass::on_comboBox_2_currentIndexChanged(int index1)
{
	
	if (index1 == 0)//关闭触发
	{
		if (cameraname == "Hik")
		{
			hikcam->SetTriggerMode(index, 0);
		}
		else if (cameraname == "DahuaCamera")
		{
			//Dcamera->CameraChangeTrig(Dcamera->trigContinous);
		}
	}
	else if (index1 == 1)//打开触发
	{
		if (cameraname == "Hik")
		{
			hikcam->SetTriggerMode(index, 1);
		}
		else if (cameraname == "DahuaCamera")
		{
			//Dcamera->CameraChangeTrig(Dcamera->trigSoftware);
		}
	}
}

void CameraClass::on_comboBox_3_currentIndexChanged(int index2)
{
	if (index2 == 0)
	{
		if (cameraname == "Hik")
		{
			hikcam->SetTriggerSource(index, 0);
		}
		else if (cameraname == "DahuaCamera")
		{
			//Dcamera->CameraChangeTrig(Dcamera->trigSoftware);
		}
	}
	if (index2 == 1)
	{
		if (cameraname == "Hik")
		{
			hikcam->SetTriggerSource(index, 1);
		}
		else if (cameraname == "DahuaCamera")
		{
			//Dcamera->CameraChangeTrig(Dcamera->trigLine0);
		}
	}
	if (index2 == 2)
	{
		if (cameraname == "Hik")
		{
			hikcam->SetTriggerSource(index, 2);
		}
		else if (cameraname == "DahuaCamera")
		{
			//Dcamera->CameraChangeTrig(Dcamera->trigLine1);
		}
	}
	if (index2 == 3)
	{
		if (cameraname == "Hik")
		{
			hikcam->SetTriggerSource(index, 1);
		}
		else if (cameraname == "DahuaCamera")
		{
			//Dcamera->CameraChangeTrig(Dcamera->trigLine2);
		}
	}
}
void CameraClass::on_toolButton_trigger_clicked()
{
	if (ui.comboBox_3->currentIndex() == 0)
	{
		if (cameraname == "Hik")
		{
			hikcam->softTrigger(index);
		}
		else if (cameraname == "DahuaCamera")
		{
			//Dcamera->ExecuteSoftTrig();
		}
	}
}
void CameraClass::on_toolButton_Saveparamater_clicked()
{
	if (cameraname == "Hik")
	{
		hikcam->stopCamera(index);
		hikcam->setUserSet(index);
		hikcam->StartCamera();
	}
}


