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
	SysMainWindow(QWidget *parent = Q_NULLPTR);//有参构造函数
	~SysMainWindow();
private:
	Ui::SysMainWindowClass ui;
	CSystemMangaer m_SystemManager;
private:
	void InitVariables();//初始化变量
	void InitConnections();//初始化槽函数
private slots:
	void slotAccountManager();//账号管理槽函数
	void slotCodeReview();//编码检视槽函数
	void slotInfoManager();//信号管理槽函数
	void ReceiveCameraImage(int index, Mat image);//相机
	void ReceiveSoftTrigger(int index);//软触发
protected:
	void keyPressEvent(QKeyEvent *ev);//口令弹窗
signals:
	void SendStackWidgetIndex(int index);//弹窗
	void SendSoftTrigger(int index);//弹窗
	void SendCameraImage(int index, Mat image);//相机
	
};
