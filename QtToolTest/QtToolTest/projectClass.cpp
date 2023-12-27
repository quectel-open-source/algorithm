#include "projectClass.h"
#include "algorithm.h"
#include <direct.h>
projectClass::projectClass(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	QFile f("./qdarkstyle/theme/darkstyle.qss");

	if (!f.exists()) {
		printf("Unable to set stylesheet, file not found\n");
	}
	else {
		f.open(QFile::ReadOnly | QFile::Text);
		QTextStream ts(&f);
		qApp->setStyleSheet(ts.readAll());
	}
	setWindowFlags(Qt::FramelessWindowHint);//隐藏边框 
	int currenttab = ui.tabWidget->currentIndex();

	eModubleType modubleName = eModubleType::Image;
	std::string modubleTitle = "图片";
	modubleData dataPhoto(modubleName, modubleTitle);
	dataPhoto.addModublePortOut( eDataType::imagePath, true, ePortType::String);
	dataPhoto.addModublePortOut( eDataType::outImage, true, ePortType::HImage);

	modubleData dataCamera(eModubleType::Camera, "相机");
	dataCamera.addModublePortOut(eDataType::outImage, true, ePortType::HImage);

	modubleData dataBarcode(eModubleType::Barcode, "条码识别");
	dataBarcode.addModublePortIn(eDataType::inputImage, true, ePortType::HImage);
	dataBarcode.addModublePortOut(eDataType::outText, true, ePortType::String);

	modubleData dataLine(eModubleType::Line, "线段检测");
	dataLine.addModublePortIn(eDataType::inputImage, true, ePortType::HImage);
	dataLine.addModublePortOut(eDataType::outText, true, ePortType::String);
	dataLine.addModublePortOut(eDataType::Line1, true, ePortType::HLine);

	modubleData dataCircle(eModubleType::Circle, "圆检测");
	dataCircle.addModublePortIn(eDataType::inputImage, true, ePortType::HImage);
	dataCircle.addModublePortOut(eDataType::outText, true, ePortType::String);
	dataCircle.addModublePortOut(eDataType::Circle1, true, ePortType::HCircle);


	modubleData dataQRCode(eModubleType::QRCode, "二维码检测");
	dataQRCode.addModublePortIn(eDataType::inputImage, true, ePortType::HImage);
	dataQRCode.addModublePortOut(eDataType::outText, true, ePortType::String);

	modubleData dataTemplate(eModubleType::Template, "模板匹配");
	dataTemplate.addModublePortIn(eDataType::inputImage, true, ePortType::HImage);
	dataTemplate.addModublePortOut(eDataType::outText, true, ePortType::String);

	modubleData dataEllipse(eModubleType::Ellipse, "椭圆检测");
	dataEllipse.addModublePortIn(eDataType::inputImage, true, ePortType::HImage);
	dataEllipse.addModublePortOut(eDataType::outText, true, ePortType::String);

	modubleData dataRectangle(eModubleType::Rectangle, "矩形检测");
	dataRectangle.addModublePortIn(eDataType::inputImage, true, ePortType::HImage);
	dataRectangle.addModublePortOut(eDataType::outText, true, ePortType::String);

	modubleData dataIntersectionLL(eModubleType::IntersectionLL, "线线交点");
	dataIntersectionLL.addModublePortIn(eDataType::inputImage, true, ePortType::HImage);
	dataIntersectionLL.addModublePortIn(eDataType::Line1, true, ePortType::HLine);
	dataIntersectionLL.addModublePortIn(eDataType::Line2, true, ePortType::HLine);
	dataIntersectionLL.addModublePortOut(eDataType::Col, true, ePortType::HTuple);
	dataIntersectionLL.addModublePortOut(eDataType::Row, true, ePortType::HTuple);

	modubleData dataIntersectionCC(eModubleType::IntersectionCC, "圆圆交点");
	dataIntersectionCC.addModublePortIn(eDataType::inputImage, true, ePortType::HImage);
	dataIntersectionCC.addModublePortIn(eDataType::Circle1, true, ePortType::HCircle);
	dataIntersectionCC.addModublePortIn(eDataType::Circle2, true, ePortType::HCircle);
	dataIntersectionCC.addModublePortOut(eDataType::Col, true, ePortType::HTuple);
	dataIntersectionCC.addModublePortOut(eDataType::Row, true, ePortType::HTuple);
	dataIntersectionCC.addModublePortOut(eDataType::Col2, true, ePortType::HTuple);
	dataIntersectionCC.addModublePortOut(eDataType::Row2, true, ePortType::HTuple);
	//setDefaultPath();

	windID = (Hlong)ui.label_image->winId();

	int width = ui.label_image->width();
	int height = ui.label_image->height();
	OpenWindow(0,
		0,
		width,
		height,
		windID,
		"visible",
		"",
		&hv_WindowHandle);

	connect(this, SIGNAL(showImageS()), this, SLOT(showImage()));
	connect(timer, SIGNAL(timeout()), this, SLOT(onTimeout()));
}

