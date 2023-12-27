#include <dataModubleType.h>

std::string dataModubleType::nameToString(eModubleType name) {
	auto modubleType = enum_name(name);
	std::string result = modubleType.data();
	return result;
}

eModubleType dataModubleType::stringToName(std::string name) {
	eModubleType result = eModubleType::Default;
	auto color = enum_cast<eModubleType>(name);
	if (color.has_value())
		result = color.value();
	return result;
}

std::vector<std::string> dataModubleType::getNameList() {
	std::vector<eModubleType> modubleNameList;
	for (std::uint16_t i = 0; i < static_cast<std::uint16_t>(eModubleType::Default); ++i)
		modubleNameList.push_back(static_cast<eModubleType>(i));
	std::vector<std::string> result;
	for (auto modubleName : modubleNameList)
		result.push_back(nameToString(modubleName));
	return result;
}