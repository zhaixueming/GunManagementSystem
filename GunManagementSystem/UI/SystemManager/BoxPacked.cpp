#include "BoxPacked.h"

CBoxPacked *CBoxPacked::m_Instance = NULL;
CBoxPacked::GarbageCollection CBoxPacked::m_Collection;

CBoxPacked::CBoxPacked(QDialog *parent /* = NULL */)
	:QDialog(parent)
{
	ui.setupUi(this);

	InitVariables();
	
}

CBoxPacked::~CBoxPacked()
{

}

CBoxPacked *CBoxPacked::GetInstance()
{
	if (m_Instance == NULL)
	{
		m_Instance = new CBoxPacked();
	}
	return m_Instance;
}

void CBoxPacked::InitVariables()
{
	qDebug() << "InitVariables";
	this->setFixedSize(this->size());
	ui.pushButton_QueDing->setStyleSheet("QPushButton{font: 75 15pt '΢���ź�';background-color:rgb(190, 190, 190);color: rgb(34, 139, 34);border:2px groove gray;border-radius:50px;padding:2px 4px;border-style: outset;}"
		"QPushButton:hover{background-color:gray; color: rgb(10, 10, 10);}"
		"QPushButton:pressed{background-color:rgb(210, 20, 20);border-style: inset;}");
	

	
	ui.comboBox_GunType->clear();
	ui.comboBox_GunType->setFixedSize(QSize(200, 30));
	ui.comboBox_GunType->addItem("Default");
	ui.comboBox_GunType->addItem(QString::fromLocal8Bit("95ʽ��ǹ"));
	ui.comboBox_GunType->addItem(QString::fromLocal8Bit("95-1ʽ��ǹ"));
	ui.comboBox_GunType->addItem(QString::fromLocal8Bit("54ʽ��ǹ"));
	ui.comboBox_GunType->addItem(QString::fromLocal8Bit("92ʽ��ǹ"));
	ui.comboBox_GunType->addItem(QString::fromLocal8Bit("81ʽ��ǹ"));
	

	//ui.comboBox_GunType->setStyleSheet("QComboBox{font: 75 15pt '΢���ź�';border-radius:3px;color:black;background:white;padding-left:5px;padding-right:12px;border:1px solid #b5b5b5;}\
 //                           QComboBox:hover{border:1px solid gray;}");

	ui.dateEdit_ChuChang->setFixedSize(QSize(200, 30));
	ui.dateEdit_ZhuangBei->setFixedSize(QSize(200, 30));
	ui.dateEdit_ChuChang->setDateTime(QDateTime::fromString("1900-1-1", "yyyy-M-d"));
	ui.dateEdit_ZhuangBei->setDateTime(QDateTime::fromString("1900-1-1", "yyyy-M-d"));
	/*ui.dateEdit_ChuChang->setStyleSheet("QDateEdit{font: 75 15pt '΢���ź�';border-radius:3px;color:black;background:white;padding-left:5px;padding-right:12px;border:1px solid #b5b5b5;}\
                            QDateEdit:hover{border:1px solid gray;}");
	ui.dateEdit_ZhuangBei->setStyleSheet("QDateEdit{font: 75 15pt '΢���ź�';border-radius:3px;color:black;background:white;padding-left:5px;padding-right:12px;border:1px solid #b5b5b5;}\
                            QDateEdit:hover{border:1px solid gray;}");*/


}

void CBoxPacked::SetControllerEnabled(bool enabled)//type==1ʱ��enabled==false
{
	ui.lineEdit_WenJianHao->setEnabled(enabled);
	ui.lineEdit_PingZhengHao->setEnabled(enabled);
	ui.lineEdit_DanHao->setEnabled(enabled);
	ui.spinBox->setEnabled(enabled);
	
}

//�޸ı�������
void CBoxPacked::SetControllContent(QList<QVariant> data)
{
	if (data.size() != 11)
	{
		return;
	}
	ui.lineEdit_WenJianHao->setText(data.at(0).toString());
	ui.lineEdit_PingZhengHao->setText(data.at(1).toString());
	ui.lineEdit_DanHao->setText(data.at(2).toString());
	ui.lineEdit_DaiMa->setText(data.at(3).toString());
	ui.lineEdit_MingCheng->setText(data.at(4).toString());
	ui.lineEdit_LiShuDanWei->setText(data.at(5).toString());
	ui.lineEdit_GuanLiDanWei->setText(data.at(6).toString());
	ui.comboBox_GunType->setCurrentText(data.at(7).toString());//ǹ֧����
	QDate DTime = QDate::fromString(data.at(8).toString(), "yyyy-M-d");
	ui.dateEdit_ChuChang->setDate(DTime);
	DTime = QDate::fromString(data.at(9).toString(), "yyyy-M-d");
	ui.dateEdit_ZhuangBei->setDate(DTime);
	ui.spinBox->setValue(data.at(10).toInt());
}


