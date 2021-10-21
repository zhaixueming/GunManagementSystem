#include <Windows.h>
#include "ParameterSettings.h"
#include"QFileDialog"
#include"Config.h"

//�������öԻ���



CParameterSettings *CParameterSettings::m_Instance = NULL;

CParameterSettings::CParameterSettings(QDialog *parent /* = NULL */)
	:QDialog(parent)
{
	ui.setupUi(this);
	this->setFixedSize(this->size()); 
	ui.pushButton_Login->setStyleSheet("QPushButton{font: 75 15pt '΢���ź�';background-color:rgb(190, 190, 190);color: rgb(34, 139, 34);border:2px groove gray;border-radius:50px;padding:2px 4px;border-style: outset;}"
		"QPushButton:hover{background-color:gray; color: rgb(10, 10, 10);}"
		"QPushButton:pressed{background-color:rgb(210, 20, 20);border-style: inset;}");
	ui.pushButton_SaveConfig->setStyleSheet("QPushButton{font: 75 15pt '΢���ź�';background-color:rgb(190, 190, 190);border:2px groove gray;border-radius:50px;padding:2px 4px;border-style: outset;}"
		"QPushButton:hover{background-color:gray; color: rgb(10, 10, 10);}"
		"QPushButton:pressed{background-color:rgb(210, 20, 20);border-style: inset;}");

	InitVariables();
	InitConnections();
	LoadConfig();
}

CParameterSettings::~CParameterSettings()
{
}

CParameterSettings *CParameterSettings::GetInstance()//����ģʽ
{
	if (m_Instance == NULL)
	{
		m_Instance = new CParameterSettings();
	}
	return m_Instance;
}

