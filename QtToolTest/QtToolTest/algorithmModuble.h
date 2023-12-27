#pragma once
#include <string>
#include <Halcon.h>
#include <halconcpp/HalconCpp.h>
#include <database.h>
#include <functional>

using namespace HalconCpp;

class _declspec(dllexport) algorithmModuble
{
public:
	virtual ~algorithmModuble() = default;
	algorithmModuble() = default;
	algorithmModuble(std::string _nodeName, int _processModubleID, int _processID);
	virtual void run() = 0;
	virtual void start(bool _isStartContinus) = 0;
	virtual void end() = 0;

	std::function<void()> triggerCallback;
	virtual void setTriggerCallback(std::function<void()> _triggerCallback) {
		triggerCallback = _triggerCallback;
	};
	HObject algorithmModuble::* getPointerHObject(eDataType hobjectString);
	HObject ho_Image;
	HObject ho_ImageOrigin;
	HObject result_DisplyResion;

	HTuple algorithmModuble::* getPointerHTuple(eDataType hobjectString);
	HTuple hv_WindowHandle;

	bool algorithmModuble::* getPointerBool(eDataType hobjectString);
	bool isOK;

	double algorithmModuble::* getPointerDouble(eDataType hobjectString);
	double hv_Width;
	double hv_Height;

	ParamsStruct_Line algorithmModuble::* getPointerHLine(eDataType hobjectString);
	ParamsStruct_Line Line1;
	ParamsStruct_Line Line2;

	std::string nodeName;
	int processModbuleID = -1;
protected:

		int processID = -1;

		//QFileInfoList imagelist;
		std::string XMLPath;
		std::string configPath;

};

class algorithmModubleType
{
public:


	static algorithmModuble* createAlgorithmModuble(const std::string& name);
	private:
		algorithmModubleType() = default;
		~algorithmModubleType() = default;

};
