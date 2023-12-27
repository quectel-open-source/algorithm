#include "IntersectionCircleCircleWindow.h"

IntersectionCircleCircleWindow::IntersectionCircleCircleWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowMinimizeButtonHint);
	//窗口初始化
	InitWindow();

	CircleCircleIntersect1 = new IntersectionDetect();

	//开机自动读图
	QString Filepath = QCoreApplication::applicationDirPath() + "/01.png";
	ReadImage(&ho_Image, HTuple(Filepath.toStdString().c_str()));
}

IntersectionCircleCircleWindow::IntersectionCircleCircleWindow(HObject image, ParamsStruct_Circle circle1, ParamsStruct_Circle circle2){
	ui.setupUi(this);
	InitWindow();
	CircleA.hv_CircleRowCenter = circle1.Row;
	CircleA.hv_CircleColumnCenter = circle1.Column;
	CircleA.hv_CircleRadius = circle1.Radius;
	CircleB.hv_CircleRowCenter = circle2.Row;
	CircleB.hv_CircleColumnCenter = circle2.Column;
	CircleB.hv_CircleRadius = circle2.Radius;

	ho_Image = image;

}

IntersectionCircleCircleWindow::~IntersectionCircleCircleWindow()
{
	delete CircleCircleIntersect1;
}
//关闭窗口
void IntersectionCircleCircleWindow::on_btn_Hide_clicked()
{
	this->hide();
}
//初始化显示窗口
void IntersectionCircleCircleWindow::InitWindow()
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
void IntersectionCircleCircleWindow::showImg(const HObject &ho_Img, HTuple hv_FillType, HTuple hv_Color)
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
void IntersectionCircleCircleWindow::GiveParameterToWindow()
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
void IntersectionCircleCircleWindow::on_pBtn_ReadImage_clicked()
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
void IntersectionCircleCircleWindow::on_pBtn_FitImage_clicked()
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
void IntersectionCircleCircleWindow::on_ckb_ShowObj_stateChanged(int arg1)
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
void IntersectionCircleCircleWindow::on_btn_ClearWindow_clicked()
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
void IntersectionCircleCircleWindow::on_pb_Run_clicked()
{
	SetRunParams_IntersectCircleCircle(CircleA, CircleB);
	int ret;
	HTuple hv_Row1, hv_Col1, hv_Row2, hv_Col2;
	QDateTime startTime = QDateTime::currentDateTime();
	ret = CircleCircleIntersect1->Intersection_CircleCircle(CircleA, CircleB, hv_Row1, hv_Col1, hv_Row2, hv_Col2);
	QDateTime endTime = QDateTime::currentDateTime();
	qint64 intervalTimeMS = startTime.msecsTo(endTime);

	//刷新结果
	GenCircleContourXld(&CircleA.ho_Contour_Circle, CircleA.hv_CircleRowCenter, CircleA.hv_CircleColumnCenter,
		CircleA.hv_CircleRadius, 0, 6.28318, "positive", 1);
	GenCircleContourXld(&CircleB.ho_Contour_Circle, CircleB.hv_CircleRowCenter, CircleB.hv_CircleColumnCenter,
		CircleB.hv_CircleRadius, 0, 6.28318, "positive", 1);
	SetTableData_IntersectCircleCircle(CircleA, CircleB, hv_Row1, hv_Col1, hv_Row2, hv_Col2, ret, intervalTimeMS);
}
//刷新结果
void IntersectionCircleCircleWindow::SetTableData_IntersectCircleCircle(const ResultParamsStruct_Circle &Circle1, const ResultParamsStruct_Circle &Circle2, HTuple hv_Row1, HTuple hv_Col1, HTuple hv_Row2, HTuple hv_Col2, int Ret, qint64 Ct)
{
	//清空结果表格数据
	ui.lineEdit_Row1_ResultCircleCircle->text().clear();
	ui.lineEdit_Col1_ResultCircleCircle->text().clear();
	ui.lineEdit_Row2_ResultCircleCircle->text().clear();
	ui.lineEdit_Col2_ResultCircleCircle->text().clear();
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
	ConcatObj(ho_ShowObj, Circle1.ho_Contour_Circle, &ho_ShowObj);
	ConcatObj(ho_ShowObj, Circle2.ho_Contour_Circle, &ho_ShowObj);
	HObject ho_Cross;
	GenCrossContourXld(&ho_Cross, hv_Row1, hv_Col1, 12, HTuple(45).TupleRad());
	ConcatObj(ho_ShowObj, ho_Cross, &ho_ShowObj);
	HObject ho_Cross1;
	GenCrossContourXld(&ho_Cross1, hv_Row2, hv_Col2, 12, HTuple(45).TupleRad());
	ConcatObj(ho_ShowObj, ho_Cross1, &ho_ShowObj);
	showImg(ho_Image, "margin", "green");
	//刷新时间
	ui.lbl_IntersectCircleCircleCT->setText("CT:" + QString::number(Ct) + "ms");

	//刷新结果坐标
	ui.lineEdit_Row1_ResultCircleCircle->setText(QString::number(hv_Row1.D(), 'f', 4));
	ui.lineEdit_Col1_ResultCircleCircle->setText(QString::number(hv_Col1.D(), 'f', 4));
	ui.lineEdit_Row2_ResultCircleCircle->setText(QString::number(hv_Row2.D(), 'f', 4));
	ui.lineEdit_Col2_ResultCircleCircle->setText(QString::number(hv_Col2.D(), 'f', 4));
}
//刷新运行参数
void IntersectionCircleCircleWindow::SetRunParams_IntersectCircleCircle(const ResultParamsStruct_Circle &Circle1, const ResultParamsStruct_Circle &Circle2)
{
	ui.dspb_Row1_CircleA->setValue(Circle1.hv_CircleRowCenter);
	ui.dspb_Col1_CircleA->setValue(Circle1.hv_CircleColumnCenter);
	ui.dspb_Radius_CircleA->setValue(Circle1.hv_CircleRadius);

	ui.dspb_Row1_CircleB->setValue(Circle2.hv_CircleRowCenter);
	ui.dspb_Col1_CircleB->setValue(Circle2.hv_CircleColumnCenter);
	ui.dspb_Radius_CircleB->setValue(Circle2.hv_CircleRadius);
}