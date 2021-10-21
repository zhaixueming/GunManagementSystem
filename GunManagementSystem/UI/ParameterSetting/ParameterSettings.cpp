#include <Windows.h>
#include "ParameterSettings.h"
#include"QFileDialog"
#include"Config.h"

//参数设置对话框



CParameterSettings *CParameterSettings::m_Instance = NULL;

CParameterSettings::CParameterSettings(QDialog *parent /* = NULL */)
	:QDialog(parent)
{
	ui.setupUi(this);
	this->setFixedSize(this->size()); 
	ui.pushButton_Login->setStyleSheet("QPushButton{font: 75 15pt '微软雅黑';background-color:rgb(190, 190, 190);color: rgb(34, 139, 34);border:2px groove gray;border-radius:50px;padding:2px 4px;border-style: outset;}"
		"QPushButton:hover{background-color:gray; color: rgb(10, 10, 10);}"
		"QPushButton:pressed{background-color:rgb(210, 20, 20);border-style: inset;}");
	ui.pushButton_SaveConfig->setStyleSheet("QPushButton{font: 75 15pt '微软雅黑';background-color:rgb(190, 190, 190);border:2px groove gray;border-radius:50px;padding:2px 4px;border-style: outset;}"
		"QPushButton:hover{background-color:gray; color: rgb(10, 10, 10);}"
		"QPushButton:pressed{background-color:rgb(210, 20, 20);border-style: inset;}");

	InitVariables();
	InitConnections();
	LoadConfig();
}

CParameterSettings::~CParameterSettings()
{
}

CParameterSettings *CParameterSettings::GetInstance()//单例模式
{
	if (m_Instance == NULL)
	{
		m_Instance = new CParameterSettings();
	}
	return m_Instance;
}

void CParameterSettings::InitVariables()
{
	m_bConnected = false;//初始化为false
	//打开相机pBt
	ui.pushButton_OpenCamera1->setEnabled(false);
	ui.pushButton_OpenCamera2->setEnabled(false);
	//触发类型选择
	m_BtnGroup1 = new QButtonGroup();
	m_BtnGroup1->addButton(ui.radioButton_FreeRun1, 1);
	m_BtnGroup1->addButton(ui.radioButton_SoftTrigger1, 2);
	m_BtnGroup1->addButton(ui.radioButton_ExternalTrigger1, 3);

	ui.radioButton_FreeRun1->setEnabled(false);
	ui.radioButton_SoftTrigger1->setEnabled(false);
	ui.radioButton_ExternalTrigger1->setEnabled(false);
	ui.radioButton_ExternalTrigger1->setChecked(true);//编码拍照，默认选中为硬触发

	m_BtnGroup2 = new QButtonGroup();
	m_BtnGroup2->addButton(ui.radioButton_FreeRun2, 1);
	m_BtnGroup2->addButton(ui.radioButton_SoftTrigger2, 2);
	m_BtnGroup2->addButton(ui.radioButton_ExternalTrigger2, 3);

	ui.radioButton_FreeRun2->setEnabled(false);
	ui.radioButton_SoftTrigger2->setEnabled(false);
	ui.radioButton_ExternalTrigger2->setEnabled(false);
	ui.radioButton_SoftTrigger2->setChecked(true);//整枪拍照，默认选中为软触发



	m_CameraCapture1 = new CImageCapture();//捕获编码图像
	m_CameraCapture1->start();//开启线程
	m_CameraCapture2 = new CImageCapture();//捕获整枪图像
	m_CameraCapture2->start();
	m_bOpenCamera1 = false;//初始化为False
	m_bOpenCamera2 = false;
	m_Camera1Type = 3;//编码拍照初始化为3，硬触发，记得修改
	m_Camera2Type = 2;//整枪拍照初始化为2，软触发
	InitCameraInfo();
}


//初始化参数
void CParameterSettings::InitConnections()
{
	qRegisterMetaType<Mat>("Mat");
	//CImageCapture类中，连接相机采集图像--》传递给此界面的槽函数
	connect(m_CameraCapture1, SIGNAL(SendCaptureImage(Mat)), this, SLOT(ReceiveCamera1Image(Mat)));
	connect(m_CameraCapture2, SIGNAL(SendCaptureImage(Mat)), this, SLOT(ReceiveCamera2Image(Mat)));

	connect(m_BtnGroup1, SIGNAL(buttonToggled(int, bool)), this, SLOT(SwitchCamera1Type(int, bool)));
	connect(m_BtnGroup2, SIGNAL(buttonToggled(int, bool)), this, SLOT(SwitchCamera2Type(int, bool)));
}