std::map<int, algorithm*> algorithmList1;
projectClass::~projectClass()
{
	saveProcesses();
	//遍历algorithmList1
	for (auto it = algorithmList1.begin(); it != algorithmList1.end(); it++)
	{

			delete it->second;
		}

}

void projectClass::on_toolButton_clicked()
{
	projectClass::showMinimized(); //最小化
}

void projectClass::on_toolButton_2_clicked()
{
	if (projectClass::isMaximized())
	{
		projectClass::showNormal();//还原事件
		//ui.toolButton_2->setIcon(QIcon(":/img/max.png"));
	}
	else
	{
		projectClass::showMaximized();//最大化事件
		//ui.toolButton_2->setIcon(QIcon(":/img/max.png"));
	}
}

void projectClass::on_toolButton_3_clicked()
{
	this->close();
}

void projectClass::mousePressEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton)
	{
		whereismouse = event->pos();
	}
	//确保右键点击，然后跳出菜单.
	if (event->button() == Qt::RightButton)
	{
		//在鼠标右击的地方弹出菜单
		/*if (ui.tabWidget->geometry().contains(this->mapFromGlobal(QCursor::pos())))
		{
			popMenu->exec(event->globalPos());
		}*/
	}
}

void projectClass::mouseMoveEvent(QMouseEvent *event)
{
	if (event->buttons() == Qt::LeftButton)
	{
		//当窗口最大化或最小化时也不进行触发
		if (projectClass::isMaximized() || projectClass::isMinimized())
		{
			return;
		}
		else
		{
			//当在按钮之类需要鼠标操作的地方不进行触发(防误触)
			if (ui.toolButton->underMouse() || ui.toolButton_2->underMouse() || ui.toolButton_3->underMouse())
			{
			}
			else
			{
				projectClass::move(projectClass::mapToGlobal(event->pos() - whereismouse));//移动
			}
		}
	}
	event->accept();
}

void projectClass::closeEvent(QCloseEvent* e){
	//QApplication* app;
	//app->quit();
	//HANDLE hself = GetCurrentProcess();
	//TerminateProcess(hself, 0);
	saveProcesses();
	this->hide();
}

void projectClass::getmessage(QString value)
{
	QString currenttime = (QDateTime::currentDateTime()).toString("yyyy.MM.dd hh:mm:ss");
	ui.plainTextEdit->appendPlainText(currenttime + ": " + value);
}


//添加流程
void projectClass::on_toolButton_addTab_clicked()
{
	//小于12个
	addProcess();
}

void projectClass::addProcess(){
	processWidget = new QWidget();
	algorithmScene::registerModuble(modubleData::getModubleData());
	addAlgorithmScene(processWidget);
	setCallback();
	algorithmList1[processID] = new algorithm(processID, configPath);
	std::string tabName = processNamePrefix + std::to_string(processID++);
	ui.tabWidget->addTab(processWidget, tabName.c_str());
}

