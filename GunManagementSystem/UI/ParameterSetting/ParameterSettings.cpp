#include <Windows.h>
#include "ParameterSettings.h"

//�������öԻ���



CParameterSettings *CParameterSettings::m_Instance = NULL;

CParameterSettings::CParameterSettings(QDialog *parent /* = NULL */)
	:QDialog(parent)
{
	ui.setupUi(this);
	this->setFixedSize(this->size());
	InitVariables();
	InitConnections();
}

CParameterSettings::~CParameterSettings()
{
}

CParameterSettings *CParameterSettings::GetInstance()//����ģʽ
{
	if (m_Instance == NULL)// �ȼ������Ƿ����
	{
		m_Instance = new CParameterSettings();//����
	}
	return m_Instance;//ע�⣺Ȼ�����ڶ��̵߳���������ַ����ǲ���ȫ�ģ�Lock lock; //α���� ����
}

void CParameterSettings::InitVariables()
{
	m_bConnected = false;//��ʼ��Ϊf
	ui.pushButton_OpenCamera1->setEnabled(false);
	ui.pushButton_OpenCamera2->setEnabled(false);
	m_BtnGroup1 = new QButtonGroup();
	m_BtnGroup1->addButton(ui.radioButton_FreeRun1, 1);
	m_BtnGroup1->addButton(ui.radioButton_SoftTrigger1, 2);
	m_BtnGroup1->addButton(ui.radioButton_ExternalTrigger1, 3);

	ui.radioButton_FreeRun1->setEnabled(false);
	ui.radioButton_SoftTrigger1->setEnabled(false);
	ui.radioButton_SoftTrigger1->setChecked(true);
	ui.radioButton_ExternalTrigger1->setEnabled(false);

	m_BtnGroup2 = new QButtonGroup();
	m_BtnGroup2->addButton(ui.radioButton_FreeRun2, 1);
	m_BtnGroup2->addButton(ui.radioButton_SoftTrigger2, 2);
	m_BtnGroup2->addButton(ui.radioButton_ExternalTrigger2, 3);

	ui.radioButton_FreeRun2->setEnabled(false);
	ui.radioButton_SoftTrigger2->setEnabled(false);
	ui.radioButton_SoftTrigger2->setChecked(true);
	ui.radioButton_ExternalTrigger2->setEnabled(false);



	m_CameraCapture1 = new CImageCapture();//����ͼ��
	m_CameraCapture1->start();
	m_CameraCapture2 = new CImageCapture();
	m_CameraCapture2->start();
	m_bOpenCamera1 = false;
	m_bOpenCamera2 = false;
	m_Camera1Type = 2;
	m_Camera2Type = 2;
	InitCameraInfo();
}


//��ʼ������
void CParameterSettings::InitConnections()
{
	qRegisterMetaType<Mat>("Mat");
	//CImageCapture���У���������ɼ�ͼ��--�����ݸ��˽���Ĳۺ���
	connect(m_CameraCapture1, SIGNAL(SendCaptureImage(Mat)), this, SLOT(ReceiveCamera1Image(Mat)));
	connect(m_CameraCapture2, SIGNAL(SendCaptureImage(Mat)), this, SLOT(ReceiveCamera2Image(Mat)));

	connect(m_BtnGroup1, SIGNAL(buttonToggled(int, bool)), this, SLOT(SwitchCamera1Type(int, bool)));
	connect(m_BtnGroup2, SIGNAL(buttonToggled(int, bool)), this, SLOT(SwitchCamera2Type(int, bool)));
}

