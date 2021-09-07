#include "SinglePacked.h"

CSinglePacked *CSinglePacked::m_Instance = NULL;
CSinglePacked::GarbageCollection CSinglePacked::m_Collection;

CSinglePacked::CSinglePacked(QDialog *parent /* = NULL */)
	:QDialog(parent)
{
	ui.setupUi(this);
	this->setFixedSize(this->size());
	ui.dateEdit_ChuChang->setDateTime(QDateTime::fromString("1900-1-1", "yyyy-M-d"));
	ui.dateEdit_ZhuangBei->setDateTime(QDateTime::fromString("1900-1-1", "yyyy-M-d"));
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
	QDate DTime = QDate::fromString(data.at(7).toString(), "yyyy/MM/dd");
	ui.dateEdit_ChuChang->setDate(DTime);
	DTime = QDate::fromString(data.at(8).toString(), "yyyy/MM/dd");
	ui.dateEdit_ZhuangBei->setDate(DTime);
}

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

	/*sql = "insert GunManager.dbo.SinglePackedTable values(\'" + WenJianHao + "\',\'" + PingZhengHao + "\',\'" + DaiMa + "\',\'";
	sql += ZhuangBeiMing +  "\',\'" + BianHao + "\',\'"+ QueShiQingKuang + "\',\'" + LiShuDanWei + "\',\'" + GuanLiDanWei + "\',\'" + ChuChangTime + "\',\'";
	sql += ZhuangBeiTime + "\'," + QString::fromLocal8Bit("\'δ����\'") + ",\'1900-1-1\')";
*/
	sql = "insert GunManager.dbo.SinglePackedTable values(\'" + WenJianHao + "\',\'" + PingZhengHao + "\',\'" + DaiMa + "\',\'";
	sql += ZhuangBeiMing + "\',\'\',\'\',\'" + LiShuDanWei + "\',\'" + GuanLiDanWei + "\',\'" + ChuChangTime + "\',\'";
	sql += ZhuangBeiTime + "\'," + QString::fromLocal8Bit("\'δ����\'") + ",\'" + RuKuDateTime + "\'" + ",\'1900-1-1\')";//��¼ʱ���Ǵ���һ����װ����ʱ��ʱ��
	
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


