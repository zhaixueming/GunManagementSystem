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
	QString sql = "select * from GunManager.dbo.SinglePackedTable where " + QString::fromLocal8Bit("退役报废文件号 = \'") + WenJianHao + "\' and ";
	sql += QString::fromLocal8Bit("调拨凭证号 = \'") + PingZhengHao + "\' and " + QString::fromLocal8Bit("装备代码 = \'") + DaiMa + "\'";
	QTableData TableData;
	bool rv = CDatabaseOperator::GetInstance()->execSql(sql, TableData, errMsg);
	return TableData.size() != 0;
}

//创建单装信息数据（槽函数：点击添加即可创建新的一条数据）
void CSinglePacked::ConfirmModification()
{
	QString WenJianHao = ui.lineEdit_WenJianHao->text();
	if (WenJianHao.isEmpty())
	{
		QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("报废文件号不能为空"));
		return;
	}

	QString PingZhengHao = ui.lineEdit_PingZhengHao->text();
	if (PingZhengHao.isEmpty())
	{
		QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("调拨凭证号不能为空"));
		return;
	}

	QString DaiMa = ui.lineEdit_DaiMa->text();
	if (DaiMa.isEmpty())
	{
		QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("装备代码不能为空"));
		return;
	}

	QString ZhuangBeiMing = ui.lineEdit_MingCheng->text();
	if (ZhuangBeiMing.isEmpty())
	{
		QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("装备名称不能为空"));
		return;
	}

	QString LiShuDanWei = ui.lineEdit_LiShuDanWei->text();
	if (LiShuDanWei.isEmpty())
	{
		QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("隶属单位不能为空"));
		return;
	}

	QString GuanLiDanWei = ui.lineEdit_GuanLiDanWei->text();
	if (GuanLiDanWei.isEmpty())
	{
		QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("管理单位不能为空"));
		return;
	}

	QString ChuChangTime = ui.dateEdit_ChuChang->date().toString("yyyy-M-d");
	QString ZhuangBeiTime = ui.dateEdit_ZhuangBei->date().toString("yyyy-M-d");

	/*QDateTime curDateTime = QDateTime::currentDateTime();
	QString JiLuDateTime = curDateTime.toString("yyyy-MM-dd hh:mm:ss");*/
	QDateTime curDateTime = QDateTime::currentDateTime();
	QString RuKuDateTime = curDateTime.toString("yyyy-M-d");
	////为下面第二种数据库插值定义变量值
	/*QString BianHao= QString::fromLocal8Bit(" ");
	QString QueShiQingKuang = QString::fromLocal8Bit(" ");*/
	QString sql;
	QString errMsg;
	bool rv = CheckSinglePackedRepeat(errMsg);
	if (!errMsg.isEmpty())
	{
		QMessageBox::information(this, QString::fromLocal8Bit("错误"), errMsg);
		return;
	}
	if (rv)
	{
		QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("单装记录已存在"));
		return;
	}
	//下面两种方法都可以
	//sql = "insert GunManager.dbo.SinglePackedTable values(\'" + WenJianHao + "\',\'" + PingZhengHao + "\',\'" + DaiMa + "\',\'";
	//sql += ZhuangBeiMing + "\',\'\',\'\',\'" + LiShuDanWei + "\',\'" + GuanLiDanWei + "\',\'" + ChuChangTime + "\',\'";
	//sql += ZhuangBeiTime + "\'," + QString::fromLocal8Bit("\'未出库\'") + ",\'"+JiLuDateTime + "\'" + ",\'1900-01-01 00:00:00.000\')";//记录时间是创建一条单装数据时的时间

	/*sql = "insert GunManager.dbo.SinglePackedTable values(\'" + WenJianHao + "\',\'" + PingZhengHao + "\',\'" + DaiMa + "\',\'";
	sql += ZhuangBeiMing +  "\',\'" + BianHao + "\',\'"+ QueShiQingKuang + "\',\'" + LiShuDanWei + "\',\'" + GuanLiDanWei + "\',\'" + ChuChangTime + "\',\'";
	sql += ZhuangBeiTime + "\'," + QString::fromLocal8Bit("\'未出库\'") + ",\'1900-1-1\')";
*/
	sql = "insert GunManager.dbo.SinglePackedTable values(\'" + WenJianHao + "\',\'" + PingZhengHao + "\',\'" + DaiMa + "\',\'";
	sql += ZhuangBeiMing + "\',\'\',\'\',\'" + LiShuDanWei + "\',\'" + GuanLiDanWei + "\',\'" + ChuChangTime + "\',\'";
	sql += ZhuangBeiTime + "\'," + QString::fromLocal8Bit("\'未出库\'") + ",\'" + RuKuDateTime + "\'" + ",\'1900-1-1\')";//记录时间是创建一条单装数据时的时间
	
	QTableData TableData;
	rv = CDatabaseOperator::GetInstance()->execSql(sql, TableData, errMsg);
	if (rv)
	{
		QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("操作成功"));
	}
	else
	{
		QMessageBox::information(this, QString::fromLocal8Bit("单装记录操作失败"), errMsg);
	}
}