//�������ý�������ݼ��ĵ�¼����
void CParameterSettings::ConnectDatabase()
{
	QString DatabaseName = ui.lineEdit_DatabaseName->text();
	QString UserName = ui.lineEdit_UserName->text();
	QString Password = ui.lineEdit_Password->text();
	QString errMsg;
	bool rv = false;
	if (m_bConnected)//init=false
	{
		rv = CDatabaseOperator::GetInstance()->DisconnectDatabase(errMsg);
		if (rv)
		{
			m_bConnected = false;
			ui.pushButton_Login->setText(QString::fromLocal8Bit("��¼"));
		}
		else
		{
			QMessageBox::information(this, QString::fromLatin1("�Ͽ����ݿ����"), errMsg);
			qDebug() << "Disconnect database:"<<errMsg;
		}
	}
	else
	{
		rv = CDatabaseOperator::GetInstance()->ConnectDatabase(DatabaseName, UserName, Password, errMsg);//�����������ݿ⺯��
		if (!rv)
		{
			qDebug() << "Disconnect database:" << errMsg;
			QMessageBox::information(this, QString::fromLatin1("�������ݿ����"), errMsg);
		}
		else
		{
			m_bConnected = true;
			ui.pushButton_Login->setText(QString::fromLocal8Bit("�Ͽ�"));
		}
	}
}
//����SDK��������
//1.ö���豸 -> 2.������� -> 3.���豸 -> 4.��ʼץͼ -> 5.��ȡһ֡������ͼ�� -> 6.ֹͣץͼ -> 7.�ر��豸 -> 8.���پ��
void CParameterSettings::InitCameraInfo()
{
	memset(&m_stDevList, 0, sizeof(MV_CC_DEVICE_INFO_LIST));
	int nRet = CMvCamera::EnumDevices(MV_GIGE_DEVICE, &m_stDevList);//.1ö���豸��GigE�豸,�豸�б�
	if (MV_OK != nRet)
	{
		qDebug() << QString::fromLocal8Bit("ö�����ʧ��:") << nRet;
		return;
	}
	if (m_stDevList.nDeviceNum > 0)//�����豸����
	{
		ui.pushButton_OpenCamera1->setEnabled(true);//�����������ť�ɵ�� 
		ui.pushButton_OpenCamera2->setEnabled(true);
	}
	for (int i = 0; i < m_stDevList.nDeviceNum; ++i)
	{
		MV_CC_DEVICE_INFO* pDeviceInfo = m_stDevList.pDeviceInfo[i];//�豸��Ϣ
		char strUserName[256] = { 0 };
		sprintf_s(strUserName, "%s_%s", pDeviceInfo->SpecialInfo.stGigEInfo.chModelName,
			pDeviceInfo->SpecialInfo.stGigEInfo.chSerialNumber);// chModelName[32]; �ͺ����ơ�chSerialNumber[16];���к�
		ui.comboBox_Camera1->addItem(strUserName);//�����������������
		ui.comboBox_Camera2->addItem(strUserName);
	}
}

bool CParameterSettings::OpenCamera(MV_CC_DEVICE_INFO device_info,int index)
{
	if (index == 1)
	{
		int nRet = m_MvCamera1.Open(&device_info);//.2�������,���豸
		if (nRet != MV_OK)
		{
			QMessageBox::information(this, QString::fromLocal8Bit("����"), QString::fromLocal8Bit("�����ʧ��:") + QString::number(nRet));
			m_bOpenCamera1 = false;
		}
		else
		{
			unsigned int PackSize = 0;
			int nRet = m_MvCamera1.GetOptimalPacketSize(&PackSize);//ch:̽��������Ѱ���С(ֻ��GigE�����Ч)
			if (nRet == MV_OK)
			{
				m_MvCamera1.SetIntValue("GevSCPSPacketSize", PackSize);
			}
			nRet = m_MvCamera1.StartGrabbing();//.4ch:����ץͼ
			m_bOpenCamera1 = nRet == MV_OK;//0x00000000
			if (!m_bOpenCamera1)
			{
				QMessageBox::information(this, QString::fromLocal8Bit("����"), "Start grabbing failed:" + QString::number(nRet));
			}
		}
		return m_bOpenCamera1;
	}
	else if (index == 2)
	{
		int nRet = m_MvCamera2.Open(&device_info);
		if (nRet != MV_OK)
		{
			QMessageBox::information(this, QString::fromLocal8Bit("����"), QString::fromLocal8Bit("�����ʧ��:") + QString::number(nRet));
			m_bOpenCamera2 = false;
		}
		else
		{
			unsigned int PackSize = 0;
			int nRet = m_MvCamera2.GetOptimalPacketSize(&PackSize);
			if (nRet == MV_OK)
			{
				m_MvCamera2.SetIntValue("GevSCPSPacketSize", PackSize);
			}
			nRet = m_MvCamera2.StartGrabbing();
			m_bOpenCamera2 = nRet == MV_OK;
			if (!m_bOpenCamera2)
			{
				QMessageBox::information(this, QString::fromLocal8Bit("����"), "Start grabbing failed:" + QString::number(nRet));
			}
		}
		return m_bOpenCamera2;
	}
	return true;
}

