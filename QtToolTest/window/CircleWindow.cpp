#include "CircleWindow.h"

CircleWindow::CircleWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowMinimizeButtonHint);
	//���ڳ�ʼ��
	InitWindow();

	//Բ���
	IniTableData_Circle();
	IniCircleClassObject();

	//�����Զ���ͼ
	QString Filepath = QCoreApplication::applicationDirPath() + "/01.png";
	ReadImage(&ho_Image, HTuple(Filepath.toStdString().c_str()));

	//�����ļ���XML·��
	configPath = FolderPath() + "/Config/";
	XMLPath = FolderPath() + "/Config/Config.xml";
}

CircleWindow::CircleWindow(HObject image, int _processID, int modubleID, std::string _modubleName, std::string configPath) {
	ui.setupUi(this);
	nodeName = _modubleName;
	processModbuleID = modubleID;
	processID = _processID;
	XMLPath = configPath + "\\config.xml";
	this->configPath = configPath + "/";
	InitWindow();
	IniTableData_Circle();
	IniCircleClassObject();
	ho_Image = image;
	showImg(ho_Image, "margin", "green");
}

CircleWindow::~CircleWindow()
{
	//�ͷ�Բnew���ڴ�
	delete CircleDetect1;
}
//�رմ���
void CircleWindow::on_btn_Hide_clicked()
{
	this->hide();
}
//��ʼ����ʾ����
void CircleWindow::InitWindow()
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
	GenEmptyObj(&ho_ShowObj);
	ho_Image.Clear();
	m_hHalconID = NULL;
	m_hLabelID = (Hlong)ui.lbl_Window->winId();

}

