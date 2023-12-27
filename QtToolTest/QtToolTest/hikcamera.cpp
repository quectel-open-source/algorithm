#include "hikcamera.h"

QMutex g_mutex;
hikcamera::hikcamera(QObject *parent) : QObject(parent)
{
	for (int i = 0; i < CAMERA_NUM_MAX; i++)
	{
		m_pDevHandle[i] = nullptr;
		m_pImageBuffer[i] = nullptr;
		m_nImageBufferSize[i] = 0;
		m_bStartGrabbing[i] = false;
		memset(&m_stImageInfo[i], 0, sizeof(MV_FRAME_OUT_INFO_EX));
	}
         m_bThreadState = false;
         m_nOnlineNum = 0;
		 m_nCurNum = -1;
}
QString hikcamera::uncharToQstring(unsigned char * id,int len)
{
    QString msg;
    char *str1=(char *)id;
    msg = QString(QLatin1String(str1));
    return msg;
}
//初始化所有在线设备
bool hikcamera::InitDevice()
{
	if (m_nOnlineNum > 0)
	{
		return false;
	}
	m_nCurNum = -1;
	m_nOnlineNum = 0;
	// ch:枚举子网内所有设备 | en:Enumerate all devices within subnet
	memset(&stDevList, 0, sizeof(MV_CC_DEVICE_INFO_LIST));
	int nRet = MV_CC_EnumDevices(MV_GIGE_DEVICE | MV_USB_DEVICE, &stDevList);
	if (MV_OK != nRet)
	{
		return false;
		emit sendmessage("Wring：未发现相机，请检查相机链接!");
	}

	if (stDevList.nDeviceNum > 0)
	{
		for (unsigned int i = 0; i < stDevList.nDeviceNum; i++)
		{
			pDeviceInfo = stDevList.pDeviceInfo[i];
			if (NULL == pDeviceInfo)
			{
				emit sendmessage("未发现相机，请检查相机链接!");
				break;
			}
			if (pDeviceInfo->nTLayerType == MV_GIGE_DEVICE)
			{
				int nIp1 = ((pDeviceInfo->SpecialInfo.stGigEInfo.nCurrentIp & 0xff000000) >> 24);
				int nIp2 = ((pDeviceInfo->SpecialInfo.stGigEInfo.nCurrentIp & 0x00ff0000) >> 16);
				int nIp3 = ((pDeviceInfo->SpecialInfo.stGigEInfo.nCurrentIp & 0x0000ff00) >> 8);
				int nIp4 = (pDeviceInfo->SpecialInfo.stGigEInfo.nCurrentIp & 0x000000ff);
				QString ipadress = QString::number(nIp1) + "." + QString::number(nIp2) + "." + QString::number(nIp3) + "." + QString::number(nIp4);
				QString SerialNumber = uncharToQstring(pDeviceInfo->SpecialInfo.stGigEInfo.chSerialNumber, 16);
				QString ModelName = uncharToQstring(pDeviceInfo->SpecialInfo.stGigEInfo.chModelName, 32);

				cameraname = "GIGE:" + ModelName + ":" + SerialNumber + ":" + ipadress;
				// print current ip and user defined name
				hikcameralist.append("HikCamera: " + cameraname);
				emit initcamera("HikCamera: " + cameraname);
				//printf("UserDefinedName: %s\n\n" , pDeviceInfo->SpecialInfo.stGigEInfo.chModelName);

			}
			else if (pDeviceInfo->nTLayerType == MV_USB_DEVICE)
			{
				QString SerialNumber = uncharToQstring(pDeviceInfo->SpecialInfo.stUsb3VInfo.chSerialNumber, 64);
				QString ModelName = uncharToQstring(pDeviceInfo->SpecialInfo.stGigEInfo.chModelName, 32);
				cameraname = "USB3:" + ModelName + ":" + SerialNumber;
				hikcameralist.append("HikCamera: " + cameraname);
				emit initcamera("HikCamera: " + cameraname);
			}
			emit sendmessage("发现海康相机:" + cameraname);
		}
	}
	else
	{
		emit sendmessage("未发现相机，请检查相机链接!");
		return false;
	}

}
int  hikcamera::connectCamera()
{
	//创建设备句柄
	int nRet = MV_CC_CreateHandle(&m_pDevHandle[indexcamera], stDevList.pDeviceInfo[indexcamera]);
	if (0 != nRet)
	{
		emit sendmessage("创建相机句柄失败!");
		return false;
	}
	//打开设备句柄
	nRet = MV_CC_OpenDevice(m_pDevHandle[indexcamera]);
	if (nRet != 0)
	{
		emit sendmessage("打开相机失败!");
		MV_CC_DestroyHandle(m_pDevHandle[indexcamera]);
		m_pDevHandle[indexcamera] = nullptr;
		return -1;
	}
	else
	{
		emit sendmessage("打开相机成功");
	}
}
int hikcamera::StartCamera()
{
	// Get payload size
	MVCC_INTVALUE stParam;
	memset(&stParam, 0, sizeof(MVCC_INTVALUE));
	int nRet = MV_CC_GetIntValue(m_pDevHandle[indexcamera], "PayloadSize", &stParam);
	if (MV_OK != nRet)
	{
		emit sendmessage("相机被占用!");
		return -1;
	}
	g_nPayloadSize = stParam.nCurValue;
	int tempValue = MV_CC_StartGrabbing(m_pDevHandle[indexcamera]);
	if (tempValue != 0)
	{
		emit sendmessage("开始图像采集失败!");
		return -1;
	}
	else
	{
		emit sendmessage("Start grabbing image sucessful!");
		return 0;
	}
}
//读取相机中的图像
int hikcamera::ReadBuffer()
{
    QFuture<int> futrueGrapThread1 = QtConcurrent::run(std::bind(&hikcamera::GrabThreadProcess, this));
    return 0;
}
//实时采图线程
int hikcamera::GrabThreadProcess()
{
	MV_FRAME_OUT_INFO_EX stImageInfo = { 0 };
	memset(&stImageInfo, 0, sizeof(MV_FRAME_OUT_INFO_EX));
	pData = (unsigned char *)malloc(sizeof(unsigned char) * (g_nPayloadSize));
	if (pData == NULL)
	{
		printf("Allocate memory failed.");

	}
	while (m_bStartGrabbing[indexcamera]==true)
	{
		g_mutex.lock();
		int nRet = MV_CC_GetOneFrameTimeout(m_pDevHandle[indexcamera], pData, g_nPayloadSize, &stImageInfo, 1000);
		g_mutex.unlock();
		if (nRet == MV_OK)
		{
			Convert2Mat(&stImageInfo, pData);

		}
		QThread::msleep(1);

	}
	return MV_OK;
}
// convert data stream in Mat format
// ch:像素格式转换 | en:Pixel format conversion
int hikcamera::ConvertPixelType(MV_CC_PIXEL_CONVERT_PARAM* pstCvtParam)
{
    return MV_CC_ConvertPixelType(m_pDevHandle[indexcamera], pstCvtParam);
}

