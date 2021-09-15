#include "SysMainWindow.h"
#include <QTextEdit>
#include <qmutex.h>
#include <QDir>
#include <QTextStream>
#include <QDateTime>
#include "SettingsLogin.h"
#include <QTextToSpeech>


//输出日志
void outputMessage(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
	static QMutex mutex;
	mutex.lock();

	QString text;
	switch (type)
	{
	case QtDebugMsg:
		text = QString("Debug:");
		break;

	case QtWarningMsg:
		text = QString("Warning:");
		break;

	case QtCriticalMsg:
		text = QString("Critical:");
		break;

	case QtFatalMsg:
		text = QString("Fatal:");
	}

	QString context_info = QString("File:(%1) Line:(%2)").arg(QString(context.file)).arg(context.line);
	QString current_date_time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ddd");
	QString current_date = QString("(%1)").arg(current_date_time);
	QString message = QString("%1          %2 %3 %4").arg(current_date).arg(text).arg(context_info).arg(msg);
	QString LogPath = QCoreApplication::applicationDirPath();
	LogPath.append("/log");
	QDir dir(LogPath);
	if (!dir.exists(LogPath))
	{
		dir.mkdir(LogPath);
	}
	QString logFile = LogPath + "/" + QDateTime::currentDateTime().toString("yyyy-MM-dd");
	logFile.append(".txt");
	QFile file(logFile);
	file.open(QIODevice::WriteOnly | QIODevice::Append);
	QTextStream text_stream(&file);
	text_stream << message << "\r\n";
	file.flush();
	file.close();
	mutex.unlock();
}

SysMainWindow::SysMainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	qInstallMessageHandler(outputMessage);//输出详细日志


	//QTextToSpeech *m_speech = new QTextToSpeech();
	//QStringList list = QTextToSpeech::availableEngines();
	////m_speech->setLocale(QLocale::English);//设置语言环境
	//m_speech->setLocale(QLocale("Microsoft KangKang"));//设置语言环境
	//m_speech->setRate(0.0);//设置语速-1.0到1.0
	//m_speech->setPitch(1.0);//设置音高-1.0到1.0
	//m_speech->setVolume(1.0);//设置音量0.0-1.0

	//QVector<QLocale> dd = m_speech->availableLocales();
	//QVector<QVoice> vv = m_speech->availableVoices();
	//	m_speech->say("hello world");
	//	m_speech->say("zcf，i love you");
	//	m_speech->say("现在语音聊天机器人是一度火热，网上也有其他编程软件的语音聊天机器人");
	//


	this->setFixedSize(this->size());//禁止拖放窗体
	InitVariables();//初始化变量
	InitConnections();//初始化信号槽函数
}

SysMainWindow::~SysMainWindow()
{
	CParameterSettings::GetInstance()->closeAllCamera();
}

//初始化变量：账号管理，编码检视，信息管理
void SysMainWindow::InitVariables()
{
	ui.pushButton_AcManager->setStyleSheet("QPushButton:hover{background-color: rgb(0,170,0);color:rgb(255,255,255);}"
		                                   "QPushButton{color:rgb(0,170,0);font:75 30pt '微软雅黑'}");
	ui.pushButton_CodeReview->setStyleSheet("QPushButton:hover{background-color: rgb(0,170,0);color:rgb(255,255,255);}"
											"QPushButton{color:rgb(0,170,0);font:75 30pt '微软雅黑'}");
	ui.pushButton_InfoManager->setStyleSheet("QPushButton:hover{background-color: rgb(0,170,0);color:rgb(255,255,255);}"
											 "QPushButton{color:rgb(0,170,0);font:75 30pt '微软雅黑'}");
}


//初始化信号槽函数
void SysMainWindow::InitConnections()
{
	connect(this, SIGNAL(SendStackWidgetIndex(int)), &m_SystemManager, SLOT(ReceiveStackWidgetIndex(int)));//主窗口--》子窗口
	connect(CParameterSettings::GetInstance(), SIGNAL(SendCameraImage(int,Mat)), this, SLOT(ReceiveCameraImage(int,Mat)));//SendCameraImage(int,Mat),int为1，2
	connect(this, SIGNAL(SendCameraImage(int,Mat)), &m_SystemManager, SLOT(ReceiveImage(int,Mat)));//图像数据--》系统管理，拍图或识别编码
	
    //拍照检视界面的中间的显示框以及下方的两个按钮：编码拍照：1；整枪拍照：2---》传给主界面ReceiveSoftTrigger(int)槽函数
	connect(&m_SystemManager, SIGNAL(SendSoftTrigger(int)),this , SLOT(ReceiveSoftTrigger(int)));

	//主界面ReceiveSoftTrigger(int)槽函数中直接使用信号—》参数设置界面
	connect(this, SIGNAL(SendSoftTrigger(int)), CParameterSettings::GetInstance(), SLOT(ReceiveSoftTrigger(int)));
}

void SysMainWindow::slotAccountManager()//“账号管理”按钮---》此槽函数
{
	bool rv = CDatabaseOperator::GetInstance()->GetConnectStatus();//连接数据成功
	if (!rv)
	{
		QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("数据库未连接"));
		return;
	}
	emit SendStackWidgetIndex(0);//发射--》账号管理 按钮
	CAdminLogin::GetInstance()->ClearInfor();
	if (1 == CAdminLogin::GetInstance()->exec())
	{
		m_SystemManager.exec();
	}
}

void SysMainWindow::slotCodeReview()//“编码检视”按钮---》此槽函数
{
 	bool rv = CDatabaseOperator::GetInstance()->GetConnectStatus();
 	if (!rv)
 	{
 		QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("数据库未连接"));
 		return;
 	}
	emit SendStackWidgetIndex(1);//
	CAdminWithEphorLogin::GetInstance()->ClearInfor();
	if (1 == CAdminWithEphorLogin::GetInstance()->exec())
	{
		m_SystemManager.exec();
	}
}

void SysMainWindow::slotInfoManager()//“信息管理”按钮---》此槽函数
{
 	bool rv = CDatabaseOperator::GetInstance()->GetConnectStatus();
 	if (!rv)
 	{
 		QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("数据库未连接"));
 		return;
 	}
	emit SendStackWidgetIndex(2);
	CAdminWithEphorLogin::GetInstance()->ClearInfor();
	if (1 == CAdminWithEphorLogin::GetInstance()->exec())
	{
		m_SystemManager.exec();
	}
}

void SysMainWindow::keyPressEvent(QKeyEvent *ev)//按Ctrl+F11弹出参数设置口令窗口,按Ctrl+F12弹出关于窗口
{
	if ((ev->modifiers() == Qt::ControlModifier) && (ev->key() == Qt::Key_F11))//Qt::ControlModifier按下Ctrl键
	{
		//弹出参数设置口令窗口
		CSettingsLogin::GetInstance()->ClearInformation();
		int ret = CSettingsLogin::GetInstance()->exec();
		if (ret == 1)
		{
			CParameterSettings::GetInstance()->exec();
		}
	}
	else if ((ev->modifiers() == Qt::ControlModifier) && (ev->key() == Qt::Key_F12))
	{
		//弹出关于窗口
	}
}

void SysMainWindow::ReceiveSoftTrigger(int index)
{
	emit SendSoftTrigger(index);
}

void SysMainWindow::ReceiveCameraImage(int index, Mat image)
{
	emit SendCameraImage(index, image);
}