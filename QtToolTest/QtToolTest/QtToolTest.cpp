#include "QtToolTest.h"
#include <corecrt_io.h>
#include <qfiledialog.h>
#include <iostream>
#include <direct.h>
#include "algorithm.h"

//#include "QtAglClass.h"

QtToolTest::QtToolTest(QWidget* parent)
	: QMainWindow(parent) {
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

	qRegisterMetaType<HObject>("HObject");
	connect(this, SIGNAL(sendResultImage(int, QString)), this, SLOT(SetData(int, QString)));
	connect(this, SIGNAL(sendResultTime(int, qint64)), this, SLOT(SetTime(int, qint64)));
	connect(this, SIGNAL(SendDisplyimage(int, HObject)), this, SLOT(Displyimage(int, HObject)));
	connect(this, SIGNAL(SendDisplyRegion(int, HObject, HObject)), this, SLOT(DisplyRegion(int, HObject, HObject)));
	connect(projectdlg, SIGNAL(sendResultInformation(int, int, HObject, HObject, bool, int)), this, SLOT(getResultInformation(int, int, HObject, HObject, bool, int)));
	connect(projectdlg, SIGNAL(sendTotalTime(int)), SLOT(getTotalTime(int)));

	//折线图初始化
	InitializeChart();
	//窗口集合初始化
	for (int i = 0; i < WindowMaxNum; i++) {
		HTuple Window1;
		Hlong WndID1;
		hv_WindowHandleTemp.append(Window1);
		MainWndIDTemp.append(WndID1);
	}
	connect(projectdlg, SIGNAL(projectPath(QString)), this, SLOT(GetprojectPath(QString)));

	QTimer* timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(timerUpDate()));
	timer->start(1000);
	// 初始化状态栏
	labCellIndex = new QLabel("当前时间:", this);
	labCellIndex->setStyleSheet("color: rgb(129, 211, 248)");
	labCellIndex->setMinimumWidth(100);
	QFont font3("Times New Roman", 12, 75);
	labCellIndex->setFont(font3);
	labCellType = new QLabel("CPU使用率:", this);
	labCellType->setMinimumWidth(100);
	labCellType->setFont(font3);
	labStudID = new QLabel("内存使用率:", this);
	labStudID->setMinimumWidth(100);
	labStudID->setFont(font3);
	labStg = new QLabel("硬盘使用率:", this);
	labStg->setMinimumWidth(100);
	labStg->setFont(font3);
	pProgressBar1->setRange(0, 100);
	pProgressBar1->setFont(font3);
	pProgressBar2->setRange(0, 100);
	pProgressBar2->setFont(font3);
	pProgressBar3->setRange(0, 100);
	pProgressBar3->setFont(font3);
	// 将初始化的标签添加到底部状态栏上
	ui.statusBar->addWidget(labCellType);
	ui.statusBar->addWidget(pProgressBar1);
	ui.statusBar->addWidget(labStudID);
	ui.statusBar->addWidget(pProgressBar2);
	ui.statusBar->addWidget(labStg);
	ui.statusBar->addWidget(pProgressBar3);
	ui.statusBar->addPermanentWidget(labCellIndex);//添加到状态栏的右边


	char buffer[256];
	_getcwd(buffer, 256);
	std::string currentPath = buffer;
	projectdir = QString::fromStdString(currentPath + "\\config");
	projectdirTemp = projectdir;
	//判断projectdir文件夹下是否有文件或文件夹,若存在删除所有文件及文件夹
	QDir dir(projectdir);
	if (dir.exists()) {
		dir.setFilter(QDir::Files | QDir::NoSymLinks);
		QFileInfoList fileList = dir.entryInfoList();
		for (int i = 0; i < fileList.size(); i++) {
			QFileInfo file = fileList.at(i);
			QString fileName = file.fileName();

				dir.remove(fileName);
			
		}
		//dir.setFilter(QDir::Dirs | QDir::NoSymLinks);
		//QFileInfoList fileList2 = dir.entryInfoList();
		//for (int i = 0; i < fileList2.size(); i++) {
		//	QFileInfo file = fileList2.at(i);
		//	QString fileName = file.fileName();

		//		dir.remove(fileName);
		//	
		//}
	}
	else {
		dir.mkpath(projectdir);
	}
	projectdlg->loadProcesses(projectdir.toStdString());
}

