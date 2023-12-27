#include "TemplateWindow.h"

TemplateWindow::TemplateWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowMinimizeButtonHint);
	//���ڳ�ʼ��
	InitWindow();

	//ģ��ƥ��
	IniTableData_Template();
	IniTemplateClassObject();

	//������ʱ��ʹ�õĲ����ؼ�(��Ҫ��һЩ��������������Ϊ�Զ�������)
	ui.label_5->setVisible(false);
	ui.dspb_AngleStep_Train->setVisible(false);
	ui.label_8->setVisible(false);
	ui.dspb_ScaleRStep_Train->setVisible(false);
	ui.label_11->setVisible(false);
	ui.dspb_ScaleCStep_Train->setVisible(false);
	ui.label_12->setVisible(false);
	ui.cmb_Optimization_Train->setVisible(false);

	//��ʼ��ģ��ƥ��ģʽ
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
	//�ͷ�ģ��new���ڴ�
	delete TemplateDetect1;
}

//�رմ���
void TemplateWindow::on_btn_Hide_clicked()
{
	this->hide();
}
//��ʼ����ʾ����
void TemplateWindow::InitWindow()
{

	/*OpenWindow(0, 0, ui.lbl_Window->width(), ui.lbl_Window->height(), (Hlong)ui.lbl_Window->winId(), "", "", &hv_WindowHandle);
	ui.lbl_Window->installEventFilter(this);
	ui.lbl_Window->setMouseTracking(true);
	ROIControl = new ROIController(hv_WindowHandle, "MSA");
	ROIControl->View_MSA = this;
	widthImage = 0, heightImage = 0;*/

	//����halcon���ļ�·��Ϊutf8�������������
	SetSystem("filename_encoding", "utf8");
	//�������д��룬����������ƶ�ʱ������mouseMove����ʱ���Կ������ꡣ����ֻ������갴��ʱ�ſ��Կ�������
	ui.lbl_Window->setMouseTracking(true);
	//���ɿ�ͼ��
	GenEmptyObj(&ho_Image);
	ho_Image.Clear();
	m_hHalconID = NULL;
	m_hLabelID = (Hlong)ui.lbl_Window->winId();

}

//ģ��������ʼ��
void TemplateWindow::IniTemplateClassObject()
{
	TemplateDetect1 = new TemplateDetect(nodeName, processModbuleID, processID, XMLPath);
}
//��ʾͼ��
void TemplateWindow::showImg(const HObject &ho_Img, HTuple hv_FillType, HTuple hv_Color)
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
void TemplateWindow::GiveParameterToWindow()
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

//ͼ������Ӧ����
void TemplateWindow::on_pBtn_FitImage_clicked()
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
	//������ˢ��ͼ�񴫵ݲ���(��Ҫ������Ϊ�˹�������ʱ��ʾͼ��)
	GiveParameterToWindow();
}
//��մ���
void TemplateWindow::on_btn_ClearWindow_clicked()
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