void CParameterSettings::InitVariables()
{
	m_bConnected = false;//��ʼ��Ϊfalse
	//�����pBt
	ui.pushButton_OpenCamera1->setEnabled(false);
	ui.pushButton_OpenCamera2->setEnabled(false);
	//��������ѡ��
	m_BtnGroup1 = new QButtonGroup();
	m_BtnGroup1->addButton(ui.radioButton_FreeRun1, 1);
	m_BtnGroup1->addButton(ui.radioButton_SoftTrigger1, 2);
	m_BtnGroup1->addButton(ui.radioButton_ExternalTrigger1, 3);

	ui.radioButton_FreeRun1->setEnabled(false);
	ui.radioButton_SoftTrigger1->setEnabled(false);
	ui.radioButton_ExternalTrigger1->setEnabled(false);
	ui.radioButton_ExternalTrigger1->setChecked(true);//�������գ�Ĭ��ѡ��ΪӲ����

	m_BtnGroup2 = new QButtonGroup();
	m_BtnGroup2->addButton(ui.radioButton_FreeRun2, 1);
	m_BtnGroup2->addButton(ui.radioButton_SoftTrigger2, 2);
	m_BtnGroup2->addButton(ui.radioButton_ExternalTrigger2, 3);

	ui.radioButton_FreeRun2->setEnabled(false);
	ui.radioButton_SoftTrigger2->setEnabled(false);
	ui.radioButton_ExternalTrigger2->setEnabled(false);
	ui.radioButton_SoftTrigger2->setChecked(true);//��ǹ���գ�Ĭ��ѡ��Ϊ����



	m_CameraCapture1 = new CImageCapture();//�������ͼ��
	m_CameraCapture1->start();//�����߳�
	m_CameraCapture2 = new CImageCapture();//������ǹͼ��
	m_CameraCapture2->start();
	m_bOpenCamera1 = false;//��ʼ��ΪFalse
	m_bOpenCamera2 = false;
	m_Camera1Type = 3;//�������ճ�ʼ��Ϊ3��Ӳ�������ǵ��޸�
	m_Camera2Type = 2;//��ǹ���ճ�ʼ��Ϊ2������
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
	if (m_bConnected)
	{
		rv = CDatabaseOperator::GetInstance()->DisconnectDatabase(errMsg);
		if (rv)
		{
			QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("���ݿ�Ͽ��ɹ�"));
			m_bConnected = false;
			ui.pushButton_Login->setText(QString::fromLocal8Bit("����"));
			ui.lineEdit_DatabaseName->setEnabled(true);
			ui.lineEdit_UserName->setEnabled(true);
			ui.lineEdit_Password->setEnabled(true);
		}
		else
		{
			QMessageBox::information(this, QString::fromLatin1("���ݿ�Ͽ�ʧ��"), errMsg);
			qDebug() << "Disconnect database:"<<errMsg;
		}
	}
	else
	{
		
		rv = CDatabaseOperator::GetInstance()->ConnectDatabase(DatabaseName, UserName, Password, errMsg);//�����������ݿ⺯��
		if (!rv)
		{
			QMessageBox::information(this, QString::fromLatin1("���ݿ�����ʧ��"), errMsg);
			qDebug() << "Disconnect database:" << errMsg;
		}
		else
		{
			//QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("���ݿ����ӳɹ�"));
			m_bConnected = true;
			ui.pushButton_Login->setText(QString::fromLocal8Bit("�Ͽ�"));
			ui.lineEdit_DatabaseName->setEnabled(false);
			ui.lineEdit_UserName->setEnabled(false);
			ui.lineEdit_Password->setEnabled(false);
		}
	}
}
//����SDK��������
//1.ö���豸 -> 2.������� -> 3.���豸 -> 4.��ʼץͼ -> 5.��ȡһ֡������ͼ�� -> 6.ֹͣץͼ -> 7.�ر��豸 -> 8.���پ��
void CParameterSettings::InitCameraInfo()
{    
	//�ֳ�usb ����gige
	memset(&m_stDevList, 0, sizeof(MV_CC_DEVICE_INFO_LIST));
	int nRet = CMvCamera::EnumDevices(MV_GIGE_DEVICE | MV_USB_DEVICE, &m_stDevList);//.1ö���豸��GigE or USB�豸,�豸�б�
	//memset(&m_stDevList, 0, sizeof(MV_CC_DEVICE_INFO_LIST));
	//int nRet = CMvCamera::EnumDevices(MV_USB_DEVICE, &m_stDevList);//.1ö���豸��usb�豸,�豸�б�
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
		char strUserNameBianMa[256] = { 0 };
		char strUserNameZhengQiang[256] = { 0 };
		sprintf_s(strUserNameBianMa, "%s_%s", pDeviceInfo->SpecialInfo.stUsb3VInfo.chModelName,
		pDeviceInfo->SpecialInfo.stUsb3VInfo.chSerialNumber);// chModelName[32]; �ͺ����ơ�chSerialNumber[16];���к�
		
		sprintf_s(strUserNameZhengQiang, "%s_%s", pDeviceInfo->SpecialInfo.stGigEInfo.chModelName,
		pDeviceInfo->SpecialInfo.stGigEInfo.chSerialNumber);// chModelName[32]; �ͺ����ơ�chSerialNumber[16];���к�

		ui.comboBox_Camera1->addItem(strUserNameBianMa);//�����������������
		ui.comboBox_Camera2->addItem(strUserNameZhengQiang);

		/*if(strUserName[0] != '_') 
			ui.comboBox_Camera1->addItem(strUserName);
		if (strUserName1[0] != '_')
			ui.comboBox_Camera2->addItem(strUserName1);*/

		qDebug() << "CameraName;" << strUserNameBianMa;
		qDebug() << "CameraName;" << strUserNameZhengQiang;

	}
}

