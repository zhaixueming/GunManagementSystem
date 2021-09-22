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
	ui.pushButton_Login->setStyleSheet("QPushButton{font: 75 24pt '微软雅黑';background-color: rgb(255, 0, 0);color: rgb(255, 255, 0);border:2px groove yellow;border-radius:150px;padding:2px 4px;border-style: outset;}"
		"QPushButton:hover{background-color:rgb(255, 0, 0); color: rgb(238, 221, 130);}");
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

//void CAdminWithEphorLogin::slotLogin()
//{
//	//QString AdminName = ui.lineEdit_Admin->text();
//	//QString AdminPwd = ui.lineEdit_AdminPwd->text();
//	//QString EphorName = ui.lineEdit_Ephor->text();
//	//QString EphorPwd = ui.lineEdit_EphorPwd->text();
//	QString AdminName = "Admin";
//	QString AdminPwd = "123456";
//	QString EphorName = "123";
//	QString EphorPwd = "123";
//	if (AdminName.isEmpty() || AdminPwd.isEmpty() || EphorName.isEmpty() || EphorPwd.isEmpty())
//	{
//		return;
//	}
//	if ("Admin" == AdminName && "123456" == AdminPwd)
//	{
//		QTableData TableData;
//		QString errMsg;
//		QString sql = QString::fromLocal8Bit("select * from GunManager.dbo.UserTable where 姓名 = \'") + EphorName + "\'";
//		sql += QString::fromLocal8Bit(" and 军官证号 = \'") + EphorPwd + "\'";
//		bool rv = CDatabaseOperator::GetInstance()->execSql(sql, TableData, errMsg);
//		if (!rv)
//		{
//			QMessageBox::information(this, QString::fromLocal8Bit("错误"), errMsg);
//			return;
//		}
//		else if (TableData.size() == 0)
//		{
//			QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("监督员账号密码错误"));
//			return;
//		}
//		done(1);
//	}
//	else
//	{
//		QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("管理员账号密码错误"));
//		return;
//	}
//}

bool CAdminWithEphorLogin::CheckCodeOperator(QString &errMsg)
{
	QTableData OperatorTableData;
	QTableData EphorTableData;
	QString OperatorName = ui.lineEdit_Operator->text();
	QString OperatorPwd = ui.lineEdit_OperatorPwd->text();
	QString EphorName = ui.lineEdit_Ephor->text();
	QString EphorPwd = ui.lineEdit_EphorPwd->text();
	QString OperatorsSql = QString::fromLocal8Bit("select * from GunManager.dbo.UserTable where 军官证号 = \'") + OperatorName + "\'";
	OperatorsSql += QString::fromLocal8Bit(" and 密码 = \'") + OperatorPwd + "\'";

	QString EphorSql = QString::fromLocal8Bit("select * from GunManager.dbo.UserTable where 军官证号 = \'") + EphorName + "\'";
	EphorSql += QString::fromLocal8Bit(" and 密码 = \'") + EphorPwd + "\'";

	QString dbErrMsg;
	bool rv = CDatabaseOperator::GetInstance()->execSql(OperatorsSql, OperatorTableData, dbErrMsg);
	if (!rv)
	{
		errMsg = QString::fromLocal8Bit("查询编码检视操作权限错误:") + dbErrMsg;
		return false; 
	}
	else if (OperatorTableData.size() == 0)
	{
		errMsg = QString::fromLocal8Bit("编码检视操作员账号或密码错误，请重新输入!"); 
		return false;
	}
	else if (OperatorTableData.size() == 1)
	{
		QList<QVariant > OneRowData = OperatorTableData.at(0);
		bool bOK = OneRowData.at(3).toBool();
		if(!bOK)
		{
			errMsg = QString::fromLocal8Bit("此军官无编码检视操作权限");
		}
		else
		{
			rv = CDatabaseOperator::GetInstance()->execSql(EphorSql, EphorTableData, dbErrMsg);
			if (!rv)
			{
				errMsg = QString::fromLocal8Bit("查询编码检视监督权限错误:") + dbErrMsg;
				return false;
			}
			else if (EphorTableData.size() == 0)
			{
				errMsg = QString::fromLocal8Bit("编码检视督权员账号或密码错误，请重新输入!");
				return false;
			}
			else if (EphorTableData.size() == 1)
			{
				QList<QVariant > OneRowData = EphorTableData.at(0);
				bool bOK = OneRowData.at(4).toBool();
				if (!bOK)
				{
					errMsg = QString::fromLocal8Bit("此军官无编码检视督权权限");
				}
				else
				{
					return true;
				}
			}
		}
	}
	return false;
}

