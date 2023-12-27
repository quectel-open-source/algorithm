#include "window.h"
#include <QtWidgets/qmessagebox.h>

void window::getSelectModubleData(int _processID, int _modubleID, std::string _modubleName,
	std::function<void(int processModubleID)> functionModubleID, HObject image1, std::string configPath) {
	int processID = _processID;
	int modubleID = _modubleID;
	ParamsStruct_Line line1;
	ParamsStruct_Line line2;
	eModubleType modubleName = data::stringToModubleName(_modubleName);
	switch (modubleName) {

	case eModubleType::Barcode:
		if (image1.Key() == nullptr) {
			QMessageBox::information(nullptr, "提示", "程序未运行，请运行后操作!", QMessageBox::Ok);
			break;
		}
		barcodeC = new BarcodeClass(image1, processID, modubleID, _modubleName, configPath, nullptr);
		barcodeC->show();
		break;

	case eModubleType::Image:
		Image = new ImageToolClass(_modubleName, modubleID, processID, configPath, nullptr);
		Image->show();
		break;

	case eModubleType::Camera:
		camera = new CameraClass(_modubleName, modubleID, processID, configPath);
		camera->show();
		break;

	case eModubleType::Line:
		if (image1.Key() == nullptr) {
			QMessageBox::information(nullptr, "提示", "程序未运行，请运行后操作!", QMessageBox::Ok);
			break;
		}
		lineW = new LineWindow(image1, processID, modubleID, _modubleName, configPath);
		lineW->show();
		break;

	case eModubleType::Circle:
		if (image1.Key() == nullptr) {
			QMessageBox::information(nullptr, "提示", "程序未运行，请运行后操作!", QMessageBox::Ok);
			break;
		}
		circleW = new CircleWindow(image1, processID, modubleID, _modubleName, configPath);
		circleW->show();
		break;

	case eModubleType::QRCode:
		if (image1.Key() == nullptr) {
			QMessageBox::information(nullptr, "提示", "程序未运行，请运行后操作!", QMessageBox::Ok);
			break;
		}
		qrcodeW = new QRCodeWindow(image1, processID, modubleID, _modubleName, configPath);
		qrcodeW->show();
		break;

	case eModubleType::Template:
		if (image1.Key() == nullptr) {
			QMessageBox::information(nullptr, "提示", "程序未运行，请运行后操作!", QMessageBox::Ok);
			break;
		}
		templateW = new TemplateWindow(image1, processID, modubleID, _modubleName, configPath);
		templateW->show();
		break;

	case eModubleType::Ellipse:
		if (image1.Key() == nullptr) {
			QMessageBox::information(nullptr, "提示", "程序未运行，请运行后操作!", QMessageBox::Ok);
			break;
		}
		ellipseW = new EllipseWindow(image1, processID, modubleID, _modubleName, configPath);
		ellipseW->show();
		break;

	case eModubleType::Rectangle:
		if (image1.Key() == nullptr) {
			QMessageBox::information(nullptr, "提示", "程序未运行，请运行后操作!", QMessageBox::Ok);
			break;
		}
		rectangleW = new RectangleWindow(image1, processID, modubleID, _modubleName, configPath);
		rectangleW->show();
		break;

	case eModubleType::IntersectionLL:
		if (image1.Key() == nullptr) {
			QMessageBox::information(nullptr, "提示", "程序未运行，请运行后操作!", QMessageBox::Ok);
			break;
		}


		line1.ColumnBegin = xA1;
		line1.RowBegin = yA1;
		line1.ColumnEnd = xA2;
		line1.RowEnd = YA2;
			
		line2.ColumnBegin = xB1;
		line2.RowBegin = yB1;
		line2.ColumnEnd = xB2;
		line2.RowEnd = YB2;

		intersectionLineLineW = new IntersectionLineLineWindow(image1, line1, line2);
		intersectionLineLineW->show();
		break;

	case eModubleType::IntersectionCC:
		if (image1.Key() == nullptr) {
			QMessageBox::information(nullptr, "提示", "程序未运行，请运行后操作!", QMessageBox::Ok);
			break;
		}
		intersectionCircleCircleW = new IntersectionCircleCircleWindow(image1, circle1, circle2);
		intersectionCircleCircleW->show();
		break;
	default:
		break;
	}
}

void window::setLine(double x1, double y1,double x2,double y2, int index) {
	if (index == 0){
		xA1 = x1;
		yA1 = y1;
		xA2 = x2;
		YA2 = y2;
	}


	else if (index == 1)
	{
		xB1 = x1;
		yB1 = y1;
		xB2 = x2;
		YB2 = y2;
	}

}

void window::setCircle(ParamsStruct_Circle circle, int index) {
	if (index == 0)
		this->circle1 = circle;
	else if (index == 1)
		this->circle2 = circle;
}