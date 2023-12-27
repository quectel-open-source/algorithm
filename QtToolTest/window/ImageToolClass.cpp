#include "ImageToolClass.h"
#include <qtWidgets/QListWidgetItem>
#include <qtWidgets/QListWidget>
#include "../detect/tinyxml2.h"

ImageToolClass::ImageToolClass(std::string _nodeName, int _processModbuleID, int _processID, std::string xmlPath,QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	nodeName = _nodeName;
	processID = _processID;
	processModbuleID = _processModbuleID;
	setWindowFlags(Qt::FramelessWindowHint);//隐藏边框 
	code = QTextCodec::codecForName("GB2312");
	XMLPath = xmlPath + "\\config.xml";
}

ImageToolClass::~ImageToolClass()
{}

void ImageToolClass::on_toolButton_clicked()
{
	ImageToolClass::showMinimized(); //最小化
}
void ImageToolClass::on_toolButton_2_clicked()
{
	if (ImageToolClass::isMaximized())
	{
		ImageToolClass::showNormal();//还原事件
		//ui.toolButton_2->setIcon(QIcon(":/img/max.png"));
	}
	else
	{
		ImageToolClass::showMaximized();//最大化事件
		//ui.toolButton_2->setIcon(QIcon(":/img/max.png"));
	}

}
void ImageToolClass::on_toolButton_3_clicked() {
	tinyxml2::XMLDocument doc;
	int processCount = 0;
	int nodeCount = 0;


	//bool isExist = false;
	//tinyxml2::XMLDocument doc1;
	//doc1.LoadFile(XMLPath.c_str());
	//for (tinyxml2::XMLElement* node1 = doc1.FirstChildElement("config"); node1;
	//	node1 = node1->NextSiblingElement("config")) {
	//	if (atoi(node1->Attribute("process")) == processID) {
	//		isExist = true;
	//	}
	//}
	//if (!isExist) {
	//	tinyxml2::XMLElement* node1 = doc1.NewElement("config");
	//	node1->SetAttribute("process", processID);
	//	doc1.InsertEndChild(node1);
	//}
	//doc1.SaveFile(XMLPath.c_str());


	doc.LoadFile(XMLPath.c_str());
	for (tinyxml2::XMLElement* node1 = doc.FirstChildElement("config"); node1;
		node1 = node1->NextSiblingElement("config")) {
		int processIDTemp = atoi(node1->Attribute("process"));
		if (processIDTemp == processID) {
			processCount++;
			for (tinyxml2::XMLElement* node = node1->FirstChildElement(); node;
				node = node->NextSiblingElement()) {

				std::string name = node->Attribute("nodeName");

				int proceedID = atoi(node->Attribute("nodeProcessID"));
				if (name == nodeName && proceedID == processModbuleID) {
					//nodeCount++;
					//RunParams.hv_MatchMethod = HTuple(xmlC->GetXMLValue(RunParams.jobName, RunParams.toolName, "hv_MatchMethod").c_str());
					
					//遍历node节点下所有imageList,并进行删除

					for (tinyxml2::XMLElement* imageList = node->FirstChildElement(); imageList;
						) {
						tinyxml2::XMLElement* imageList1 = imageList->NextSiblingElement();
						node->DeleteChild(imageList);
						imageList= imageList1;
					}
					doc.SaveFile(XMLPath.c_str());
					break;
				}
			}
		}
	}
	tinyxml2::XMLElement* nodes;

	if (processCount == 0) {
		//插入节点process
		nodes = doc.NewElement("config");
		nodes->SetAttribute("process", processID);
		doc.InsertEndChild(nodes);
	}

	for (nodes = doc.FirstChildElement("config"); nodes;
		nodes = nodes->NextSiblingElement("config")) {
		int processIDTemp = atoi(nodes->Attribute("process"));
		if (processIDTemp == processID) {
			break;
		}
	}

	tinyxml2::XMLElement* process;
	for (process = nodes->FirstChildElement(); process;
		process = process->NextSiblingElement()) {
		std::string name = process->Attribute("nodeName");
		int proceedID = atoi(process->Attribute("nodeProcessID"));
		if (name == nodeName && proceedID == processModbuleID) {
			nodeCount++;
			break;
		}
	}

	if (nodeCount == 0) {
		//在process节点中插入nodeName节点
		process = doc.NewElement("node");
		process->SetAttribute("nodeName", nodeName.c_str());
		process->SetAttribute("nodeProcessID", processModbuleID);
		nodes->InsertEndChild(process);
	}
	//在node节点插入imageList节点


	for (size_t i = 0; i < imagelist.length(); i++) {
		tinyxml2::XMLElement* imageList2 = doc.NewElement("imageList");

		imageList2->SetAttribute("path", imagelist.at(i).absoluteFilePath().toStdString().c_str());
		process->InsertEndChild(imageList2);

	}
	std::string XMLPath1 = XMLPath.c_str();
	doc.SaveFile(XMLPath1.c_str());



	if (ui.radioButton_switchImage->isChecked()) {

	}
	else {


	}
	this->close();
}




