#pragma once
#include <string>
#include <vector>
#include <magic_enum.hpp>
#include <dataBase.h>

using namespace magic_enum;



class dataModubleType {
public:
	//modubleNameö��תΪ�ַ���
	static std::string nameToString(eModubleType name);

	//modubleName�ַ���תΪö��

	static eModubleType stringToName(std::string name);

	static std::vector<std::string> getNameList();

};

