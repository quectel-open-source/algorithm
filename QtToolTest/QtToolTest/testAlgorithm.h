#pragma once

#include <Halcon.h>
#include <halconcpp/HalconCpp.h>
#include <functional>

using namespace HalconCpp;

static std::function<void(HObject, HObject, bool)> callbackResultData;
class testAlgorithm
{
public:
	std::string modubleName;
	int processModubleID;

	testAlgorithm();
	testAlgorithm(std::string _modubleName, int _processModubleID) {
		modubleName = _modubleName;
		processModubleID = _processModubleID;
	}
	~testAlgorithm();


	static void setCallbackResultData(std::function<void(HObject, HObject, bool)> _callbackResultData) {
		callbackResultData = _callbackResultData;
	}
	void threld(HObject image, int threshold1) {

		HObject resultRegion;
		GenEmptyObj(&resultRegion);

		HObject originImage;
		GenEmptyObj(&originImage);
		//algorithm start
		HObject thresholdRegion;
		GenEmptyObj(&thresholdRegion);
		HalconCpp::Threshold(image, &thresholdRegion, threshold1, 255);
		WriteImage(image, "bmp", 255, "./weree");
		if (true) {
			originImage = image;
		}

		if (modubleName == "threshold")
		{
			resultRegion = thresholdRegion;
		}
		//algorithm end
		bool isOK = true;
		callbackResultData(originImage, resultRegion, isOK);
	}
};

