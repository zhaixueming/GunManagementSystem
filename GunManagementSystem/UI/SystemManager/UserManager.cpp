#include "UserManager.h"

CUserManager *CUserManager::m_Instance = NULL;
CUserManager::GarbageCollection CUserManager::m_Collection;

CUserManager::CUserManager(QDialog *parent /* = NULL */)
	:QDialog(parent)
{
	ui.setupUi(this);
	ui.pushButton_QueDing->setStyleSheet("QPushButton{font: 75 15pt '微软雅黑';background-color:rgb(190, 190, 190);color: rgb(34, 139, 34);border:2px groove gray;border-radius:50px;padding:2px 4px;border-style: outset;}"
		"QPushButton:hover{background-color:gray; color: rgb(10, 10, 10);}"
		"QPushButton:pressed{background-color:rgb(210, 20, 20);border-style: inset;}");
	this->setFixedSize(this->size());//不可缩放
	m_Type = -1;
}

CUserManager::~CUserManager()
{

}

CUserManager *CUserManager::GetInstance()
{
	if (m_Instance == NULL)
	{
		m_Instance = new CUserManager();
	}
	return m_Instance;
}

////清空设置
//void CUserManager::ClearController()
//{
//	//权限
//	ui.checkBox_ShiBieCaoZuo->setChecked(false);
//	ui.checkBox_ShiBieJianDu->setChecked(false);
//	ui.checkBox_RuKuCaoZuo->setChecked(false);
//	ui.checkBox_RuKuJianDu->setChecked(false);
//	ui.checkBox_ChuKuCaoZuo->setChecked(false);
//	ui.checkBox_ChuKuJianDu->setChecked(false);
//	//清空
//	ui.lineEdit_XingMing->setText("");
//	ui.lineEdit_JunGuanZheng->setText("");
//	ui.lineEdit_MiMa->setText("");
//	ui.lineEdit_QueRenMiMa->setText("");
//}

//清空设置
void CUserManager::ClearController()
{
	//权限
	ui.checkBox_BianMaJianShiCaoZuo->setChecked(false);
	ui.checkBox_BianMaJianShiJianDu->setChecked(false);
	ui.checkBox_XinXiGuanLiCaoZuo->setChecked(false);
	ui.checkBox_XinXiGuanLiJianDu->setChecked(false);
	/*ui.checkBox_ChuKuCaoZuo->setChecked(false);
	ui.checkBox_ChuKuJianDu->setChecked(false);*/
	//清空
	ui.lineEdit_XingMing->setText("");
	ui.lineEdit_JunGuanZheng->setText("");
	ui.lineEdit_MiMa->setText("");
	ui.lineEdit_QueRenMiMa->setText("");
}

//密码可见设置：旧密码标签，旧密码编辑框，修改密码复选框，显示密码复选框 为相同状态
void CUserManager::SetControllerVisble(bool bVisble)
{
	ui.label_JiuMiMa->setVisible(bVisble);//是否可见
	ui.lineEdit_JiuMiMa->setVisible(bVisble);
	ui.checkBox_XianShi->setVisible(bVisble);
	ui.checkBox_XiuGaiMiMa->setVisible(bVisble);
}

//是否可编辑：姓名，军官证号，密码，确认密码 为相同状态
void CUserManager::SetControllerEnabled(bool bEnabled)
{
	ui.lineEdit_XingMing->setEnabled(bEnabled);
	ui.lineEdit_JunGuanZheng->setEnabled(bEnabled);
	ui.lineEdit_MiMa->setEnabled(bEnabled);
	ui.lineEdit_QueRenMiMa->setEnabled(bEnabled);
}

//
void CUserManager::SetData(QList<QVariant> data)
{
	if (data.size() != 7)
	{
		return;
	}
	QString Name = data.at(0).toString();
	ui.lineEdit_XingMing->setText(Name);//姓名框中设置（string）
	QString Number = data.at(1).toString();
	ui.lineEdit_JunGuanZheng->setText(Number);//军官证号框中设置（string）
	QString Password = data.at(2).toString();
	ui.lineEdit_JiuMiMa->setText(Password);//旧密码框中设置（string）
	bool checked = data.at(3).toBool();
	ui.checkBox_BianMaJianShiCaoZuo->setChecked(checked);//选中或不选中“编码检视操作”复选框
	checked = data.at(4).toBool();
	ui.checkBox_BianMaJianShiJianDu->setChecked(checked);//选中或不选中“编码检视监督”复选框
	checked = data.at(5).toBool();
	ui.checkBox_XinXiGuanLiCaoZuo->setChecked(checked);//选中或不选中“信息管理操作”复选框
	checked = data.at(6).toBool();
	ui.checkBox_XinXiGuanLiJianDu->setChecked(checked);//选中或不选中“信息管理监督”复选框
	
}


//设置操作类型
void CUserManager::SetOperatorType(int index, QList<QVariant> Data)
{
	m_Type = index;//init = -1
	//添加用户
	if (index == 0)
	{
		ui.pushButton_QueDing->setText(QString::fromLocal8Bit("添加"));//“添加”按钮
		ClearController();//调用清空操作函数
		SetControllerVisble(false);//调用密码可见设置函数 为不可见
		SetControllerEnabled(true);//调用是否可编辑函数 为可编辑
	}
	else if (index == 1)   //编辑用户
	{
		ui.pushButton_QueDing->setText(QString::fromLocal8Bit("修改"));//“添加”按钮
		SetControllerVisble(true);//调用密码可见设置函数 为可见
		SetControllerEnabled(false);//调用是否可编辑函数 为可编辑
		SetData(Data);//调用setdata函数
	}
}

