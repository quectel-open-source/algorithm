#pragma once
#include <string>

#include <Halcon.h>
#include <halconCpp/HalconCpp.h>
#include <functional>

struct ParamsStruct_Line {
	HTuple RowBegin;
	HTuple ColumnBegin;
	HTuple RowEnd;
	HTuple ColumnEnd;
};

struct ParamsStruct_Circle {
	HTuple Row;
	HTuple Column;
	HTuple Radius;
};

using namespace HalconCpp;

class  _declspec(dllexport) window {
public:
	void getSelectModubleData(int _processID, int _modubleID, std::string _modubleName,
		std::function<void(int processModubleID)> functionModubleID, HObject image1, std::string configPath);
	void setLine(double x1, double y1, double x2, double y2, int index);
	void setCircle(ParamsStruct_Circle circle2, int index);

private:

	ParamsStruct_Circle circle1;
	ParamsStruct_Circle circle2;
};