//��ʾͼ��
void CircleWindow::showImg(const HObject &ho_Img, HTuple hv_FillType, HTuple hv_Color)
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
void CircleWindow::GiveParameterToWindow()
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
void CircleWindow::on_pBtn_ReadImage_clicked()
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
void CircleWindow::on_pBtn_FitImage_clicked()
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
void CircleWindow::on_ckb_ShowObj_stateChanged(int arg1)
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
void CircleWindow::on_btn_ClearWindow_clicked()
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
//*****************Բ�����ش���**********************************************************************
//����Բ
void CircleWindow::on_btn_DrawCircle_Circle_clicked()
{
	if (ho_Image.Key() == nullptr)
	{
		//ͼ��Ϊ�գ�����ͼ��clear
		QMessageBox::information(this, "��ʾ", "ͼ���ǿգ����ȼ���ͼ��!", QMessageBox::Ok);
		return;
	}
	SetColor(m_hHalconID, "red");
	SetLineWidth(m_hHalconID, 1);

	HObject ho_XldCircle;
	HTuple CircleRow, CircleCol, CircleRadius;
	DrawCircle(m_hHalconID, &CircleRow, &CircleCol, &CircleRadius);
	GenCircle(&ho_XldCircle, CircleRow, CircleCol, CircleRadius);
	ConcatObj(ho_ShowObj, ho_XldCircle, &ho_ShowObj);
	//������ˢ��ͼ�񴫵ݲ���(��Ҫ������Ϊ�˹�������ʱ��ʾͼ��)
	GiveParameterToWindow();
	DispObj(ho_XldCircle, m_hHalconID);

	//����������
	ShowArrow_Circle(m_hHalconID, CircleRow, CircleCol, CircleRadius);
	//����Բ������ֵ
	ui.dspb_CenterRow_Circle->setValue(CircleRow.TupleReal().D());
	ui.dspb_CenterCol_Circle->setValue(CircleCol.TupleReal().D());
	ui.dspb_CenterRadius_Circle->setValue(CircleRadius.TupleReal().D());
	//������Բ����
	SetRunParams_Circle(hv_RunParamsCircle);
	//����Բ���в���
	dataIOC.WriteParams_Circle(configPath, XMLPath, hv_RunParamsCircle, processID, nodeName, processModbuleID);
}
//���ԲROI
void CircleWindow::on_btn_ClearRoi_Circle_clicked()
{
	//��մ�����ʾ��ͼ�α���
	GenEmptyObj(&ho_ShowObj);
	//��ʾԭͼ
	showImg(ho_Image, "margin", "green");
}
//���Ƽ�ͷ
void CircleWindow::ShowArrow_Circle(HTuple windowId, HTuple CircleRow, HTuple CircleCol, HTuple CircleRadius)
{
	//��ʾ������������
	//��ͷ����ʼ������(���㷽ʽ����Բ��Ϊ��㣬�յ��������Բ��������ϰ뾶�������)
	HTuple hv_ArrowRow1, hv_ArrowCol1, hv_ArrowRow2, hv_ArrowCol2;
	hv_ArrowRow1 = CircleRow;
	hv_ArrowCol1 = CircleCol;
	hv_ArrowRow2 = CircleRow - CircleRadius - 50;
	hv_ArrowCol2 = CircleCol;

	//��ʾ��������
	SetColor(m_hHalconID, "green");
	DispArrow(windowId, hv_ArrowRow1, hv_ArrowCol1, hv_ArrowRow2, hv_ArrowCol2, 5);
}
//Բ������ʼ��
void CircleWindow::IniCircleClassObject()
{
	CircleDetect1 = new CircleDetect(nodeName, processModbuleID, processID, XMLPath);
}
//���в���Բ�ṹ�������ֵ����
void CircleWindow::SetRunParams_Circle(RunParamsStruct_Circle &runParams)
{
	//ץԲroi��ʼ��
	runParams.hv_Row = ui.dspb_CenterRow_Circle->value();
	runParams.hv_Column = ui.dspb_CenterCol_Circle->value();
	runParams.hv_Radius = ui.dspb_CenterRadius_Circle->value();

	//ץԲģ����Ҫ��ץԲ����
	runParams.hv_MeasureLength1 = ui.spb_MeasureLength1_Circle->value();		//���߰볤
	runParams.hv_MeasureLength2 = ui.spb_MeasureLength2_Circle->value();		//���߰��
	runParams.hv_MeasureSigma = ui.dspb_MeasureSigma_Circle->value();		//ƽ��ֵ 
	runParams.hv_MeasureThreshold = ui.spb_MeasureThreshold_Circle->value();	//��Ե��ֵ
	runParams.hv_MeasureTransition = HTuple(ui.cmb_MeasureTransition_Circle->currentText().toStdString().c_str());	//���߼���
	runParams.hv_MeasureSelect = HTuple(ui.cmb_MeasureSelect_Circle->currentText().toStdString().c_str());		//��Եѡ��
	runParams.hv_MeasureNum = ui.spb_MeasureNum_Circle->value();		    //���߸���
	runParams.hv_InstancesNum = 1;		//ץԲ����
	runParams.hv_MeasureMinScore = ui.dspb_MinScore_Circle->value();     //��С�÷�
	runParams.hv_DistanceThreshold = ui.dspb_DistanceThreshold_Circle->value();   //������ֵ
	runParams.hv_MeasureInterpolation = HTuple(ui.cmb_MeasureInterpolation_Circle->currentText().toStdString().c_str());//��ֵ�㷨



	if (ui.cmb_IsFollow_Circle->currentText() == "Yes")
	{
		runParams.isFollow = true;
	}
	else
	{
		runParams.isFollow = false;
	}

}
//���Բ
void CircleWindow::on_btn_DetectCircle_Circle_clicked()
{
	if (ho_Image.Key() == nullptr)
	{
		//ͼ��Ϊ�գ�����ͼ��clear
		QMessageBox::information(this, "��ʾ", "ͼ���ǿգ����ȼ���ͼ��!", QMessageBox::Ok);
		return;
	}

	//��Բ����
	QDateTime startTime = QDateTime::currentDateTime();
	ResultParamsStruct_Circle resultParams;
	slot_FindCircle(resultParams);
	QDateTime endTime = QDateTime::currentDateTime();
	qint64 intervalTimeMS = startTime.msecsTo(endTime);
	//ˢ�½��
	SetTableData_Circle(resultParams, intervalTimeMS);
}
//��ʼ��Բ�����ʾ���
void CircleWindow::IniTableData_Circle()
{
	QTableWidgetItem   *hearderItem;
	QStringList hearderText;
	hearderText << "X" << "Y";
	ui.tablewidget_PointsResult_Circle->setColumnCount(hearderText.count());
	for (int i = 0; i < ui.tablewidget_PointsResult_Circle->columnCount(); i++)
	{
		hearderItem = new QTableWidgetItem(hearderText.at(i));
		QFont font = hearderItem->font();
		font.setBold(true);//����Ϊ����
		font.setPointSize(12);//���������С
		hearderItem->setTextColor(Qt::red);//������ɫ
		hearderItem->setFont(font);//��������
		ui.tablewidget_PointsResult_Circle->setHorizontalHeaderItem(i, hearderItem);
	}
}
//����Բ�����ʾ�������
void CircleWindow::SetTableData_Circle(const ResultParamsStruct_Circle &resultParams, qint64 Ct)
{
	//��ս���������
	ui.tablewidget_PointsResult_Circle->clearContents();
	//�ж��Ƿ��ҵ�Բ
	if (resultParams.hv_RetNum == 0)
	{
		//û���ҵ�Բ���˳�
		GenEmptyObj(&ho_ShowObj);
		showImg(ho_Image, "margin", "green");
		return;
	}
	//ˢ��ͼ��
	GenEmptyObj(&ho_ShowObj);
	ConcatObj(ho_ShowObj, resultParams.ho_Contour_Circle, &ho_ShowObj);
	ConcatObj(ho_ShowObj, resultParams.ho_Contour_Calipers, &ho_ShowObj);
	ConcatObj(ho_ShowObj, resultParams.ho_Contour_CrossPoints, &ho_ShowObj);
	showImg(ho_Image, "margin", "green");
	//ˢ��ʱ��
	ui.lbl_RunCircleCT->setText("CT:" + QString::number(Ct) + "ms");
	//ˢ�¿����ҵ������е�����
	int count = resultParams.hv_PointsNum.I();
	ui.tablewidget_PointsResult_Circle->setRowCount(count);
	for (int i = 0; i < count; i++)
	{
		QTableWidgetItem *item;
		QString str;
		double d = resultParams.hv_PointsColumn[0].D();
		//X
		str = QString::number(resultParams.hv_PointsColumn[i].D(), 'f', 2);
		item = new QTableWidgetItem(str, 1000);
		item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
		ui.tablewidget_PointsResult_Circle->setItem(i, 0, item);
		//Y
		str = QString::number(resultParams.hv_PointsRow[i].D(), 'f', 2);
		item = new QTableWidgetItem(str, 1000);
		item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
		ui.tablewidget_PointsResult_Circle->setItem(i, 1, item);

	}
	//ˢ��Բ������Ͱ뾶
	ui.txt_Row1_Circle->setText(QString::number(resultParams.hv_CircleRowCenter.D(), 'f', 2));
	ui.txt_Col1_Circle->setText(QString::number(resultParams.hv_CircleColumnCenter.D(), 'f', 2));
	ui.txt_Radius_Circle->setText(QString::number(resultParams.hv_CircleRadius.D(), 'f', 2));
}
//Բ��������
void CircleWindow::on_btn_SaveCircleData_clicked()
{
	int ret = 1;
	//������Բ����
	SetRunParams_Circle(hv_RunParamsCircle);
	//����Բ���в���
	ret = dataIOC.WriteParams_Circle(configPath, XMLPath, hv_RunParamsCircle, processID, nodeName, processModbuleID);
	if (ret != 0)
	{
		QMessageBox::information(this, "��ʾ", "��������ʧ��", QMessageBox::Ok);
		return;
	}
}
//Բ������ȡ
void CircleWindow::on_btn_LoadCircleData_clicked()
{
	ErrorCode_Xml errorCode;
	//��ȡԲ����
	errorCode = dataIOC.ReadParams_Circle(configPath, XMLPath, hv_RunParamsCircle, processID, nodeName, processModbuleID);
	if (errorCode != Ok_Xml)
	{
		QMessageBox::information(this, "��ʾ", "������ȡʧ��", QMessageBox::Ok);
		return;
	}
	//�������µ�����
	UpdateCircleDataWindow(hv_RunParamsCircle);
}
//����Բ������в���������
void CircleWindow::UpdateCircleDataWindow(const RunParamsStruct_Circle &RunParams)
{
	//ץԲroi��ʼ��
	ui.dspb_CenterRow_Circle->setValue(RunParams.hv_Row.TupleReal().D());
	ui.dspb_CenterCol_Circle->setValue(RunParams.hv_Column.TupleReal().D());
	ui.dspb_CenterRadius_Circle->setValue(RunParams.hv_Radius.TupleReal().D());
	//ץԲģ����Ҫ��ץ�߲���
	ui.spb_MeasureLength1_Circle->setValue(RunParams.hv_MeasureLength1.TupleInt().I());		//���߰볤
	ui.spb_MeasureLength2_Circle->setValue(RunParams.hv_MeasureLength2.TupleInt().I());		//���߰��
	ui.dspb_MeasureSigma_Circle->setValue(RunParams.hv_MeasureSigma.TupleReal().D());		//ƽ��ֵ 
	ui.spb_MeasureThreshold_Circle->setValue(RunParams.hv_MeasureThreshold.TupleInt().I());	//��Ե��ֵ
	ui.cmb_MeasureTransition_Circle->setCurrentText(QString::fromUtf8(RunParams.hv_MeasureTransition.S().Text()));	//���߼���
	ui.cmb_MeasureSelect_Circle->setCurrentText(QString::fromUtf8(RunParams.hv_MeasureSelect.S().Text()));		//��Եѡ��
	ui.spb_MeasureNum_Circle->setValue(RunParams.hv_MeasureNum.TupleInt().I());		    //���߸���
	ui.dspb_MinScore_Circle->setValue(RunParams.hv_MeasureMinScore.TupleReal().D());     //��С�÷�
	ui.dspb_DistanceThreshold_Circle->setValue(RunParams.hv_DistanceThreshold.TupleReal().D());   //������ֵ
	ui.cmb_MeasureInterpolation_Circle->setCurrentText(QString::fromUtf8(RunParams.hv_MeasureInterpolation.S().Text()));//��ֵ�㷨
	if (RunParams.isFollow)
	{
		ui.cmb_IsFollow_Circle->setCurrentText("Yes");
	}
	else
	{
		ui.cmb_IsFollow_Circle->setCurrentText("No");
	}
}
//���Բ�ۺ���
int CircleWindow::slot_FindCircle(ResultParamsStruct_Circle &resultParams)
{
	try
	{
		int ret = 1;
		//XML��ȡ����
		ErrorCode_Xml errorCode = dataIOC.ReadParams_Circle(configPath, XMLPath, hv_RunParamsCircle, processID, nodeName, processModbuleID);
		if (errorCode != Ok_Xml)
		{
			//XML��ȡʧ�ܣ���Ĭ��ֵ
			hv_RunParamsCircle.hv_Row = 50;
			hv_RunParamsCircle.hv_Column = 50;
			hv_RunParamsCircle.hv_Radius = 50;
			//ץ��ģ����Ҫ��ץ�߲���
			hv_RunParamsCircle.hv_MeasureLength1 = 50;
			hv_RunParamsCircle.hv_MeasureLength2 = 5;
			hv_RunParamsCircle.hv_MeasureSigma = 1.0;
			hv_RunParamsCircle.hv_MeasureThreshold = 20;
			hv_RunParamsCircle.hv_MeasureTransition = "all";
			hv_RunParamsCircle.hv_MeasureSelect = "first";
			hv_RunParamsCircle.hv_MeasureNum = 10;
			hv_RunParamsCircle.hv_InstancesNum = 1;
			hv_RunParamsCircle.hv_MeasureMinScore = 0.5;
			hv_RunParamsCircle.hv_DistanceThreshold = 3.5;
			hv_RunParamsCircle.hv_MeasureInterpolation = "nearest_neighbor";
			hv_RunParamsCircle.isFollow = false;
			//����ֱ�߼�����в���
			ret = dataIOC.WriteParams_Circle(configPath, XMLPath, hv_RunParamsCircle, processID, nodeName, processModbuleID);
			if (ret != 0)
			{
				return ret;
			}
		}
		//�����㷨
		return CircleDetect1->FindCircle(ho_Image, hv_RunParamsCircle, resultParams);
	}
	catch (...)
	{
		return -1;
	}
}
//exe·��
string CircleWindow::FolderPath()
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
string CircleWindow::strReplaceAll(const string& strResource, const string& strOld, const string& strNew)
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
//****************************************************************************************************