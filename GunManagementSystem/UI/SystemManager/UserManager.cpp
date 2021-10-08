#include "UserManager.h"

CUserManager *CUserManager::m_Instance = NULL;
CUserManager::GarbageCollection CUserManager::m_Collection;

CUserManager::CUserManager(QDialog *parent /* = NULL */)
	:QDialog(parent)
{
	ui.setupUi(this);
	ui.pushButton_QueDing->setStyleSheet("QPushButton{font: 75 15pt '΢���ź�';background-color:rgb(190, 190, 190);color: rgb(34, 139, 34);border:2px groove gray;border-radius:50px;padding:2px 4px;border-style: outset;}"
		"QPushButton:hover{background-color:gray; color: rgb(10, 10, 10);}"
		"QPushButton:pressed{background-color:rgb(210, 20, 20);border-style: inset;}");
	this->setFixedSize(this->size());//��������
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

////�������
//void CUserManager::ClearController()
//{
//	//Ȩ��
//	ui.checkBox_ShiBieCaoZuo->setChecked(false);
//	ui.checkBox_ShiBieJianDu->setChecked(false);
//	ui.checkBox_RuKuCaoZuo->setChecked(false);
//	ui.checkBox_RuKuJianDu->setChecked(false);
//	ui.checkBox_ChuKuCaoZuo->setChecked(false);
//	ui.checkBox_ChuKuJianDu->setChecked(false);
//	//���
//	ui.lineEdit_XingMing->setText("");
//	ui.lineEdit_JunGuanZheng->setText("");
//	ui.lineEdit_MiMa->setText("");
//	ui.lineEdit_QueRenMiMa->setText("");
//}

//�������
void CUserManager::ClearController()
{
	//Ȩ��
	ui.checkBox_BianMaJianShiCaoZuo->setChecked(false);
	ui.checkBox_BianMaJianShiJianDu->setChecked(false);
	ui.checkBox_XinXiGuanLiCaoZuo->setChecked(false);
	ui.checkBox_XinXiGuanLiJianDu->setChecked(false);
	/*ui.checkBox_ChuKuCaoZuo->setChecked(false);
	ui.checkBox_ChuKuJianDu->setChecked(false);*/
	//���
	ui.lineEdit_XingMing->setText("");
	ui.lineEdit_JunGuanZheng->setText("");
	ui.lineEdit_MiMa->setText("");
	ui.lineEdit_QueRenMiMa->setText("");
}

//����ɼ����ã��������ǩ��������༭���޸����븴ѡ����ʾ���븴ѡ�� Ϊ��ͬ״̬
void CUserManager::SetControllerVisble(bool bVisble)
{
	ui.label_JiuMiMa->setVisible(bVisble);//�Ƿ�ɼ�
	ui.lineEdit_JiuMiMa->setVisible(bVisble);
	ui.checkBox_XianShi->setVisible(bVisble);
	ui.checkBox_XiuGaiMiMa->setVisible(bVisble);
}

//�Ƿ�ɱ༭������������֤�ţ����룬ȷ������ Ϊ��ͬ״̬
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
	ui.lineEdit_XingMing->setText(Name);//�����������ã�string��
	QString Number = data.at(1).toString();
	ui.lineEdit_JunGuanZheng->setText(Number);//����֤�ſ������ã�string��
	QString Password = data.at(2).toString();
	ui.lineEdit_JiuMiMa->setText(Password);//������������ã�string��
	bool checked = data.at(3).toBool();
	ui.checkBox_BianMaJianShiCaoZuo->setChecked(checked);//ѡ�л�ѡ�С�������Ӳ�������ѡ��
	checked = data.at(4).toBool();
	ui.checkBox_BianMaJianShiJianDu->setChecked(checked);//ѡ�л�ѡ�С�������Ӽල����ѡ��
	checked = data.at(5).toBool();
	ui.checkBox_XinXiGuanLiCaoZuo->setChecked(checked);//ѡ�л�ѡ�С���Ϣ�����������ѡ��
	checked = data.at(6).toBool();
	ui.checkBox_XinXiGuanLiJianDu->setChecked(checked);//ѡ�л�ѡ�С���Ϣ����ල����ѡ��
	
}


//���ò�������
void CUserManager::SetOperatorType(int index, QList<QVariant> Data)
{
	m_Type = index;//init = -1
	//����û�
	if (index == 0)
	{
		ui.pushButton_QueDing->setText(QString::fromLocal8Bit("���"));//����ӡ���ť
		ClearController();//������ղ�������
		SetControllerVisble(false);//��������ɼ����ú��� Ϊ���ɼ�
		SetControllerEnabled(true);//�����Ƿ�ɱ༭���� Ϊ�ɱ༭
	}
	else if (index == 1)   //�༭�û�
	{
		ui.pushButton_QueDing->setText(QString::fromLocal8Bit("�޸�"));//����ӡ���ť
		SetControllerVisble(true);//��������ɼ����ú��� Ϊ�ɼ�
		SetControllerEnabled(false);//�����Ƿ�ɱ༭���� Ϊ�ɱ༭
		SetData(Data);//����setdata����
	}
}

//�����޸�����
void CUserManager::SetModifyPasswordChecked(bool checked)
{
	ui.lineEdit_MiMa->setEnabled(checked);//�ɱ༭orֻ��
	ui.lineEdit_QueRenMiMa->setEnabled(checked);//�ɱ༭orֻ��
}

//������༭�� �Ƿ���/��
void CUserManager::ShowPassword(bool checked)//�༭��Ļ���ģʽ
{
	ui.lineEdit_JiuMiMa->setEchoMode(checked?QLineEdit::Normal: QLineEdit::Password);
}