QtToolTest::~QtToolTest()
{}

void QtToolTest::closeEvent(QCloseEvent* e){
	if (projectdir == projectdirTemp)
	{
		QMessageBox::StandardButton result=QMessageBox::information(this, "提示", "配方未保存，是否进行保存!", QMessageBox::Cancel|QMessageBox::Ok);
		if (result == QMessageBox::Ok) {
			on_pushButton_saveProject_clicked();
		}
	}
}

bool QtToolTest::GetSysDisk(double& nDiskTotal, double& nDiskUsed)
{
	static char path[_MAX_PATH];//存储当前系统存在的盘符
	int curdrive = _getdrive();
	unsigned long lFreeAll = 0UL;
	unsigned long lTotalAll = 0UL;
	//for (int drive = 1; drive <= 26; drive++)//遍历所有盘符
	//{
		/*if (!_chdrive(2))
		{*/
	sprintf(path, "%c:\\", 2 + 'C');
	ULARGE_INTEGER caller, total, free;
	WCHAR wszClassName[_MAX_PATH];
	memset(wszClassName, 0, sizeof(wszClassName));
	MultiByteToWideChar(CP_ACP, 0, path, strlen(path) + 1, wszClassName,
		sizeof(wszClassName) / sizeof(wszClassName[0]));
	if (GetDiskFreeSpaceEx(wszClassName, &caller, &total, &free) == 0)
	{
		qDebug() << "GetDiskFreeSpaceEx Filed!";
		return false;
	}

	double dTepFree = free.QuadPart / (1024.0*1024.0*1024.0);
	double dTepTotal = total.QuadPart / (1024.0*1024.0*1024.0);
	//qDebug()<<"Get Windows Disk Information:"<<path<<"--free:"<<dTepFree<<"--total:"<<dTepTotal;
	lFreeAll += (unsigned long)ceil(dTepFree);
	lTotalAll += (unsigned long)ceil(dTepTotal);
	//}
//}
	nDiskUsed = lFreeAll;
	nDiskTotal = lTotalAll;
	return true;
}
bool QtToolTest::GetMemUsage(double &nMemTotal, double &nMemUsed)
{
	MEMORYSTATUSEX memsStat;
	memsStat.dwLength = sizeof(memsStat);
	if (!GlobalMemoryStatusEx(&memsStat))//如果获取系统内存信息不成功，就直接返回
	{
		return false;
	}
	double nMemFree = memsStat.ullAvailPhys / (1024.0*1024.0);
	nMemTotal = memsStat.ullTotalPhys / (1024.0*1024.0);
	nMemUsed = nMemTotal - nMemFree;
	return true;
}
int QtToolTest::getCpu()
{
	// FILETIME 是一个用两个32位字节表示时间值的结构体
	//  dwLowDateTime 低位32位时间值。
	//  dwHighDateTime 高位32位时间值
	static FILETIME preidleTime;
	static FILETIME prekernelTime;
	static FILETIME preuserTime;

	FILETIME idleTime;
	FILETIME kernelTime;
	FILETIME userTime;

	// 三个参数分别为 cpu空闲时间 内核进程占用时间 用户进程占用时间
	// 函数执行成功返回true 执行失败返回false
	bool k = GetSystemTimes(&idleTime, &kernelTime, &userTime);
	//qDebug() << "GetSystemTimes:" << k;
	if (!k)
		return 0;

	quint64 x, y;
	qint64 idle = 0, kernel = 0, user = 0;

	x = (preidleTime.dwHighDateTime << 31) | preidleTime.dwLowDateTime;
	y = (idleTime.dwHighDateTime << 31) | idleTime.dwLowDateTime;
	idle = y - x;

	x = (prekernelTime.dwHighDateTime << 31) | prekernelTime.dwLowDateTime;
	y = (kernelTime.dwHighDateTime << 31) | kernelTime.dwLowDateTime;
	kernel = y - x;

	x = (preuserTime.dwHighDateTime << 31) | preuserTime.dwLowDateTime;
	y = (userTime.dwHighDateTime << 31) | userTime.dwLowDateTime;
	user = y - x;

	int cpuPercent = (kernel + user - idle) * 100 / (kernel + user);

	//preidleTime = idleTime;
	//prekernelTime = kernelTime;
	//preuserTime = userTime;
	//QString msg = QString("CPU使用率 : %1%").arg(cpuPercent);
	return cpuPercent;
}

