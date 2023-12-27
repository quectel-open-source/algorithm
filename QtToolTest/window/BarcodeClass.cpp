#include "BarcodeClass.h"
#include <qtWidgets/qmessagebox.h>

BarcodeClass::BarcodeClass(HObject image, int _processID, int _processModbuleID, std::string _nodeName, std::string configPath, QWidget* parent)
	: QMainWindow(parent) {
	ui.setupUi(this);
	IniTableData_BarCode();
	barCodeParams1 = new BarCodeDetect();
	setWindowFlags(Qt::FramelessWindowHint);//���ر߿� 
	XMLPath = configPath + "/config.xml";
	this->configPath = configPath;
	nodeName = _nodeName;
	processID = _processID;
	processModbuleID = _processModbuleID;
	ho_Image = image;
	MainWndID = (Hlong)ui.label_image->winId();
	int labHeight = (Hlong)ui.label_image->height();
	int labWidth = (Hlong)ui.label_image->width();
	Displyimage(ho_Image, MainWndID, labHeight, labWidth);

	//����xml��ui
	updataUIData();
}

BarcodeClass::BarcodeClass(std::string _nodeName, int _processModbuleID, int _processID, std::string xmlPath) {
	barCodeParams1 = new BarCodeDetect();
	setWindowFlags(Qt::FramelessWindowHint);//���ر߿� 
	nodeName = _nodeName;
	processID = _processID;
	processModbuleID = _processModbuleID;
	XMLPath = xmlPath + "/config.xml";
	configPath = xmlPath + "/";
}

BarcodeClass::~BarcodeClass() {
}

void BarcodeClass::updataUIData(){
	//������Ҫ���
	RunParams_BarCode.hv_CodeType_Run.Clear();
	//��ȡһά�����
	dataIOC.ReadParams_BarCode(configPath, XMLPath, RunParams_BarCode, processID, nodeName, processModbuleID);
	UpdateBarCodeDataWindow(RunParams_BarCode);
}

void BarcodeClass::UpdateBarCodeDataWindow(const RunParamsStruct_BarCode& runParams) {
	ui.spb_CodeNum_BarCode->setValue(runParams.hv_CodeNum.I());
	SearchRoi_BarCode = runParams.ho_SearchRegion;

	QString contentTemp = "";
	contentTemp = QString::fromUtf8(runParams.hv_HeadChar.S().Text());
	if (contentTemp != "null" && contentTemp != "") {
		ui.txt_HeadChar_BarCode->setText(contentTemp);
	}

	contentTemp = QString::fromUtf8(runParams.hv_EndChar.S().Text());
	if (contentTemp != "null" && contentTemp != "") {
		ui.txt_EndChar_BarCode->setText(contentTemp);
	}

	contentTemp = QString::fromUtf8(runParams.hv_ContainChar.S().Text());
	if (contentTemp != "null" && contentTemp != "") {
		ui.txt_ContainChar_BarCode->setText(contentTemp);
	}

	contentTemp = QString::fromUtf8(runParams.hv_NotContainChar.S().Text());
	if (contentTemp != "null" && contentTemp != "") {
		ui.txt_NotContainChar_BarCode->setText(contentTemp);
	}

	ui.txt_CodeLength_BarCode->setText(QString::fromUtf8(to_string(runParams.hv_CodeLength_Run.I()).c_str()));
	ui.spb_TimeOut_BarCode->setValue(runParams.hv_TimeOut.I());

	CodeTypeStruct_BarCode codeTypeStruct;
	int len = runParams.hv_CodeType_Run.TupleLength().I();
	for (int i = 0; i < len; i++) {
		if (runParams.hv_CodeType_Run[i] == codeTypeStruct.CODABAR) {
			ui.ckb_CODABAR_BarCode->setCheckState(Qt::Checked);
		}
		else if (runParams.hv_CodeType_Run[i] == codeTypeStruct.CODE128) {
			ui.ckb_CODE128_BarCode->setCheckState(Qt::Checked);
		}
		else if (runParams.hv_CodeType_Run[i] == codeTypeStruct.CODE39) {
			ui.ckb_CODE39_BarCode->setCheckState(Qt::Checked);
		}
		else if (runParams.hv_CodeType_Run[i] == codeTypeStruct.CODE93) {
			ui.ckb_CODE93_BarCode->setCheckState(Qt::Checked);
		}
		else if (runParams.hv_CodeType_Run[i] == codeTypeStruct.EAN13) {
			ui.ckb_EAN13_BarCode->setCheckState(Qt::Checked);
		}
		else if (runParams.hv_CodeType_Run[i] == codeTypeStruct.EAN8) {
			ui.ckb_EAN8_BarCode->setCheckState(Qt::Checked);
		}
		else if (runParams.hv_CodeType_Run[i] == codeTypeStruct.ITF25) {
			ui.ckb_ITF25_BarCode->setCheckState(Qt::Checked);
		}
		else if (runParams.hv_CodeType_Run[i] == codeTypeStruct.PHARMACODE) {
			ui.ckb_PHARMACODE_BarCode->setCheckState(Qt::Checked);
		}
		else if (runParams.hv_CodeType_Run[i] == codeTypeStruct.UPCA) {
			ui.ckb_UPCA_BarCode->setCheckState(Qt::Checked);
		}
		else if (runParams.hv_CodeType_Run[i] == codeTypeStruct.UPCE) {
			ui.ckb_UPCE_BarCode->setCheckState(Qt::Checked);
		}
		else {
			string str = runParams.hv_CodeType_Run[i].S();
		}
	}
}

