#pragma once
#include <string>
#include <Halcon.h>
#include <halconcpp/HalconCpp.h>

using namespace HalconCpp;

struct RunParamsStruct_Camera {
	std::string factory;
	std::string equipment;
	std::string SN;
	std::string address;

	float gain;
	float ExposureTime;
	int TriggerMode;
	int TriggerSource;
};

//һά�������в����ṹ��
struct RunParamsStruct_BarCode {
	HObject ho_SearchRegion;					    //��������
	HTuple hv_CodeType_Run;							//��������(Ĭ��"auto"������ѡ��ṹ��CodeTypeStruct_BarCode����Ķ����),��ʱ����Ĭ��ֵ����Ϊ�����������͵�ʱ��auto����������ǰ�棬���±���
	HTuple hv_CodeNum = 1;						    //ʶ������(����Ϊ0����ɨ����������)
	HTuple hv_Tolerance = "high";                   //ʶ���ݲ�(Ĭ�ϸ߼���Ĭ��high������������"low")
	HTuple hv_HeadChar = "null";					    //�ض��ַ���ͷ
	HTuple hv_EndChar = "null";						    //�ض��ַ���β
	HTuple hv_ContainChar = "null";						//�����ض��ַ�
	HTuple hv_NotContainChar = "null";					//�������ض��ַ�
	HTuple hv_CodeLength_Run = 2;               //������С����
	HTuple hv_TimeOut = 50;						//��ʱʱ��(��λms)
};

//������ʶ�����ṹ��
struct ResultParamsStruct_BarCode {
	//����������
	HTuple hv_CodeType_Result;         //��������
	HTuple hv_CodeContent;			  //��������
	HTuple hv_CodeLength_Result;	  //���볤��
	HObject ho_ContourBarCode;		  //��������
	HObject ho_RegionBarCode;		  //����ʶ��������
	HTuple hv_Row;                    //��������������
	HTuple hv_Column;                 //��������������
	HTuple hv_RetNum = 0;			 //�ҵ����������(Ĭ����0��ʶ����������0)

};


//���������ͽṹ��
struct CodeTypeStruct_BarCode {
	HTuple CODE128 = "Code 128";
	HTuple CODE39 = "Code 39";
	HTuple CODE93 = "Code 93";
	HTuple EAN13 = "EAN-13";
	HTuple EAN8 = "EAN-8";
	HTuple ITF25 = "2/5 Industrial";
	HTuple UPCA = "UPC-A";
	HTuple UPCE = "UPC-E";
	HTuple CODABAR = "Codabar";
	HTuple PHARMACODE = "PharmaCode";
	HTuple AUTO = "auto";
};