void QtToolTest::timerUpDate()
{
	QDateTime time = QDateTime::currentDateTime();
	//获取系统现在的时间
	QString str = time.toString("yyyy-MM-dd hh:mm:ss dddd");
	//设置系统时间显示格式
	labCellIndex->setText(str);//在标签上显示时间

	labCellType->setText("CPU使用率:");
	pProgressBar1->setValue(getCpu());
	double nMemTotal; double nMemUsed;
	GetMemUsage(nMemTotal, nMemUsed);
	//labStudID->setText("内存使用率 : "+QString::number(nMemUsed/ nMemTotal*100, 'f', 1) + "%" );
	pProgressBar2->setValue(nMemUsed / nMemTotal * 100);
	double nDiskTotal; double nDiskUsed;
	GetSysDisk(nDiskTotal, nDiskUsed);
	//labStg->setText("硬盘使用率 : " + QString::number( nDiskUsed/nDiskTotal*100 , 'f', 1) + "%");
	pProgressBar3->setValue((nDiskTotal - nDiskUsed) / nDiskTotal * 100);
}
void QtToolTest::GetprojectPath(QString value)
{
	projectdir = value;
}
void QtToolTest::getmessage(QString value)
{
	QString currenttime = (QDateTime::currentDateTime()).toString("yyyy.MM.dd hh:mm:ss");
	ui.plainTextEdit->appendPlainText(currenttime + ": " + value);
}
void  QtToolTest::on_pushButton_openProject_clicked()
{
	projectdir  = QFileDialog::getExistingDirectory();
	if (projectdir != "")
	{
		getmessage("方案打开成功,请点击运行按钮!");
		projectdlg->loadProcesses(projectdir.toStdString());
	}
}
void  QtToolTest::on_pushButton_saveProject_clicked()
{
	QString directnary;
	projectdlg->saveProcesses();
	if (projectdir == projectdirTemp){
		directnary = QFileDialog::getExistingDirectory();
		if (!directnary.isNull()) {
			QDir dir(directnary);
			if (dir.exists()) {
				copyDirectory(projectdir, directnary, true);
				getmessage("方案保存成功!");
			}
		}
		else {
			getmessage("未选择保存路径!");
		}
	}
	else{
		getmessage("方案保存成功!");
	}
}
//(源文件目录路劲，目的文件目录，文件存在是否覆盖)
bool QtToolTest::copyDirectory(const QString& srcPath, const QString& dstPath, bool coverFileIfExist)
{
	QDir srcDir(srcPath);
	QDir dstDir(dstPath);
	if (!dstDir.exists()) { //目的文件目录不存在则创建文件目录
		if (!dstDir.mkdir(dstDir.absolutePath()))
			return false;
	}
	QFileInfoList fileInfoList = srcDir.entryInfoList();
	foreach(QFileInfo fileInfo, fileInfoList) {
		if (fileInfo.fileName() == "." || fileInfo.fileName() == "..")
			continue;

		if (fileInfo.isDir()) {    // 当为目录时，递归的进行copy 
			if (!copyDirectory(fileInfo.filePath(), dstDir.filePath(fileInfo.fileName()), coverFileIfExist))
				return false;
		}
		else {            //当允许覆盖操作时，将旧文件进行删除操作 
			if (coverFileIfExist && dstDir.exists(fileInfo.fileName())) {
				dstDir.remove(fileInfo.fileName());
			}
			/// 进行文件copy
			if (!QFile::copy(fileInfo.filePath(), dstDir.filePath(fileInfo.fileName()))) {
				return false;
			}
		}
	}
	return true;
}
void QtToolTest::on_toolButton_dataCheck_clicked()
{
	//SQLite1->searchAllRecord(projectName, flowNumber);
	//SQLite1->show();

}
void QtToolTest::on_toolButton_Edit_clicked()
{
	if (ui.lineEdit_title->isReadOnly() == true)
	{
		ui.lineEdit_title->setReadOnly(false);
	}
	else
	{
		ui.lineEdit_title->setReadOnly(true);
	}
	getmessage("方案名称修改完成!");
}
void QtToolTest::on_toolButton_reSet_clicked()
{
	NGNumber = 0;
	AllNumber = 0;
	ui.label_OKrate->setText("0%");
	ui.label_NG->setText("0");
	ui.label_AllCount->setText("0");
	ui.label_costTime->setText("0");
	for (int i = 0; i < list_CountNumber.length(); i++)
	{
		list_CountNumber[i]->setText("0");
		list_CostTime[i]->setText("0");
	}
	InitializeChart();
	getmessage("数据清空完成!");
}
void QtToolTest::InitializeChart()
{
	chart = new QChart();
	mAxY = new QValueAxis();
	mAxX = new QValueAxis();
	mLineSeries = new QLineSeries();
	mLineSeries2 = new QLineSeries();
	////y轴范围
	mAxY->setRange(80, 100);
	// Y轴分等份
	mAxY->setTickCount(10);
	mAxX->setRange(0, 100);
	//mAxX->setTickCount(100);
	// 将系列添加到图表
	chart->addSeries(mLineSeries);
	chart->addSeries(mLineSeries2);
	chart->setTheme(QtCharts::QChart::ChartThemeBrownSand);
	mAxX->setTitleText(QString(tr("检测总数 ")));
	mAxY->setTitleText(QString(tr("合格率(%)")));
	chart->addAxis(mAxY, Qt::AlignLeft);
	chart->addAxis(mAxX, Qt::AlignBottom);
	mLineSeries->attachAxis(mAxY);
	mLineSeries->attachAxis(mAxX);
	mLineSeries->setColor(QColor(0, 255, 0));
	mLineSeries->setName("合格率");
	mLineSeries2->attachAxis(mAxY);
	mLineSeries2->attachAxis(mAxX);
	mLineSeries2->setColor(QColor(255, 0, 0));
	mLineSeries2->setName("最低合格率预警");
	//隐藏背景
	chart->setBackgroundVisible(false);
	//设置外边界全部为0
	chart->setContentsMargins(0, 0, 0, 0);
	//设置内边界全部为0
	chart->setMargins(QMargins(0, 0, 0, 0));
	//设置背景区域无圆角
	chart->setBackgroundRoundness(0);
	//突出曲线上的点
	mLineSeries->setPointsVisible(true);
	mLineSeries2->setPointsVisible(true);
	chart->createDefaultAxes();
	chart->axisX()->setLabelsColor(QColor(255, 255, 255));
	chart->axisY()->setLabelsColor(QColor(255, 255, 255));
	// 将图表绑定到视图 wiget 为 QChartView
	ui.widget->setChart(chart);
}
void QtToolTest::on_pushButton_camerasetting_clicked()
{
	//cameradlg->show();
}
void QtToolTest::on_pushButton_project_clicked()
{
	//projectdlg = new projectClass();
	if (projectdir == projectdirTemp)
		;
	if(projectdir=="")
	{
		QMessageBox::information(this, "提示", "未设置配置路径，请先设置!", QMessageBox::Ok);
	}
	else
	{
		projectdlg->show();
	}

}
void QtToolTest::on_toolButton_clicked()
{
	QtToolTest::showMinimized(); //最小化
}
void QtToolTest::on_toolButton_2_clicked()
{
	if (QtToolTest::isMaximized())
	{
		QtToolTest::showNormal();//还原事件
		//ui.toolButton_2->setIcon(QIcon(":/img/max.png"));
	}
	else
	{
		QtToolTest::showMaximized();//最大化事件
		//ui.toolButton_2->setIcon(QIcon(":/img/max.png"));
	}

}
void QtToolTest::on_toolButton_3_clicked()
{
	this->close();
}
void QtToolTest::mousePressEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton)
	{
		whereismouse = event->pos();
	}
}
void QtToolTest::mouseMoveEvent(QMouseEvent *event)
{
	if (event->buttons() == Qt::LeftButton)
	{
		//当窗口最大化或最小化时也不进行触发
		if (QtToolTest::isMaximized() || QtToolTest::isMinimized())
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
				QtToolTest::move(QtToolTest::mapToGlobal(event->pos() - whereismouse));//移动
			}
		}
	}
	event->accept();
}
void QtToolTest::DisplyRegion(int c, HObject ho_Image, HObject TempRoi)
{
	if (ho_Image.Key() == nullptr)
	{
		return;
	}
	int windowSize = list_Windows.size();
	if(c<= windowSize-1){
		MainWndIDTemp[c] = (Hlong)list_Windows[c]->winId();
		int labHeight = (Hlong)list_Windows[c]->height();
		int labWidth = (Hlong)list_Windows[c]->width();
		if (hv_WindowHandleTemp[c] != NULL) {
			CloseWindow(hv_WindowHandleTemp[c]);
		}
		GetImageSize(ho_Image, &hv_Width, &hv_Height);
		//求出QT显示图像窗口的大小然后绑定Halcon窗口
		OpenWindow(0, 0, (Hlong)labWidth, (Hlong)labHeight, MainWndIDTemp[c], "visible", "", &hv_WindowHandleTemp[c]);
		HDevWindowStack::Push(hv_WindowHandleTemp[c]);
		SetPart(hv_WindowHandleTemp[c], 0, 0, hv_Height - 1, hv_Width - 1);
		if (HDevWindowStack::IsOpen()) {
			HObject backImage;
			GenImageConst(&backImage, "byte", labWidth, labHeight);
			DispObj(backImage, hv_WindowHandleTemp[c]);
		}
		//获取缩放系数
		TupleMin2(1.0 * labWidth / hv_Width, 1.0 * labHeight / hv_Height, &m_hvScaledRate);
		//缩放图像
		ZoomImageFactor(ho_Image, &m_hResizedImg, m_hvScaledRate, m_hvScaledRate, "constant");
		//获取缩放后的大小
		GetImageSize(m_hResizedImg, &m_scaledWidth, &m_scaledHeight);
		//打开窗口
		if (1.0 * labWidth / hv_Width < 1.0 * labHeight / hv_Height) {
			SetWindowExtents(hv_WindowHandleTemp[c], labHeight / 2.0 - m_scaledHeight / 2.0, 0, labWidth, m_scaledHeight);
		}
		else {
			SetWindowExtents(hv_WindowHandleTemp[c], 0, labWidth / 2.0 - m_scaledWidth / 2.0, m_scaledWidth, labHeight);

		}
		SetColor(hv_WindowHandleTemp[c], "green");
		SetLineWidth(hv_WindowHandleTemp[c], 2);
		SetDraw(hv_WindowHandleTemp[c], "margin");
		if (HDevWindowStack::IsOpen()) {
			DispObj(ho_Image, hv_WindowHandleTemp[c]);
			DispObj(TempRoi, hv_WindowHandleTemp[c]);
		}
	}
	
}

