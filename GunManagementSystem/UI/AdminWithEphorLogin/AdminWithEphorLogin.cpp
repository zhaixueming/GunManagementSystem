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
	ui.pushButton_Login->setStyleSheet("QPushButton{font: 75 24pt 'Î¢ÈíÑÅºÚ';background-color: rgb(255, 0, 0);color: rgb(255, 255, 0);border:2px groove yellow;border-radius:150px;padding:2px 4px;border-style: outset;}"
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
//		QString sql = QString::fromLocal8Bit("select * from GunManager.dbo.UserTable where ÐÕÃû = \'") + EphorName + "\'";
//		sql += QString::fromLocal8Bit(" and ¾ü¹ÙÖ¤ºÅ = \'") + EphorPwd + "\'";
//		bool rv = CDatabaseOperator::GetInstance()->execSql(sql, TableData, errMsg);
//		if (!rv)
//		{
//			QMessageBox::information(this, QString::fromLocal8Bit("´íÎó"), errMsg);
//			return;
//		}
//		else if (TableData.size() == 0)
//		{
//			QMessageBox::information(this, QString::fromLocal8Bit("ÌáÊ¾"), QString::fromLocal8Bit("¼à¶½Ô±ÕËºÅÃÜÂë´íÎó"));
//			return;
//		}
//		done(1);
//	}
//	else
//	{
//		QMessageBox::information(this, QString::fromLocal8Bit("ÌáÊ¾"), QString::fromLocal8Bit("¹ÜÀíÔ±ÕËºÅÃÜÂë´íÎó"));
//		return;
//	}
//}

void CAdminWithEphorLogin::slotLogin()
{
	QString OperatorName = ui.lineEdit_Operator->text();
	QString OperatorPwd = ui.lineEdit_OperatorPwd->text();
	QString EphorName = ui.lineEdit_Ephor->text();
	QString EphorPwd = ui.lineEdit_EphorPwd->text();

	if (OperatorName.isEmpty() || OperatorPwd.isEmpty() || EphorName.isEmpty() || EphorPwd.isEmpty())
	{
		QMessageBox::information(this, QString::fromLocal8Bit("ÌáÊ¾"), QString::fromLocal8Bit("ÇëÊäÈëÕËºÅºÍÃÜÂë£¡"));
		return;
	}
	/*else if (OperatorName == EphorName && OperatorPwd == EphorPwd)
	{
		QMessageBox::information(this, QString::fromLocal8Bit("ÌáÊ¾"), QString::fromLocal8Bit("µÇÂ¼ÐÅÏ¢´íÎó£¡"));
		return;
	}*/
	else
	{
		QTableData OperatorTableData;
		QTableData EphorTableData;
		QString errMsg;
		QString sql = QString::fromLocal8Bit("select * from GunManager.dbo.UserTable where ¾ü¹ÙÖ¤ºÅ = \'") + OperatorName + "\'";
		sql += QString::fromLocal8Bit(" and ÃÜÂë = \'") + OperatorPwd + "\'";
		sql += QString::fromLocal8Bit(" and (Ê¶±ð²Ù×÷ = 1");
		sql += QString::fromLocal8Bit(" or Èë¿â²Ù×÷ = 1");
		sql += QString::fromLocal8Bit(" or ³ö¿â²Ù×÷ = 1)");
		bool rv = CDatabaseOperator::GetInstance()->execSql(sql, OperatorTableData, errMsg);
		if (!rv)
		{
			QMessageBox::information(this, QString::fromLocal8Bit("´íÎó"), errMsg);
			return;
		}
		else if (OperatorTableData.size() == 0)
		{
			QMessageBox::information(this, QString::fromLocal8Bit("ÌáÊ¾"), QString::fromLocal8Bit("²Ù×÷Ô±ÕËºÅ»òÃÜÂë´íÎó£¬ÇëÖØÐÂÊäÈë£¡"));
			return;
		}
		sql.clear();
	    sql = QString::fromLocal8Bit("select * from GunManager.dbo.UserTable where ¾ü¹ÙÖ¤ºÅ = \'") + EphorName + "\'";
		sql += QString::fromLocal8Bit(" and ÃÜÂë = \'") + EphorPwd + "\'";
		sql += QString::fromLocal8Bit(" and (Ê¶±ð¼à¶½ = 1");
		sql += QString::fromLocal8Bit(" or Èë¿â¼à¶½ = 1");
		sql += QString::fromLocal8Bit(" or ³ö¿â¼à¶½ = 1)");

		rv = CDatabaseOperator::GetInstance()->execSql(sql, EphorTableData, errMsg);
		QTableData AllTableData;
		AllTableData.append(OperatorTableData);
		AllTableData.append(EphorTableData);
		if (!rv)
		{
			QMessageBox::information(this, QString::fromLocal8Bit("´íÎó"), errMsg);
			return;
		}

		else if (EphorTableData.size() == 0)
		{
			QMessageBox::information(this, QString::fromLocal8Bit("ÌáÊ¾"), QString::fromLocal8Bit("¼à¶½Ô±ÕËºÅ»òÃÜÂë´íÎó£¬ÇëÖØÐÂÊäÈë£¡"));
			return;
		}

		else if(AllTableData.size()==2)
		{
			done(1);
		}
		//done(1);
	}

}



void CAdminWithEphorLogin::ClearInfor()
{
	ui.lineEdit_Operator->setText("");
	ui.lineEdit_OperatorPwd->setText("");
	ui.lineEdit_Ephor->setText("");
	ui.lineEdit_EphorPwd->setText("");
}