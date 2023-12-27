#include "LineWindow.h"

LineWindow::LineWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowMinimizeButtonHint);
	//窗口初始化
	InitWindow();

	//直线检测
	IniTableData_Line();
	IniLineClassObject();

	//开机自动读图
	QString Filepath = QCoreApplication::applicationDirPath() + "/01.png";
	ReadImage(&ho_Image, HTuple(Filepath.toStdString().c_str()));

	//配置文件和XML路径
	configPath = FolderPath() + "/Config/";
	XMLPath = FolderPath() + "/Config/Config.xml";
}

LineWindow::LineWindow(HObject image, int _processID, int modubleID, std::string _modubleName, std::string configPath) {
	ui.setupUi(this);


	nodeName = _modubleName;
	processModbuleID = modubleID;
	processID = _processID;
	XMLPath = configPath + "\\config.xml";
	this->configPath = configPath + "/";
	InitWindow();
	IniTableData_Line();
	IniLineClassObject();
	ho_Image = image;
	showImg(ho_Image, "margin", "green");

}

LineWindow::~LineWindow()
{
	//释放直线new的内存
	delete LineDetect1;
}

//关闭窗口
void LineWindow::on_btn_Hide_clicked()
{
	this->hide();
}
//初始化显示窗口
void LineWindow::InitWindow()
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
void LineWindow::showImg(const HObject &ho_Img, HTuple hv_FillType, HTuple hv_Color)
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
void LineWindow::GiveParameterToWindow()
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
void LineWindow::on_pBtn_ReadImage_clicked()
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
		ReadImage(&ho_Image, h_FilePath);
		GenEmptyObj(&ho_ShowObj);
		showImg(ho_Image, "margin", "green");
	}
}

//图像自适应窗口
void LineWindow::on_pBtn_FitImage_clicked()
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
void LineWindow::on_ckb_ShowObj_stateChanged(int arg1)
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
void LineWindow::on_btn_ClearWindow_clicked()
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

