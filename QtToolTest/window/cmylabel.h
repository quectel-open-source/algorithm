#pragma once

#include <QLabel>
#include <QWheelEvent>
#include <Halcon.h>
#include <halconcpp/HalconCpp.h>
#include <QDebug>

using namespace HalconCpp;

class CMyLabel : public QLabel
{
	Q_OBJECT

public:
	CMyLabel(QWidget *parent = Q_NULLPTR);
	~CMyLabel();

	//����Halconͼ���Halcon���ھ�����û���Ӧ����¼���ʵʱ����ͼ��
	void setHalconWnd(HObject img, HObject obj, bool isShowObj, HTuple hHalconID, QLabel *label);

	//�����������¼�
	void wheelEvent(QWheelEvent *ev);

	//��갴���¼�
	void mousePressEvent(QMouseEvent *ev);

	//����ͷ��¼�
	void mouseReleaseEvent(QMouseEvent *ev);

	//����ƶ��¼�
	void mouseMoveEvent(QMouseEvent *ev);

public:
	HTuple m_labelID;			//Qt��ǩ���
	HTuple m_hHalconID;			//Halcon���ھ��

	HObject m_currentImg;		//��ǰ��ͼ��
	HObject m_currentObj;      //��ǰ������Ҫ��ʾ��ͼ��(����ֱ�ߣ�Բ�������)
	bool m_isShowObj = false;    //�Ƿ��ڴ�����ʾͼ��

	//��������ʾ����ı�ǩ
	QLabel *m_label;

	//��갴�µ�λ�� 
	HTuple m_tMouseDownRow;
	HTuple m_tMouseDownCol;

	bool m_bIsMove;				//�Ƿ��ƶ�ͼ���ʶ
};