//����Ƿ��ظ�
bool CUserManager::CheckRepeat(QString &errMsg)
{
	QString UserName = ui.lineEdit_XingMing->text();//��ȡ���������
	QString Number = ui.lineEdit_JunGuanZheng->text();//��ȡ����ľ���֤��
	QString sql = "select * from GunManager.dbo.UserTable where " + QString::fromLocal8Bit("���� = \'") + UserName + "\' and ";//��ӵ����ݿ�������������֤��
	sql += QString::fromLocal8Bit("����֤�� = \'") + Number + "\'";
	QTableData TableData;
	bool rv = CDatabaseOperator::GetInstance()->execSql(sql, TableData, errMsg);
	return TableData.size() != 0;//�������ݿ��Ƿ�Ϊ��
}

//ȷ���޸�
void CUserManager::ConfirmModification()
{
	QString UserName = ui.lineEdit_XingMing->text();//��ȡ���������
	if (UserName.isEmpty())//�ж������Ƿ�Ϊ��
	{
		QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("�û�������Ϊ��"));
		return;
	}
	QString Number = ui.lineEdit_JunGuanZheng->text();
	if (Number.isEmpty())//�ж��������֤���Ƿ�Ϊ��
	{
		QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("����֤�Ų���Ϊ��"));
		return;
	}
	QString sql;
	QString Password;
	if (m_Type == 0)//�����˺�
	{
		Password = ui.lineEdit_MiMa->text();//��ȡ����
		QString ConfirmPassword = ui.lineEdit_QueRenMiMa->text();//��ȡȷ������
		if (Password.isEmpty() || ConfirmPassword.isEmpty())
		{
			QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("���벻��Ϊ��"));
			return;
		}
		else if (Password != ConfirmPassword)//�б����������Ƿ����
		{
			QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("�������벻���"));
			return;
		}

		QString errMsg;
		bool rv = CheckRepeat(errMsg); //���� ����Ƿ��ظ�����
		if (!errMsg.isEmpty())//�б����ݿ��Ƿ��ʼ�������Ƿ�Ϊ�ա����������Ҳ�̫��
		{
			QMessageBox::information(this, QString::fromLocal8Bit("���ݿ����"), errMsg);
			return;
		}
		if (rv)//�����ݿ�����Ϣ�Ƿ��Ѿ����������;�������
		{
			QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("��¼�Ѵ���"));
			return;
		}

		sql = "insert into " + CDatabaseOperator::GetInstance()->GetDatabaseName();
		sql += ".dbo.UserTable values(\'" + UserName + "\',\'" + Number + "\',\'" + Password + "\',";
		bool check = ui.checkBox_BianMaJianShiCaoZuo->isChecked();//��ѡ�������ѡ�У�����1�����򷵻�0
		sql += check ? "1," : "0,";
		check = ui.checkBox_BianMaJianShiJianDu->isChecked();//��ѡ�������ѡ�У�����1�����򷵻�0
		sql += check ? "1," : "0,";
		check = ui.checkBox_XinXiGuanLiCaoZuo->isChecked();
		sql += check ? "1," : "0,";
		check = ui.checkBox_XinXiGuanLiJianDu->isChecked();
		sql += check ? "1)" : "0)";
	}
	else if (m_Type == 1)//�༭�˺�
	{
		Password = ui.lineEdit_JiuMiMa->text();//��ȡ������
		if (ui.checkBox_XiuGaiMiMa->isChecked())//����޸����븴ѡ��ѡ��
		{
			QString NewPassword = ui.lineEdit_MiMa->text();//��ȡ��������ݣ���Ϊ������
			QString ConfirmPassword = ui.lineEdit_QueRenMiMa->text();//��ȡȷ����������ݣ���Ϊ������
			if (NewPassword.isEmpty() || ConfirmPassword.isEmpty())
			{
				QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("���벻��Ϊ��"));
				return;
			}
			else if (NewPassword != ConfirmPassword)
			{
				QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("�������벻���"));
				return;
			}
			if (NewPassword == Password)
			{
				QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("���������������ͬ"));
				return;
			}
			Password = NewPassword;//��������
		}
		sql = "update GunManager.dbo.UserTable set UserTable." + QString::fromLocal8Bit("���� = ") + "\'" + Password + "\',";
		bool check = ui.checkBox_BianMaJianShiCaoZuo->isChecked();
		sql += "UserTable." + QString::fromLocal8Bit("������Ӳ��� = ") + (check ? "1," : "0,");
		check = ui.checkBox_BianMaJianShiJianDu->isChecked();
		sql += "UserTable." + QString::fromLocal8Bit("������Ӽල = ") + (check ? "1," : "0,");
		check = ui.checkBox_XinXiGuanLiCaoZuo->isChecked();
		sql += "UserTable." + QString::fromLocal8Bit("��Ϣ������� = ") + (check ? "1," : "0,");
		check = ui.checkBox_XinXiGuanLiJianDu->isChecked();
		sql += "UserTable." + QString::fromLocal8Bit("��Ϣ����ල = ") + (check ? "1" : "0");
		sql += " where " + QString::fromLocal8Bit("����= \'") + UserName + QString::fromLocal8Bit("\' and ����֤�� = \'") + Number + "\'";
	}
	
	QTableData TableData;
	QString errMsg;
	bool rv = CDatabaseOperator::GetInstance()->execSql(sql, TableData, errMsg);
	if (!rv)
	{
		QMessageBox::information(this, QString::fromLocal8Bit("��������"), errMsg);
	}
	else
	{
		QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("�����ɹ�"));
	}
}