//绘制直线
void LineWindow::on_btn_DrawLine_Line_clicked()
{
	if (ho_Image.Key() == nullptr)
	{
		//图像为空，或者图像被clear
		QMessageBox::information(this, "提示", "图像是空，请先加载图像!", QMessageBox::Ok);
		return;
	}
	SetColor(m_hHalconID, "red");
	SetLineWidth(m_hHalconID, 1);

	HObject ho_XldLine;
	HTuple LineRow1, LineCol1, LineRow2, LineCol2;
	DrawLine(m_hHalconID, &LineRow1, &LineCol1, &LineRow2, &LineCol2);
	HTuple hv_ConcatRow, hv_ConcatCol;
	TupleConcat(LineRow1, LineRow2, &hv_ConcatRow);
	TupleConcat(LineCol1, LineCol2, &hv_ConcatCol);
	GenContourPolygonXld(&ho_XldLine, hv_ConcatRow, hv_ConcatCol);
	ConcatObj(ho_ShowObj, ho_XldLine, &ho_ShowObj);
	//给窗口刷新图像传递参数(主要作用是为了滚轮缩放时显示图形)
	GiveParameterToWindow();
	DispObj(ho_XldLine, m_hHalconID);

	//画搜索方向
	ShowArrow_Line(m_hHalconID, LineRow1, LineCol1, LineRow2, LineCol2);
	//绘制直线参数赋值
	ui.dspb_RowBegin_Line->setValue(LineRow1.TupleReal().D());
	ui.dspb_ColBegin_Line->setValue(LineCol1.TupleReal().D());
	ui.dspb_RowEnd_Line->setValue(LineRow2.TupleReal().D());
	ui.dspb_ColEnd_Line->setValue(LineCol2.TupleReal().D());
}
//清除直线ROI
void LineWindow::on_btn_ClearRoi_Line_clicked()
{
	//清空窗口显示的图形变量
	GenEmptyObj(&ho_ShowObj);
	//显示原图
	showImg(ho_Image, "margin", "green");
}
//绘制箭头
void LineWindow::ShowArrow_Line(HTuple windowId, HTuple LineRow1, HTuple LineCol1, HTuple LineRow2, HTuple LineCol2)
{
	//显示卡尺搜索方向
	HTuple hv_AngleLine;
	AngleLx(LineRow1, LineCol1, LineRow2, LineCol2, &hv_AngleLine);
	//箭头的起始点坐标(计算方式：以卡尺半长为斜边，以绘制的直线与水平轴夹角为角度。分别计算斜边的cos值给x,即col。计算斜边的sin值给y，即row)
	HTuple measureLength1 = HTuple(ui.spb_MeasureLength1_Line->value());
	HTuple hv_Cos, hv_Sin, hv_ArrowRow1, hv_ArrowCol1, hv_ArrowRow2, hv_ArrowCol2;
	TupleCos(hv_AngleLine, &hv_Cos);
	TupleSin(hv_AngleLine, &hv_Sin);
	hv_ArrowRow1 = (LineRow1 + LineRow2) / 2 - measureLength1 * hv_Cos;
	hv_ArrowCol1 = (LineCol1 + LineCol2) / 2 - measureLength1 * hv_Sin;
	hv_ArrowRow2 = (LineRow1 + LineRow2) / 2 + measureLength1 * hv_Cos;
	hv_ArrowCol2 = (LineCol1 + LineCol2) / 2 + measureLength1 * hv_Sin;

	//显示搜索方向
	SetColor(m_hHalconID, "green");
	DispArrow(windowId, hv_ArrowRow1, hv_ArrowCol1, hv_ArrowRow2, hv_ArrowCol2, 5);
	//显示直线方向
	SetColor(m_hHalconID, "red");
	DispArrow(windowId, LineRow1, LineCol1, LineRow2, LineCol2, 5);
}
//直线类对象初始化
void LineWindow::IniLineClassObject()
{
	LineDetect1 = new LineDetect(nodeName, processModbuleID, processID, XMLPath);
}
//运行查找直线结构体参数赋值函数
void LineWindow::SetRunParams_Line(RunParamsStruct_Line &runParams)
{
	//直线抓边roi起始点
	runParams.hv_Row1 = ui.dspb_RowBegin_Line->value();
	runParams.hv_Column1 = ui.dspb_ColBegin_Line->value();
	runParams.hv_Row2 = ui.dspb_RowEnd_Line->value();
	runParams.hv_Column2 = ui.dspb_ColEnd_Line->value();

	//抓边模型需要的抓边参数
	runParams.hv_MeasureLength1 = ui.spb_MeasureLength1_Line->value();		//卡尺半长
	runParams.hv_MeasureLength2 = ui.spb_MeasureLength2_Line->value();		//卡尺半宽
	runParams.hv_MeasureSigma = ui.dspb_MeasureSigma_Line->value();		//平滑值 
	runParams.hv_MeasureThreshold = ui.spb_MeasureThreshold_Line->value();	//边缘阈值
	runParams.hv_MeasureTransition = HTuple(ui.cmb_MeasureTransition_Line->currentText().toStdString().c_str());	//卡尺极性
	runParams.hv_MeasureSelect = HTuple(ui.cmb_MeasureSelect_Line->currentText().toStdString().c_str());		//边缘选择
	runParams.hv_MeasureNum = ui.spb_MeasureNum_Line->value();		    //卡尺个数
	runParams.hv_InstancesNum = 1;		//抓边数量
	runParams.hv_MeasureMinScore = ui.dspb_MinScore_Line->value();     //最小得分
	runParams.hv_DistanceThreshold = ui.dspb_DistanceThreshold_Line->value();   //距离阈值
	runParams.hv_MeasureInterpolation = HTuple(ui.cmb_MeasureInterpolation_Line->currentText().toStdString().c_str());//插值算法

	if (ui.cmb_IsFollow_Line->currentText() == "Yes")
	{
		runParams.isFollow = true;
	}
	else
	{
		runParams.isFollow = false;
	}
}
//检测直线
void LineWindow::on_btn_DetectLine_Line_clicked()
{
	if (ho_Image.Key() == nullptr)
	{
		//图像为空，或者图像被clear
		QMessageBox::information(this, "提示", "图像是空，请先加载图像!", QMessageBox::Ok);
		return;
	}
	int ret = 1;
	//找边运行
	QDateTime startTime = QDateTime::currentDateTime();
	ResultParamsStruct_Line resultParams;
	ret = slot_FindLine(resultParams);
	QDateTime endTime = QDateTime::currentDateTime();
	qint64 intervalTimeMS = startTime.msecsTo(endTime);
	//刷新结果
	SetTableData_Line(resultParams, intervalTimeMS);
}
//初始化直线结果显示表格
void LineWindow::IniTableData_Line()
{
	QTableWidgetItem   *hearderItem;
	QStringList hearderText;
	hearderText << "X" << "Y";
	ui.tablewidget_PointsResult_Line->setColumnCount(hearderText.count());
	for (int i = 0; i < ui.tablewidget_PointsResult_Line->columnCount(); i++)
	{
		hearderItem = new QTableWidgetItem(hearderText.at(i));
		QFont font = hearderItem->font();
		font.setBold(true);//设置为粗体
		font.setPointSize(12);//设置字体大小
		hearderItem->setTextColor(Qt::red);//字体颜色
		hearderItem->setFont(font);//设置字体
		ui.tablewidget_PointsResult_Line->setHorizontalHeaderItem(i, hearderItem);
	}
}
//设置直线结果显示表格数据
void LineWindow::SetTableData_Line(const ResultParamsStruct_Line &resultParams, qint64 Ct)
{
	//清空结果表格数据
	ui.tablewidget_PointsResult_Line->clearContents();
	//判断是否找到直线
	if (resultParams.hv_RetNum == 0)
	{
		//没有找到直线，退出
		GenEmptyObj(&ho_ShowObj);
		showImg(ho_Image, "margin", "green");
		return;
	}
	//刷新图像
	GenEmptyObj(&ho_ShowObj);
	ConcatObj(ho_ShowObj, resultParams.ho_Contour_Line, &ho_ShowObj);
	ConcatObj(ho_ShowObj, resultParams.ho_Contour_Calipers, &ho_ShowObj);
	ConcatObj(ho_ShowObj, resultParams.ho_Contour_CrossPoints, &ho_ShowObj);
	showImg(ho_Image, "margin", "green");
	//刷新时间
	ui.lbl_RunLineCT->setText("CT:" + QString::number(Ct) + "ms");
	//刷新卡尺找到的所有点坐标
	int count = resultParams.hv_PointsNum.I();
	ui.tablewidget_PointsResult_Line->setRowCount(count);
	for (int i = 0; i < count; i++)
	{
		QTableWidgetItem *item;
		QString str;
		double d = resultParams.hv_PointsColumn[0].D();
		//X
		str = QString::number(resultParams.hv_PointsColumn[i].D(), 'f', 2);
		item = new QTableWidgetItem(str, 1000);
		item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
		ui.tablewidget_PointsResult_Line->setItem(i, 0, item);
		//Y
		str = QString::number(resultParams.hv_PointsRow[i].D(), 'f', 2);
		item = new QTableWidgetItem(str, 1000);
		item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
		ui.tablewidget_PointsResult_Line->setItem(i, 1, item);

	}
	//刷新直线起始坐标
	ui.txt_Row1_Line->setText(QString::number(resultParams.hv_LineRowBegin.D(), 'f', 2));
	ui.txt_Col1_Line->setText(QString::number(resultParams.hv_LineColumnBegin.D(), 'f', 2));
	ui.txt_Row2_Line->setText(QString::number(resultParams.hv_LineRowEnd.D(), 'f', 2));
	ui.txt_Col2_Line->setText(QString::number(resultParams.hv_LineColumnEnd.D(), 'f', 2));
}
//直线参数保存
void LineWindow::on_btn_SaveLineData_clicked()
{
	int ret = 1;
	//设置抓边参数
	SetRunParams_Line(hv_RunParamsLine);
	//保存直线运行参数
	ret = dataIOC.WriteParams_Line(configPath, XMLPath, hv_RunParamsLine, processID, nodeName, processModbuleID);
	if (ret != 0)
	{
		QMessageBox::information(this, "提示", "参数保存失败", QMessageBox::Ok);
		return;
	}
}
//直线参数读取
void LineWindow::on_btn_LoadLineData_clicked()
{
	ErrorCode_Xml errorCode;
	//读取直线参数
	errorCode = dataIOC.ReadParams_Line(configPath, XMLPath, hv_RunParamsLine, processID, nodeName, processModbuleID);
	if (errorCode != Ok_Xml)
	{
		QMessageBox::information(this, "提示", "参数读取失败", QMessageBox::Ok);
		return;
	}
	//参数更新到窗口
	UpdateLineDataWindow(hv_RunParamsLine);
}
//更新直线检测运行参数到窗口
void LineWindow::UpdateLineDataWindow(const RunParamsStruct_Line &RunParams)
{
	//直线抓边roi起始点
	ui.dspb_RowBegin_Line->setValue(RunParams.hv_Row1.TupleReal().D());
	ui.dspb_ColBegin_Line->setValue(RunParams.hv_Column1.TupleReal().D());
	ui.dspb_RowEnd_Line->setValue(RunParams.hv_Row2.TupleReal().D());
	ui.dspb_ColEnd_Line->setValue(RunParams.hv_Column2.TupleReal().D());

	//抓边模型需要的抓边参数
	ui.spb_MeasureLength1_Line->setValue(RunParams.hv_MeasureLength1.TupleInt().I());		//卡尺半长
	ui.spb_MeasureLength2_Line->setValue(RunParams.hv_MeasureLength2.TupleInt().I());		//卡尺半宽
	ui.dspb_MeasureSigma_Line->setValue(RunParams.hv_MeasureSigma.TupleReal().D());		//平滑值 
	ui.spb_MeasureThreshold_Line->setValue(RunParams.hv_MeasureThreshold);	//边缘阈值
	ui.cmb_MeasureTransition_Line->setCurrentText(QString::fromUtf8(RunParams.hv_MeasureTransition.S().Text()));	//卡尺极性
	ui.cmb_MeasureSelect_Line->setCurrentText(QString::fromUtf8(RunParams.hv_MeasureSelect.S().Text()));		//边缘选择
	ui.spb_MeasureNum_Line->setValue(RunParams.hv_MeasureNum.TupleInt().I());		    //卡尺个数
	ui.dspb_MinScore_Line->setValue(RunParams.hv_MeasureMinScore.TupleReal().D());     //最小得分
	ui.dspb_DistanceThreshold_Line->setValue(RunParams.hv_DistanceThreshold.TupleReal().D());   //距离阈值
	ui.cmb_MeasureInterpolation_Line->setCurrentText(QString::fromUtf8(RunParams.hv_MeasureInterpolation.S().Text()));//插值算法
	if (RunParams.isFollow)
	{
		ui.cmb_IsFollow_Line->setCurrentText("Yes");
	}
	else
	{
		ui.cmb_IsFollow_Line->setCurrentText("No");
	}
}
//检测直线槽函数
int LineWindow::slot_FindLine(ResultParamsStruct_Line &resultParams)
{
	try
	{
		int ret = 1;
		//XML读取参数
		ErrorCode_Xml errorCode = dataIOC.ReadParams_Line(configPath, XMLPath, hv_RunParamsLine, processID, nodeName, processModbuleID);
		if (errorCode != Ok_Xml)
		{
			//XML读取失败，给默认值
			hv_RunParamsLine.hv_Row1 = 10;
			hv_RunParamsLine.hv_Column1 = 10;
			hv_RunParamsLine.hv_Row2 = 10;
			hv_RunParamsLine.hv_Column2 = 50;

			//抓边模型需要的抓边参数
			hv_RunParamsLine.hv_MeasureLength1 = 50;		
			hv_RunParamsLine.hv_MeasureLength2 = 5;		
			hv_RunParamsLine.hv_MeasureSigma = 1.0;		
			hv_RunParamsLine.hv_MeasureThreshold = 20;	
			hv_RunParamsLine.hv_MeasureTransition = "all";	
			hv_RunParamsLine.hv_MeasureSelect = "first";		
			hv_RunParamsLine.hv_MeasureNum = 10;		    
			hv_RunParamsLine.hv_InstancesNum = 1;		
			hv_RunParamsLine.hv_MeasureMinScore = 0.5;     
			hv_RunParamsLine.hv_DistanceThreshold = 3.5;   
			hv_RunParamsLine.hv_MeasureInterpolation = "nearest_neighbor";
			hv_RunParamsLine.isFollow = false;                
			//保存直线检测运行参数
			ret = dataIOC.WriteParams_Line(configPath, XMLPath, hv_RunParamsLine, processID, nodeName, processModbuleID);
			if (ret != 0)
			{
				return ret;
			}
		}
		//调用算法
		return LineDetect1->FindLine(ho_Image, hv_RunParamsLine, resultParams);
	}
	catch (...)
	{
		return -1;
	}
}
//exe路径
string LineWindow::FolderPath()
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
string LineWindow::strReplaceAll(const string& strResource, const string& strOld, const string& strNew)
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
