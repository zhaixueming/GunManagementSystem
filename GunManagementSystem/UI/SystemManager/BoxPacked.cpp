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
	ui.pushButton_QueDing->setStyleSheet("QPushButton{font: 75 15pt '微软雅黑';background-color:rgb(190, 190, 190);color: rgb(34, 139, 34);border:2px groove gray;border-radius:50px;padding:2px 4px;border-style: outset;}"
		"QPushButton:hover{background-color:gray; color: rgb(10, 10, 10);}"
		"QPushButton:pressed{background-color:rgb(210, 20, 20);border-style: inset;}");
	

	
	ui.comboBox_GunType->clear();
	ui.comboBox_GunType->setFixedSize(QSize(200, 30));
	ui.comboBox_GunType->addItem("Default");
	ui.comboBox_GunType->addItem(QString::fromLocal8Bit("95式步枪"));
	ui.comboBox_GunType->addItem(QString::fromLocal8Bit("95-1式步枪"));
	ui.comboBox_GunType->addItem(QString::fromLocal8Bit("54式手枪"));
	ui.comboBox_GunType->addItem(QString::fromLocal8Bit("92式手枪"));
	ui.comboBox_GunType->addItem(QString::fromLocal8Bit("81式步枪"));
	

	//ui.comboBox_GunType->setStyleSheet("QComboBox{font: 75 15pt '微软雅黑';border-radius:3px;color:black;background:white;padding-left:5px;padding-right:12px;border:1px solid #b5b5b5;}\
 //                           QComboBox:hover{border:1px solid gray;}");

	ui.dateEdit_ChuChang->setFixedSize(QSize(200, 30));
	ui.dateEdit_ZhuangBei->setFixedSize(QSize(200, 30));
	ui.dateEdit_ChuChang->setDateTime(QDateTime::fromString("1900-1-1", "yyyy-M-d"));
	ui.dateEdit_ZhuangBei->setDateTime(QDateTime::fromString("1900-1-1", "yyyy-M-d"));
	/*ui.dateEdit_ChuChang->setStyleSheet("QDateEdit{font: 75 15pt '微软雅黑';border-radius:3px;color:black;background:white;padding-left:5px;padding-right:12px;border:1px solid #b5b5b5;}\
                            QDateEdit:hover{border:1px solid gray;}");
	ui.dateEdit_ZhuangBei->setStyleSheet("QDateEdit{font: 75 15pt '微软雅黑';border-radius:3px;color:black;background:white;padding-left:5px;padding-right:12px;border:1px solid #b5b5b5;}\
                            QDateEdit:hover{border:1px solid gray;}");*/


}

void CBoxPacked::SetControllerEnabled(bool enabled)//type==1时，enabled==false
{
	ui.lineEdit_WenJianHao->setEnabled(enabled);
	ui.lineEdit_PingZhengHao->setEnabled(enabled);
	ui.lineEdit_DanHao->setEnabled(enabled);
	ui.spinBox->setEnabled(enabled);
	
}

//修改表单的内容
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
	ui.comboBox_GunType->setCurrentText(data.at(7).toString());//枪支类型
	QDate DTime = QDate::fromString(data.at(8).toString(), "yyyy-M-d");
	ui.dateEdit_ChuChang->setDate(DTime);
	DTime = QDate::fromString(data.at(9).toString(), "yyyy-M-d");
	ui.dateEdit_ZhuangBei->setDate(DTime);
	ui.spinBox->setValue(data.at(10).toInt());
}


////箱装 枪支类型名字
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
//		QMessageBox::information(this, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("未设置枪支类型"));
//		//return;
//	}
//
//}


