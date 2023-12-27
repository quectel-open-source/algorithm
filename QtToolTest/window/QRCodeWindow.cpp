#include "QRCodeWindow.h"

QRCodeWindow::QRCodeWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowMinimizeButtonHint);
	//窗口初始化
	InitWindow();
	//二维码检测
	IniTableData_Code2d();
	IniCode2dClassObject();
}

QRCodeWindow::QRCodeWindow(HObject image, int _processID, int modubleID, std::string _modubleName, std::string configPath) {
	ui.setupUi(this);
	nodeName = _modubleName;
	processModbuleID = modubleID;
	processID = _processID;
	XMLPath = configPath+ "\\config.xml";
	this->configPath = configPath + "/";
	InitWindow();
	IniTableData_Code2d();
	IniCode2dClassObject();
	ho_Image = image;
	showImg(ho_Image, "margin", "green");
}

QRCodeWindow::~QRCodeWindow()
{
	//释放二维码内存
	delete code2dParams1;
}
//关闭窗口
void QRCodeWindow::on_btn_Hide_clicked()
{
	this->hide();
}
//初始化显示窗口
void QRCodeWindow::InitWindow()
{

	/*OpenWindow(0, 0, ui.lbl_Window->width(), ui.lbl_Window->height(), (Hlong)ui.lbl_Window->winId(), "", "", &hv_WindowHandle);
	ui.lbl_Window->installEventFilter(this);
	ui.lbl_Window->setMouseTracking(true);
	ROIControl = new ROIController(hv_WindowHandle, "MSA");
	ROIControl->View_MSA = this;
	widthImage = 0, heightImage = 0;*/

	//设置halcon的文件路径为utf8，解决中文乱码
	SetSystem("filename_encoding", "utf8");
	//设置这行代码，可以让鼠标移动时，触发mouseMove，随时可以看到坐标。否则，只有在鼠标按下时才可以看到坐标
	ui.lbl_Window->setMouseTracking(true);
	//生成空图像
	GenEmptyObj(&ho_Image);
	ho_Image.Clear();
	m_hHalconID = NULL;
	m_hLabelID = (Hlong)ui.lbl_Window->winId();

}

