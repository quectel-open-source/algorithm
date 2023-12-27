#include "DataIO.h"
DataIO::DataIO()
{
	configPath = FolderPath() + "/Config/";
	xmlPath = FolderPath() + "/Config/Config.xml";

	// 判定目录或文件是否存在的标识符
	int mode = 0;
	if (_access(configPath.c_str(), mode))
	{
		//system("mkdir head");
		_mkdir(configPath.c_str());
	}

	//实例化XML类对象
	xmlC = new XmlClass2(xmlPath);
	int Ret = xmlC->CreateXML();
	if (Ret != 0)
	{
		WriteTxt("打开参数配置xml文件失败");
		delete xmlC;
		//mutex1.unlock();
		return;
	}
}

DataIO::~DataIO()
{
	delete xmlC;
}
//保存一维码检测参数
int DataIO::WriteParams_BarCode(const RunParamsStruct_BarCode &runParams, const string& processId, const string& sectionName, const string& sectionId)
{
	//mutex1.lock();
	try
	{
		//一维码参数保存
		//写入数组(数组按照逗号分割存储)
		int typeCount = runParams.hv_CodeType_Run.TupleLength().TupleInt().I();
		if (typeCount == 0)
		{
			WriteTxt("一维码类型为空，保存一维码检测参数失败");
			return 1;
		}

		if (typeCount == 1)
		{
			xmlC->InsertXMLNode(processId, sectionName, sectionId, "hv_CodeType_Run", runParams.hv_CodeType_Run.S().Text());
		}
		else
		{
			HTuple typeTemp = runParams.hv_CodeType_Run[0] + ",";
			for (int i = 1; i < typeCount; i++)
			{
				if (i == typeCount - 1)
				{
					typeTemp += runParams.hv_CodeType_Run[i];
				}
				else
				{
					typeTemp += runParams.hv_CodeType_Run[i] + ",";
				}
			}
			xmlC->InsertXMLNode(processId, sectionName, sectionId, "hv_CodeType_Run", typeTemp.S().Text());
		}
		//保存其余参数
		xmlC->InsertXMLNode(processId, sectionName, sectionId, "hv_CodeNum", to_string(runParams.hv_CodeNum.TupleInt().I()));
		xmlC->InsertXMLNode(processId, sectionName, sectionId, "hv_Tolerance", runParams.hv_Tolerance.S().Text());
		xmlC->InsertXMLNode(processId, sectionName, sectionId, "hv_HeadChar", runParams.hv_HeadChar.S().Text());
		xmlC->InsertXMLNode(processId, sectionName, sectionId, "hv_EndChar", runParams.hv_EndChar.S().Text());
		xmlC->InsertXMLNode(processId, sectionName, sectionId, "hv_ContainChar", runParams.hv_ContainChar.S().Text());
		xmlC->InsertXMLNode(processId, sectionName, sectionId, "hv_NotContainChar", runParams.hv_NotContainChar.S().Text());
		xmlC->InsertXMLNode(processId, sectionName, sectionId, "hv_CodeLength_Run", to_string(runParams.hv_CodeLength_Run.TupleInt().I()));
		xmlC->InsertXMLNode(processId, sectionName, sectionId, "hv_TimeOut", to_string(runParams.hv_TimeOut.TupleInt().I()));


		//保存运行区域
		if (runParams.ho_SearchRegion.Key() == nullptr)
		{
			//图像为空，或者图像被clear
			WriteTxt("条码搜索区域为空，保存失败");
		}
		else
		{
			HTuple PathRunRegion = HTuple(configPath.c_str()) + HTuple(processId.c_str()) + HTuple(sectionName.c_str()) + HTuple(sectionId.c_str()) + "_RunRegion.hobj";
			WriteRegion(runParams.ho_SearchRegion, PathRunRegion);
		}

		WriteTxt("一维码检测参数保存成功!");
		//mutex1.unlock();
		return 0;
	}
	catch (...)
	{
		WriteTxt("XML保存代码崩溃，一维码检测参数保存失败!");
		//mutex1.unlock();
		return -1;
	}
}
//读取一维码检测参数
ErrorCode_Xml DataIO::ReadParams_BarCode(RunParamsStruct_BarCode &runParams, const string& processId, const string& sectionName, const string& sectionId)
{
	//mutex1.lock();
	try
	{
		string valueXml;
		ErrorCode_Xml errorCode;
		int tempIntValue;
		double tempDoubleValue;
		//一维码检测参数读取
		//读取数组(数组按照逗号分割存储)
		errorCode = xmlC->GetXMLValue(processId, sectionName, sectionId, "hv_CodeType_Run", valueXml);
		if (errorCode != Ok_Xml)
		{
			WriteTxt("XML读取一维码检测参数失败");
			return errorCode;
		}
		vector<string> typeArray;
		stringToken(valueXml, ",", typeArray);
		runParams.hv_CodeType_Run.Clear();
		for (int i = 0; i < typeArray.size(); i++)
		{
			runParams.hv_CodeType_Run.Append(HTuple(typeArray[i].c_str()));
		}
		int typeCount = runParams.hv_CodeType_Run.TupleLength().TupleInt().I();
		if (typeCount == 0)
		{
			WriteTxt("一维码类型为空，读取一维码检测参数失败");
			return nullKeyName_Xml;
		}


		//读取其余参数
		errorCode = xmlC->GetXMLValue(processId, sectionName, sectionId, "hv_CodeNum", valueXml);
		if (errorCode != Ok_Xml)
		{
			WriteTxt("XML读取一维码检测参数失败");
			return errorCode;
		}
		xmlC->StrToInt(valueXml, tempIntValue);
		runParams.hv_CodeNum = tempIntValue;

		errorCode = xmlC->GetXMLValue(processId, sectionName, sectionId, "hv_Tolerance", valueXml);
		if (errorCode != Ok_Xml)
		{
			WriteTxt("XML读取一维码检测参数失败");
			return errorCode;
		}
		runParams.hv_Tolerance = HTuple(valueXml.c_str());

		errorCode = xmlC->GetXMLValue(processId, sectionName, sectionId, "hv_HeadChar", valueXml);
		if (errorCode != Ok_Xml)
		{
			WriteTxt("XML读取一维码检测参数失败");
			return errorCode;
		}
		runParams.hv_HeadChar = HTuple(valueXml.c_str());

		errorCode = xmlC->GetXMLValue(processId, sectionName, sectionId, "hv_EndChar", valueXml);
		if (errorCode != Ok_Xml)
		{
			WriteTxt("XML读取一维码检测参数失败");
			return errorCode;
		}
		runParams.hv_EndChar = HTuple(valueXml.c_str());

		errorCode = xmlC->GetXMLValue(processId, sectionName, sectionId, "hv_ContainChar", valueXml);
		if (errorCode != Ok_Xml)
		{
			WriteTxt("XML读取一维码检测参数失败");
			return errorCode;
		}
		runParams.hv_ContainChar = HTuple(valueXml.c_str());

		errorCode = xmlC->GetXMLValue(processId, sectionName, sectionId, "hv_NotContainChar", valueXml);
		if (errorCode != Ok_Xml)
		{
			WriteTxt("XML读取一维码检测参数失败");
			return errorCode;
		}
		runParams.hv_NotContainChar = HTuple(valueXml.c_str());

		errorCode = xmlC->GetXMLValue(processId, sectionName, sectionId, "hv_CodeLength_Run", valueXml);
		if (errorCode != Ok_Xml)
		{
			WriteTxt("XML读取一维码检测参数失败");
			return errorCode;
		}
		xmlC->StrToInt(valueXml, tempIntValue);
		runParams.hv_CodeLength_Run = tempIntValue;

		errorCode = xmlC->GetXMLValue(processId, sectionName, sectionId, "hv_TimeOut", valueXml);
		if (errorCode != Ok_Xml)
		{
			WriteTxt("XML读取一维码检测参数失败");
			return errorCode;
		}
		xmlC->StrToInt(valueXml, tempIntValue);
		runParams.hv_TimeOut = tempIntValue;

		//运行区域加载
		HTuple PathRunRegion = HTuple(configPath.c_str()) + HTuple(processId.c_str()) + HTuple(sectionName.c_str()) + HTuple(sectionId.c_str()) + "_RunRegion.hobj";
		HTuple isExist;
		FileExists(PathRunRegion, &isExist);
		if (isExist > 0)
		{
			ReadRegion(&runParams.ho_SearchRegion, PathRunRegion);
		}
		else
		{
			GenEmptyObj(&runParams.ho_SearchRegion);
			runParams.ho_SearchRegion.Clear();
		}


		WriteTxt("一维码检测参数读取成功!");
		//mutex1.unlock();
		return Ok_Xml;

	}
	catch (...)
	{
		WriteTxt("XML读取代码崩溃，一维码检测参数读取失败!");
		//mutex1.unlock();
		return nullUnKnow_Xml;
	}
}