void BarcodeClass::on_toolButton_clicked() {
	BarcodeClass::showMinimized(); //��С��
}

void BarcodeClass::on_toolButton_2_clicked() {
	if (BarcodeClass::isMaximized()) {
		BarcodeClass::showNormal();//��ԭ�¼�
		//ui.toolButton_2->setIcon(QIcon(":/img/max.png"));
	}
	else {
		BarcodeClass::showMaximized();//����¼�
		//ui.toolButton_2->setIcon(QIcon(":/img/max.png"));
	}
}

void BarcodeClass::on_toolButton_3_clicked() {
	this->close();
}

void BarcodeClass::mousePressEvent(QMouseEvent* event) {
	if (event->button() == Qt::LeftButton) {
		whereismouse = event->pos();
	}
}

void BarcodeClass::mouseMoveEvent(QMouseEvent* event) {
	if (event->buttons() == Qt::LeftButton) {
		//��������󻯻���С��ʱҲ�����д���
		if (BarcodeClass::isMaximized() || BarcodeClass::isMinimized()) {
			return;
		}
		else {
			//���ڰ�ť֮����Ҫ�������ĵط������д���(����)
			if (ui.toolButton->underMouse() || ui.toolButton_2->underMouse() || ui.toolButton_3->underMouse()) {

			}
			else if (keypoint == 1) {

			}
			else {
				BarcodeClass::move(BarcodeClass::mapToGlobal(event->pos() - whereismouse));//�ƶ�
			}
		}
	}
	event->accept();
}

void BarcodeClass::getmessage(QString value) {
	QString currenttime = (QDateTime::currentDateTime()).toString("yyyy.MM.dd hh:mm:ss");
	ui.plainTextEdit->appendPlainText(currenttime + ": " + value);
}

void BarcodeClass::Displyimage(HObject ho_Image, Hlong MainWndID, int labHeight, int labWidth) {
	if (hv_WindowHandle != NULL) {
		CloseWindow(hv_WindowHandle);
	}
	GetImageSize(ho_Image, &hv_Width, &hv_Height);
	//���QT��ʾͼ�񴰿ڵĴ�СȻ���Halcon����
	OpenWindow(0, 0, (Hlong)labWidth, (Hlong)labHeight, MainWndID, "visible", "", &hv_WindowHandle);
	HDevWindowStack::Push(hv_WindowHandle);
	SetPart(hv_WindowHandle, 0, 0, hv_Height - 1, hv_Width - 1);
	if (HDevWindowStack::IsOpen()) {
		DispObj(ho_Image, hv_WindowHandle);
	}
}