//*****************ģ��ƥ����ش���****************************************************************
//ROI��״ѡ��
void TemplateWindow::on_cmb_RoiShape_Template_activated(const QString &arg1)
{
	RoiShape = arg1;
}
//ģ��ƥ������ѡ��
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
//����ģ��ѵ������
void TemplateWindow::on_btn_DrawTrainRoi_Template_clicked()
{
	if (ho_Image.Key() == nullptr)
	{
		//ͼ��Ϊ�գ�����ͼ��clear
		QMessageBox::information(this, "��ʾ", "ͼ���ǿգ����ȼ���ͼ��!", QMessageBox::Ok);
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
		//������ˢ��ͼ�񴫵ݲ���(��Ҫ������Ϊ�˹�������ʱ��ʾͼ��)
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
		//������ˢ��ͼ�񴫵ݲ���(��Ҫ������Ϊ�˹�������ʱ��ʾͼ��)
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
		//������ˢ��ͼ�񴫵ݲ���(��Ҫ������Ϊ�˹�������ʱ��ʾͼ��)
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
		//������ˢ��ͼ�񴫵ݲ���(��Ҫ������Ϊ�˹�������ʱ��ʾͼ��)
		GiveParameterToWindow();
		DispObj(TempRoi, m_hHalconID);
	}
	else if (RoiShape == "polygon")
	{
		HObject TempRoi;
		DrawRegion(&TempRoi, m_hHalconID);

		ho_TemplateRegions.push_back(TempRoi);
		ConcatObj(ho_ShowObj, TempRoi, &ho_ShowObj);
		//������ˢ��ͼ�񴫵ݲ���(��Ҫ������Ϊ�˹�������ʱ��ʾͼ��)
		GiveParameterToWindow();
		DispObj(TempRoi, m_hHalconID);
	}
	else
	{
		QMessageBox::information(this, "��ʾ", "��ѡ��������״!", QMessageBox::Ok);
	}
}
//����ģ����������
void TemplateWindow::on_btn_DrawSearchRoi_Template_clicked()
{
	if (ho_Image.Key() == nullptr)
	{
		//ͼ��Ϊ�գ�����ͼ��clear
		QMessageBox::information(this, "��ʾ", "ͼ���ǿգ����ȼ���ͼ��!", QMessageBox::Ok);
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
		//������ˢ��ͼ�񴫵ݲ���(��Ҫ������Ϊ�˹�������ʱ��ʾͼ��)
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
		//������ˢ��ͼ�񴫵ݲ���(��Ҫ������Ϊ�˹�������ʱ��ʾͼ��)
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
		//������ˢ��ͼ�񴫵ݲ���(��Ҫ������Ϊ�˹�������ʱ��ʾͼ��)
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
		//������ˢ��ͼ�񴫵ݲ���(��Ҫ������Ϊ�˹�������ʱ��ʾͼ��)
		GiveParameterToWindow();
		DispObj(TempRoi, m_hHalconID);
	}
	else if (RoiShape == "polygon")
	{
		HObject TempRoi;
		DrawRegion(&TempRoi, m_hHalconID);
		ho_SearchRegions.push_back(TempRoi);
		ConcatObj(ho_ShowObj, TempRoi, &ho_ShowObj);
		//������ˢ��ͼ�񴫵ݲ���(��Ҫ������Ϊ�˹�������ʱ��ʾͼ��)
		GiveParameterToWindow();
		DispObj(TempRoi, m_hHalconID);
	}
	else
	{
		QMessageBox::information(this, "��ʾ", "��ѡ��������״!", QMessageBox::Ok);
	}
}
//������ģ����
void TemplateWindow::on_btn_DrawShaddowRoi_Template_clicked()
{
	if (ho_Image.Key() == nullptr)
	{
		//ͼ��Ϊ�գ�����ͼ��clear
		QMessageBox::information(this, "��ʾ", "ͼ���ǿգ����ȼ���ͼ��!", QMessageBox::Ok);
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
		//������ˢ��ͼ�񴫵ݲ���(��Ҫ������Ϊ�˹�������ʱ��ʾͼ��)
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
		//������ˢ��ͼ�񴫵ݲ���(��Ҫ������Ϊ�˹�������ʱ��ʾͼ��)
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
		//������ˢ��ͼ�񴫵ݲ���(��Ҫ������Ϊ�˹�������ʱ��ʾͼ��)
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
		//������ˢ��ͼ�񴫵ݲ���(��Ҫ������Ϊ�˹�������ʱ��ʾͼ��)
		GiveParameterToWindow();
		DispObj(TempRoi, m_hHalconID);
	}
	else if (RoiShape == "polygon")
	{
		HObject TempRoi;
		DrawRegion(&TempRoi, m_hHalconID);
		ho_ShadowRegions.push_back(TempRoi);
		ConcatObj(ho_ShowObj, TempRoi, &ho_ShowObj);
		//������ˢ��ͼ�񴫵ݲ���(��Ҫ������Ϊ�˹�������ʱ��ʾͼ��)
		GiveParameterToWindow();
		DispObj(TempRoi, m_hHalconID);
	}
	else
	{
		QMessageBox::information(this, "��ʾ", "��ѡ��������״!", QMessageBox::Ok);
	}
}
//�ϲ�ģ������Roi
void TemplateWindow::on_btn_UnionRoi_Template_clicked()
{
	if (ho_Image.Key() == nullptr)
	{
		//ͼ��Ϊ�գ�����ͼ��clear
		QMessageBox::information(this, "��ʾ", "ͼ���ǿգ����ȼ���ͼ��!", QMessageBox::Ok);
		return;
	}
	if (ho_TemplateRegions.isEmpty())
	{
		QMessageBox::information(this, "��ʾ", "ģ��ѵ������ROIΪ��!", QMessageBox::Ok);
		return;
	}
	else
	{
		SetColor(m_hHalconID, "red");
		SetLineWidth(m_hHalconID, 1);
		//ѵ������ϲ�
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

		//��ģ����ϲ�
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
			//������ʾͼ�θ�ֵ
			//GenEmptyObj(&ho_ShowObj);
			ConcatObj(ho_ShowObj, ShadowRoi_Template, &ho_ShowObj);
		}

		//�ٳ���ģ����
		if (!ho_ShadowRegions.isEmpty())
		{
			Difference(TrainRoi_Template, ShadowRoi_Template, &TrainRoi_Template);
		}

		//������ʾͼ�θ�ֵ
		//GenEmptyObj(&ho_ShowObj);
		ConcatObj(ho_ShowObj, TrainRoi_Template, &ho_ShowObj);
		//������ˢ��ͼ�񴫵ݲ���(��Ҫ������Ϊ�˹�������ʱ��ʾͼ��)
		GiveParameterToWindow();

		QMessageBox::information(this, "��ʾ", "�ϲ�ROI�ɹ���ѵ����������Ϊ:" + QString::number(ho_TemplateRegions.count()), QMessageBox::Ok);

		//���vector�ڴ�
		ho_TemplateRegions.clear();
		ho_ShadowRegions.clear();
	}
}
//���ģ������Roi
void TemplateWindow::on_btn_ClearRoi_Template_clicked()
{
	if (ho_Image.Key() == nullptr)
	{
		//ͼ��Ϊ�գ�����ͼ��clear
		QMessageBox::information(this, "��ʾ", "ͼ���ǿգ����ȼ���ͼ��!", QMessageBox::Ok);
		return;
	}
	//������򼯺�
	ho_TemplateRegions.clear();
	ho_SearchRegions.clear();
	ho_ShadowRegions.clear();
	//����������
	GenEmptyObj(&TrainRoi_Template);
	GenEmptyObj(&SearchRoi_Template);
	GenEmptyObj(&ShadowRoi_Template);
	//��մ�����ʾ��ͼ�α���
	GenEmptyObj(&ho_ShowObj);
	//��ʾԭͼ
	showImg(ho_Image, "margin", "green");
}
//ѵ��ģ��
void TemplateWindow::on_btn_Train_Template_clicked()
{
	if (ho_Image.Key() == nullptr)
	{
		//ͼ��Ϊ�գ�����ͼ��clear
		QMessageBox::information(this, "��ʾ", "ͼ���ǿգ����ȼ���ͼ��!", QMessageBox::Ok);
		return;
	}
	int ret = 1;
	//����ģ��
	//���ò���ģ������в���
	SetRunParams_Template(hv_RunParamsTemplate);
	ret = slot_CreateTemplate(hv_RunParamsTemplate);
	if (ret != 0)
	{
		QMessageBox::information(this, "��ʾ", "ģ��ѵ��ʧ��", QMessageBox::Ok);
		return;
	}
	//*******************************************************************************************************
	//����ģ��
	ResultParamsStruct_Template resultParams;
	QDateTime startTime = QDateTime::currentDateTime();
	ret = slot_FindTemplate(resultParams);
	QDateTime endTime = QDateTime::currentDateTime();
	qint64 intervalTimeMS = startTime.msecsTo(endTime);

	//ˢ�½��
	SetTableData_Template(resultParams, intervalTimeMS);
}
//����ģ��
void TemplateWindow::on_btn_FindTemplate_clicked()
{
	if (ho_Image.Key() == nullptr)
	{
		//ͼ��Ϊ�գ�����ͼ��clear
		QMessageBox::information(this, "��ʾ", "ͼ���ǿգ����ȼ���ͼ��!", QMessageBox::Ok);
		return;
	}
	int ret = 1;
	//����ģ��
	ResultParamsStruct_Template resultParams;
	QDateTime startTime = QDateTime::currentDateTime();
	ret = slot_FindTemplate(resultParams);
	QDateTime endTime = QDateTime::currentDateTime();
	//qint64 intervalTime = startTime.secsTo(endTime); //��ʱ���
	qint64 intervalTimeMS = startTime.msecsTo(endTime);

	//ˢ�½��
	SetTableData_Template(resultParams, intervalTimeMS);
}
//ģ���������
void TemplateWindow::on_btn_SaveTemplateData_clicked()
{
	int ret = 1;
	//���ò���ģ������в���
	SetRunParams_Template(hv_RunParamsTemplate);
	//����ģ��ƥ��ѵ�����������в���
	ret = dataIOC.WriteParams_Template(configPath, XMLPath, hv_RunParamsTemplate, processID, nodeName, processModbuleID);
	if (ret != 0)
	{
		QMessageBox::information(this, "��ʾ", "��������ʧ��", QMessageBox::Ok);
		return;
	}
}
//ģ�������ȡ
void TemplateWindow::on_btn_ReadTemplateData_clicked()
{
	ErrorCode_Xml errorCode; 
	//��ȡģ��ƥ�����
	errorCode = dataIOC.ReadParams_Template(configPath, XMLPath, hv_RunParamsTemplate, processID, nodeName, processModbuleID);
	if (errorCode != Ok_Xml)
	{
		QMessageBox::information(this, "��ʾ", "������ȡʧ��", QMessageBox::Ok);
		return;
	}
	//�������µ�����
	UpdateTemplateDataWindow(hv_RunParamsTemplate);
}