//创建或编辑表单信息类型
void CBoxPacked::SetOperatorType(int type, QList<QVariant> data)
{
	m_Type = type;//添加
	if (type == 0)
	{
		SetControllerEnabled(true);
		ui.pushButton_QueDing->setText(QString::fromLocal8Bit("添加"));
	}
	else if (type == 1)//修改
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
	if (ChuChangTime > ZhuangBeiTime)
	{
		QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("出厂时间不能晚于装备时间"));
		return;
	}

	QString JianShiZhuangTai = QString::fromLocal8Bit("未检视");
	QString Number = ui.spinBox->text();

	QDateTime curDateTime = QDateTime::currentDateTime();
	QString RuKuDateTime = curDateTime.toString("yyyy-M-d");//获取当前日期，并转换为字符串

	//枪支类型
	QString GunType = ui.comboBox_GunType->currentText();

	QString sql;
	QString errMsg;
	bool rv = false;
	if (m_Type == 0)//新建
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
		sql += DaiMa + "\',\'" + ZhuangBeiMing + "\',\'" + LiShuDanWei + "\',\'" + GuanLiDanWei + "\',\'"+ GunType + "\',\'" + ChuChangTime+ "\',\'";
		sql += ZhuangBeiTime + "\'," + Number + ",\'" + RuKuDateTime + "\')";
	}
	else if (m_Type == 1)//编辑
	{
		sql = "update GunManager.dbo.BoxPackedTable set " + QString::fromLocal8Bit("装备代码 = \'") + DaiMa + "\',";
		sql += QString::fromLocal8Bit("装备名称 = \'") + ZhuangBeiMing + "\'," + QString::fromLocal8Bit("隶属单位 = \'") + LiShuDanWei + "\',";
		sql += QString::fromLocal8Bit("管理单位 = \'") + GuanLiDanWei + "\'," +QString::fromLocal8Bit("枪支类型 = \'") + GunType + "\'," + QString::fromLocal8Bit("出厂时间 = \'") + ChuChangTime + "\',";
		sql += QString::fromLocal8Bit("装备时间 = \'") + ZhuangBeiTime + "\' where " + QString::fromLocal8Bit("退役报废文件号 = \'") + WenJianHao + "\' and ";
		sql += QString::fromLocal8Bit("调拨凭证号 = \'") + PingZhengHao + "\' and " + QString::fromLocal8Bit("装箱单号 = \'") + DanHao + "\'";
		//sql = "update GunManager.dbo.BoxPackedTable set " + QString::fromLocal8Bit("装备代码 = \'") + DaiMa + "\',";
		//sql += QString::fromLocal8Bit("装备名称 = \'") + ZhuangBeiMing + "\'," + QString::fromLocal8Bit("隶属单位 = \'") + LiShuDanWei + "\',";
		//sql += QString::fromLocal8Bit("管理单位 = \'") + GuanLiDanWei + "\'," + QString::fromLocal8Bit("出厂时间 = \'") + ChuChangTime + "\',";
		//sql += QString::fromLocal8Bit("装备时间 = \'") + ZhuangBeiTime + "\',"+ QString::fromLocal8Bit("装箱数量 = ") + Number + " where " + QString::fromLocal8Bit("退役报废文件号 = \'") + WenJianHao + "\' and ";
		//sql += QString::fromLocal8Bit("调拨凭证号 = \'") + PingZhengHao + "\' and " + QString::fromLocal8Bit("装箱单号 = \'") + DanHao + "\'";
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
			//QString RuKuDateTime = curDateTime.toString("yyyy-M-d");//获取当前日期，并转换为字符串
			

			sql = "insert into GunManager.dbo.BoxPackedDetailsTable values ";
			int n = ui.spinBox->value();
			int i = 0;
			for (; i < n - 1; ++i)
			{

				sql += "(" + QString::number(i + 1) + ",\'" + DanHao + "\',\'" + DaiMa + "\',\'" + ZhuangBeiMing + QString::fromLocal8Bit("\',\'\',\'\',\'\',\'\',\'\',\'\',\'未出库\',\'") +  GunType + "\',\'" + RuKuDateTime + "\'" + ",null,null," + "\'" + JianShiZhuangTai + "\'),";
			}
			sql += "(" + QString::number(i + 1) + ",\'" + DanHao + "\',\'" + DaiMa + "\',\'" + ZhuangBeiMing + QString::fromLocal8Bit("\',\'\',\'\',\'\',\'\',\'\',\'\',\'未出库\',\'") +  GunType + "\',\'" + RuKuDateTime + "\'" + ",null,null," + "\'" + JianShiZhuangTai + "\')";
			
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