int DataIO::WriteParams_Camera(const RunParamsStruct_Camera& runParams, const string& processId, const string& sectionName, const string& sectionId) {
	//mutex1.lock();
	try {

		//保存其余参数
		xmlC->InsertXMLNode(processId, sectionName, sectionId, "factory", runParams.factory);
		xmlC->InsertXMLNode(processId, sectionName, sectionId, "equipment", runParams.equipment);
		xmlC->InsertXMLNode(processId, sectionName, sectionId, "SN", runParams.SN);
		xmlC->InsertXMLNode(processId, sectionName, sectionId, "address", runParams.address);
		xmlC->InsertXMLNode(processId, sectionName, sectionId, "gain", to_string(runParams.gain));
		xmlC->InsertXMLNode(processId, sectionName, sectionId, "ExposureTime", to_string(runParams.ExposureTime));
		xmlC->InsertXMLNode(processId, sectionName, sectionId, "TriggerMode", to_string(runParams.TriggerMode));
		xmlC->InsertXMLNode(processId, sectionName, sectionId, "TriggerSource", to_string(runParams.TriggerSource));

		WriteTxt("一维码检测参数保存成功!");
		//mutex1.unlock();
		return 0;
	}
	catch (...) {
		WriteTxt("XML保存代码崩溃，一维码检测参数保存失败!");
		//mutex1.unlock();
		return -1;
	}
}
//读取一维码检测参数
ErrorCode_Xml DataIO::ReadParams_Camera(RunParamsStruct_Camera& runParams, const string& processId, const string& sectionName, const string& sectionId) {
	//mutex1.lock();
	try {
		string valueXml;
		ErrorCode_Xml errorCode;
		int tempIntValue;
		double tempDoubleValue;
		//一维码检测参数读取
		//读取数组(数组按照逗号分割存储)
		errorCode = xmlC->GetXMLValue(processId, sectionName, sectionId, "factory", valueXml);
		if (errorCode != Ok_Xml) {
			WriteTxt("XML读取一维码检测参数失败");
			return errorCode;
		}
		runParams.factory = valueXml;

		errorCode = xmlC->GetXMLValue(processId, sectionName, sectionId, "equipment", valueXml);
		if (errorCode != Ok_Xml) {
			WriteTxt("XML读取一维码检测参数失败");
			return errorCode;
		}
		runParams.equipment = valueXml;

		errorCode = xmlC->GetXMLValue(processId, sectionName, sectionId, "SN", valueXml);
		if (errorCode != Ok_Xml) {
			WriteTxt("XML读取一维码检测参数失败");
			return errorCode;
		}
		runParams.SN = valueXml;

		errorCode = xmlC->GetXMLValue(processId, sectionName, sectionId, "address", valueXml);
		if (errorCode != Ok_Xml) {
			WriteTxt("XML读取一维码检测参数失败");
			return errorCode;
		}
		runParams.address = valueXml;

		errorCode = xmlC->GetXMLValue(processId, sectionName, sectionId, "gain", valueXml);
		if (errorCode != Ok_Xml) {
			WriteTxt("XML读取一维码检测参数失败");
			return errorCode;
		}

		xmlC->StrToDouble(valueXml, tempDoubleValue);
		runParams.gain = tempDoubleValue;

		errorCode = xmlC->GetXMLValue(processId, sectionName, sectionId, "ExposureTime", valueXml);
		if (errorCode != Ok_Xml) {
			WriteTxt("XML读取一维码检测参数失败");
			return errorCode;
		}
		xmlC->StrToDouble(valueXml, tempDoubleValue);
		runParams.ExposureTime = tempDoubleValue;

		errorCode = xmlC->GetXMLValue(processId, sectionName, sectionId, "TriggerMode", valueXml);
		if (errorCode != Ok_Xml) {
			WriteTxt("XML读取一维码检测参数失败");
			return errorCode;
		}
		xmlC->StrToInt(valueXml, tempIntValue);
		runParams.TriggerMode = tempIntValue;

		errorCode = xmlC->GetXMLValue(processId, sectionName, sectionId, "TriggerSource", valueXml);
		if (errorCode != Ok_Xml) {
			WriteTxt("XML读取一维码检测参数失败");
			return errorCode;
		}
		xmlC->StrToInt(valueXml, tempIntValue);
		runParams.TriggerSource = tempIntValue;

		WriteTxt("一维码检测参数读取成功!");
		//mutex1.unlock();
		return Ok_Xml;

	}
	catch (...) {
		WriteTxt("XML读取代码崩溃，一维码检测参数读取失败!");
		//mutex1.unlock();
		return nullUnKnow_Xml;
	}
}



