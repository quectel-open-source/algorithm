#pragma once
#include <string>
#include <vector>
#include <magic_enum.hpp>
#include <dataBase.h>

using namespace magic_enum;



class dataModubleType {
public:
	//modubleName枚举转为字符串
	static std::string nameToString(eModubleType name);

	//modubleName字符串转为枚举

	static eModubleType stringToName(std::string name);

	static std::vector<std::string> getNameList();

};