void BarcodeClass::DisplyRegionImage(HObject ho_Image, HObject TempRoi, Hlong MainWndID, int labHeight, int labWidth) {
	HObject imagereduce, cropimage;

	if (region_WindowHandle != NULL) {
		CloseWindow(region_WindowHandle);
	}
	else {
		return;
	}
	ReduceDomain(ho_Image, TempRoi, &imagereduce);
	CropDomain(imagereduce, &cropimage);
	GetImageSize(cropimage, &hv_Width, &hv_Height);
	//���QT��ʾͼ�񴰿ڵĴ�СȻ���Halcon����
	OpenWindow(0, 0, (Hlong)labWidth, (Hlong)labHeight, MainWndID, "visible", "", &region_WindowHandle);
	HDevWindowStack::Push(region_WindowHandle);
	SetPart(region_WindowHandle, 0, 0, hv_Height - 1, hv_Width - 1);
	if (HDevWindowStack::IsOpen()) {
		DispObj(cropimage, region_WindowHandle);
	}
}

void BarcodeClass::DisplyRegion(HObject ho_Image, HObject TempRoi, Hlong MainWndID, int labHeight, int labWidth) {
	HObject xld;
	if (hv_WindowHandle != NULL) {
		CloseWindow(hv_WindowHandle);
	}
	GetImageSize(ho_Image, &hv_Width, &hv_Height);
	//���QT��ʾͼ�񴰿ڵĴ�СȻ���Halcon����
	OpenWindow(0, 0, (Hlong)labWidth, (Hlong)labHeight, MainWndID, "visible", "", &hv_WindowHandle);
	HDevWindowStack::Push(hv_WindowHandle);
	SetPart(hv_WindowHandle, 0, 0, hv_Height - 1, hv_Width - 1);
	SetColor(hv_WindowHandle, "green");
	SetLineWidth(hv_WindowHandle, 2);
	SetDraw(hv_WindowHandle, "margin");
	if (HDevWindowStack::IsOpen()) {
		DispObj(ho_Image, hv_WindowHandle);
		DispObj(TempRoi, hv_WindowHandle);
	}
}

void BarcodeClass::on_pushButton_save_clicked() {
	RunParamsStruct_BarCode runParams;
	SetRunParams_BarCode(runParams);
	dataIOC.WriteParams_BarCode(configPath, XMLPath, runParams, processID, nodeName, processModbuleID);
}

void BarcodeClass::gettitle(QString value) {
	ui.label_title->setText(value.mid(3, value.count() - 3));
	FlowName = value.mid(0, 3);
}

void BarcodeClass::getimage(HObject value) {
	//ui.cmb_BarCodeImage->addItem("ͼ��1");
	ho_ImageList.append(value);
	ho_Image = value;
	MainWndID = (Hlong)ui.label_image->winId();
	int labHeight = (Hlong)ui.label_image->height();
	int labWidth = (Hlong)ui.label_image->width();
	Displyimage(ho_Image, MainWndID, labHeight, labWidth);
}

void BarcodeClass::on_cmb_BarCodeImage_currentIndexChanged(int index) {
	if (ho_ImageList.size() != 0) {
		ho_Image = ho_ImageList[index];
		MainWndID = (Hlong)ui.label_image->winId();
		int labHeight = (Hlong)ui.label_image->height();
		int labWidth = (Hlong)ui.label_image->width();
		Displyimage(ho_Image, MainWndID, labHeight, labWidth);
	}
}

