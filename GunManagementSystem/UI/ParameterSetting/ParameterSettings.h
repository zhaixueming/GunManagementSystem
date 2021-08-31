#pragma once
#include "ui_ParameterSettings.h"
#include "DatabaseOperator.h"
#include "ImageCapture.h"
#include "QButtonGroup"

class CParameterSettings :public QDialog
{
	Q_OBJECT
public:
	static CParameterSettings *GetInstance();
	bool SoftTriggerOnce(int index,QString &errMsg);
	void closeAllCamera();
	~CParameterSettings();
private:
	CParameterSettings(QDialog *parent = NULL);//私有构造函数，不允许使用者自己生成对象。单例模式
private:
	Ui::ParameterSetting ui;
	static CParameterSettings *m_Instance;//静态成员变量，单例模式
	QButtonGroup *m_BtnGroup1;
	QButtonGroup *m_BtnGroup2;
	bool m_bConnected;
	MV_CC_DEVICE_INFO_LIST m_stDevList;//设备信息列表
	CImageCapture *m_CameraCapture1;
	CImageCapture *m_CameraCapture2;
	bool m_bOpenCamera1;
	bool m_bOpenCamera2;
	QString m_Camera1Name;
	QString m_Camera2Name;
	int m_Camera1Type;
	int m_Camera2Type;
	CMvCamera m_MvCamera1;
	CMvCamera m_MvCamera2;

private:
	void InitVariables();
	void InitConnections();
	//相机操作
	bool OpenCamera(MV_CC_DEVICE_INFO device_info, int index);
	bool CloseDevice(int index);
	//连续模式
	bool SetFreeFrame(int index);
	//软触发
	bool SetSoftTrigger(int index);
	//设置硬触发
	bool SetExternalTrigger(int index);
private slots:
	void ConnectDatabase();
	void Camera1Controller();
	void Camera2Controller();
	void SwitchCamera1Type(int index, bool checked);
	void SwitchCamera2Type(int index, bool checked);
	void ReceiveSoftTrigger(int index);
	void ReceiveCamera1Image(Mat image);
	void ReceiveCamera2Image(Mat image);
	void InitCameraInfo();
signals:
	void SendCameraImage(int type,Mat image);
};