void ImageToolClass::mousePressEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton)
	{
		whereismouse = event->pos();
	}
}
void ImageToolClass::mouseMoveEvent(QMouseEvent *event)
{
	if (event->buttons() == Qt::LeftButton)
	{
		//当窗口最大化或最小化时也不进行触发
		if (ImageToolClass::isMaximized() || ImageToolClass::isMinimized())
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
				ImageToolClass::move(ImageToolClass::mapToGlobal(event->pos() - whereismouse));//移动
			}
		}
	}
	event->accept();
}
void ImageToolClass::getmessage(QString value)
{
	QString currenttime = (QDateTime::currentDateTime()).toString("yyyy.MM.dd hh:mm:ss");
	QMessageBox::information(this, "提示", value, QMessageBox::Ok);
	//ui.plainTextEdit->appendPlainText(currenttime + ": " + value);

}
void ImageToolClass::Displyimage(HObject ho_Image)
{
	MainWndID = (Hlong)ui.label_image->winId();
	int labHeight = (Hlong)ui.label_image->height();
	int labWidth = (Hlong)ui.label_image->width();
	if (hv_WindowHandle != NULL)
	{
		CloseWindow(hv_WindowHandle);
	}
	GetImageSize(ho_Image, &hv_Width, &hv_Height);
	int uyuy = hv_Width / labHeight;
	//求出QT显示图像窗口的大小然后绑定Halcon窗口
	OpenWindow(0, 0, (Hlong)labWidth, (Hlong)labHeight, MainWndID, "visible", "", &hv_WindowHandle);
	HDevWindowStack::Push(hv_WindowHandle);
	//获取缩放系数
	TupleMin2(1.0 * labWidth / hv_Width, 1.0 * labHeight / hv_Height, &m_hvScaledRate);
	//缩放图像
	ZoomImageFactor(ho_Image, &m_hResizedImg, m_hvScaledRate, m_hvScaledRate, "constant");
	//获取缩放后的大小
	GetImageSize(m_hResizedImg, &m_scaledWidth, &m_scaledHeight);
	//打开窗口
	if (1.0 * labWidth / hv_Width < 1.0 * labHeight / hv_Height)
	{
		SetWindowExtents(hv_WindowHandle, labHeight / 2.0 - m_scaledHeight / 2.0, 0, labWidth, m_scaledHeight);
	}
	else
	{
		SetWindowExtents(hv_WindowHandle, 0, labWidth / 2.0 - m_scaledWidth / 2.0, m_scaledWidth, labHeight);

	}
	SetPart(hv_WindowHandle, 0, 0, hv_Height - 1, hv_Width - 1);
	if (HDevWindowStack::IsOpen())
	{
		////如果有图像，则先清空图像
		DetachBackgroundFromWindow(hv_WindowHandle);
		////这句显示图像，不会闪烁(把图像设置成窗口的背景图)
		AttachBackgroundToWindow(ho_Image, hv_WindowHandle);
		//DispObj(ho_Image, hv_WindowHandle);
	}
}
void ImageToolClass::on_btn_deleteImage_clicked()
{

	imagelist.removeAt(ui.listWidget->currentRow());
	QListWidgetItem *item1;
	item1 = ui.listWidget->currentItem();
	ui.listWidget->removeItemWidget(item1);
	delete item1;
	int bhgh = ui.listWidget->currentRow();
	ui.label_imageNumber->setText("图像源(" + QString::number(ui.listWidget->currentRow() + 1, 10) + " / " + QString::number(imagelist.size(), 10) + ")");
	std::string str = code->fromUnicode(imagelist.at(ui.listWidget->currentRow()).filePath());
	if (str != "")
	{
		ReadImage(&ho_Image, str.c_str());
		Displyimage(ho_Image);
		imageindex = imageindex - 1;
	}
	ho_Image.Clear();
}
void ImageToolClass::on_btn_openImage_clicked()
{
	QString filePath = QFileDialog::getOpenFileName(this, tr("选择图片"), ".", tr("Image Files(*.bmp *.jpg *.png *.jpeg)"));
	std::string str = code->fromUnicode(filePath).data();     // 中文路径也可读取

	if (str != "")
	{
		imagelist.append(filePath);
		ReadImage(&ho_Image, str.c_str());
		MainWndID = (Hlong)ui.label_image->winId();
		int labHeight = (Hlong)ui.label_image->height();
		int labWidth = (Hlong)ui.label_image->width();
		Displyimage(ho_Image);
		QPixmap pixmap(filePath);
		QListWidgetItem *listWidgetItem = new QListWidgetItem();
		//为单元项设置属性
		listWidgetItem->setIcon(QIcon(pixmap));
		listWidgetItem->setSizeHint(QSize(200, 170));
		ui.listWidget->insertItem(imagelist.size(), listWidgetItem);
		connect(ui.listWidget, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(slot_itemClicked(QListWidgetItem*)));
		QListWidgetItem *item = ui.listWidget->item(imagelist.size() - 1);
		item->setSelected(true);
		ui.label_imageNumber->setText("图像源(" + QString::number(imagelist.size(), 10) + "/ " + QString::number(imagelist.size(), 10) + ")");
		imageindex = imageindex + 1;
	}

}
void ImageToolClass::on_btn_imagefiles_clicked()
{
	imagelist.clear();
	ui.listWidget->clear();
	QString filePath = QFileDialog::getExistingDirectory(this, "请选择图片路径…", "./");
	if (filePath.size() == 0)
	{
		getmessage("未选择任何文件！");
		return;
	}
	QDir d(filePath);
	d.setFilter(QDir::NoDotAndDotDot | QDir::AllEntries);
	d.setSorting(QDir::Time | QDir::DirsFirst);
	QFileInfoList list = d.entryInfoList();

	for (int i = 0; i < list.size(); i++)
	{
		if (list.at(i).isFile())
		{
			if (list.at(i).suffix() == "bmp" | list.at(i).suffix() == "png" | list.at(i).suffix() == "jpg" | list.at(i).suffix() == "jpeg")
			{
				imagelist.append(filePath + "/" + list.at(i).fileName());
			}
		}
	}
	for (int i = 0; i < imagelist.size(); i++)
	{
		QPixmap pixmap(filePath + "/" + imagelist.at(i).fileName());
		QListWidgetItem *listWidgetItem = new QListWidgetItem();
		//为单元项设置属性
		listWidgetItem->setIcon(QIcon(pixmap));
		listWidgetItem->setSizeHint(QSize(200, 170));
		ui.listWidget->insertItem(i, listWidgetItem);
	}
	//QScroller::grabGesture(ui.listWidget, QScroller::LeftMouseButtonGesture);
	ui.listWidget->show();
	connect(ui.listWidget, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(slot_itemClicked(QListWidgetItem*)));

	imageindex = 0;
	if (imagelist.size() > 0)
	{
		ui.label_imageNumber->setText("图像源(" + QString::number(imageindex + 1, 10) + " / " + QString::number(imagelist.size()) + ")");
		QString filePath = imagelist.at(imageindex).filePath();
		std::string str = code->fromUnicode(filePath).data();     // 中文路径也可读取
		if (str != "")
		{
			ReadImage(&ho_Image, str.c_str());
			MainWndID = (Hlong)ui.label_image->winId();
			int labHeight = (Hlong)ui.label_image->height();
			int labWidth = (Hlong)ui.label_image->width();
			Displyimage(ho_Image);
		}
		QListWidgetItem *item = ui.listWidget->item(0);
		item->setSelected(true);
		ho_Image.Clear();
	}
	else
	{
		getmessage("未选择文件，请重新选择文件");
	}
}
void ImageToolClass::on_toolButton_provious_clicked()
{
	if (!imagelist.empty())
	{
		if (imageindex > 0 && imageindex <= imagelist.size())
		{
			QString filePath = imagelist.at(imageindex - 1).filePath();
			std::string str = code->fromUnicode(filePath).data();     // 中文路径也可读取
			if (str != "")
			{
				ReadImage(&ho_Image, str.c_str());
				MainWndID = (Hlong)ui.label_image->winId();
				int labHeight = (Hlong)ui.label_image->height();
				int labWidth = (Hlong)ui.label_image->width();
				Displyimage(ho_Image);
			}
			ho_Image.Clear();
			QListWidgetItem *item = ui.listWidget->item(imageindex - 1);
			item->setSelected(true);
			imageindex--;
		}
		ui.label_imageNumber->setText("图像源(" + QString::number(imageindex + 1, 10) + " / " + QString::number(imagelist.size(), 10) + ")");

	}
}
void ImageToolClass::on_toolButton_next_clicked()
{
	if (!imagelist.empty())
	{
		if (imageindex >= 0 && imageindex < imagelist.size() - 1)
		{
			QString filePath = imagelist.at(imageindex + 1).filePath();
			std::string str = code->fromUnicode(filePath).data();     // 中文路径也可读取
			if (str != "")
			{

				ReadImage(&ho_Image, str.c_str());
				MainWndID = (Hlong)ui.label_image->winId();
				int labHeight = (Hlong)ui.label_image->height();
				int labWidth = (Hlong)ui.label_image->width();
				Displyimage(ho_Image);

			}
			ho_Image.Clear();
			QListWidgetItem *item = ui.listWidget->item(imageindex + 1);
			item->setSelected(true);
			imageindex++;
		}
		ui.label_imageNumber->setText("图像源(" + QString::number(imageindex + 1, 10) + " / " + QString::number(imagelist.size(), 10) + ")");
	}

}
void ImageToolClass::slot_itemClicked(QListWidgetItem * item)
{
	QString filePath = imagelist.at(ui.listWidget->row(item)).filePath();
	std::string str = code->fromUnicode(filePath).data();     // 中文路径也可读取
	if (str != "")
	{
		ReadImage(&ho_Image, str.c_str());
		MainWndID = (Hlong)ui.label_image->winId();
		int labHeight = (Hlong)ui.label_image->height();
		int labWidth = (Hlong)ui.label_image->width();
		Displyimage(ho_Image);
	}
	ui.label_imageNumber->setText("图像源(" + QString::number(ui.listWidget->currentRow() + 1, 10) + " / " + QString::number(imagelist.size(), 10) + ")");
	imageindex = ui.listWidget->currentRow();
	ho_Image.Clear();

}