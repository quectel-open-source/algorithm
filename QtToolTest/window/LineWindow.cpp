#include "LineWindow.h"

LineWindow::LineWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowMinimizeButtonHint);
	//���ڳ�ʼ��
	InitWindow();

	//ֱ�߼��
	IniTableData_Line();
	IniLineClassObject();

	//�����Զ���ͼ
	QString Filepath = QCoreApplication::applicationDirPath() + "/01.png";
	ReadImage(&ho_Image, HTuple(Filepath.toStdString().c_str()));

	//�����ļ���XML·��
	configPath = FolderPath() + "/Config/";
	XMLPath = FolderPath() + "/Config/Config.xml";
}

LineWindow::LineWindow(HObject image, int _processID, int modubleID, std::string _modubleName, std::string configPath) {
	ui.setupUi(this);


	nodeName = _modubleName;
	processModbuleID = modubleID;
	processID = _processID;
	XMLPath = configPath + "\\config.xml";
	this->configPath = configPath + "/";
	InitWindow();
	IniTableData_Line();
	IniLineClassObject();
	ho_Image = image;
	showImg(ho_Image, "margin", "green");

}

LineWindow::~LineWindow()
{
	//�ͷ�ֱ��new���ڴ�
	delete LineDetect1;
}

//�رմ���
void LineWindow::on_btn_Hide_clicked()
{
	this->hide();
}
//��ʼ����ʾ����
void LineWindow::InitWindow()
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
void LineWindow::showImg(const HObject &ho_Img, HTuple hv_FillType, HTuple hv_Color)
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
void LineWindow::GiveParameterToWindow()
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
void LineWindow::on_pBtn_ReadImage_clicked()
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
void LineWindow::on_pBtn_FitImage_clicked()
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
void LineWindow::on_ckb_ShowObj_stateChanged(int arg1)
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
void LineWindow::on_btn_ClearWindow_clicked()
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

