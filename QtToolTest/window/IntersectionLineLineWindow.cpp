#include "IntersectionLineLineWindow.h"

IntersectionLineLineWindow::IntersectionLineLineWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowMinimizeButtonHint);
	//窗口初始化
	InitWindow();

	LineLineIntersect1 = new IntersectionDetect();

	//开机自动读图
	QString Filepath = QCoreApplication::applicationDirPath() + "/01.png";
	ReadImage(&ho_Image, HTuple(Filepath.toStdString().c_str()));
}

IntersectionLineLineWindow::IntersectionLineLineWindow(HObject image, ParamsStruct_Line line1, ParamsStruct_Line line2){
	ui.setupUi(this);
	LineA.hv_LineRowBegin= line1.RowBegin;	
	LineA.hv_LineColumnBegin= line1.ColumnBegin;
	LineA.hv_LineRowEnd= line1.RowEnd;
	LineA.hv_LineColumnEnd= line1.ColumnEnd;

	LineB.hv_LineRowBegin= line2.RowBegin;
	LineB.hv_LineColumnBegin= line2.ColumnBegin;
	LineB.hv_LineRowEnd= line2.RowEnd;
	LineB.hv_LineColumnEnd= line2.ColumnEnd;

	ho_Image= image;
	InitWindow();
}

IntersectionLineLineWindow::~IntersectionLineLineWindow()
{
	delete LineLineIntersect1;
}
//关闭窗口
void IntersectionLineLineWindow::on_btn_Hide_clicked()
{
	this->hide();
}
//初始化显示窗口
void IntersectionLineLineWindow::InitWindow()
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
void IntersectionLineLineWindow::showImg(const HObject &ho_Img, HTuple hv_FillType, HTuple hv_Color)
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
void IntersectionLineLineWindow::GiveParameterToWindow()
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
void IntersectionLineLineWindow::on_pBtn_ReadImage_clicked()
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
void IntersectionLineLineWindow::on_pBtn_FitImage_clicked()
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
void IntersectionLineLineWindow::on_ckb_ShowObj_stateChanged(int arg1)
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
void IntersectionLineLineWindow::on_btn_ClearWindow_clicked()
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
//运行按钮
void IntersectionLineLineWindow::on_pb_Run_clicked()
{
	SetRunParams_IntersectLineLine(LineA, LineB);
	int ret;
	HTuple hv_Row, hv_Col;
	QDateTime startTime = QDateTime::currentDateTime();
	ret = LineLineIntersect1->Intersection_LineLine(LineA, LineB, hv_Row, hv_Col);
	QDateTime endTime = QDateTime::currentDateTime();
	qint64 intervalTimeMS = startTime.msecsTo(endTime);

	//刷新结果
	SetTableData_IntersectLineLine(LineA, LineB, hv_Row, hv_Col, ret, intervalTimeMS);
}
//刷新结果
void IntersectionLineLineWindow::SetTableData_IntersectLineLine(const ResultParamsStruct_Line &Line1, const ResultParamsStruct_Line &Line2, HTuple hv_RowRet, HTuple hv_ColRet, int Ret, qint64 Ct)
{
	//清空结果表格数据
	ui.lineEdit_Row_ResultLineLine->text().clear();
	ui.lineEdit_Col_ResultLineLine->text().clear();
	//判断是否OK
	if (Ret != 0)
	{
		//计算失败
		GenEmptyObj(&ho_ShowObj);
		showImg(ho_Image, "margin", "green");
		return;
	}
	//刷新图像
	GenEmptyObj(&ho_ShowObj);
	ConcatObj(ho_ShowObj, Line1.ho_Contour_Line, &ho_ShowObj);
	ConcatObj(ho_ShowObj, Line2.ho_Contour_Line, &ho_ShowObj);
	HObject ho_Cross;
	GenCrossContourXld(&ho_Cross, hv_RowRet, hv_ColRet, 12, HTuple(45).TupleRad());
	ConcatObj(ho_ShowObj, ho_Cross, &ho_ShowObj);
	showImg(ho_Image, "margin", "green");
	//刷新时间
	ui.lbl_IntersectLineLineCT->setText("CT:" + QString::number(Ct) + "ms");

	//刷新结果坐标
	ui.lineEdit_Row_ResultLineLine->setText(QString::number(hv_RowRet.D(), 'f', 4));
	ui.lineEdit_Col_ResultLineLine->setText(QString::number(hv_ColRet.D(), 'f', 4));
}
//刷新运行参数
void IntersectionLineLineWindow::SetRunParams_IntersectLineLine(const ResultParamsStruct_Line &Line1, const ResultParamsStruct_Line &Line2)
{
	ui.dspb_Row1_LineA->setValue(Line1.hv_LineRowBegin);
	ui.dspb_Col1_LineA->setValue(Line1.hv_LineColumnBegin);
	ui.dspb_Row2_LineA->setValue(Line1.hv_LineRowEnd);
	ui.dspb_Col2_LineA->setValue(Line1.hv_LineColumnEnd);

	ui.dspb_Row1_LineB->setValue(Line2.hv_LineRowBegin);
	ui.dspb_Col1_LineB->setValue(Line2.hv_LineColumnBegin);
	ui.dspb_Row2_LineB->setValue(Line2.hv_LineRowEnd);
	ui.dspb_Col2_LineB->setValue(Line2.hv_LineColumnEnd);
}