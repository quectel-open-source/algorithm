#include "IntersectionLineLineWindow.h"

IntersectionLineLineWindow::IntersectionLineLineWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowMinimizeButtonHint);
	//���ڳ�ʼ��
	InitWindow();

	LineLineIntersect1 = new IntersectionDetect();

	//�����Զ���ͼ
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
//�رմ���
void IntersectionLineLineWindow::on_btn_Hide_clicked()
{
	this->hide();
}
//��ʼ����ʾ����
void IntersectionLineLineWindow::InitWindow()
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
void IntersectionLineLineWindow::showImg(const HObject &ho_Img, HTuple hv_FillType, HTuple hv_Color)
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
void IntersectionLineLineWindow::GiveParameterToWindow()
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

//ͼ������Ӧ����
void IntersectionLineLineWindow::on_pBtn_FitImage_clicked()
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
	//������ˢ��ͼ�񴫵ݲ���(��Ҫ������Ϊ�˹�������ʱ��ʾͼ��)
	GiveParameterToWindow();
}
//��մ���
void IntersectionLineLineWindow::on_btn_ClearWindow_clicked()
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
void IntersectionLineLineWindow::on_pb_Run_clicked()
{
	SetRunParams_IntersectLineLine(LineA, LineB);
	int ret;
	HTuple hv_Row, hv_Col;
	QDateTime startTime = QDateTime::currentDateTime();
	ret = LineLineIntersect1->Intersection_LineLine(LineA, LineB, hv_Row, hv_Col);
	QDateTime endTime = QDateTime::currentDateTime();
	qint64 intervalTimeMS = startTime.msecsTo(endTime);

	//ˢ�½��
	SetTableData_IntersectLineLine(LineA, LineB, hv_Row, hv_Col, ret, intervalTimeMS);
}
//ˢ�½��
void IntersectionLineLineWindow::SetTableData_IntersectLineLine(const ResultParamsStruct_Line &Line1, const ResultParamsStruct_Line &Line2, HTuple hv_RowRet, HTuple hv_ColRet, int Ret, qint64 Ct)
{
	//��ս���������
	ui.lineEdit_Row_ResultLineLine->text().clear();
	ui.lineEdit_Col_ResultLineLine->text().clear();
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
	ConcatObj(ho_ShowObj, Line1.ho_Contour_Line, &ho_ShowObj);
	ConcatObj(ho_ShowObj, Line2.ho_Contour_Line, &ho_ShowObj);
	HObject ho_Cross;
	GenCrossContourXld(&ho_Cross, hv_RowRet, hv_ColRet, 12, HTuple(45).TupleRad());
	ConcatObj(ho_ShowObj, ho_Cross, &ho_ShowObj);
	showImg(ho_Image, "margin", "green");
	//ˢ��ʱ��
	ui.lbl_IntersectLineLineCT->setText("CT:" + QString::number(Ct) + "ms");

	//ˢ�½������
	ui.lineEdit_Row_ResultLineLine->setText(QString::number(hv_RowRet.D(), 'f', 4));
	ui.lineEdit_Col_ResultLineLine->setText(QString::number(hv_ColRet.D(), 'f', 4));
}
//ˢ�����в���
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