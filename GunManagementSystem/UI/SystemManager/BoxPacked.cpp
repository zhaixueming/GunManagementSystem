#include "BoxPacked.h"

CBoxPacked *CBoxPacked::m_Instance = NULL;
CBoxPacked::GarbageCollection CBoxPacked::m_Collection;

CBoxPacked::CBoxPacked(QDialog *parent /* = NULL */)
	:QDialog(parent)
{
	ui.setupUi(this);
	this->setFixedSize(this->size());
	ui.pushButton_QueDing->setStyleSheet("QPushButton{font: 75 15pt '微软雅黑';background-color:rgb(190, 190, 190);color: rgb(34, 139, 34);border:2px groove gray;border-radius:50px;padding:2px 4px;border-style: outset;}"
		"QPushButton:hover{background-color:gray; color: rgb(10, 10, 10);}"
		"QPushButton:pressed{background-color:rgb(210, 20, 20);border-style: inset;}");
	ui.dateEdit_ChuChang->setDateTime(QDateTime::fromString("1900-1-1", "yyyy-M-d"));
	ui.dateEdit_ZhuangBei->setDateTime(QDateTime::fromString("1900-1-1", "yyyy-M-d"));
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

void CBoxPacked::SetControllerEnabled(bool enabled)
{
	ui.lineEdit_WenJianHao->setEnabled(enabled);
	ui.lineEdit_PingZhengHao->setEnabled(enabled);
	ui.lineEdit_DanHao->setEnabled(enabled);
	ui.spinBox->setEnabled(enabled);
}

void CBoxPacked::SetControllContent(QList<QVariant> data)
{
	if (data.size() != 10)
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
	QDate DTime = QDate::fromString(data.at(7).toString(), "yyyy-M-d");
	ui.dateEdit_ChuChang->setDate(DTime);
	DTime = QDate::fromString(data.at(8).toString(), "yyyy-M-d");
	ui.dateEdit_ZhuangBei->setDate(DTime);
	ui.spinBox->setValue(data.at(9).toInt());
}

void CBoxPacked::SetOperatorType(int type, QList<QVariant> data)
{
	m_Type = type;
	if (type == 0)
	{
		SetControllerEnabled(true);
		ui.pushButton_QueDing->setText(QString::fromLocal8Bit("添加"));
	}
	else if (type == 1)
	{
		SetControllContent(data);
		SetControllerEnabled(false);
		ui.pushButton_QueDing->setText(QString::fromLocal8Bit("修改"));
	}
}

bool CBoxPacked::CheckBoxRepeat(QString &errMsg)
{
	QString WenJianHao = ui.lineEdit_WenJianHao->text();
	QString PingZhengHao = ui.lineEdit_PingZhengHao->text();
	QString DanHao = ui.lineEdit_DanHao->text();
	QString sql = "select * from GunManager.dbo.BoxPackedTable where " + QString::fromLocal8Bit("退役报废文件号 = \'") + WenJianHao + "\' and ";
	sql += QString::fromLocal8Bit("调拨凭证号 = \'") + PingZhengHao + "\' and " + QString::fromLocal8Bit("装箱单号 = \'") + DanHao + "\'";
	QTableData TableData;
	bool rv = CDatabaseOperator::GetInstance()->execSql(sql, TableData, errMsg);
	return TableData.size() != 0;
}

bool CBoxPacked::CheckBoxDetailsRepeat(QString &errMsg)
{
	QString DanHao = ui.lineEdit_DanHao->text();
	QString sql = "select * from GunManager.dbo.BoxPackedDetailsTable where " + QString::fromLocal8Bit("装箱单号 = \'") + DanHao + "\'";
	QTableData TableData;
	bool rv = CDatabaseOperator::GetInstance()->execSql(sql, TableData, errMsg);
	return TableData.size() != 0;
}

void CBoxPacked::ConfirmModification()
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

	QString DanHao = ui.lineEdit_DanHao->text();
	if (DanHao.isEmpty())
	{
		QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("装箱单号不能为空"));
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
	QString Number = ui.spinBox->text();
	QString sql;
	QString errMsg;
	bool rv = false;
	if (m_Type == 0)
	{
		rv = CheckBoxRepeat(errMsg);
		if (!errMsg.isEmpty())
		{
			QMessageBox::information(this, QString::fromLocal8Bit("箱装查重失败"), errMsg);
			return;
		}
		if (rv)
		{
			QMessageBox::information(this, QString::fromLocal8Bit("箱装查重提示"), QString::fromLocal8Bit("箱装信息记录已存在"));
			return;
		}
		rv = CheckBoxDetailsRepeat(errMsg);
		if (!errMsg.isEmpty())
		{
			QMessageBox::information(this, QString::fromLocal8Bit("箱装列表查重失败"), errMsg);
			return;
		}
		if (rv)
		{
			QMessageBox::information(this, QString::fromLocal8Bit("箱装列表查重提示"), QString::fromLocal8Bit("箱装单号记录已存在"));
			return;
		}
		
		sql = "insert GunManager.dbo.BoxPackedTable values(\'" + WenJianHao + "\',\'" + PingZhengHao + "\',\'" + DanHao + "\',\'";
		sql += DaiMa + "\',\'" + ZhuangBeiMing + "\',\'" + LiShuDanWei + "\',\'" + GuanLiDanWei + "\',\'" + ChuChangTime+ "\',\'";
		sql += ZhuangBeiTime + "\'," + Number + ")";
	}
	else if (m_Type == 1)
	{
		sql = "update GunManager.dbo.BoxPackedTable set " + QString::fromLocal8Bit("装备代码 = \'") + DaiMa + "\',";
		sql += QString::fromLocal8Bit("装备名称 = \'") + ZhuangBeiMing + "\'," + QString::fromLocal8Bit("隶属单位 = \'") + LiShuDanWei + "\',";
		sql += QString::fromLocal8Bit("管理单位 = \'") + GuanLiDanWei + "\'," + QString::fromLocal8Bit("出厂时间 = \'") + ChuChangTime + "\',";
		sql += QString::fromLocal8Bit("装备时间 = \'") + ZhuangBeiTime + "\' where " + QString::fromLocal8Bit("退役报废文件号 = \'") + WenJianHao + "\' and ";
		sql += QString::fromLocal8Bit("调拨凭证号 = \'") + PingZhengHao + "\' and " + QString::fromLocal8Bit("装箱单号 = \'") + DanHao + "\'";
	}
	QTableData TableData;
	rv = CDatabaseOperator::GetInstance()->execSql(sql, TableData, errMsg);
	if (rv)
	{
		if (m_Type == 0)
		{
			/*QDateTime curDateTime = QDateTime::currentDateTime();
			QString JiLuDateTime = curDateTime.toString("yyyy-MM-dd hh:mm:ss");*/
			QDateTime curDateTime = QDateTime::currentDateTime();
			QString RuKuDateTime = curDateTime.toString("yyyy-M-d");//获取当前日期，并转换为字符串


			sql = "insert into GunManager.dbo.BoxPackedDetailsTable values ";
			int n = ui.spinBox->value();
			int i = 0;
			for (; i < n - 1; ++i)
			{
				//sql += "(" + QString::number(i + 1) + ",\'" + DanHao + "\',\'" + DaiMa + "\',\'" + ZhuangBeiMing + QString::fromLocal8Bit("\',\'\',\'\',\'未出库\',\'1900-1-1\'),");
				//sql += "(" + QString::number(i + 1) + ",\'" + DanHao + "\',\'" + DaiMa + "\',\'" + ZhuangBeiMing + QString::fromLocal8Bit("\',\'\',\'\',\'未出库\',\'")+ JiLuDateTime +"\'),";
				//sql += "(" + QString::number(i + 1) + ",\'" + DanHao + "\',\'" + DaiMa + "\',\'" + ZhuangBeiMing + QString::fromLocal8Bit("\',\'\',\'\',\'未出库\',\'") + JiLuDateTime + "\'" + ",\'1900-01-01 00:00:00.000\'),";//这是ok的
				//sql += "(" + QString::number(i + 1) + ",\'" + DanHao + "\',\'" + DaiMa + "\',\'" + ZhuangBeiMing + QString::fromLocal8Bit("\',\'\',\'\',\'未出库\',\'") + RuKuDateTime + "\'" + ",\'1900-1-1\'),";
				sql += "(" + QString::number(i + 1) + ",\'" + DanHao + "\',\'" + DaiMa + "\',\'" + ZhuangBeiMing + QString::fromLocal8Bit("\',\'\',\'\',\'\',\'\',\'\',\'\',\'未出库\',\'") + RuKuDateTime + "\'" + ",\'\',\'\'),";
				
			}
			sql += "(" + QString::number(i + 1) + ",\'" + DanHao + "\',\'" + DaiMa + "\',\'" + ZhuangBeiMing + QString::fromLocal8Bit("\',\'\',\'\',\'\',\'\',\'\',\'\',\'未出库\',\'") + RuKuDateTime + "\'" + ",\'\',\'\')";
			//sql += "(" + QString::number(i + 1) + ",\'" + DanHao + "\',\'" + DaiMa + "\',\'" + ZhuangBeiMing + QString::fromLocal8Bit("\',\'\',\'\',\'未出库\',\'") + JiLuDateTime + "\'" + ",\'1900-01-01 00:00:00.000\')";//这是ok的
			//sql += "(" + QString::number(i + 1) + ",\'" + DanHao + "\',\'" + DaiMa + "\',\'" + ZhuangBeiMing  + QString::fromLocal8Bit("\',\'\',\'\',\'未出库\'") + ",\'" + JiLuDateTime + "\')";
			rv = CDatabaseOperator::GetInstance()->execSql(sql, TableData, errMsg);
			if (!rv)
			{
				QMessageBox::information(this, QString::fromLocal8Bit("添加箱装列表操作失败"), errMsg);
				return;
			}
		}
		QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("操作成功"));
	}
	else
	{
		QMessageBox::information(this, QString::fromLocal8Bit("添加箱装信息操作失败"), errMsg);
	}
}