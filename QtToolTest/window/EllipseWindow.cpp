#include "EllipseWindow.h"

EllipseWindow::EllipseWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowMinimizeButtonHint);
	//窗口初始化
	InitWindow();
	//椭圆检测
	IniTableData_Ellipse();
	EllipseDetect1 = new EllipseDetect();

	//开机自动读图
	QString Filepath = QCoreApplication::applicationDirPath() + "/01.png";
	ReadImage(&ho_Image, HTuple(Filepath.toStdString().c_str()));

	//配置文件和XML路径
	configPath = FolderPath() + "/Config/";
	XMLPath = FolderPath() + "/Config/Config.xml";
}

EllipseWindow::EllipseWindow(HObject image, int _processID, int modubleID, std::string _modubleName, std::string configPath) {
	ui.setupUi(this);
	nodeName = _modubleName;
	processModbuleID = modubleID;
	processID = _processID;
	XMLPath = configPath + "/Config.xml";
	this->configPath = configPath + "/";

	//窗口初始化
	InitWindow();
	//椭圆检测
	IniTableData_Ellipse();
	EllipseDetect1 = new EllipseDetect(nodeName, processModbuleID, processID, XMLPath);

	ho_Image = image;
	showImg(ho_Image, "margin", "green");
}
EllipseWindow::~EllipseWindow()
{
	delete EllipseDetect1;
}
//关闭窗口
void EllipseWindow::on_btn_Hide_clicked()
{
	this->hide();
}
//初始化显示窗口
void EllipseWindow::InitWindow()
{
	//设置halcon的文件路径为utf8，解决中文乱码
	SetSystem("filename_encoding", "utf8");
	//设置这行代码，可以让鼠标移动时，触发mouseMove，随时可以看到坐标。否则，只有在鼠标按下时才可以看到坐标
	ui.lbl_Window->setMouseTracking(true);
	//生成空图像
	GenEmptyObj(&ho_Image);
	GenEmptyObj(&ho_ShowObj);
	ho_Image.Clear();
	m_hHalconID = NULL;
	m_hLabelID = (Hlong)ui.lbl_Window->winId();

}

//显示图像
void EllipseWindow::showImg(const HObject &ho_Img, HTuple hv_FillType, HTuple hv_Color)
{
	if (ho_Img.Key() == nullptr)
	{
		//图像为空，或者图像被clear
		QMessageBox::information(this, "提示", "图像是空，请先加载图像!", QMessageBox::Ok);
		return;
	}

	//判断窗口句柄
	if (m_hHalconID != NULL)
	{
		//如果有图像，则先清空图像
		DetachBackgroundFromWindow(m_hHalconID);
	}
	else
	{
		//打开窗口
		OpenWindow(0, 0, ui.lbl_Window->width(), ui.lbl_Window->height(), m_hLabelID, "visible", "", &m_hHalconID);
	}

	//设置图形显示属性
	SetDraw(m_hHalconID, hv_FillType);
	SetColor(m_hHalconID, hv_Color);
	SetLineWidth(m_hHalconID, 1);
	//设置窗口显示变量
	ui.lbl_Window->setHalconWnd(ho_Img, ho_ShowObj, isShowObj, m_hHalconID, ui.lbl_Status);

	//获取图像大小
	GetImageSize(ho_Img, &m_imgWidth, &m_imgHeight);
	//获取缩放系数
	TupleMin2(1.0 * ui.lbl_Window->width() / m_imgWidth, 1.0 * ui.lbl_Window->height() / m_imgHeight, &m_hvScaledRate);
	//缩放图像
	ZoomImageFactor(ho_Img, &m_hResizedImg, m_hvScaledRate, m_hvScaledRate, "constant");
	//获取缩放后的大小
	GetImageSize(m_hResizedImg, &m_scaledWidth, &m_scaledHeight);
	//打开窗口
	if (1.0 * ui.lbl_Window->width() / m_imgWidth < 1.0 * ui.lbl_Window->height() / m_imgHeight)
	{
		SetWindowExtents(m_hHalconID, ui.lbl_Window->height() / 2.0 - m_scaledHeight / 2.0, 0, ui.lbl_Window->width(), m_scaledHeight);
	}
	else
	{
		SetWindowExtents(m_hHalconID, 0, ui.lbl_Window->width() / 2.0 - m_scaledWidth / 2.0, m_scaledWidth, ui.lbl_Window->height());

	}
	SetPart(m_hHalconID, 0, 0, m_imgHeight - 1, m_imgWidth - 1);
	//这句显示图像，不会闪烁(把图像设置成窗口的背景图)
	AttachBackgroundToWindow(ho_Img, m_hHalconID);

	//显示图形
	if (isShowObj)
	{
		SetCheck("give_error");
		try
		{
			DispObj(ho_ShowObj, m_hHalconID);
		}
		catch (...)
		{
			return;
		}
		SetCheck("give_error");
	}
}