//�ر��豸
bool CParameterSettings::CloseDevice(int index)
{
	bool bSuccess = false;
	if (index == 1 && m_bOpenCamera1)
	{
		int nRet = m_MvCamera1.StopGrabbing();//.6ֹͣץͼ
		if (nRet != MV_OK)
		{
			QMessageBox::information(this, QString::fromLocal8Bit("����"), "StopGrabbing failed:" + QString::number(nRet));
			bSuccess = false;
		}
		nRet = m_MvCamera1.Close();//.7�ر��豸
		if (nRet == MV_OK)
		{
			bSuccess = true;
		}
		else
		{
			QMessageBox::information(this, QString::fromLocal8Bit("����"), "close device failed:" + QString::number(nRet));
			bSuccess = false;
		}
		m_bOpenCamera1 = !bSuccess;
	}
	else if (index == 2 && m_bOpenCamera2)
	{
		m_MvCamera2.StopGrabbing();
		int nRet = m_MvCamera2.Close();
		if (nRet == MV_OK)
		{
			bSuccess = true;
		}
		else
		{
			QMessageBox::information(this, QString::fromLocal8Bit("����"), "close device failed:" + QString::number(nRet));
			bSuccess = false;
		}
		m_bOpenCamera2 = !bSuccess;
	}
	return bSuccess;
}

//����Ϊ���ɲɼ�
bool CParameterSettings::SetFreeFrame(int index)
{
	int nRet = MV_OK;
	if (index == 1 && m_bOpenCamera1)
	{
		nRet = m_MvCamera1.SetEnumValue("TriggerMode", MV_TRIGGER_MODE_OFF);
	}
	else if (index == 2 && m_bOpenCamera2)
	{
		nRet = m_MvCamera2.SetEnumValue("TriggerMode", MV_TRIGGER_MODE_OFF);
	}
	if (nRet != MV_OK)
	{
		QMessageBox::information(this, QString::fromLocal8Bit("����"), QString::fromLocal8Bit("�������ɲɼ�ģʽʧ��:") + QString::number(nRet));
		return false;
	}
	return true;
}

bool CParameterSettings::SetSoftTrigger(int index)
{
	if (index == 1 && m_bOpenCamera1)
	{
		int nRet = m_MvCamera1.SetEnumValue("TriggerMode", MV_TRIGGER_MODE_ON);
		if (nRet != MV_OK)
		{
			QMessageBox::information(this, QString::fromLocal8Bit("����"), QString::fromLocal8Bit("��������ģʽʧ��:") + QString::number(nRet));
			return false;
		}
		nRet = m_MvCamera1.SetEnumValue("TriggerSource", MV_TRIGGER_SOURCE_SOFTWARE);
		if (nRet != MV_OK)
		{
			QMessageBox::information(this, QString::fromLocal8Bit("����"), QString::fromLocal8Bit("���ô���Դʧ��:") + QString::number(nRet));
			return false;
		}
	}
	else if (index == 2 && m_bOpenCamera2)
	{
		int nRet = m_MvCamera2.SetEnumValue("TriggerMode", MV_TRIGGER_MODE_ON);
		if (nRet != MV_OK)
		{
			QMessageBox::information(this, QString::fromLocal8Bit("����"), QString::fromLocal8Bit("��������ģʽʧ��:") + QString::number(nRet));
			return false;
		}
		nRet = m_MvCamera2.SetEnumValue("TriggerSource", MV_TRIGGER_SOURCE_SOFTWARE);
		if (nRet != MV_OK)
		{
			QMessageBox::information(this, QString::fromLocal8Bit("����"), QString::fromLocal8Bit("���ô���Դʧ��:") + QString::number(nRet));
			return false;
		}
	}
	return true;
}

bool CParameterSettings::SetExternalTrigger(int index)
{
	if (index == 1 && m_bOpenCamera1)
	{
		int nRet = m_MvCamera1.SetEnumValue("TriggerMode", MV_TRIGGER_MODE_ON);
		if (nRet != MV_OK)
		{
			QMessageBox::information(this, QString::fromLocal8Bit("����"), QString::fromLocal8Bit("�����ⴥ��ģʽʧ��:") + QString::number(nRet));
			return false;
		}
		nRet = m_MvCamera1.SetEnumValue("TriggerSource", MV_TRIGGER_SOURCE_LINE0);
		if (nRet != MV_OK)
		{
			QMessageBox::information(this, QString::fromLocal8Bit("����"), QString::fromLocal8Bit("���ô���Դʧ��:") + QString::number(nRet));
			return false;
		}
	}
	else if (index == 2 && m_bOpenCamera2)
	{
		int nRet = m_MvCamera2.SetEnumValue("TriggerMode", MV_TRIGGER_MODE_ON);
		if (nRet != MV_OK)
		{
			QMessageBox::information(this, QString::fromLocal8Bit("����"), QString::fromLocal8Bit("�����ⴥ��ģʽʧ��:") + QString::number(nRet));
			return false;
		}
		nRet = m_MvCamera2.SetEnumValue("TriggerSource", MV_TRIGGER_SOURCE_LINE0);
		if (nRet != MV_OK)
		{
			QMessageBox::information(this, QString::fromLocal8Bit("����"), QString::fromLocal8Bit("���ô���Դʧ��:") + QString::number(nRet));
			return false;
		}
	}
	return true;
}

