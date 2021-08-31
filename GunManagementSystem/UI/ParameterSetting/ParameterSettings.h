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
	CParameterSettings(QDialog *parent = NULL);//˽�й��캯����������ʹ�����Լ����ɶ��󡣵���ģʽ
private:
	Ui::ParameterSetting ui;
	static CParameterSettings *m_Instance;//��̬��Ա����������ģʽ
	QButtonGroup *m_BtnGroup1;
	QButtonGroup *m_BtnGroup2;
	bool m_bConnected;
	MV_CC_DEVICE_INFO_LIST m_stDevList;//�豸��Ϣ�б�
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
	//�������
	bool OpenCamera(MV_CC_DEVICE_INFO device_info, int index);
	bool CloseDevice(int index);
	//����ģʽ
	bool SetFreeFrame(int index);
	//����
	bool SetSoftTrigger(int index);
	//����Ӳ����
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