//参数设置界面的数据集的登录界面
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
			QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("数据库断开成功"));
			m_bConnected = false;
			ui.pushButton_Login->setText(QString::fromLocal8Bit("连接"));
			ui.lineEdit_DatabaseName->setEnabled(true);
			ui.lineEdit_UserName->setEnabled(true);
			ui.lineEdit_Password->setEnabled(true);
		}
		else
		{
			QMessageBox::information(this, QString::fromLatin1("数据库断开失败"), errMsg);
			qDebug() << "Disconnect database:"<<errMsg;
		}
	}
	else
	{
		
		rv = CDatabaseOperator::GetInstance()->ConnectDatabase(DatabaseName, UserName, Password, errMsg);//调用连接数据库函数
		if (!rv)
		{
			QMessageBox::information(this, QString::fromLatin1("数据库连接失败"), errMsg);
			qDebug() << "Disconnect database:" << errMsg;
		}
		else
		{
			//QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("数据库连接成功"));
			m_bConnected = true;
			ui.pushButton_Login->setText(QString::fromLocal8Bit("断开"));
			ui.lineEdit_DatabaseName->setEnabled(false);
			ui.lineEdit_UserName->setEnabled(false);
			ui.lineEdit_Password->setEnabled(false);
		}
	}
}
//海康SDK开发流程
//1.枚举设备 -> 2.创建句柄 -> 3.打开设备 -> 4.开始抓图 -> 5.获取一帧并保存图像 -> 6.停止抓图 -> 7.关闭设备 -> 8.销毁句柄
void CParameterSettings::InitCameraInfo()
{    
	//手持usb ，软触gige
	memset(&m_stDevList, 0, sizeof(MV_CC_DEVICE_INFO_LIST));
	int nRet = CMvCamera::EnumDevices(MV_GIGE_DEVICE | MV_USB_DEVICE, &m_stDevList);//.1枚举设备（GigE or USB设备,设备列表）
	//memset(&m_stDevList, 0, sizeof(MV_CC_DEVICE_INFO_LIST));
	//int nRet = CMvCamera::EnumDevices(MV_USB_DEVICE, &m_stDevList);//.1枚举设备（usb设备,设备列表）
	if (MV_OK != nRet)
	{
		qDebug() << QString::fromLocal8Bit("枚举相机失败:") << nRet;
		return;
	}
	if (m_stDevList.nDeviceNum > 0)//在线设备数量
	{
		ui.pushButton_OpenCamera1->setEnabled(true);//“打开相机”按钮可点击 
		ui.pushButton_OpenCamera2->setEnabled(true);
	}
	for (int i = 0; i < m_stDevList.nDeviceNum; ++i)
	{
		MV_CC_DEVICE_INFO* pDeviceInfo = m_stDevList.pDeviceInfo[i];//设备信息
		char strUserNameBianMa[256] = { 0 };
		char strUserNameZhengQiang[256] = { 0 };
		sprintf_s(strUserNameBianMa, "%s_%s", pDeviceInfo->SpecialInfo.stUsb3VInfo.chModelName,
		pDeviceInfo->SpecialInfo.stUsb3VInfo.chSerialNumber);// chModelName[32]; 型号名称。chSerialNumber[16];序列号
		
		sprintf_s(strUserNameZhengQiang, "%s_%s", pDeviceInfo->SpecialInfo.stGigEInfo.chModelName,
		pDeviceInfo->SpecialInfo.stGigEInfo.chSerialNumber);// chModelName[32]; 型号名称。chSerialNumber[16];序列号

		ui.comboBox_Camera1->addItem(strUserNameBianMa);//下拉框中添加新数据
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
		int nRet = m_MvCamera1.Open(&device_info);//.2创建句柄,打开设备   int Open(MV_CC_DEVICE_INFO* pstDeviceInfo);
		if (nRet != MV_OK)
		{
			QMessageBox::information(this, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("编码拍照相机打开失败:") + QString::number(nRet));
			m_bOpenCamera1 = false;
		}
		else
		{
			//QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("编码拍照相机打开成功"));
			unsigned int PackSize = 0;
			int nRet = m_MvCamera1.GetOptimalPacketSize(&PackSize);//ch:探测网络最佳包大小(只对GigE相机有效)
			if (nRet == MV_OK)
			{
				m_MvCamera1.SetIntValue("GevSCPSPacketSize", PackSize);
			}
			nRet = m_MvCamera1.StartGrabbing();//.4ch:开启抓图
			m_bOpenCamera1 = nRet == MV_OK;//0x00000000
			if (!m_bOpenCamera1)
			{
				QMessageBox::information(this, QString::fromLocal8Bit("错误"), "Start grabbing failed:" + QString::number(nRet));
			}
		}
		return m_bOpenCamera1;
	}
	else if (index == 2)
	{
		int nRet = m_MvCamera2.Open(&device_info);
		if (nRet != MV_OK)
		{
			QMessageBox::information(this, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("整枪拍照相机打开失败:") + QString::number(nRet));
			m_bOpenCamera2 = false;
		}
		else
		{
			//QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("整枪拍照相机打开成功"));
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
				QMessageBox::information(this, QString::fromLocal8Bit("错误"), "Start grabbing failed:" + QString::number(nRet));
			}
		}
		return m_bOpenCamera2;
	}
	return true;
}