//����
bool CParameterSettings::SoftTriggerOnce(int index, QString &errMsg)
{
	if (index == 1 && m_bOpenCamera1)
	{
		if (m_Camera1Type != 2)//2�Ǵ���
		{
			errMsg = QString::fromLocal8Bit("�������������������ģʽ");
			return false;
		}
		int nRet = m_MvCamera1.CommandExecute("TriggerSoftware"); //���SDKִ��һ��Command������
		if (nRet != MV_OK)
		{
			errMsg = QString::fromLocal8Bit("����ʧ��:") + QString::number(nRet);
			return false;
		}
	}
	else if (index == 2 && m_bOpenCamera2)//���2
	{
		if (m_Camera2Type != 2)
		{
			errMsg = QString::fromLocal8Bit("�������������������ģʽ");
			return false;
		}
		int nRet = m_MvCamera2.CommandExecute("TriggerSoftware");
		if (nRet != MV_OK)
		{
			errMsg = QString::fromLocal8Bit("����ʧ��:") + QString::number(nRet);
			return false;
		}
	}
	return true;
}


//�ر��������
void CParameterSettings::closeAllCamera()
{
	QString errMsg;
	if (m_bOpenCamera1)
	{
		m_CameraCapture1->SetCameraStatus(false);
		Sleep(100);
		CloseDevice(1);
	}
	m_CameraCapture1->StopThread();//�߳�1
	if (m_bOpenCamera2)
	{
		m_CameraCapture2->SetCameraStatus(false);
		Sleep(100);
		CloseDevice(2);
	}
	m_CameraCapture2->StopThread();//�߳�2
}

//�ۺ������������ý���ı��������еġ�������������󡪡����˲ۺ���
void CParameterSettings::Camera1Controller()
{
	QString name = ui.comboBox_Camera1->currentText();//��ǰ�ı���ֵ
	int index = ui.comboBox_Camera1->currentIndex();
	if (m_bOpenCamera1)
	{
		m_CameraCapture1->SetCameraStatus(false);
		bool rv = CloseDevice(1);//returnvalue
		if (!rv)
		{
			return;
		}
		ui.pushButton_OpenCamera1->setText(QString::fromLocal8Bit("�����"));
		m_bOpenCamera1 = false;
		m_Camera1Name.clear();
		ui.radioButton_FreeRun1->setEnabled(false);//���ɲɼ���ѡ��ť���ɵ��
		ui.radioButton_SoftTrigger1->setEnabled(false);//��ɼ���ѡ��ť���ɵ��
		ui.radioButton_ExternalTrigger1->setEnabled(false);//Ӳ������ѡ��ť���ɵ��
	}
	else
	{
		if (name == m_Camera1Name)
		{
			QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("����ѱ�ռ��"));
			return;
		}
		else if (index <= m_stDevList.nDeviceNum)//�����豸����
		{
			QString errMsg;
			m_bOpenCamera1 = OpenCamera(*m_stDevList.pDeviceInfo[index],1);
			if (!m_bOpenCamera1)
			{
				return;
			}
			SwitchCamera1Type(m_Camera1Type, true);
			m_CameraCapture1->SetCameraHandle(m_MvCamera1);
			m_CameraCapture1->SetCameraStatus(true);
			m_Camera1Name = name;
			ui.radioButton_FreeRun1->setEnabled(true);
			ui.radioButton_SoftTrigger1->setEnabled(true);
			ui.radioButton_ExternalTrigger1->setEnabled(true);
			ui.pushButton_OpenCamera1->setText(QString::fromLocal8Bit("�ر����"));
		}
	}
}


