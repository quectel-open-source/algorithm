#include "XmlClass2.h"
XmlClass2::XmlClass2(string Path)
{
	FilePath = Path;
}
XmlClass2::~XmlClass2()
{}

//function��create a xml file����XML�ļ�
//param��FilePath.c_str():xml�ļ�·��
//return��0,�ɹ�����0��ʧ��
int XmlClass2::CreateXML()
{
	try
	{
		// �ж�Ŀ¼���ļ��Ƿ���ڵı�ʶ��
		int mode = 0;
		if (_access(FilePath.c_str(), mode))
		{
			const char* declaration = "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?>";
			XMLDocument doc;
			doc.Parse(declaration);//�Ḳ��xml��������

			//�����������ʹ����������
			//XMLDeclaration* declaration=doc.NewDeclaration();
			//doc.InsertFirstChild(declaration);

			return doc.SaveFile(FilePath.c_str());
		}
		else
		{
			//xml�ļ��Ѵ���
			return 0;
		}
	}
	catch (...)
	{
		return 1;
	}
}

//����(stationId ����Id�� sectionName ���ڵ����ƣ�sectionId ���ڵ�Id, keyName �ӽڵ����ƣ�value ֵ )
//return��0 �ɹ�; �� 0 ʧ��
int XmlClass2::InsertXMLNode(const string& processId, const string& sectionName, const string& sectionId, const string& keyName, const string& value)
{
	try
	{
		//��ȡXML
		XMLDocument doc;
		if (doc.LoadFile(FilePath.c_str()) != 0)
		{
			cout << "load xml file failed" << endl;
			return 1;
		}

		int isNotExit_Process = 0;
		int isNotExit_Section = 0;
		//��ȡ��һ�����̽ڵ�
		XMLElement* StationNameNode = doc.FirstChildElement("config");
		if (StationNameNode == NULL)
		{
			//����������ƽڵ�
			XMLElement* stationNameNode = doc.NewElement("config");
			stationNameNode->SetAttribute("process", processId.c_str());//�������Id
			doc.InsertEndChild(stationNameNode);

			//���ģ��ڵ�
			XMLElement* SectionNode = doc.NewElement("node");
			SectionNode->SetAttribute("nodeName", sectionName.c_str());//�������nodeName
			SectionNode->SetAttribute("nodeProcessID", sectionId.c_str());//�������nodeProcessID

			//����ӽڵ㣬�������ӽڵ��ֵ
			XMLElement* keyNode = doc.NewElement(keyName.c_str());
			keyNode->InsertEndChild(doc.NewText(value.c_str()));

			//�ӽڵ���ӵ����ڵ�
			SectionNode->InsertEndChild(keyNode);

			//ģ��ڵ���ӵ��������ƽڵ�
			stationNameNode->InsertEndChild(SectionNode);

			//����
			return doc.SaveFile(FilePath.c_str());
		}
		else
		{
			//��ȡ����Id
			string IdTemp = StationNameNode->Attribute("process");
			while (IdTemp != processId)
			{
				//��ȡ��һ�����̽ڵ�
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
			//isNotExit_Process > 0˵��ָ�������̽ڵ㲻����
			if (isNotExit_Process > 0)
			{
				//����������ƽڵ�
				XMLElement* stationNameNode = doc.NewElement("config");
				stationNameNode->SetAttribute("process", processId.c_str());//�������Id
				doc.InsertEndChild(stationNameNode);

				//���ģ��ڵ�
				XMLElement* SectionNode = doc.NewElement("node");
				SectionNode->SetAttribute("nodeName", sectionName.c_str());//�������nodeName
				SectionNode->SetAttribute("nodeProcessID", sectionId.c_str());//�������nodeProcessID

				//����ӽڵ㣬�������ӽڵ��ֵ
				XMLElement* keyNode = doc.NewElement(keyName.c_str());
				keyNode->InsertEndChild(doc.NewText(value.c_str()));

				//�ӽڵ���ӵ����ڵ�
				SectionNode->InsertEndChild(keyNode);

				//ģ��ڵ���ӵ��������ƽڵ�
				stationNameNode->InsertEndChild(SectionNode);

				//����
				return doc.SaveFile(FilePath.c_str());
			}
			else
			{
				//��ȡ��һ��ģ��ڵ�
				XMLElement* SectionNode = StationNameNode->FirstChildElement("node");
				if (SectionNode == NULL)
				{
					return 1;
				}
				//��ȡģ������
				string nameTemp = SectionNode->Attribute("nodeName");
				//��ȡģ��Id
				IdTemp = SectionNode->Attribute("nodeProcessID");
				while (nameTemp != sectionName || IdTemp != sectionId)
				{
					//��ȡ��һ��ģ��ڵ�
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
				//isNotExit_Section > 0˵��ָ����ģ��ڵ㲻����
				if (isNotExit_Section > 0)
				{
					//���ģ��ڵ�
					XMLElement* SectionNode = doc.NewElement("node");
					SectionNode->SetAttribute("nodeName", sectionName.c_str());//�������nodeName
					SectionNode->SetAttribute("nodeProcessID", sectionId.c_str());//�������nodeProcessID

					//����ӽڵ㣬�������ӽڵ��ֵ
					XMLElement* keyNode = doc.NewElement(keyName.c_str());
					keyNode->InsertEndChild(doc.NewText(value.c_str()));

					//�ӽڵ���ӵ����ڵ�
					SectionNode->InsertEndChild(keyNode);

					//ģ��ڵ���ӵ��������ƽڵ�
					StationNameNode->InsertEndChild(SectionNode);

					//����
					return doc.SaveFile(FilePath.c_str());
				}
				else
				{
					//��ȡ�����ڵ㣬�ж��Ƿ����
					XMLElement* KeyNode = SectionNode->FirstChildElement(keyName.c_str());
					if (KeyNode == NULL)
					{
						//����ӽڵ㣬�������ӽڵ��ֵ
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
						//�ӽڵ���ӵ����ڵ�
						SectionNode->InsertEndChild(keyNode);

						//ģ��ڵ���ӵ��������ƽڵ�
						StationNameNode->InsertEndChild(SectionNode);

						//����
						return doc.SaveFile(FilePath.c_str());
					}
					else
					{
						//�޸��ӽڵ��ֵ
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
				
						//����
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
//��ȡָ���ڵ�����
ErrorCode_Xml XmlClass2::GetXMLValue(const string& processId, const string& sectionName, const string& sectionId, const string& keyName, string& value)
{
	try
	{
		//��ȡXML
		XMLDocument doc;
		if (doc.LoadFile(FilePath.c_str()) != 0)
		{
			cout << "load xml file failed" << endl;
			return nullFile_Xml;
		}

		//��ȡ��һ�����̽ڵ�
		XMLElement* StationNameNode = doc.FirstChildElement("config");
		if (StationNameNode == NULL)
		{
			return nullConfig_Xml;
		}
		//��ȡ����Id
		string IdTemp = StationNameNode->Attribute("process");
		while (IdTemp != processId)
		{
			//��ȡ��һ�����̽ڵ�
			StationNameNode = StationNameNode->NextSiblingElement("config");
			if (StationNameNode == NULL)
			{
				return nullProcess_Xml;
			}
			IdTemp = StationNameNode->Attribute("process");
		}

		//��ȡ��һ��ģ��ڵ�
		XMLElement* SectionNode = StationNameNode->FirstChildElement("node");
		if (SectionNode == NULL)
		{
			return nullNode_Xml;
		}
		//��ȡģ������
		string nameTemp = SectionNode->Attribute("nodeName");
		//��ȡģ��Id
		IdTemp = SectionNode->Attribute("nodeProcessID");
		while (nameTemp != sectionName || IdTemp != sectionId)
		{
			//��ȡ��һ��ģ��ڵ�
			SectionNode = SectionNode->NextSiblingElement("node");
			if (SectionNode == NULL)
			{
				return nullNodeNameOrID_Xml;
			}
			nameTemp = SectionNode->Attribute("nodeName");
			IdTemp = SectionNode->Attribute("nodeProcessID");
		}

		//��ȡ�����ڵ�
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

//ɾ�����ڵ���ָ���ӽڵ�
//return 0 OK,��0 NG
int XmlClass2::DeleteSection_Key(const string& processId, const string& sectionName, const string& sectionId, const string& keyName)
{
	try
	{
		//doc.DeleteNode(root);//ɾ��xml���нڵ�

		//��ȡXML
		XMLDocument doc;
		if (doc.LoadFile(FilePath.c_str()) != 0)
		{
			cout << "load xml file failed" << endl;
			return 1;
		}

		//��ȡ��һ�����̽ڵ�
		XMLElement* StationNameNode = doc.FirstChildElement("config");
		if (StationNameNode == NULL)
		{
			return 1;
		}

		//��ȡ����Id
		string IdTemp = StationNameNode->Attribute("process");
		while (IdTemp != processId)
		{
			//��ȡ��һ�����̽ڵ�
			StationNameNode = StationNameNode->NextSiblingElement("config");
			if (StationNameNode == NULL)
			{
				return 1;
			}
			IdTemp = StationNameNode->Attribute("process");
		}

		//��ȡ��һ��ģ��ڵ�
		XMLElement* SectionNode = StationNameNode->FirstChildElement("node");
		if (SectionNode == NULL)
		{
			return 1;
		}
		//��ȡģ������
		string nameTemp = SectionNode->Attribute("nodeName");
		//��ȡģ��Id
		IdTemp = SectionNode->Attribute("nodeProcessID");
		while (nameTemp != sectionName || IdTemp != sectionId)
		{
			//��ȡ��һ��ģ��ڵ�
			SectionNode = SectionNode->NextSiblingElement("node");
			if (SectionNode == NULL)
			{
				return 1;
			}
			nameTemp = SectionNode->Attribute("nodeName");
			IdTemp = SectionNode->Attribute("nodeProcessID");
		}

		//��ȡ�����ڵ�
		XMLElement* KeyNode = SectionNode->FirstChildElement(keyName.c_str());
		if (KeyNode == NULL)
		{
			return 1;
		}
		//ɾ��
		SectionNode->DeleteChild(KeyNode); //ɾ��ָ���ڵ�
		//SectionNode->DeleteChildren();//ɾ���ڵ�����к��ӽڵ�
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
//ɾ�����ڵ�����������ӽڵ�
//return 0 OK,��0 NG
int XmlClass2::DeleteSection_AllKeys(const string& processId, const string& sectionName, const string& sectionId)
{
	try
	{
		//��ȡXML
		XMLDocument doc;
		if (doc.LoadFile(FilePath.c_str()) != 0)
		{
			cout << "load xml file failed" << endl;
			return 1;
		}

		//��ȡ��һ�����̽ڵ�
		XMLElement* StationNameNode = doc.FirstChildElement("config");
		if (StationNameNode == NULL)
		{
			return 1;
		}

		//��ȡ����Id
		string IdTemp = StationNameNode->Attribute("process");
		while (IdTemp != processId)
		{
			//��ȡ��һ�����̽ڵ�
			StationNameNode = StationNameNode->NextSiblingElement("config");
			if (StationNameNode == NULL)
			{
				return 1;
			}
			IdTemp = StationNameNode->Attribute("process");
		}

		//��ȡ��һ��ģ��ڵ�
		XMLElement* SectionNode = StationNameNode->FirstChildElement("node");
		if (SectionNode == NULL)
		{
			return 1;
		}
		//��ȡģ������
		string nameTemp = SectionNode->Attribute("nodeName");
		//��ȡģ��Id
		IdTemp = SectionNode->Attribute("nodeProcessID");
		while (nameTemp != sectionName || IdTemp != sectionId)
		{
			//��ȡ��һ��ģ��ڵ�
			SectionNode = SectionNode->NextSiblingElement("node");
			if (SectionNode == NULL)
			{
				return 1;
			}
			nameTemp = SectionNode->Attribute("nodeName");
			IdTemp = SectionNode->Attribute("nodeProcessID");
		}
		//ɾ��
		SectionNode->DeleteChildren();//ɾ���ڵ�����к��ӽڵ�
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
//ɾ��XMLȫ������
//return 0 OK,��0 NG
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