//给窗口刷新图像传递参数(主要作用是为了滚轮缩放时显示图形)
void EllipseWindow::GiveParameterToWindow()
{
	if (ho_Image.Key() == nullptr)
	{
		QMessageBox::information(this, "提示", "图像是空，请先加载图像!", QMessageBox::Ok);
		return;
	}

	//判断窗口句柄
	if (m_hHalconID != NULL)
	{
		//如果有图像，则先清空图像
		//DetachBackgroundFromWindow(m_hHalconID);
	}
	else
	{
		//打开窗口
		OpenWindow(0, 0, ui.lbl_Window->width(), ui.lbl_Window->height(), m_hLabelID, "visible", "", &m_hHalconID);
	}

	//设置图形显示属性
	SetDraw(m_hHalconID, "margin");
	SetColor(m_hHalconID, "red");
	SetLineWidth(m_hHalconID, 1);
	//设置窗口显示变量
	ui.lbl_Window->setHalconWnd(ho_Image, ho_ShowObj, isShowObj, m_hHalconID, ui.lbl_Status);

}

//打开图片
void EllipseWindow::on_pBtn_ReadImage_clicked()
{
	QFileDialog dlg;
	dlg.setAcceptMode(QFileDialog::AcceptOpen);
	dlg.setFileMode(QFileDialog::ExistingFile);
	QString filePath = dlg.getOpenFileName();
	std::string str1 = filePath.toStdString();
	const char *str = str1.c_str();
	HTuple h_FilePath(str);
	if (!filePath.isEmpty())
	{
		QImage image;
		//cv::Mat img = cv::imread(filePath.toStdString());
		//image = Mat2QImage(img);

		ReadImage(&ho_Image, h_FilePath);
		GenEmptyObj(&ho_ShowObj);
		showImg(ho_Image, "margin", "green");
	}
}

