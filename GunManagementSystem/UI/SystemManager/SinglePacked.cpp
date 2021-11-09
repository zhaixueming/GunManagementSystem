#include "SinglePacked.h"

CSinglePacked *CSinglePacked::m_Instance = NULL;
CSinglePacked::GarbageCollection CSinglePacked::m_Collection;

CSinglePacked::CSinglePacked(QDialog *parent /* = NULL */)
	:QDialog(parent)
{
	ui.setupUi(this);

	InitVariables();
	
}

CSinglePacked::~CSinglePacked()
{

}

CSinglePacked *CSinglePacked::GetInstance()
{
	if (m_Instance == NULL)
	{
		m_Instance = new CSinglePacked();
	}
	return m_Instance;
}



void CSinglePacked::InitVariables()
{
	qDebug() << "InitVariables";
	this->setFixedSize(this->size());
	ui.pushButton_QueDing->setStyleSheet("QPushButton{font: 75 15pt '΢���ź�';background-color:rgb(190, 190, 190);color: rgb(34, 139, 34);border:2px groove gray;border-radius:50px;padding:2px 4px;border-style: outset;}"
		"QPushButton:hover{background-color:gray; color: rgb(10, 10, 10);}"
		"QPushButton:pressed{background-color:rgb(210, 20, 20);border-style: inset;}");

	//m_GunTypeInfos.insert(QString::fromLocal8Bit("Default"), "default");
	//m_GunTypeInfos.insert(QString::fromLocal8Bit("95ʽ��ǹ"), "95shibuqiang");
	//m_GunTypeInfos.insert(QString::fromLocal8Bit("95-1ʽ��ǹ"), "951shibuqiang");
	//m_GunTypeInfos.insert(QString::fromLocal8Bit("54ʽ��ǹ"), "54shishouqiang");
	////m_GunTypeInfos.insert(QString::fromLocal8Bit("81ʽ��ǹ"), "81shibuqiang");
	////m_GunTypeInfos.insert(QString::fromLocal8Bit("92ʽ��ǹ"), "92shishouqiang");

	ui.comboBox_GunType->clear();
	ui.comboBox_GunType->setFixedSize(QSize(200, 30));
	ui.comboBox_GunType->addItem("Default");
	ui.comboBox_GunType->addItem(QString::fromLocal8Bit("95ʽ��ǹ"));
	ui.comboBox_GunType->addItem(QString::fromLocal8Bit("95-1ʽ��ǹ"));
	ui.comboBox_GunType->addItem(QString::fromLocal8Bit("54ʽ��ǹ"));
	ui.comboBox_GunType->addItem(QString::fromLocal8Bit("92ʽ��ǹ"));
	ui.comboBox_GunType->addItem(QString::fromLocal8Bit("81ʽ��ǹ"));
	
	/*ui.comboBox_GunType->setStyleSheet("QComboBox{font: 75 15pt '΢���ź�';border-radius:3px;color:black;background:white;padding-left:5px;padding-right:12px;border:1px solid #b5b5b5;}\
                            QComboBox:hover{border:1px solid gray;}");*/


	ui.dateEdit_ChuChang->setFixedSize(QSize(200, 30));
	ui.dateEdit_ZhuangBei->setFixedSize(QSize(200, 30));
	ui.dateEdit_ChuChang->setDateTime(QDateTime::fromString("1900-1-1", "yyyy-M-d"));
	ui.dateEdit_ZhuangBei->setDateTime(QDateTime::fromString("1900-1-1", "yyyy-M-d"));
}

void CSinglePacked::SetControllerEnabled(bool enabled)
{
	ui.lineEdit_WenJianHao->setEnabled(enabled);
	ui.lineEdit_PingZhengHao->setEnabled(enabled);
	ui.lineEdit_DaiMa->setEnabled(enabled);
}

void CSinglePacked::SetControllContent(QList<QVariant> data)
{
	if (data.size() != 10)
	{
		return;
	}
	ui.lineEdit_WenJianHao->setText(data.at(0).toString());
	ui.lineEdit_PingZhengHao->setText(data.at(1).toString());
	ui.lineEdit_DaiMa->setText(data.at(3).toString());
	ui.lineEdit_MingCheng->setText(data.at(4).toString());
	ui.lineEdit_LiShuDanWei->setText(data.at(5).toString());
	ui.lineEdit_GuanLiDanWei->setText(data.at(6).toString());
	ui.comboBox_GunType->setCurrentText(data.at(7).toString());//ǹ֧����
	QDate DTime = QDate::fromString(data.at(8).toString(), "yyyy/MM/dd");
	ui.dateEdit_ChuChang->setDate(DTime);
	DTime = QDate::fromString(data.at(9).toString(), "yyyy/MM/dd");
	ui.dateEdit_ZhuangBei->setDate(DTime);
}


