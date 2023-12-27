#include "TemplateWindow.h"

TemplateWindow::TemplateWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowMinimizeButtonHint);
	//窗口初始化
	InitWindow();

	//模板匹配
	IniTableData_Template();
	IniTemplateClassObject();

	//屏蔽暂时不使用的参数控件(主要是一些步长参数，设置为自动更合理)
	ui.label_5->setVisible(false);
	ui.dspb_AngleStep_Train->setVisible(false);
	ui.label_8->setVisible(false);
	ui.dspb_ScaleRStep_Train->setVisible(false);
	ui.label_11->setVisible(false);
	ui.dspb_ScaleCStep_Train->setVisible(false);
	ui.label_12->setVisible(false);
	ui.cmb_Optimization_Train->setVisible(false);

	//初始化模板匹配模式
	ui.cmb_MatchMethod_Train->setCurrentIndex(5);

}

TemplateWindow::TemplateWindow(HObject image, int _processID, int modubleID, std::string _modubleName, std::string configPath){
	ui.setupUi(this);
	nodeName = _modubleName;
	processModbuleID = modubleID;
	processID = _processID;
	XMLPath = configPath + "/config.xml";
	this->configPath = configPath + "/";
	InitWindow();
	IniTableData_Template();
	IniTemplateClassObject();

	ui.label_5->setVisible(false);
	ui.dspb_AngleStep_Train->setVisible(false);
	ui.label_8->setVisible(false);
	ui.dspb_ScaleRStep_Train->setVisible(false);
	ui.label_11->setVisible(false);
	ui.dspb_ScaleCStep_Train->setVisible(false);
	ui.label_12->setVisible(false);
	ui.cmb_Optimization_Train->setVisible(false);

	ho_Image = image;
	showImg(ho_Image, "margin", "green");
	GenEmptyObj(&ho_ShowObj);
}

TemplateWindow::~TemplateWindow()
{
	//释放模板new的内存
	delete TemplateDetect1;
}

//关闭窗口
void TemplateWindow::on_btn_Hide_clicked()
{
	this->hide();
}
//初始化显示窗口
void TemplateWindow::InitWindow()
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

//模板类对象初始化
void TemplateWindow::IniTemplateClassObject()
{
	TemplateDetect1 = new TemplateDetect(nodeName, processModbuleID, processID, XMLPath);
}
//显示图像
void TemplateWindow::showImg(const HObject &ho_Img, HTuple hv_FillType, HTuple hv_Color)
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
void TemplateWindow::GiveParameterToWindow()
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
void TemplateWindow::on_pBtn_ReadImage_clicked()
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
void TemplateWindow::on_pBtn_FitImage_clicked()
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
void TemplateWindow::on_ckb_ShowObj_stateChanged(int arg1)
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
void TemplateWindow::on_btn_ClearWindow_clicked()
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