//�ۺ������������ý������ǹ�����еġ�������������󡪡����˲ۺ���
void CParameterSettings::Camera2Controller()
{
	QString name = ui.comboBox_Camera2->currentText();
	int index = ui.comboBox_Camera2->currentIndex();
	if (m_bOpenCamera2)
	{
		m_CameraCapture2->SetCameraStatus(false);//�������������SetCameraStatus(false)�������������״̬
		bool rv = CloseDevice(2);
		if (!rv)
		{
			return;
		}
		ui.pushButton_OpenCamera2->setText(QString::fromLocal8Bit("�����"));
		m_bOpenCamera2 = false;
		m_Camera2Name.clear();
		ui.radioButton_FreeRun2->setEnabled(false);
		ui.radioButton_SoftTrigger2->setEnabled(false);
		ui.radioButton_ExternalTrigger2->setEnabled(false);
	}
	else
	{
		if (name == m_Camera2Name)
		{
			QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("����ѱ�ռ��"));
			return;
		}
		else if (index <= m_stDevList.nDeviceNum)//�����豸����
		{
			QString errMsg;
			m_bOpenCamera2 = OpenCamera(*m_stDevList.pDeviceInfo[index], 2);
			if (!m_bOpenCamera2)
			{
				return;
			}
			SwitchCamera2Type(m_Camera2Type, true);
			m_CameraCapture2->SetCameraHandle(m_MvCamera2);
			m_CameraCapture2->SetCameraStatus(true);
			m_Camera2Name = name;
			ui.radioButton_FreeRun2->setEnabled(true);
			ui.radioButton_SoftTrigger2->setEnabled(true);
			ui.radioButton_ExternalTrigger2->setEnabled(true);
			ui.pushButton_OpenCamera2->setText(QString::fromLocal8Bit("�ر����"));
		}
	}
}


//�л����1����
void CParameterSettings::SwitchCamera1Type(int index, bool checked)
{
	if (checked)
	{
		if (!m_bOpenCamera1)
		{
			ui.label_Info->setText(QString::fromLocal8Bit("���δ��"));//���������á��������»ƿ�
			return;
		}
		QString errMsg;
		switch (index)
		{
			case 1:
			{
				SetFreeFrame(1);//���ɲɼ�
				m_Camera1Type = 1;
				break;
			}
			case 2:
			{
				SetSoftTrigger(1);//����
				m_Camera1Type = 2;
				break;
			}
			case 3:
			{
				SetExternalTrigger(1);//�ⲿ����
				m_Camera1Type = 3;
				break;
			}
		}
	}
}

//�л����2����
void CParameterSettings::SwitchCamera2Type(int index, bool checked)
{
	if (checked)
	{
		if (!m_bOpenCamera2)
		{
			ui.label_Info->setText(QString::fromLocal8Bit("���δ��"));
			return;
		}
		QString errMsg;
		switch (index)
		{
		case 1:
		{
			SetFreeFrame(2);
			m_Camera1Type = 1;
			break;
		}
		case 2:
		{
			SetSoftTrigger(2);
			m_Camera1Type = 2;
			break;
		}
		case 3:
		{
			SetExternalTrigger(2);
			m_Camera1Type = 3;
			break;
		}
		}
	}
}

//�ۺ����������洫�ݹ��������ѡ��--׷�ݵĻ��ǡ����ռ��ӡ�������м����ʾ���Լ��·���������ť���������գ�1����ǹ���գ�2
void CParameterSettings::ReceiveSoftTrigger(int index)
{
	if (index == 1 && m_bOpenCamera1)//���1&&�����
	{  
		QString errMsg;
		bool rv =SoftTriggerOnce(index,errMsg);//���1�������
		if (!rv)
		{
			QMessageBox::information(this, QString::fromLocal8Bit("����"), QString::fromLocal8Bit("��������:")+errMsg);
			return;
		}
	}
	else if (index == 2 && m_bOpenCamera2)
	{
		QString errMsg;
		bool rv = SoftTriggerOnce(index,errMsg);
		if (!rv)
		{
			QMessageBox::information(this, QString::fromLocal8Bit("����"), QString::fromLocal8Bit("��������:") + errMsg);
			return;
		}
	}
}

void CParameterSettings::ReceiveCamera1Image(Mat image)
{
	emit SendCameraImage(1, image);//ѡ�����
}

void CParameterSettings::ReceiveCamera2Image(Mat image)
{
	emit SendCameraImage(2, image);
}

