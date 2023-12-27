#pragma once
#pragma execution_character_set("utf-8")

#include <iostream>
#include <vector>
#include <stdio.h>
#include <fstream>
#include <Halcon.h>
#include <halconCpp/HalconCpp.h>
#include <thread>
#include <mutex>
#include "DataIO.h"
#include "algorithmModuble.h"
#include "dataDetect.h"


using namespace std;
using namespace HalconCpp;


class  _declspec(dllexport) BarCodeDetect 
{
public:
	BarCodeDetect(std::string _nodeName, int _processModbuleID, int _processID, std::string xmlPath);
	BarCodeDetect();
	~BarCodeDetect();
	//ʶ������(OK����0��NG����1���㷨NG����-1)
	int FindBarCodeFunc(const HObject &ho_Image, const RunParamsStruct_BarCode &runParams, ResultParamsStruct_BarCode &resultParams);


private:
	//д��־����
	int WriteTxt(string content);
private:
	//����һ���߳������������߳�ͬ��
	//mutex mutex1;//����һά����߳�ͬ������


	DataIO dataIOC;
	std::string nodeName="";
	int processID=-1;
	int processModbuleID=-1;
	std::string XMLPath="";
};