struct resultInformation {
	QLabel* resultLabel;
	QLabel* timeLabel;
	QLabel* countLabel;
};

std::map<int, resultInformation> resultInformationMap;

map<int, map<int, bool>> result;
int total=0;
int ngCount=0;
map<int, vector<int>> ngMap;

void QtToolTest::getResultInformation(int totalProcess,int labelIndex, HObject image, HObject region, bool isOK,int consume){

	setShowWidgets(totalProcess);
	DisplyRegion(labelIndex, image, region);
	int index = result[labelIndex].size();
	result[labelIndex][index] = isOK;
	int count2 = result[labelIndex].size();
	if (!isOK)
		ngMap[labelIndex].push_back(count2);
	int currentRunIDCount = 0;
	bool isNG = false;
	for (map<int, map<int, bool>>::iterator iter = result.begin();
		iter != result.end();
		iter++) {
		std::map<int, bool> processMapTemp = iter->second;
		for (map<int, bool>::iterator iter2 = processMapTemp.begin(); iter2 != processMapTemp.end();
			iter2++)
			if (iter2->first == index){
				currentRunIDCount++;
				if(!isOK)
					isNG= true;
			}

	}
	if (currentRunIDCount== totalProcess){  
		total++;
		int okRate = (int)((total - ngCount) * 100.0 / total);
		if(isNG)
			ngCount++;
		if (ngCount == 0)
			ui.label_OKrate->setText("100%");
		else
			ui.label_OKrate->setText((to_string(okRate) + "%").c_str());
		ui.label_NG->setText(to_string(ngCount).c_str());
		ui.label_AllCount->setText(to_string(total).c_str());
		SetData(total, okRate);
	}
	if(resultInformationMap[labelIndex].countLabel!=nullptr){
		resultInformationMap[labelIndex].countLabel->setText(QString::fromStdString(to_string(ngMap[labelIndex].size())));
		resultInformationMap[labelIndex].timeLabel->setText(QString::fromStdString(to_string(consume)));
		if (isOK) {
			resultInformationMap[labelIndex].resultLabel->setText("OK");
			resultInformationMap[labelIndex].resultLabel->setStyleSheet("color: rgb(0, 255, 0)");
		}
		else {
			resultInformationMap[labelIndex].resultLabel->setText("NG");
			resultInformationMap[labelIndex].resultLabel->setStyleSheet("color: rgb(255, 0, 0)");
		}
	}


}

