#ifndef HIKCAMERA_H
#define HIKCAMERA_H

#include <QObject>
#include <MvCameraControl.h>
#include "opencv2/opencv.hpp"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <QGlobalStatic>
#include <CameraParams.h>
#include <QtConcurrent/QtConcurrent>
#include <QMutex>
#include <QFuture>
#include <QMetaType>
#include <Halcon.h>
#include <halconcpp/HalconCpp.h>

using namespace std;
using namespace HalconCpp;
using namespace cv;

#define CAMERA_NUM_MAX 12    //支持的相机最大个数
class hikcamera : public QObject
{
    Q_OBJECT
public:
    explicit hikcamera(QObject *parent = nullptr);
    QString uncharToQstring(unsigned char * id,int len);
       bool InitDevice();
        MV_CC_DEVICE_INFO* pDeviceInfo;
       int connectCamera();
       int StartCamera();
       int GrabThreadProcess();
       //读取相机中的图像
       int ReadBuffer();
       int RGB2BGR( unsigned char* pRgbData, unsigned int nWidth, unsigned int nHeight );
       bool Convert2Mat(MV_FRAME_OUT_INFO_EX* pstImageInfo, unsigned char * pData);
       //停止相机采集
       int stopCamera(int index);
       //关闭相机
       int closeCamera(int index);
       //发送软触发
       bool softTrigger(int index);
       //设置获取触发模式
         bool SetTriggerMode(int index, int mode);
         int GetTriggerMode(int index);

         //设置获取曝光时间
         bool SetExposureTime(int index, double exp);
         float GetExposureTime(int index);

         //设置获取增益
         bool SetGain(int index, double gain);
         float GetGain(int index);

         //设置帧率控制使能
         int setFrameRateEnable(int index,bool comm);
         //设置获取帧率
         bool SetFrameRate(int index, double frame);
         float GetFrameRate(int index);

         //设置获取触发源
         bool SetTriggerSource(int index, int soft);
         int GetTriggerSource(int index);
         //设置图像水平偏移OffsetX
         int setOffsetX(int index,unsigned int offsetX);

         //设置图像竖直偏移OffsetY
         int setOffsetY(int index,unsigned int offsetY);
         //设置图像高度
         int setHeight(int index,unsigned int height);

         //设置图像ROI宽度
         int setWidth(int index,unsigned int width);
         //设置心跳时间
         int setHeartBeatTime(int index,unsigned int time);
         int setUserSet(int index);
         // ch:像素格式转换 | en:Pixel format conversion
             int ConvertPixelType(MV_CC_PIXEL_CONVERT_PARAM* pstCvtParam);
public:
       QString cameraname;
       QStringList hikcameralist;
       //Mat srcImage;
       unsigned char * pData;
       //在线设备总数
       int m_nOnlineNum;
       //当前工作相机序号
       int m_nCurNum;
       MV_CC_DEVICE_INFO_LIST stDevList;
       //相机设备句柄
       void* m_pDevHandle[CAMERA_NUM_MAX];
       int indexcamera;
       //用于从驱动获取图像的缓存
       unsigned char*  m_pImageBuffer[CAMERA_NUM_MAX];
       //一帧图像大小
       unsigned int m_nImageBufferSize[CAMERA_NUM_MAX];
       //实时采图状态
       bool m_bThreadState;
       //是否开始抓图
       bool  m_bStartGrabbing[CAMERA_NUM_MAX];
       //输出帧的信息
       MV_FRAME_OUT_INFO_EX m_stImageInfo[CAMERA_NUM_MAX];
       unsigned int g_nPayloadSize = 0;

signals:
       void sendimage(HObject);
       void initcamera(QString t);
       void sendmessage(QString y);
       void sendtime(int);

};

#endif // HIKCAMERA_H
