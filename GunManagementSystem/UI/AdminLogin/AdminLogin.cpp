#include "AdminLogin.h"
#include "QMessageBox"

CAdminLogin *CAdminLogin::m_Instance = NULL;
CAdminLogin::GarbageCollection CAdminLogin::m_garbage_collection;

CAdminLogin::CAdminLogin(QDialog *parent /* = NULL */)
	:QDialog(parent)
{
	ui.setupUi(this);
	this->setFixedSize(this->size());
	ui.pushButton_Login->setStyleSheet("QPushButton{font: 75 24pt '微软雅黑';background-color: rgb(255, 0, 0);color: rgb(255, 255, 0);border:2px groove yellow;border-radius:150px;padding:2px 4px;border-style: outset;}"
		"QPushButton:hover{background-color:rgb(255, 0, 0); color: rgb(238, 221, 130);}");
}

CAdminLogin::~CAdminLogin()
{

}

CAdminLogin *CAdminLogin::GetInstance()//单例模式
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

void CAdminLogin::slotLogin()//账号操槽函数
{
	QString AdminName = ui.lineEdit_Admin->text();
	QString AdminPwd = ui.lineEdit_AdminPwd->text();
	if ("Admin" == AdminName && "123456" == AdminPwd || "Admin1" == AdminName && "1234567" == AdminPwd)
	{
		done(1);
	}
	else if (AdminName.isEmpty() || AdminPwd.isEmpty())
	{
		QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("请输入账号和密码！"));
		return;
	}
	/*else if("123456" == AdminPwd)
	{
		QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("用户名不存在"));
	}
	else if ("Admin" == AdminName)
	{
		QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("密码错误"));
	}*/
	else
	{
		QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("登录信息错误"));
	}
}

void CAdminLogin::ClearInfor()
{
	ui.lineEdit_Admin->setText("");
	ui.lineEdit_AdminPwd->setText("");
}