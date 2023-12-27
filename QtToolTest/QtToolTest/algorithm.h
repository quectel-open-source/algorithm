#pragma once
#include "algorithmModuble.h"
#include "BarcodeDetect.h"

#include "algorithmScene.h"
#include "data.h"


static map<int, map<int, algorithmModuble*>> processMap;

struct idName {
	int id;
	eModubleType name;
};

class _declspec(dllexport) algorithm {
public:

	int processID;
	std::string xmlPath;
	algorithm(int processID,std::string _xmlPath);
	~algorithm();
	void addModuble(eModubleType moduble, int processModubleID);
	algorithmModuble* getModuble(std::string modubleName, int processModubleID);

	algorithmModuble* getAlgorithmModuble(eModubleType moduble, int processModubleID);
	map<int, algorithmModuble*> getModubleList();
	std::vector<std::string> getModubleNameList();
	HObject getShowImage(int modubleID);
	HObject getShowRegion(int modubleID);
	ParamsStruct_Line getLine(int modubleID, int index);
	ParamsStruct_Circle getCircle(int modubleID, int index);
	void runProcess(std::vector<int> modubleOrder, std::vector<connectionPair> connectionPair, std::vector<idName> idNameList);
	vector<connectionPair> findOtherNodePairList(vector<connectionPair> connectionPairList, int outModubleID);
	void setOtherNodePairValue(vector<connectionPair> otherPartList);
private:

};