////��װ ǹ֧��������
//QString CBoxPacked::ConnectGunType1()
//{
//	QString GunType = ui.comboBox_GunType->currentText();
//
//	//QString GTModule = m_GunTypeInfos.value(GunType);
//	//int ConnectType = ui.comboBox_GunType->currentIndex();
//	
//	if (!GunType.isEmpty())
//	{
//		return GunType;
//	}
//	else
//	{
//		QMessageBox::information(this, QString::fromLocal8Bit("����"), QString::fromLocal8Bit("δ����ǹ֧����"));
//		//return;
//	}
//
//}


//������༭����Ϣ����
void CBoxPacked::SetOperatorType(int type, QList<QVariant> data)
{
	m_Type = type;//���
	if (type == 0)
	{
		SetControllerEnabled(true);
		ui.pushButton_QueDing->setText(QString::fromLocal8Bit("���"));
	}
	else if (type == 1)//�޸�
	{
		SetControllContent(data);
		SetControllerEnabled(false);
		ui.pushButton_QueDing->setText(QString::fromLocal8Bit("�޸�"));
	}
}

bool CBoxPacked::CheckBoxRepeat(QString &errMsg)
{
	QString WenJianHao = ui.lineEdit_WenJianHao->text();
	QString PingZhengHao = ui.lineEdit_PingZhengHao->text();
	QString DanHao = ui.lineEdit_DanHao->text();
	QString sql = "select * from GunManager.dbo.BoxPackedTable where " + QString::fromLocal8Bit("���۱����ļ��� = \'") + WenJianHao + "\' and ";
	sql += QString::fromLocal8Bit("����ƾ֤�� = \'") + PingZhengHao + "\' and " + QString::fromLocal8Bit("װ�䵥�� = \'") + DanHao + "\'";
	QTableData TableData;
	bool rv = CDatabaseOperator::GetInstance()->execSql(sql, TableData, errMsg);
	return TableData.size() != 0;
}

bool CBoxPacked::CheckBoxDetailsRepeat(QString &errMsg)
{
	QString DanHao = ui.lineEdit_DanHao->text();
	QString sql = "select * from GunManager.dbo.BoxPackedDetailsTable where " + QString::fromLocal8Bit("װ�䵥�� = \'") + DanHao + "\'";
	QTableData TableData;
	bool rv = CDatabaseOperator::GetInstance()->execSql(sql, TableData, errMsg);
	return TableData.size() != 0;
}

