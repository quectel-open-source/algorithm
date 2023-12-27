#pragma once
#pragma execution_character_set("utf-8")

#include <iostream>
#include <vector>
#include <stdio.h>
#include <fstream>
#include <Halcon.h>
#include <halconcpp/HalconCpp.h>
#include <thread>
#include <string>
#include <mutex>
#include <io.h>
#include <direct.h>
#include "XmlClass2.h"
#include "dataDetect.h"


using namespace std;
using namespace HalconCpp;
class DataIO
{
public:
	DataIO();
	~DataIO();
	//保存一维码检测参数(runParams 一维码参数，processId 流程ID, sectionName 模块名称， sectionId 模块ID)
	int WriteParams_BarCode(const RunParamsStruct_BarCode &runParams, const string& processId, const string& sectionName, const string& sectionId);
	//读取一维码检测参数(runParams 一维码参数，processId 流程ID, sectionName 模块名称， sectionId 模块ID, value 输出读取到的值)
	ErrorCode_Xml ReadParams_BarCode(RunParamsStruct_BarCode &runParams, const string& processId, const string& sectionName, const string& sectionId);

	//保存一维码检测参数(runParams 一维码参数，processId 流程ID, sectionName 模块名称， sectionId 模块ID)
	int WriteParams_Camera(const RunParamsStruct_Camera& runParams, const string& processId, const string& sectionName, const string& sectionId);
	//读取一维码检测参数(runParams 一维码参数，processId 流程ID, sectionName 模块名称， sectionId 模块ID, value 输出读取到的值)
	ErrorCode_Xml ReadParams_Camera(RunParamsStruct_Camera& runParams, const string& processId, const string& sectionName, const string& sectionId);
private:
	//写日志函数
	int WriteTxt(string content);
	//返回一个不含strOld
	string strReplaceAll(const string& strResource, const string& strOld, const string& strNew);
	//按照指定字符分割字符串到vector
	void stringToken(const string sToBeToken, const string sSeperator, vector<string>& vToken);
private:
	//mutex mutex1;//参数设置的线程同步变量
	XmlClass2 *xmlC;//xml存取指针变量
	string configPath;
	string xmlPath;
	string LogPath;
	string FolderPath();
};

