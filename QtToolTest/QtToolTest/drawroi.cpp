#include "drawroi.h"

drawroi::drawroi(QObject *parent)
	: QObject(parent)
{}

drawroi::~drawroi()
{}
void drawroi::draw(HObject ho_Image,HTuple m_hHalconID,QString RoiShape, HObject &TempRoi)
{
	HObject  ho_EmptyObject;
	HTuple  hv_IsEqual;
	GenEmptyObj(&ho_EmptyObject);
	TestEqualObj(ho_EmptyObject, ho_Image, &hv_IsEqual);
	if ((!ho_Image.IsInitialized()) || (hv_IsEqual == 1))
	{
		//图像为空，或者图像被clear
		//QMessageBox::information(this, "提示", "图像是空，请先加载图像!", QMessageBox::Ok);
		return;
	}
	SetColor(m_hHalconID, "red");
	SetLineWidth(m_hHalconID, 1);
	if (RoiShape == "rectangle1")
	{
		HTuple RecRow1, RecCol1, RecRow2, RecCol2;
		DrawRectangle1(m_hHalconID, &RecRow1, &RecCol1, &RecRow2, &RecCol2);
		GenRectangle1(&TempRoi, RecRow1, RecCol1, RecRow2, RecCol2);
	}
	else if (RoiShape == "rectangle2")
	{
		HTuple RecRow, RecCol, RecPhi, RecLength1, RecLength2;
		DrawRectangle2(m_hHalconID, &RecRow, &RecCol, &RecPhi, &RecLength1, &RecLength2);
		GenRectangle2(&TempRoi, RecRow, RecCol, RecPhi, RecLength1, RecLength2);
	}
	else if (RoiShape == "circle")
	{
		HTuple CircleRow, CircleCol, CircleRadius;
		DrawCircle(m_hHalconID, &CircleRow, &CircleCol, &CircleRadius);
		GenCircle(&TempRoi, CircleRow, CircleCol, CircleRadius);
	}
	else if (RoiShape == "ellipse")
	{
		HTuple EllipseRow, EllipseCol, EllipsePhi, EllipseRadius1, EllipseRadius12;
		DrawEllipse(m_hHalconID, &EllipseRow, &EllipseCol, &EllipsePhi, &EllipseRadius1, &EllipseRadius12);
		GenEllipse(&TempRoi, EllipseRow, EllipseCol, EllipsePhi, EllipseRadius1, EllipseRadius12);
	}
	else if (RoiShape == "polygon")
	{
		DrawPolygon(&TempRoi, m_hHalconID);
	}
	else
	{
		//QMessageBox::information(this, "提示", "请选择区域形状!", QMessageBox::Ok);
	}


 }