#pragma once

#include <QObject>
#include <Halcon.h>
#include <halconcpp/HalconCpp.h>
#include <halconcpp/HDevThread.h>

#include<QTextCodec>

using namespace HalconCpp;

class drawroi  : public QObject
{
	Q_OBJECT

public:
	drawroi(QObject *parent);
	~drawroi();

	void draw(HObject ho_Image, HTuple m_hHalconID, QString RoiShape, HObject &TempRoi);
};