//添加流程
void projectClass::addAlgorithmScene(QWidget* processWidget)
{
	algorithmScene* c2 = new algorithmScene(processID, processWidget);
	algorithmSceneList[processID] = c2;
}

window window1;
void projectClass::getSelectModubleData(int _processID, int _modubleID, std::string _modubleName, std::function<void(int processModubleID)> functionModubleID) {

	eModubleType modubleName = data::stringToModubleName(_modubleName);
	HObject image1;
	if (modubleName == eModubleType::Barcode|| modubleName== eModubleType::Line || modubleName == eModubleType::Circle
		|| modubleName== eModubleType::QRCode|| modubleName== eModubleType::Template || modubleName == eModubleType::Ellipse
		|| modubleName==eModubleType::Rectangle || modubleName == eModubleType::IntersectionLL || modubleName == eModubleType::IntersectionCC)
		image1 = algorithmList1[_processID]->getShowImage(_modubleID);
	else
		GenEmptyObj(&image1);

	//设置需要的值交点
	ParamsStruct_Line line12;
	ParamsStruct_Line line22;
	ParamsStruct_Circle circle12;
	ParamsStruct_Circle circle22;

	switch (modubleName) {
	case eModubleType::IntersectionLL:
		line12 = algorithmList1[_processID]->getLine(_modubleID,0);
		line22 = algorithmList1[_processID]->getLine(_modubleID,1);
		window1.setLine(line12.ColumnBegin,line12.RowBegin,line12.ColumnEnd,line12.RowEnd, 0);
		window1.setLine(line22.ColumnBegin, line22.RowBegin, line22.ColumnEnd, line22.RowEnd, 1);
		break;
	case eModubleType::IntersectionCC:
		circle12= algorithmList1[_processID]->getCircle(_modubleID, 0);
		circle22 = algorithmList1[_processID]->getCircle(_modubleID, 1);
		window1.setCircle(circle12, 0);
		window1.setCircle(circle22, 1);
		break;
	default:
		break;
	}
	//调用window组件中的getSelectModubleData
	window1.getSelectModubleData(_processID, _modubleID, _modubleName, functionModubleID, image1,configPath);
}

void projectClass::getClickModuble(int _processID, int _modubleID) {
	showModubleID = _modubleID;
	HObject showImage = algorithmList1[_processID]->getShowImage(_modubleID);
	HObject showRegion = algorithmList1[_processID]->getShowRegion(_modubleID);
	if (showImage.Key() != nullptr) {
		HTuple x, y;
		GetImageSize(showImage, &x, &y);
		SetPart(hv_WindowHandle, 0, 0, y, x);

		DispObj(showImage, hv_WindowHandle);
		SetColor(hv_WindowHandle, "green");
		if (showRegion.Key() != nullptr)
			DispObj(showRegion, hv_WindowHandle);
	}
}

void projectClass::setCallback()
{
	//添加模块回调
	std::function<void(int rightMousePositionX, int rightMousePositionY)> callbackRightMousePosition
		= std::bind(&projectClass::addModule, this, std::placeholders::_1, std::placeholders::_2);

	algorithmSceneList[processID]->setCallback(callbackRightMousePosition,nullptr,
		std::bind(&projectClass::getSelectModubleData, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, 
			std::placeholders::_4),
		nullptr, std::bind(&projectClass::getClickModuble, this, std::placeholders::_1, std::placeholders::_2));
}

void projectClass::loadProcesses(std::string _configPath) {
	configPath = _configPath;
	saveProcesses();
	clearProcesses();

	if (configPath != "") {
		algorithmScene::setConfigPath(configPath);
		//process::setConfigPath(configPath);
		loadProcesses(algorithmScene::getProcessIDList());
		loadScenes();
	}
	//runProcesses();
	this->update();
}

void projectClass::saveProcesses() {
	for (std::map<int, algorithmScene*>::iterator iter = algorithmSceneList.begin();
		iter != algorithmSceneList.end();
		iter++)
		iter->second->save();
}

