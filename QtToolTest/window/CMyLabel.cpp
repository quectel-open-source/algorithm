#include "CMyLabel.h"

//���嵥���Ŵ���
#define ZOOMRATIO 2.0

CMyLabel::CMyLabel(QWidget *parent)
	: QLabel(parent)
{
	m_bIsMove = false;
}

CMyLabel::~CMyLabel()
{
}

//����Halconͼ���Halcon���ھ�����û���Ӧ����¼���ʵʱ����ͼ��
void CMyLabel::setHalconWnd(HObject img, HObject obj,bool isShowObj, HTuple hHalconID, QLabel *label)
{
	m_hHalconID = hHalconID;
	m_currentImg = img;
	m_currentObj = obj;
	m_label = label;
	m_isShowObj = isShowObj;
}

//�����������¼�����������ͼ��
void CMyLabel::wheelEvent(QWheelEvent *ev)
{
	double Zoom;			//�Ŵ����С����
	HTuple  mouseRow, mouseCol, Button;
	HTuple startRowBf, startColBf, endRowBf, endColBf, Ht, Wt, startRowAft, startColAft, endRowAft, endColAft;

	//����ǰ�����Ŵ�
	if (ev->delta() > 0)
	{
		Zoom = ZOOMRATIO;
	}
	else
	{
		Zoom = 1 / ZOOMRATIO;
	}

	//��ȡ�����ԭͼ�ϵ�λ�ã�ע����ԭͼ���꣬����Label�µ�����
	SetCheck("give_error");
	try
	{
		GetMposition(m_hHalconID, &mouseRow, &mouseCol, &Button);

	}
	catch (HException& HDevExpDefaultException)
	{
		return;
	}
	SetCheck("give_error");

	//��ȡԭͼ��ʾ�Ĳ��֣�ע��Ҳ��ԭͼ����
	GetPart(m_hHalconID, &startRowBf, &startColBf, &endRowBf, &endColBf);

	//����ǰ��ʾ��ͼ����
	Ht = endRowBf - startRowBf;
	Wt = endColBf - startColBf;

	//��ͨ��halcon�ܴ����ͼ�����ߴ���32K*32K�����������Сԭͼ�񣬵�����ʾ��ͼ�񳬳����ƣ������ɳ������
	if ((Ht * Wt < 20000 * 20000 || Zoom == ZOOMRATIO))
	{
		//�������ź��ͼ������
		startRowAft = mouseRow - ((mouseRow - startRowBf) / Zoom);
		startColAft = mouseCol - ((mouseCol - startColBf) / Zoom);

		endRowAft = startRowAft + (Ht / Zoom);
		endColAft = startColAft + (Wt / Zoom);

		//����Ŵ�����򷵻�
		if (endRowAft - startRowAft < 2)
		{
			return;
		}

		if (m_hHalconID != NULL)
		{
			//�����ͼ���������ͼ��
			DetachBackgroundFromWindow(m_hHalconID);
		}
		SetPart(m_hHalconID, startRowAft, startColAft, endRowAft, endColAft);
		AttachBackgroundToWindow(m_currentImg, m_hHalconID);
		//��ʾͼ��
		if (m_isShowObj)
		{
			SetCheck("give_error");
			try
			{
				DispObj(m_currentObj, m_hHalconID);
			}
			catch (HException& HDevExpDefaultException)
			{
				return;
			}
			SetCheck("give_error");
		}
	}
}

//��갴���¼�
void CMyLabel::mousePressEvent(QMouseEvent *ev)
{
	HTuple mouseRow, mouseCol, Button;
	SetCheck("~give_error");
	try
	{
		GetMposition(m_hHalconID, &mouseRow, &mouseCol, &Button);
	}
	catch (HException)
	{
		return;
	}
	SetCheck("give_error");

	//��갴��ʱ����������
	m_tMouseDownRow = mouseRow;
	m_tMouseDownCol = mouseCol;

	m_bIsMove = true;
}

//����ͷ��¼�
void CMyLabel::mouseReleaseEvent(QMouseEvent *ev)
{
	m_bIsMove = false;
}

//����ƶ��¼�
void CMyLabel::mouseMoveEvent(QMouseEvent *ev)
{
	HTuple startRowBf, startColBf, endRowBf, endColBf, mouseRow, mouseCol, Button;

	//��ȡ��ǰ�����ԭͼ��λ��
	SetCheck("~give_error");
	try
	{
		GetMposition(m_hHalconID, &mouseRow, &mouseCol, &Button);
		//qDebug()<< "row:"<<
	}
	catch (HException)
	{
		return;
	}
	SetCheck("give_error");

	//��갴�²��ƶ�ʱ���ƶ�ͼ�񣬷���ֻ��ʾ����
	//��ʱ��������϶�ͼ��Ϊ�˷�����Hwindow�ϻ�������
	if (m_bIsMove)
	{
		////�����ƶ�ֵ
		//double RowMove = mouseRow[0].TupleReal().D() - m_tMouseDownRow[0].TupleReal().D();
		//double ColMove = mouseCol[0].TupleReal().D() - m_tMouseDownCol[0].TupleReal().D();

		////�õ���ǰ�Ĵ�������
		//GetPart(m_hHalconID, &startRowBf, &startColBf, &endRowBf, &endColBf);

		////�ƶ�ͼ��
		//if (m_hHalconID != NULL)
		//{
		//	//�����ͼ���������ͼ��
		//	DetachBackgroundFromWindow(m_hHalconID);
		//}
		//SetPart(m_hHalconID, startRowBf - RowMove, startColBf - ColMove, endRowBf - RowMove, endColBf - ColMove);
		//AttachBackgroundToWindow(m_currentImg, m_hHalconID);
	}

	//��ȡ�Ҷ�ֵ
	HTuple pointGray;
	SetCheck("~give_error");
	try
	{
		GetGrayval(m_currentImg, mouseRow, mouseCol, &pointGray);
	}
	catch (HException)
	{
		m_label->setText(QString::fromLocal8Bit("X���꣺-    Y���꣺-    �Ҷ�ֵ��-"));

		return;
	}
	SetCheck("give_error");

	//��������
	m_label->setText(QString::fromLocal8Bit("X���꣺%1    Y���꣺%2    �Ҷ�ֵ��%3").arg(mouseCol[0].D()).arg(mouseRow[0].D()).arg(pointGray[0].D()));
}
