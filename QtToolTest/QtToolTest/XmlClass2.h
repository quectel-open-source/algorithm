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
	Ok_Xml,						//没有错误
	nullFile_Xml,				//Xml文件路径不存在
	nullConfig_Xml,				//config节点不存在
	nullProcess_Xml,			//流程ID，Process不存在
	nullNode_Xml,				//node节点不存在
	nullNodeNameOrID_Xml,		//模块名称或者ID，NodeNameOrID不存在
	nullKeyName_Xml,			//参数名KeyName，不存在
	nullUnKnow_Xml				//Catch捕捉的错误，有可能是属性不存在代码跳Catch
};
class XmlClass2
{
public:
	XmlClass2(string Path);
	~XmlClass2();
	//创建XML文件(xmlPath xml路径)
	int CreateXML();
	//插入(processId 流程Id， sectionName 父节点名称，sectionId 父节点Id, keyName 子节点名称，value 值 )
	int InsertXMLNode(const string& processId, const string& sectionName, const string& sectionId, const string& keyName, const string& value);
	//读取XML内容(processId 流程Id， sectionName 父节点名称，sectionId 父节点Id, keyName 子节点名称, value 输出读取到的值)
	ErrorCode_Xml GetXMLValue(const string& processId, const string& sectionName, const string& sectionId, const string& keyName, string& value);
	//删除指定流程下的指定模块的指定参数
	int DeleteSection_Key(const string& processId, const string& sectionName, const string& sectionId, const string& keyName);
	//删除指定流程下的指定模块的所有参数
	int DeleteSection_AllKeys(const string& processId, const string& sectionName, const string& sectionId);
	//删除XML全部内容
	int DeleteXMLValue();
	//数据转换
	void StrToInt(const string&  str, int& num);
	void StrToDouble(const string&  str, double& num);
	void strToChar(const string&  str, char& num);
private:
	string FilePath;

};