void projectClass::clearProcesses() {
	for (std::map<int, algorithmScene*>::iterator iter = algorithmSceneList.begin();
		iter != algorithmSceneList.end();
		iter++)
		ui.tabWidget->removeTab(ui.tabWidget->currentIndex());
	algorithmSceneList.clear();
	processID = 0;
	//QLayoutItem* child;
	//while ((child = resultLayout->takeAt(0)) != 0) {
	//	delete child->widget();
	//	delete child;
	//}
	//while ((child = ui.verticalLayoutProcessID->takeAt(0)) != 0) {
	//	delete child->widget();
	//	delete child;
	//}
	//while ((child = ui.verticalLayoutProcessCount->takeAt(0)) != 0) {
	//	delete child->widget();
	//	delete child;
	//}
	//while ((child = ui.verticalLayoutProcessNG->takeAt(0)) != 0) {
	//	delete child->widget();
	//	delete child;
	//}
}

std::map<int, std::string> getPairList(std::string XMLPath, int processID) {
	std::map<int, std::string> mapTemp;
	tinyxml2::XMLDocument doc;
	doc.LoadFile(XMLPath.c_str());
	std::vector<std::string> pathList;
	for (tinyxml2::XMLElement* node1 = doc.FirstChildElement("nodesView"); node1;
		node1 = node1->NextSiblingElement("nodesView")) {
		int processIDTemp = atoi(node1->Attribute("process"));
		if (processIDTemp == processID) {
			for (tinyxml2::XMLElement* node = node1->FirstChildElement(); node;
				node = node->NextSiblingElement()) {

				std::string name = node->Attribute("nodeName");

				int proceedID = atoi(node->Attribute("nodeProcessID"));
				mapTemp[proceedID] = name;
			}
		}
	}
	return mapTemp;
}

void projectClass::loadProcesses(std::vector<int> processIDList) {
	int maxIndex = 0;
	for (int i = 0; i < processIDList.size(); i++) {
		processID = processIDList[i];
		addProcess();
		//获取当天id下模块名称及模块id列表configPath
		std::map<int, std::string> modubleList = getPairList(configPath+"\\config.xml", processID-1);
		for(std::map<int, std::string>::iterator iter = modubleList.begin();iter != modubleList.end();iter++)
			loadProcessAddModule(iter->second,processID-1,iter->first);

		if (processID > maxIndex)
			maxIndex = processID;
	}
	processID = maxIndex;
}

void projectClass::loadScenes(){
	for (std::map<int, algorithmScene*>::iterator iter = algorithmSceneList.begin();
		iter != algorithmSceneList.end();
		iter++)
		iter->second->load();
}

std::map<int, std::vector<idName>> modubleDataList;
//添加模块
void projectClass::addModule(int positionX, int positionY)
{
	QString currentWidgetName = ui.tabWidget->tabText(ui.tabWidget->currentIndex());
	int currentProcessID = std::stoi(currentWidgetName.toStdString().substr(processNamePrefix.length()));
	//QString moduleName = ui.comboBox->currentText();
	int modubleID = algorithmSceneList[currentProcessID]->addModule(moduleName, QPointF(positionX, positionY));

	modubleDataList[currentProcessID].push_back({ modubleID, moduleName });
	algorithmList1[currentProcessID]->addModuble(moduleName, modubleID);

	if (moduleName == eModubleType::Camera) {
		std::function<void()> onTimeout
			= std::bind(&projectClass::onTimeout, this);
		algorithmList1[currentProcessID]->getModuble(data::modubleNameToString(moduleName), modubleID)->setTriggerCallback(onTimeout);
	}

	//testAlgorithm *QtAglClass1 = new testAlgorithm("threshold", modubleID);
	//std::function<void(HObject image, int thresholdMin)> callbackIndexAlgorithm
	//	= std::bind(&testAlgorithm::threld, QtAglClass1, std::placeholders::_1, std::placeholders::_2);
	//std::function<void(HObject originImage, HObject resultRegion, bool isOK)> getOriginResultImage
	//	= std::bind(&QtToolTest::getOriginResultImage, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);
	//testAlgorithm::setCallbackResultData(getOriginResultImage);
	//indexAlgorithmMap[modubleID] = callbackIndexAlgorithm;
}

