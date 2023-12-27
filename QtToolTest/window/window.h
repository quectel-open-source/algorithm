#pragma once
#include <string>
#include <functional>
#include <Halcon.h>
#include <halconCpp/HalconCpp.h>
#include "../data/dataBase.h"
#include "../data/data.h"
#include "BarcodeClass.h"
#include "ImageToolClass.h"
#include "CameraClass.h"
#include "LineWindow.h"
#include "CircleWindow.h"
#include "QRCodeWindow.h"
#include "TemplateWindow.h"
#include "EllipseWindow.h"
#include "RectangleWindow.h"
#include "IntersectionLineLineWindow.h"
#include "IntersectionCircleCircleWindow.h"
#include "../detect/dataDetect.h"

using namespace HalconCpp;

class  _declspec(dllexport) window {

	BarcodeClass* barcodeC;
	ImageToolClass* Image;
	CameraClass* camera;
	LineWindow* lineW;
	CircleWindow *circleW;
	QRCodeWindow *qrcodeW;
	TemplateWindow *templateW;
	EllipseWindow *ellipseW;
	RectangleWindow *rectangleW;
	IntersectionLineLineWindow *intersectionLineLineW;
	IntersectionCircleCircleWindow *intersectionCircleCircleW;

	std::string configPath = "";
public:
	void getSelectModubleData(int _processID, int _modubleID, std::string _modubleName, 
		std::function<void(int processModubleID)> functionModubleID, HObject image1, std::string configPath);
	void setLine(double x1, double y1, double x2, double y2, int index);
	void setCircle(ParamsStruct_Circle circle2,int index);
private:

	double xA1, xA2, yA1, YA2, xB1, xB2, yB1, YB2;
	ParamsStruct_Circle circle1;
	ParamsStruct_Circle circle2;


};