//���в���һά��ṹ�������ֵ����
void BarcodeClass::SetRunParams_BarCode(RunParamsStruct_BarCode& runParams) {

	runParams.hv_CodeNum = ui.spb_CodeNum_BarCode->value();
	runParams.ho_SearchRegion = SearchRoi_BarCode;
	string strTemp = ui.txt_HeadChar_BarCode->text().trimmed().toStdString().c_str();
	runParams.hv_HeadChar = HTuple(strTemp.c_str());

	strTemp = ui.txt_EndChar_BarCode->text().trimmed().toStdString().c_str();
	runParams.hv_EndChar = HTuple(strTemp.c_str());

	strTemp = ui.txt_ContainChar_BarCode->text().trimmed().toStdString().c_str();
	runParams.hv_ContainChar = HTuple(strTemp.c_str());

	strTemp = ui.txt_NotContainChar_BarCode->text().trimmed().toStdString().c_str();
	runParams.hv_NotContainChar = HTuple(strTemp.c_str());

	strTemp = ui.txt_NotContainChar_BarCode->text().trimmed().toStdString().c_str();
	runParams.hv_NotContainChar = HTuple(strTemp.c_str());


	runParams.hv_CodeLength_Run = HTuple(ui.txt_CodeLength_BarCode->text().trimmed().toInt());
	runParams.hv_TimeOut = ui.spb_TimeOut_BarCode->value();

	CodeTypeStruct_BarCode CodeTypes;
	runParams.hv_CodeType_Run.Clear();
	if (ui.ckb_CODABAR_BarCode->isChecked()) {
		runParams.hv_CodeType_Run.Append(CodeTypes.CODABAR);
	}
	if (ui.ckb_CODE128_BarCode->isChecked()) {
		runParams.hv_CodeType_Run.Append(CodeTypes.CODE128);
	}
	if (ui.ckb_CODE39_BarCode->isChecked()) {
		runParams.hv_CodeType_Run.Append(CodeTypes.CODE39);
	}
	if (ui.ckb_CODE93_BarCode->isChecked()) {
		runParams.hv_CodeType_Run.Append(CodeTypes.CODE93);
	}
	if (ui.ckb_EAN13_BarCode->isChecked()) {
		runParams.hv_CodeType_Run.Append(CodeTypes.EAN13);
	}
	if (ui.ckb_EAN8_BarCode->isChecked()) {
		runParams.hv_CodeType_Run.Append(CodeTypes.EAN8);
	}
	if (ui.ckb_ITF25_BarCode->isChecked()) {
		runParams.hv_CodeType_Run.Append(CodeTypes.ITF25);
	}
	if (ui.ckb_PHARMACODE_BarCode->isChecked()) {
		runParams.hv_CodeType_Run.Append(CodeTypes.PHARMACODE);
	}
	if (ui.ckb_UPCA_BarCode->isChecked()) {
		runParams.hv_CodeType_Run.Append(CodeTypes.UPCA);
	}
	if (ui.ckb_UPCE_BarCode->isChecked()) {
		runParams.hv_CodeType_Run.Append(CodeTypes.UPCE);
	}
	if (runParams.hv_CodeType_Run.TupleLength() == 0) {
		runParams.hv_CodeType_Run = CodeTypes.AUTO;
	}

	if (ui.cmb_Tolerance_BarCode->currentText() == "��׼") {
		runParams.hv_Tolerance = "low";
	}
	else {
		runParams.hv_Tolerance = "high";
	}
	//*******************************************************************************
	//��������ֵ
	GenEmptyObj(&SearchRoi_BarCode);
	//��������ϲ�
	if (!ho_BarCodeRegions.isEmpty()) {
		//һά����������ϲ�
		if (ho_BarCodeRegions.count() == 1) {
			SearchRoi_BarCode = ho_BarCodeRegions[0];
		}
		else {
			SearchRoi_BarCode = ho_BarCodeRegions[0];
			for (int i = 1; i < ho_BarCodeRegions.count(); i++) {
				Union2(SearchRoi_BarCode, ho_BarCodeRegions[i], &SearchRoi_BarCode);
			}
		}
		//������ʾͼ�θ�ֵ
		//ConcatObj(ho_ShowObj, SearchRoi_BarCode, &ho_ShowObj);
		runParams.ho_SearchRegion = SearchRoi_BarCode;
	}
	else {
		//���û�л�����������,�ÿ�
		GenEmptyObj(&SearchRoi_BarCode);
		SearchRoi_BarCode.Clear();
		GenEmptyObj(&runParams.ho_SearchRegion);
		runParams.ho_SearchRegion.Clear();
	}
}