//写日志函数
int DataIO::WriteTxt(string content)
{
	if (content.empty())
	{
		return -1;
	}
	const char *p = content.c_str();
	ofstream in;
	in.open("D:\\AriLog.txt", ios::app); //ios::trunc表示在打开文件前将文件清空,由于是写入,文件不存在则创建
	in << p << "\r";
	in.close();//关闭文件
	return 0;
}
string DataIO::FolderPath()
{
	char strBuf[256] = { 0 };
	GetModuleFileNameA(NULL, strBuf, sizeof(strBuf));
	string strTemp = strBuf;
	if (strTemp.empty())
		return strTemp;

	strTemp = strReplaceAll(strTemp, "\\", "/");
	string::size_type pos = strTemp.rfind("/");
	if (string::npos != pos)
		strTemp = strTemp.substr(0, pos);
	else
		strTemp = "";

	return strTemp;
}

//返回一个不含strOld
string DataIO::strReplaceAll(const string& strResource, const string& strOld, const string& strNew)
{
	string::size_type pos = 0;
	string strTemp = strResource;
	do
	{
		if ((pos = strTemp.find(strOld)) != string::npos)
		{
			strTemp.replace(pos, strOld.length(), strNew);
		}
	} while (pos != string::npos);
	return strTemp;
}
//按照指定字符分割字符串到vector
void DataIO::stringToken(const string sToBeToken, const string sSeperator, vector<string>& vToken)
{
	string sCopy = sToBeToken;
	int iPosEnd = 0;
	while (true)
	{
		iPosEnd = sCopy.find(sSeperator);
		if (iPosEnd == -1)
		{
			vToken.push_back(sCopy);
			break;
		}
		vToken.push_back(sCopy.substr(0, iPosEnd));
		sCopy = sCopy.substr(iPosEnd + 1);
	}
}