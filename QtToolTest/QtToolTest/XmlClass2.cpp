#include "XmlClass2.h"
XmlClass2::XmlClass2(string Path)
{
	FilePath = Path;
}
XmlClass2::~XmlClass2()
{}

//function：create a xml file创建XML文件
//param：FilePath.c_str():xml文件路径
//return：0,成功；非0，失败
int XmlClass2::CreateXML()
{
	try
	{
		// 判定目录或文件是否存在的标识符
		int mode = 0;
		if (_access(FilePath.c_str(), mode))
		{
			const char* declaration = "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?>";
			XMLDocument doc;
			doc.Parse(declaration);//会覆盖xml所有内容

			//添加申明可以使用如下两行
			//XMLDeclaration* declaration=doc.NewDeclaration();
			//doc.InsertFirstChild(declaration);

			return doc.SaveFile(FilePath.c_str());
		}
		else
		{
			//xml文件已存在
			return 0;
		}
	}
	catch (...)
	{
		return 1;
	}
}

//插入(stationId 流程Id， sectionName 父节点名称，sectionId 父节点Id, keyName 子节点名称，value 值 )
//return：0 成功; 非 0 失败
int XmlClass2::InsertXMLNode(const string& processId, const string& sectionName, const string& sectionId, const string& keyName, const string& value)
{
	try
	{
		//读取XML
		XMLDocument doc;
		if (doc.LoadFile(FilePath.c_str()) != 0)
		{
			cout << "load xml file failed" << endl;
			return 1;
		}

		int isNotExit_Process = 0;
		int isNotExit_Section = 0;
		//获取第一个流程节点
		XMLElement* StationNameNode = doc.FirstChildElement("config");
		if (StationNameNode == NULL)
		{
			//添加流程名称节点
			XMLElement* stationNameNode = doc.NewElement("config");
			stationNameNode->SetAttribute("process", processId.c_str());//添加属性Id
			doc.InsertEndChild(stationNameNode);

			//添加模块节点
			XMLElement* SectionNode = doc.NewElement("node");
			SectionNode->SetAttribute("nodeName", sectionName.c_str());//添加属性nodeName
			SectionNode->SetAttribute("nodeProcessID", sectionId.c_str());//添加属性nodeProcessID

			//添加子节点，并设置子节点的值
			XMLElement* keyNode = doc.NewElement(keyName.c_str());
			keyNode->InsertEndChild(doc.NewText(value.c_str()));

			//子节点添加到父节点
			SectionNode->InsertEndChild(keyNode);

			//模块节点添加到流程名称节点
			stationNameNode->InsertEndChild(SectionNode);

			//保存
			return doc.SaveFile(FilePath.c_str());
		}
		else
		{
			//获取流程Id
			string IdTemp = StationNameNode->Attribute("process");
			while (IdTemp != processId)
			{
				//获取下一个流程节点
				StationNameNode = StationNameNode->NextSiblingElement("config");
				if (StationNameNode == NULL)
				{
					isNotExit_Process += 1;
				}
				IdTemp = StationNameNode->Attribute("process");
				if (IdTemp == processId)
				{
					isNotExit_Process = 0;
				}
			}
			//isNotExit_Process > 0说明指定的流程节点不存在
			if (isNotExit_Process > 0)
			{
				//添加流程名称节点
				XMLElement* stationNameNode = doc.NewElement("config");
				stationNameNode->SetAttribute("process", processId.c_str());//添加属性Id
				doc.InsertEndChild(stationNameNode);

				//添加模块节点
				XMLElement* SectionNode = doc.NewElement("node");
				SectionNode->SetAttribute("nodeName", sectionName.c_str());//添加属性nodeName
				SectionNode->SetAttribute("nodeProcessID", sectionId.c_str());//添加属性nodeProcessID

				//添加子节点，并设置子节点的值
				XMLElement* keyNode = doc.NewElement(keyName.c_str());
				keyNode->InsertEndChild(doc.NewText(value.c_str()));

				//子节点添加到父节点
				SectionNode->InsertEndChild(keyNode);

				//模块节点添加到流程名称节点
				stationNameNode->InsertEndChild(SectionNode);

				//保存
				return doc.SaveFile(FilePath.c_str());
			}
			else
			{
				//获取第一个模块节点
				XMLElement* SectionNode = StationNameNode->FirstChildElement("node");
				if (SectionNode == NULL)
				{
					return 1;
				}
				//获取模块名称
				string nameTemp = SectionNode->Attribute("nodeName");
				//获取模块Id
				IdTemp = SectionNode->Attribute("nodeProcessID");
				while (nameTemp != sectionName || IdTemp != sectionId)
				{
					//获取下一个模块节点
					SectionNode = SectionNode->NextSiblingElement("node");
					if (SectionNode == NULL)
					{
						isNotExit_Section += 1;
						break;
					}
					else
					{
						nameTemp = SectionNode->Attribute("nodeName");
						IdTemp = SectionNode->Attribute("nodeProcessID");
						if (nameTemp == sectionName || IdTemp == sectionId) {
							isNotExit_Section = 0;
						}
					}

				}
				//isNotExit_Section > 0说明指定的模块节点不存在
				if (isNotExit_Section > 0)
				{
					//添加模块节点
					XMLElement* SectionNode = doc.NewElement("node");
					SectionNode->SetAttribute("nodeName", sectionName.c_str());//添加属性nodeName
					SectionNode->SetAttribute("nodeProcessID", sectionId.c_str());//添加属性nodeProcessID

					//添加子节点，并设置子节点的值
					XMLElement* keyNode = doc.NewElement(keyName.c_str());
					keyNode->InsertEndChild(doc.NewText(value.c_str()));

					//子节点添加到父节点
					SectionNode->InsertEndChild(keyNode);

					//模块节点添加到流程名称节点
					StationNameNode->InsertEndChild(SectionNode);

					//保存
					return doc.SaveFile(FilePath.c_str());
				}
				else
				{
					//获取参数节点，判断是否存在
					XMLElement* KeyNode = SectionNode->FirstChildElement(keyName.c_str());
					if (KeyNode == NULL)
					{
						//添加子节点，并设置子节点的值
						XMLElement* keyNode = doc.NewElement(keyName.c_str());
						string valueTemp;
						if (value == "" || value == "null")
						{
							valueTemp = "null";
						}
						else
						{
							valueTemp = value;
						}
						keyNode->InsertEndChild(doc.NewText(valueTemp.c_str()));
						//子节点添加到父节点
						SectionNode->InsertEndChild(keyNode);

						//模块节点添加到流程名称节点
						StationNameNode->InsertEndChild(SectionNode);

						//保存
						return doc.SaveFile(FilePath.c_str());
					}
					else
					{
						//修改子节点的值
						string valueTemp;
						if (value == "" || value == "null")
						{
							valueTemp = "null";
						}
						else
						{
							valueTemp = value;
						}
						KeyNode->SetText(valueTemp.c_str());
				
						//保存
						return doc.SaveFile(FilePath.c_str());
					}
				}
			}
		}
	}
	catch (...)
	{
		return -1;
	}
}
//读取指定节点内容
ErrorCode_Xml XmlClass2::GetXMLValue(const string& processId, const string& sectionName, const string& sectionId, const string& keyName, string& value)
{
	try
	{
		//读取XML
		XMLDocument doc;
		if (doc.LoadFile(FilePath.c_str()) != 0)
		{
			cout << "load xml file failed" << endl;
			return nullFile_Xml;
		}

		//获取第一个流程节点
		XMLElement* StationNameNode = doc.FirstChildElement("config");
		if (StationNameNode == NULL)
		{
			return nullConfig_Xml;
		}
		//获取流程Id
		string IdTemp = StationNameNode->Attribute("process");
		while (IdTemp != processId)
		{
			//获取下一个流程节点
			StationNameNode = StationNameNode->NextSiblingElement("config");
			if (StationNameNode == NULL)
			{
				return nullProcess_Xml;
			}
			IdTemp = StationNameNode->Attribute("process");
		}

		//获取第一个模块节点
		XMLElement* SectionNode = StationNameNode->FirstChildElement("node");
		if (SectionNode == NULL)
		{
			return nullNode_Xml;
		}
		//获取模块名称
		string nameTemp = SectionNode->Attribute("nodeName");
		//获取模块Id
		IdTemp = SectionNode->Attribute("nodeProcessID");
		while (nameTemp != sectionName || IdTemp != sectionId)
		{
			//获取下一个模块节点
			SectionNode = SectionNode->NextSiblingElement("node");
			if (SectionNode == NULL)
			{
				return nullNodeNameOrID_Xml;
			}
			nameTemp = SectionNode->Attribute("nodeName");
			IdTemp = SectionNode->Attribute("nodeProcessID");
		}

		//获取参数节点
		XMLElement* KeyNode = SectionNode->FirstChildElement(keyName.c_str());
		if (KeyNode == NULL)
		{
			return nullKeyName_Xml;
		}

		value = KeyNode->GetText();
		return Ok_Xml;
	}
	catch (...)
	{
		return nullUnKnow_Xml;
	}
}

