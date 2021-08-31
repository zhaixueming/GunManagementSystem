#include <Windows.h>
#include "ParameterSettings.h"

//参数设置对话框



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

CParameterSettings *CParameterSettings::GetInstance()//单例模式
{
	if (m_Instance == NULL)// 先检查对象是否存在
	{
		m_Instance = new CParameterSettings();//不存
	}
	return m_Instance;//注意：然而，在多线程的情况下这种方法是不安全的；Lock lock; //伪代码 加锁
}

void CParameterSettings::InitVariables()
{
	m_bConnected = false;//初始化为f
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



	m_CameraCapture1 = new CImageCapture();//捕获图像
	m_CameraCapture1->start();
	m_CameraCapture2 = new CImageCapture();
	m_CameraCapture2->start();
	m_bOpenCamera1 = false;
	m_bOpenCamera2 = false;
	m_Camera1Type = 2;
	m_Camera2Type = 2;
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
	if (m_bConnected)//init=false
	{
		rv = CDatabaseOperator::GetInstance()->DisconnectDatabase(errMsg);
		if (rv)
		{
			m_bConnected = false;
			ui.pushButton_Login->setText(QString::fromLocal8Bit("登录"));
		}
		else
		{
			QMessageBox::information(this, QString::fromLatin1("断开数据库错误"), errMsg);
			qDebug() << "Disconnect database:"<<errMsg;
		}
	}
	else
	{
		rv = CDatabaseOperator::GetInstance()->ConnectDatabase(DatabaseName, UserName, Password, errMsg);//调用连接数据库函数
		if (!rv)
		{
			qDebug() << "Disconnect database:" << errMsg;
			QMessageBox::information(this, QString::fromLatin1("链接数据库错误"), errMsg);
		}
		else
		{
			m_bConnected = true;
			ui.pushButton_Login->setText(QString::fromLocal8Bit("断开"));
		}
	}
}
//海康SDK开发流程
//1.枚举设备 -> 2.创建句柄 -> 3.打开设备 -> 4.开始抓图 -> 5.获取一帧并保存图像 -> 6.停止抓图 -> 7.关闭设备 -> 8.销毁句柄
void CParameterSettings::InitCameraInfo()
{
	memset(&m_stDevList, 0, sizeof(MV_CC_DEVICE_INFO_LIST));
	int nRet = CMvCamera::EnumDevices(MV_GIGE_DEVICE, &m_stDevList);//.1枚举设备（GigE设备,设备列表）
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
		char strUserName[256] = { 0 };
		sprintf_s(strUserName, "%s_%s", pDeviceInfo->SpecialInfo.stGigEInfo.chModelName,
			pDeviceInfo->SpecialInfo.stGigEInfo.chSerialNumber);// chModelName[32]; 型号名称。chSerialNumber[16];序列号
		ui.comboBox_Camera1->addItem(strUserName);//下拉框中添加新数据
		ui.comboBox_Camera2->addItem(strUserName);
	}
}

bool CParameterSettings::OpenCamera(MV_CC_DEVICE_INFO device_info,int index)
{
	if (index == 1)
	{
		int nRet = m_MvCamera1.Open(&device_info);//.2创建句柄,打开设备
		if (nRet != MV_OK)
		{
			QMessageBox::information(this, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("打开相机失败:") + QString::number(nRet));
			m_bOpenCamera1 = false;
		}
		else
		{
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
			QMessageBox::information(this, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("打开相机失败:") + QString::number(nRet));
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

bool CParameterSettings::SetExternalTrigger(int index)
{
	if (index == 1 && m_bOpenCamera1)
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

//软触发
bool CParameterSettings::SoftTriggerOnce(int index, QString &errMsg)
{
	if (index == 1 && m_bOpenCamera1)
	{
		if (m_Camera1Type != 2)//2是触发
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
	QString name = ui.comboBox_Camera1->currentText();//当前文本的值
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
			ui.radioButton_FreeRun1->setEnabled(true);
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
			ui.radioButton_FreeRun2->setEnabled(true);
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
void CParameterSettings::SwitchCamera2Type(int index, bool checked)
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

//槽函数：主界面传递过来的相机选项--追溯的话是“拍照检视”界面的中间的显示框以及下方的两个按钮：编码拍照：1；整枪拍照：2
void CParameterSettings::ReceiveSoftTrigger(int index)
{
	if (index == 1 && m_bOpenCamera1)//相机1&&相机打开
	{  
		QString errMsg;
		bool rv =SoftTriggerOnce(index,errMsg);//相机1，软出发
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