//关闭设备
bool CParameterSettings::CloseDevice(int index)
{
	bool bSuccess = false;
	if (index == 1 && m_bOpenCamera1)
	{
		int nRet = m_MvCamera1.StopGrabbing();//.6停止抓图
		if (nRet != MV_OK)
		{
			QMessageBox::information(this, QString::fromLocal8Bit("错误"), "StopGrabbing failed:" + QString::number(nRet));
			bSuccess = false;
		}
		nRet = m_MvCamera1.Close();//.7关闭设备
		if (nRet == MV_OK)
		{
			bSuccess = true;
		}
		else
		{
			QMessageBox::information(this, QString::fromLocal8Bit("错误"), "close device failed:" + QString::number(nRet));
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
			QMessageBox::information(this, QString::fromLocal8Bit("错误"), "close device failed:" + QString::number(nRet));
			bSuccess = false;
		}
		m_bOpenCamera2 = !bSuccess;
	}
	return bSuccess;
}

//设置为自由采集
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
		QMessageBox::information(this, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("设置自由采集模式失败:") + QString::number(nRet));
		return false;
	}
	return true;
}
//软触发
bool CParameterSettings::SetSoftTrigger(int index)
{
	if (index == 1 && m_bOpenCamera1)
	{
		int nRet = m_MvCamera1.SetEnumValue("TriggerMode", MV_TRIGGER_MODE_ON);
		if (nRet != MV_OK)
		{
			QMessageBox::information(this, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("设置软触发模式失败:") + QString::number(nRet));
			return false;
		}
		nRet = m_MvCamera1.SetEnumValue("TriggerSource", MV_TRIGGER_SOURCE_SOFTWARE);
		if (nRet != MV_OK)
		{
			QMessageBox::information(this, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("设置触发源失败:") + QString::number(nRet));
			return false;
		}
	}
	else if (index == 2 && m_bOpenCamera2)
	{
		int nRet = m_MvCamera2.SetEnumValue("TriggerMode", MV_TRIGGER_MODE_ON);
		if (nRet != MV_OK)
		{
			QMessageBox::information(this, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("设置软触发模式失败:") + QString::number(nRet));
			return false;
		}
		nRet = m_MvCamera2.SetEnumValue("TriggerSource", MV_TRIGGER_SOURCE_SOFTWARE);
		if (nRet != MV_OK)
		{
			QMessageBox::information(this, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("设置触发源失败:") + QString::number(nRet));
			return false;
		}
	}
	return true;
}
//硬触发
bool CParameterSettings::SetExternalTrigger(int index)
{
	if (index == 1 && m_bOpenCamera1)//编码拍照
	{
		int nRet = m_MvCamera1.SetEnumValue("TriggerMode", MV_TRIGGER_MODE_ON);
		if (nRet != MV_OK)
		{
			QMessageBox::information(this, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("设置外触发模式失败:") + QString::number(nRet));
			return false;
		}
		nRet = m_MvCamera1.SetEnumValue("TriggerSource", MV_TRIGGER_SOURCE_LINE0);
		if (nRet != MV_OK)
		{
			
			QMessageBox::information(this, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("设置触发源失败:") + QString::number(nRet));
			return false;
		}
	
	}
	else if (index == 2 && m_bOpenCamera2)
	{
		int nRet = m_MvCamera2.SetEnumValue("TriggerMode", MV_TRIGGER_MODE_ON);
		if (nRet != MV_OK)
		{
			QMessageBox::information(this, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("设置外触发模式失败:") + QString::number(nRet));
			return false;
		}
		nRet = m_MvCamera2.SetEnumValue("TriggerSource", MV_TRIGGER_SOURCE_LINE0);
		if (nRet != MV_OK)
		{
			QMessageBox::information(this, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("设置触发源失败:") + QString::number(nRet));
			return false;
		}

		
	}
	return true;
}