void QtToolTest::getTotalTime(int totalTime){
	ui.label_costTime->setText(QString::fromStdString(to_string(totalTime)));
}

bool isInitedWindow = false;
void QtToolTest::setShowWidgets(int totalProcess){
	if(!isInitedWindow){
		isInitedWindow = true;
		if(totalProcess<=2)
			addWindows(1, 2);
		else if(totalProcess<=4)
			addWindows(2, 2);
		else if(totalProcess<=6)
			addWindows(2, 3);
		else if(totalProcess<=9)
			addWindows(3, 3);
		else if(totalProcess<=12)
			addWindows(3, 4);

		AddFlowTool(totalProcess+1);
	}

}

void QtToolTest::on_treeView1_doubleClicked()
{
}
void QtToolTest::SetData(int currentID, double OKRate) {
	////声明静态全局集合，存储每一个流程结果
	//static QList<QList<QString> > list_allresult_;
	//if (RunCount == 0)
	//{
	//	list_allresult_.clear();
	//	for (int i = 0; i < flowNumber; i++)
	//	{
	//		QList<QString> list_allresultTemp;
	//		list_allresult_.append(list_allresultTemp);
	//	}

	//	RunCount += 1;
	//}
	////把每个流程结果添加到集合
	//list_allresult_[count1].append(value);

	////判断每一个流程的集合Size个数是否为0
	//int ListSizeNull = 0;
	//for (int i = 0; i < list_allresult_.size(); i++)
	//{
	//	if (list_allresult_[i].size() == 0)
	//	{
	//		ListSizeNull += 1;
	//	}
	//}
	//所有的流程集合Size都不等于0的时候执行判断
	//if (ListSizeNull == 0)
	//{
		//AllNumber++;
		//int ngCount = 0;
		//for (int i = 0; i < list_allresult_.size(); i++)
		//{
		//	QString str1 = list_allresult_[i][0];
		//	list_result.append(str1);
		//	list_allresult_[i].removeAt(0);
		//	if (str1 != "OK")
		//	{
		//		ngCount += 1;
		//	}
		//}
		////SQLite1->insertRecord(flowNumber, projectName, list_result);
		//list_result.clear();
		//if (ngCount == 0)
		//{
		//	ui->label_result->setPixmap(QPixmap("./Resources/ok.png"));
		//	list_FlowToolResult[count1]->setStyleSheet("color: rgb(0, 255, 0)");
		//	list_FlowToolResult[count1]->setText("OK");
		//}
		//else
		//{
		//	ui->label_result->setPixmap(QPixmap("./Resources/ng.png"));
		//	list_FlowToolResult[count1]->setStyleSheet("color: rgb(255, 0, 0)");
		//	list_FlowToolResult[count1]->setText("NG");
		//	NGNumber++;
		//	ui->label_NG->setText(QString::number(NGNumber));
		//}
		//ui->label_AllCount->setText(QString::number(AllNumber));
		//double  a1 = AllNumber; double  a2 = NGNumber;
		//double  uiu = ((a1 - a2) / a1) * 100;
		//uiu正确率


	//ui.label_OKrate->setText(QString::number(OKRate, 'f', 1) + "%");
	chart->axisX()->setMax(currentID + 1);
	chart->axisX()->setMin(0);
	mLineSeries->append(currentID, OKRate);
	mLineSeries2->append(currentID, 95);


	//list_ALLCount[count1]++;
	//list_CountNumber[count1]->setText(QString::number(list_ALLCount[count1]));
}

