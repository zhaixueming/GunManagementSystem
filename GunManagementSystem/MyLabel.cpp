#include "mylabel.h"
#include <QPainter>
#include <QDebug>
#include <QWheelEvent>
#include <QMenu>
#include <QFileDialog>

MyLabel::MyLabel(QWidget *parent) :QLabel(parent)
{

}

//QPainter��ͼ
void MyLabel::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);
	painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
	// ���ݴ��ڼ���Ӧ����ʾ��ͼƬ�Ĵ�С
	m_Mutex.lock();
	int width = qMin(m_Image.width(), this->width());
	int height = width * 1.0 / (m_Image.width() * 1.0 / m_Image.height());
	height = qMin(height, this->height());
	width = height * 1.0 * (m_Image.width() * 1.0 / m_Image.height());

	// ƽ��
	painter.translate(this->width() / 2 + XPtInterval, this->height() / 2 + YPtInterval);

	// ����
	painter.scale(ZoomValue, ZoomValue);

	// ����ͼ��
	QRect picRect(-width / 2, -height / 2, width, height);

// 	QPixmap pixmap = QPixmap::fromImage(m_Image);
//	QPixmap fitpixmap = pixmap.scaled(this->width(), this->height(),Qt::KeepAspectRatio, Qt::SmoothTransformation);
// 	this->setPixmap(fitpixmap);
//	painter.drawPixmap(picRect, fitpixmap);
	painter.drawImage(picRect, m_Image);
	m_Mutex.unlock();
}

//�����ֹ���
void MyLabel::wheelEvent(QWheelEvent *event)
{
	int value = event->delta();
	if (value > 0)  //�Ŵ�
		OnZoomInImage();
	else            //��С
		OnZoomOutImage();

	update();
}

//�������
void MyLabel::mousePressEvent(QMouseEvent *event)
{
	OldPos = event->pos();
	Pressed = true;
}

void MyLabel::mouseDoubleClickEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton)
	{
		ZoomValue = 1.0;
		XPtInterval = 0;
		YPtInterval = 0;
		update();
	}
}
//����ɿ�
void MyLabel::mouseMoveEvent(QMouseEvent *event)
{
	if (!Pressed)
		return QWidget::mouseMoveEvent(event);

	this->setCursor(Qt::SizeAllCursor);
	QPoint pos = event->pos();
	int xPtInterval = pos.x() - OldPos.x();
	int yPtInterval = pos.y() - OldPos.y();

	XPtInterval += xPtInterval;
	YPtInterval += yPtInterval;

	OldPos = pos;
	update();
}
//��귢���¼�
void MyLabel::mouseReleaseEvent(QMouseEvent *event)
{
	Pressed = false;
	setCursor(Qt::ArrowCursor);
}

//ͼƬ�Ŵ�
void MyLabel::OnZoomInImage()
{
	ZoomValue += 1;
	if (ZoomValue > 10)
	{
		ZoomValue = 10;
	}
	update();
}

//ͼƬ��С
void MyLabel::OnZoomOutImage()
{
	ZoomValue -= 1;
	if (ZoomValue <= 0)
	{
		ZoomValue = 0.5;
		return;
	}

	update();
}

//ͼƬ��ԭ
void MyLabel::OnPresetImage()
{
	ZoomValue = 1.0;
	XPtInterval = 0;
	YPtInterval = 0;
	update();
}

void MyLabel::SetImage(QImage image)
{
	m_Mutex.lock();
	m_Image = image;
	m_Mutex.unlock();
	update();
}