//设置修改密码
void CUserManager::SetModifyPasswordChecked(bool checked)
{
	ui.lineEdit_MiMa->setEnabled(checked);//可编辑or只读
	ui.lineEdit_QueRenMiMa->setEnabled(checked);//可编辑or只读
}

//旧密码编辑框 是否显/隐
void CUserManager::ShowPassword(bool checked)//编辑框的回显模式
{
	ui.lineEdit_JiuMiMa->setEchoMode(checked?QLineEdit::Normal: QLineEdit::Password);
}

//检查是否重复
bool CUserManager::CheckRepeat(QString &errMsg)
{
	QString UserName = ui.lineEdit_XingMing->text();//获取输入的姓名
	QString Number = ui.lineEdit_JunGuanZheng->text();//获取输入的军官证号
	QString sql = "select * from GunManager.dbo.UserTable where " + QString::fromLocal8Bit("姓名 = \'") + UserName + "\' and ";//添加到数据库中姓名及军官证号
	sql += QString::fromLocal8Bit("军官证号 = \'") + Number + "\'";
	QTableData TableData;
	bool rv = CDatabaseOperator::GetInstance()->execSql(sql, TableData, errMsg);
	return TableData.size() != 0;//返回数据库是否为空
}

//确认修改
void CUserManager::ConfirmModification()
{
	QString UserName = ui.lineEdit_XingMing->text();//获取输入的姓名
	if (UserName.isEmpty())//判断输入是否为空
	{
		QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("用户名不能为空"));
		return;
	}
	QString Number = ui.lineEdit_JunGuanZheng->text();
	if (Number.isEmpty())//判断输入军官证号是否为空
	{
		QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("军官证号不能为空"));
		return;
	}
	QString sql;
	QString Password;
	if (m_Type == 0)//创建账号
	{
		Password = ui.lineEdit_MiMa->text();//获取密码
		QString ConfirmPassword = ui.lineEdit_QueRenMiMa->text();//获取确认密码
		if (Password.isEmpty() || ConfirmPassword.isEmpty())
		{
			QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("密码不能为空"));
			return;
		}
		else if (Password != ConfirmPassword)//判别两次密码是否相等
		{
			QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("两次密码不相等"));
			return;
		}

		QString errMsg;
		bool rv = CheckRepeat(errMsg); //调用 检查是否重复函数
		if (!errMsg.isEmpty())//判别数据库是否初始化，即是否为空。。。。。我不太懂
		{
			QMessageBox::information(this, QString::fromLocal8Bit("数据库错误"), errMsg);
			return;
		}
		if (rv)//在数据库中信息是否已经存在姓名和军官密码
		{
			QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("记录已存在"));
			return;
		}

		sql = "insert into " + CDatabaseOperator::GetInstance()->GetDatabaseName();
		sql += ".dbo.UserTable values(\'" + UserName + "\',\'" + Number + "\',\'" + Password + "\',";
		bool check = ui.checkBox_BianMaJianShiCaoZuo->isChecked();//复选框如果被选中，返回1，否则返回0
		sql += check ? "1," : "0,";
		check = ui.checkBox_BianMaJianShiJianDu->isChecked();//复选框如果被选中，返回1，否则返回0
		sql += check ? "1," : "0,";
		check = ui.checkBox_XinXiGuanLiCaoZuo->isChecked();
		sql += check ? "1," : "0,";
		check = ui.checkBox_XinXiGuanLiJianDu->isChecked();
		sql += check ? "1)" : "0)";
	}
	else if (m_Type == 1)//编辑账号
	{
		Password = ui.lineEdit_JiuMiMa->text();//获取旧密码
		if (ui.checkBox_XiuGaiMiMa->isChecked())//如果修改密码复选框被选中
		{
			QString NewPassword = ui.lineEdit_MiMa->text();//获取密码框内容，作为新密码
			QString ConfirmPassword = ui.lineEdit_QueRenMiMa->text();//获取确认密码框内容，作为新密码
			if (NewPassword.isEmpty() || ConfirmPassword.isEmpty())
			{
				QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("密码不能为空"));
				return;
			}
			else if (NewPassword != ConfirmPassword)
			{
				QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("两次密码不相等"));
				return;
			}
			if (NewPassword == Password)
			{
				QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("旧密码和新密码相同"));
				return;
			}
			Password = NewPassword;//更新密码
		}
		sql = "update GunManager.dbo.UserTable set UserTable." + QString::fromLocal8Bit("密码 = ") + "\'" + Password + "\',";
		bool check = ui.checkBox_BianMaJianShiCaoZuo->isChecked();
		sql += "UserTable." + QString::fromLocal8Bit("编码检视操作 = ") + (check ? "1," : "0,");
		check = ui.checkBox_BianMaJianShiJianDu->isChecked();
		sql += "UserTable." + QString::fromLocal8Bit("编码检视监督 = ") + (check ? "1," : "0,");
		check = ui.checkBox_XinXiGuanLiCaoZuo->isChecked();
		sql += "UserTable." + QString::fromLocal8Bit("信息管理操作 = ") + (check ? "1," : "0,");
		check = ui.checkBox_XinXiGuanLiJianDu->isChecked();
		sql += "UserTable." + QString::fromLocal8Bit("信息管理监督 = ") + (check ? "1" : "0");
		sql += " where " + QString::fromLocal8Bit("姓名= \'") + UserName + QString::fromLocal8Bit("\' and 军官证号 = \'") + Number + "\'";
	}
	
	QTableData TableData;
	QString errMsg;
	bool rv = CDatabaseOperator::GetInstance()->execSql(sql, TableData, errMsg);
	if (!rv)
	{
		QMessageBox::information(this, QString::fromLocal8Bit("操作错误"), errMsg);
	}
	else
	{
		QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("操作成功"));
	}
}