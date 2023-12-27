#pragma once

#include <string>
#include "dataBase.h"
#include <vector>

class __declspec(dllexport) data {
public:
	data();
	~data();

	static std::string portTypeToString(ePortType portType);

	static std::string modubleNameToString(eModubleType modubleType);

	static eModubleType stringToModubleName(std::string modubleType);

	static std::vector<std::string> getModubleNameList();

	static std::string dataTypeToString(eDataType dateType);

	static eDataType stringToDataType(std::string dateType);

private:

};