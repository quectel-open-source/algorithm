#pragma once
#include <string>
#include <magic_enum.hpp>
#include "dataBase.h"

using namespace magic_enum;


class dataDataType {
public:
	static std::string typeToString(eDataType dataType);
	static eDataType stringToType(std::string dataType);
};