void BarcodeClass::readRunParams_BarCode(RunParamsStruct_BarCode& runParams) {
	string strName = nodeName;
	if (strName == "") {
		getmessage("�����빤������!");
		return;
	}
}


//����һά����������
void BarcodeClass::on_btn_DrawRoi_BarCode_clicked() {
	keypoint = 1;
	MainWndID = (Hlong)ui.label_image->winId();
	if (ho_Image.IsInitialized() == NULL) {
		//ͼ��Ϊ�գ�����ͼ��clear
		getmessage("ͼ���ǿգ����ȼ���ͼ��!");
		return;
	}

	HObject TempRoi;
	roi->draw(ho_Image, hv_WindowHandle, "rectangle1", TempRoi);
	ho_BarCodeRegions.push_back(TempRoi);
	//һά����������ϲ�
	if (ho_BarCodeRegions.count() == 1) {
		SearchRoi_BarCode = ho_BarCodeRegions[0];
	}
	else {
		SearchRoi_BarCode = ho_BarCodeRegions[0];
		for (int i = 1; i < ho_BarCodeRegions.count(); i++) {
			Union2(SearchRoi_BarCode, ho_BarCodeRegions[i], &SearchRoi_BarCode);
		}
	}

	//������ˢ��ͼ�񴫵ݲ���(��Ҫ������Ϊ�˹�������ʱ��ʾͼ��)
	int labHeight = (Hlong)ui.label_image->height();
	int labWidth = (Hlong)ui.label_image->width();
	DisplyRegion(ho_Image, SearchRoi_BarCode, MainWndID, labHeight, labWidth);
	keypoint = 0;
}
void BarcodeClass::on_btn_ClearRoi_BarCode_clicked() {
	ho_BarCodeRegions.clear();
	SearchRoi_BarCode.Clear();
	MainWndID = (Hlong)ui.label_image->winId();
	int labHeight = (Hlong)ui.label_image->height();
	int labWidth = (Hlong)ui.label_image->width();
	Displyimage(ho_Image, MainWndID, labHeight, labWidth);
}
//��ʼ��һά������ʾ���
void BarcodeClass::IniTableData_BarCode() {
	QTableWidgetItem* hearderItem;
	QStringList hearderText;
	hearderText << "��������" << "��������" << "���볤��" << "X����" << "Y����";
	ui.tablewidget_Results_BarCode->setColumnCount(hearderText.size());
	for (int i = 0; i < ui.tablewidget_Results_BarCode->columnCount(); i++) {
		hearderItem = new QTableWidgetItem(hearderText.at(i));
		QFont font = hearderItem->font();
		font.setBold(true);//����Ϊ����
		font.setPointSize(12);//���������С
		hearderItem->setTextColor(Qt::red);//������ɫ
		hearderItem->setFont(font);//��������
		ui.tablewidget_Results_BarCode->setHorizontalHeaderItem(i, hearderItem);
	}
}
//����һά������ʾ�������
void BarcodeClass::SetTableData_BarCode(const ResultParamsStruct_BarCode& resultStruct) {
	//��ս���������
	ui.tablewidget_Results_BarCode->clearContents();
	//�ж��Ƿ��ҵ�����
	if (resultStruct.hv_RetNum == 0) {
		//û���ҵ����룬�˳�
		return;
	}
	//ˢ�������ҵ���������Ϣ
	int count = resultStruct.hv_RetNum.I();
	ui.tablewidget_Results_BarCode->setRowCount(count);
	for (int i = 0; i < count; i++) {
		QTableWidgetItem* item;
		QString str;
		//��������
		str = QString::fromUtf8(resultStruct.hv_CodeType_Result[i].S().Text());
		item = new QTableWidgetItem(str, 1000);
		item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
		ui.tablewidget_Results_BarCode->setItem(i, 0, item);
		//��������
		str = QString::fromUtf8(resultStruct.hv_CodeContent[i].S().Text());
		item = new QTableWidgetItem(str, 1000);
		item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
		ui.tablewidget_Results_BarCode->setItem(i, 1, item);
		//���볤��
		str = QString::number(resultStruct.hv_CodeLength_Result[i].I());
		item = new QTableWidgetItem(str, 1000);
		item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
		ui.tablewidget_Results_BarCode->setItem(i, 2, item);
		//X����
		str = QString::number(resultStruct.hv_Column[i].D(), 'f', 2);
		item = new QTableWidgetItem(str, 1000);
		item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
		ui.tablewidget_Results_BarCode->setItem(i, 3, item);
		//Y����
		str = QString::number(resultStruct.hv_Row[i].D(), 'f', 2);
		item = new QTableWidgetItem(str, 1000);
		item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
		ui.tablewidget_Results_BarCode->setItem(i, 4, item);
	}
}