void projectClass::loadProcessAddModule(std::string _moduleName,int currentProcessID, int modubleID) {
	eModubleType moduleName = data::stringToModubleName(_moduleName);
	modubleDataList[currentProcessID].push_back({ modubleID, moduleName });
	algorithmList1[currentProcessID]->addModuble(moduleName, modubleID);

	if (moduleName == eModubleType::Camera) {
		std::function<void()> onTimeout
			= std::bind(&projectClass::onTimeout, this);
		algorithmList1[currentProcessID]->getModuble(data::modubleNameToString(moduleName), modubleID)->setTriggerCallback(onTimeout);
	}
}

void projectClass::on_toolButton_camera_clicked()
{
	if (ui.tabWidget->count() == 0)
	{
		getmessage("请先添加流程!");
		return;
	}
	moduleName = eModubleType::Camera;
	addModule(30, 50);
}

void projectClass::on_toolButton_iamge_clicked()
{
	if (ui.tabWidget->count() == 0)
	{
		getmessage("请先添加流程!");
		return;
	}
	moduleName = eModubleType::Image;
	addModule(30, 50);
}

void projectClass::on_toolButton_barcode_clicked()
{
	if (ui.tabWidget->count() == 0)
	{
		getmessage("请先添加流程!");
		return;
	}
	moduleName = eModubleType::Barcode;
	addModule(30, 50);
}

void projectClass::on_toolButton_line_clicked() {
	if (ui.tabWidget->count() == 0) {
		getmessage("请先添加流程!");
		return;
	}
	moduleName = eModubleType::Line;
	addModule(30, 50);
}

void projectClass::on_toolButton_circle_clicked() {
	if (ui.tabWidget->count() == 0) {
			getmessage("请先添加流程!");
			return;
		}
	moduleName = eModubleType::Circle;
	addModule(30, 50);
}

void projectClass::on_QRCodeButton_clicked(){
	if (ui.tabWidget->count() == 0) {
			getmessage("请先添加流程!");
			return;
		}
	moduleName = eModubleType::QRCode;
	addModule(30, 50);
}

void projectClass::on_toolButton_match_clicked(){
	if (ui.tabWidget->count() == 0) {
		getmessage("请先添加流程!");
		return;
	}
	moduleName = eModubleType::Template;
	addModule(30, 50);
}

void projectClass::on_toolButton_ellipse_clicked() {
	if (ui.tabWidget->count() == 0) {
		getmessage("请先添加流程!");
		return;
	}
	moduleName = eModubleType::Ellipse;
	addModule(30, 50);
}

void projectClass::on_toolButton_rectangle_clicked() {
	if (ui.tabWidget->count() == 0) {
			getmessage("请先添加流程!");
			return;
		}
	moduleName = eModubleType::Rectangle;
	addModule(30, 50);
}

void projectClass::on_toolButton_cross_clicked() {
	if (ui.tabWidget->count() == 0) {
		getmessage("请先添加流程!");
		return;
	}
	moduleName = eModubleType::IntersectionLL;
	addModule(30, 50);
}

void projectClass::on_toolButton_crossCC_clicked() {
	if (ui.tabWidget->count() == 0) {
		getmessage("请先添加流程!");
		return;
	}
	moduleName = eModubleType::IntersectionCC;
	addModule(30, 50);
}

void projectClass::on_toolButton_match_14_clicked() {
	startProcesses(false);
	runProcesses();
	emit showImageS();
	endProcesses();
}