//����ģ��ѵ�����������в�������
void TemplateWindow::UpdateTemplateDataWindow(const RunParamsStruct_Template &RunParams)
{
	//����ѵ������
	ModelTypeStruct_Template typeStructTemplate;
	if (RunParams.hv_MatchMethod == typeStructTemplate.None)
	{
		ui.cmb_MatchMethod_Train->setCurrentText("������״������");
	}
	else if (RunParams.hv_MatchMethod == typeStructTemplate.Auto_None)
	{
		ui.cmb_MatchMethod_Train->setCurrentText("������״�������Զ�����");
	}
	else if (RunParams.hv_MatchMethod == typeStructTemplate.Scaled)
	{
		ui.cmb_MatchMethod_Train->setCurrentText("������״ͬ�������Զ�����");
	}
	else if (RunParams.hv_MatchMethod == typeStructTemplate.Auto_scaled)
	{
		ui.cmb_MatchMethod_Train->setCurrentText("������״ͬ�������Զ�����");
	}
	else if (RunParams.hv_MatchMethod == typeStructTemplate.Aniso)
	{
		ui.cmb_MatchMethod_Train->setCurrentText("������״�첽����");
	}
	else if (RunParams.hv_MatchMethod == typeStructTemplate.Auto_Aniso)
	{
		ui.cmb_MatchMethod_Train->setCurrentText("������״�첽�����Զ�����");
	}
	else if (RunParams.hv_MatchMethod == typeStructTemplate.Ncc)
	{
		ui.cmb_MatchMethod_Train->setCurrentText("���ڻ����");
	}
	else if (RunParams.hv_MatchMethod == typeStructTemplate.Auto_Ccc)
	{
		ui.cmb_MatchMethod_Train->setCurrentText("���ڻ�����Զ�����");
	}

	//�ж�tuple���������ǲ�������
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

	//�������в���
	ui.dspb_MinScore_Run->setValue(RunParams.hv_MinScore.D());
	ui.spb_NumMatches_Run->setValue(RunParams.hv_NumMatches.I());
	ui.dspb_MaxOverlap_Run->setValue(RunParams.hv_MaxOverlap.D());
	ui.cmb_SubPixel_Run->setCurrentText(QString::fromUtf8(RunParams.hv_SubPixel.S().Text()));
	ui.dspb_Greediness_Run->setValue(RunParams.hv_Greediness.D());
	SearchRoi_Template = RunParams.ho_SearchRegion;
}
//����ģ��ṹ�������ֵ����
void TemplateWindow::SetRunParams_Template(RunParamsStruct_Template &runParams)
{
	ModelTypeStruct_Template typeStructTemplate;
	HTuple hv_typeTemp;

	if (ui.cmb_MatchMethod_Train->currentText().toStdString() == "������״������")
	{
		hv_typeTemp = typeStructTemplate.None;
	}
	else if (ui.cmb_MatchMethod_Train->currentText().toStdString() == "������״�������Զ�����")
	{
		hv_typeTemp = typeStructTemplate.Auto_None;
	}
	else if (ui.cmb_MatchMethod_Train->currentText().toStdString() == "������״ͬ������")
	{
		hv_typeTemp = typeStructTemplate.Scaled;
	}
	else if (ui.cmb_MatchMethod_Train->currentText().toStdString() == "������״ͬ�������Զ�����")
	{
		hv_typeTemp = typeStructTemplate.Auto_scaled;
	}
	else if (ui.cmb_MatchMethod_Train->currentText().toStdString() == "������״�첽����")
	{
		hv_typeTemp = typeStructTemplate.Aniso;
	}
	else if (ui.cmb_MatchMethod_Train->currentText().toStdString() == "������״�첽�����Զ�����")
	{
		hv_typeTemp = typeStructTemplate.Auto_Aniso;
	}
	else if (ui.cmb_MatchMethod_Train->currentText().toStdString() == "���ڻ����")
	{
		hv_typeTemp = typeStructTemplate.Ncc;
	}
	else if (ui.cmb_MatchMethod_Train->currentText().toStdString() == "���ڻ�����Զ�����")
	{
		hv_typeTemp = typeStructTemplate.Auto_Ccc;
	}
	else
	{
		hv_typeTemp = typeStructTemplate.Auto_None;
	}
	runParams.hv_MatchMethod = hv_typeTemp;   //����ģʽ:"none"������,"scaled"ͬ������,"aniso"�첽����,"auto"�Զ�

	if (ui.spb_NumLevels_Train->value() == -1)
	{
		runParams.hv_NumLevels = typeStructTemplate.Auto;  //����������("auto")
	}
	else
	{
		runParams.hv_NumLevels = ui.spb_NumLevels_Train->value();  //����������
	}
	runParams.hv_AngleStart = ui.dspb_AngleStart_Train->value();             //��ʼ�Ƕ�
	runParams.hv_AngleExtent = ui.dspb_AngleExtent_Train->value();            //�Ƕȷ�Χ
	if (ui.dspb_AngleStep_Train->value() == 0)
	{
		runParams.hv_AngleStep = typeStructTemplate.Auto;   //�ǶȲ���("auto")
	}
	else
	{
		runParams.hv_AngleStep = ui.dspb_AngleStep_Train->value();             //�ǶȲ���
	}
	runParams.hv_ScaleRMin = ui.dspb_ScaleRMin_Train->value();              //��С������
	runParams.hv_ScaleRMax = ui.dspb_ScaleRMax_Train->value();              //���������
	if (ui.dspb_ScaleRStep_Train->value() == 0)
	{
		runParams.hv_ScaleRStep = typeStructTemplate.Auto;     //�з������Ų���("auto")
	}
	else
	{
		runParams.hv_ScaleRStep = ui.dspb_ScaleRStep_Train->value();       //�з������Ų���
	}
	runParams.hv_ScaleCMin = ui.dspb_ScaleCMin_Train->value();              //��С������
	runParams.hv_ScaleCMax = ui.dspb_ScaleCMax_Train->value();              //���������
	if (ui.dspb_ScaleCStep_Train->value() == 0)
	{
		runParams.hv_ScaleCStep = typeStructTemplate.Auto;     //�з������Ų���("auto")
	}
	else
	{
		runParams.hv_ScaleCStep = ui.dspb_ScaleCStep_Train->value();       //�з������Ų���
	}
	runParams.hv_Optimization = HTuple(ui.cmb_Optimization_Train->currentText().toStdString().c_str());           //�Ż��㷨
	runParams.hv_Metric = HTuple(ui.cmb_Metric_Train->currentText().toStdString().c_str());                 //����/����
	if (ui.spb_Contrast_Train->value() == 0)
	{
		runParams.hv_Contrast = typeStructTemplate.Auto;               //�Աȶ�("auto")
	}
	else
	{
		runParams.hv_Contrast = ui.spb_Contrast_Train->value();               //�Աȶ�
	}

	if (ui.spb_MinContrast_Train->value() == 0)
	{
		runParams.hv_MinContrast = typeStructTemplate.Auto;       //��С�Աȶ�("auto")
	}
	else
	{
		runParams.hv_MinContrast = ui.spb_MinContrast_Train->value();   //��С�Աȶ�
	}
	runParams.ho_TrainRegion = TrainRoi_Template;				//ģ��ѵ������
	runParams.hv_MinScore = ui.dspb_MinScore_Run->value();               //��С����
	runParams.hv_NumMatches = ui.spb_NumMatches_Run->value();             //ƥ�������0���Զ�ѡ��100�����ƥ��100��
	runParams.hv_MaxOverlap = ui.dspb_MaxOverlap_Run->value();             //Ҫ�ҵ�ģ��ʵ��������ص�
	runParams.hv_SubPixel = HTuple(ui.cmb_SubPixel_Run->currentText().toStdString().c_str());               //�����ؾ���
	runParams.hv_Greediness = ui.dspb_Greediness_Run->value();             //̰��ϵ��

	//*******************************************************************************
	//��������ֵ
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
		//������ʾͼ�θ�ֵ
		ConcatObj(ho_ShowObj, SearchRoi_Template, &ho_ShowObj);
		runParams.ho_SearchRegion = SearchRoi_Template; 
	}
	else
	{
		//���û�л�������������ȫͼ����
		GenEmptyObj(&SearchRoi_Template);
		SearchRoi_Template.Clear();
		GenEmptyObj(&runParams.ho_SearchRegion);
		runParams.ho_SearchRegion.Clear();
	}
}

