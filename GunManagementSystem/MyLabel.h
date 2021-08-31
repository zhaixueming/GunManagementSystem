#ifndef MYLABEL_H
#define MYLABEL_H

#include <QObject>
#include <QLabel>
#include <QMutex>

class MyLabel : public QLabel
{
	Q_OBJECT
public:
	explicit MyLabel(QWidget *parent = 0);
	void SetImage(QImage image);
protected:
	void paintEvent(QPaintEvent *event);                        //QPaint��ͼ
	void wheelEvent(QWheelEvent *event) override;               //�����ֹ���
	void mousePressEvent(QMouseEvent *event) override;          //�������
	void mouseDoubleClickEvent(QMouseEvent *event) override;    //˫������ԭͼ���С
	void mouseMoveEvent(QMouseEvent *event) override;           //����ɿ�
	void mouseReleaseEvent(QMouseEvent *event) override;        //��귢���¼�

private:
	void OnZoomInImage();       //ͼƬ�Ŵ�
	void OnZoomOutImage();      //ͼƬ��С
	void OnPresetImage();       //ͼƬ��ԭ

private:
	QMutex m_Mutex;
	QImage m_Image;           //��ʾ��ͼƬ
	qreal ZoomValue = 1.0;  //�������ֵ
	int XPtInterval = 0;    //ƽ��X���ֵ
	int YPtInterval = 0;    //ƽ��Y���ֵ
	QPoint OldPos;          //�ɵ����λ��
	bool Pressed = false;   //����Ƿ���ѹ
};

#endif // MYLABEL_H