void QtToolTest::SetTime(int count2, qint64 value)
{
	ui.label_costTime->setText(QString::number(value));
	list_CostTime[count2]->setText(QString::number(value));
}
void QtToolTest::on_pushButton_run_clicked()
{
	isInitedWindow = false;
	projectdlg->runProcessesContinuous(true);
}
void QtToolTest::on_pushButton_stop_clicked()
{
	projectdlg->runProcessesContinuous(false);
	RunCount = 0;
}

std::map<int ,QLabel*> labelMap;
void QtToolTest::addWindows(int HBoxLayout, int value)
{
	if (list_Windows.length() != 0)
	{
		QList<QLabel*> listLabel = ui.frame->findChildren<QLabel*>();//找出所有label控件
		foreach(QLabel *label, listLabel)
		{
			delete label;//删除label控件
		}
		QList<QHBoxLayout*> list1 = ui.frame->findChildren<QHBoxLayout*>();//找出所有label控件
		foreach(QHBoxLayout *label1, list1)
		{
			delete label1;
		}
		delete QVBoxLayout_image;
	}
	list_Windows.clear();
	labelMap.clear();
	int labelIndex = 0;
	QVBoxLayout_image = new QVBoxLayout();
	for (int j = 0; j < HBoxLayout; j++)
	{
		QHBoxLayout_image = new QHBoxLayout();

		for (int i = 0; i < value; i++)
		{
			label = new QLabel();
			label->setFrameStyle(QFrame::Panel | QFrame::Sunken);
			label->setAlignment(Qt::AlignBottom | Qt::AlignRight);
			label->setStyleSheet(QString("background-color:") + "black");
			list_Windows.append(label);
			QHBoxLayout_image->addWidget(label);
			labelMap[labelIndex++]= label;
		}
		QVBoxLayout_image->addLayout(QHBoxLayout_image);
	}
	ui.frame->setLayout(QVBoxLayout_image);
}
void QtToolTest::on_toolButton_WindowChange_clicked()
{

}