bool CParameterSettings::OpenCamera(MV_CC_DEVICE_INFO device_info,int index)
{
	if (index == 1)
	{
		int nRet = m_MvCamera1.Open(&device_info);//.2�������,���豸   int Open(MV_CC_DEVICE_INFO* pstDeviceInfo);
		if (nRet != MV_OK)
		{
			QMessageBox::information(this, QString::fromLocal8Bit("����"), QString::fromLocal8Bit("�������������ʧ��:") + QString::number(nRet));
			m_bOpenCamera1 = false;
		}
		else
		{
			//QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("������������򿪳ɹ�"));
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
			QMessageBox::information(this, QString::fromLocal8Bit("����"), QString::fromLocal8Bit("��ǹ���������ʧ��:") + QString::number(nRet));
			m_bOpenCamera2 = false;
		}
		else
		{
			//QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("��ǹ��������򿪳ɹ�"));
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
//����
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
//Ӳ����
bool CParameterSettings::SetExternalTrigger(int index)
{
	if (index == 1 && m_bOpenCamera1)//��������
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


bool CParameterSettings::SoftTriggerOnce(int index, QString &errMsg)
{
	if (index == 1 && m_bOpenCamera1)//m_bOpenCamera1���1���ӳɹ�
	{
		if (m_Camera1Type != 2)//2������ģʽ
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


//ͼƬ·����Ϣ
QString CParameterSettings::GetSavePath()
{
	QString SavePath = ui.lineEdit_SaveImagePath->text();
	if (!SavePath.isEmpty())
	{
		return SavePath;
	}
	else
	{
		QMessageBox::information(this, QString::fromLocal8Bit("����"), QString::fromLocal8Bit("δ���ô��ͼƬ·����Ϣ"));
		//return;
	}
}

//������ʾ���·��
void CParameterSettings::BrowseSavePath()
{
	QString filePath = QFileDialog::getExistingDirectory(this, "Open Image Save Path", QCoreApplication::applicationDirPath());
	if (!filePath.isEmpty())
	{
		ui.lineEdit_SaveImagePath->setText(filePath);
	}
	else
	{
		QMessageBox::information(this, QString::fromLocal8Bit("����"), QString::fromLocal8Bit("δ����·����Ϣ"));
	}

}

//��Ϣд�뵽ini�ļ���
void CParameterSettings::SaveConfig()
{
	QString IniPath = QCoreApplication::applicationDirPath() + "/parameter_cfg.ini";//����һ��ini�ļ�
	CConfig *cfg = new CConfig(IniPath);
	
	if (m_bOpenCamera1)
	{
		QString m_Camera1Name = ui.comboBox_Camera1->currentText();
		cfg->Write(CAMERA_SECTION, CAMERA_NAME1, m_Camera1Name);
	}

	if (m_bOpenCamera2)
	{
		QString m_Camera2Name = ui.comboBox_Camera2->currentText();
		cfg->Write(CAMERA_SECTION, CAMERA_NAME2, m_Camera2Name);
	}
	//��������ı���·��
	QString SavePath = ui.lineEdit_SaveImagePath->text();
	if (!SavePath.isEmpty())
	{
		cfg->Write(DATA_SECTION, IMAGE_SAVE_PATH, SavePath);

	}

	//���ݿ�
	bool bconnected = CDatabaseOperator::GetInstance()->GetConnectStatus();
	cfg->Write(DATABASE, HOSTNAME, bconnected);
	if (bconnected)
	{
		QString DatabaseName = ui.lineEdit_DatabaseName->text();
		QString UserName = ui.lineEdit_UserName->text();
		QString Password = ui.lineEdit_Password->text();
		
		cfg->Write(DATABASE, DATABASE_NAME, DatabaseName);
		cfg->Write(DATABASE, USER_NAME, UserName);
		cfg->Write(DATABASE, PASSWORD, Password);
	}

}


//void CParameterSettings::LoadConfig()
//{
//	QString IniPath = QCoreApplication::applicationDirPath() + "/parameter_cfg.ini";
//	CConfig *cfg = new CConfig(IniPath);
//	m_Camera1Name = cfg->GetString(CAMERA_SECTION, CAMERA_NAME1);
//	if (!m_Camera1Name.isEmpty())
//	{
//		for (int i = 0; i < ui.comboBox_Camera1->count(); ++i)
//		{
//			QString CurrentName = ui.comboBox_Camera1->itemText(i);
//			if (CurrentName == m_Camera1Name)
//			{
//				QString errMsg;
//				m_bOpenCamera1 = OpenCamera(*m_stDevList.pDeviceInfo[i],1);
//				if (!m_bOpenCamera1)
//				{
//					return;
//				}
//				m_CameraCapture1.SetCameraHandle(m_MvCamera1);
//				m_CameraCapture1.SetCameraStatus(true);
//				ui.spinBox_Exposure->setEnabled(true);
//				//ui.spinBox_Gain->setEnabled(true);
//				ui.pushButton_OpenCamera1->setText(QString::fromLocal8Bit("�ر����"));
//				break;
//			}
//		}
//	}
//}

//�ӱ��ص�ini�ļ�������Ϣ
void CParameterSettings::LoadConfig()
{
	QString IniPath = QCoreApplication::applicationDirPath() + "/parameter_cfg.ini";
	//CConfig *cfg = new CConfig(IniPath);
	QFileInfo info;
	if (info.exists(IniPath))
	{
		CConfig *cfg = new CConfig(IniPath);

		//���1����
		QString m_Camera1Name = cfg->GetString(CAMERA_SECTION, CAMERA_NAME1);
		qDebug() << "load config camera1 name:" << m_Camera1Name;
		printf("load config camera1 name:%s\n", m_Camera1Name.toStdString().c_str());
		if (!m_Camera1Name.isEmpty())
		{
			int index = ui.comboBox_Camera1->findText(m_Camera1Name);
			qDebug() << "camera1 comboBox index: " << index;
			printf("camera1 comBox index:%d\n", index);
			if (index != -1)
			{
				ui.comboBox_Camera1->setCurrentIndex(index);
				Camera1Controller();//�����1
			}

		}
		//���2����
		QString m_Camera2Name = cfg->GetString(CAMERA_SECTION, CAMERA_NAME2);
		qDebug() << "load config camera2 name:" << m_Camera2Name;
		printf("load config camera2 name:%s\n", m_Camera2Name.toStdString().c_str());
		if (!m_Camera2Name.isEmpty())
		{
			int index = ui.comboBox_Camera2->findText(m_Camera2Name);
			qDebug() << "camera2 comboBox index: " << index;
			printf("camera2 comBox index:%d\n", index);
			if (index != -1)
			{
				ui.comboBox_Camera2->setCurrentIndex(index);
				Camera2Controller();//�����2
			}

		}

		//���ݿ�
		bool rv = cfg->GetBool(DATABASE, HOSTNAME);
		qDebug() << "load config database connected:" << rv;
		if (rv)
		{
			QString databasename = cfg->GetString(DATABASE, DATABASE_NAME);
			qDebug() << "load config database name:" << databasename;
			printf("load config database name:%s\n", databasename.toStdString().c_str());
			ui.lineEdit_DatabaseName->setText(databasename);

			QString username = cfg->GetString(DATABASE, USER_NAME);
			qDebug() << "load config database username:" << username;
			printf("load config database username:%s\n", username.toStdString().c_str());
			ui.lineEdit_UserName->setText(username);

			QString password = cfg->GetString(DATABASE, PASSWORD);
			qDebug() << "load config database password:" << password;
			printf("load config database password:%s\n", password);
			ui.lineEdit_Password->setText(password);
			ConnectDatabase();

		}

		//����·��
		bool bSavePath = cfg->GetBool(DATA_SECTION, IMAGE_SAVE_PATH);
		qDebug() << "load config save path: " << bSavePath;
		printf("load config save path:%d\n", bSavePath);
		if (bSavePath)
		{
			QString SavePath = cfg->GetString(DATA_SECTION, IMAGE_SAVE_PATH);
			qDebug() << "load config save path:" << SavePath;
			printf("load config save path:%s\n", SavePath.toStdString().c_str());
			if (!SavePath.isEmpty())
			{
				ui.lineEdit_SaveImagePath->setText(SavePath);
				
			}
		}


	}
	
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
	QString name = ui.comboBox_Camera1->currentText();//��ȡ���������
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
			//ui.radioButton_FreeRun1->setEnabled(true);
			ui.radioButton_FreeRun1->setEnabled(false);//���ɲɼ�������
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
			//ui.radioButton_FreeRun2->setEnabled(true);
			ui.radioButton_FreeRun2->setEnabled(false);//���ɲɼ�������

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
void CParameterSettings::SwitchCamera2Type(int index, bool checked)//index=1,2,3
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
			m_Camera2Type = 1;
			break;
		}
		case 2:
		{
			SetSoftTrigger(2);
			m_Camera2Type = 2;
			break;
		}
		case 3:
		{
			SetExternalTrigger(2);
			m_Camera2Type = 3;
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
		bool rv =SoftTriggerOnce(index,errMsg);//���1������
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