void projectClass::on_toolButton_run_clicked() {
	QString buttonName = ui.toolButton_run->text();
	if (buttonName == "连续运行")
		ui.toolButton_run->setText("停止运行");
	else if (buttonName == "停止运行")
		ui.toolButton_run->setText("连续运行");
	bool isContinus = (buttonName == "连续运行") ? true : false;
	runProcessesContinuous(isContinus);
}

void projectClass::runProcessesContinuous(bool isContinus){
	//使用迭代器，遍历processMap[processID]
	int currentProcessID = getCurrentProcessID();
	map<int, algorithmModuble*> processList = algorithmList1[currentProcessID]->getModubleList();
	std::vector<std::string> modubleNameList = algorithmList1[currentProcessID]->getModubleNameList();
	bool isExistCamera = false;
	bool isExistImage = false;
	//for (std::map<int, algorithmModuble*>::iterator iter = processList.begin();
	//	iter != processList.end();
	//	iter++) {
	for (int index = 0; index < modubleNameList.size(); index++) {
		//if (data::stringToModubleName(iter->second->nodeName) == eModubleType::Image)
		if (data::stringToModubleName(modubleNameList[index]) == eModubleType::Image)
			isExistImage = true;
		//if (data::stringToModubleName(iter->second->nodeName) == eModubleType::Camera)
		if (data::stringToModubleName(modubleNameList[index]) == eModubleType::Camera)
			isExistCamera = true;
	}
	;
	runProcessContinuous(isContinus, isExistCamera, isExistImage);
}

void projectClass::runProcessContinuous(bool isContinus,bool isExistCamera,bool isExistImage){
	if (isContinus) {
		if (isExistCamera) {
			startProcesses(true);
		}
		else if (isExistImage) {
			int nodeCount = 0;
			std::string XMLPath = configPath + "\\config.xml";
			tinyxml2::XMLDocument doc;
			doc.LoadFile(XMLPath.c_str());
			std::vector<std::string> pathList;
			for (tinyxml2::XMLElement* node1 = doc.FirstChildElement("config"); node1;
				node1 = node1->NextSiblingElement("config")) {
				int processIDTemp = atoi(node1->Attribute("process"));
				if (processIDTemp == 0) {
					for (tinyxml2::XMLElement* node = node1->FirstChildElement(); node;
						node = node->NextSiblingElement()) {
						std::string name = node->Attribute("nodeName");
						int proceedID = atoi(node->Attribute("nodeProcessID"));
						if (name == data::modubleNameToString(eModubleType::Image) && proceedID == 0) {
							nodeCount++;
							//RunParams.hv_MatchMethod = HTuple(xmlC->GetXMLValue(RunParams.jobName, RunParams.toolName, "hv_MatchMethod").c_str());

							//遍历node节点下所有imageList,并进行删除

							for (tinyxml2::XMLElement* imageList = node->FirstChildElement(); imageList; imageList = imageList->NextSiblingElement()
								) {
								std::string temp = imageList->Attribute("path");
								pathList.push_back(temp);

							}
							break;
						}
					}
				}
			}
			timer->start(500);
		}
	}
	else if (!isContinus) {
		if (isExistCamera) {
			endProcesses();
		}
		else if (isExistImage)
			timer->stop();
	}
}

void projectClass::onTimeout(){

	runProcesses();
	emit showImageS();

}

void projectClass::startProcesses(bool isStartContinus){
	int currentProcessID = getCurrentProcessID();
	map<int, algorithmModuble*> processList = algorithmList1[currentProcessID]->getModubleList();
	for (std::map<int, algorithmModuble*>::iterator iter = processList.begin();
		iter != processList.end();
		iter++)
		iter->second->start(isStartContinus);
}

int saveINDEX = 0;