//*****************模板匹配相关代码****************************************************************
//ROI形状选择
void TemplateWindow::on_cmb_RoiShape_Template_activated(const QString &arg1)
{
	RoiShape = arg1;
}
//模板匹配类型选择
void TemplateWindow::on_cmb_MatchMethod_Train_activated(const QString &arg1)
{
	if (ui.cmb_MatchMethod_Train->currentIndex() == 0)
	{
		ui.label_25->setVisible(true);
		ui.cmb_SubPixel_Run->setVisible(true);
		ui.label_27->setVisible(true);
		ui.dspb_Greediness_Run->setVisible(true);

		ui.label_6->setVisible(false);
		ui.dspb_ScaleRMin_Train->setVisible(false);
		ui.label_7->setVisible(false);
		ui.dspb_ScaleRMax_Train->setVisible(false);
		ui.label_9->setVisible(false);
		ui.dspb_ScaleCMin_Train->setVisible(false);
		ui.label_10->setVisible(false);
		ui.dspb_ScaleCMax_Train->setVisible(false);
	
	

		ui.label_2->setVisible(true);
		ui.spb_NumLevels_Train->setVisible(true);
		ui.label_14->setVisible(true);
		ui.spb_Contrast_Train->setVisible(true);
		ui.label_15->setVisible(true);
		ui.spb_MinContrast_Train->setVisible(true);
	}
	else if(ui.cmb_MatchMethod_Train->currentIndex() == 1)
	{
		ui.label_25->setVisible(true);
		ui.cmb_SubPixel_Run->setVisible(true);
		ui.label_27->setVisible(true);
		ui.dspb_Greediness_Run->setVisible(true);

		ui.label_6->setVisible(false);
		ui.dspb_ScaleRMin_Train->setVisible(false);
		ui.label_7->setVisible(false);
		ui.dspb_ScaleRMax_Train->setVisible(false);
		ui.label_9->setVisible(false);
		ui.dspb_ScaleCMin_Train->setVisible(false);
		ui.label_10->setVisible(false);
		ui.dspb_ScaleCMax_Train->setVisible(false);
	


		ui.label_2->setVisible(false);
		ui.spb_NumLevels_Train->setVisible(false);
		ui.label_14->setVisible(false);
		ui.spb_Contrast_Train->setVisible(false);
		ui.label_15->setVisible(false);
		ui.spb_MinContrast_Train->setVisible(false);
	}
	else if (ui.cmb_MatchMethod_Train->currentIndex() == 2)
	{
		ui.label_25->setVisible(true);
		ui.cmb_SubPixel_Run->setVisible(true);
		ui.label_27->setVisible(true);
		ui.dspb_Greediness_Run->setVisible(true);

		ui.label_6->setVisible(true);
		ui.dspb_ScaleRMin_Train->setVisible(true);
		ui.label_7->setVisible(true);
		ui.dspb_ScaleRMax_Train->setVisible(true);
		ui.label_9->setVisible(false);
		ui.dspb_ScaleCMin_Train->setVisible(false);
		ui.label_10->setVisible(false);
		ui.dspb_ScaleCMax_Train->setVisible(false);


		ui.label_2->setVisible(true);
		ui.spb_NumLevels_Train->setVisible(true);
		ui.label_14->setVisible(true);
		ui.spb_Contrast_Train->setVisible(true);
		ui.label_15->setVisible(true);
		ui.spb_MinContrast_Train->setVisible(true);
	}
	else if (ui.cmb_MatchMethod_Train->currentIndex() == 3)
	{
		ui.label_25->setVisible(true);
		ui.cmb_SubPixel_Run->setVisible(true);
		ui.label_27->setVisible(true);
		ui.dspb_Greediness_Run->setVisible(true);

		ui.label_6->setVisible(true);
		ui.dspb_ScaleRMin_Train->setVisible(true);
		ui.label_7->setVisible(true);
		ui.dspb_ScaleRMax_Train->setVisible(true);
		ui.label_9->setVisible(false);
		ui.dspb_ScaleCMin_Train->setVisible(false);
		ui.label_10->setVisible(false);
		ui.dspb_ScaleCMax_Train->setVisible(false);



		ui.label_2->setVisible(false);
		ui.spb_NumLevels_Train->setVisible(false);
		ui.label_14->setVisible(false);
		ui.spb_Contrast_Train->setVisible(false);
		ui.label_15->setVisible(false);
		ui.spb_MinContrast_Train->setVisible(false);
	}
	else if (ui.cmb_MatchMethod_Train->currentIndex() == 4)
	{
		ui.label_25->setVisible(true);
		ui.cmb_SubPixel_Run->setVisible(true);
		ui.label_27->setVisible(true);
		ui.dspb_Greediness_Run->setVisible(true);

		ui.label_6->setVisible(true);
		ui.dspb_ScaleRMin_Train->setVisible(true);
		ui.label_7->setVisible(true);
		ui.dspb_ScaleRMax_Train->setVisible(true);
		ui.label_9->setVisible(true);
		ui.dspb_ScaleCMin_Train->setVisible(true);
		ui.label_10->setVisible(true);
		ui.dspb_ScaleCMax_Train->setVisible(true);


		ui.label_2->setVisible(true);
		ui.spb_NumLevels_Train->setVisible(true);
		ui.label_14->setVisible(true);
		ui.spb_Contrast_Train->setVisible(true);
		ui.label_15->setVisible(true);
		ui.spb_MinContrast_Train->setVisible(true);
	}
	else if (ui.cmb_MatchMethod_Train->currentIndex() == 5)
	{
		ui.label_25->setVisible(true);
		ui.cmb_SubPixel_Run->setVisible(true);
		ui.label_27->setVisible(true);
		ui.dspb_Greediness_Run->setVisible(true);

		ui.label_6->setVisible(true);
		ui.dspb_ScaleRMin_Train->setVisible(true);
		ui.label_7->setVisible(true);
		ui.dspb_ScaleRMax_Train->setVisible(true);
		ui.label_9->setVisible(true);
		ui.dspb_ScaleCMin_Train->setVisible(true);
		ui.label_10->setVisible(true);
		ui.dspb_ScaleCMax_Train->setVisible(true);


		ui.label_2->setVisible(false);
		ui.spb_NumLevels_Train->setVisible(false);
		ui.label_14->setVisible(false);
		ui.spb_Contrast_Train->setVisible(false);
		ui.label_15->setVisible(false);
		ui.spb_MinContrast_Train->setVisible(false);
	}
	else if (ui.cmb_MatchMethod_Train->currentIndex() == 6)
	{
		ui.label_6->setVisible(false);
		ui.dspb_ScaleRMin_Train->setVisible(false);
		ui.label_7->setVisible(false);
		ui.dspb_ScaleRMax_Train->setVisible(false);
		ui.label_9->setVisible(false);
		ui.dspb_ScaleCMin_Train->setVisible(false);
		ui.label_10->setVisible(false);
		ui.dspb_ScaleCMax_Train->setVisible(false);

		ui.label_14->setVisible(false);
		ui.spb_Contrast_Train->setVisible(false);
		ui.label_15->setVisible(false);
		ui.spb_MinContrast_Train->setVisible(false);
		ui.label_25->setVisible(false);
		ui.cmb_SubPixel_Run->setVisible(false);
		ui.label_27->setVisible(false);
		ui.dspb_Greediness_Run->setVisible(false);


		ui.label_2->setVisible(true);
		ui.spb_NumLevels_Train->setVisible(true);

	}
	else if (ui.cmb_MatchMethod_Train->currentIndex() == 7)
	{
		ui.label_6->setVisible(false);
		ui.dspb_ScaleRMin_Train->setVisible(false);
		ui.label_7->setVisible(false);
		ui.dspb_ScaleRMax_Train->setVisible(false);
		ui.label_9->setVisible(false);
		ui.dspb_ScaleCMin_Train->setVisible(false);
		ui.label_10->setVisible(false);
		ui.dspb_ScaleCMax_Train->setVisible(false);

		ui.label_14->setVisible(false);
		ui.spb_Contrast_Train->setVisible(false);
		ui.label_15->setVisible(false);
		ui.spb_MinContrast_Train->setVisible(false);
		ui.label_25->setVisible(false);
		ui.cmb_SubPixel_Run->setVisible(false);
		ui.label_27->setVisible(false);
		ui.dspb_Greediness_Run->setVisible(false);


		ui.label_2->setVisible(false);
		ui.spb_NumLevels_Train->setVisible(false);
	}
}
//绘制模板训练区域
void TemplateWindow::on_btn_DrawTrainRoi_Template_clicked()
{
	if (ho_Image.Key() == nullptr)
	{
		//图像为空，或者图像被clear
		QMessageBox::information(this, "提示", "图像是空，请先加载图像!", QMessageBox::Ok);
		return;
	}
	SetColor(m_hHalconID, "red");
	SetLineWidth(m_hHalconID, 1);
	if (RoiShape == "rectangle1")
	{
		HObject TempRoi;
		HTuple RecRow1, RecCol1, RecRow2, RecCol2;
		DrawRectangle1(m_hHalconID, &RecRow1, &RecCol1, &RecRow2, &RecCol2);
		GenRectangle1(&TempRoi, RecRow1, RecCol1, RecRow2, RecCol2);
		ho_TemplateRegions.push_back(TempRoi);
		ConcatObj(ho_ShowObj, TempRoi, &ho_ShowObj);
		//给窗口刷新图像传递参数(主要作用是为了滚轮缩放时显示图形)
		GiveParameterToWindow();
		DispObj(TempRoi, m_hHalconID);
	}
	else if (RoiShape == "rectangle2")
	{
		HObject TempRoi;
		HTuple RecRow, RecCol, RecPhi, RecLength1, RecLength2;
		DrawRectangle2(m_hHalconID, &RecRow, &RecCol, &RecPhi, &RecLength1, &RecLength2);
		GenRectangle2(&TempRoi, RecRow, RecCol, RecPhi, RecLength1, RecLength2);
		ho_TemplateRegions.push_back(TempRoi);
		ConcatObj(ho_ShowObj, TempRoi, &ho_ShowObj);
		//给窗口刷新图像传递参数(主要作用是为了滚轮缩放时显示图形)
		GiveParameterToWindow();
		DispObj(TempRoi, m_hHalconID);
	}
	else if (RoiShape == "circle")
	{
		HObject TempRoi;
		HTuple CircleRow, CircleCol, CircleRadius;
		DrawCircle(m_hHalconID, &CircleRow, &CircleCol, &CircleRadius);
		GenCircle(&TempRoi, CircleRow, CircleCol, CircleRadius);
		ho_TemplateRegions.push_back(TempRoi);
		ConcatObj(ho_ShowObj, TempRoi, &ho_ShowObj);
		//给窗口刷新图像传递参数(主要作用是为了滚轮缩放时显示图形)
		GiveParameterToWindow();
		DispObj(TempRoi, m_hHalconID);
	}
	else if (RoiShape == "ellipse")
	{
		HObject TempRoi;
		HTuple EllipseRow, EllipseCol, EllipsePhi, EllipseRadius1, EllipseRadius12;
		DrawEllipse(m_hHalconID, &EllipseRow, &EllipseCol, &EllipsePhi, &EllipseRadius1, &EllipseRadius12);
		GenEllipse(&TempRoi, EllipseRow, EllipseCol, EllipsePhi, EllipseRadius1, EllipseRadius12);
		ho_TemplateRegions.push_back(TempRoi);
		ConcatObj(ho_ShowObj, TempRoi, &ho_ShowObj);
		//给窗口刷新图像传递参数(主要作用是为了滚轮缩放时显示图形)
		GiveParameterToWindow();
		DispObj(TempRoi, m_hHalconID);
	}
	else if (RoiShape == "polygon")
	{
		HObject TempRoi;
		DrawRegion(&TempRoi, m_hHalconID);

		ho_TemplateRegions.push_back(TempRoi);
		ConcatObj(ho_ShowObj, TempRoi, &ho_ShowObj);
		//给窗口刷新图像传递参数(主要作用是为了滚轮缩放时显示图形)
		GiveParameterToWindow();
		DispObj(TempRoi, m_hHalconID);
	}
	else
	{
		QMessageBox::information(this, "提示", "请选择区域形状!", QMessageBox::Ok);
	}
}
//绘制模板搜索区域
void TemplateWindow::on_btn_DrawSearchRoi_Template_clicked()
{
	if (ho_Image.Key() == nullptr)
	{
		//图像为空，或者图像被clear
		QMessageBox::information(this, "提示", "图像是空，请先加载图像!", QMessageBox::Ok);
		return;
	}
	SetColor(m_hHalconID, "blue");
	SetLineWidth(m_hHalconID, 1);
	if (RoiShape == "rectangle1")
	{
		HObject TempRoi;
		HTuple RecRow1, RecCol1, RecRow2, RecCol2;
		DrawRectangle1(m_hHalconID, &RecRow1, &RecCol1, &RecRow2, &RecCol2);
		GenRectangle1(&TempRoi, RecRow1, RecCol1, RecRow2, RecCol2);
		ho_SearchRegions.push_back(TempRoi);
		ConcatObj(ho_ShowObj, TempRoi, &ho_ShowObj);
		//给窗口刷新图像传递参数(主要作用是为了滚轮缩放时显示图形)
		GiveParameterToWindow();
		DispObj(TempRoi, m_hHalconID);
	}
	else if (RoiShape == "rectangle2")
	{
		HObject TempRoi;
		HTuple RecRow, RecCol, RecPhi, RecLength1, RecLength2;
		DrawRectangle2(m_hHalconID, &RecRow, &RecCol, &RecPhi, &RecLength1, &RecLength2);
		GenRectangle2(&TempRoi, RecRow, RecCol, RecPhi, RecLength1, RecLength2);
		ho_SearchRegions.push_back(TempRoi);
		ConcatObj(ho_ShowObj, TempRoi, &ho_ShowObj);
		//给窗口刷新图像传递参数(主要作用是为了滚轮缩放时显示图形)
		GiveParameterToWindow();
		DispObj(TempRoi, m_hHalconID);
	}
	else if (RoiShape == "circle")
	{
		HObject TempRoi;
		HTuple CircleRow, CircleCol, CircleRadius;
		DrawCircle(m_hHalconID, &CircleRow, &CircleCol, &CircleRadius);
		GenCircle(&TempRoi, CircleRow, CircleCol, CircleRadius);
		ho_SearchRegions.push_back(TempRoi);
		ConcatObj(ho_ShowObj, TempRoi, &ho_ShowObj);
		//给窗口刷新图像传递参数(主要作用是为了滚轮缩放时显示图形)
		GiveParameterToWindow();
		DispObj(TempRoi, m_hHalconID);
	}
	else if (RoiShape == "ellipse")
	{
		HObject TempRoi;
		HTuple EllipseRow, EllipseCol, EllipsePhi, EllipseRadius1, EllipseRadius12;
		DrawEllipse(m_hHalconID, &EllipseRow, &EllipseCol, &EllipsePhi, &EllipseRadius1, &EllipseRadius12);
		GenEllipse(&TempRoi, EllipseRow, EllipseCol, EllipsePhi, EllipseRadius1, EllipseRadius12);
		ho_SearchRegions.push_back(TempRoi);
		ConcatObj(ho_ShowObj, TempRoi, &ho_ShowObj);
		//给窗口刷新图像传递参数(主要作用是为了滚轮缩放时显示图形)
		GiveParameterToWindow();
		DispObj(TempRoi, m_hHalconID);
	}
	else if (RoiShape == "polygon")
	{
		HObject TempRoi;
		DrawRegion(&TempRoi, m_hHalconID);
		ho_SearchRegions.push_back(TempRoi);
		ConcatObj(ho_ShowObj, TempRoi, &ho_ShowObj);
		//给窗口刷新图像传递参数(主要作用是为了滚轮缩放时显示图形)
		GiveParameterToWindow();
		DispObj(TempRoi, m_hHalconID);
	}
	else
	{
		QMessageBox::information(this, "提示", "请选择区域形状!", QMessageBox::Ok);
	}
}
//绘制掩模区域
void TemplateWindow::on_btn_DrawShaddowRoi_Template_clicked()
{
	if (ho_Image.Key() == nullptr)
	{
		//图像为空，或者图像被clear
		QMessageBox::information(this, "提示", "图像是空，请先加载图像!", QMessageBox::Ok);
		return;
	}
	SetColor(m_hHalconID, "green");
	SetLineWidth(m_hHalconID, 1);
	if (RoiShape == "rectangle1")
	{
		HObject TempRoi;
		HTuple RecRow1, RecCol1, RecRow2, RecCol2;
		DrawRectangle1(m_hHalconID, &RecRow1, &RecCol1, &RecRow2, &RecCol2);
		GenRectangle1(&TempRoi, RecRow1, RecCol1, RecRow2, RecCol2);
		ho_ShadowRegions.push_back(TempRoi);
		ConcatObj(ho_ShowObj, TempRoi, &ho_ShowObj);
		//给窗口刷新图像传递参数(主要作用是为了滚轮缩放时显示图形)
		GiveParameterToWindow();
		DispObj(TempRoi, m_hHalconID);
	}
	else if (RoiShape == "rectangle2")
	{
		HObject TempRoi;
		HTuple RecRow, RecCol, RecPhi, RecLength1, RecLength2;
		DrawRectangle2(m_hHalconID, &RecRow, &RecCol, &RecPhi, &RecLength1, &RecLength2);
		GenRectangle2(&TempRoi, RecRow, RecCol, RecPhi, RecLength1, RecLength2);
		ho_ShadowRegions.push_back(TempRoi);
		ConcatObj(ho_ShowObj, TempRoi, &ho_ShowObj);
		//给窗口刷新图像传递参数(主要作用是为了滚轮缩放时显示图形)
		GiveParameterToWindow();
		DispObj(TempRoi, m_hHalconID);
	}
	else if (RoiShape == "circle")
	{
		HObject TempRoi;
		HTuple CircleRow, CircleCol, CircleRadius;
		DrawCircle(m_hHalconID, &CircleRow, &CircleCol, &CircleRadius);
		GenCircle(&TempRoi, CircleRow, CircleCol, CircleRadius);
		ho_ShadowRegions.push_back(TempRoi);
		ConcatObj(ho_ShowObj, TempRoi, &ho_ShowObj);
		//给窗口刷新图像传递参数(主要作用是为了滚轮缩放时显示图形)
		GiveParameterToWindow();
		DispObj(TempRoi, m_hHalconID);
	}
	else if (RoiShape == "ellipse")
	{
		HObject TempRoi;
		HTuple EllipseRow, EllipseCol, EllipsePhi, EllipseRadius1, EllipseRadius12;
		DrawEllipse(m_hHalconID, &EllipseRow, &EllipseCol, &EllipsePhi, &EllipseRadius1, &EllipseRadius12);
		GenEllipse(&TempRoi, EllipseRow, EllipseCol, EllipsePhi, EllipseRadius1, EllipseRadius12);
		ho_ShadowRegions.push_back(TempRoi);
		ConcatObj(ho_ShowObj, TempRoi, &ho_ShowObj);
		//给窗口刷新图像传递参数(主要作用是为了滚轮缩放时显示图形)
		GiveParameterToWindow();
		DispObj(TempRoi, m_hHalconID);
	}
	else if (RoiShape == "polygon")
	{
		HObject TempRoi;
		DrawRegion(&TempRoi, m_hHalconID);
		ho_ShadowRegions.push_back(TempRoi);
		ConcatObj(ho_ShowObj, TempRoi, &ho_ShowObj);
		//给窗口刷新图像传递参数(主要作用是为了滚轮缩放时显示图形)
		GiveParameterToWindow();
		DispObj(TempRoi, m_hHalconID);
	}
	else
	{
		QMessageBox::information(this, "提示", "请选择区域形状!", QMessageBox::Ok);
	}
}
//合并模板区域Roi
void TemplateWindow::on_btn_UnionRoi_Template_clicked()
{
	if (ho_Image.Key() == nullptr)
	{
		//图像为空，或者图像被clear
		QMessageBox::information(this, "提示", "图像是空，请先加载图像!", QMessageBox::Ok);
		return;
	}
	if (ho_TemplateRegions.isEmpty())
	{
		QMessageBox::information(this, "提示", "模板训练区域ROI为空!", QMessageBox::Ok);
		return;
	}
	else
	{
		SetColor(m_hHalconID, "red");
		SetLineWidth(m_hHalconID, 1);
		//训练区域合并
		if (ho_TemplateRegions.count() == 1)
		{
			TrainRoi_Template = ho_TemplateRegions[0];
		}
		else
		{
			TrainRoi_Template = ho_TemplateRegions[0];
			for (int i = 1; i < ho_TemplateRegions.count(); i++)
			{
				Union2(TrainRoi_Template, ho_TemplateRegions[i], &TrainRoi_Template);
			}
		}

		//掩模区域合并
		if (!ho_ShadowRegions.isEmpty())
		{
			if (ho_ShadowRegions.count() == 1)
			{
				ShadowRoi_Template = ho_ShadowRegions[0];
			}
			else
			{
				ShadowRoi_Template = ho_ShadowRegions[0];
				for (int i = 1; i < ho_ShadowRegions.count(); i++)
				{
					Union2(ShadowRoi_Template, ho_ShadowRegions[i], &ShadowRoi_Template);
				}
			}
			//窗口显示图形赋值
			//GenEmptyObj(&ho_ShowObj);
			ConcatObj(ho_ShowObj, ShadowRoi_Template, &ho_ShowObj);
		}

		//抠出掩模区域
		if (!ho_ShadowRegions.isEmpty())
		{
			Difference(TrainRoi_Template, ShadowRoi_Template, &TrainRoi_Template);
		}

		//窗口显示图形赋值
		//GenEmptyObj(&ho_ShowObj);
		ConcatObj(ho_ShowObj, TrainRoi_Template, &ho_ShowObj);
		//给窗口刷新图像传递参数(主要作用是为了滚轮缩放时显示图形)
		GiveParameterToWindow();

		QMessageBox::information(this, "提示", "合并ROI成功，训练区域数量为:" + QString::number(ho_TemplateRegions.count()), QMessageBox::Ok);

		//清除vector内存
		ho_TemplateRegions.clear();
		ho_ShadowRegions.clear();
	}
}
//清除模板区域Roi
void TemplateWindow::on_btn_ClearRoi_Template_clicked()
{
	if (ho_Image.Key() == nullptr)
	{
		//图像为空，或者图像被clear
		QMessageBox::information(this, "提示", "图像是空，请先加载图像!", QMessageBox::Ok);
		return;
	}
	//清空区域集合
	ho_TemplateRegions.clear();
	ho_SearchRegions.clear();
	ho_ShadowRegions.clear();
	//清空区域变量
	GenEmptyObj(&TrainRoi_Template);
	GenEmptyObj(&SearchRoi_Template);
	GenEmptyObj(&ShadowRoi_Template);
	//清空窗口显示的图形变量
	GenEmptyObj(&ho_ShowObj);
	//显示原图
	showImg(ho_Image, "margin", "green");
}
//训练模板
void TemplateWindow::on_btn_Train_Template_clicked()
{
	if (ho_Image.Key() == nullptr)
	{
		//图像为空，或者图像被clear
		QMessageBox::information(this, "提示", "图像是空，请先加载图像!", QMessageBox::Ok);
		return;
	}
	int ret = 1;
	//创建模板
	//设置查找模板的运行参数
	SetRunParams_Template(hv_RunParamsTemplate);
	ret = slot_CreateTemplate(hv_RunParamsTemplate);
	if (ret != 0)
	{
		QMessageBox::information(this, "提示", "模板训练失败", QMessageBox::Ok);
		return;
	}
	//*******************************************************************************************************
	//查找模板
	ResultParamsStruct_Template resultParams;
	QDateTime startTime = QDateTime::currentDateTime();
	ret = slot_FindTemplate(resultParams);
	QDateTime endTime = QDateTime::currentDateTime();
	qint64 intervalTimeMS = startTime.msecsTo(endTime);

	//刷新结果
	SetTableData_Template(resultParams, intervalTimeMS);
}
//查找模板
void TemplateWindow::on_btn_FindTemplate_clicked()
{
	if (ho_Image.Key() == nullptr)
	{
		//图像为空，或者图像被clear
		QMessageBox::information(this, "提示", "图像是空，请先加载图像!", QMessageBox::Ok);
		return;
	}
	int ret = 1;
	//查找模板
	ResultParamsStruct_Template resultParams;
	QDateTime startTime = QDateTime::currentDateTime();
	ret = slot_FindTemplate(resultParams);
	QDateTime endTime = QDateTime::currentDateTime();
	//qint64 intervalTime = startTime.secsTo(endTime); //求时间差
	qint64 intervalTimeMS = startTime.msecsTo(endTime);

	//刷新结果
	SetTableData_Template(resultParams, intervalTimeMS);
}
//模板参数保存
void TemplateWindow::on_btn_SaveTemplateData_clicked()
{
	int ret = 1;
	//设置查找模板的运行参数
	SetRunParams_Template(hv_RunParamsTemplate);
	//保存模板匹配训练参数和运行参数
	ret = dataIOC.WriteParams_Template(configPath, XMLPath, hv_RunParamsTemplate, processID, nodeName, processModbuleID);
	if (ret != 0)
	{
		QMessageBox::information(this, "提示", "参数保存失败", QMessageBox::Ok);
		return;
	}
}
//模板参数读取
void TemplateWindow::on_btn_ReadTemplateData_clicked()
{
	ErrorCode_Xml errorCode; 
	//读取模板匹配参数
	errorCode = dataIOC.ReadParams_Template(configPath, XMLPath, hv_RunParamsTemplate, processID, nodeName, processModbuleID);
	if (errorCode != Ok_Xml)
	{
		QMessageBox::information(this, "提示", "参数读取失败", QMessageBox::Ok);
		return;
	}
	//参数更新到窗口
	UpdateTemplateDataWindow(hv_RunParamsTemplate);
}

