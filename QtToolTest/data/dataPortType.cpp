#include "dataPortType.h"

std::string dataPortType::typeToString(ePortType type) {
	auto protType = enum_name(type);
	string result = protType.data();
	return result;
}