//显示图像
void QRCodeWindow::showImg(const HObject &ho_Img, HTuple hv_FillType, HTuple hv_Color)
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
void QRCodeWindow::GiveParameterToWindow()
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
void QRCodeWindow::on_pBtn_ReadImage_clicked()
{
	//QString path = QFileDialog::getOpenFileName(this, "加载图像", "./", "图像文件(*.bmp *.png *.jpg)");
	//QFileInfo fileInfo(path);
	//QString dir = fileInfo.path();

	//if (!path.isEmpty())
	//{
	//	ListFiles(dir.toStdString().c_str(), "files", &m_imgFiles);

	//	TupleRegexpSelect(m_imgFiles, HTuple("\\.bmp|png|jpg").Append("ignore_case"), &m_imgFiles);


	//	for (int i = 0; i < m_imgFiles.Length(); i++)
	//	{

	//		QString currentPath = m_imgFiles[i];
	//		currentPath.replace("\\", "/");

	//		if (currentPath == path)
	//		{
	//			currentIndex = i;
	//			ReadImage(&ho_Image, m_imgFiles[i]);
	//			showImg();
	//		}

	//	}
	//}


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
void QRCodeWindow::on_pBtn_FitImage_clicked()
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
void QRCodeWindow::on_ckb_ShowObj_stateChanged(int arg1)
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
void QRCodeWindow::on_btn_ClearWindow_clicked()
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
//****************二维码检测相关函数***********************
//二维码类对象初始化
void QRCodeWindow::IniCode2dClassObject()
{
	code2dParams1 = new QRCodeDetect(nodeName, processModbuleID, processID, XMLPath);
}
//运行查找二维码结构体参数赋值函数
void QRCodeWindow::SetRunParams_Code2d(RunParamsStruct_Code2d &runParams)
{
	//设置二维码工具名称
	runParams.hv_CodeNum = ui.spb_CodeNum_Code2d->value();
	runParams.ho_SearchRegion = SearchRoi_Code2d;

	string strTemp = ui.txt_HeadChar_Code2d->text().trimmed().toStdString().c_str();
	runParams.hv_HeadChar = HTuple(strTemp.c_str());

	strTemp = ui.txt_EndChar_Code2d->text().trimmed().toStdString().c_str();
	runParams.hv_EndChar = HTuple(strTemp.c_str());
	
	strTemp = ui.txt_ContainChar_Code2d->text().trimmed().toStdString().c_str();
	runParams.hv_ContainChar = HTuple(strTemp.c_str());
	
	strTemp = ui.txt_NotContainChar_Code2d->text().trimmed().toStdString().c_str();
	runParams.hv_NotContainChar = HTuple(strTemp.c_str());
	
	strTemp = ui.txt_NotContainChar_Code2d->text().trimmed().toStdString().c_str();
	runParams.hv_NotContainChar = HTuple(strTemp.c_str());
	
	runParams.hv_CodeLength_Run = HTuple(ui.spb_CodeLength_Code2d->value());
	runParams.hv_TimeOut = ui.spb_TimeOut_Code2d->value();

	CodeTypeStruct_Code2d CodeTypes;
	runParams.hv_CodeType_Run.Clear();
	if (ui.ckb_Aztec_Code2d->isChecked())
	{
		runParams.hv_CodeType_Run.Append(CodeTypes.Aztec);
	}
	if (ui.ckb_DM_Code2d->isChecked())
	{
		runParams.hv_CodeType_Run.Append(CodeTypes.DM);
	}
	if (ui.ckb_GS1Aztec_Code2d->isChecked())
	{
		runParams.hv_CodeType_Run.Append(CodeTypes.GS1Aztec);
	}
	if (ui.ckb_GS1DM_Code2d->isChecked())
	{
		runParams.hv_CodeType_Run.Append(CodeTypes.GS1DM);
	}
	if (ui.ckb_GS1QR_Code2d->isChecked())
	{
		runParams.hv_CodeType_Run.Append(CodeTypes.GS1QR);
	}
	if (ui.ckb_MicroQR_Code2d->isChecked())
	{
		runParams.hv_CodeType_Run.Append(CodeTypes.MicroQR);
	}
	if (ui.ckb_PDF417_Code2d->isChecked())
	{
		runParams.hv_CodeType_Run.Append(CodeTypes.PDF417);
	}
	if (ui.ckb_QR_Code2d->isChecked())
	{
		runParams.hv_CodeType_Run.Append(CodeTypes.QR);
	}
	if (runParams.hv_CodeType_Run.TupleLength().I() == 0)
	{
		runParams.hv_CodeType_Run = CodeTypes.QR;
	}

	if (ui.cmb_Tolerance_Code2d->currentText() == "标准")
	{
		runParams.hv_Tolerance = "low";
	}
	else
	{
		runParams.hv_Tolerance = "high";
	}
	//*******************************************************************************
	//搜索区域赋值
	GenEmptyObj(&SearchRoi_Code2d);
	//搜索区域合并
	if (!ho_Code2dRegions.isEmpty())
	{
		//一维码搜索区域合并
		if (ho_Code2dRegions.count() == 1)
		{
			SearchRoi_Code2d = ho_Code2dRegions[0];
		}
		else
		{
			SearchRoi_Code2d = ho_Code2dRegions[0];
			for (int i = 1; i < ho_Code2dRegions.count(); i++)
			{
				Union2(SearchRoi_Code2d, ho_Code2dRegions[i], &SearchRoi_Code2d);
			}
		}
		//窗口显示图形赋值
		ConcatObj(ho_ShowObj, SearchRoi_Code2d, &ho_ShowObj);
		runParams.ho_SearchRegion = SearchRoi_Code2d;
	}
	else
	{
		//如果没有绘制搜索区域,置空
		GenEmptyObj(&SearchRoi_Code2d);
		SearchRoi_Code2d.Clear();
		GenEmptyObj(&runParams.ho_SearchRegion);
		runParams.ho_SearchRegion.Clear();
	}
}
//设置二维码结果显示表格数据
void QRCodeWindow::SetTableData_Code2d(const ResultParamsStruct_Code2d &resultStruct, qint64 Ct)
{
	//清空结果表格数据
	ui.tablewidget_Results_Code2d->clearContents();
	//判断是否找到二维码
	if (resultStruct.hv_RetNum == 0)
	{
		//没有找到二维码，退出
		GenEmptyObj(&ho_ShowObj);
		showImg(ho_Image, "margin", "green");
		return;
	}
	//刷新图像
	GenEmptyObj(&ho_ShowObj);
	ConcatObj(ho_ShowObj, resultStruct.ho_ContourCode2d, &ho_ShowObj);
	showImg(ho_Image, "margin", "green");
	//刷新时间
	ui.lbl_CT_Code2d->setText("CT:" + QString::number(Ct) + "ms");

	//刷新所有找到的二维码信息
	int count = resultStruct.hv_RetNum.I();
	ui.tablewidget_Results_Code2d->setRowCount(count);
	for (int i = 0; i < count; i++)
	{
		QTableWidgetItem *item;
		QString str;
		//二维码类型
		str = QString::fromUtf8(resultStruct.hv_CodeType_Result[i].S().Text());
		item = new QTableWidgetItem(str, 1000);
		item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
		ui.tablewidget_Results_Code2d->setItem(i, 0, item);
		//二维码内容
		str = QString::fromUtf8(resultStruct.hv_CodeContent[i].S().Text());
		item = new QTableWidgetItem(str, 1000);
		item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
		ui.tablewidget_Results_Code2d->setItem(i, 1, item);
		//二维码长度
		str = QString::number(resultStruct.hv_CodeLength_Result[i].I());
		item = new QTableWidgetItem(str, 1000);
		item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
		ui.tablewidget_Results_Code2d->setItem(i, 2, item);
		//X坐标
		str = QString::number(resultStruct.hv_Column[i].D(), 'f', 2);
		item = new QTableWidgetItem(str, 1000);
		item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
		ui.tablewidget_Results_Code2d->setItem(i, 3, item);
		//Y坐标
		str = QString::number(resultStruct.hv_Row[i].D(), 'f', 2);
		item = new QTableWidgetItem(str, 1000);
		item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
		ui.tablewidget_Results_Code2d->setItem(i, 4, item);
	}
}
//更新二维码检测运行参数到窗口
void QRCodeWindow::UpdateCode2dDataWindow(const RunParamsStruct_Code2d &runParams)
{
	ui.spb_CodeNum_Code2d->setValue(runParams.hv_CodeNum.I());
	SearchRoi_Code2d = runParams.ho_SearchRegion;

	QString contentTemp = "";
	contentTemp = QString::fromUtf8(runParams.hv_HeadChar.S().Text());
	if (contentTemp != "null" && contentTemp != "")
	{
		ui.txt_HeadChar_Code2d->setText(contentTemp);
	}

	contentTemp = QString::fromUtf8(runParams.hv_EndChar.S().Text());
	if (contentTemp != "null" && contentTemp != "")
	{
		ui.txt_EndChar_Code2d->setText(contentTemp);
	}

	contentTemp = QString::fromUtf8(runParams.hv_ContainChar.S().Text());
	if (contentTemp != "null" && contentTemp != "")
	{
		ui.txt_ContainChar_Code2d->setText(contentTemp);
	}

	contentTemp = QString::fromUtf8(runParams.hv_NotContainChar.S().Text());
	if (contentTemp != "null" && contentTemp != "")
	{
		ui.txt_NotContainChar_Code2d->setText(contentTemp);
	}

	ui.spb_CodeLength_Code2d->setValue(runParams.hv_CodeLength_Run.I());
	ui.spb_TimeOut_Code2d->setValue(runParams.hv_TimeOut.I());

	CodeTypeStruct_Code2d codeTypeStruct;
	int len = runParams.hv_CodeType_Run.TupleLength().I();
	for (int i = 0; i < len; i++)
	{
		if (runParams.hv_CodeType_Run[i] == codeTypeStruct.Aztec)
		{
			ui.ckb_Aztec_Code2d->setCheckState(Qt::Checked);
		}
		else if (runParams.hv_CodeType_Run[i] == codeTypeStruct.DM)
		{
			ui.ckb_DM_Code2d->setCheckState(Qt::Checked);
		}
		else if (runParams.hv_CodeType_Run[i] == codeTypeStruct.GS1Aztec)
		{
			ui.ckb_GS1Aztec_Code2d->setCheckState(Qt::Checked);
		}
		else if (runParams.hv_CodeType_Run[i] == codeTypeStruct.GS1DM)
		{
			ui.ckb_GS1DM_Code2d->setCheckState(Qt::Checked);
		}
		else if (runParams.hv_CodeType_Run[i] == codeTypeStruct.GS1QR)
		{
			ui.ckb_GS1QR_Code2d->setCheckState(Qt::Checked);
		}
		else if (runParams.hv_CodeType_Run[i] == codeTypeStruct.MicroQR)
		{
			ui.ckb_MicroQR_Code2d->setCheckState(Qt::Checked);
		}
		else if (runParams.hv_CodeType_Run[i] == codeTypeStruct.PDF417)
		{
			ui.ckb_PDF417_Code2d->setCheckState(Qt::Checked);
		}
		else if (runParams.hv_CodeType_Run[i] == codeTypeStruct.QR)
		{
			ui.ckb_QR_Code2d->setCheckState(Qt::Checked);
		}
		else
		{
			string str = runParams.hv_CodeType_Run[i].S();
		}
	}
}

//保存二维码检测参数
void QRCodeWindow::on_btn_SaveCode2dData_clicked()
{
	int ret = 1;
	//设置二维码运行参数
	SetRunParams_Code2d(hv_RunParamsCode2d);
	//保存二维码运行参数
	ret = dataIOC.WriteParams_Code2d(configPath, XMLPath, hv_RunParamsCode2d, processID, nodeName, processModbuleID);
	if (ret != 0)
	{
		QMessageBox::information(this, "提示", "参数保存失败", QMessageBox::Ok);
		return;
	}
}
//读取二维码检测参数
void QRCodeWindow::on_btn_LoadCode2dData_clicked()
{
	ErrorCode_Xml errorCode;
	//数组需要清空
	hv_RunParamsCode2d.hv_CodeType_Run.Clear();
	//读取二维码参数
	errorCode = dataIOC.ReadParams_Code2d(configPath, XMLPath, hv_RunParamsCode2d, processID, nodeName, processModbuleID);
	if (errorCode != Ok_Xml)
	{
		QMessageBox::information(this, "提示", "参数读取失败", QMessageBox::Ok);
		return;
	}
	//参数更新到窗口
	UpdateCode2dDataWindow(hv_RunParamsCode2d);
}
//绘制二维码搜索区域
void QRCodeWindow::on_btn_DrawRoi_Code2d_clicked()
{
	if (ho_Image.Key() == nullptr)
	{
		//图像为空，或者图像被clear
		QMessageBox::information(this, "提示", "图像是空，请先加载图像!", QMessageBox::Ok);
		return;
	}
	SetColor(m_hHalconID, "red");
	SetLineWidth(m_hHalconID, 1);

	HObject TempRoi;
	HTuple RecRow1, RecCol1, RecRow2, RecCol2;
	DrawRectangle1(m_hHalconID, &RecRow1, &RecCol1, &RecRow2, &RecCol2);
	GenRectangle1(&TempRoi, RecRow1, RecCol1, RecRow2, RecCol2);
	ho_Code2dRegions.push_back(TempRoi);
	ConcatObj(ho_ShowObj, TempRoi, &ho_ShowObj);
	//给窗口刷新图像传递参数(主要作用是为了滚轮缩放时显示图形)
	GiveParameterToWindow();
	DispObj(TempRoi, m_hHalconID);

}
//清空ROI
void QRCodeWindow::on_btn_ClearRoi_Code2d_clicked()
{
	ho_Code2dRegions.clear();
	GenEmptyObj(&SearchRoi_Code2d);
	GenEmptyObj(&ho_ShowObj);
	//给窗口刷新图像传递参数(主要作用是为了滚轮缩放时显示图形)
	GiveParameterToWindow();
	showImg(ho_Image, "margin", "green");
}
//初始化二维码结果显示表格
void QRCodeWindow::IniTableData_Code2d()
{
	QTableWidgetItem   *hearderItem;
	QStringList hearderText;
	hearderText << "条码类型" << "条码内容" << "条码长度" << "X坐标" << "Y坐标";
	ui.tablewidget_Results_Code2d->setColumnCount(hearderText.count());
	for (int i = 0; i < ui.tablewidget_Results_Code2d->columnCount(); i++)
	{
		hearderItem = new QTableWidgetItem(hearderText.at(i));
		QFont font = hearderItem->font();
		font.setBold(true);//设置为粗体
		font.setPointSize(12);//设置字体大小
		hearderItem->setTextColor(Qt::red);//字体颜色
		hearderItem->setFont(font);//设置字体
		ui.tablewidget_Results_Code2d->setHorizontalHeaderItem(i, hearderItem);
	}
}
//二维码检测槽函数
void QRCodeWindow::on_btn_FindCode2d_clicked()
{
	if (ho_Image.Key() == nullptr)
	{
		//图像为空，或者图像被clear
		QMessageBox::information(this, "提示", "图像是空，请先加载图像!", QMessageBox::Ok);
		return;
	}
	int ret = 1;
	//识别二维码
	ResultParamsStruct_Code2d resultParams;
	QDateTime startTime = QDateTime::currentDateTime();
	ret = slot_FindCode2d(resultParams);
	QDateTime endTime = QDateTime::currentDateTime();
	qint64 intervalTimeMS = startTime.msecsTo(endTime);

	//刷新结果
	SetTableData_Code2d(resultParams, intervalTimeMS);
}
//检测二维码槽函数
int QRCodeWindow::slot_FindCode2d(ResultParamsStruct_Code2d &resultParams)
{
	try
	{
		int ret = 1;
		//XML读取参数
		hv_RunParamsCode2d.hv_CodeType_Run.Clear();
		ErrorCode_Xml errorCode = dataIOC.ReadParams_Code2d(configPath, XMLPath, hv_RunParamsCode2d, processID, nodeName, processModbuleID);
		if (errorCode != Ok_Xml)
		{
			//XML读取失败，给默认值
			GenEmptyObj(&hv_RunParamsCode2d.ho_SearchRegion);
			hv_RunParamsCode2d.ho_SearchRegion.Clear();
			hv_RunParamsCode2d.hv_CodeType_Run = "QR Code";
			hv_RunParamsCode2d.hv_CodeNum = 1;
			hv_RunParamsCode2d.hv_Tolerance = "high";
			hv_RunParamsCode2d.hv_HeadChar = "null";
			hv_RunParamsCode2d.hv_EndChar = "null";
			hv_RunParamsCode2d.hv_ContainChar = "null";
			hv_RunParamsCode2d.hv_NotContainChar = "null";
			hv_RunParamsCode2d.hv_CodeLength_Run = 2;
			hv_RunParamsCode2d.hv_TimeOut = 100;
			//保存二维码运行参数
			ret = dataIOC.WriteParams_Code2d(configPath, XMLPath, hv_RunParamsCode2d, processID, nodeName, processModbuleID);
			if (ret != 0)
			{
				return ret;
			}
		}
		//调用算法
		return code2dParams1->FindCode2dFunc(ho_Image, hv_RunParamsCode2d, resultParams);
	}
	catch (...)
	{
		return -1;
	}
}