//更新模板训练参数和运行参数窗口
void TemplateWindow::UpdateTemplateDataWindow(const RunParamsStruct_Template &RunParams)
{
	//更新训练参数
	ModelTypeStruct_Template typeStructTemplate;
	if (RunParams.hv_MatchMethod == typeStructTemplate.None)
	{
		ui.cmb_MatchMethod_Train->setCurrentText("基于形状无缩放");
	}
	else if (RunParams.hv_MatchMethod == typeStructTemplate.Auto_None)
	{
		ui.cmb_MatchMethod_Train->setCurrentText("基于形状无缩放自动参数");
	}
	else if (RunParams.hv_MatchMethod == typeStructTemplate.Scaled)
	{
		ui.cmb_MatchMethod_Train->setCurrentText("基于形状同步缩放自动参数");
	}
	else if (RunParams.hv_MatchMethod == typeStructTemplate.Auto_scaled)
	{
		ui.cmb_MatchMethod_Train->setCurrentText("基于形状同步缩放自动参数");
	}
	else if (RunParams.hv_MatchMethod == typeStructTemplate.Aniso)
	{
		ui.cmb_MatchMethod_Train->setCurrentText("基于形状异步缩放");
	}
	else if (RunParams.hv_MatchMethod == typeStructTemplate.Auto_Aniso)
	{
		ui.cmb_MatchMethod_Train->setCurrentText("基于形状异步缩放自动参数");
	}
	else if (RunParams.hv_MatchMethod == typeStructTemplate.Ncc)
	{
		ui.cmb_MatchMethod_Train->setCurrentText("基于互相关");
	}
	else if (RunParams.hv_MatchMethod == typeStructTemplate.Auto_Ccc)
	{
		ui.cmb_MatchMethod_Train->setCurrentText("基于互相关自动参数");
	}

	//判断tuple类型数据是不是数字
	HTuple hv_isNumber;
	TupleIsNumber(RunParams.hv_NumLevels, &hv_isNumber);
	if (hv_isNumber == 1)
	{
		ui.spb_NumLevels_Train->setValue(RunParams.hv_NumLevels.I());
	}
	else
	{
		ui.spb_NumLevels_Train->setValue(-1);
	}
	ui.dspb_AngleStart_Train->setValue(RunParams.hv_AngleStart.D());
	ui.dspb_AngleExtent_Train->setValue(RunParams.hv_AngleExtent.D());
	TupleIsNumber(RunParams.hv_AngleStep, &hv_isNumber);
	if (hv_isNumber == 1)
	{
		ui.dspb_AngleStep_Train->setValue(RunParams.hv_AngleStep.D());
	}
	else
	{
		ui.dspb_AngleStep_Train->setValue(0);
	}
	ui.dspb_ScaleRMin_Train->setValue(RunParams.hv_ScaleRMin.D());
	ui.dspb_ScaleRMax_Train->setValue(RunParams.hv_ScaleRMax.D());
	TupleIsNumber(RunParams.hv_ScaleRStep, &hv_isNumber);
	if (hv_isNumber == 1)
	{
		ui.dspb_ScaleRStep_Train->setValue(RunParams.hv_ScaleRStep.D());
	}
	else
	{
		ui.dspb_ScaleRStep_Train->setValue(0);
	}
	ui.dspb_ScaleCMin_Train->setValue(RunParams.hv_ScaleCMin.D());
	ui.dspb_ScaleCMax_Train->setValue(RunParams.hv_ScaleCMax.D());
	TupleIsNumber(RunParams.hv_ScaleCStep, &hv_isNumber);
	if (hv_isNumber == 1)
	{
		ui.dspb_ScaleCStep_Train->setValue(RunParams.hv_ScaleCStep.D());
	}
	else
	{
		ui.dspb_ScaleCStep_Train->setValue(0);
	}
	ui.cmb_Optimization_Train->setCurrentText(QString::fromUtf8(RunParams.hv_Optimization.S().Text()));
	ui.cmb_Metric_Train->setCurrentText(QString::fromUtf8(RunParams.hv_Metric.S().Text()));
	TupleIsNumber(RunParams.hv_Contrast, &hv_isNumber);
	if (hv_isNumber == 1)
	{
		ui.spb_Contrast_Train->setValue(RunParams.hv_Contrast.I());
	}
	else
	{
		ui.spb_Contrast_Train->setValue(0);
	}
	TupleIsNumber(RunParams.hv_MinContrast, &hv_isNumber);
	if (hv_isNumber == 1)
	{
		ui.spb_MinContrast_Train->setValue(RunParams.hv_MinContrast.I());
	}
	else
	{
		ui.spb_MinContrast_Train->setValue(0);
	}
	TrainRoi_Template = RunParams.ho_TrainRegion;

	//更新运行参数
	ui.dspb_MinScore_Run->setValue(RunParams.hv_MinScore.D());
	ui.spb_NumMatches_Run->setValue(RunParams.hv_NumMatches.I());
	ui.dspb_MaxOverlap_Run->setValue(RunParams.hv_MaxOverlap.D());
	ui.cmb_SubPixel_Run->setCurrentText(QString::fromUtf8(RunParams.hv_SubPixel.S().Text()));
	ui.dspb_Greediness_Run->setValue(RunParams.hv_Greediness.D());
	SearchRoi_Template = RunParams.ho_SearchRegion;
}
//查找模板结构体参数赋值函数
void TemplateWindow::SetRunParams_Template(RunParamsStruct_Template &runParams)
{
	ModelTypeStruct_Template typeStructTemplate;
	HTuple hv_typeTemp;

	if (ui.cmb_MatchMethod_Train->currentText().toStdString() == "基于形状无缩放")
	{
		hv_typeTemp = typeStructTemplate.None;
	}
	else if (ui.cmb_MatchMethod_Train->currentText().toStdString() == "基于形状无缩放自动参数")
	{
		hv_typeTemp = typeStructTemplate.Auto_None;
	}
	else if (ui.cmb_MatchMethod_Train->currentText().toStdString() == "基于形状同步缩放")
	{
		hv_typeTemp = typeStructTemplate.Scaled;
	}
	else if (ui.cmb_MatchMethod_Train->currentText().toStdString() == "基于形状同步缩放自动参数")
	{
		hv_typeTemp = typeStructTemplate.Auto_scaled;
	}
	else if (ui.cmb_MatchMethod_Train->currentText().toStdString() == "基于形状异步缩放")
	{
		hv_typeTemp = typeStructTemplate.Aniso;
	}
	else if (ui.cmb_MatchMethod_Train->currentText().toStdString() == "基于形状异步缩放自动参数")
	{
		hv_typeTemp = typeStructTemplate.Auto_Aniso;
	}
	else if (ui.cmb_MatchMethod_Train->currentText().toStdString() == "基于互相关")
	{
		hv_typeTemp = typeStructTemplate.Ncc;
	}
	else if (ui.cmb_MatchMethod_Train->currentText().toStdString() == "基于互相关自动参数")
	{
		hv_typeTemp = typeStructTemplate.Auto_Ccc;
	}
	else
	{
		hv_typeTemp = typeStructTemplate.Auto_None;
	}
	runParams.hv_MatchMethod = hv_typeTemp;   //比例模式:"none"无缩放,"scaled"同步缩放,"aniso"异步缩放,"auto"自动

	if (ui.spb_NumLevels_Train->value() == -1)
	{
		runParams.hv_NumLevels = typeStructTemplate.Auto;  //金字塔级别("auto")
	}
	else
	{
		runParams.hv_NumLevels = ui.spb_NumLevels_Train->value();  //金字塔级别
	}
	runParams.hv_AngleStart = ui.dspb_AngleStart_Train->value();             //起始角度
	runParams.hv_AngleExtent = ui.dspb_AngleExtent_Train->value();            //角度范围
	if (ui.dspb_AngleStep_Train->value() == 0)
	{
		runParams.hv_AngleStep = typeStructTemplate.Auto;   //角度步长("auto")
	}
	else
	{
		runParams.hv_AngleStep = ui.dspb_AngleStep_Train->value();             //角度步长
	}
	runParams.hv_ScaleRMin = ui.dspb_ScaleRMin_Train->value();              //最小行缩放
	runParams.hv_ScaleRMax = ui.dspb_ScaleRMax_Train->value();              //最大行缩放
	if (ui.dspb_ScaleRStep_Train->value() == 0)
	{
		runParams.hv_ScaleRStep = typeStructTemplate.Auto;     //行方向缩放步长("auto")
	}
	else
	{
		runParams.hv_ScaleRStep = ui.dspb_ScaleRStep_Train->value();       //行方向缩放步长
	}
	runParams.hv_ScaleCMin = ui.dspb_ScaleCMin_Train->value();              //最小列缩放
	runParams.hv_ScaleCMax = ui.dspb_ScaleCMax_Train->value();              //最大列缩放
	if (ui.dspb_ScaleCStep_Train->value() == 0)
	{
		runParams.hv_ScaleCStep = typeStructTemplate.Auto;     //列方向缩放步长("auto")
	}
	else
	{
		runParams.hv_ScaleCStep = ui.dspb_ScaleCStep_Train->value();       //列方向缩放步长
	}
	runParams.hv_Optimization = HTuple(ui.cmb_Optimization_Train->currentText().toStdString().c_str());           //优化算法
	runParams.hv_Metric = HTuple(ui.cmb_Metric_Train->currentText().toStdString().c_str());                 //极性/度量
	if (ui.spb_Contrast_Train->value() == 0)
	{
		runParams.hv_Contrast = typeStructTemplate.Auto;               //对比度("auto")
	}
	else
	{
		runParams.hv_Contrast = ui.spb_Contrast_Train->value();               //对比度
	}

	if (ui.spb_MinContrast_Train->value() == 0)
	{
		runParams.hv_MinContrast = typeStructTemplate.Auto;       //最小对比度("auto")
	}
	else
	{
		runParams.hv_MinContrast = ui.spb_MinContrast_Train->value();   //最小对比度
	}
	runParams.ho_TrainRegion = TrainRoi_Template;				//模板训练区域
	runParams.hv_MinScore = ui.dspb_MinScore_Run->value();               //最小分数
	runParams.hv_NumMatches = ui.spb_NumMatches_Run->value();             //匹配个数，0则自动选择，100则最多匹配100个
	runParams.hv_MaxOverlap = ui.dspb_MaxOverlap_Run->value();             //要找到模型实例的最大重叠
	runParams.hv_SubPixel = HTuple(ui.cmb_SubPixel_Run->currentText().toStdString().c_str());               //亚像素精度
	runParams.hv_Greediness = ui.dspb_Greediness_Run->value();             //贪婪系数

	//*******************************************************************************
	//搜索区域赋值
	if (!ho_SearchRegions.isEmpty())
	{
		if (ho_SearchRegions.count() == 1)
		{
			SearchRoi_Template = ho_SearchRegions[0];
		}
		else
		{
			SearchRoi_Template = ho_SearchRegions[0];
			for (int i = 1; i < ho_SearchRegions.count(); i++)
			{
				Union2(SearchRoi_Template, ho_SearchRegions[i], &SearchRoi_Template);
			}
		}
		//窗口显示图形赋值
		ConcatObj(ho_ShowObj, SearchRoi_Template, &ho_ShowObj);
		runParams.ho_SearchRegion = SearchRoi_Template; 
	}
	else
	{
		//如果没有绘制搜索区域，则全图搜索
		GenEmptyObj(&SearchRoi_Template);
		SearchRoi_Template.Clear();
		GenEmptyObj(&runParams.ho_SearchRegion);
		runParams.ho_SearchRegion.Clear();
	}
}

