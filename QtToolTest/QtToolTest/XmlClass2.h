#pragma once
#include <iostream>
#include "tinyxml2.h"
#include <string.h>
#include <string>
#include <io.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
using std::string;
using std::vector;
using std::map;
using std::ifstream;
using std::ofstream;
using std::endl;
using std::cout;
using std::stringstream;
using namespace tinyxml2;
using namespace std;

enum ErrorCode_Xml
{
	Ok_Xml,						//û�д���
	nullFile_Xml,				//Xml�ļ�·��������
	nullConfig_Xml,				//config�ڵ㲻����
	nullProcess_Xml,			//����ID��Process������
	nullNode_Xml,				//node�ڵ㲻����
	nullNodeNameOrID_Xml,		//ģ�����ƻ���ID��NodeNameOrID������
	nullKeyName_Xml,			//������KeyName��������
	nullUnKnow_Xml				//Catch��׽�Ĵ����п��������Բ����ڴ�����Catch
};
class XmlClass2
{
public:
	XmlClass2(string Path);
	~XmlClass2();
	//����XML�ļ�(xmlPath xml·��)
	int CreateXML();
	//����(processId ����Id�� sectionName ���ڵ����ƣ�sectionId ���ڵ�Id, keyName �ӽڵ����ƣ�value ֵ )
	int InsertXMLNode(const string& processId, const string& sectionName, const string& sectionId, const string& keyName, const string& value);
	//��ȡXML����(processId ����Id�� sectionName ���ڵ����ƣ�sectionId ���ڵ�Id, keyName �ӽڵ�����, value �����ȡ����ֵ)
	ErrorCode_Xml GetXMLValue(const string& processId, const string& sectionName, const string& sectionId, const string& keyName, string& value);
	//ɾ��ָ�������µ�ָ��ģ���ָ������
	int DeleteSection_Key(const string& processId, const string& sectionName, const string& sectionId, const string& keyName);
	//ɾ��ָ�������µ�ָ��ģ������в���
	int DeleteSection_AllKeys(const string& processId, const string& sectionName, const string& sectionId);
	//ɾ��XMLȫ������
	int DeleteXMLValue();
	//����ת��
	void StrToInt(const string&  str, int& num);
	void StrToDouble(const string&  str, double& num);
	void strToChar(const string&  str, char& num);
private:
	string FilePath;

};