//��ʼ��ģ����ʾ���
void TemplateWindow::IniTableData_Template()
{
	QTableWidgetItem   *hearderItem;
	QStringList hearderText;
	hearderText << "X" << "Y" << "�Ƕ�" << "����";
	ui.tablewidget_Result_Template->setColumnCount(hearderText.count());
	for (int i = 0; i < ui.tablewidget_Result_Template->columnCount(); i++)
	{
		hearderItem = new QTableWidgetItem(hearderText.at(i));
		QFont font = hearderItem->font();
		font.setBold(true);//����Ϊ����
		font.setPointSize(12);//���������С
		hearderItem->setTextColor(Qt::red);//������ɫ
		hearderItem->setFont(font);//��������
		ui.tablewidget_Result_Template->setHorizontalHeaderItem(i, hearderItem);
	}
}
//����ģ����ʾ�������
void TemplateWindow::SetTableData_Template(const ResultParamsStruct_Template &resultStruct, qint64 Ct)
{
	//��ս���������
	ui.tablewidget_Result_Template->clearContents();
	//�ж���ģ����
	if (resultStruct.hv_RetNum == 0)
	{
		//û���ҵ�ģ�壬�˳�
		GenEmptyObj(&ho_ShowObj);
		showImg(ho_Image, "margin", "green");
		return;
	}
	//ˢ��ͼ��
	ho_ShowObj.Clear();
	ho_ShowObj = resultStruct.ho_Contour_Template;
	showImg(ho_Image, "margin", "green");
	//ˢ��ʱ��
	ui.lbl_RunTemplateCT->setText("CT:" + QString::number(Ct) + "ms");
	//ˢ�������ҵ���ģ����Ϣ
	int count = resultStruct.hv_RetNum.I();
	ui.tablewidget_Result_Template->setRowCount(count);
	for (int i = 0; i < count; i++)
	{
		QTableWidgetItem *item;
		QString str;
		//ģ��X
		str = QString::number(resultStruct.hv_Column[i].D(), 'f', 2);
		item = new QTableWidgetItem(str, 1000);
		item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
		ui.tablewidget_Result_Template->setItem(i, 0, item);
		//ģ��Y
		str = QString::number(resultStruct.hv_Row[i].D(), 'f', 2);
		item = new QTableWidgetItem(str, 1000);
		item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
		ui.tablewidget_Result_Template->setItem(i, 1, item);
		//ģ��Ƕ�
		str = QString::number(resultStruct.hv_Angle[i].D(), 'f', 2);
		item = new QTableWidgetItem(str, 1000);
		item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
		ui.tablewidget_Result_Template->setItem(i, 2, item);
		//ģ�����
		str = QString::number(resultStruct.hv_Score[i].D(), 'f', 2);
		item = new QTableWidgetItem(str, 1000);
		item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
		ui.tablewidget_Result_Template->setItem(i, 3, item);
	}
}
//����ģ��ۺ���
int TemplateWindow::slot_FindTemplate(ResultParamsStruct_Template &resultParams)
{
	try
	{
		int ret = 1;
		//XML��ȡ����
		ErrorCode_Xml errorCode = dataIOC.ReadParams_Template(configPath, XMLPath, hv_RunParamsTemplate, processID, nodeName, processModbuleID);
		if (errorCode != Ok_Xml)
		{
			//XML��ȡʧ�ܣ���Ĭ��ֵ
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
			//����һά�����в���
			ret = dataIOC.WriteParams_Template(configPath, XMLPath, hv_RunParamsTemplate, processID, nodeName, processModbuleID);
			if (ret != 0)
			{
				return ret;
			}
		}
		//�����㷨
		return TemplateDetect1->FindTemplate(ho_Image, hv_RunParamsTemplate, resultParams);
	}
	catch (...)
	{
		return -1;
	}
}
//ѵ��ģ��ۺ���
int TemplateWindow::slot_CreateTemplate(RunParamsStruct_Template &runParams)
{
	try
	{
		int ret = 1;
		//����ģ��
		ret = TemplateDetect1->CreateTemplate(ho_Image, runParams);
		if (ret != 0)
		{
			return ret;
		}
		//����ģ��ƥ��ѵ�����������в���
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
