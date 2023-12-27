#include "dataDataType.h"

std::string dataDataType::typeToString(eDataType dataType) {
	auto type = enum_name(dataType);
	std::string result = type.data();
	return result;
}

eDataType dataDataType::stringToType(std::string dataType) {
	eDataType result = eDataType::Default;
	auto datatype = enum_cast<eDataType>(dataType);
	if (datatype.has_value())
		result = datatype.value();
	return result;
}