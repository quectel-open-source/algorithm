#include "QRCodeWindow.h"

QRCodeWindow::QRCodeWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowMinimizeButtonHint);
	//���ڳ�ʼ��
	InitWindow();
	//��ά����
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
	//�ͷŶ�ά���ڴ�
	delete code2dParams1;
}
//�رմ���
void QRCodeWindow::on_btn_Hide_clicked()
{
	this->hide();
}
//��ʼ����ʾ����
void QRCodeWindow::InitWindow()
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

//��ʾͼ��
void QRCodeWindow::showImg(const HObject &ho_Img, HTuple hv_FillType, HTuple hv_Color)
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
void QRCodeWindow::GiveParameterToWindow()
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
void QRCodeWindow::on_pBtn_ReadImage_clicked()
{
	//QString path = QFileDialog::getOpenFileName(this, "����ͼ��", "./", "ͼ���ļ�(*.bmp *.png *.jpg)");
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

//ͼ������Ӧ����
void QRCodeWindow::on_pBtn_FitImage_clicked()
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
	//������ˢ��ͼ�񴫵ݲ���(��Ҫ������Ϊ�˹�������ʱ��ʾͼ��)
	GiveParameterToWindow();
}
//��մ���
void QRCodeWindow::on_btn_ClearWindow_clicked()
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
//****************��ά������غ���***********************
//��ά��������ʼ��
void QRCodeWindow::IniCode2dClassObject()
{
	code2dParams1 = new QRCodeDetect(nodeName, processModbuleID, processID, XMLPath);
}
//���в��Ҷ�ά��ṹ�������ֵ����
void QRCodeWindow::SetRunParams_Code2d(RunParamsStruct_Code2d &runParams)
{
	//���ö�ά�빤������
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

	if (ui.cmb_Tolerance_Code2d->currentText() == "��׼")
	{
		runParams.hv_Tolerance = "low";
	}
	else
	{
		runParams.hv_Tolerance = "high";
	}
	//*******************************************************************************
	//��������ֵ
	GenEmptyObj(&SearchRoi_Code2d);
	//��������ϲ�
	if (!ho_Code2dRegions.isEmpty())
	{
		//һά����������ϲ�
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
		//������ʾͼ�θ�ֵ
		ConcatObj(ho_ShowObj, SearchRoi_Code2d, &ho_ShowObj);
		runParams.ho_SearchRegion = SearchRoi_Code2d;
	}
	else
	{
		//���û�л�����������,�ÿ�
		GenEmptyObj(&SearchRoi_Code2d);
		SearchRoi_Code2d.Clear();
		GenEmptyObj(&runParams.ho_SearchRegion);
		runParams.ho_SearchRegion.Clear();
	}
}
//���ö�ά������ʾ�������
void QRCodeWindow::SetTableData_Code2d(const ResultParamsStruct_Code2d &resultStruct, qint64 Ct)
{
	//��ս���������
	ui.tablewidget_Results_Code2d->clearContents();
	//�ж��Ƿ��ҵ���ά��
	if (resultStruct.hv_RetNum == 0)
	{
		//û���ҵ���ά�룬�˳�
		GenEmptyObj(&ho_ShowObj);
		showImg(ho_Image, "margin", "green");
		return;
	}
	//ˢ��ͼ��
	GenEmptyObj(&ho_ShowObj);
	ConcatObj(ho_ShowObj, resultStruct.ho_ContourCode2d, &ho_ShowObj);
	showImg(ho_Image, "margin", "green");
	//ˢ��ʱ��
	ui.lbl_CT_Code2d->setText("CT:" + QString::number(Ct) + "ms");

	//ˢ�������ҵ��Ķ�ά����Ϣ
	int count = resultStruct.hv_RetNum.I();
	ui.tablewidget_Results_Code2d->setRowCount(count);
	for (int i = 0; i < count; i++)
	{
		QTableWidgetItem *item;
		QString str;
		//��ά������
		str = QString::fromUtf8(resultStruct.hv_CodeType_Result[i].S().Text());
		item = new QTableWidgetItem(str, 1000);
		item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
		ui.tablewidget_Results_Code2d->setItem(i, 0, item);
		//��ά������
		str = QString::fromUtf8(resultStruct.hv_CodeContent[i].S().Text());
		item = new QTableWidgetItem(str, 1000);
		item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
		ui.tablewidget_Results_Code2d->setItem(i, 1, item);
		//��ά�볤��
		str = QString::number(resultStruct.hv_CodeLength_Result[i].I());
		item = new QTableWidgetItem(str, 1000);
		item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
		ui.tablewidget_Results_Code2d->setItem(i, 2, item);
		//X����
		str = QString::number(resultStruct.hv_Column[i].D(), 'f', 2);
		item = new QTableWidgetItem(str, 1000);
		item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
		ui.tablewidget_Results_Code2d->setItem(i, 3, item);
		//Y����
		str = QString::number(resultStruct.hv_Row[i].D(), 'f', 2);
		item = new QTableWidgetItem(str, 1000);
		item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
		ui.tablewidget_Results_Code2d->setItem(i, 4, item);
	}
}
//���¶�ά�������в���������
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

