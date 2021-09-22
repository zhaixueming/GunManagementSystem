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
	ui.pushButton_Login->setStyleSheet("QPushButton{font: 75 24pt '΢���ź�';background-color: rgb(255, 0, 0);color: rgb(255, 255, 0);border:2px groove yellow;border-radius:150px;padding:2px 4px;border-style: outset;}"
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
//		QString sql = QString::fromLocal8Bit("select * from GunManager.dbo.UserTable where ���� = \'") + EphorName + "\'";
//		sql += QString::fromLocal8Bit(" and ����֤�� = \'") + EphorPwd + "\'";
//		bool rv = CDatabaseOperator::GetInstance()->execSql(sql, TableData, errMsg);
//		if (!rv)
//		{
//			QMessageBox::information(this, QString::fromLocal8Bit("����"), errMsg);
//			return;
//		}
//		else if (TableData.size() == 0)
//		{
//			QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("�ලԱ�˺��������"));
//			return;
//		}
//		done(1);
//	}
//	else
//	{
//		QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("����Ա�˺��������"));
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
	QString OperatorsSql = QString::fromLocal8Bit("select * from GunManager.dbo.UserTable where ����֤�� = \'") + OperatorName + "\'";
	OperatorsSql += QString::fromLocal8Bit(" and ���� = \'") + OperatorPwd + "\'";

	QString EphorSql = QString::fromLocal8Bit("select * from GunManager.dbo.UserTable where ����֤�� = \'") + EphorName + "\'";
	EphorSql += QString::fromLocal8Bit(" and ���� = \'") + EphorPwd + "\'";

	QString dbErrMsg;
	bool rv = CDatabaseOperator::GetInstance()->execSql(OperatorsSql, OperatorTableData, dbErrMsg);
	if (!rv)
	{
		errMsg = QString::fromLocal8Bit("��ѯ������Ӳ���Ȩ�޴���:") + dbErrMsg;
		return false; 
	}
	else if (OperatorTableData.size() == 0)
	{
		errMsg = QString::fromLocal8Bit("������Ӳ���Ա�˺Ż������������������!"); 
		return false;
	}
	else if (OperatorTableData.size() == 1)
	{
		QList<QVariant > OneRowData = OperatorTableData.at(0);
		bool bOK = OneRowData.at(3).toBool();
		if(!bOK)
		{
			errMsg = QString::fromLocal8Bit("�˾����ޱ�����Ӳ���Ȩ��");
		}
		else
		{
			rv = CDatabaseOperator::GetInstance()->execSql(EphorSql, EphorTableData, dbErrMsg);
			if (!rv)
			{
				errMsg = QString::fromLocal8Bit("��ѯ������ӼලȨ�޴���:") + dbErrMsg;
				return false;
			}
			else if (EphorTableData.size() == 0)
			{
				errMsg = QString::fromLocal8Bit("������Ӷ�ȨԱ�˺Ż������������������!");
				return false;
			}
			else if (EphorTableData.size() == 1)
			{
				QList<QVariant > OneRowData = EphorTableData.at(0);
				bool bOK = OneRowData.at(4).toBool();
				if (!bOK)
				{
					errMsg = QString::fromLocal8Bit("�˾����ޱ�����Ӷ�ȨȨ��");
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
	QString OperatorsSql = QString::fromLocal8Bit("select * from GunManager.dbo.UserTable where ����֤�� = \'") + OperatorName + "\'";
	OperatorsSql += QString::fromLocal8Bit(" and ���� = \'") + OperatorPwd + "\'";

	QString EphorSql = QString::fromLocal8Bit("select * from GunManager.dbo.UserTable where ����֤�� = \'") + EphorName + "\'";
	EphorSql += QString::fromLocal8Bit(" and ���� = \'") + EphorPwd + "\'";

	QString dbErrMsg;
	bool rv = CDatabaseOperator::GetInstance()->execSql(OperatorsSql, OperatorTableData, dbErrMsg);
	if (!rv)
	{
		errMsg = QString::fromLocal8Bit("��ѯ��Ϣ�������Ȩ�޴���:") + dbErrMsg;
		return false;
	}
	else if (OperatorTableData.size() == 0)
	{
		errMsg = QString::fromLocal8Bit("��Ϣ�������Ա�˺Ż������������������!");
		return false;
	}
	else if (OperatorTableData.size() == 1)
	{
		QList<QVariant > OneRowData = OperatorTableData.at(0);
		bool bOK = OneRowData.at(5).toBool();
		if (!bOK)
		{
			errMsg = QString::fromLocal8Bit("�˾�������Ϣ�������Ȩ��");
		}
		else
		{
			rv = CDatabaseOperator::GetInstance()->execSql(EphorSql, EphorTableData, dbErrMsg);
			if (!rv)
			{
				errMsg = QString::fromLocal8Bit("��ѯ��Ϣ����ලȨ�޴���:") + dbErrMsg;
				return false;
			}
			else if (EphorTableData.size() == 0)
			{
				errMsg = QString::fromLocal8Bit("��Ϣ����ȨԱ�˺Ż������������������!");
				return false;
			}
			else if (EphorTableData.size() == 1)
			{
				QList<QVariant > OneRowData = EphorTableData.at(0);
				bool bOK = OneRowData.at(6).toBool();
				if (!bOK)
				{
					errMsg = QString::fromLocal8Bit("�˾�����Ϣ����ȨȨ��");
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
		QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("�������˺ź����룡"));
		return;
	}
	else
	{
		//�������
		QString errMsg;
		bool rv = false;
		if (m_Flag == 1)
		{
			rv = CheckCodeOperator(errMsg);
			if (!rv)
			{
				QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"), errMsg);
				return;
			}
		}
		else if (m_Flag == 2)
		{
			rv = CheckInfoOperpator(errMsg);
			if (!rv)
			{
				QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"), errMsg);
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