////��װ ǹ֧��������
//QString CSinglePacked::ConnectGunType2()
//{
//
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


bool CSinglePacked::CheckSinglePackedRepeat(QString &errMsg)
{
	QString WenJianHao = ui.lineEdit_WenJianHao->text();
	QString PingZhengHao = ui.lineEdit_PingZhengHao->text();
	QString DaiMa = ui.lineEdit_DaiMa->text();
	QString sql = "select * from GunManager.dbo.SinglePackedTable where " + QString::fromLocal8Bit("���۱����ļ��� = \'") + WenJianHao + "\' and ";
	sql += QString::fromLocal8Bit("����ƾ֤�� = \'") + PingZhengHao + "\' and " + QString::fromLocal8Bit("װ������ = \'") + DaiMa + "\'";
	QTableData TableData;
	bool rv = CDatabaseOperator::GetInstance()->execSql(sql, TableData, errMsg);
	return TableData.size() != 0;
}

//������װ��Ϣ���ݣ��ۺ����������Ӽ��ɴ����µ�һ�����ݣ�
void CSinglePacked::ConfirmModification()
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

	QString GunType = ui.comboBox_GunType->currentText();//ǹ֧����

	/*QDateTime curDateTime = QDateTime::currentDateTime();
	QString JiLuDateTime = curDateTime.toString("yyyy-MM-dd hh:mm:ss");*/
	QDateTime curDateTime = QDateTime::currentDateTime();
	QString RuKuDateTime = curDateTime.toString("yyyy-M-d");
	////Ϊ����ڶ������ݿ��ֵ�������ֵ
	/*QString BianHao= QString::fromLocal8Bit(" ");
	QString QueShiQingKuang = QString::fromLocal8Bit(" ");*/

	QString sql;
	QString errMsg;
	bool rv = CheckSinglePackedRepeat(errMsg);
	if (!errMsg.isEmpty())
	{
		QMessageBox::information(this, QString::fromLocal8Bit("����"), errMsg);
		return;
	}
	if (rv)
	{
		QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("��װ��¼�Ѵ���"));
		return;
	}
	//�������ַ���������
	//sql = "insert GunManager.dbo.SinglePackedTable values(\'" + WenJianHao + "\',\'" + PingZhengHao + "\',\'" + DaiMa + "\',\'";
	//sql += ZhuangBeiMing + "\',\'\',\'\',\'" + LiShuDanWei + "\',\'" + GuanLiDanWei + "\',\'" + ChuChangTime + "\',\'";
	//sql += ZhuangBeiTime + "\'," + QString::fromLocal8Bit("\'δ����\'") + ",\'"+JiLuDateTime + "\'" + ",\'1900-01-01 00:00:00.000\')";//��¼ʱ���Ǵ���һ����װ����ʱ��ʱ��

	sql = "insert GunManager.dbo.SinglePackedTable values(\'" + WenJianHao + "\',\'" + PingZhengHao + "\',\'" + DaiMa + "\',\'";
	sql += ZhuangBeiMing + "\',\'\',\'\',\'\',\'\',\'\',\'\',\'" + LiShuDanWei + "\',\'" + GuanLiDanWei + "\',\'" + GunType+ "\',\'" + ChuChangTime + "\',\'";
	//sql += ZhuangBeiTime + "\'," + QString::fromLocal8Bit("\'δ����\'") + ",\'" + RuKuDateTime + "\'" + ")";//��¼ʱ���Ǵ���һ����װ����ʱ��ʱ��
	//sql += ZhuangBeiTime + "\'," + QString::fromLocal8Bit("\'δ����\'") + ",\'" + RuKuDateTime + "\'" + ",\'\',\'\'," + "\'" + JianShiZhuangTai+ "\')";
	sql += ZhuangBeiTime + "\'," + QString::fromLocal8Bit("\'δ����\'") + ",\'" + RuKuDateTime + "\'" + ",null,null," + "\'" + JianShiZhuangTai + "\')";
	
	QTableData TableData;
	rv = CDatabaseOperator::GetInstance()->execSql(sql, TableData, errMsg);
	if (rv)
	{
		QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("�����ɹ�"));
	}
	else
	{
		QMessageBox::information(this, QString::fromLocal8Bit("��װ��¼����ʧ��"), errMsg);
	}
}


