#pragma once


enum class eDataType : int {
	//bool
	result,

	//double
	Width,
	Height,

	//HTuple
	WindowHandle,
	imagePath,
	outText,
	Row,
	Col,
	Row2,
	Col2,

	//HRegion
	outRegion,
	inRegion,

	//HObject
	outImage,
	inputImage,

	//HLine
	Line1,
	Line2,

	Circle1,
	Circle2,

	Default
};

enum class eModubleType : int {
	Camera,
	Barcode,
	Image,
	Threshold,
	Line,
	Circle,
	Ellipse,
	Rectangle,
	QRCode,
	Template,
	IntersectionLL,
	IntersectionCC,
	Default
};

enum class ePortType : int {
	String,
	Int,
	Double,
	HTuple,
	HImage,
	HRegion,
	HLine,
	HCircle,
};