bool CParameterSettings::SoftTriggerOnce(int index, QString &errMsg)
{
	if (index == 1 && m_bOpenCamera1)//m_bOpenCamera1相机1连接成功
	{
		if (m_Camera1Type != 2)//2是软触发模式
		{
			errMsg = QString::fromLocal8Bit("编码拍照相机不是软触发模式");
			return false;
		}
		int nRet = m_MvCamera1.CommandExecute("TriggerSoftware"); //相机SDK执行一次Command型命令

		if (nRet != MV_OK)
		{
			errMsg = QString::fromLocal8Bit("软触发失败:") + QString::number(nRet);
			return false;
			
		}

		
	}
	else if (index == 2 && m_bOpenCamera2)//相机2
	{
		if (m_Camera2Type != 2)
		{
			errMsg = QString::fromLocal8Bit("整抢拍照相机不是软触发模式");
			return false;
		}
		int nRet = m_MvCamera2.CommandExecute("TriggerSoftware");
		if (nRet != MV_OK)
		{
			errMsg = QString::fromLocal8Bit("软触发失败:") + QString::number(nRet);
			return false;
		}

	}
	return true;
}


//图片路径信息
QString CParameterSettings::GetSavePath()
{
	QString SavePath = ui.lineEdit_SaveImagePath->text();
	if (!SavePath.isEmpty())
	{
		return SavePath;
	}
	else
	{
		QMessageBox::information(this, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("未设置存放图片路径信息"));
		//return;
	}
}

//框中显示存放路径
void CParameterSettings::BrowseSavePath()
{
	QString filePath = QFileDialog::getExistingDirectory(this, "Open Image Save Path", QCoreApplication::applicationDirPath());
	if (!filePath.isEmpty())
	{
		ui.lineEdit_SaveImagePath->setText(filePath);
	}
	else
	{
		QMessageBox::information(this, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("未设置路径信息"));
	}

}

//信息写入到ini文件中
void CParameterSettings::SaveConfig()
{
	QString IniPath = QCoreApplication::applicationDirPath() + "/parameter_cfg.ini";//创建一个ini文件
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
	//编码相机的保存路径
	QString SavePath = ui.lineEdit_SaveImagePath->text();
	if (!SavePath.isEmpty())
	{
		cfg->Write(DATA_SECTION, IMAGE_SAVE_PATH, SavePath);

	}

	//数据库
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
//				ui.pushButton_OpenCamera1->setText(QString::fromLocal8Bit("关闭相机"));
//				break;
//			}
//		}
//	}
//}

//从本地的ini文件上载信息
void CParameterSettings::LoadConfig()
{
	QString IniPath = QCoreApplication::applicationDirPath() + "/parameter_cfg.ini";
	//CConfig *cfg = new CConfig(IniPath);
	QFileInfo info;
	if (info.exists(IniPath))
	{
		CConfig *cfg = new CConfig(IniPath);

		//相机1名字
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
				Camera1Controller();//打开相机1
			}

		}
		//相机2名字
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
				Camera2Controller();//打开相机2
			}

		}

		//数据库
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

		//保存路径
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


//关闭所有相机
void CParameterSettings::closeAllCamera()
{
	QString errMsg;
	if (m_bOpenCamera1)
	{
		m_CameraCapture1->SetCameraStatus(false);
		Sleep(100);
		CloseDevice(1);
	}
	m_CameraCapture1->StopThread();//线程1
	if (m_bOpenCamera2)
	{
		m_CameraCapture2->SetCameraStatus(false);
		Sleep(100);
		CloseDevice(2);
	}
	m_CameraCapture2->StopThread();//线程2
}