//初始化模板显示表格
void TemplateWindow::IniTableData_Template()
{
	QTableWidgetItem   *hearderItem;
	QStringList hearderText;
	hearderText << "X" << "Y" << "角度" << "分数";
	ui.tablewidget_Result_Template->setColumnCount(hearderText.count());
	for (int i = 0; i < ui.tablewidget_Result_Template->columnCount(); i++)
	{
		hearderItem = new QTableWidgetItem(hearderText.at(i));
		QFont font = hearderItem->font();
		font.setBold(true);//设置为粗体
		font.setPointSize(12);//设置字体大小
		hearderItem->setTextColor(Qt::red);//字体颜色
		hearderItem->setFont(font);//设置字体
		ui.tablewidget_Result_Template->setHorizontalHeaderItem(i, hearderItem);
	}
}
//设置模板显示表格数据
void TemplateWindow::SetTableData_Template(const ResultParamsStruct_Template &resultStruct, qint64 Ct)
{
	//清空结果表格数据
	ui.tablewidget_Result_Template->clearContents();
	//判断找模板结果
	if (resultStruct.hv_RetNum == 0)
	{
		//没有找到模板，退出
		GenEmptyObj(&ho_ShowObj);
		showImg(ho_Image, "margin", "green");
		return;
	}
	//刷新图像
	ho_ShowObj.Clear();
	ho_ShowObj = resultStruct.ho_Contour_Template;
	showImg(ho_Image, "margin", "green");
	//刷新时间
	ui.lbl_RunTemplateCT->setText("CT:" + QString::number(Ct) + "ms");
	//刷新所有找到的模板信息
	int count = resultStruct.hv_RetNum.I();
	ui.tablewidget_Result_Template->setRowCount(count);
	for (int i = 0; i < count; i++)
	{
		QTableWidgetItem *item;
		QString str;
		//模板X
		str = QString::number(resultStruct.hv_Column[i].D(), 'f', 2);
		item = new QTableWidgetItem(str, 1000);
		item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
		ui.tablewidget_Result_Template->setItem(i, 0, item);
		//模板Y
		str = QString::number(resultStruct.hv_Row[i].D(), 'f', 2);
		item = new QTableWidgetItem(str, 1000);
		item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
		ui.tablewidget_Result_Template->setItem(i, 1, item);
		//模板角度
		str = QString::number(resultStruct.hv_Angle[i].D(), 'f', 2);
		item = new QTableWidgetItem(str, 1000);
		item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
		ui.tablewidget_Result_Template->setItem(i, 2, item);
		//模板分数
		str = QString::number(resultStruct.hv_Score[i].D(), 'f', 2);
		item = new QTableWidgetItem(str, 1000);
		item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
		ui.tablewidget_Result_Template->setItem(i, 3, item);
	}
}
//查找模板槽函数
int TemplateWindow::slot_FindTemplate(ResultParamsStruct_Template &resultParams)
{
	try
	{
		int ret = 1;
		//XML读取参数
		ErrorCode_Xml errorCode = dataIOC.ReadParams_Template(configPath, XMLPath, hv_RunParamsTemplate, processID, nodeName, processModbuleID);
		if (errorCode != Ok_Xml)
		{
			//XML读取失败，给默认值
			GenEmptyObj(&hv_RunParamsTemplate.ho_SearchRegion);
			hv_RunParamsTemplate.ho_SearchRegion.Clear();
			hv_RunParamsTemplate.hv_MatchMethod = "auto_scaled";  
			hv_RunParamsTemplate.hv_NumLevels = "auto";           
			hv_RunParamsTemplate.hv_AngleStart = -30;             
			hv_RunParamsTemplate.hv_AngleExtent = 30;             
			hv_RunParamsTemplate.hv_AngleStep = "auto";           
			hv_RunParamsTemplate.hv_ScaleRMin = 0.9;              
			hv_RunParamsTemplate.hv_ScaleRMax = 1.1;              
			hv_RunParamsTemplate.hv_ScaleRStep = "auto";          
			hv_RunParamsTemplate.hv_ScaleCMin = 0.9;              
			hv_RunParamsTemplate.hv_ScaleCMax = 1.1;				
			hv_RunParamsTemplate.hv_ScaleCStep = "auto";          
			hv_RunParamsTemplate.hv_Optimization = "auto";        
			hv_RunParamsTemplate.hv_Metric = "use_polarity";      
			hv_RunParamsTemplate.hv_Contrast = "auto";            
			hv_RunParamsTemplate.hv_MinContrast = "auto";         
		
			hv_RunParamsTemplate.hv_Angle_Original = 0;			
			hv_RunParamsTemplate.hv_CenterRow_Original = 0;		
			hv_RunParamsTemplate.hv_CenterCol_Original = 0;		
		
			hv_RunParamsTemplate.hv_MinScore = 0.5;               
			hv_RunParamsTemplate.hv_NumMatches = 1;               
			hv_RunParamsTemplate.hv_MaxOverlap = 0.5;             
			hv_RunParamsTemplate.hv_SubPixel = "least_squares";   
			hv_RunParamsTemplate.hv_Greediness = 0.9;             
			//保存一维码运行参数
			ret = dataIOC.WriteParams_Template(configPath, XMLPath, hv_RunParamsTemplate, processID, nodeName, processModbuleID);
			if (ret != 0)
			{
				return ret;
			}
		}
		//调用算法
		return TemplateDetect1->FindTemplate(ho_Image, hv_RunParamsTemplate, resultParams);
	}
	catch (...)
	{
		return -1;
	}
}
//训练模板槽函数
int TemplateWindow::slot_CreateTemplate(RunParamsStruct_Template &runParams)
{
	try
	{
		int ret = 1;
		//创建模板
		ret = TemplateDetect1->CreateTemplate(ho_Image, runParams);
		if (ret != 0)
		{
			return ret;
		}
		//保存模板匹配训练参数和运行参数
		ret = dataIOC.WriteParams_Template(configPath, XMLPath, runParams, processID, nodeName, processModbuleID);
		if (ret != 0)
		{
			return ret;
		}
		return 0;
	}
	catch (...)
	{
		return -1;
	}
}
//*******************************************************************************************************************************************************