//�����ά�������
void QRCodeWindow::on_btn_SaveCode2dData_clicked()
{
	int ret = 1;
	//���ö�ά�����в���
	SetRunParams_Code2d(hv_RunParamsCode2d);
	//�����ά�����в���
	ret = dataIOC.WriteParams_Code2d(configPath, XMLPath, hv_RunParamsCode2d, processID, nodeName, processModbuleID);
	if (ret != 0)
	{
		QMessageBox::information(this, "��ʾ", "��������ʧ��", QMessageBox::Ok);
		return;
	}
}
//��ȡ��ά�������
void QRCodeWindow::on_btn_LoadCode2dData_clicked()
{
	ErrorCode_Xml errorCode;
	//������Ҫ���
	hv_RunParamsCode2d.hv_CodeType_Run.Clear();
	//��ȡ��ά�����
	errorCode = dataIOC.ReadParams_Code2d(configPath, XMLPath, hv_RunParamsCode2d, processID, nodeName, processModbuleID);
	if (errorCode != Ok_Xml)
	{
		QMessageBox::information(this, "��ʾ", "������ȡʧ��", QMessageBox::Ok);
		return;
	}
	//�������µ�����
	UpdateCode2dDataWindow(hv_RunParamsCode2d);
}
//���ƶ�ά����������
void QRCodeWindow::on_btn_DrawRoi_Code2d_clicked()
{
	if (ho_Image.Key() == nullptr)
	{
		//ͼ��Ϊ�գ�����ͼ��clear
		QMessageBox::information(this, "��ʾ", "ͼ���ǿգ����ȼ���ͼ��!", QMessageBox::Ok);
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
	//������ˢ��ͼ�񴫵ݲ���(��Ҫ������Ϊ�˹�������ʱ��ʾͼ��)
	GiveParameterToWindow();
	DispObj(TempRoi, m_hHalconID);

}
//���ROI
void QRCodeWindow::on_btn_ClearRoi_Code2d_clicked()
{
	ho_Code2dRegions.clear();
	GenEmptyObj(&SearchRoi_Code2d);
	GenEmptyObj(&ho_ShowObj);
	//������ˢ��ͼ�񴫵ݲ���(��Ҫ������Ϊ�˹�������ʱ��ʾͼ��)
	GiveParameterToWindow();
	showImg(ho_Image, "margin", "green");
}
//��ʼ����ά������ʾ���
void QRCodeWindow::IniTableData_Code2d()
{
	QTableWidgetItem   *hearderItem;
	QStringList hearderText;
	hearderText << "��������" << "��������" << "���볤��" << "X����" << "Y����";
	ui.tablewidget_Results_Code2d->setColumnCount(hearderText.count());
	for (int i = 0; i < ui.tablewidget_Results_Code2d->columnCount(); i++)
	{
		hearderItem = new QTableWidgetItem(hearderText.at(i));
		QFont font = hearderItem->font();
		font.setBold(true);//����Ϊ����
		font.setPointSize(12);//���������С
		hearderItem->setTextColor(Qt::red);//������ɫ
		hearderItem->setFont(font);//��������
		ui.tablewidget_Results_Code2d->setHorizontalHeaderItem(i, hearderItem);
	}
}
//��ά����ۺ���
void QRCodeWindow::on_btn_FindCode2d_clicked()
{
	if (ho_Image.Key() == nullptr)
	{
		//ͼ��Ϊ�գ�����ͼ��clear
		QMessageBox::information(this, "��ʾ", "ͼ���ǿգ����ȼ���ͼ��!", QMessageBox::Ok);
		return;
	}
	int ret = 1;
	//ʶ���ά��
	ResultParamsStruct_Code2d resultParams;
	QDateTime startTime = QDateTime::currentDateTime();
	ret = slot_FindCode2d(resultParams);
	QDateTime endTime = QDateTime::currentDateTime();
	qint64 intervalTimeMS = startTime.msecsTo(endTime);

	//ˢ�½��
	SetTableData_Code2d(resultParams, intervalTimeMS);
}
//����ά��ۺ���
int QRCodeWindow::slot_FindCode2d(ResultParamsStruct_Code2d &resultParams)
{
	try
	{
		int ret = 1;
		//XML��ȡ����
		hv_RunParamsCode2d.hv_CodeType_Run.Clear();
		ErrorCode_Xml errorCode = dataIOC.ReadParams_Code2d(configPath, XMLPath, hv_RunParamsCode2d, processID, nodeName, processModbuleID);
		if (errorCode != Ok_Xml)
		{
			//XML��ȡʧ�ܣ���Ĭ��ֵ
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
			//�����ά�����в���
			ret = dataIOC.WriteParams_Code2d(configPath, XMLPath, hv_RunParamsCode2d, processID, nodeName, processModbuleID);
			if (ret != 0)
			{
				return ret;
			}
		}
		//�����㷨
		return code2dParams1->FindCode2dFunc(ho_Image, hv_RunParamsCode2d, resultParams);
	}
	catch (...)
	{
		return -1;
	}
}