bool CAdminWithEphorLogin::CheckInfoOperpator(QString &errMsg)
{
	QTableData OperatorTableData;
	QTableData EphorTableData;
	QString OperatorName = ui.lineEdit_Operator->text();
	QString OperatorPwd = ui.lineEdit_OperatorPwd->text();
	QString EphorName = ui.lineEdit_Ephor->text();
	QString EphorPwd = ui.lineEdit_EphorPwd->text();
	QString OperatorsSql = QString::fromLocal8Bit("select * from GunManager.dbo.UserTable where 军官证号 = \'") + OperatorName + "\'";
	OperatorsSql += QString::fromLocal8Bit(" and 密码 = \'") + OperatorPwd + "\'";

	QString EphorSql = QString::fromLocal8Bit("select * from GunManager.dbo.UserTable where 军官证号 = \'") + EphorName + "\'";
	EphorSql += QString::fromLocal8Bit(" and 密码 = \'") + EphorPwd + "\'";

	QString dbErrMsg;
	bool rv = CDatabaseOperator::GetInstance()->execSql(OperatorsSql, OperatorTableData, dbErrMsg);
	if (!rv)
	{
		errMsg = QString::fromLocal8Bit("查询信息管理操作权限错误:") + dbErrMsg;
		return false;
	}
	else if (OperatorTableData.size() == 0)
	{
		errMsg = QString::fromLocal8Bit("信息管理操作员账号或密码错误，请重新输入!");
		return false;
	}
	else if (OperatorTableData.size() == 1)
	{
		QList<QVariant > OneRowData = OperatorTableData.at(0);
		bool bOK = OneRowData.at(5).toBool();
		if (!bOK)
		{
			errMsg = QString::fromLocal8Bit("此军官无信息管理操作权限");
		}
		else
		{
			rv = CDatabaseOperator::GetInstance()->execSql(EphorSql, EphorTableData, dbErrMsg);
			if (!rv)
			{
				errMsg = QString::fromLocal8Bit("查询信息管理监督权限错误:") + dbErrMsg;
				return false;
			}
			else if (EphorTableData.size() == 0)
			{
				errMsg = QString::fromLocal8Bit("信息管理督权员账号或密码错误，请重新输入!");
				return false;
			}
			else if (EphorTableData.size() == 1)
			{
				QList<QVariant > OneRowData = EphorTableData.at(0);
				bool bOK = OneRowData.at(6).toBool();
				if (!bOK)
				{
					errMsg = QString::fromLocal8Bit("此军官信息管理督权权限");
				}
				else
				{
					return true;
				}
			}
		}
	}
	return false;
}

void CAdminWithEphorLogin::slotLogin()
{
	QString OperatorName = ui.lineEdit_Operator->text();
	QString OperatorPwd = ui.lineEdit_OperatorPwd->text();
	QString EphorName = ui.lineEdit_Ephor->text();
	QString EphorPwd = ui.lineEdit_EphorPwd->text();

	if (OperatorName.isEmpty() || OperatorPwd.isEmpty() || EphorName.isEmpty() || EphorPwd.isEmpty())
	{
		QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("请输入账号和密码！"));
		return;
	}
	else
	{
		//编码检视
		QString errMsg;
		bool rv = false;
		if (m_Flag == 1)
		{
			rv = CheckCodeOperator(errMsg);
			if (!rv)
			{
				QMessageBox::information(this, QString::fromLocal8Bit("提示"), errMsg);
				return;
			}
		}
		else if (m_Flag == 2)
		{
			rv = CheckInfoOperpator(errMsg);
			if (!rv)
			{
				QMessageBox::information(this, QString::fromLocal8Bit("提示"), errMsg);
				return;
			}
		}
	}
	done(1);
}

void CAdminWithEphorLogin::SetLoginFlag(int flag)
{
	m_Flag = flag;
}

void CAdminWithEphorLogin::ClearInfor()
{
	ui.lineEdit_Operator->setText("");
	ui.lineEdit_OperatorPwd->setText("");
	ui.lineEdit_Ephor->setText("");
	ui.lineEdit_EphorPwd->setText("");
}