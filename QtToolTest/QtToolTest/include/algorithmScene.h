#pragma once

#include <QtWidgets/QApplication>
#include <Halcon.h>
#include <halconcpp/HalconCpp.h>
#include "data.h"
using namespace HalconCpp;

//template<class ModelType>
//__declspec(dllexport)  void registerModuble();

struct portData {
    bool isSelect;
    ePortType dataType;
};

struct connectionPair {
    int outModubleID;
    std::string outPortName;
    int inModubleID;
    std::string inPortName;
};

struct sceneModubleData {
    std::map<eModubleType, std::string > modubleNameTitleMap;
    std::map<eModubleType, std::map<std::string,portData>> portIn;
    std::map<eModubleType, std::map<std::string, portData>> portOut;
};

class __declspec(dllexport) algorithmScene {
public:
    algorithmScene(int _proceedID, QWidget* processWidget);
    ~algorithmScene();
    void run();
    void save();
    static void registerModuble(sceneModubleData test);
    std::vector<int> getModubleOrder();
    std::vector<connectionPair> getConnectionPair();
    void load();
    static void setConfigPath(std::string _configPath);
    int addModule(eModubleType  name, QPointF  mouseScenePos);
    void setCallback(std::function<void(int, int)> callbackScenePosition,
        std::function<void(int)> callbackRemoveModuble,
        std::function<void(int, int, std::string, std::function<void(int)>)> callbackSelectModubleData,
        std::function<void(HObject, HObject, bool)> _callbackResultData,
        std::function<void(int processID, int modubleID)> _callbackClickData);
    void setCallbackS(std::function<void(int, int)> callbackScenePosition);
	static std::vector<int> getProcessIDList();
};