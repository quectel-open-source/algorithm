#include "IntersectionCircleCircleWindow.h"

IntersectionCircleCircleWindow::IntersectionCircleCircleWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowMinimizeButtonHint);
	//���ڳ�ʼ��
	InitWindow();

	CircleCircleIntersect1 = new IntersectionDetect();

	//�����Զ���ͼ
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
//�رմ���
void IntersectionCircleCircleWindow::on_btn_Hide_clicked()
{
	this->hide();
}
//��ʼ����ʾ����
void IntersectionCircleCircleWindow::InitWindow()
{
	//����halcon���ļ�·��Ϊutf8�������������
	SetSystem("filename_encoding", "utf8");
	//�������д��룬����������ƶ�ʱ������mouseMove����ʱ���Կ������ꡣ����ֻ������갴��ʱ�ſ��Կ�������
	ui.lbl_Window->setMouseTracking(true);
	//���ɿ�ͼ��
	GenEmptyObj(&ho_Image);
	GenEmptyObj(&ho_ShowObj);
	ho_Image.Clear();
	m_hHalconID = NULL;
	m_hLabelID = (Hlong)ui.lbl_Window->winId();

}

//��ʾͼ��
void IntersectionCircleCircleWindow::showImg(const HObject &ho_Img, HTuple hv_FillType, HTuple hv_Color)
{
	if (ho_Img.Key() == nullptr)
	{
		//ͼ��Ϊ�գ�����ͼ��clear
		QMessageBox::information(this, "��ʾ", "ͼ���ǿգ����ȼ���ͼ��!", QMessageBox::Ok);
		return;
	}

	//�жϴ��ھ��
	if (m_hHalconID != NULL)
	{
		//�����ͼ���������ͼ��
		DetachBackgroundFromWindow(m_hHalconID);
	}
	else
	{
		//�򿪴���
		OpenWindow(0, 0, ui.lbl_Window->width(), ui.lbl_Window->height(), m_hLabelID, "visible", "", &m_hHalconID);
	}

	//����ͼ����ʾ����
	SetDraw(m_hHalconID, hv_FillType);
	SetColor(m_hHalconID, hv_Color);
	SetLineWidth(m_hHalconID, 1);
	//���ô�����ʾ����
	ui.lbl_Window->setHalconWnd(ho_Img, ho_ShowObj, isShowObj, m_hHalconID, ui.lbl_Status);

	//��ȡͼ���С
	GetImageSize(ho_Img, &m_imgWidth, &m_imgHeight);
	//��ȡ����ϵ��
	TupleMin2(1.0 * ui.lbl_Window->width() / m_imgWidth, 1.0 * ui.lbl_Window->height() / m_imgHeight, &m_hvScaledRate);
	//����ͼ��
	ZoomImageFactor(ho_Img, &m_hResizedImg, m_hvScaledRate, m_hvScaledRate, "constant");
	//��ȡ���ź�Ĵ�С
	GetImageSize(m_hResizedImg, &m_scaledWidth, &m_scaledHeight);
	//�򿪴���
	if (1.0 * ui.lbl_Window->width() / m_imgWidth < 1.0 * ui.lbl_Window->height() / m_imgHeight)
	{
		SetWindowExtents(m_hHalconID, ui.lbl_Window->height() / 2.0 - m_scaledHeight / 2.0, 0, ui.lbl_Window->width(), m_scaledHeight);
	}
	else
	{
		SetWindowExtents(m_hHalconID, 0, ui.lbl_Window->width() / 2.0 - m_scaledWidth / 2.0, m_scaledWidth, ui.lbl_Window->height());

	}
	SetPart(m_hHalconID, 0, 0, m_imgHeight - 1, m_imgWidth - 1);
	//�����ʾͼ�񣬲�����˸(��ͼ�����óɴ��ڵı���ͼ)
	AttachBackgroundToWindow(ho_Img, m_hHalconID);

	//��ʾͼ��
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

//������ˢ��ͼ�񴫵ݲ���(��Ҫ������Ϊ�˹�������ʱ��ʾͼ��)
void IntersectionCircleCircleWindow::GiveParameterToWindow()
{
	if (ho_Image.Key() == nullptr)
	{
		QMessageBox::information(this, "��ʾ", "ͼ���ǿգ����ȼ���ͼ��!", QMessageBox::Ok);
		return;
	}

	//�жϴ��ھ��
	if (m_hHalconID != NULL)
	{
		//�����ͼ���������ͼ��
		//DetachBackgroundFromWindow(m_hHalconID);
	}
	else
	{
		//�򿪴���
		OpenWindow(0, 0, ui.lbl_Window->width(), ui.lbl_Window->height(), m_hLabelID, "visible", "", &m_hHalconID);
	}

	//����ͼ����ʾ����
	SetDraw(m_hHalconID, "margin");
	SetColor(m_hHalconID, "red");
	SetLineWidth(m_hHalconID, 1);
	//���ô�����ʾ����
	ui.lbl_Window->setHalconWnd(ho_Image, ho_ShowObj, isShowObj, m_hHalconID, ui.lbl_Status);

}

//��ͼƬ
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

//ͼ������Ӧ����
void IntersectionCircleCircleWindow::on_pBtn_FitImage_clicked()
{
	if (ho_Image.Key() == nullptr)
	{
		//ͼ��Ϊ�գ�����ͼ��clear
		QMessageBox::information(this, "��ʾ", "ͼ���ǿգ����ȼ���ͼ��!", QMessageBox::Ok);
		return;
	}
	showImg(ho_Image, "margin", "green");
}
//�Ƿ���ʾͼ�θ�ѡ��
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
	//������ˢ��ͼ�񴫵ݲ���(��Ҫ������Ϊ�˹�������ʱ��ʾͼ��)
	GiveParameterToWindow();
}
//��մ���
void IntersectionCircleCircleWindow::on_btn_ClearWindow_clicked()
{
	if (ho_Image.Key() == nullptr)
	{
		//ͼ��Ϊ�գ�����ͼ��clear
		QMessageBox::information(this, "��ʾ", "ͼ���ǿգ����ȼ���ͼ��!", QMessageBox::Ok);
		return;
	}
	//��մ�����ʾ��ͼ�α���
	GenEmptyObj(&ho_ShowObj);
	//��ʾԭͼ
	showImg(ho_Image, "margin", "green");
}
//���а�ť
void IntersectionCircleCircleWindow::on_pb_Run_clicked()
{
	SetRunParams_IntersectCircleCircle(CircleA, CircleB);
	int ret;
	HTuple hv_Row1, hv_Col1, hv_Row2, hv_Col2;
	QDateTime startTime = QDateTime::currentDateTime();
	ret = CircleCircleIntersect1->Intersection_CircleCircle(CircleA, CircleB, hv_Row1, hv_Col1, hv_Row2, hv_Col2);
	QDateTime endTime = QDateTime::currentDateTime();
	qint64 intervalTimeMS = startTime.msecsTo(endTime);

	//ˢ�½��
	GenCircleContourXld(&CircleA.ho_Contour_Circle, CircleA.hv_CircleRowCenter, CircleA.hv_CircleColumnCenter,
		CircleA.hv_CircleRadius, 0, 6.28318, "positive", 1);
	GenCircleContourXld(&CircleB.ho_Contour_Circle, CircleB.hv_CircleRowCenter, CircleB.hv_CircleColumnCenter,
		CircleB.hv_CircleRadius, 0, 6.28318, "positive", 1);
	SetTableData_IntersectCircleCircle(CircleA, CircleB, hv_Row1, hv_Col1, hv_Row2, hv_Col2, ret, intervalTimeMS);
}
//ˢ�½��
void IntersectionCircleCircleWindow::SetTableData_IntersectCircleCircle(const ResultParamsStruct_Circle &Circle1, const ResultParamsStruct_Circle &Circle2, HTuple hv_Row1, HTuple hv_Col1, HTuple hv_Row2, HTuple hv_Col2, int Ret, qint64 Ct)
{
	//��ս���������
	ui.lineEdit_Row1_ResultCircleCircle->text().clear();
	ui.lineEdit_Col1_ResultCircleCircle->text().clear();
	ui.lineEdit_Row2_ResultCircleCircle->text().clear();
	ui.lineEdit_Col2_ResultCircleCircle->text().clear();
	//�ж��Ƿ�OK
	if (Ret != 0)
	{
		//����ʧ��
		GenEmptyObj(&ho_ShowObj);
		showImg(ho_Image, "margin", "green");
		return;
	}
	//ˢ��ͼ��
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
	//ˢ��ʱ��
	ui.lbl_IntersectCircleCircleCT->setText("CT:" + QString::number(Ct) + "ms");

	//ˢ�½������
	ui.lineEdit_Row1_ResultCircleCircle->setText(QString::number(hv_Row1.D(), 'f', 4));
	ui.lineEdit_Col1_ResultCircleCircle->setText(QString::number(hv_Col1.D(), 'f', 4));
	ui.lineEdit_Row2_ResultCircleCircle->setText(QString::number(hv_Row2.D(), 'f', 4));
	ui.lineEdit_Col2_ResultCircleCircle->setText(QString::number(hv_Col2.D(), 'f', 4));
}
//ˢ�����в���
void IntersectionCircleCircleWindow::SetRunParams_IntersectCircleCircle(const ResultParamsStruct_Circle &Circle1, const ResultParamsStruct_Circle &Circle2)
{
	ui.dspb_Row1_CircleA->setValue(Circle1.hv_CircleRowCenter);
	ui.dspb_Col1_CircleA->setValue(Circle1.hv_CircleColumnCenter);
	ui.dspb_Radius_CircleA->setValue(Circle1.hv_CircleRadius);

	ui.dspb_Row1_CircleB->setValue(Circle2.hv_CircleRowCenter);
	ui.dspb_Col1_CircleB->setValue(Circle2.hv_CircleColumnCenter);
	ui.dspb_Radius_CircleB->setValue(Circle2.hv_CircleRadius);
}