void CBoxPacked::ConfirmModification()
{
	QString WenJianHao = ui.lineEdit_WenJianHao->text();
	if (WenJianHao.isEmpty())
	{
		QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("�����ļ��Ų���Ϊ��"));
		return;
	}

	QString PingZhengHao = ui.lineEdit_PingZhengHao->text();
	if (PingZhengHao.isEmpty())
	{
		QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("����ƾ֤�Ų���Ϊ��"));
		return;
	}

	QString DanHao = ui.lineEdit_DanHao->text();
	if (DanHao.isEmpty())
	{
		QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("װ�䵥�Ų���Ϊ��"));
		return;
	}

	QString DaiMa = ui.lineEdit_DaiMa->text();
	if (DaiMa.isEmpty())
	{
		QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("װ�����벻��Ϊ��"));
		return;
	}

	QString ZhuangBeiMing = ui.lineEdit_MingCheng->text();
	if (ZhuangBeiMing.isEmpty())
	{
		QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("װ�����Ʋ���Ϊ��"));
		return;
	}

	QString LiShuDanWei = ui.lineEdit_LiShuDanWei->text();
	if (LiShuDanWei.isEmpty())
	{
		QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("������λ����Ϊ��"));
		return;
	}

	QString GuanLiDanWei = ui.lineEdit_GuanLiDanWei->text();
	if (GuanLiDanWei.isEmpty())
	{
		QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("����λ����Ϊ��"));
		return;
	}

	QString ChuChangTime = ui.dateEdit_ChuChang->date().toString("yyyy-M-d");
	QString ZhuangBeiTime = ui.dateEdit_ZhuangBei->date().toString("yyyy-M-d");
	if (ChuChangTime > ZhuangBeiTime)
	{
		QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("����ʱ�䲻������װ��ʱ��"));
		return;
	}

	QString JianShiZhuangTai = QString::fromLocal8Bit("δ����");
	QString Number = ui.spinBox->text();

	QDateTime curDateTime = QDateTime::currentDateTime();
	QString RuKuDateTime = curDateTime.toString("yyyy-M-d");//��ȡ��ǰ���ڣ���ת��Ϊ�ַ���

	//ǹ֧����
	QString GunType = ui.comboBox_GunType->currentText();

	QString sql;
	QString errMsg;
	bool rv = false;
	if (m_Type == 0)//�½�
	{
		rv = CheckBoxRepeat(errMsg);
		if (!errMsg.isEmpty())
		{
			QMessageBox::information(this, QString::fromLocal8Bit("��װ����ʧ��"), errMsg);
			return;
		}
		if (rv)
		{
			QMessageBox::information(this, QString::fromLocal8Bit("��װ������ʾ"), QString::fromLocal8Bit("��װ��Ϣ��¼�Ѵ���"));
			return;
		}
		rv = CheckBoxDetailsRepeat(errMsg);
		if (!errMsg.isEmpty())
		{
			QMessageBox::information(this, QString::fromLocal8Bit("��װ�б����ʧ��"), errMsg);
			return;
		}
		if (rv)
		{
			QMessageBox::information(this, QString::fromLocal8Bit("��װ�б������ʾ"), QString::fromLocal8Bit("��װ���ż�¼�Ѵ���"));
			return;
		}
		
		sql = "insert GunManager.dbo.BoxPackedTable values(\'" + WenJianHao + "\',\'" + PingZhengHao + "\',\'" + DanHao + "\',\'";
		sql += DaiMa + "\',\'" + ZhuangBeiMing + "\',\'" + LiShuDanWei + "\',\'" + GuanLiDanWei + "\',\'"+ GunType + "\',\'" + ChuChangTime+ "\',\'";
		sql += ZhuangBeiTime + "\'," + Number + ",\'" + RuKuDateTime + "\')";
	}
	else if (m_Type == 1)//�༭
	{
		sql = "update GunManager.dbo.BoxPackedTable set " + QString::fromLocal8Bit("װ������ = \'") + DaiMa + "\',";
		sql += QString::fromLocal8Bit("װ������ = \'") + ZhuangBeiMing + "\'," + QString::fromLocal8Bit("������λ = \'") + LiShuDanWei + "\',";
		sql += QString::fromLocal8Bit("����λ = \'") + GuanLiDanWei + "\'," +QString::fromLocal8Bit("ǹ֧���� = \'") + GunType + "\'," + QString::fromLocal8Bit("����ʱ�� = \'") + ChuChangTime + "\',";
		sql += QString::fromLocal8Bit("װ��ʱ�� = \'") + ZhuangBeiTime + "\' where " + QString::fromLocal8Bit("���۱����ļ��� = \'") + WenJianHao + "\' and ";
		sql += QString::fromLocal8Bit("����ƾ֤�� = \'") + PingZhengHao + "\' and " + QString::fromLocal8Bit("װ�䵥�� = \'") + DanHao + "\'";
		//sql = "update GunManager.dbo.BoxPackedTable set " + QString::fromLocal8Bit("װ������ = \'") + DaiMa + "\',";
		//sql += QString::fromLocal8Bit("װ������ = \'") + ZhuangBeiMing + "\'," + QString::fromLocal8Bit("������λ = \'") + LiShuDanWei + "\',";
		//sql += QString::fromLocal8Bit("����λ = \'") + GuanLiDanWei + "\'," + QString::fromLocal8Bit("����ʱ�� = \'") + ChuChangTime + "\',";
		//sql += QString::fromLocal8Bit("װ��ʱ�� = \'") + ZhuangBeiTime + "\',"+ QString::fromLocal8Bit("װ������ = ") + Number + " where " + QString::fromLocal8Bit("���۱����ļ��� = \'") + WenJianHao + "\' and ";
		//sql += QString::fromLocal8Bit("����ƾ֤�� = \'") + PingZhengHao + "\' and " + QString::fromLocal8Bit("װ�䵥�� = \'") + DanHao + "\'";
	}
	QTableData TableData;
	rv = CDatabaseOperator::GetInstance()->execSql(sql, TableData, errMsg);
	if (rv)
	{
		if (m_Type == 0)
		{
			/*QDateTime curDateTime = QDateTime::currentDateTime();
			QString JiLuDateTime = curDateTime.toString("yyyy-MM-dd hh:mm:ss");*/
			//QDateTime curDateTime = QDateTime::currentDateTime();
			//QString RuKuDateTime = curDateTime.toString("yyyy-M-d");//��ȡ��ǰ���ڣ���ת��Ϊ�ַ���
			

			sql = "insert into GunManager.dbo.BoxPackedDetailsTable values ";
			int n = ui.spinBox->value();
			int i = 0;
			for (; i < n - 1; ++i)
			{

				sql += "(" + QString::number(i + 1) + ",\'" + DanHao + "\',\'" + DaiMa + "\',\'" + ZhuangBeiMing + QString::fromLocal8Bit("\',\'\',\'\',\'\',\'\',\'\',\'\',\'δ����\',\'") +  GunType + "\',\'" + RuKuDateTime + "\'" + ",null,null," + "\'" + JianShiZhuangTai + "\'),";
			}
			sql += "(" + QString::number(i + 1) + ",\'" + DanHao + "\',\'" + DaiMa + "\',\'" + ZhuangBeiMing + QString::fromLocal8Bit("\',\'\',\'\',\'\',\'\',\'\',\'\',\'δ����\',\'") +  GunType + "\',\'" + RuKuDateTime + "\'" + ",null,null," + "\'" + JianShiZhuangTai + "\')";
			
			rv = CDatabaseOperator::GetInstance()->execSql(sql, TableData, errMsg);
			if (!rv)
			{
				QMessageBox::information(this, QString::fromLocal8Bit("�����װ�б����ʧ��"), errMsg);
				return;
			}
		}
		
		QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("�����ɹ�"));
	}
	else
	{
		QMessageBox::information(this, QString::fromLocal8Bit("�����װ��Ϣ����ʧ��"), errMsg);
	}
}