#include "AdminLogin.h"
#include "QMessageBox"

CAdminLogin *CAdminLogin::m_Instance = NULL;
CAdminLogin::GarbageCollection CAdminLogin::m_garbage_collection;

CAdminLogin::CAdminLogin(QDialog *parent /* = NULL */)
	:QDialog(parent)
{
	ui.setupUi(this);
	this->setFixedSize(this->size());
	ui.pushButton_Login->setStyleSheet("QPushButton{font: 75 24pt '΢���ź�';background-color: rgb(255, 0, 0);color: rgb(255, 255, 0);border:2px groove yellow;border-radius:150px;padding:2px 4px;border-style: outset;}"
		"QPushButton:hover{background-color:rgb(255, 0, 0); color: rgb(238, 221, 130);}");
}

CAdminLogin::~CAdminLogin()
{

}

CAdminLogin *CAdminLogin::GetInstance()//����ģʽ
{
	if (m_Instance == NULL)
	{
		m_Instance = new CAdminLogin();
	}
	return m_Instance;
}

void CAdminLogin::closeEvent(QCloseEvent *event)
{
	done(0);
}

void CAdminLogin::slotLogin()//�˺Ųٲۺ���
{
	QString AdminName = ui.lineEdit_Admin->text();
	QString AdminPwd = ui.lineEdit_AdminPwd->text();
	if ("Admin" == AdminName && "123456" == AdminPwd || "Admin1" == AdminName && "1234567" == AdminPwd)
	{
		done(1);
	}
	else if (AdminName.isEmpty() || AdminPwd.isEmpty())
	{
		QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("�������˺ź����룡"));
		return;
	}
	/*else if("123456" == AdminPwd)
	{
		QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("�û���������"));
	}
	else if ("Admin" == AdminName)
	{
		QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("�������"));
	}*/
	else
	{
		QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("��¼��Ϣ����"));
	}
}

void CAdminLogin::ClearInfor()
{
	ui.lineEdit_Admin->setText("");
	ui.lineEdit_AdminPwd->setText("");
}