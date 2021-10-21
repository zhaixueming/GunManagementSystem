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
    QString GetSavePath();

	//����Ӳ����
	//bool SetExternalTrigger(int index);//�޸�0927

	bool SoftTriggerOnce(int index,QString &errMsg);
	void closeAllCamera();





private:
	CParameterSettings(QDialog *parent = NULL);
	~CParameterSettings();
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



	QString m_Camera1Name;//���1����
	QString m_Camera2Name;
	int m_Camera1Type;
	int m_Camera2Type;
	CMvCamera m_MvCamera1;//������
	CMvCamera m_MvCamera2;

private:
	void InitVariables();
	void InitCameraInfo();////////
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

	void LoadConfig();/////////////
	

private slots:

	
	void ConnectDatabase();//�������ݼ�����¼��
	void Camera1Controller();//���롰��������ۺ��� OpenSecondCamera()
	void Camera2Controller();//��ǹ���������
	void SwitchCamera1Type(int index, bool checked); //void SwitchSecondCameraStatus(int index, bool checked);
	void SwitchCamera2Type(int index, bool checked);
	void ReceiveSoftTrigger(int index);
	void ReceiveCamera1Image(Mat image);//���ձ������ͼ��
	void ReceiveCamera2Image(Mat image);//������ǹ���ͼ��

	void BrowseSavePath();//����ͼ��·��//
	void SaveConfig();///////////////////////
	//void InitCameraInfo();
signals:
	void SendCameraImage(int type,Mat image);
};


