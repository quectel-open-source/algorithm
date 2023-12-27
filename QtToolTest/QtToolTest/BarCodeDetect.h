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
	//识别条码(OK返回0，NG返回1，算法NG返回-1)
	int FindBarCodeFunc(const HObject &ho_Image, const RunParamsStruct_BarCode &runParams, ResultParamsStruct_BarCode &resultParams);


private:
	//写日志函数
	int WriteTxt(string content);
private:
	//声明一个线程锁，用于做线程同步
	//mutex mutex1;//查找一维码的线程同步变量


	DataIO dataIOC;
	std::string nodeName="";
	int processID=-1;
	int processModbuleID=-1;
	std::string XMLPath="";
};

