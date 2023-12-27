#pragma once
#include <string>
#include <Halcon.h>
#include <halconcpp/HalconCpp.h>

using namespace HalconCpp;

struct RunParamsStruct_Camera {
	std::string factory;
	std::string equipment;
	std::string SN;
	std::string address;

	float gain;
	float ExposureTime;
	int TriggerMode;
	int TriggerSource;
};

//一维码检测运行参数结构体
struct RunParamsStruct_BarCode {
	HObject ho_SearchRegion;					    //搜索区域
	HTuple hv_CodeType_Run;							//条码类型(默认"auto"，否则选择结构体CodeTypeStruct_BarCode里面的额参数),暂时不给默认值，因为增加条码类型的时候auto会在数组最前面，导致报错
	HTuple hv_CodeNum = 1;						    //识别数量(设置为0，则扫描所有条码)
	HTuple hv_Tolerance = "high";                   //识别容差(默认高级别，默认high，还可以设置"low")
	HTuple hv_HeadChar = "null";					    //特定字符开头
	HTuple hv_EndChar = "null";						    //特定字符结尾
	HTuple hv_ContainChar = "null";						//包含特定字符
	HTuple hv_NotContainChar = "null";					//不包含特定字符
	HTuple hv_CodeLength_Run = 2;               //条码最小长度
	HTuple hv_TimeOut = 50;						//超时时间(单位ms)
};

//条形码识别结果结构体
struct ResultParamsStruct_BarCode {
	//条码结果参数
	HTuple hv_CodeType_Result;         //条码类型
	HTuple hv_CodeContent;			  //条码内容
	HTuple hv_CodeLength_Result;	  //条码长度
	HObject ho_ContourBarCode;		  //条码轮廓
	HObject ho_RegionBarCode;		  //条码识别结果区域
	HTuple hv_Row;                    //条码中心行坐标
	HTuple hv_Column;                 //条码中心列坐标
	HTuple hv_RetNum = 0;			 //找到的条码个数(默认是0，识别到条码后大于0)

};


//条形码类型结构体
struct CodeTypeStruct_BarCode {
	HTuple CODE128 = "Code 128";
	HTuple CODE39 = "Code 39";
	HTuple CODE93 = "Code 93";
	HTuple EAN13 = "EAN-13";
	HTuple EAN8 = "EAN-8";
	HTuple ITF25 = "2/5 Industrial";
	HTuple UPCA = "UPC-A";
	HTuple UPCE = "UPC-E";
	HTuple CODABAR = "Codabar";
	HTuple PHARMACODE = "PharmaCode";
	HTuple AUTO = "auto";
};