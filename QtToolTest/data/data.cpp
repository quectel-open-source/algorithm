#include "data.h"

#include <magic_enum.hpp>
#include <dataPortType.h>
#include <dataModubleType.h>
#include <dataDataType.h>

using namespace magic_enum;

std::string data::portTypeToString(ePortType portType){
	return dataPortType::typeToString(portType);
}

std::string data::modubleNameToString(eModubleType modubleType){
	return dataModubleType::nameToString(modubleType);
}

eModubleType data::stringToModubleName(std::string modubleType){
	return dataModubleType::stringToName(modubleType);
}

std::vector<std::string> data::getModubleNameList(){
	return dataModubleType::getNameList();
}

std::string data::dataTypeToString(eDataType dateType){
	return dataDataType::typeToString(dateType);
}

eDataType data::stringToDataType(std::string dateType){
	return dataDataType::stringToType(dateType);
}