//槽函数：参数设置界面的编码拍照中的“打开相机”触发后——》此槽函数
void CParameterSettings::Camera1Controller()
{
	QString name = ui.comboBox_Camera1->currentText();//获取相机的名字
	int index = ui.comboBox_Camera1->currentIndex();
	if (m_bOpenCamera1)
	{
		m_CameraCapture1->SetCameraStatus(false);
		bool rv = CloseDevice(1);//returnvalue
		if (!rv)
		{
			return;
		}
		ui.pushButton_OpenCamera1->setText(QString::fromLocal8Bit("打开相机"));
		m_bOpenCamera1 = false;
		m_Camera1Name.clear();
		ui.radioButton_FreeRun1->setEnabled(false);//自由采集单选按钮不可点击
		ui.radioButton_SoftTrigger1->setEnabled(false);//软采集单选按钮不可点击
		ui.radioButton_ExternalTrigger1->setEnabled(false);//硬触发单选按钮不可点击
	}
	else
	{
		if (name == m_Camera1Name)
		{
			QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("相机已被占用"));
			return;
		}
		else if (index <= m_stDevList.nDeviceNum)//在线设备数量
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
			ui.radioButton_FreeRun1->setEnabled(false);//自由采集不启用
			ui.radioButton_SoftTrigger1->setEnabled(true);
			ui.radioButton_ExternalTrigger1->setEnabled(true);
			ui.pushButton_OpenCamera1->setText(QString::fromLocal8Bit("关闭相机"));
		}
	}
}


//槽函数：参数设置界面的整枪拍照中的“打开相机”触发后——》此槽函数
void CParameterSettings::Camera2Controller()
{
	QString name = ui.comboBox_Camera2->currentText();
	int index = ui.comboBox_Camera2->currentIndex();
	if (m_bOpenCamera2)
	{
		m_CameraCapture2->SetCameraStatus(false);//捕获相机，调用SetCameraStatus(false)函数并设置相机状态
		bool rv = CloseDevice(2);
		if (!rv)
		{
			return;
		}
		ui.pushButton_OpenCamera2->setText(QString::fromLocal8Bit("打开相机"));
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
			QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("相机已被占用"));
			return;
		}
		else if (index <= m_stDevList.nDeviceNum)//在线设备数量
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
			ui.radioButton_FreeRun2->setEnabled(false);//自由采集不启用

			ui.radioButton_SoftTrigger2->setEnabled(true);
			ui.radioButton_ExternalTrigger2->setEnabled(true);
			ui.pushButton_OpenCamera2->setText(QString::fromLocal8Bit("关闭相机"));
		}
	}
}


//切换相机1类型
void CParameterSettings::SwitchCamera1Type(int index, bool checked)
{
	if (checked)
	{
		if (!m_bOpenCamera1)
		{
			ui.label_Info->setText(QString::fromLocal8Bit("相机未打开"));//“参数设置”界面中下黄框
			return;
		}
		QString errMsg;
		switch (index)
		{
			case 1:
			{
				SetFreeFrame(1);//自由采集
				m_Camera1Type = 1;
				break;
			}
			case 2:
			{
				SetSoftTrigger(1);//软触发
				m_Camera1Type = 2;
				break;
			}
			case 3:
			{
				SetExternalTrigger(1);//外部触发
				m_Camera1Type = 3;
				break;
			}
		}
	}
}

//切换相机2类型
void CParameterSettings::SwitchCamera2Type(int index, bool checked)//index=1,2,3
{
	if (checked)
	{
		if (!m_bOpenCamera2)
		{
			ui.label_Info->setText(QString::fromLocal8Bit("相机未打开"));
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

//槽函数：主界面传递过来的相机选项--追溯的话是“拍照检视”界面的中间的显示框以及下方的两个按钮：编码拍照：1；整枪拍照：2
void CParameterSettings::ReceiveSoftTrigger(int index)
{
	if (index == 1 && m_bOpenCamera1)//相机1&&相机打开
	{  
		QString errMsg;
		bool rv =SoftTriggerOnce(index,errMsg);//相机1，软触发
		if (!rv)
		{
			QMessageBox::information(this, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("编码拍照:")+errMsg);
			return;
		}
	}
	else if (index == 2 && m_bOpenCamera2)
	{
		QString errMsg;
		bool rv = SoftTriggerOnce(index,errMsg);
		if (!rv)
		{
			QMessageBox::information(this, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("整抢拍照:") + errMsg);
			return;
		}
	}
}

void CParameterSettings::ReceiveCamera1Image(Mat image)
{
	emit SendCameraImage(1, image);//选择相机
}

void CParameterSettings::ReceiveCamera2Image(Mat image)
{
	emit SendCameraImage(2, image);
}

