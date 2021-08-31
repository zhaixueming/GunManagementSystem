#pragma once

#include <QtWidgets/QMainWindow>
#include <QKeyEvent>
#include "ui_SysMainWindow.h"
#include "SystemManager.h"
#include "ParameterSettings.h"

class SysMainWindow : public QMainWindow
{
	Q_OBJECT

public:
	SysMainWindow(QWidget *parent = Q_NULLPTR);//�вι��캯��
	~SysMainWindow();
private:
	Ui::SysMainWindowClass ui;
	CSystemMangaer m_SystemManager;
private:
	void InitVariables();//��ʼ������
	void InitConnections();//��ʼ���ۺ���
private slots:
	void slotAccountManager();//�˺Ź���ۺ���
	void slotCodeReview();//������Ӳۺ���
	void slotInfoManager();//�źŹ���ۺ���
	void ReceiveCameraImage(int index, Mat image);//���
	void ReceiveSoftTrigger(int index);//����
protected:
	void keyPressEvent(QKeyEvent *ev);//�����
signals:
	void SendStackWidgetIndex(int index);//����
	void SendSoftTrigger(int index);//����
	void SendCameraImage(int index, Mat image);//���
	
};