void QtToolTest::AddFlowTool(int value)
{
	QFrame *frame1;
	QVBoxLayout *QVBoxLayout_flow2 = new QVBoxLayout;
	QVBoxLayout_flow2->setMargin(0);
	QFrame *frame2 = new QFrame;
	for (int i = 1; i < value ; i++)
	{
		frame1 = new QFrame;
		QHBoxLayout *QHBoxLayout_flow1 = new QHBoxLayout;
		QHBoxLayout_flow1->setMargin(0);
		QHBoxLayout *QHBoxLayout_flow2 = new QHBoxLayout;
		QHBoxLayout_flow2->setMargin(0);
		QHBoxLayout *QHBoxLayout_flow3 = new QHBoxLayout;
		QHBoxLayout_flow3->setMargin(0);
		QVBoxLayout *QVBoxLayout_flow = new QVBoxLayout;
		QVBoxLayout_flow->setMargin(0);

		QLabel *labelTitle = new QLabel();
		labelTitle->setText("流程" + QString::number(i));
		labelTitle->setStyleSheet("color: rgb(255, 255, 0)");
		QFont font1("Microsoft YaHei", 12, 75);
		labelTitle->setFont(font1);

		QLabel *labelCount = new QLabel();
		labelCount->setFrameStyle(QFrame::Panel | QFrame::Sunken);
		labelCount->setAlignment(Qt::AlignBottom | Qt::AlignRight);
		labelCount->setText(tr("NG总数:"));
		labelCount->setStyleSheet("color: rgb(255, 255, 255)");
		QFont font2("Microsoft YaHei", 10, 75);
		labelCount->setFont(font2);
		QLabel *labelCountNumber = new QLabel();
		labelCountNumber->setText("0");
		resultInformationMap[i -1].countLabel = labelCountNumber;
		labelCountNumber->setStyleSheet("color: rgb(255, 255, 255)");
		list_CountNumber.append(labelCountNumber);
		list_ALLCount.append(0);//工具检测计数
		labelCountNumber->setFont(font2);
		QHBoxLayout_flow1->addWidget(labelCount);
		QHBoxLayout_flow1->addWidget(labelCountNumber);

		QLabel *labelCount1 = new QLabel();
		labelCount1->setText("耗时(ms):");
		labelCount1->setStyleSheet("color: rgb(255, 255, 255)");

		labelCount1->setFont(font2);
		QLabel *labelCountTime = new QLabel();
		labelCountTime->setText("0");
		resultInformationMap[i -1].timeLabel = labelCountTime;
		labelCountTime->setStyleSheet("color: rgb(255, 255, 255)");
		labelCountTime->setFont(font2);
		list_CostTime.append(labelCountTime);

		QHBoxLayout_flow2->addWidget(labelCount1);
		QHBoxLayout_flow2->addWidget(labelCountTime);

		QVBoxLayout_flow->addStretch();
		QVBoxLayout_flow->addWidget(labelTitle);
		QVBoxLayout_flow->addStretch();
		QVBoxLayout_flow->addLayout(QHBoxLayout_flow1);
		QVBoxLayout_flow->addStretch();
		QVBoxLayout_flow->addLayout(QHBoxLayout_flow2);
		QVBoxLayout_flow->addStretch();
		QVBoxLayout_flow->setSpacing(0);

		QLabel *labelimage = new QLabel();
		labelimage->setPixmap(QPixmap("./Resources/flow.png"));
		labelimage->setScaledContents(true);
		labelimage->setMaximumSize(QSize(70, 70));

		QLabel *labelresult = new QLabel();
		labelresult->setText("OK");
		resultInformationMap[i -1].resultLabel = labelresult;
		labelresult->setStyleSheet("color: rgb(0, 255, 0)");
		QFont font3("Times New Roman", 28, 75);
		labelresult->setFont(font3);
		list_FlowToolResult.append(labelresult);

		QHBoxLayout_flow3->addStretch();
		QHBoxLayout_flow3->addWidget(labelimage);
		QHBoxLayout_flow3->addStretch();
		QHBoxLayout_flow3->addLayout(QVBoxLayout_flow);
		QHBoxLayout_flow3->addStretch();
		QHBoxLayout_flow3->addWidget(labelresult);
		QHBoxLayout_flow3->addStretch();
		QHBoxLayout_flow3->setSpacing(20);

		frame1->setMaximumHeight(80);
		frame1->setStyleSheet(QString("background-color:") + "rgb(37, 52, 69)");
		frame1->setLayout(QHBoxLayout_flow3);

		if (value == 2)
		{
			QVBoxLayout_flow2->addWidget(frame1);
			if (i == 2)
			{
				QVBoxLayout_flow2->addStretch();
			}
		}
		else if (value == 1)
		{
			QVBoxLayout_flow2->addWidget(frame1);
			QVBoxLayout_flow2->addStretch();
		}
		else
		{
			QVBoxLayout_flow2->addWidget(frame1);
		}
	}
	frame2->setLayout(QVBoxLayout_flow2);
	ui.scrollArea->setWidget(frame2);
}
