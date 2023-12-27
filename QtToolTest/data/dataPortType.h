#pragma once
#include <string>
#include <magic_enum.hpp>
#include "dataBase.h"

using namespace magic_enum;

class dataPortType {
public:
	static std::string typeToString(ePortType type);
};