bool hikcamera::Convert2Mat(MV_FRAME_OUT_INFO_EX* pstImageInfo, unsigned char * pData)
{
	HObject srcImage;
	MV_CC_PIXEL_CONVERT_PARAM stConvertParam = { 0 };
	int nChannelNum;
	if (pstImageInfo->enPixelType == PixelType_Gvsp_Mono8)
	{
		nChannelNum = 1;
		//unsigned char * pConvertData = (unsigned char*)malloc(pstImageInfo->nWidth * pstImageInfo->nHeight * nChannelNum);
		int nConvertDataSize = pstImageInfo->nWidth * pstImageInfo->nHeight * nChannelNum;
		// ch:像素格式转换 | en:Convert pixel format
		stConvertParam.nWidth = pstImageInfo->nWidth;                 //ch:图像宽 | en:image width
		stConvertParam.nHeight = pstImageInfo->nHeight;               //ch:图像高 | en:image height
		stConvertParam.pSrcData = pData;                         //ch:输入数据缓存 | en:input data buffer
		stConvertParam.nSrcDataLen = pstImageInfo->nFrameLen;         //ch:输入数据大小 | en:input data size
		stConvertParam.enSrcPixelType = pstImageInfo->enPixelType;    //ch:输入像素格式 | en:input pixel format
		stConvertParam.enDstPixelType = PixelType_Gvsp_Mono8;                         //ch:输出像素格式 | en:output pixel format
		stConvertParam.pDstBuffer = pData;                            //ch:输出数据缓存 | en:output data buffer
		stConvertParam.nDstBufferSize = nConvertDataSize;                     //ch:输出缓存大小 | en:output buffer size
		ConvertPixelType(&stConvertParam);
		unsigned char * data = new unsigned char[pstImageInfo->nWidth * pstImageInfo->nHeight];
		memcpy(data, pData, pstImageInfo->nFrameLen);
		GenImage1(&srcImage, "byte", pstImageInfo->nWidth, pstImageInfo->nHeight, (Hlong)(data));
		free(data);
	}
	else if (pstImageInfo->enPixelType == PixelType_Gvsp_RGB8_Packed)
	{
		nChannelNum = 3;
		//pConvertData = (unsigned char*)malloc(pFrame.stFrameInfo.nWidth * pFrame.stFrameInfo.nHeight * nChannelNum);
		int nConvertDataSize = pstImageInfo->nWidth * pstImageInfo->nHeight * nChannelNum;
		// ch:像素格式转换 | en:Convert pixel format
		stConvertParam.nWidth = pstImageInfo->nWidth;                 //ch:图像宽 | en:image width
		stConvertParam.nHeight = pstImageInfo->nHeight;                //ch:图像高 | en:image height
		stConvertParam.pSrcData = pData;                         //ch:输入数据缓存 | en:input data buffer
		stConvertParam.nSrcDataLen = pstImageInfo->nFrameLen;         //ch:输入数据大小 | en:input data size
		stConvertParam.enSrcPixelType = pstImageInfo->enPixelType;    //ch:输入像素格式 | en:input pixel format
		stConvertParam.enDstPixelType = PixelType_Gvsp_RGB8_Packed;                         //ch:输出像素格式 | en:output pixel format
		stConvertParam.pDstBuffer = pData;                            //ch:输出数据缓存 | en:output data buffer
		stConvertParam.nDstBufferSize = nConvertDataSize;                     //ch:输出缓存大小 | en:output buffer size
		ConvertPixelType(&stConvertParam);
		int nRet = MV_CC_ConvertPixelType(m_pDevHandle[indexcamera], &stConvertParam);
		//unsigned char*图像转换为HObject
		unsigned char * dataRed = new unsigned char[pstImageInfo->nWidth * pstImageInfo->nHeight];
		unsigned char * dataGreen = new unsigned char[pstImageInfo->nWidth * pstImageInfo->nHeight];
		unsigned char * dataBlue = new unsigned char[pstImageInfo->nWidth * pstImageInfo->nHeight];
		unsigned char * data = new unsigned char[pstImageInfo->nWidth * pstImageInfo->nHeight * 3];
		memcpy(data, pData, pstImageInfo->nFrameLen * 3);
		for (int i = 0; i < pstImageInfo->nWidth * pstImageInfo->nHeight; i++)
		{
			dataRed[i] = data[3 * i];
			dataGreen[i] = data[3 * i + 1];
			dataBlue[i] = data[3 * i + 2];
		}
		GenImage3(&srcImage, "byte", pstImageInfo->nWidth, pstImageInfo->nHeight, (Hlong)(dataRed), (Hlong)(dataGreen), (Hlong)(dataBlue));

		free(dataRed);
		free(dataGreen);
		free(dataBlue);

	}
	else
	{
		emit sendmessage("unsupported pixel format");
		return false;
	}

	if (NULL == srcImage.CountObj())
	{
		return false;
	}
	else
	{
		emit sendimage(srcImage);
	}

	srcImage.Clear();

	return true;
}