void projectClass::runProcesses() {
	clock_t startTotal, finishTotal;
	startTotal = clock();
	for (std::map<int, algorithmScene*>::iterator iter = algorithmSceneList.begin();
		iter != algorithmSceneList.end();
		iter++)
	//	iter->second->run();
	{
		clock_t start, finish;
		start= clock();
		int currentProcessID = getCurrentProcessID();
		int ProcessID = iter->first;
		std::vector<connectionPair> connectionPair1 = algorithmSceneList[ProcessID]->getConnectionPair();
		//connectionPair中的outModubleID或inModubleID为模块的id,该id与addModule函数中的modubleID变量对应
		std::vector<int> ModubleOrder = algorithmSceneList[ProcessID]->getModubleOrder();

		clock_t t1, t2;
		t1= clock();
		algorithmList1[ProcessID]->runProcess(ModubleOrder, connectionPair1, modubleDataList[ProcessID]);
		t2 = clock();
		int time = t2 - t1;
		
		//获取ModubleOrder最后一个元素

		//判断当前iter在整个algorithmSceneList中的下标
		int distance = std::distance(algorithmSceneList.begin(), iter);
		int total= std::distance(algorithmSceneList.begin(), algorithmSceneList.end());
		int modubleID = 0;
		int modubleSize= ModubleOrder.size();
		if(showModubleID> modubleSize - 1)
			showModubleID= modubleSize - 1;
		if (showModubleID >= 0)
			modubleID = showModubleID;
		else
			modubleID = ModubleOrder.size() - 1;
		finish = clock();
		int timeOnce = finish - start;
		if (ModubleOrder.size() == 0 && modubleDataList[ProcessID].size() > 0){
			//回调
			sendResultInformation(total,distance, algorithmList1[ProcessID]->getShowImage(0), algorithmList1[ProcessID]->getShowRegion(0), rand() % 100 >10, timeOnce);
		}
		else{
			//回调
			if(modubleSize>0)
			sendResultInformation(total,distance, algorithmList1[ProcessID]->getShowImage(ModubleOrder[modubleID]), algorithmList1[ProcessID]->getShowRegion(ModubleOrder[modubleID]), rand() % 100 > 10, timeOnce);
		}

		if(currentProcessID== ProcessID){
			if (ModubleOrder.size() == 0 && modubleDataList[currentProcessID].size() > 0) {
				showImage1 = algorithmList1[currentProcessID]->getShowImage(0);
				showRegion1 = algorithmList1[currentProcessID]->getShowRegion(0);
			}
			else {
				showImage1 = algorithmList1[currentProcessID]->getShowImage(ModubleOrder[modubleID]);
				showRegion1 = algorithmList1[currentProcessID]->getShowRegion(ModubleOrder[modubleID]);
			}
		}
	}
	finishTotal = clock();
	sendTotalTime(finishTotal-startTotal);
}

void projectClass::showImage(){
	HTuple x, y;
	if(showImage1.Key()!=nullptr){
		GetImageSize(showImage1, &x, &y);
		SetPart(hv_WindowHandle, 0, 0, y, x);
		DispObj(showImage1, hv_WindowHandle);
		//std::string savePath = "d:/" + to_string(saveINDEX);
		//WriteImage(showImage,"png",255, savePath.c_str());
	}

	SetColor(hv_WindowHandle, "green");
	if (showRegion1.Key() != nullptr)
		DispObj(showRegion1, hv_WindowHandle);
}

void projectClass::endProcesses() {
	int currentProcessID = getCurrentProcessID();
	map<int, algorithmModuble*> processList = algorithmList1[currentProcessID]->getModubleList();
	for (std::map<int, algorithmModuble*>::iterator iter = processList.begin();
		iter != processList.end();
		iter++)
		iter->second->end();
}

int projectClass::getCurrentProcessID() {
	int index = ui.tabWidget->currentIndex();
	QString currentWidgetName = ui.tabWidget->tabText(index);
	int currentProcessID = std::stoi(
		currentWidgetName.toStdString().substr(processNamePrefix.length()));
	return currentProcessID;
}

void projectClass::setDefaultPath() {
	char buffer[256];
	_getcwd(buffer, 256);
	std::string currentPath = buffer;
	configPath = currentPath + "\\config";
}