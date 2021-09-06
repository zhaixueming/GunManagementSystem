#include "AdminWithEphorLogin.h"
#include "QMessageBox"
#include "DatabaseOperator.h"

CAdminWithEphorLogin *CAdminWithEphorLogin::m_Instance = NULL;
CAdminWithEphorLogin::GarbageCollection CAdminWithEphorLogin::m_garbage_collection;

CAdminWithEphorLogin::CAdminWithEphorLogin(QDialog *parent /* = NULL */)
	:QDialog(parent)
{
	ui.setupUi(this);
	this->setFixedSize(this->size());
}

CAdminWithEphorLogin::~CAdminWithEphorLogin()
{

}

CAdminWithEphorLogin *CAdminWithEphorLogin::GetInstance()
{
	if (m_Instance == NULL)
	{
		m_Instance = new CAdminWithEphorLogin();
	}
	return m_Instance;
}

void CAdminWithEphorLogin::closeEvent(QCloseEvent *event)
{
	done(0);
}

void CAdminWithEphorLogin::slotLogin()
{
	//QString AdminName = ui.lineEdit_Admin->text();
	//QString AdminPwd = ui.lineEdit_AdminPwd->text();
	//QString EphorName = ui.lineEdit_Ephor->text();
	//QString EphorPwd = ui.lineEdit_EphorPwd->text();
	QString AdminName = "Admin";
	QString AdminPwd = "123456";
	QString EphorName = "123";
	QString EphorPwd = "123";
	if (AdminName.isEmpty() || AdminPwd.isEmpty() || EphorName.isEmpty() || EphorPwd.isEmpty())
	{
		return;
	}
	if ("Admin" == AdminName && "123456" == AdminPwd)
	{
		QTableData TableData;
		QString errMsg;
		QString sql = QString::fromLocal8Bit("select * from GunManager.dbo.UserTable where 姓名 = \'") + EphorName + "\'";
		sql += QString::fromLocal8Bit(" and 军官证号 = \'") + EphorPwd + "\'";
		bool rv = CDatabaseOperator::GetInstance()->execSql(sql, TableData, errMsg);
		if (!rv)
		{
			QMessageBox::information(this, QString::fromLocal8Bit("错误"), errMsg);
			return;
		}
		else if (TableData.size() == 0)
		{
			QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("监视员账号密码错误"));
			return;
		}
		done(1);
	}
	else
	{
		QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("管理员账号密码错误"));
		return;
	}
}

void CAdminWithEphorLogin::ClearInfor()
{
	ui.lineEdit_Admin->setText("");
	ui.lineEdit_AdminPwd->setText("");
	ui.lineEdit_Ephor->setText("");
	ui.lineEdit_EphorPwd->setText("");
}