//停止相机采集
int hikcamera::stopCamera(int index)
{
	int tempValue = MV_CC_StopGrabbing(m_pDevHandle[index]);
	if (tempValue != 0)
	{
		emit sendmessage("停止图像采集失败!");
		return -1;
	}
	else
	{
		emit sendmessage("停止图像采集成功!");
		return 0;
	}
}
//关闭相机
int hikcamera::closeCamera(int index)
{
	if (NULL == m_pDevHandle[index])
	{
		emit sendmessage("未打开相机!");
		return -1;
	}
	MV_CC_CloseDevice(m_pDevHandle[index]);
	int tempValue = MV_CC_DestroyHandle(m_pDevHandle[index]);
	m_pDevHandle[index] = NULL;
	if (tempValue != 0)
	{
		emit sendmessage("关闭相机失败!");
		return -1;
	}
	else
	{
		return 0;
	}
}
//发送软触发
bool hikcamera::softTrigger(int index)
{
	int tempValue = MV_CC_SetCommandValue(m_pDevHandle[index], "TriggerSoftware");
	if (tempValue != 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

// ch:设置触发模式
bool hikcamera::SetTriggerMode(int index, int mode)
{
	if (index < 0)
	{
		emit sendmessage("未选择相机");
		return false;
	}
	int nRet = MV_CC_SetEnumValue(m_pDevHandle[index], "TriggerMode", mode);
	if (MV_OK != nRet)
	{
		return false;
	}

	return true;
}
int hikcamera::GetTriggerMode(int index)
{
	if (index < 0)
	{
		emit sendmessage("未选择相机");
		return -1;
	}
	MVCC_ENUMVALUE stEnumValue = { 0 };
	int nRet = MV_CC_GetEnumValue(m_pDevHandle[index], "TriggerMode", &stEnumValue);
	if (MV_OK != nRet)
	{
		emit sendmessage("设置触发模式失败!");
		return -1;
	}

	int mode = stEnumValue.nCurValue;

	return mode;
}
// ch:设置曝光时间
bool hikcamera::SetExposureTime(int index, double exp)
{
	if (index < 0)
	{
		emit sendmessage("未选择相机");
		return false;
	}
	if (!m_pDevHandle[index])
	{
		return false;
	}

	int nRet = MV_CC_SetFloatValue(m_pDevHandle[index], "ExposureTime", (float)exp);
	if (MV_OK != nRet)
	{
		emit sendmessage("设置曝光时间失败!");
		return false;
	}

	return true;
}
float hikcamera::GetExposureTime(int index)
{
	if (index < 0)
	{
		emit sendmessage("未选择相机");
		return -1;
	}
	MVCC_FLOATVALUE stFloatValue = { 0 };
	int nRet = MV_CC_GetFloatValue(m_pDevHandle[index], "ExposureTime", &stFloatValue);
	if (MV_OK != nRet)
	{
		emit sendmessage("获取曝光时间失败!");
		return -1;
	}

	double exp = stFloatValue.fCurValue;
	return exp;
}

// ch:设置增益
bool hikcamera::SetGain(int index, double gain)
{
	if (index < 0)
	{
		emit sendmessage("未选择相机");
		return false;
	}
	if (!m_pDevHandle[index])
	{
		emit sendmessage("设置增益失败!");
		return false;
	}
	// ch:设置增益前先把自动增益关闭，失败无需返回
	//int nRet = MV_CC_SetEnumValue(m_pDevHandle[index], "GainAuto", 0);
	int nRet = MV_CC_SetFloatValue(m_pDevHandle[index], "Gain", (float)gain);
	if (MV_OK != nRet)
	{
		return -1;
	}
	return true;
}
float hikcamera::GetGain(int index)
{
	if (index < 0)
	{
		emit sendmessage("未选择相机");
		return -1;
	}
	MVCC_FLOATVALUE stFloatValue = { 0 };
	int nRet = MV_CC_GetFloatValue(m_pDevHandle[index], "Gain", &stFloatValue);
	if (MV_OK != nRet)
	{
		emit sendmessage("获取增益失败!");
		return -1;
	}
	else
	{
		float gain = stFloatValue.fCurValue;
		return gain;
	}
}
//设置帧率控制使能
int hikcamera::setFrameRateEnable(int index, bool comm)
{
	int tempValue = MV_CC_SetBoolValue(m_pDevHandle[index], "AcquisitionFrameRateEnable", comm);
	if (tempValue != 0)
	{
		emit sendmessage("设置帧率使能失败!");
		return -1;
	}
	else
	{
		emit sendmessage("设置帧率使能成功!");
		return 0;
	}
}
// ch:设置帧率
bool hikcamera::SetFrameRate(int index, double frame)
{
	if (index < 0)
	{
		emit sendmessage("未选择相机");
		return false;
	}
	if (!m_pDevHandle[index])
	{
		return false;
	}
	int nRet = MV_CC_SetBoolValue(m_pDevHandle[index], "AcquisitionFrameRateEnable", true);
	if (MV_OK != nRet)
	{
		emit sendmessage("设置帧率失败!");
		return nRet;
	}
	return MV_CC_SetFloatValue(m_pDevHandle[index], "AcquisitionFrameRate", (float)frame);
}
float hikcamera::GetFrameRate(int index)
{
	if (index < 0)
	{
		emit sendmessage("未选择相机");
		return -1;
	}
	MVCC_FLOATVALUE stFloatValue = { 0 };
	int nRet = MV_CC_GetFloatValue(m_pDevHandle[index], "ResultingFrameRate", &stFloatValue);
	if (MV_OK != nRet)
	{
		emit sendmessage("获取相机帧率失败!");
		return false;
	}
	double frame = stFloatValue.fCurValue;
	return frame;
}

// ch:设置触发源
bool hikcamera::SetTriggerSource(int index, int soft)
{
	//0：Line0  1：Line1  7：Software
	if (index < 0)
	{
		emit sendmessage("未选择相机");
		return false;
	}
	if (!m_pDevHandle[index])
	{
		emit sendmessage("相机打开失败!");
		return false;
	}
	if (soft == 0)
	{
		int nRet = MV_CC_SetEnumValue(m_pDevHandle[index], "TriggerSource", MV_TRIGGER_SOURCE_SOFTWARE);
		if (MV_OK != nRet)
		{
			emit sendmessage("设置触发源SOFTWARE失败!");
			return false;
		}
	}
	else if (soft == 1)
	{
		int nRet = MV_CC_SetEnumValue(m_pDevHandle[index], "TriggerSource", MV_TRIGGER_SOURCE_LINE0);
		if (MV_OK != nRet)
		{
			emit sendmessage("设置触发源LINE0失败!");
			return false;
		}
	}
	else if (soft == 2)
	{
		int nRet = MV_CC_SetEnumValue(m_pDevHandle[index], "TriggerSource", MV_TRIGGER_SOURCE_LINE1);
		if (MV_OK != nRet)
		{
			emit sendmessage("设置触发源LINE1失败!");
			return false;
		}
	}
	else if (soft == 3)
	{
		int nRet = MV_CC_SetEnumValue(m_pDevHandle[index], "TriggerSource", MV_TRIGGER_SOURCE_LINE2);
		if (MV_OK != nRet)
		{
			emit sendmessage("设置触发源LINE2失败!");
			return false;
		}
	}
	return true;
}
int hikcamera::GetTriggerSource(int index)
{
	//0：Line0  1：Line1  7：Software
	if (index < 0)
	{
		emit sendmessage("未选择相机，请选择一个相机!");
		return -1;
	}
	MVCC_ENUMVALUE stEnumValue = { 0 };
	int nRet = MV_CC_GetEnumValue(m_pDevHandle[index], "TriggerSource", &stEnumValue);
	if (MV_OK != nRet)
	{
		emit sendmessage("获取触发源失败！");
		return false;
	}
	int value = stEnumValue.nCurValue;
	if (MV_TRIGGER_SOURCE_SOFTWARE == stEnumValue.nCurValue)
	{
		return 0;
	}
	else if (MV_TRIGGER_SOURCE_LINE0 == stEnumValue.nCurValue)
	{
		return 1;
	}
	else if (MV_TRIGGER_SOURCE_LINE1 == stEnumValue.nCurValue)
	{
		return 2;
	}
	else if (MV_TRIGGER_SOURCE_LINE2 == stEnumValue.nCurValue)
	{
		return 3;
	}
	else if (MV_TRIGGER_SOURCE_LINE3 == stEnumValue.nCurValue)
	{
		return 4;
	}
}

//设置图像ROI高度
int hikcamera::setHeight(int index, unsigned int height)
{
	int tempValue = MV_CC_SetIntValue(m_pDevHandle[index], "Height", height);
	if (tempValue != 0)
	{
		emit sendmessage("设置图像ROI高度失败!");
		return -1;
	}
	else
	{
		return 0;
	}
}

//设置图像ROI宽度
int hikcamera::setWidth(int index, unsigned int width)
{
	int tempValue = MV_CC_SetIntValue(m_pDevHandle[index], "Width", width);
	if (tempValue != 0)
	{
		emit sendmessage("设置图像ROI宽度失败!");
		return -1;
	}
	else
	{
		return 0;
	}
}

//设置图像水平偏移OffsetX
int hikcamera::setOffsetX(int index, unsigned int offsetX)
{
	int tempValue = MV_CC_SetIntValue(m_pDevHandle[index], "OffsetX", offsetX);
	if (tempValue != 0)
	{
		emit sendmessage("设置图像水平偏移OffsetX失败!");
		return -1;
	}
	else
	{
		return 0;
	}
}

//设置图像竖直偏移OffsetY
int hikcamera::setOffsetY(int index, unsigned int offsetY)
{
	int tempValue = MV_CC_SetIntValue(m_pDevHandle[index], "OffsetY", offsetY);
	if (tempValue != 0)
	{
		emit sendmessage("设置图像竖直偏移OffsetY失败!");
		return -1;
	}
	else
	{
		return 0;
	}
}
//设置心跳时间
int hikcamera::setHeartBeatTime(int index, unsigned int time)
{
	//心跳时间最小为500ms
	if (time < 500)
		time = 500;
	int tempValue = MV_CC_SetIntValue(m_pDevHandle[index], "GevHeartbeatTimeout", time);
	if (tempValue != 0)
	{
		emit sendmessage("设置心跳时间失败!");
		return -1;
	}
	else
	{
		return 0;
	}
}
//userSET
int hikcamera::setUserSet(int index)
{
	//0：Line0  1：Line1  7：Software
	if (index < 0)
	{
		emit sendmessage("未选择相机，请选择一个相机！");
		return -1;
	}
	MV_CC_SetEnumValue(m_pDevHandle[index], "UserSetSelector", 1);
	MV_CC_SetEnumValue(m_pDevHandle[index], "UserSetDefault", 1);
	int tempValue = MV_CC_SetCommandValue(m_pDevHandle[index], "UserSetSave");
	if (tempValue != 0)
	{
		return 0;
	}
	else
	{
		return 0;
	}
}







