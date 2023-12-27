#include "EllipseWindow.h"

EllipseWindow::EllipseWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowMinimizeButtonHint);
	//���ڳ�ʼ��
	InitWindow();
	//��Բ���
	IniTableData_Ellipse();
	EllipseDetect1 = new EllipseDetect();

	//�����Զ���ͼ
	QString Filepath = QCoreApplication::applicationDirPath() + "/01.png";
	ReadImage(&ho_Image, HTuple(Filepath.toStdString().c_str()));

	//�����ļ���XML·��
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

	//���ڳ�ʼ��
	InitWindow();
	//��Բ���
	IniTableData_Ellipse();
	EllipseDetect1 = new EllipseDetect(nodeName, processModbuleID, processID, XMLPath);

	ho_Image = image;
	showImg(ho_Image, "margin", "green");
}
EllipseWindow::~EllipseWindow()
{
	delete EllipseDetect1;
}
//�رմ���
void EllipseWindow::on_btn_Hide_clicked()
{
	this->hide();
}
//��ʼ����ʾ����
void EllipseWindow::InitWindow()
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
void EllipseWindow::showImg(const HObject &ho_Img, HTuple hv_FillType, HTuple hv_Color)
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
void EllipseWindow::GiveParameterToWindow()
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

//ͼ������Ӧ����
void EllipseWindow::on_pBtn_FitImage_clicked()
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
	//������ˢ��ͼ�񴫵ݲ���(��Ҫ������Ϊ�˹�������ʱ��ʾͼ��)
	GiveParameterToWindow();
}
//��մ���
void EllipseWindow::on_btn_ClearWindow_clicked()
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
//****************************************************************************************************
//****************��Բ�����غ���***********************
//��ʼ����Բ�����ʾ����
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
		font.setBold(true);//����Ϊ����
		font.setPointSize(12);//���������С
		hearderItem->setTextColor(Qt::red);//������ɫ
		hearderItem->setFont(font);//��������
		ui.tablewidget_PointsResult_Ellipse->setHorizontalHeaderItem(i, hearderItem);
	}
}
//������Բ
void EllipseWindow::on_btn_DrawEllipse_Ellipse_clicked()
{
	if (ho_Image.Key() == nullptr)
	{
		//ͼ��Ϊ�գ�����ͼ��clear
		QMessageBox::information(this, "��ʾ", "ͼ���ǿգ����ȼ���ͼ��!", QMessageBox::Ok);
		return;
	}
	SetColor(m_hHalconID, "red");
	SetLineWidth(m_hHalconID, 1);

	HObject ho_XldEllipse;
	HTuple Row, Col, Angle, Radius1, Radius2;
	DrawEllipse(m_hHalconID, &Row, &Col, &Angle, &Radius1, &Radius2);
	GenEllipseContourXld(&ho_XldEllipse, Row, Col, Angle, Radius1, Radius2, 0, HTuple(360).TupleRad(), "positive", 1.5);

	//������Բ������ֵ
	ui.dspb_CenterRow_Ellipse->setValue(Row.TupleReal().D());
	ui.dspb_CenterCol_Ellipse->setValue(Col.TupleReal().D());
	ui.dspb_Angle_Ellipse->setValue(Angle.TupleDeg().TupleReal().D());
	ui.dspb_Radius1_Ellipse->setValue(Radius1.TupleReal().D());
	ui.dspb_Radius2_Ellipse->setValue(Radius2.TupleReal().D());

	ConcatObj(ho_ShowObj, ho_XldEllipse, &ho_ShowObj);
	//������ˢ��ͼ�񴫵ݲ���(��Ҫ������Ϊ�˹�������ʱ��ʾͼ��)
	GiveParameterToWindow();
	SetColor(m_hHalconID, "green");
	DispObj(ho_XldEllipse, m_hHalconID);

	//����������
	//��ͷ����ʼ������(���㷽ʽ���Ի��Ƶľ��ΰ볤Ϊб�ߣ��Ի��Ƶľ��νǶ�Ϊ�Ƕȡ��ֱ����б�ߵ�cosֵ��x,��col������б�ߵ�sinֵ��y����row)
	HTuple measureLength1 = HTuple(ui.spb_MeasureLength1_Ellipse->value());
	HTuple hv_Cos, hv_Sin, hv_ArrowRow1, hv_ArrowCol1, hv_ArrowRow2, hv_ArrowCol2;
	TupleCos(Angle, &hv_Cos);
	TupleSin(Angle, &hv_Sin);
	hv_ArrowRow1 = Row;
	hv_ArrowCol1 = Col;
	hv_ArrowRow2 = Row + 2 * Radius1 * hv_Cos;
	hv_ArrowCol2 = Col + 2 * Radius1 * hv_Sin;

	//��ʾ��������
	SetColor(m_hHalconID, "red");
	DispArrow(m_hHalconID, hv_ArrowRow1, hv_ArrowCol1, hv_ArrowRow2, hv_ArrowCol2, 5);
}
//�����Բ
void EllipseWindow::on_btn_DetectEllipse_Ellipse_clicked()
{
	if (ho_Image.Key() == nullptr)
	{
		//ͼ��Ϊ�գ�����ͼ��clear
		QMessageBox::information(this, "��ʾ", "ͼ���ǿգ����ȼ���ͼ��!", QMessageBox::Ok);
		return;
	}
	int ret = 1;
	//����Բ����
	QDateTime startTime = QDateTime::currentDateTime();
	ResultParamsStruct_Ellipse resultParams;
	ret = slot_FindEllipse(resultParams);
	QDateTime endTime = QDateTime::currentDateTime();
	qint64 intervalTimeMS = startTime.msecsTo(endTime);
	//ˢ�½��
	SetTableData_Ellipse(resultParams, intervalTimeMS);
}
//������Բ����
void EllipseWindow::on_btn_SaveData_Ellipse_clicked()
{
	int ret = 1;
	//����ץ��Բ����
	SetRunParams_Ellipse(hv_RunParamsEllipse);
	//������Բ���в���
	ret = dataIOC.WriteParams_Ellipse(configPath, XMLPath, hv_RunParamsEllipse, processID, nodeName, processModbuleID);
	if (ret != 0)
	{
		QMessageBox::information(this, "��ʾ", "��������ʧ��", QMessageBox::Ok);
		return;
	}
}
//������Բ����
void EllipseWindow::on_btn_LoadData_Ellipse_clicked()
{
	ErrorCode_Xml errorCode;
	//��ȡ��Բ����
	errorCode = dataIOC.ReadParams_Ellipse(configPath, XMLPath, hv_RunParamsEllipse, processID, nodeName, processModbuleID);
	if (errorCode != Ok_Xml)
	{
		QMessageBox::information(this, "��ʾ", "������ȡʧ��", QMessageBox::Ok);
		return;
	}
	//�������µ�����
	UpdateEllipseDataWindow(hv_RunParamsEllipse);
}
//���ROI
void EllipseWindow::on_btn_ClearRoi_Ellipse_clicked()
{
	//��մ�����ʾ��ͼ�α���
	GenEmptyObj(&ho_ShowObj);
	//��ʾԭͼ
	showImg(ho_Image, "margin", "green");
}
//������Բ������в���������
void EllipseWindow::UpdateEllipseDataWindow(const RunParamsStruct_Ellipse &RunParams)
{
	//ֱ��ץ��roi��ʼ��
	ui.dspb_CenterRow_Ellipse->setValue(RunParams.hv_Row.TupleReal().D());
	ui.dspb_CenterCol_Ellipse->setValue(RunParams.hv_Column.TupleReal().D());
	ui.dspb_Angle_Ellipse->setValue(RunParams.hv_Angle.TupleReal().D());
	ui.dspb_Radius1_Ellipse->setValue(RunParams.hv_Radius1.TupleReal().D());
	ui.dspb_Radius2_Ellipse->setValue(RunParams.hv_Radius2.TupleReal().D());

	//ץ��ģ����Ҫ��ץ�߲���
	ui.spb_MeasureLength1_Ellipse->setValue(RunParams.hv_MeasureLength1.TupleInt().I());		//���߰볤
	ui.spb_MeasureLength2_Ellipse->setValue(RunParams.hv_MeasureLength2.TupleInt().I());		//���߰��
	ui.dspb_MeasureSigma_Ellipse->setValue(RunParams.hv_MeasureSigma.TupleReal().D());		//ƽ��ֵ 
	ui.spb_MeasureThreshold_Ellipse->setValue(RunParams.hv_MeasureThreshold);	//��Ե��ֵ
	ui.cmb_MeasureTransition_Ellipse->setCurrentText(QString::fromUtf8(RunParams.hv_MeasureTransition.S().Text()));	//���߼���
	ui.cmb_MeasureSelect_Ellipse->setCurrentText(QString::fromUtf8(RunParams.hv_MeasureSelect.S().Text()));		//��Եѡ��
	ui.spb_MeasureNum_Ellipse->setValue(RunParams.hv_MeasureNum.TupleInt().I());		    //���߸���
	ui.dspb_MinScore_Ellipse->setValue(RunParams.hv_MeasureMinScore.TupleReal().D());     //��С�÷�
	ui.dspb_DistanceThreshold_Ellipse->setValue(RunParams.hv_DistanceThreshold.TupleReal().D());   //������ֵ
	ui.cmb_MeasureInterpolation_Ellipse->setCurrentText(QString::fromUtf8(RunParams.hv_MeasureInterpolation.S().Text()));//��ֵ�㷨
	if (RunParams.isFollow)
	{
		ui.cmb_IsFollow_Ellipse->setCurrentText("Yes");
	}
	else
	{
		ui.cmb_IsFollow_Ellipse->setCurrentText("No");
	}
}
//���в�����Բ�ṹ�������ֵ����
void EllipseWindow::SetRunParams_Ellipse(RunParamsStruct_Ellipse &RunParams)
{
	//roi��ʼ��
	RunParams.hv_Row = ui.dspb_CenterRow_Ellipse->value();
	RunParams.hv_Column = ui.dspb_CenterCol_Ellipse->value();
	RunParams.hv_Angle = ui.dspb_Angle_Ellipse->value();
	RunParams.hv_Radius1 = ui.dspb_Radius1_Ellipse->value();
	RunParams.hv_Radius2 = ui.dspb_Radius2_Ellipse->value();

	//ģ����Ҫ�Ĳ���
	RunParams.hv_MeasureLength1 = ui.spb_MeasureLength1_Ellipse->value();		//���߰볤
	RunParams.hv_MeasureLength2 = ui.spb_MeasureLength2_Ellipse->value();		//���߰��
	RunParams.hv_MeasureSigma = ui.dspb_MeasureSigma_Ellipse->value();		//ƽ��ֵ 
	RunParams.hv_MeasureThreshold = ui.spb_MeasureThreshold_Ellipse->value();	//��Ե��ֵ
	RunParams.hv_MeasureTransition = HTuple(ui.cmb_MeasureTransition_Ellipse->currentText().toStdString().c_str());	//���߼���
	RunParams.hv_MeasureSelect = HTuple(ui.cmb_MeasureSelect_Ellipse->currentText().toStdString().c_str());		//��Եѡ��
	RunParams.hv_MeasureNum = ui.spb_MeasureNum_Ellipse->value();		    //���߸���
	RunParams.hv_InstancesNum = 1;		//����
	RunParams.hv_MeasureMinScore = ui.dspb_MinScore_Ellipse->value();     //��С�÷�
	RunParams.hv_DistanceThreshold = ui.dspb_DistanceThreshold_Ellipse->value();   //������ֵ
	RunParams.hv_MeasureInterpolation = HTuple(ui.cmb_MeasureInterpolation_Ellipse->currentText().toStdString().c_str());//��ֵ�㷨

	if (ui.cmb_IsFollow_Ellipse->currentText() == "Yes")
	{
		RunParams.isFollow = true;
	}
	else
	{
		RunParams.isFollow = false;
	}
}
//������Բ�����ʾ��������
void EllipseWindow::SetTableData_Ellipse(const ResultParamsStruct_Ellipse &resultParams, qint64 Ct)
{
	//��ս����������
	ui.tablewidget_PointsResult_Ellipse->clearContents();
	//�ж��Ƿ��ҵ���Բ
	if (resultParams.hv_RetNum == 0)
	{
		//û���ҵ����˳�
		GenEmptyObj(&ho_ShowObj);
		showImg(ho_Image, "margin", "green");
		return;
	}
	//ˢ��ͼ��
	GenEmptyObj(&ho_ShowObj);
	ConcatObj(ho_ShowObj, resultParams.ho_Contour_Ellipse, &ho_ShowObj);
	ConcatObj(ho_ShowObj, resultParams.ho_Contour_Calipers, &ho_ShowObj);
	ConcatObj(ho_ShowObj, resultParams.ho_Contour_CrossPoints, &ho_ShowObj);
	showImg(ho_Image, "margin", "green");
	//ˢ��ʱ��
	ui.lbl_RunCT_Ellipse->setText("CT:" + QString::number(Ct) + "ms");
	//ˢ�¿����ҵ������е�����
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
	//ˢ����Բ�������
	ui.txt_Col_Ellipse->setText(QString::number(resultParams.hv_EllipseColumn.D(), 'f', 2));
	ui.txt_Row_Ellipse->setText(QString::number(resultParams.hv_EllipseRow.D(), 'f', 2));
	ui.txt_Angle_Ellipse->setText(QString::number(resultParams.hv_EllipseAngle.D(), 'f', 2));
	ui.txt_Radius1_Ellipse->setText(QString::number(resultParams.hv_EllipseRadius1.D(), 'f', 2));
	ui.txt_Radius2_Ellipse->setText(QString::number(resultParams.hv_EllipseRadius2.D(), 'f', 2));
}
//�����Բ�ۺ���
int EllipseWindow::slot_FindEllipse(ResultParamsStruct_Ellipse &resultParams)
{
	try
	{
		int ret = 1;
		//XML��ȡ����
		ErrorCode_Xml errorCode = dataIOC.ReadParams_Ellipse(configPath, XMLPath, hv_RunParamsEllipse, processID, nodeName, processModbuleID);
		if (errorCode != Ok_Xml)
		{
			//XML��ȡʧ�ܣ���Ĭ��ֵ
			hv_RunParamsEllipse.hv_Row = 10;
			hv_RunParamsEllipse.hv_Column = 10;
			hv_RunParamsEllipse.hv_Angle = 0;
			hv_RunParamsEllipse.hv_Radius1 = 50;
			hv_RunParamsEllipse.hv_Radius2 = 25;

			//ץ��Բģ����Ҫ��ץ�߲���
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
			//������Բ������в���
			ret = dataIOC.WriteParams_Ellipse(configPath, XMLPath, hv_RunParamsEllipse, processID, nodeName, processModbuleID);
			if (ret != 0)
			{
				return ret;
			}
		}
		//�����㷨
		return EllipseDetect1->FindEllipse(ho_Image, hv_RunParamsEllipse, resultParams);
	}
	catch (...)
	{
		return -1;
	}
}
//exe·��
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
//����һ������strOld
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