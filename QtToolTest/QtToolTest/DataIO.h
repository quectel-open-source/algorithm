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
	//����һά�������(runParams һά�������processId ����ID, sectionName ģ�����ƣ� sectionId ģ��ID)
	int WriteParams_BarCode(const RunParamsStruct_BarCode &runParams, const string& processId, const string& sectionName, const string& sectionId);
	//��ȡһά�������(runParams һά�������processId ����ID, sectionName ģ�����ƣ� sectionId ģ��ID, value �����ȡ����ֵ)
	ErrorCode_Xml ReadParams_BarCode(RunParamsStruct_BarCode &runParams, const string& processId, const string& sectionName, const string& sectionId);

	//����һά�������(runParams һά�������processId ����ID, sectionName ģ�����ƣ� sectionId ģ��ID)
	int WriteParams_Camera(const RunParamsStruct_Camera& runParams, const string& processId, const string& sectionName, const string& sectionId);
	//��ȡһά�������(runParams һά�������processId ����ID, sectionName ģ�����ƣ� sectionId ģ��ID, value �����ȡ����ֵ)
	ErrorCode_Xml ReadParams_Camera(RunParamsStruct_Camera& runParams, const string& processId, const string& sectionName, const string& sectionId);
private:
	//д��־����
	int WriteTxt(string content);
	//����һ������strOld
	string strReplaceAll(const string& strResource, const string& strOld, const string& strNew);
	//����ָ���ַ��ָ��ַ�����vector
	void stringToken(const string sToBeToken, const string sSeperator, vector<string>& vToken);
private:
	//mutex mutex1;//�������õ��߳�ͬ������
	XmlClass2 *xmlC;//xml��ȡָ�����
	string configPath;
	string xmlPath;
	string LogPath;
	string FolderPath();
};