//����ֱ��
void LineWindow::on_btn_DrawLine_Line_clicked()
{
	if (ho_Image.Key() == nullptr)
	{
		//ͼ��Ϊ�գ�����ͼ��clear
		QMessageBox::information(this, "��ʾ", "ͼ���ǿգ����ȼ���ͼ��!", QMessageBox::Ok);
		return;
	}
	SetColor(m_hHalconID, "red");
	SetLineWidth(m_hHalconID, 1);

	HObject ho_XldLine;
	HTuple LineRow1, LineCol1, LineRow2, LineCol2;
	DrawLine(m_hHalconID, &LineRow1, &LineCol1, &LineRow2, &LineCol2);
	HTuple hv_ConcatRow, hv_ConcatCol;
	TupleConcat(LineRow1, LineRow2, &hv_ConcatRow);
	TupleConcat(LineCol1, LineCol2, &hv_ConcatCol);
	GenContourPolygonXld(&ho_XldLine, hv_ConcatRow, hv_ConcatCol);
	ConcatObj(ho_ShowObj, ho_XldLine, &ho_ShowObj);
	//������ˢ��ͼ�񴫵ݲ���(��Ҫ������Ϊ�˹�������ʱ��ʾͼ��)
	GiveParameterToWindow();
	DispObj(ho_XldLine, m_hHalconID);

	//����������
	ShowArrow_Line(m_hHalconID, LineRow1, LineCol1, LineRow2, LineCol2);
	//����ֱ�߲�����ֵ
	ui.dspb_RowBegin_Line->setValue(LineRow1.TupleReal().D());
	ui.dspb_ColBegin_Line->setValue(LineCol1.TupleReal().D());
	ui.dspb_RowEnd_Line->setValue(LineRow2.TupleReal().D());
	ui.dspb_ColEnd_Line->setValue(LineCol2.TupleReal().D());
}
//���ֱ��ROI
void LineWindow::on_btn_ClearRoi_Line_clicked()
{
	//��մ�����ʾ��ͼ�α���
	GenEmptyObj(&ho_ShowObj);
	//��ʾԭͼ
	showImg(ho_Image, "margin", "green");
}
//���Ƽ�ͷ
void LineWindow::ShowArrow_Line(HTuple windowId, HTuple LineRow1, HTuple LineCol1, HTuple LineRow2, HTuple LineCol2)
{
	//��ʾ������������
	HTuple hv_AngleLine;
	AngleLx(LineRow1, LineCol1, LineRow2, LineCol2, &hv_AngleLine);
	//��ͷ����ʼ������(���㷽ʽ���Կ��߰볤Ϊб�ߣ��Ի��Ƶ�ֱ����ˮƽ��н�Ϊ�Ƕȡ��ֱ����б�ߵ�cosֵ��x,��col������б�ߵ�sinֵ��y����row)
	HTuple measureLength1 = HTuple(ui.spb_MeasureLength1_Line->value());
	HTuple hv_Cos, hv_Sin, hv_ArrowRow1, hv_ArrowCol1, hv_ArrowRow2, hv_ArrowCol2;
	TupleCos(hv_AngleLine, &hv_Cos);
	TupleSin(hv_AngleLine, &hv_Sin);
	hv_ArrowRow1 = (LineRow1 + LineRow2) / 2 - measureLength1 * hv_Cos;
	hv_ArrowCol1 = (LineCol1 + LineCol2) / 2 - measureLength1 * hv_Sin;
	hv_ArrowRow2 = (LineRow1 + LineRow2) / 2 + measureLength1 * hv_Cos;
	hv_ArrowCol2 = (LineCol1 + LineCol2) / 2 + measureLength1 * hv_Sin;

	//��ʾ��������
	SetColor(m_hHalconID, "green");
	DispArrow(windowId, hv_ArrowRow1, hv_ArrowCol1, hv_ArrowRow2, hv_ArrowCol2, 5);
	//��ʾֱ�߷���
	SetColor(m_hHalconID, "red");
	DispArrow(windowId, LineRow1, LineCol1, LineRow2, LineCol2, 5);
}
//ֱ��������ʼ��
void LineWindow::IniLineClassObject()
{
	LineDetect1 = new LineDetect(nodeName, processModbuleID, processID, XMLPath);
}
//���в���ֱ�߽ṹ�������ֵ����
void LineWindow::SetRunParams_Line(RunParamsStruct_Line &runParams)
{
	//ֱ��ץ��roi��ʼ��
	runParams.hv_Row1 = ui.dspb_RowBegin_Line->value();
	runParams.hv_Column1 = ui.dspb_ColBegin_Line->value();
	runParams.hv_Row2 = ui.dspb_RowEnd_Line->value();
	runParams.hv_Column2 = ui.dspb_ColEnd_Line->value();

	//ץ��ģ����Ҫ��ץ�߲���
	runParams.hv_MeasureLength1 = ui.spb_MeasureLength1_Line->value();		//���߰볤
	runParams.hv_MeasureLength2 = ui.spb_MeasureLength2_Line->value();		//���߰��
	runParams.hv_MeasureSigma = ui.dspb_MeasureSigma_Line->value();		//ƽ��ֵ 
	runParams.hv_MeasureThreshold = ui.spb_MeasureThreshold_Line->value();	//��Ե��ֵ
	runParams.hv_MeasureTransition = HTuple(ui.cmb_MeasureTransition_Line->currentText().toStdString().c_str());	//���߼���
	runParams.hv_MeasureSelect = HTuple(ui.cmb_MeasureSelect_Line->currentText().toStdString().c_str());		//��Եѡ��
	runParams.hv_MeasureNum = ui.spb_MeasureNum_Line->value();		    //���߸���
	runParams.hv_InstancesNum = 1;		//ץ������
	runParams.hv_MeasureMinScore = ui.dspb_MinScore_Line->value();     //��С�÷�
	runParams.hv_DistanceThreshold = ui.dspb_DistanceThreshold_Line->value();   //������ֵ
	runParams.hv_MeasureInterpolation = HTuple(ui.cmb_MeasureInterpolation_Line->currentText().toStdString().c_str());//��ֵ�㷨

	if (ui.cmb_IsFollow_Line->currentText() == "Yes")
	{
		runParams.isFollow = true;
	}
	else
	{
		runParams.isFollow = false;
	}
}
//���ֱ��
void LineWindow::on_btn_DetectLine_Line_clicked()
{
	if (ho_Image.Key() == nullptr)
	{
		//ͼ��Ϊ�գ�����ͼ��clear
		QMessageBox::information(this, "��ʾ", "ͼ���ǿգ����ȼ���ͼ��!", QMessageBox::Ok);
		return;
	}
	int ret = 1;
	//�ұ�����
	QDateTime startTime = QDateTime::currentDateTime();
	ResultParamsStruct_Line resultParams;
	ret = slot_FindLine(resultParams);
	QDateTime endTime = QDateTime::currentDateTime();
	qint64 intervalTimeMS = startTime.msecsTo(endTime);
	//ˢ�½��
	SetTableData_Line(resultParams, intervalTimeMS);
}
//��ʼ��ֱ�߽����ʾ���
void LineWindow::IniTableData_Line()
{
	QTableWidgetItem   *hearderItem;
	QStringList hearderText;
	hearderText << "X" << "Y";
	ui.tablewidget_PointsResult_Line->setColumnCount(hearderText.count());
	for (int i = 0; i < ui.tablewidget_PointsResult_Line->columnCount(); i++)
	{
		hearderItem = new QTableWidgetItem(hearderText.at(i));
		QFont font = hearderItem->font();
		font.setBold(true);//����Ϊ����
		font.setPointSize(12);//���������С
		hearderItem->setTextColor(Qt::red);//������ɫ
		hearderItem->setFont(font);//��������
		ui.tablewidget_PointsResult_Line->setHorizontalHeaderItem(i, hearderItem);
	}
}
//����ֱ�߽����ʾ�������
void LineWindow::SetTableData_Line(const ResultParamsStruct_Line &resultParams, qint64 Ct)
{
	//��ս���������
	ui.tablewidget_PointsResult_Line->clearContents();
	//�ж��Ƿ��ҵ�ֱ��
	if (resultParams.hv_RetNum == 0)
	{
		//û���ҵ�ֱ�ߣ��˳�
		GenEmptyObj(&ho_ShowObj);
		showImg(ho_Image, "margin", "green");
		return;
	}
	//ˢ��ͼ��
	GenEmptyObj(&ho_ShowObj);
	ConcatObj(ho_ShowObj, resultParams.ho_Contour_Line, &ho_ShowObj);
	ConcatObj(ho_ShowObj, resultParams.ho_Contour_Calipers, &ho_ShowObj);
	ConcatObj(ho_ShowObj, resultParams.ho_Contour_CrossPoints, &ho_ShowObj);
	showImg(ho_Image, "margin", "green");
	//ˢ��ʱ��
	ui.lbl_RunLineCT->setText("CT:" + QString::number(Ct) + "ms");
	//ˢ�¿����ҵ������е�����
	int count = resultParams.hv_PointsNum.I();
	ui.tablewidget_PointsResult_Line->setRowCount(count);
	for (int i = 0; i < count; i++)
	{
		QTableWidgetItem *item;
		QString str;
		double d = resultParams.hv_PointsColumn[0].D();
		//X
		str = QString::number(resultParams.hv_PointsColumn[i].D(), 'f', 2);
		item = new QTableWidgetItem(str, 1000);
		item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
		ui.tablewidget_PointsResult_Line->setItem(i, 0, item);
		//Y
		str = QString::number(resultParams.hv_PointsRow[i].D(), 'f', 2);
		item = new QTableWidgetItem(str, 1000);
		item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
		ui.tablewidget_PointsResult_Line->setItem(i, 1, item);

	}
	//ˢ��ֱ����ʼ����
	ui.txt_Row1_Line->setText(QString::number(resultParams.hv_LineRowBegin.D(), 'f', 2));
	ui.txt_Col1_Line->setText(QString::number(resultParams.hv_LineColumnBegin.D(), 'f', 2));
	ui.txt_Row2_Line->setText(QString::number(resultParams.hv_LineRowEnd.D(), 'f', 2));
	ui.txt_Col2_Line->setText(QString::number(resultParams.hv_LineColumnEnd.D(), 'f', 2));
}
//ֱ�߲�������
void LineWindow::on_btn_SaveLineData_clicked()
{
	int ret = 1;
	//����ץ�߲���
	SetRunParams_Line(hv_RunParamsLine);
	//����ֱ�����в���
	ret = dataIOC.WriteParams_Line(configPath, XMLPath, hv_RunParamsLine, processID, nodeName, processModbuleID);
	if (ret != 0)
	{
		QMessageBox::information(this, "��ʾ", "��������ʧ��", QMessageBox::Ok);
		return;
	}
}
//ֱ�߲�����ȡ
void LineWindow::on_btn_LoadLineData_clicked()
{
	ErrorCode_Xml errorCode;
	//��ȡֱ�߲���
	errorCode = dataIOC.ReadParams_Line(configPath, XMLPath, hv_RunParamsLine, processID, nodeName, processModbuleID);
	if (errorCode != Ok_Xml)
	{
		QMessageBox::information(this, "��ʾ", "������ȡʧ��", QMessageBox::Ok);
		return;
	}
	//�������µ�����
	UpdateLineDataWindow(hv_RunParamsLine);
}
//����ֱ�߼�����в���������
void LineWindow::UpdateLineDataWindow(const RunParamsStruct_Line &RunParams)
{
	//ֱ��ץ��roi��ʼ��
	ui.dspb_RowBegin_Line->setValue(RunParams.hv_Row1.TupleReal().D());
	ui.dspb_ColBegin_Line->setValue(RunParams.hv_Column1.TupleReal().D());
	ui.dspb_RowEnd_Line->setValue(RunParams.hv_Row2.TupleReal().D());
	ui.dspb_ColEnd_Line->setValue(RunParams.hv_Column2.TupleReal().D());

	//ץ��ģ����Ҫ��ץ�߲���
	ui.spb_MeasureLength1_Line->setValue(RunParams.hv_MeasureLength1.TupleInt().I());		//���߰볤
	ui.spb_MeasureLength2_Line->setValue(RunParams.hv_MeasureLength2.TupleInt().I());		//���߰��
	ui.dspb_MeasureSigma_Line->setValue(RunParams.hv_MeasureSigma.TupleReal().D());		//ƽ��ֵ 
	ui.spb_MeasureThreshold_Line->setValue(RunParams.hv_MeasureThreshold);	//��Ե��ֵ
	ui.cmb_MeasureTransition_Line->setCurrentText(QString::fromUtf8(RunParams.hv_MeasureTransition.S().Text()));	//���߼���
	ui.cmb_MeasureSelect_Line->setCurrentText(QString::fromUtf8(RunParams.hv_MeasureSelect.S().Text()));		//��Եѡ��
	ui.spb_MeasureNum_Line->setValue(RunParams.hv_MeasureNum.TupleInt().I());		    //���߸���
	ui.dspb_MinScore_Line->setValue(RunParams.hv_MeasureMinScore.TupleReal().D());     //��С�÷�
	ui.dspb_DistanceThreshold_Line->setValue(RunParams.hv_DistanceThreshold.TupleReal().D());   //������ֵ
	ui.cmb_MeasureInterpolation_Line->setCurrentText(QString::fromUtf8(RunParams.hv_MeasureInterpolation.S().Text()));//��ֵ�㷨
	if (RunParams.isFollow)
	{
		ui.cmb_IsFollow_Line->setCurrentText("Yes");
	}
	else
	{
		ui.cmb_IsFollow_Line->setCurrentText("No");
	}
}
//���ֱ�߲ۺ���
int LineWindow::slot_FindLine(ResultParamsStruct_Line &resultParams)
{
	try
	{
		int ret = 1;
		//XML��ȡ����
		ErrorCode_Xml errorCode = dataIOC.ReadParams_Line(configPath, XMLPath, hv_RunParamsLine, processID, nodeName, processModbuleID);
		if (errorCode != Ok_Xml)
		{
			//XML��ȡʧ�ܣ���Ĭ��ֵ
			hv_RunParamsLine.hv_Row1 = 10;
			hv_RunParamsLine.hv_Column1 = 10;
			hv_RunParamsLine.hv_Row2 = 10;
			hv_RunParamsLine.hv_Column2 = 50;

			//ץ��ģ����Ҫ��ץ�߲���
			hv_RunParamsLine.hv_MeasureLength1 = 50;		
			hv_RunParamsLine.hv_MeasureLength2 = 5;		
			hv_RunParamsLine.hv_MeasureSigma = 1.0;		
			hv_RunParamsLine.hv_MeasureThreshold = 20;	
			hv_RunParamsLine.hv_MeasureTransition = "all";	
			hv_RunParamsLine.hv_MeasureSelect = "first";		
			hv_RunParamsLine.hv_MeasureNum = 10;		    
			hv_RunParamsLine.hv_InstancesNum = 1;		
			hv_RunParamsLine.hv_MeasureMinScore = 0.5;     
			hv_RunParamsLine.hv_DistanceThreshold = 3.5;   
			hv_RunParamsLine.hv_MeasureInterpolation = "nearest_neighbor";
			hv_RunParamsLine.isFollow = false;                
			//����ֱ�߼�����в���
			ret = dataIOC.WriteParams_Line(configPath, XMLPath, hv_RunParamsLine, processID, nodeName, processModbuleID);
			if (ret != 0)
			{
				return ret;
			}
		}
		//�����㷨
		return LineDetect1->FindLine(ho_Image, hv_RunParamsLine, resultParams);
	}
	catch (...)
	{
		return -1;
	}
}
//exe·��
string LineWindow::FolderPath()
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
string LineWindow::strReplaceAll(const string& strResource, const string& strOld, const string& strNew)
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