//删除父节点下指定子节点
//return 0 OK,非0 NG
int XmlClass2::DeleteSection_Key(const string& processId, const string& sectionName, const string& sectionId, const string& keyName)
{
	try
	{
		//doc.DeleteNode(root);//删除xml所有节点

		//读取XML
		XMLDocument doc;
		if (doc.LoadFile(FilePath.c_str()) != 0)
		{
			cout << "load xml file failed" << endl;
			return 1;
		}

		//获取第一个流程节点
		XMLElement* StationNameNode = doc.FirstChildElement("config");
		if (StationNameNode == NULL)
		{
			return 1;
		}

		//获取流程Id
		string IdTemp = StationNameNode->Attribute("process");
		while (IdTemp != processId)
		{
			//获取下一个流程节点
			StationNameNode = StationNameNode->NextSiblingElement("config");
			if (StationNameNode == NULL)
			{
				return 1;
			}
			IdTemp = StationNameNode->Attribute("process");
		}

		//获取第一个模块节点
		XMLElement* SectionNode = StationNameNode->FirstChildElement("node");
		if (SectionNode == NULL)
		{
			return 1;
		}
		//获取模块名称
		string nameTemp = SectionNode->Attribute("nodeName");
		//获取模块Id
		IdTemp = SectionNode->Attribute("nodeProcessID");
		while (nameTemp != sectionName || IdTemp != sectionId)
		{
			//获取下一个模块节点
			SectionNode = SectionNode->NextSiblingElement("node");
			if (SectionNode == NULL)
			{
				return 1;
			}
			nameTemp = SectionNode->Attribute("nodeName");
			IdTemp = SectionNode->Attribute("nodeProcessID");
		}

		//获取参数节点
		XMLElement* KeyNode = SectionNode->FirstChildElement(keyName.c_str());
		if (KeyNode == NULL)
		{
			return 1;
		}
		//删除
		SectionNode->DeleteChild(KeyNode); //删除指定节点
		//SectionNode->DeleteChildren();//删除节点的所有孩子节点
		if (doc.SaveFile(FilePath.c_str()) == 0)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
	catch (...)
	{
		return -1;
	}
}
//删除父节点下面的所有子节点
//return 0 OK,非0 NG
int XmlClass2::DeleteSection_AllKeys(const string& processId, const string& sectionName, const string& sectionId)
{
	try
	{
		//读取XML
		XMLDocument doc;
		if (doc.LoadFile(FilePath.c_str()) != 0)
		{
			cout << "load xml file failed" << endl;
			return 1;
		}

		//获取第一个流程节点
		XMLElement* StationNameNode = doc.FirstChildElement("config");
		if (StationNameNode == NULL)
		{
			return 1;
		}

		//获取流程Id
		string IdTemp = StationNameNode->Attribute("process");
		while (IdTemp != processId)
		{
			//获取下一个流程节点
			StationNameNode = StationNameNode->NextSiblingElement("config");
			if (StationNameNode == NULL)
			{
				return 1;
			}
			IdTemp = StationNameNode->Attribute("process");
		}

		//获取第一个模块节点
		XMLElement* SectionNode = StationNameNode->FirstChildElement("node");
		if (SectionNode == NULL)
		{
			return 1;
		}
		//获取模块名称
		string nameTemp = SectionNode->Attribute("nodeName");
		//获取模块Id
		IdTemp = SectionNode->Attribute("nodeProcessID");
		while (nameTemp != sectionName || IdTemp != sectionId)
		{
			//获取下一个模块节点
			SectionNode = SectionNode->NextSiblingElement("node");
			if (SectionNode == NULL)
			{
				return 1;
			}
			nameTemp = SectionNode->Attribute("nodeName");
			IdTemp = SectionNode->Attribute("nodeProcessID");
		}
		//删除
		SectionNode->DeleteChildren();//删除节点的所有孩子节点
		if (doc.SaveFile(FilePath.c_str()) == 0)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
	catch (...)
	{
		return -1;
	}
}
//删除XML全部内容
//return 0 OK,非0 NG
int XmlClass2::DeleteXMLValue()
{
	try
	{
		XMLDocument doc;
		if (doc.LoadFile(FilePath.c_str()) != 0)
		{
			return 1;
		}
		doc.DeleteChildren();
		if (doc.SaveFile(FilePath.c_str()) == 0)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
	catch (const std::exception&)
	{
		return -1;
	}
}
void XmlClass2::StrToInt(const string&  str, int& num)
{
	stringstream stream;
	stream << str;
	stream >> num;
}

void XmlClass2::StrToDouble(const string&  str, double& num)
{
	stringstream stream;
	stream << str;
	stream >> num;
}

void XmlClass2::strToChar(const string&  str, char& num)
{
	stringstream stream;
	stream << str;
	stream >> num;
}