//图像自适应窗口
void EllipseWindow::on_pBtn_FitImage_clicked()
{
	if (ho_Image.Key() == nullptr)
	{
		//图像为空，或者图像被clear
		QMessageBox::information(this, "提示", "图像是空，请先加载图像!", QMessageBox::Ok);
		return;
	}
	showImg(ho_Image, "margin", "green");
}
//是否显示图形复选框
void EllipseWindow::on_ckb_ShowObj_stateChanged(int arg1)
{
	if (arg1 == Qt::Checked)
	{
		isShowObj = true;
	}
	else
	{
		isShowObj = false;
	}
	//给窗口刷新图像传递参数(主要作用是为了滚轮缩放时显示图形)
	GiveParameterToWindow();
}
//清空窗口
void EllipseWindow::on_btn_ClearWindow_clicked()
{
	if (ho_Image.Key() == nullptr)
	{
		//图像为空，或者图像被clear
		QMessageBox::information(this, "提示", "图像是空，请先加载图像!", QMessageBox::Ok);
		return;
	}
	//清空窗口显示的图形变量
	GenEmptyObj(&ho_ShowObj);
	//显示原图
	showImg(ho_Image, "margin", "green");
}
//****************************************************************************************************
//****************椭圆检测相关函数***********************
//初始化椭圆结果显示表格
void EllipseWindow::IniTableData_Ellipse()
{
	QTableWidgetItem   *hearderItem;
	QStringList hearderText;
	hearderText << "X" << "Y";
	ui.tablewidget_PointsResult_Ellipse->setColumnCount(hearderText.count());
	for (int i = 0; i < ui.tablewidget_PointsResult_Ellipse->columnCount(); i++)
	{
		hearderItem = new QTableWidgetItem(hearderText.at(i));
		QFont font = hearderItem->font();
		font.setBold(true);//设置为粗体
		font.setPointSize(12);//设置字体大小
		hearderItem->setTextColor(Qt::red);//字体颜色
		hearderItem->setFont(font);//设置字体
		ui.tablewidget_PointsResult_Ellipse->setHorizontalHeaderItem(i, hearderItem);
	}
}
//绘制椭圆
void EllipseWindow::on_btn_DrawEllipse_Ellipse_clicked()
{
	if (ho_Image.Key() == nullptr)
	{
		//图像为空，或者图像被clear
		QMessageBox::information(this, "提示", "图像是空，请先加载图像!", QMessageBox::Ok);
		return;
	}
	SetColor(m_hHalconID, "red");
	SetLineWidth(m_hHalconID, 1);

	HObject ho_XldEllipse;
	HTuple Row, Col, Angle, Radius1, Radius2;
	DrawEllipse(m_hHalconID, &Row, &Col, &Angle, &Radius1, &Radius2);
	GenEllipseContourXld(&ho_XldEllipse, Row, Col, Angle, Radius1, Radius2, 0, HTuple(360).TupleRad(), "positive", 1.5);

	//绘制椭圆参数赋值
	ui.dspb_CenterRow_Ellipse->setValue(Row.TupleReal().D());
	ui.dspb_CenterCol_Ellipse->setValue(Col.TupleReal().D());
	ui.dspb_Angle_Ellipse->setValue(Angle.TupleDeg().TupleReal().D());
	ui.dspb_Radius1_Ellipse->setValue(Radius1.TupleReal().D());
	ui.dspb_Radius2_Ellipse->setValue(Radius2.TupleReal().D());

	ConcatObj(ho_ShowObj, ho_XldEllipse, &ho_ShowObj);
	//给窗口刷新图像传递参数(主要作用是为了滚轮缩放时显示图形)
	GiveParameterToWindow();
	SetColor(m_hHalconID, "green");
	DispObj(ho_XldEllipse, m_hHalconID);

	//画搜索方向
	//箭头的起始点坐标(计算方式：以绘制的矩形半长为斜边，以绘制的矩形角度为角度。分别计算斜边的cos值给x,即col。计算斜边的sin值给y，即row)
	HTuple measureLength1 = HTuple(ui.spb_MeasureLength1_Ellipse->value());
	HTuple hv_Cos, hv_Sin, hv_ArrowRow1, hv_ArrowCol1, hv_ArrowRow2, hv_ArrowCol2;
	TupleCos(Angle, &hv_Cos);
	TupleSin(Angle, &hv_Sin);
	hv_ArrowRow1 = Row;
	hv_ArrowCol1 = Col;
	hv_ArrowRow2 = Row + 2 * Radius1 * hv_Cos;
	hv_ArrowCol2 = Col + 2 * Radius1 * hv_Sin;

	//显示搜索方向
	SetColor(m_hHalconID, "red");
	DispArrow(m_hHalconID, hv_ArrowRow1, hv_ArrowCol1, hv_ArrowRow2, hv_ArrowCol2, 5);
}
//检测椭圆
void EllipseWindow::on_btn_DetectEllipse_Ellipse_clicked()
{
	if (ho_Image.Key() == nullptr)
	{
		//图像为空，或者图像被clear
		QMessageBox::information(this, "提示", "图像是空，请先加载图像!", QMessageBox::Ok);
		return;
	}
	int ret = 1;
	//找椭圆运行
	QDateTime startTime = QDateTime::currentDateTime();
	ResultParamsStruct_Ellipse resultParams;
	ret = slot_FindEllipse(resultParams);
	QDateTime endTime = QDateTime::currentDateTime();
	qint64 intervalTimeMS = startTime.msecsTo(endTime);
	//刷新结果
	SetTableData_Ellipse(resultParams, intervalTimeMS);
}
//保存椭圆参数
void EllipseWindow::on_btn_SaveData_Ellipse_clicked()
{
	int ret = 1;
	//设置抓椭圆参数
	SetRunParams_Ellipse(hv_RunParamsEllipse);
	//保存椭圆运行参数
	ret = dataIOC.WriteParams_Ellipse(configPath, XMLPath, hv_RunParamsEllipse, processID, nodeName, processModbuleID);
	if (ret != 0)
	{
		QMessageBox::information(this, "提示", "参数保存失败", QMessageBox::Ok);
		return;
	}
}
//加载椭圆参数
void EllipseWindow::on_btn_LoadData_Ellipse_clicked()
{
	ErrorCode_Xml errorCode;
	//读取椭圆参数
	errorCode = dataIOC.ReadParams_Ellipse(configPath, XMLPath, hv_RunParamsEllipse, processID, nodeName, processModbuleID);
	if (errorCode != Ok_Xml)
	{
		QMessageBox::information(this, "提示", "参数读取失败", QMessageBox::Ok);
		return;
	}
	//参数更新到窗口
	UpdateEllipseDataWindow(hv_RunParamsEllipse);
}
//清除ROI
void EllipseWindow::on_btn_ClearRoi_Ellipse_clicked()
{
	//清空窗口显示的图形变量
	GenEmptyObj(&ho_ShowObj);
	//显示原图
	showImg(ho_Image, "margin", "green");
}
//更新椭圆检测运行参数到窗口
void EllipseWindow::UpdateEllipseDataWindow(const RunParamsStruct_Ellipse &RunParams)
{
	//直线抓边roi起始点
	ui.dspb_CenterRow_Ellipse->setValue(RunParams.hv_Row.TupleReal().D());
	ui.dspb_CenterCol_Ellipse->setValue(RunParams.hv_Column.TupleReal().D());
	ui.dspb_Angle_Ellipse->setValue(RunParams.hv_Angle.TupleReal().D());
	ui.dspb_Radius1_Ellipse->setValue(RunParams.hv_Radius1.TupleReal().D());
	ui.dspb_Radius2_Ellipse->setValue(RunParams.hv_Radius2.TupleReal().D());

	//抓边模型需要的抓边参数
	ui.spb_MeasureLength1_Ellipse->setValue(RunParams.hv_MeasureLength1.TupleInt().I());		//卡尺半长
	ui.spb_MeasureLength2_Ellipse->setValue(RunParams.hv_MeasureLength2.TupleInt().I());		//卡尺半宽
	ui.dspb_MeasureSigma_Ellipse->setValue(RunParams.hv_MeasureSigma.TupleReal().D());		//平滑值 
	ui.spb_MeasureThreshold_Ellipse->setValue(RunParams.hv_MeasureThreshold);	//边缘阈值
	ui.cmb_MeasureTransition_Ellipse->setCurrentText(QString::fromUtf8(RunParams.hv_MeasureTransition.S().Text()));	//卡尺极性
	ui.cmb_MeasureSelect_Ellipse->setCurrentText(QString::fromUtf8(RunParams.hv_MeasureSelect.S().Text()));		//边缘选择
	ui.spb_MeasureNum_Ellipse->setValue(RunParams.hv_MeasureNum.TupleInt().I());		    //卡尺个数
	ui.dspb_MinScore_Ellipse->setValue(RunParams.hv_MeasureMinScore.TupleReal().D());     //最小得分
	ui.dspb_DistanceThreshold_Ellipse->setValue(RunParams.hv_DistanceThreshold.TupleReal().D());   //距离阈值
	ui.cmb_MeasureInterpolation_Ellipse->setCurrentText(QString::fromUtf8(RunParams.hv_MeasureInterpolation.S().Text()));//插值算法
	if (RunParams.isFollow)
	{
		ui.cmb_IsFollow_Ellipse->setCurrentText("Yes");
	}
	else
	{
		ui.cmb_IsFollow_Ellipse->setCurrentText("No");
	}
}
//运行查找椭圆结构体参数赋值函数
void EllipseWindow::SetRunParams_Ellipse(RunParamsStruct_Ellipse &RunParams)
{
	//roi起始点
	RunParams.hv_Row = ui.dspb_CenterRow_Ellipse->value();
	RunParams.hv_Column = ui.dspb_CenterCol_Ellipse->value();
	RunParams.hv_Angle = ui.dspb_Angle_Ellipse->value();
	RunParams.hv_Radius1 = ui.dspb_Radius1_Ellipse->value();
	RunParams.hv_Radius2 = ui.dspb_Radius2_Ellipse->value();

	//模型需要的参数
	RunParams.hv_MeasureLength1 = ui.spb_MeasureLength1_Ellipse->value();		//卡尺半长
	RunParams.hv_MeasureLength2 = ui.spb_MeasureLength2_Ellipse->value();		//卡尺半宽
	RunParams.hv_MeasureSigma = ui.dspb_MeasureSigma_Ellipse->value();		//平滑值 
	RunParams.hv_MeasureThreshold = ui.spb_MeasureThreshold_Ellipse->value();	//边缘阈值
	RunParams.hv_MeasureTransition = HTuple(ui.cmb_MeasureTransition_Ellipse->currentText().toStdString().c_str());	//卡尺极性
	RunParams.hv_MeasureSelect = HTuple(ui.cmb_MeasureSelect_Ellipse->currentText().toStdString().c_str());		//边缘选择
	RunParams.hv_MeasureNum = ui.spb_MeasureNum_Ellipse->value();		    //卡尺个数
	RunParams.hv_InstancesNum = 1;		//数量
	RunParams.hv_MeasureMinScore = ui.dspb_MinScore_Ellipse->value();     //最小得分
	RunParams.hv_DistanceThreshold = ui.dspb_DistanceThreshold_Ellipse->value();   //距离阈值
	RunParams.hv_MeasureInterpolation = HTuple(ui.cmb_MeasureInterpolation_Ellipse->currentText().toStdString().c_str());//插值算法

	if (ui.cmb_IsFollow_Ellipse->currentText() == "Yes")
	{
		RunParams.isFollow = true;
	}
	else
	{
		RunParams.isFollow = false;
	}
}
//设置椭圆结果显示表格数据
void EllipseWindow::SetTableData_Ellipse(const ResultParamsStruct_Ellipse &resultParams, qint64 Ct)
{
	//清空结果表格数据
	ui.tablewidget_PointsResult_Ellipse->clearContents();
	//判断是否找到椭圆
	if (resultParams.hv_RetNum == 0)
	{
		//没有找到，退出
		GenEmptyObj(&ho_ShowObj);
		showImg(ho_Image, "margin", "green");
		return;
	}
	//刷新图像
	GenEmptyObj(&ho_ShowObj);
	ConcatObj(ho_ShowObj, resultParams.ho_Contour_Ellipse, &ho_ShowObj);
	ConcatObj(ho_ShowObj, resultParams.ho_Contour_Calipers, &ho_ShowObj);
	ConcatObj(ho_ShowObj, resultParams.ho_Contour_CrossPoints, &ho_ShowObj);
	showImg(ho_Image, "margin", "green");
	//刷新时间
	ui.lbl_RunCT_Ellipse->setText("CT:" + QString::number(Ct) + "ms");
	//刷新卡尺找到的所有点坐标
	int count = resultParams.hv_PointsNum.I();
	ui.tablewidget_PointsResult_Ellipse->setRowCount(count);
	for (int i = 0; i < count; i++)
	{
		QTableWidgetItem *item;
		QString str;
		double d = resultParams.hv_PointsColumn[0].D();
		//X
		str = QString::number(resultParams.hv_PointsColumn[i].D(), 'f', 2);
		item = new QTableWidgetItem(str, 1000);
		item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
		ui.tablewidget_PointsResult_Ellipse->setItem(i, 0, item);
		//Y
		str = QString::number(resultParams.hv_PointsRow[i].D(), 'f', 2);
		item = new QTableWidgetItem(str, 1000);
		item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
		ui.tablewidget_PointsResult_Ellipse->setItem(i, 1, item);

	}
	//刷新椭圆结果参数
	ui.txt_Col_Ellipse->setText(QString::number(resultParams.hv_EllipseColumn.D(), 'f', 2));
	ui.txt_Row_Ellipse->setText(QString::number(resultParams.hv_EllipseRow.D(), 'f', 2));
	ui.txt_Angle_Ellipse->setText(QString::number(resultParams.hv_EllipseAngle.D(), 'f', 2));
	ui.txt_Radius1_Ellipse->setText(QString::number(resultParams.hv_EllipseRadius1.D(), 'f', 2));
	ui.txt_Radius2_Ellipse->setText(QString::number(resultParams.hv_EllipseRadius2.D(), 'f', 2));
}
//检测椭圆槽函数
int EllipseWindow::slot_FindEllipse(ResultParamsStruct_Ellipse &resultParams)
{
	try
	{
		int ret = 1;
		//XML读取参数
		ErrorCode_Xml errorCode = dataIOC.ReadParams_Ellipse(configPath, XMLPath, hv_RunParamsEllipse, processID, nodeName, processModbuleID);
		if (errorCode != Ok_Xml)
		{
			//XML读取失败，给默认值
			hv_RunParamsEllipse.hv_Row = 10;
			hv_RunParamsEllipse.hv_Column = 10;
			hv_RunParamsEllipse.hv_Angle = 0;
			hv_RunParamsEllipse.hv_Radius1 = 50;
			hv_RunParamsEllipse.hv_Radius2 = 25;

			//抓椭圆模型需要的抓边参数
			hv_RunParamsEllipse.hv_MeasureLength1 = 50;
			hv_RunParamsEllipse.hv_MeasureLength2 = 5;
			hv_RunParamsEllipse.hv_MeasureSigma = 1.0;
			hv_RunParamsEllipse.hv_MeasureThreshold = 20;
			hv_RunParamsEllipse.hv_MeasureTransition = "all";
			hv_RunParamsEllipse.hv_MeasureSelect = "first";
			hv_RunParamsEllipse.hv_MeasureNum = 10;
			hv_RunParamsEllipse.hv_InstancesNum = 1;
			hv_RunParamsEllipse.hv_MeasureMinScore = 0.5;
			hv_RunParamsEllipse.hv_DistanceThreshold = 3.5;
			hv_RunParamsEllipse.hv_MeasureInterpolation = "nearest_neighbor";
			hv_RunParamsEllipse.isFollow = false;
			//保存椭圆检测运行参数
			ret = dataIOC.WriteParams_Ellipse(configPath, XMLPath, hv_RunParamsEllipse, processID, nodeName, processModbuleID);
			if (ret != 0)
			{
				return ret;
			}
		}
		//调用算法
		return EllipseDetect1->FindEllipse(ho_Image, hv_RunParamsEllipse, resultParams);
	}
	catch (...)
	{
		return -1;
	}
}
//exe路径
string EllipseWindow::FolderPath()
{
	char strBuf[256] = { 0 };
	GetModuleFileNameA(NULL, strBuf, sizeof(strBuf));
	string strTemp = strBuf;
	if (strTemp.empty())
		return strTemp;

	strTemp = strReplaceAll(strTemp, "\\", "/");
	string::size_type pos = strTemp.rfind("/");
	if (string::npos != pos)
		strTemp = strTemp.substr(0, pos);
	else
		strTemp = "";

	return strTemp;
}
//返回一个不含strOld
string EllipseWindow::strReplaceAll(const string& strResource, const string& strOld, const string& strNew)
{
	string::size_type pos = 0;
	string strTemp = strResource;
	do
	{
		if ((pos = strTemp.find(strOld)) != string::npos)
		{
			strTemp.replace(pos, strOld.length(), strNew);
		}
	} while (pos != string::npos);
	return strTemp;
}