//һά����ۺ���
void BarcodeClass::on_btn_FindBarCode_clicked() {
	if (ho_Image.Key() == nullptr) {
		//ͼ��Ϊ�գ�����ͼ��clear
		QMessageBox::information(this, "��ʾ", "ͼ���ǿգ����ȼ���ͼ��!", QMessageBox::Ok);
		return;
	}

	//ʶ��һά��
	ResultParamsStruct_BarCode resultParams;
	QDateTime startTime = QDateTime::currentDateTime();
	run(resultParams);
	QDateTime endTime = QDateTime::currentDateTime();
	qint64 intervalTimeMS = startTime.msecsTo(endTime);

	HTuple contourCount;
	CountObj(resultParams.ho_ContourBarCode,&contourCount);
	if (contourCount.I() == 0) {
		MainWndID = (Hlong)ui.label_image->winId();
		int labHeight = (Hlong)ui.label_image->height();
		int labWidth = (Hlong)ui.label_image->width();
		Displyimage(ho_Image, MainWndID, labHeight, labWidth);
		return;
	}
	else {
		result_DisplyResion = resultParams.ho_ContourBarCode;
		MainWndID = (Hlong)ui.label_image->winId();
		int labHeight = (Hlong)ui.label_image->height();
		int labWidth = (Hlong)ui.label_image->width();
		DisplyRegion(ho_Image, result_DisplyResion, MainWndID, labHeight, labWidth);
		if (intervalTimeMS != 0) {
			getmessage("һά���ʱ�� " + QString::number(intervalTimeMS) + " ms");
		}
	}
}

void BarcodeClass::run(ResultParamsStruct_BarCode& _resultParams) {

	try {
		//XML��ȡ����
		RunParamsStruct_BarCode _runParams;  //һά�����в���
		_runParams.hv_CodeType_Run.Clear();
		ErrorCode_Xml errorCode = dataIOC.ReadParams_BarCode(configPath, XMLPath, _runParams, processID, nodeName, processModbuleID);
		if (errorCode != Ok_Xml) {
			//XML��ȡʧ�ܣ���Ĭ��ֵ
			GenEmptyObj(&_runParams.ho_SearchRegion);
			_runParams.ho_SearchRegion.Clear();
			_runParams.hv_CodeType_Run = "auto";
			_runParams.hv_CodeNum = 1;
			_runParams.hv_Tolerance = "high";
			_runParams.hv_HeadChar = "null";
			_runParams.hv_EndChar = "null";
			_runParams.hv_ContainChar = "null";
			_runParams.hv_NotContainChar = "null";
			_runParams.hv_CodeLength_Run = 2;
			_runParams.hv_TimeOut = 50;
			//����һά�����в���
			dataIOC.WriteParams_BarCode(configPath, XMLPath, _runParams, processID, nodeName, processModbuleID);
		}
		//�����㷨
		barCodeParams1->FindBarCodeFunc(ho_Image, _runParams, _resultParams);
		HTuple countRegion;
		CountObj(_resultParams.ho_ContourBarCode, &countRegion);
		if (countRegion.I() == 0)
			return;
		else
			result_DisplyResion = _resultParams.ho_ContourBarCode;
	}
	catch (const std::exception&) {
		return ;
	}
}