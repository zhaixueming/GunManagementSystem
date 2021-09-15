#include "SysMainWindow.h"
#include <QTextEdit>
#include <qmutex.h>
#include <QDir>
#include <QTextStream>
#include <QDateTime>
#include "SettingsLogin.h"
#include <QTextToSpeech>


//�����־
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
	qInstallMessageHandler(outputMessage);//�����ϸ��־


	//QTextToSpeech *m_speech = new QTextToSpeech();
	//QStringList list = QTextToSpeech::availableEngines();
	////m_speech->setLocale(QLocale::English);//�������Ի���
	//m_speech->setLocale(QLocale("Microsoft KangKang"));//�������Ի���
	//m_speech->setRate(0.0);//��������-1.0��1.0
	//m_speech->setPitch(1.0);//��������-1.0��1.0
	//m_speech->setVolume(1.0);//��������0.0-1.0

	//QVector<QLocale> dd = m_speech->availableLocales();
	//QVector<QVoice> vv = m_speech->availableVoices();
	//	m_speech->say("hello world");
	//	m_speech->say("zcf��i love you");
	//	m_speech->say("�������������������һ�Ȼ��ȣ�����Ҳ���������������������������");
	//


	this->setFixedSize(this->size());//��ֹ�ϷŴ���
	InitVariables();//��ʼ������
	InitConnections();//��ʼ���źŲۺ���
}

SysMainWindow::~SysMainWindow()
{
	CParameterSettings::GetInstance()->closeAllCamera();
}

//��ʼ���������˺Ź���������ӣ���Ϣ����
void SysMainWindow::InitVariables()
{
	ui.pushButton_AcManager->setStyleSheet("QPushButton:hover{background-color: rgb(0,170,0);color:rgb(255,255,255);}"
		                                   "QPushButton{color:rgb(0,170,0);font:75 30pt '΢���ź�'}");
	ui.pushButton_CodeReview->setStyleSheet("QPushButton:hover{background-color: rgb(0,170,0);color:rgb(255,255,255);}"
											"QPushButton{color:rgb(0,170,0);font:75 30pt '΢���ź�'}");
	ui.pushButton_InfoManager->setStyleSheet("QPushButton:hover{background-color: rgb(0,170,0);color:rgb(255,255,255);}"
											 "QPushButton{color:rgb(0,170,0);font:75 30pt '΢���ź�'}");
}


//��ʼ���źŲۺ���
void SysMainWindow::InitConnections()
{
	connect(this, SIGNAL(SendStackWidgetIndex(int)), &m_SystemManager, SLOT(ReceiveStackWidgetIndex(int)));//������--���Ӵ���
	connect(CParameterSettings::GetInstance(), SIGNAL(SendCameraImage(int,Mat)), this, SLOT(ReceiveCameraImage(int,Mat)));//SendCameraImage(int,Mat),intΪ1��2
	connect(this, SIGNAL(SendCameraImage(int,Mat)), &m_SystemManager, SLOT(ReceiveImage(int,Mat)));//ͼ������--��ϵͳ������ͼ��ʶ�����
	
    //���ռ��ӽ�����м����ʾ���Լ��·���������ť���������գ�1����ǹ���գ�2---������������ReceiveSoftTrigger(int)�ۺ���
	connect(&m_SystemManager, SIGNAL(SendSoftTrigger(int)),this , SLOT(ReceiveSoftTrigger(int)));

	//������ReceiveSoftTrigger(int)�ۺ�����ֱ��ʹ���źš����������ý���
	connect(this, SIGNAL(SendSoftTrigger(int)), CParameterSettings::GetInstance(), SLOT(ReceiveSoftTrigger(int)));
}

void SysMainWindow::slotAccountManager()//���˺Ź�����ť---���˲ۺ���
{
	bool rv = CDatabaseOperator::GetInstance()->GetConnectStatus();//�������ݳɹ�
	if (!rv)
	{
		QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("���ݿ�δ����"));
		return;
	}
	emit SendStackWidgetIndex(0);//����--���˺Ź��� ��ť
	CAdminLogin::GetInstance()->ClearInfor();
	if (1 == CAdminLogin::GetInstance()->exec())
	{
		m_SystemManager.exec();
	}
}

void SysMainWindow::slotCodeReview()//��������ӡ���ť---���˲ۺ���
{
 	bool rv = CDatabaseOperator::GetInstance()->GetConnectStatus();
 	if (!rv)
 	{
 		QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("���ݿ�δ����"));
 		return;
 	}
	emit SendStackWidgetIndex(1);//
	CAdminWithEphorLogin::GetInstance()->ClearInfor();
	if (1 == CAdminWithEphorLogin::GetInstance()->exec())
	{
		m_SystemManager.exec();
	}
}

void SysMainWindow::slotInfoManager()//����Ϣ������ť---���˲ۺ���
{
 	bool rv = CDatabaseOperator::GetInstance()->GetConnectStatus();
 	if (!rv)
 	{
 		QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("���ݿ�δ����"));
 		return;
 	}
	emit SendStackWidgetIndex(2);
	CAdminWithEphorLogin::GetInstance()->ClearInfor();
	if (1 == CAdminWithEphorLogin::GetInstance()->exec())
	{
		m_SystemManager.exec();
	}
}

void SysMainWindow::keyPressEvent(QKeyEvent *ev)//��Ctrl+F11�����������ÿ����,��Ctrl+F12�������ڴ���
{
	if ((ev->modifiers() == Qt::ControlModifier) && (ev->key() == Qt::Key_F11))//Qt::ControlModifier����Ctrl��
	{
		//�����������ÿ����
		CSettingsLogin::GetInstance()->ClearInformation();
		int ret = CSettingsLogin::GetInstance()->exec();
		if (ret == 1)
		{
			CParameterSettings::GetInstance()->exec();
		}
	}
	else if ((ev->modifiers() == Qt::ControlModifier) && (ev->key() == Qt::Key_F12))
	{
		//�������ڴ���
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