#include "SystemManager.h"
#include "UserManager.h"
#include "BoxPacked.h"
#include "SinglePacked.h"
#include "QToolButton"
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintPreviewDialog>
#include <QFileDialog>
#include <QTextEdit>
#include "ParameterSettings.h"
#include "qdatetime.h"

CSystemMangaer::CSystemMangaer(QDialog *parent /* = NULL */)
	:QDialog(parent)
{
	ui.setupUi(this);
	this->setWindowFlags(Qt::Dialog | Qt::WindowMinMaxButtonsHint | Qt::WindowCloseButtonHint);
	//Qt::WindowFlags flags = Qt::Dialog;
	////flags |= Qt::MaximizeUsingFullscreenGeometryHint;
 //	flags |= Qt::WindowMinimizeButtonHint;//最小
 //	flags |= Qt::WindowMaximizeButtonHint;//最大
 //	flags |= Qt::WindowCloseButtonHint;//关闭
	//this->showMaximized();
	//setWindowFlags(flags);
	InitVariables();
	InitConnections();
}

CSystemMangaer::~CSystemMangaer()
{
	
}

void CSystemMangaer::InitVariables()
{
	ui.tabWidget->tabBar()->hide();//5.0以上 在5.0以下的tabBar()是受保护的，是protected的，不被外部调用

	m_bInitAlogSuccess = CAlgoCodeReview::GetInstance()->InitAlgo();//vimoOCR模块
	if (!m_bInitAlogSuccess)
	{
		QMessageBox::information(this, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("算法模块初始化失败"));
		return;
	}
	//标题栏红色背景，tab选中蓝色，未选中灰色
	ui.tabWidget_Storage->setStyleSheet("QTabBar::tab{background-color:rgb(220,200,180);color:rgb(0,0,0);font:25pt '微软雅黑'}\
                                  QTabBar::tab::selected{background-color:rgb(0,170,0);color:rgb(255,255,0);font:25pt '微软雅黑'}\
                                  QTabBar::tab{ width:200 }\
 				                 QTabBar::tab{ height:40 }");

	ui.tabWidget_Information->setStyleSheet("QTabBar::tab{background-color:rgb(220,200,180);color:rgb(0,0,0);font:25pt '微软雅黑'}\
                                  QTabBar::tab::selected{background-color:rgb(0,170,0);color:rgb(255,255,0);font:25pt '微软雅黑'}\
                                  QTabBar::tab{ width:150 }\
 				                 QTabBar::tab{ height:40 }");
	//checkbox属性
	//ui.checkBox_QiangGuan->setStyleSheet("QCheckBox::indicator:checked{image:url(:/SysMainWindow/Resources/allow.png);}");
	//ui.checkBox_QiangGuan->setStyleSheet("QCheckBox::indicator{width:50px;height:50px;}");
	/*ui.checkBox_QiangGuan->setStyleSheet("QCheckBox::indicator{width: 177px;height: 66px;color: rgb(0, 0, 0);}");
	ui.checkBox_QiangGuan->setStyleSheet("QCheckBox::indicator:unchecked{image: url(image : url(:D:/documents/smartmoreitem/GunManagementSystem1/GunManagementSystem/GunManagementSystem/Resources/allow.png));}");
		*/

	//按钮属性
	ui.pushButton_AddUser->setStyleSheet("QPushButton{font: 75 15pt '微软雅黑';background-color: rgb(255, 5, 5);border:2px groove gray;border-radius:50px;padding:2px 4px;border-style: outset;}"
		"QPushButton:hover{background-color:rgb(255, 0, 0); color: rgb(255, 255, 0);}"
		"QPushButton:pressed{background-color:rgb(210, 20, 20);border-style: inset;}");
	ui.pushButton_QueryUser->setStyleSheet("QPushButton{font: 75 15pt '微软雅黑';background-color: rgb(41, 136, 41);border:2px groove gray;border-radius:50px;padding:2px 4px;border-style: outset;}"
		"QPushButton:hover{background-color:rgb(40, 136, 40); color: rgb(255, 255, 255);}"
		"QPushButton:pressed{background-color:rgb(210, 20, 20);border-style: inset;}");
	ui.pushButton_QueryBox->setStyleSheet("QPushButton{font: 75 15pt '微软雅黑';background-color: rgb(41, 136, 41);border:2px groove gray;border-radius:50px;padding:2px 4px;border-style: outset;}"
		"QPushButton:hover{background-color:rgb(40, 136, 40); color: rgb(255, 255, 255);}"
		"QPushButton:pressed{background-color:rgb(210, 20, 20);border-style: inset;}");
	ui.pushButton_AddBox->setStyleSheet("QPushButton{font: 75 15pt '微软雅黑';background-color: rgb(255, 5, 5);border:2px groove gray;border-radius:50px;padding:2px 4px;border-style: outset;}"
		"QPushButton:hover{background-color:rgb(255, 0, 0); color: rgb(255, 255, 0);}"
		"QPushButton:pressed{background-color:rgb(210, 20, 20);border-style: inset;}");
	ui.pushButton_PrintBox->setStyleSheet("QPushButton{font: 75 15pt '微软雅黑';background-color:rgb(0, 205, 0);border:2px groove gray;border-radius:50px;padding:2px 4px;border-style: outset;}"
		"QPushButton:hover{background-color:rgb(0, 205, 0); color: rgb(255, 255, 0);}"
		"QPushButton:pressed{background-color:rgb(210, 20, 20);border-style: inset;}");
	ui.pushButton_BoxDetailsReturn->setStyleSheet("QPushButton{font: 75 15pt '微软雅黑';background-color:rgb(190, 190, 190);color: rgb(0, 0, 0);border:2px groove gray;border-radius:50px;padding:2px 4px;border-style: outset;}"
		"QPushButton:hover{background-color:gray; color: rgb(10, 10, 10);}"
		"QPushButton:pressed{background-color:rgb(210, 20, 20);border-style: inset;}");
	ui.pushButton_InageGrabberReturn->setStyleSheet("QPushButton{font: 75 15pt '微软雅黑';background-color:rgb(190, 190, 190);color: rgb(0, 0, 0);border:2px groove gray;border-radius:50px;padding:2px 4px;border-style: outset;}"
		"QPushButton:hover{background-color:gray; color: rgb(10, 10, 10);}"
		"QPushButton:pressed{background-color:rgb(210, 20, 20);border-style: inset;}");
	ui.pushButton_Modify->setStyleSheet("QPushButton{font: 75 15pt '微软雅黑';background-color:rgb(190, 190, 190);color: rgb(255, 0, 0);border:2px groove gray;border-radius:50px;padding:2px 4px;border-style: outset;}"
		"QPushButton:hover{background-color:gray; color: rgb(10, 10, 10);}"
		"QPushButton:pressed{background-color:rgb(210, 20, 20);border-style: inset;}");
	ui.pushButton_Save->setStyleSheet("QPushButton{font: 75 15pt '微软雅黑';background-color:rgb(190, 190, 190);color: rgb(34, 139, 34);border:2px groove gray;border-radius:50px;padding:2px 4px;border-style: outset;}"
		"QPushButton:hover{background-color:gray; color: rgb(10, 10, 10);}"
		"QPushButton:pressed{background-color:rgb(210, 20, 20);border-style: inset;}");
	ui.pushButton_QuerySinglePacked->setStyleSheet("QPushButton{font: 75 15pt '微软雅黑';background-color: rgb(41, 136, 41);border:2px groove gray;border-radius:50px;padding:2px 4px;border-style: outset;}"
		"QPushButton:hover{background-color:rgb(40, 136, 40); color: rgb(255, 255, 255);}"
		"QPushButton:pressed{background-color:rgb(210, 20, 20);border-style: inset;}");
	ui.pushButton_AddSinglePacked->setStyleSheet("QPushButton{font: 75 15pt '微软雅黑';background-color: rgb(255, 5, 5);border:2px groove gray;border-radius:50px;padding:2px 4px;border-style: outset;}"
		"QPushButton:hover{background-color:rgb(255, 0, 0); color: rgb(255, 255, 0);}"
		"QPushButton:pressed{background-color:rgb(210, 20, 20);border-style: inset;}");
	ui.pushButton_PrintSinglePacked->setStyleSheet("QPushButton{font: 75 15pt '微软雅黑';background-color:rgb(0, 205, 0);border:2px groove gray;border-radius:50px;padding:2px 4px;border-style: outset;}"
		"QPushButton:hover{background-color:rgb(0, 205, 0); color: rgb(255, 255, 0);}"
		"QPushButton:pressed{background-color:rgb(210, 20, 20);border-style: inset;}");
	ui.pushButton_QueryDeliver->setStyleSheet("QPushButton{font: 75 15pt '微软雅黑';background-color: rgb(41, 136, 41);border:2px groove gray;border-radius:50px;padding:2px 4px;border-style: outset;}"
		"QPushButton:hover{background-color:rgb(40, 136, 40); color: rgb(255, 255, 255);}"
		"QPushButton:pressed{background-color:rgb(210, 20, 20);border-style: inset;}");
	ui.pushButton_Deliver->setStyleSheet("QPushButton{font: 75 15pt '微软雅黑';background-color: rgb(255, 5, 5);border:2px groove gray;border-radius:50px;padding:2px 4px;border-style: outset;}"
		"QPushButton:hover{background-color:rgb(255, 0, 0); color: rgb(255, 255, 0);}"
		"QPushButton:pressed{background-color:rgb(210, 20, 20);border-style: inset;}");
	ui.pushButton_QueryInfo->setStyleSheet("QPushButton{font: 75 20pt '微软雅黑';background-color: rgb(41, 136, 41);border:2px groove gray;border-radius:50px;padding:2px 4px;border-style: outset;}"
		"QPushButton:hover{background-color:rgb(40, 136, 40); color: rgb(255, 255, 255);}"
		"QPushButton:pressed{background-color:rgb(210, 20, 20);border-style: inset;}");
	ui.pushButton_ExportExcel->setStyleSheet("QPushButton{font: 75 20pt '微软雅黑';background-color:rgb(0, 205, 0);border:2px groove gray;border-radius:50px;padding:2px 4px;border-style: outset;}"
		"QPushButton:hover{background-color:rgb(0, 205, 0); color: rgb(255, 255, 0);}"
		"QPushButton:pressed{background-color:rgb(210, 20, 20);border-style: inset;}");


	

	//设置用户管理列表
	QFont font("微软雅黑", 12);
	ui.tableWidget_User->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui.tableWidget_User->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);//表头字体居中
	ui.tableWidget_User->setEditTriggers(QAbstractItemView::NoEditTriggers);//单元格不可编辑
	ui.tableWidget_User->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//不可拉伸
	ui.tableWidget_User->horizontalHeader()->setFont(font);//设置字体，大小
	ui.tableWidget_User->horizontalHeader()->setHighlightSections(false);//去除表头高亮
	ui.tableWidget_User->horizontalHeader()->setStyleSheet("QHeaderView::section{color:rgb(255,255,255);background:rgb(41,136,41);}");//设置表头和字体颜色
	ui.tableWidget_User->setColumnCount(10);
	QStringList header;
	header << QString::fromLocal8Bit("姓名") << QString::fromLocal8Bit("军官证号") << QString::fromLocal8Bit("识别操作");
	header << QString::fromLocal8Bit("识别监督") << QString::fromLocal8Bit("入库操作") << QString::fromLocal8Bit("入库监督");
	header << QString::fromLocal8Bit("出库操作") << QString::fromLocal8Bit("出库监督") << QString::fromLocal8Bit("编辑");
	header << QString::fromLocal8Bit("删除");
	ui.tableWidget_User->setHorizontalHeaderLabels(header);
	
	//箱装信息入库操作表
	ui.tableWidget_Box->setColumnCount(12);
	ui.tableWidget_Box->setSelectionBehavior(QAbstractItemView::SelectRows); //整行选中的方式
	ui.tableWidget_Box->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);
	ui.tableWidget_Box->setEditTriggers(QAbstractItemView::NoEditTriggers);//不能对表格内容进行修改
	ui.tableWidget_Box->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);//行表头，设置自适应模式，用户可设置，也可被程序设置成默认大小
	ui.tableWidget_Box->horizontalHeader()->setStretchLastSection(true);//最后一列填满控件
	//ui.tableWidget_Box->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	ui.tableWidget_Box->horizontalHeader()->setFont(font);//设置字体
	ui.tableWidget_Box->horizontalHeader()->setHighlightSections(false);
	ui.tableWidget_Box->horizontalHeader()->setStyleSheet("QHeaderView::section{color:rgb(255,255,255);background:rgb(41,136,41);}");
	ui.tableWidget_Box->setColumnCount(12);
	ui.tableWidget_Box->setColumnWidth(0, 170);
	ui.tableWidget_Box->setColumnWidth(1, 170);
	ui.tableWidget_Box->setColumnWidth(2, 170);
	ui.tableWidget_Box->setColumnWidth(3, 170);
	ui.tableWidget_Box->setColumnWidth(4, 170);
	ui.tableWidget_Box->setColumnWidth(5, 190);
	ui.tableWidget_Box->setColumnWidth(6, 190);
	ui.tableWidget_Box->setColumnWidth(7, 120);
	ui.tableWidget_Box->setColumnWidth(8, 120);
	ui.tableWidget_Box->setColumnWidth(9, 120);
	ui.tableWidget_Box->setColumnWidth(10, 120);
	ui.tableWidget_Box->setColumnWidth(11, 120);
	header.clear();
	header << QString::fromLocal8Bit("退役报废文件号") << QString::fromLocal8Bit("退役报废装备处理\n调拨凭证号");
	header << QString::fromLocal8Bit("装箱单号") << QString::fromLocal8Bit("装备代码") << QString::fromLocal8Bit("装备(部件)名称");
	header << QString::fromLocal8Bit("隶属单位") << QString::fromLocal8Bit("管理单位") << QString::fromLocal8Bit("出厂时间");
	header << QString::fromLocal8Bit("装备时间") << QString::fromLocal8Bit("装箱数量") << QString::fromLocal8Bit("编辑");
	header << QString::fromLocal8Bit("删除");
	ui.tableWidget_Box->setHorizontalHeaderLabels(header);

	//箱装列表信息表
	ui.tableWidget_PackedInfo->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui.tableWidget_PackedInfo->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);
	ui.tableWidget_PackedInfo->setEditTriggers(QAbstractItemView::NoEditTriggers);
	//ui.tableWidget_PackedInfo->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	ui.tableWidget_PackedInfo->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);//行表头，设置自适应模式，用户可设置，也可被程序设置成默认大小
	ui.tableWidget_PackedInfo->horizontalHeader()->setStretchLastSection(true);//最后一列填满控件
	ui.tableWidget_PackedInfo->horizontalHeader()->setFont(font);
	ui.tableWidget_PackedInfo->horizontalHeader()->setHighlightSections(false);
	ui.tableWidget_PackedInfo->horizontalHeader()->setStyleSheet("QHeaderView::section{color:rgb(255,255,255);background:rgb(41,136,41);}");
	ui.tableWidget_PackedInfo->setColumnCount(12);
	ui.tableWidget_PackedInfo->setColumnCount(12);
	ui.tableWidget_PackedInfo->setColumnWidth(0, 170);
	ui.tableWidget_PackedInfo->setColumnWidth(1, 170);
	ui.tableWidget_PackedInfo->setColumnWidth(2, 170);
	ui.tableWidget_PackedInfo->setColumnWidth(3, 170);
	ui.tableWidget_PackedInfo->setColumnWidth(4, 170);
	ui.tableWidget_PackedInfo->setColumnWidth(5, 200);
	ui.tableWidget_PackedInfo->setColumnWidth(6, 200);
	ui.tableWidget_PackedInfo->setColumnWidth(7, 120);
	ui.tableWidget_PackedInfo->setColumnWidth(8, 120);
	ui.tableWidget_PackedInfo->setColumnWidth(9, 120);
	ui.tableWidget_PackedInfo->setColumnWidth(10, 120);
	ui.tableWidget_PackedInfo->setColumnWidth(11, 120);
	header.clear();
	header <<QString::fromLocal8Bit("装箱单号") << QString::fromLocal8Bit("装备代码") << QString::fromLocal8Bit("装备(部件)名称");
	header << QString::fromLocal8Bit("单装编号")<< QString::fromLocal8Bit("重要部件缺失情况")<<QString::fromLocal8Bit("枪管号");
	header <<QString::fromLocal8Bit("枪机或套筒号")<<QString::fromLocal8Bit("机枪框号")<<QString::fromLocal8Bit("备份枪管号");
	header << QString::fromLocal8Bit("出库状态") << QString::fromLocal8Bit("编辑") << QString::fromLocal8Bit("删除");//修改..
	ui.tableWidget_PackedInfo->setHorizontalHeaderLabels(header);
	
	//单装入库操作表
	ui.tableWidget_Single->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui.tableWidget_Single->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);
	ui.tableWidget_Single->setEditTriggers(QAbstractItemView::NoEditTriggers);
	//ui.tableWidget_Single->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	ui.tableWidget_Single->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive); //可拉伸
	ui.tableWidget_Single->horizontalHeader()->setStretchLastSection(true);//最后一列填满控件
	ui.tableWidget_Single->horizontalHeader()->setFont(font);
	ui.tableWidget_Single->horizontalHeader()->setHighlightSections(false);
	ui.tableWidget_Single->horizontalHeader()->setStyleSheet("QHeaderView::section{color:rgb(255,255,255);background:rgb(41,136,41);}");
	ui.tableWidget_Single->setColumnCount(17);
	ui.tableWidget_Single->setColumnWidth(0, 110);
	ui.tableWidget_Single->setColumnWidth(1, 160);
	ui.tableWidget_Single->setColumnWidth(2, 110);
	ui.tableWidget_Single->setColumnWidth(3, 110);
	ui.tableWidget_Single->setColumnWidth(4, 110);
	ui.tableWidget_Single->setColumnWidth(5, 160);
	ui.tableWidget_Single->setColumnWidth(6, 100);
	ui.tableWidget_Single->setColumnWidth(7, 130);
	ui.tableWidget_Single->setColumnWidth(8, 100);
	ui.tableWidget_Single->setColumnWidth(9, 100);
	ui.tableWidget_Single->setColumnWidth(10, 110);
	ui.tableWidget_Single->setColumnWidth(11, 110);
	ui.tableWidget_Single->setColumnWidth(12, 100);
	ui.tableWidget_Single->setColumnWidth(13, 100);
	ui.tableWidget_Single->setColumnWidth(14, 100);
	ui.tableWidget_Single->setColumnWidth(15, 60);
	ui.tableWidget_Single->setColumnWidth(16, 60);
	header.clear();
	header << QString::fromLocal8Bit("退役报废\n文件号") << QString::fromLocal8Bit("退役报废装备处理\n调拨凭证号");
	header << QString::fromLocal8Bit("  装备代码  ") << QString::fromLocal8Bit("装备(部件)\n名称") << QString::fromLocal8Bit("  单装编号  ") << QString::fromLocal8Bit("  重要部件缺失情况  ");
	header << QString::fromLocal8Bit("枪管号") << QString::fromLocal8Bit("枪机或套筒号") << QString::fromLocal8Bit("机枪框号") << QString::fromLocal8Bit("备份枪管号");
	header << QString::fromLocal8Bit("  隶属单位  ") << QString::fromLocal8Bit("  管理单位  ") << QString::fromLocal8Bit("  出厂时间  ");
	header << QString::fromLocal8Bit("  装备时间  ") << QString::fromLocal8Bit("出库状态") << QString::fromLocal8Bit("编辑") << QString::fromLocal8Bit("删除");
	ui.tableWidget_Single->setHorizontalHeaderLabels(header);

	//拍照检视界面右下角的列表框，此软件好像没用到
	//m_ListViewModel = new QStandardItemModel();
	//ui.listView->setModel(m_ListViewModel);

	//信息查询表
	ui.tableWidget_Search->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui.tableWidget_Search->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);
	ui.tableWidget_Search->setEditTriggers(QAbstractItemView::NoEditTriggers);
	//ui.tableWidget_Search->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	ui.tableWidget_Search->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive); //可拉伸
	ui.tableWidget_Search->horizontalHeader()->setStretchLastSection(true);//最后一列填满控件
	ui.tableWidget_Search->horizontalHeader()->setFont(font);
	ui.tableWidget_Search->horizontalHeader()->setHighlightSections(false);
	ui.tableWidget_Search->horizontalHeader()->setStyleSheet("QHeaderView::section{color:rgb(255,255,255);background:rgb(41,136,41);}");
	ui.tableWidget_Search->setColumnCount(14);
	ui.tableWidget_Search->setColumnWidth(0, 170);
	ui.tableWidget_Search->setColumnWidth(1, 180);
	ui.tableWidget_Search->setColumnWidth(2, 110);
	ui.tableWidget_Search->setColumnWidth(3, 110);
	ui.tableWidget_Search->setColumnWidth(4, 140);
	ui.tableWidget_Search->setColumnWidth(5, 110);
	ui.tableWidget_Search->setColumnWidth(6, 110);
	ui.tableWidget_Search->setColumnWidth(7, 130);
	ui.tableWidget_Search->setColumnWidth(8, 110);
	ui.tableWidget_Search->setColumnWidth(9, 110);
	ui.tableWidget_Search->setColumnWidth(10, 110);
	ui.tableWidget_Search->setColumnWidth(11, 110);
	ui.tableWidget_Search->setColumnWidth(12, 110);
	ui.tableWidget_Search->setColumnWidth(13, 110);
	header.clear();
	header << QString::fromLocal8Bit(" 退役报废文件号 ") << QString::fromLocal8Bit("退役报废装备处理\n调拨凭证号");
	header << QString::fromLocal8Bit("  装箱单号  ") << QString::fromLocal8Bit("  装备代码  ") << QString::fromLocal8Bit("  装备(部件)名称  ");
	header << QString::fromLocal8Bit("  单装编号  ") << QString::fromLocal8Bit("  出厂时间  ") << QString::fromLocal8Bit("  装备时间  ");
	header << QString::fromLocal8Bit("  检视状态  ") << QString::fromLocal8Bit("  出库状态  ") << QString::fromLocal8Bit("  入库时间  ");
	header << QString::fromLocal8Bit("检视时间") << QString::fromLocal8Bit("  出库时间  ") << QString::fromLocal8Bit("选择");
	ui.tableWidget_Search->setHorizontalHeaderLabels(header);

	//出库表
	
	ui.tableWidget_Delivery->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui.tableWidget_Delivery->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);
	ui.tableWidget_Delivery->setEditTriggers(QAbstractItemView::NoEditTriggers);
	//ui.tableWidget_Delivery->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	ui.tableWidget_Delivery->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive); //可拉伸
	ui.tableWidget_Delivery->horizontalHeader()->setStretchLastSection(true);//最后一列填满控件
	ui.tableWidget_Delivery->horizontalHeader()->setFont(font);
	ui.tableWidget_Delivery->horizontalHeader()->setHighlightSections(false);
	ui.tableWidget_Delivery->horizontalHeader()->setStyleSheet("QHeaderView::section{color:rgb(255,255,255);background:rgb(41,136,41);}");
	ui.tableWidget_Delivery->setColumnCount(15);
	ui.tableWidget_Delivery->setColumnWidth(0, 170);
	ui.tableWidget_Delivery->setColumnWidth(1,180);
	ui.tableWidget_Delivery->setColumnWidth(2, 110);
	ui.tableWidget_Delivery->setColumnWidth(3, 110);
	ui.tableWidget_Delivery->setColumnWidth(4, 130);
	ui.tableWidget_Delivery->setColumnWidth(5, 110);
	ui.tableWidget_Delivery->setColumnWidth(6, 110);
	ui.tableWidget_Delivery->setColumnWidth(7, 130);
	ui.tableWidget_Delivery->setColumnWidth(8, 110);
	ui.tableWidget_Delivery->setColumnWidth(9, 110);
	ui.tableWidget_Delivery->setColumnWidth(10, 110);
	ui.tableWidget_Delivery->setColumnWidth(11, 110);
	ui.tableWidget_Delivery->setColumnWidth(12, 110);
	ui.tableWidget_Delivery->setColumnWidth(13, 110);
	ui.tableWidget_Delivery->setColumnWidth(14, 110);
	header.clear();
	header << QString::fromLocal8Bit(" 退役报废文件号 ") << QString::fromLocal8Bit("退役报废装备处理\n调拨凭证号");
	header << QString::fromLocal8Bit("  装箱单号  ") << QString::fromLocal8Bit("  装备代码  ") << QString::fromLocal8Bit("  装备(部件)名称  ") << QString::fromLocal8Bit("  单装编号  ");
	header << QString::fromLocal8Bit("枪管号") << QString::fromLocal8Bit("枪机或套筒号") << QString::fromLocal8Bit("机枪框号") << QString::fromLocal8Bit("备份枪管号");
	header << QString::fromLocal8Bit("  出厂时间  ") << QString::fromLocal8Bit("  装备时间  ");
	header << QString::fromLocal8Bit("  装箱数量  ") << QString::fromLocal8Bit("  入库时间  ") << QString::fromLocal8Bit("选择");
	ui.tableWidget_Delivery->setHorizontalHeaderLabels(header);
	//ui.tableWidget_Delivery->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

}

void CSystemMangaer::InitConnections()
{
}

void CSystemMangaer::ReceiveStackWidgetIndex(int index)//主界面三个按钮发射信号：---》系统管理界面弹窗
{
	setWindowState(Qt::WindowMaximized);
	ui.tabWidget->setCurrentIndex(index);//多窗口
	update();
}

void CSystemMangaer::AddUser()//账号管理界面-》左上“新建”按钮--》此槽函数
{
	CUserManager::GetInstance()->SetOperatorType(0, QList<QVariant>());//-->调用“用户管理”界面
	CUserManager::GetInstance()->exec();
}


void CSystemMangaer::QueryUserInfo()//账号管理界面的右边“查询”按钮---》此槽函数
{
	QString Name = ui.lineEdit_Name->text();//读取输入的姓名
	QString Number = ui.lineEdit_OfficerNumber->text();//读取输入的军官证号
	QString sql = "select * from GunManager.dbo.UserTable";
	if (!Name.isEmpty() && !Number.isEmpty())//若有姓名与军官证号，就检索
	{
		sql += QString::fromLocal8Bit(" where 姓名 like \'%") + Name + QString::fromLocal8Bit("%\' and 军官证号 like \'%") + Number + "%\'";
	}
	else if (!Name.isEmpty())//若有姓名
	{
		sql += QString::fromLocal8Bit(" where 姓名 like \'%") + Name + "%\'";
	}
	else if (!Number.isEmpty())//若有军官证号
	{
		sql += QString::fromLocal8Bit(" where 军官证号 like \'%") + Number + "%\'";
	}
	m_Password.clear();//执行清空密码列表操作
	QString errMsg;
	QTableData TableData;
	bool rv = CDatabaseOperator::GetInstance()->execSql(sql, TableData, errMsg);
	if (rv)
	{
		//清空数据
		int r = ui.tableWidget_User->rowCount();
		for (int i = 0; i < r; ++i)
		{
			ui.tableWidget_User->removeRow(0);
		}

		//设置行数
		ui.tableWidget_User->setRowCount(TableData.size());

		ui.tableWidget_User->setSortingEnabled(false);//点击表头，排序（否），但是有问题
		
       //代替表头排序
		ui.tableWidget_User->horizontalHeader()->setSortIndicatorShown(true);
		ui.tableWidget_User->horizontalHeader()->setSortIndicator(0, Qt::DescendingOrder);
		connect(ui.tableWidget_User->horizontalHeader(), SIGNAL(sectionClicked(int)), ui.tableWidget_User, SLOT(sortByColumn(int)));
		
		for (int row = 0; row < TableData.size(); ++row)
		{
			QList<QVariant> RowData = TableData.at(row);
			int col = 0, i = 0;
			for (; col < RowData.size(); ++col,++i)
			{
				QString data = RowData.at(col).toString();
				QTableWidgetItem *item;
				//item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
				if (i < 2)
				{
					item = new QTableWidgetItem(data);
					item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
					ui.tableWidget_User->setItem(row, col, item);//为单元格设置Item
				}
				else if (i == 2)
				{
					m_Password.push_back(data);//在最后添加元素
				}
				else if (i > 2)
				{
					
					if (data == "1")
					{
						item = new QTableWidgetItem(QIcon(":/SysMainWindow/Resources/allow.png"),NULL);//QTableWidgetItem 对象存储了单元格的所有内容
						
						/*QLabel *label = new QLabel();
						label->setPixmap(QPixmap(":/SysMainWindow/Resources/allow.png"));
						label->setFixedSize(QSize(this->width(),this->height()));
						label->setAlignment(Qt::AlignHCenter);
						ui.tableWidget_User->setCellWidget(row, col - 1, label);*/
					}
					else if (data == "0")
					{
						item = new QTableWidgetItem(QIcon(":/SysMainWindow/Resources/reject.png"),NULL);
						
						/*QLabel *label = new QLabel();
						label->setPixmap(QPixmap(":/SysMainWindow/Resources/reject.png"));
						label->setAlignment(Qt::AlignHCenter);
						ui.tableWidget_User->setCellWidget(row, col - 1, label);*/
					}
					ui.tableWidget_User->setItem(row, col - 1, item);
				}
			}
			QPushButton *EditButton = new QPushButton(QString::fromLocal8Bit("编辑"));
			EditButton->setStyleSheet("color:rgb(41,136,41)");
			EditButton->setMinimumHeight(20);
			QPushButton *DeleteButton = new QPushButton(QString::fromLocal8Bit("删除"));
			DeleteButton->setStyleSheet("color:rgb(255,0,0)");
			DeleteButton->setMinimumHeight(20);
			ui.tableWidget_User->setCellWidget(row, col - 1, EditButton);
			ui.tableWidget_User->setCellWidget(row, col, DeleteButton);
			connect(EditButton, SIGNAL(clicked()), this, SLOT(ModifyUser()));
			connect(DeleteButton, SIGNAL(clicked()), this, SLOT(DeleteUser()));
		}
		ui.tableWidget_User->setSortingEnabled(true);
		ui.tableWidget_User->sortByColumn(0, Qt::AscendingOrder);
	}
	else
	{
		QMessageBox::information(this, QString::fromLocal8Bit("查询失败"), errMsg);
	}
}

//编辑用户
void CSystemMangaer::ModifyUser()
{
	QPushButton *senderObj = qobject_cast<QPushButton*>(sender());
	if (senderObj == nullptr)
	{
		return;
	}

	int row = ui.tableWidget_User->indexAt(QPoint(senderObj->frameGeometry().x(), senderObj->frameGeometry().y())).row();
	QList<QVariant> RowData;
	RowData.push_back(ui.tableWidget_User->item(row, 0)->text());
	RowData.push_back(ui.tableWidget_User->item(row, 1)->text());
	RowData.push_back(m_Password.at(row));
	RowData.push_back(ui.tableWidget_User->item(row, 2)->text());
	RowData.push_back(ui.tableWidget_User->item(row, 3)->text());
	RowData.push_back(ui.tableWidget_User->item(row, 4)->text());
	RowData.push_back(ui.tableWidget_User->item(row, 5)->text());
	RowData.push_back(ui.tableWidget_User->item(row, 6)->text());
	RowData.push_back(ui.tableWidget_User->item(row, 7)->text());
	CUserManager::GetInstance()->SetOperatorType(1, RowData);
	CUserManager::GetInstance()->exec();
}

//删除用户
void CSystemMangaer::DeleteUser()
{
	QPushButton *senderObj = qobject_cast<QPushButton*>(sender());
	if (senderObj == nullptr)
	{
		return;
	}
	int row = ui.tableWidget_User->indexAt(QPoint(senderObj->frameGeometry().x(), senderObj->frameGeometry().y())).row();
	if (QMessageBox::question(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("确实要删除吗?"), QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes)
	{
		QString name = ui.tableWidget_User->item(row, 0)->text();
		QString number = ui.tableWidget_User->item(row, 1)->text();
		QString sql = "delete from GunManager.dbo.UserTable where " + QString::fromLocal8Bit("姓名 = \'") + name;
		sql += "\' and " + QString::fromLocal8Bit("军官证号 = \'") + number + "\'";
		QString errMsg;
		bool rv = CDatabaseOperator::GetInstance()->execSql(sql, QTableData(), errMsg);
		if (rv)
		{
			ui.tableWidget_User->removeRow(row);
		}
		else
		{
			QMessageBox::information(this, QString::fromLocal8Bit("删除失败"), errMsg);
		}
	}
}

void CSystemMangaer::AddBoxPacked()//编码检视界面-》“箱装入库”界面的左上“新建”按钮--》此槽函数
{
	CBoxPacked::GetInstance()->SetOperatorType(0, QList<QVariant>());
	CBoxPacked::GetInstance()->exec();
}

//修改箱装入库信息
void CSystemMangaer::ModifyBoxPackedInfo()
{
	QPushButton *senderObj = qobject_cast<QPushButton*>(sender());
	if (senderObj == nullptr)
	{
		return;
	}
	int row = ui.tableWidget_Box->indexAt(QPoint(senderObj->frameGeometry().x(), senderObj->frameGeometry().y())).row();
	QList<QVariant> data;
	data.push_back(ui.tableWidget_Box->item(row, 0)->text());  //退役报废文件号
	data.push_back(ui.tableWidget_Box->item(row, 1)->text());  //调拨凭证号
	data.push_back(((QToolButton*)ui.tableWidget_Box->cellWidget(row, 2))->text());  //装箱单号
	data.push_back(ui.tableWidget_Box->item(row, 3)->text());  //装备代码
	data.push_back(ui.tableWidget_Box->item(row, 4)->text());  //装备（部件）名称
	data.push_back(ui.tableWidget_Box->item(row, 5)->text());  //隶属单位
	data.push_back(ui.tableWidget_Box->item(row, 6)->text());  //管理单位
	data.push_back(ui.tableWidget_Box->item(row, 7)->text());  //出厂时间
	data.push_back(ui.tableWidget_Box->item(row, 8)->text());  //装备时间
	data.push_back(ui.tableWidget_Box->item(row, 9)->text());  //装箱数量
	CBoxPacked::GetInstance()->SetOperatorType(1, data);
	CBoxPacked::GetInstance()->exec();
}

//删除箱装信息
void CSystemMangaer::DeleteBoxPackedInfo()
{
	QPushButton *senderObj = qobject_cast<QPushButton*>(sender());
	if (senderObj == nullptr)
	{
		return;
	}
	//int row = senderObj->objectName().toInt();
	int row = ui.tableWidget_Box->indexAt(QPoint(senderObj->frameGeometry().x(), senderObj->frameGeometry().y())).row();
	if (QMessageBox::question(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("确实要删除吗?"), QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes)
	{
		QString WenJianHao = ui.tableWidget_Box->item(row, 0)->text();
		QString PingZhengHao = ui.tableWidget_Box->item(row, 1)->text();
		QToolButton *button = (QToolButton*)ui.tableWidget_Box->cellWidget(row, 2);
		QString DanHao = button->text();
		QString sql = "delete from GunManager.dbo.BoxPackedTable where " + QString::fromLocal8Bit("退役报废文件号 = \'") + WenJianHao + "\'";
		sql += QString::fromLocal8Bit(" and 调拨凭证号 = \'") + PingZhengHao + "\'";
		sql += QString::fromLocal8Bit(" and 装箱单号 = \'") + DanHao + "\'";
		QString errMsg;
		QTableData TableData;
		bool rv = CDatabaseOperator::GetInstance()->execSql(sql, TableData, errMsg);
		if (!rv)
		{
			QMessageBox::information(this, QString::fromLocal8Bit("箱装信息删除错误"), errMsg);
		}
		else
		{
			sql = "delete from GunManager.dbo.BoxPackedDetailsTable where " + QString::fromLocal8Bit("装箱单号 = \'") + DanHao + "\'";
			//sql+= QString::fromLocal8Bit(" and 序号 = \'") + PingZhengHao + "\'";
			//
			rv = CDatabaseOperator::GetInstance()->execSql(sql, TableData, errMsg);
			if (rv)
			{
				ui.tableWidget_Box->removeRow(row);
			}
			else
			{
				QMessageBox::information(this, QString::fromLocal8Bit("箱装列表删除错误"), errMsg);
			}
		}

	}
}


void CSystemMangaer::QueryBoxPacked()//编码检视界面->“箱装入库”界面，右边“查询”按钮——》此槽函数
{
	QString errMsg;
	QTableData TableData;
	QString WenJianHao = ui.lineEdit_WenJianHao->text();//获取文件号
	QString PingZhengHao = ui.lineEdit_PingZhengHao->text();//获取凭证号
	QString DanHao = ui.lineEdit_ZhuangXiangDanHao->text();//获取装箱单号
	QString ChuChangRiQi = ui.dateEdit_BoxCC->dateTime().toString("yyyy-M-d");//获取出场日期
	QString ZhuangBeiRiQi = ui.dateEdit_BoxZB->dateTime().toString("yyyy-M-d");//获取装备日期
	//检索数据库
	QString sql = "select * from GunManager.dbo.BoxPackedTable where";
	sql += QString::fromLocal8Bit(" 退役报废文件号 like \'%") + WenJianHao + "%\'";
	sql += QString::fromLocal8Bit(" and 调拨凭证号 like \'%") + PingZhengHao + "%\'";
	sql += QString::fromLocal8Bit(" and 装箱单号 like \'%") + DanHao + "%\'";
	if (ChuChangRiQi != "1900-1-1")
	{
		sql += QString::fromLocal8Bit("and 出厂时间 = \'") + ChuChangRiQi + "\'";
	}
	if (ZhuangBeiRiQi != "1900-1-1")
	{
		sql += QString::fromLocal8Bit("and 装备时间 = \'") + ZhuangBeiRiQi + "\'";
	}
	bool rv = CDatabaseOperator::GetInstance()->execSql(sql, TableData, errMsg);
	if (!rv)
	{
		QMessageBox::information(this, QString::fromLocal8Bit("查询错误"), errMsg);
	}
	else
	{
		int rows = ui.tableWidget_Box->rowCount();
		for (int i = 0; i < rows; ++i)
		{
			ui.tableWidget_Box->removeRow(0);
		}
		ui.tableWidget_Box->setRowCount(TableData.size());
		ui.tableWidget_Box->setSortingEnabled(false);
		for (int row = 0; row < TableData.size(); ++row)
		{
			QList<QVariant> RowData = TableData.at(row);
			int col = 0;
			for (; col < RowData.size(); ++col)
			{
				QString data = RowData.at(col).toString();
				if (col == 2)
				{
					QToolButton *Button = new QToolButton();
					Button->setText(data);
					Button->setStyleSheet("text-decoration:underline;color:rgb(0,170,0);");
					Button->setAutoRaise(true);
					ui.tableWidget_Box->setCellWidget(row, col, Button);
					connect(Button, SIGNAL(clicked()), this, SLOT(slotClickToolButton()));
				}
				else if (col == 9)
				{
					QString DanHao = RowData.at(2).toString();
					QString sql = "select * from GunManager.dbo.BoxPackedDetailsTable where " + QString::fromLocal8Bit("装箱单号 = \'") + DanHao + "\'";
					QTableData ListTableData;
					QString errMsgList;
					bool rv = CDatabaseOperator::GetInstance()->execSql(sql, ListTableData, errMsgList);
					int countList = ListTableData.size();
					QString countListStr = QString::number(countList);
					QTableWidgetItem *item = new QTableWidgetItem(countListStr);
					item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
					ui.tableWidget_Box->setItem(row, col, item);

				}
				else
				{
					QTableWidgetItem *item = new QTableWidgetItem(data);
					item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
					ui.tableWidget_Box->setItem(row, col, item);
				}
			}
			QPushButton *EditButton = new QPushButton(QString::fromLocal8Bit("编辑"));
			EditButton->setStyleSheet("color:rgb(41,136,41)");
			EditButton->setMinimumHeight(20);
			QPushButton *DeleteButton = new QPushButton(QString::fromLocal8Bit("删除"));
			DeleteButton->setStyleSheet("color:rgb(255,0,0)");
			DeleteButton->setMinimumHeight(20);
			ui.tableWidget_Box->setCellWidget(row, col, EditButton);
			ui.tableWidget_Box->setCellWidget(row, col+1, DeleteButton);
			connect(EditButton, SIGNAL(clicked()), this, SLOT(ModifyBoxPackedInfo()));
			connect(DeleteButton, SIGNAL(clicked()), this, SLOT(DeleteBoxPackedInfo()));
		}
		ui.tableWidget_Box->setSortingEnabled(true);
		ui.tableWidget_Box->sortByColumn(0, Qt::AscendingOrder);
	}
}


//点击装箱单号,进入箱装单号界面，看到的是箱装列表,然后进行编辑和删除操作
void CSystemMangaer::slotClickToolButton()
{
	QToolButton *senderObj = qobject_cast<QToolButton*>(sender());//返回信号来源的对象
	if (senderObj == nullptr)
	{
		return;
	}
	QString text = senderObj->text();
	QString sql = "select * from GunManager.dbo.BoxPackedDetailsTable where " + QString::fromLocal8Bit("装箱单号 = \'") + text + "\'";
	QTableData TableData;
	QString errMsg;
	bool rv = CDatabaseOperator::GetInstance()->execSql(sql, TableData, errMsg);
	if (rv)
	{
		if (TableData.size() > 0)
		{
			ui.tabWidget->setCurrentIndex(3);
			int rows = ui.tableWidget_PackedInfo->rowCount();//表格行数
			for (int i = 0; i < rows; ++i)
			{
				ui.tableWidget_PackedInfo->removeRow(rows);//删除行
			}
			ui.tableWidget_PackedInfo->setRowCount(TableData.size());//长度
			ui.tableWidget_PackedInfo->setSortingEnabled(false);//设置为不可自动排序

			for (int row = 0; row < TableData.size(); ++row)
			{
				QList<QVariant> RowData = TableData.at(row);//每一行数据有几列
				int col = 1;
				for (; col < RowData.size() - 1; ++col)
				{
					QString data = RowData.at(col).toString();
					QTableWidgetItem *item = new QTableWidgetItem(data);
					item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
					ui.tableWidget_PackedInfo->setItem(row, col - 1, item);
				}
				QPushButton *EditButton = new QPushButton(QString::fromLocal8Bit("编辑"));
				EditButton->setStyleSheet("color:rgb(41,136,41)");
				EditButton->setMinimumHeight(20);
				QPushButton *DeleteButton = new QPushButton(QString::fromLocal8Bit("删除"));
				DeleteButton->setStyleSheet("color:rgb(255,0,0)");
				DeleteButton->setMinimumHeight(20);
				//ui.tableWidget_PackedInfo->setCellWidget(row, col - 1, EditButton);
				//ui.tableWidget_PackedInfo->setCellWidget(row, col, DeleteButton);
				ui.tableWidget_PackedInfo->setCellWidget(row, col - 3, EditButton);
				ui.tableWidget_PackedInfo->setCellWidget(row, col-2, DeleteButton);
				connect(EditButton, SIGNAL(clicked()), this, SLOT(EditPackedListInfo()));
				connect(DeleteButton, SIGNAL(clicked()), this, SLOT(DeletePackedListInfo()));
			}
			ui.tableWidget_PackedInfo->setSortingEnabled(true);//设置自动排列
			ui.tableWidget_PackedInfo->sortByColumn(0, Qt::AscendingOrder);//按列排序模式
		}
		else
		{
			return;
		}
	}
	else
	{
		QMessageBox::information(this, QString::fromLocal8Bit("查询箱装列表失败"), errMsg);
	}
}

void CSystemMangaer::BoxDetailsReturn()//装箱信息界面 - 》右下“返回”按钮--》此槽函数
{
	ui.tabWidget->setCurrentIndex(1);
}

//编辑“箱装列表”,枪支部件缺失情况，OCR识别结果等（拍照检视界面下）
void CSystemMangaer::EditPackedListInfo()
{
	QPushButton *senderObj = qobject_cast<QPushButton*>(sender());
	if (senderObj == nullptr)
	{
		return;
	}

	int row = ui.tableWidget_PackedInfo->indexAt(QPoint(senderObj->frameGeometry().x(), senderObj->frameGeometry().y())).row();//行

	QString DanHao = ui.tableWidget_PackedInfo->item(row, 0)->text();//获取箱装列表的第一列为箱装单号
	ui.label_DanHao->setText(DanHao);
	ui.lineEdit_Ocr->setText("");//图像识别编辑框
	ui.lineEdit_XiuZheng->setText("");//人工修正编辑框
	ui.checkBox_QiangGuan->setEnabled(true); //可编辑，激活按钮，可以触发事件
	ui.checkBox_QiangJi->setEnabled(true);
	ui.checkBox_QiangKuang->setEnabled(true);
	ui.checkBox_BeiFen->setEnabled(true);
	ui.checkBox_QiangGuan->setChecked(true);//初始默认复选框为选中状态
	ui.checkBox_QiangJi->setChecked(true);
	ui.checkBox_QiangKuang->setChecked(true);
	ui.checkBox_BeiFen->setChecked(true);
	
	//4个枪支部件编号
	ui.lineEdit_QiangGuan->setText("");//初始值为空
	ui.lineEdit_QiangJi->setText("");
	ui.lineEdit_QiangKuang->setText("");
	ui.lineEdit_BeiFen->setText("");

	//m_ListViewModel->removeRows(0, m_ListViewModel->rowCount());
	m_CurDZBianHao.clear();//单装编号
	m_QSQingKuang.clear();//缺失情况
	m_curMsg.clear();//清空当前信息
	m_curMsg.type = 1;//1为箱装
	m_curMsg.index = row+1;//数据库表-BoxPackedDetailsTable-序号
	m_curMsg.PackedNum = DanHao;//数据库表- BoxPackedDetailsTable-装箱单号
	ui.tabWidget->setCurrentIndex(4);//第4tab
	m_PreviousIndex = 1; //1：箱装信息列
}

//删除箱装列表
void CSystemMangaer::DeletePackedListInfo()
{
	QPushButton *senderObj = qobject_cast<QPushButton*>(sender());
	if (senderObj == nullptr)
	{
		return;
	}
	//int row = senderObj->objectName().toInt();
	int row = ui.tableWidget_PackedInfo->indexAt(QPoint(senderObj->frameGeometry().x(), senderObj->frameGeometry().y())).row();
	
	if (QMessageBox::question(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("确实要删除吗?"), QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes)
	{
		m_curMsg.index = row+1;
		QString DanHao = ui.tableWidget_PackedInfo->item(row, 0)->text();
		QString BianHao = ui.tableWidget_PackedInfo->item(row, 3)->text();
		//QMessageBox::information(this, "check", QString::fromLocal8Bit("看看4是啥 ") + BianHao);
		QString sql = "delete from GunManager.dbo.BoxPackedDetailsTable where " + QString::fromLocal8Bit("序号 = \'") + QString::number(m_curMsg.index) + "\'"; 
		sql += QString::fromLocal8Bit(" and 装箱单号 = \'") + DanHao + "\'";
		sql += QString::fromLocal8Bit(" and 装箱单号 = \'") + DanHao + "\'";
		sql += QString::fromLocal8Bit(" and 单装编号 = \'") + BianHao + "\'";
		//QMessageBox::information(this, "check", QString::fromLocal8Bit("看看4是啥 ") + sql);
		//QMessageBox::information(this, "check", QString::fromLocal8Bit("确认删除行为 ") + QString::number(m_curMsg.index));
		

		QString errMsg;
		QTableData TableData;
		bool rv = CDatabaseOperator::GetInstance()->execSql(sql, TableData, errMsg);
		if (!rv)
		{
			QMessageBox::information(this, QString::fromLocal8Bit("箱装列表删除错误"), errMsg);
		}
		else
		{
			ui.tableWidget_PackedInfo->removeRow(row);
		}
	}
}


void CSystemMangaer::PrintBoxList()//装箱信息界面的左下角的"打印装箱清单"按钮----》此槽函数
{
	//todo
	QVector<QStringList> content;
	int rows = ui.tableWidget_PackedInfo->rowCount();
	if (rows == 0)
	{
		return;
	}
	for (int i = 0; i < rows; ++i)
	{
		QStringList oneRow;
		oneRow.push_back(QString::number(i + 1));
		//oneRow.push_back(ui.tableWidget_PackedInfo->item(i, 1)->text());
		//oneRow.push_back(ui.tableWidget_PackedInfo->item(i, 2)->text());
		//oneRow.push_back(ui.tableWidget_PackedInfo->item(i, 3)->text());
		oneRow.push_back(ui.tableWidget_PackedInfo->item(i, 2)->text());
		oneRow.push_back(ui.tableWidget_PackedInfo->item(i, 3)->text());
		oneRow.push_back(ui.tableWidget_PackedInfo->item(i, 4)->text());
		oneRow.push_back(QString::fromLocal8Bit("支"));
		oneRow.push_back("1");
		content.push_back(oneRow);
	}
	PrintAPI::Instance()->PrintGridA2(content);
}

void CSystemMangaer::AddSinglePacked()//编码检视界面-》“单装入库”界面的左上“新建”按钮--》此槽函数
{
	CSinglePacked::GetInstance()->exec();
}


//编辑“编码检视”--单装入库--》编辑--各个复选框的权限（拍照检视下）
void CSystemMangaer::EditSinglePacked()
{
	QPushButton *senderObj = qobject_cast<QPushButton*>(sender());
	if (senderObj == nullptr)
	{
		return;
	}
	int row = ui.tableWidget_Single->indexAt(QPoint(senderObj->frameGeometry().x(), senderObj->frameGeometry().y())).row();
	ui.label_DanHao->setText("");//单装 没有箱装单号  设为空
	ui.lineEdit_Ocr->setText("");
	ui.lineEdit_XiuZheng->setText("");

	//ui.checkBox_QiangGuan->setEnabled(false);//不可触控
	//ui.checkBox_QiangJi->setEnabled(false);
	//ui.checkBox_QiangKuang->setEnabled(false);
	//ui.checkBox_BeiFen->setEnabled(false);

	ui.checkBox_QiangGuan->setEnabled(true);
	ui.checkBox_QiangJi->setEnabled(true);
	ui.checkBox_QiangKuang->setEnabled(true);
	ui.checkBox_BeiFen->setEnabled(true);
	ui.checkBox_QiangGuan->setChecked(true);
	ui.checkBox_QiangJi->setChecked(true);
	ui.checkBox_QiangKuang->setChecked(true);
	ui.checkBox_BeiFen->setChecked(true);
	//m_ListViewModel->removeRows(0, m_ListViewModel->rowCount());
	
	//4个枪支部件
	ui.lineEdit_QiangGuan->setText("");
	ui.lineEdit_QiangJi->setText("");
	ui.lineEdit_QiangKuang->setText("");
	ui.lineEdit_BeiFen->setText("");


	m_CurDZBianHao.clear();//单装编号清空
	m_curMsg.clear();//清空当前信息
	m_curMsg.index = row;//数据库表-SinglePackedTable-序号,注意:(0----)
	m_curMsg.type = 2;//2为单装
	m_curMsg.BFWenJianHao = ui.tableWidget_Single->item(row, 0)->text();//数据库表 - SinglePackedTable取第1列文件号
	m_curMsg.DBPingZhengHao = ui.tableWidget_Single->item(row, 1)->text();//数据库表 - SinglePackedTable取第2列凭证号
	m_curMsg.ZBDaiMa = ui.tableWidget_Single->item(row, 2)->text();//数据库表 - SinglePackedTable取第3列 装备代码
	ui.tabWidget->setCurrentIndex(4);
	m_PreviousIndex = 2;
}

//删除单装信息
void CSystemMangaer::DeleteSinglePacked()
{
	QPushButton *senderObj = qobject_cast<QPushButton*>(sender());
	if (senderObj == nullptr)
	{
		return;
	}
	//int row = senderObj->objectName().toInt();
	int row = ui.tableWidget_Single->indexAt(QPoint(senderObj->frameGeometry().x(), senderObj->frameGeometry().y())).row();
	if (QMessageBox::question(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("确实要删除吗?"), QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes)
	{
		QString WenJianHao = ui.tableWidget_Single->item(row, 0)->text();
		QString PingZhengHao = ui.tableWidget_Single->item(row, 1)->text();
		QString DaiMa = ui.tableWidget_Single->item(row, 2)->text();
		QString sql = "delete from GunManager.dbo.SinglePackedTable where " + QString::fromLocal8Bit("退役报废文件号 = \'") + WenJianHao + "\'";
		sql += QString::fromLocal8Bit(" and 调拨凭证号 = \'") + PingZhengHao + "\'";
		sql += QString::fromLocal8Bit(" and 装备代码 = \'") + DaiMa + "\'";
		QString errMsg;
		QTableData TableData;
		bool rv = CDatabaseOperator::GetInstance()->execSql(sql, TableData, errMsg);
		if (!rv)
		{
			QMessageBox::information(this, QString::fromLocal8Bit("单装信息删除错误"), errMsg);
		}
		else
		{
			ui.tableWidget_Single->removeRow(row);
		}
	}
}

void CSystemMangaer::QuerySinglePacked()//“编码检视”界面下，单装入库界面下右边"查询"按钮--》此槽函数
{
	QString WenJianHao = ui.lineEdit_SingleWJH->text();
	QString PingZhengHao = ui.lineEdit_SinglePZH->text();
	QString DaiMa = ui.lineEdit_SingleDM->text();
	QString ChuChangRiQi = ui.dateEdit_SingleCC->dateTime().toString("yyyy-M-d");
	QString ZhuangBeiRiQi = ui.dateEdit_SingleZB->dateTime().toString("yyyy-M-d");
	QString sql = "select * from GunManager.dbo.SinglePackedTable where";
	sql += QString::fromLocal8Bit(" 退役报废文件号 like \'%") + WenJianHao + "%\'";
	sql += QString::fromLocal8Bit(" and 调拨凭证号 like \'%") + PingZhengHao + "%\'";
	sql += QString::fromLocal8Bit(" and 装备代码 like \'%") + DaiMa + "%\'";
	if (ChuChangRiQi != "1900-1-1")
	{
		sql += QString::fromLocal8Bit("and 出厂时间 = \'") + ChuChangRiQi + "\'";
	}
	if (ZhuangBeiRiQi != "1900-1-1")
	{
		sql += QString::fromLocal8Bit("and 装备时间 = \'") + ZhuangBeiRiQi + "\'";
	}
	QTableData TableData;
	QString errMsg;
	bool rv = CDatabaseOperator::GetInstance()->execSql(sql, TableData, errMsg);
	if (!rv)
	{
		QMessageBox::information(this, QString::fromLocal8Bit("查询错误"), errMsg);
	}
	else if (TableData.size() == 0)
	{
		QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("查无此记录"));
	}
	else
	{
		int rows = ui.tableWidget_Single->rowCount();
		for (int i = 0; i < rows; ++i)
		{
			ui.tableWidget_Single->removeRow(0);
		}
		ui.tableWidget_Single->setRowCount(TableData.size());
		ui.tableWidget_Single->setSortingEnabled(false);
		for (int row = 0; row < TableData.size(); ++row)
		{
			QList<QVariant> RowData = TableData.at(row);
			int col = 0;
			for (; col < RowData.size()-1; ++col)
			{
				QString data = RowData.at(col).toString();
				QTableWidgetItem *item = new QTableWidgetItem(data);
				item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
				ui.tableWidget_Single->setItem(row, col, item);
			}
			QPushButton *EditButton = new QPushButton(QString::fromLocal8Bit("编辑"));
			EditButton->setStyleSheet("color:rgb(41,136,41)");
			EditButton->setMinimumHeight(20);
			QPushButton *DeleteButton = new QPushButton(QString::fromLocal8Bit("删除"));
			DeleteButton->setStyleSheet("color:rgb(255,0,0)");
			DeleteButton->setMinimumHeight(20);
			//ui.tableWidget_Single->setCellWidget(row, col, EditButton);
			//ui.tableWidget_Single->setCellWidget(row, col+1, DeleteButton);
			ui.tableWidget_Single->setCellWidget(row, col-2, EditButton);
			ui.tableWidget_Single->setCellWidget(row, col-1, DeleteButton);
			connect(EditButton, SIGNAL(clicked()), this, SLOT(EditSinglePacked()));
			connect(DeleteButton, SIGNAL(clicked()), this, SLOT(DeleteSinglePacked()));
		}
		ui.tableWidget_Single->setSortingEnabled(true);
		ui.tableWidget_Single->sortByColumn(0, Qt::AscendingOrder);
	}
}

void CSystemMangaer::PrintSinglePacked()//编码检视界面->"单装入库"界面,左下角“打印单装卡片”按钮--》此槽函数
{
	// 创建打印机对象
	int row = ui.tableWidget_Single->currentRow();
	if (row < 0)
	{
		QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("请选择要打印的数据"));
		return;
	}

	QStringList content;
	content.push_back(ui.tableWidget_Single->item(row, 0)->text());//退役报废文件号
	content.push_back(ui.tableWidget_Single->item(row, 1)->text());//调拨凭证号
	content.push_back(ui.tableWidget_Single->item(row, 2)->text());//装备代码
	content.push_back(ui.tableWidget_Single->item(row, 3)->text());//装备名称
	content.push_back(ui.tableWidget_Single->item(row, 4)->text());//单装编号
	//content.push_back(ui.tableWidget_Single->item(row, 5)->text());//重要部件缺失情况
	content.push_back(ui.tableWidget_Single->item(row, 10)->text());//隶属单位
	content.push_back(ui.tableWidget_Single->item(row, 11)->text());//管理单位
	content.push_back(ui.tableWidget_Single->item(row, 12)->text());//出厂时间
	content.push_back(ui.tableWidget_Single->item(row, 13)->text());//装备时间

	PrintAPI::Instance()->PrintGridA3(content);
}


void CSystemMangaer::QueryInformations()//信息管理界面->“查询”界面中右边的"查询"按钮---》此槽函数
{
	//select t1.退役报废文件号,t1.调拨凭证号,t1.装箱单号,t1.装备代码,t1.装备名称,t2.单装编号,t1.出厂时间,t1.装备时间,t1.已检视 as 状态,t2.记录时间
	//from BoxPackedTable t1 right join BoxPackedDetailsTable t2 on t1.装箱单号 = t2.装箱单号 and t1.装备代码 = t2.装备代码 and t1.装备名称 = t2.装备名称

	QString sql = QString::fromLocal8Bit("select t1.退役报废文件号,t1.调拨凭证号,t1.装箱单号,t1.装备代码,t1.装备名称,t2.单装编号,t1.出厂时间,t1.装备时间,t2.出库状态,t2.入库时间,t2.检视时间,t2.出库时间");
	sql += " from GunManager.dbo.BoxPackedTable t1 right join GunManager.dbo.BoxPackedDetailsTable t2 on";
	sql += QString::fromLocal8Bit(" t1.装箱单号 = t2.装箱单号 and t1.装备代码 = t2.装备代码 and t1.装备名称 = t2.装备名称");
	sql += " where " + QString::fromLocal8Bit("t1.退役报废文件号 like \'%") + ui.lineEdit_BFWenJianHao->text() + "%\'";
	sql += " and " + QString::fromLocal8Bit("t1.调拨凭证号 like \'%") + ui.lineEdit_DBPingZhengHao->text() + "%\'";
	sql += " and " + QString::fromLocal8Bit("t1.装箱单号 like \'%") + ui.lineEdit_XZDanHao->text() + "%\'";
	sql += " and " + QString::fromLocal8Bit("t1.装备代码 like \'%") + ui.lineEdit_ZBDaima->text() + "%\'";
	sql += " and " + QString::fromLocal8Bit("t1.装备名称 like \'%") + ui.lineEdit_ZBMingCheng->text() + "%\'";
	sql += " and " + QString::fromLocal8Bit("t2.单装编号 like \'%") + ui.lineEdit_DZBianHao->text() + "%\'";//添加的单装编号查询
	QString RuKuRiQi = ui.dateEdit_InfoRK->dateTime().toString("yyyy-M-d");
	QString RuKuRiQi_end = ui.dateEdit_InfoRK_end->dateTime().toString("yyyy-M-d");
	QString ChuKuRiQi = ui.dateEdit_InfoCK->dateTime().toString("yyyy-M-d");
	QString ChuKuRiQi_end = ui.dateEdit_InfoCK_end->dateTime().toString("yyyy-M-d");
	QString JianShiRiqQi = ui.dateEdit_InfoJS->dateTime().toString("yyyy-M-d");
	QString JianShiRiqQi_end = ui.dateEdit_InfoJS_end->dateTime().toString("yyyy-M-d");


	//sql += " and " + QString::fromLocal8Bit("t2.入库时间 BETWEEN \'1995-9-5\' AND \'1995-9-7\' and t2.出库时间 BETWEEN \'1995-12-12\' AND \'1996-9-7\'");
	//sql += " and " + QString::fromLocal8Bit("t2.入库时间 BETWEEN \'")+ RuKuRiQi+"\' AND \'2025-9-7\'");
	//sql += " and " + QString::fromLocal8Bit("t2.入库时间 BETWEEN \'1995-9-5\' AND \'2025-9-7\'");
	//sql += " and " + QString::fromLocal8Bit("t2.入库时间 BETWEEN \'") + RuKuRiQi + "\' AND \'" + RuKuRiQi_end + "\'";
	//sql += " and " + QString::fromLocal8Bit("t2.入库时间 BETWEEN \'") + RuKuRiQi + "\' AND \'" + RuKuRiQi_end + "\'";
	//sql += " and " + QString::fromLocal8Bit("t2.出库时间 BETWEEN \'") + ChuKuRiQi + "\' AND \'" + ChuKuRiQi_end + "\'";
	//if (RuKuRiQi != "1900-1-1"&& RuKuRiQi_end != "1900-1-1")
	//{
	//	sql += " and " + QString::fromLocal8Bit("t2.入库时间 = \'") + RuKuRiQi + "\'";
	//}
	//if (ChuKuRiQi != "1900-1-1")
	//{
	//	sql += " and " + QString::fromLocal8Bit("t2.出库时间 = \'") + ChuKuRiQi + "\'";
	//}

	if (RuKuRiQi != "1900-1-1"&& RuKuRiQi_end != "1900-1-1")
	{
		sql += " and " + QString::fromLocal8Bit("t2.入库时间 BETWEEN \'") + RuKuRiQi + "\' AND \'" + RuKuRiQi_end + "\'";
	}

	if (JianShiRiqQi != "1900-1-1" && JianShiRiqQi_end != "1900-1-1")
	{
		sql += " and " + QString::fromLocal8Bit("t2.检视时间 BETWEEN \'") + JianShiRiqQi + "\'AND \'" + JianShiRiqQi_end + "\'";
	}

	if (ChuKuRiQi != "1900-1-1" && ChuKuRiQi_end != "1900-1-1")
	{
		sql += " and " + QString::fromLocal8Bit("t2.出库时间 BETWEEN \'") + ChuKuRiQi + "\' AND \'" + ChuKuRiQi_end + "\'";
	}

	QTableData PackedTableData;
	QTableData SingleTableData;
	QString errMsg;
	bool rv = CDatabaseOperator::GetInstance()->execSql(sql, PackedTableData, errMsg);
	if (!rv)
	{
		QMessageBox::information(this, QString::fromLocal8Bit("箱装信息查询失败"), errMsg);
		return;
	}

	sql.clear();
	sql = QString::fromLocal8Bit("select 退役报废文件号,调拨凭证号,\'-\' as 箱装单号,装备代码,装备名称,单装编号,出厂时间,装备时间,出库状态,入库时间,检视时间,出库时间 from GunManager.dbo.SinglePackedTable");
	sql += " where " + QString::fromLocal8Bit("退役报废文件号 like \'%") + ui.lineEdit_BFWenJianHao->text() + "%\'";
	sql += " and " + QString::fromLocal8Bit("调拨凭证号 like \'%") + ui.lineEdit_DBPingZhengHao->text() + "%\'";
	sql += " and " + QString::fromLocal8Bit("装备代码 like \'%") + ui.lineEdit_ZBDaima->text() + "%\'";
	sql += " and " + QString::fromLocal8Bit("装备名称 like \'%") + ui.lineEdit_ZBMingCheng->text() + "%\'";
	sql += " and " + QString::fromLocal8Bit("单装编号 like \'%") + ui.lineEdit_DZBianHao->text() + "%\'";//添加的单装编号查询
	
	//sql += " and " + QString::fromLocal8Bit("t2.入库时间 BETWEEN \'1995-9-5\' AND \'1995-9-7\' and t2.出库时间 BETWEEN \'1995-12-12\' AND \'1996-9-7\'");
	//sql += " and " + QString::fromLocal8Bit("入库时间 BETWEEN \'1995-09-05\' AND \'1998-09-07\'");
	//sql += " and " + QString::fromLocal8Bit("入库时间 BETWEEN \'") + RuKuRiQi + "\' AND \'" + RuKuRiQi_end + "\'";


	//if (RuKuRiQi != "1900-01-01")
	//{
	//	sql += " and " + QString::fromLocal8Bit("入库时间 = \'") + RuKuRiQi + "\'";
	//	
	//}
	//if (ChuKuRiQi != "1900-01-01")
	//{
	//	sql += " and " + QString::fromLocal8Bit("出库时间 = \'") + ChuKuRiQi + "\'";
	//}

	if (RuKuRiQi != "1900-1-1" && RuKuRiQi_end != "1900-1-1")
	{
		
		sql += " and " + QString::fromLocal8Bit("入库时间 BETWEEN \'") + RuKuRiQi + "\' AND \'" + RuKuRiQi_end + "\'";
	}

	if (JianShiRiqQi != "1900-1-1" && JianShiRiqQi_end != "1900-1-1")
	{
		sql += " and " + QString::fromLocal8Bit("检视时间 BETWEEN \'") + JianShiRiqQi + "\'AND \'" + JianShiRiqQi_end + "\'";
	}

	if (ChuKuRiQi != "1900-1-1" && ChuKuRiQi_end != "1900-1-1")
	{
		sql += " and " + QString::fromLocal8Bit("出库时间 BETWEEN \'") + ChuKuRiQi + "\'AND \'" + ChuKuRiQi_end + "\'";
	}


	rv = CDatabaseOperator::GetInstance()->execSql(sql, SingleTableData, errMsg);
	if (!rv)
	{
		QMessageBox::information(this, QString::fromLocal8Bit("单装信息查询失败"), errMsg);
		return;
	}
	QTableData AllTableData;
	AllTableData.append(PackedTableData);
	AllTableData.append(SingleTableData);

	int rows = ui.tableWidget_Search->rowCount();
	for (int i = 0; i < rows; ++i)
	{
		ui.tableWidget_Search->removeRow(0);
	}
	ui.tableWidget_Search->setRowCount(AllTableData.size());
	ui.tableWidget_Search->setSortingEnabled(false);
	for (int row = 0; row < AllTableData.size(); ++row)
	{
		QList<QVariant> RowData = AllTableData.at(row);
		int col = 0;
		bool bChecked = true;
		for (; col < 8; ++col)
		{
			QString data = RowData.at(col).toString();
			if (col == 5 && data.isEmpty())
			{
				data = "-";
				bChecked = false;
			}
			QTableWidgetItem *item = new QTableWidgetItem(data);
			item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
			ui.tableWidget_Search->setItem(row, col, item);
		}
		//检视状态
		QTableWidgetItem *item = new QTableWidgetItem(bChecked?QString::fromLocal8Bit("已检视"): QString::fromLocal8Bit("未检视"));
		item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
		ui.tableWidget_Search->setItem(row, col, item);

		//出库状态
		QString data = RowData.at(col).toString();
		item = new QTableWidgetItem(data);
		item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
		ui.tableWidget_Search->setItem(row, col+1, item);
		//ui.tableWidget_Search->setItem(row, col, item);
		

		//入库时间
		data = RowData.at(col + 1).toString();
		data = data.replace("T", " ");
		item = new QTableWidgetItem(data);
		item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);//表格文字居中
		ui.tableWidget_Search->setItem(row, col + 2, item);

		//检视时间
		data = RowData.at(col + 2).toString();
		data = data.replace("T", " ");
		item = new QTableWidgetItem(data);
		item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);//表格文字居中
		//ui.tableWidget_Search->setItem(row, col+2, item);
		ui.tableWidget_Search->setItem(row, col + 3, item);

		//出库时间
		data = RowData.at(col + 3).toString();
		data = data.replace("T", " ");
		item = new QTableWidgetItem(data);
		item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);//表格文字居中
		ui.tableWidget_Search->setItem(row, col + 4, item);

		//复选框
		//QCheckBox *checkBox = new QCheckBox(QString::fromLocal8Bit("勾选"));
		//ui.tableWidget_Search->setCellWidget(row, col+5, checkBox);
		QCheckBox *checkBox = new QCheckBox(QString::fromLocal8Bit("勾选"));
		QHBoxLayout *hLayout = new QHBoxLayout();
		QWidget *widget = new QWidget(ui.tableWidget_Search);
		hLayout->addWidget(checkBox);
		hLayout->setMargin(0);                          // 必须添加, 否则CheckBox不能正常显示
		hLayout->setAlignment(checkBox, Qt::AlignCenter);
		widget->setLayout(hLayout);
		ui.tableWidget_Search->setCellWidget(row, col + 5, widget);
	}
	ui.tableWidget_Search->setSortingEnabled(true);
	ui.tableWidget_Search->sortByColumn(0, Qt::AscendingOrder);
	
}


void CSystemMangaer::QueryDeliveryInformations()//信息管理界面->“出库”界面中右边的"查询"按钮---》此槽函数
{

	QString sql = QString::fromLocal8Bit("select t1.退役报废文件号,t1.调拨凭证号,t1.装箱单号,t1.装备代码,t1.装备名称,t2.单装编号,t2.枪管号,t2.枪击或套筒号,t2.机枪框号,t2.备份枪管号,t1.出厂时间,t1.装备时间,t1.装箱数量,t2.入库时间");
	sql += " from GunManager.dbo.BoxPackedTable t1 right join GunManager.dbo.BoxPackedDetailsTable t2 on";
	sql += QString::fromLocal8Bit(" t1.装箱单号 = t2.装箱单号 and t1.装备代码 = t2.装备代码 and t1.装备名称 = t2.装备名称");
	sql += " where " + QString::fromLocal8Bit("t1.退役报废文件号 like \'%") + ui.lineEdit_DeliveryBFWenJianHao->text() + "%\'";
	sql += " and " + QString::fromLocal8Bit("t1.调拨凭证号 like \'%") + ui.lineEdit_DeliveryDBPingZhengHao->text() + "%\'";
	sql += " and " + QString::fromLocal8Bit("t1.装箱单号 like \'%") + ui.lineEdit_DeliveryXZDanHao->text() + "%\'";
	sql += " and " + QString::fromLocal8Bit("t1.装备代码 like \'%") + ui.lineEdit_DeliveryZBDaima->text() + "%\'";
	sql += " and " + QString::fromLocal8Bit("t1.装备名称 like \'%") + ui.lineEdit_DeliveryZBMingCheng->text() + "%\'";
	sql += " and " + QString::fromLocal8Bit("t2.单装编号 != \'\'");
	sql += " and " + QString::fromLocal8Bit("t2.出库状态 = \'未出库\'");
	QString DeliveryCC = ui.dateEdit_DeliveryCC->dateTime().toString("yyyy-M-d");
	if (DeliveryCC != "1900-1-1")
	{
		sql += " and " + QString::fromLocal8Bit("t1.出厂时间 = \'") + DeliveryCC + "\'";
	}
	QString DeliveryZB = ui.dateEdit_DeliveryZB->dateTime().toString("yyyy-M-d");
	if (DeliveryZB != "1900-1-1")
	{
		sql += " and " + QString::fromLocal8Bit("t1.装备时间 = \'") + DeliveryZB + "\'";
	}

	QTableData PackedTableData;
	QTableData SingleTableData;
	QString errMsg;
	bool rv = CDatabaseOperator::GetInstance()->execSql(sql, PackedTableData, errMsg);
	if (!rv)
	{
		QMessageBox::information(this, QString::fromLocal8Bit("箱装信息查询失败"), errMsg);
		return;
	}

	sql.clear();
	sql = QString::fromLocal8Bit("select 退役报废文件号,调拨凭证号,\'-\' as 箱装单号,装备代码,装备名称,单装编号,枪管号,枪击或套筒号,机枪框号,备份枪管号,出厂时间,装备时间,\'-\' as 箱装数量,入库时间 from GunManager.dbo.SinglePackedTable");
	sql += " where " + QString::fromLocal8Bit("退役报废文件号 like \'%") + ui.lineEdit_DeliveryBFWenJianHao->text() + "%\'";
	sql += " and " + QString::fromLocal8Bit("调拨凭证号 like \'%") + ui.lineEdit_DeliveryDBPingZhengHao->text() + "%\'";
	sql += " and " + QString::fromLocal8Bit("装备代码 like \'%") + ui.lineEdit_DeliveryZBDaima->text() + "%\'";
	sql += " and " + QString::fromLocal8Bit("装备名称 like \'%") + ui.lineEdit_DeliveryZBMingCheng->text() + "%\'";
	sql += " and " + QString::fromLocal8Bit("单装编号 != \'\'");
	sql += " and " + QString::fromLocal8Bit("出库状态 = \'未出库\'");
	if (DeliveryCC != "1900-1-1")
	{
		sql += " and " + QString::fromLocal8Bit("出厂时间 = \'") + DeliveryCC + "\'";
	}
	if (DeliveryZB != "1900-1-1")
	{
		sql += " and " + QString::fromLocal8Bit("装备时间 = \'") + DeliveryZB + "\'";
	}

	rv = CDatabaseOperator::GetInstance()->execSql(sql, SingleTableData, errMsg);
	if (!rv)
	{
		QMessageBox::information(this, QString::fromLocal8Bit("单装信息查询失败"), errMsg);
		return;
	}
	QTableData AllTableData;
	AllTableData.append(PackedTableData);
	AllTableData.append(SingleTableData);

	int rows = ui.tableWidget_Delivery->rowCount();
	for (int i = 0; i < rows; ++i)
	{
		ui.tableWidget_Delivery->removeRow(0);
	}
	ui.tableWidget_Delivery->setRowCount(AllTableData.size());
	ui.tableWidget_Delivery->setSortingEnabled(false);
	for (int row = 0; row < AllTableData.size(); ++row)
	{
		QList<QVariant> RowData = AllTableData.at(row);
		int col = 0;
		for (; col < RowData.size()-1; ++col)
		{
			QString data = RowData.at(col).toString();
			QTableWidgetItem *item = new QTableWidgetItem(data);
			item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
			ui.tableWidget_Delivery->setItem(row, col, item);
		}
		//入库时间
		QString data = RowData.at(col).toString();
		data = data.replace("T", " ");
		QTableWidgetItem *item = new QTableWidgetItem(data);
		item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
		ui.tableWidget_Delivery->setItem(row, col++, item);

		//勾选框
		/*QCheckBox *checkBox = new QCheckBox(QString::fromLocal8Bit("勾选"));
		ui.tableWidget_Delivery->setCellWidget(row, col, checkBox);*/
		  //在QtableWidget中添加QCheckBox并使其居中显示
		QCheckBox *checkBox = new QCheckBox(QString::fromLocal8Bit("勾选"));
		QHBoxLayout *hLayout = new QHBoxLayout();
		QWidget *widget = new QWidget(ui.tableWidget_Delivery);
		hLayout->addWidget(checkBox);
		hLayout->setMargin(0);                          // 必须添加, 否则CheckBox不能正常显示
		hLayout->setAlignment(checkBox, Qt::AlignCenter);
		widget->setLayout(hLayout);
		ui.tableWidget_Delivery->setCellWidget(row, col, widget);//row，col 单元格内
	}
	ui.tableWidget_Delivery->setSortingEnabled(true);
	ui.tableWidget_Delivery->sortByColumn(0, Qt::AscendingOrder);
	//Remainder();
}

  
void CSystemMangaer::DoDelivery()//信息管理界面-》“出库”界面的左上“出库”按钮-----》此槽函数
{
	int rows = ui.tableWidget_Delivery->rowCount();
	int cols = ui.tableWidget_Delivery->columnCount();
	for (int i = 0; i < rows; ++i)
	{
		//QCheckBox *box = (QCheckBox *)ui.tableWidget_Delivery->cellWidget(i, cols - 1);
		QWidget *widget = (QWidget *)ui.tableWidget_Delivery->cellWidget(i, cols - 1);
		QCheckBox *box = (QCheckBox *)widget->children().at(1);
		if (box != NULL && box->isChecked())
		{
			QString sql;
			QString BFWenJianHao = ui.tableWidget_Delivery->item(i, 0)->text();
			QString DBPingZhengHao = ui.tableWidget_Delivery->item(i, 1)->text();//凭证号
			QString ZBDaiMa = ui.tableWidget_Delivery->item(i, 3)->text();//装备单号
			QString ZBMingCheng = ui.tableWidget_Delivery->item(i, 4)->text();//装备名称
			QString DZBianHao = ui.tableWidget_Delivery->item(i, 5)->text();//单装编号
			QString ZXDanHao = ui.tableWidget_Delivery->item(i, 2)->text();  //装箱单号
			//装箱单号为"-",则为单装入库，将单装入库表中此记录修改为"已出库"
			//装箱单号有值，则为箱装入库，将箱装入库信息表中记录修改为"已出库"

			//出库时间
			/*QDateTime curDateTime = QDateTime::currentDateTime();
			QString ChuKuDateTime = curDateTime.toString("yyyy-MM-dd hh:mm:ss");*/

			QDateTime curDateTime = QDateTime::currentDateTime();
			QString ChuKuDateTime = curDateTime.toString("yyyy-M-d");
			if (ZXDanHao == "-")//单装入库
			{
				sql = QString::fromLocal8Bit("update GunManager.dbo.SinglePackedTable set 出库状态 = '已出库',出库时间= \'")+ChuKuDateTime+"\' where";
				sql += QString::fromLocal8Bit(" 退役报废文件号 = ") + "\'" + BFWenJianHao +"\'";
				sql += QString::fromLocal8Bit(" and 调拨凭证号 = ") + "\'" + DBPingZhengHao + "\'";
				sql += QString::fromLocal8Bit(" and 装备代码 = ") + "\'" + ZBDaiMa + "\'";
				sql += QString::fromLocal8Bit(" and 装备名称 = ") + "\'"+ZBMingCheng + "\'";
				sql += QString::fromLocal8Bit(" and 单装编号 = ") + "\'"+DZBianHao + "\'";
				QString errMsg;
				bool rv = CDatabaseOperator::GetInstance()->execSql(sql, QTableData(), errMsg);
				if (!rv)
				{
					QMessageBox::information(this, QString::fromLocal8Bit("单装入库"), errMsg);
					return;
				}
			}
			else
			{
				sql = QString::fromLocal8Bit("update GunManager.dbo.BoxPackedDetailsTable set 出库状态 = '已出库',出库时间= \'") + ChuKuDateTime + "\' where";
				sql += QString::fromLocal8Bit(" GunManager.dbo.BoxPackedDetailsTable.单装编号 in (select 单装编号 from");
				sql += QString::fromLocal8Bit(" GunManager.dbo.BoxPackedTable t1,GunManager.dbo.BoxPackedDetailsTable t2");
				sql += QString::fromLocal8Bit(" where t1.退役报废文件号 = ") + "\'" + BFWenJianHao + "\'";
				sql += QString::fromLocal8Bit(" and t1.调拨凭证号 = ") + "\'" + DBPingZhengHao + "\'";
				sql += QString::fromLocal8Bit(" and t1.装箱单号 = ") + "\'" + ZXDanHao + "\'";
				sql += QString::fromLocal8Bit(" and t1.装箱单号 = t2.装箱单号 and t2.单装编号 = \'") + DZBianHao + "\')";
				QString errMsg;
				bool rv = CDatabaseOperator::GetInstance()->execSql(sql, QTableData(), errMsg);
				if (!rv)
				{
					QMessageBox::information(this, QString::fromLocal8Bit("箱装入库"), errMsg);
					return;
				}
			}
		}
	}
	ExportGridA9();
}

void CSystemMangaer::Remainder()//信息管理界面-》“出库”界面的左上“查询”按钮后，显示库存数量
{
	QString sql = QString::fromLocal8Bit("select t1.退役报废文件号,t1.调拨凭证号,t1.装箱单号,t1.装备代码,t1.装备名称,t2.单装编号,t2.枪管号,t2.枪击或套筒号,t2.机枪框号,t2.备份枪管号,t1.出厂时间,t1.装备时间,t1.装箱数量,t2.入库时间");
	sql += " from GunManager.dbo.BoxPackedTable t1 right join GunManager.dbo.BoxPackedDetailsTable t2 on";
	sql += QString::fromLocal8Bit(" t1.装箱单号 = t2.装箱单号 and t1.装备代码 = t2.装备代码 and t1.装备名称 = t2.装备名称");
	sql += " where " + QString::fromLocal8Bit("t2.出库状态 = \'未出库\'");
	//QString sql = QString::fromLocal8Bit("select * from GunManager.dbo.SinglePackedTable");
	//sql += " where " + QString::fromLocal8Bit("出库状态 = \'未出库\'");

	QTableData PackedTableData;
	QTableData SingleTableData;
	QString errMsg;
	bool rv = CDatabaseOperator::GetInstance()->execSql(sql, PackedTableData, errMsg);
	if (!rv)
	{
		QMessageBox::information(this, QString::fromLocal8Bit("箱装信息查询失败"), errMsg);
		return;
	}

	sql.clear();
	
	sql = QString::fromLocal8Bit("select * from GunManager.dbo.SinglePackedTable");
	sql += " where " + QString::fromLocal8Bit("出库状态 = \'未出库\'");
	/*sql = QString::fromLocal8Bit("select * from GunManager.dbo.SinglePackedTable");
	sql += " where " + QString::fromLocal8Bit("出库状态= \'") + QString::fromLocal8Bit("未出库\'");*/

	rv = CDatabaseOperator::GetInstance()->execSql(sql, SingleTableData, errMsg);
	if (!rv)
	{
		QMessageBox::information(this, QString::fromLocal8Bit("单装信息查询失败"), errMsg);
		return;
	}
	QTableData AllTableData;
	AllTableData.append(PackedTableData);
	AllTableData.append(SingleTableData);
    int count_Remainder =AllTableData.size();
	QString count = QString::number(count_Remainder);
	ui.label_Remainder->setText(count);

}

//导出为csv格式，全程登记表
void CSystemMangaer::ExportGridA9()
{
	//获取创建的csv文件
	QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath(),tr("Files (*.csv)"));
	if (fileName.isEmpty())
	{
		return;
	}

	// 打开.csv文件
	QFile file(fileName);
	if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
	{
		qDebug() << "Open file failed!";
		return;
	}

	//int row = ui.tableWidget_Delivery->rowCount();//表格总行数
	//int col = ui.tableWidget_Delivery->columnCount();

	QTextStream out(&file);
	//QString str;
   //表头 
	out << QString::fromLocal8Bit("退役报废枪械销毁处理情况全过程登记表\n");
	//第一行
	out << QString::fromLocal8Bit("枪械名称,,,,,,,,,")<< QString::fromLocal8Bit("单位,,") << QString::fromLocal8Bit("数量,,") << QString::fromLocal8Bit("来源,,,,,,") << QString::fromLocal8Bit("文件号,,\n");

	//第二行
	out << QString::fromLocal8Bit("序号,")<< QString::fromLocal8Bit("枪械号码,,,,")<< QString::fromLocal8Bit("检查拆解记录,,,,") << QString::fromLocal8Bit("毁形装箱记录,,,,") << QString::fromLocal8Bit("装卸运输记录,,,,,,") << QString::fromLocal8Bit("投炉熔炼记录,,,,") << QString::fromLocal8Bit("备注\n");
	//第三行
	out << QString::fromLocal8Bit(",主枪号,") << QString::fromLocal8Bit("枪管号,") << QString::fromLocal8Bit("机枪号或套筒号,") << QString::fromLocal8Bit("机枪框号,");
	out << QString::fromLocal8Bit("日期,") << QString::fromLocal8Bit("检查人,") << QString::fromLocal8Bit("拆解人,") << QString::fromLocal8Bit("监督人,");
	out << QString::fromLocal8Bit("日期,") << QString::fromLocal8Bit("箱(捆)号,") << QString::fromLocal8Bit("毁形装箱人,") << QString::fromLocal8Bit("监督人,");
	out << QString::fromLocal8Bit("日期,") << QString::fromLocal8Bit("运输车号,") << QString::fromLocal8Bit("装车人,") << QString::fromLocal8Bit("押运人,") << QString::fromLocal8Bit("卸车人,") << QString::fromLocal8Bit("监督人,");
	out << QString::fromLocal8Bit("日期,") << QString::fromLocal8Bit("点验人,") << QString::fromLocal8Bit("核查人,") << QString::fromLocal8Bit("监销人\n");

	//for (int i = 0; i < col; i++)
	//{
	//	//out << QString::fromLocal8Bit("退役") << "\n";
	//	//out << ui.tableWidget_Delivery->header(i, Qt::Horizontal, Qt::DisplayRole).toString() << ",";
	//	if (i == (col - 1))
	//	{
	//		out << "\n";
	//	}
	//}

	//获取表格内容
	int row = ui.tableWidget_Delivery->rowCount();//表格总行数
	int col = ui.tableWidget_Delivery->columnCount();
	for (int i = 0; i < row; i++)
	{
		//QCheckBox *box = (QCheckBox*)ui.tableWidget_Delivery->cellWidget(i, col - 1);
		QWidget *widget = (QWidget *)ui.tableWidget_Delivery->cellWidget(i, col - 1);
		QCheckBox *box = (QCheckBox *)widget->children().at(1);
		if (box->isChecked())
		{
			QString rowStr = "";//str
			out << ",";
			for (int j = 6; j < col - 5; j++)
			{
				
				rowStr = ui.tableWidget_Delivery->item(i, j)->text();
				out << rowStr << ",";// 写入文件
			}
			//out << "\n" << ",";
			out << "\n" ;
		}
		
	}
	QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("出库成功！"));
	//QMessageBox::information(this, QString::fromLocal8Bit("导出数据成功"), QString::fromLocal8Bit("信息已保存在%1！").arg(fileName), QString::fromLocal8Bit("确定"));
	file.close();

}


 //导出xls格式，出库表
//void CSystemMangaer::DoDelivery()//信息管理界面-》“查询”界面的左上“出库”按钮-----》此槽函数
//{
//	int rows = ui.tableWidget_Delivery->rowCount();
//	if (rows == 0)
//	{
//		return;
//	}
//	QString filepath = QFileDialog::getSaveFileName(this, ("Save as..."), QString(), tr("EXCEL files (*.xls *.xlsx)"));
//	if (filepath.isEmpty())
//	{
//		QMessageBox::critical(0, tr("错误"), tr("要保存的文件名不能为空！"));
//		return;
//	}
//	qDebug() << "Export excel:" << filepath.toStdString().c_str();
//
//	int row = ui.tableWidget_Delivery->rowCount();
//	int col = ui.tableWidget_Delivery->columnCount();
//	QList<QString> list;
//	添加列标题  
//	QString HeaderRow;
//	for (int i = 0; i < col - 1; i++)//表头，抛弃最后一列
//	{
//		QString header = ui.tableWidget_Delivery->horizontalHeaderItem(i)->text().toStdString().c_str();
//		if (header.indexOf("\n") != -1);
//		{
//			header = header.replace("\n", "");
//		}
//		HeaderRow.append(header + "\t");
//	}
//	list.push_back(HeaderRow);
//	for (int i = 0; i < row; i++)
//	{
//		QCheckBox *box = (QCheckBox*)ui.tableWidget_Delivery->cellWidget(i, col - 1);
//		if (box->isChecked())
//		{
//			QString rowStr = "";
//			for (int j = 0; j < col - 1; j++)//数据
//			{
//				rowStr += ui.tableWidget_Delivery->item(i, j)->text() + "\t";
//			}
//			list.push_back(rowStr);
//		}
//	}
//	将表格内容添加到富文本中
//	QTextEdit textEdit;
//	for (int i = 0; i < list.size(); i++)
//	{
//		textEdit.append(list.at(i));
//	}
//	写入文件中
//	QFile file(filepath);
//	if (file.open(QFile::WriteOnly | QIODevice::Text))
//	{
//		QTextStream ts(&file);
//		ts.setCodec("GB2312");//这个地方大家自己判断是否用“utf-8”
//		ts << textEdit.document()->toPlainText();
//		file.close();
//		QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("导出excel成功"));
//	}
//}



//修改，准备导出xls的全程记录表
//void CSystemMangaer::DoDelivery()//信息管理界面-》“查询”界面的左上“出库”按钮-----》此槽函数
//{
//	QString fileName = QFileDialog::getSaveFileName(this, QStringLiteral("保存"),
//		QString(), QStringLiteral("Excel 文件(*.xls *.xlsx)"));
//	if (fileName != "")
//	{
//		QAxObject *excel = new QAxObject;
//		if (excel->setControl("Excel.Application")) //连接Excel控件
//		{
//			excel->dynamicCall("SetVisible (bool Visible)", "false");//不显示窗体
//			excel->setProperty("DisplayAlerts", false);//不显示任何警告信息
//			QAxObject *workbooks = excel->querySubObject("WorkBooks");//获取工作簿集合
//			workbooks->dynamicCall("Add");//新建一个工作簿
//			QAxObject *workbook = excel->querySubObject("ActiveWorkBook");//获取当前工作簿
//			QAxObject *worksheet = workbook->querySubObject("Worksheets(int)", 1);
//
//			int i, j;
//			int colount = ui.tableWidget_Delivery->columnCount();
//			int rowcount = ui.tableWidget_Delivery->rowCount();
//
//			QAxObject *cell, *col;
//			//标题行
//			cell = worksheet->querySubObject("Cells(int,int)", 1, 1);
//			cell->dynamicCall("SetValue(const QString&)", QStringLiteral("日志信息"));
//			cell->querySubObject("Font")->setProperty("Size", 15);
//			//调整行高
//			worksheet->querySubObject("Range(const QString&)", "1:1")->setProperty("RowHeight", 30);
//			//合并标题行
//			QString cellTitle;
//			cellTitle.append("A1:");
//			cellTitle.append(QChar(colount - 1 + 'A'));
//			cellTitle.append(QString::number(1));
//			QAxObject *range = worksheet->querySubObject("Range(const QString&)", cellTitle);
//			range->setProperty("WrapText", true);
//			range->setProperty("MergeCells", true);
//			range->setProperty("HorizontalAlignment", -4108);
//			range->setProperty("VerticalAlignment", -4108);
//			//列标题
//			for (i = 0; i < colount; i++)
//			{
//				QString columnName;
//				columnName.append(QChar(i + 'A'));
//				columnName.append(":");
//				columnName.append(QChar(i + 'A'));
//				col = worksheet->querySubObject("Columns(const QString&)", columnName);
//				//ui.tableWidget_Delivery->horizontalHeader()
//				col->setProperty("ColumnWidth", ui.tableWidget_Delivery->columnWidth(i) / 6);
//				cell = worksheet->querySubObject("Cells(int,int)", 2, i + 1);
//
//				//QTableView 获取表格头部文字信息
//				//columnName = ui.tableWidget_Delivery->header(i, Qt::Horizontal, Qt::DisplayRole).toString();
//				//columnName = ui.tableWidget_Delivery->horizontalHeader();
//				cell->dynamicCall("SetValue(const QString&)", columnName);
//				cell->querySubObject("Font")->setProperty("Bold", true);
//				cell->querySubObject("Interior")->setProperty("Color", QColor(191, 191, 191));
//				cell->setProperty("HorizontalAlignment", -4108);//xlCenter
//				cell->setProperty("VerticalAlignment", -4108);//xlCenter
//			}
//			//QTableView 获取表格数据部分
//			for (i = 0; i < rowcount; i++)
//			{
//				for (j = 0; j < colount; j++)
//				{
//					//QModelIndex index = ui.tableWidget_Delivery->index(i, j);
//					//QString strdata = m_model->data(index).toString();
//					QString strdata = ui.tableWidget_Delivery->item(i, j)->text();
//					worksheet->querySubObject("Cells(int,int)", i + 3, j + 1)->dynamicCall("SetValue(const QString&)", strdata);
//				}
//			}
//			//画框线
//			QString lrange;
//			lrange.append("A2:");
//			lrange.append(colount - 1 + 'A');
//			lrange.append(QString::number(ui.tableWidget_Delivery->rowCount() + 2));
//			range = worksheet->querySubObject("Range(const QString&)", lrange);
//			range->querySubObject("Borders")->setProperty("LineStyle", QString::number(1));
//			range->querySubObject("Borders")->setProperty("Color", QColor(0, 0, 0));
//			//调整数据区行高
//			QString rowsName;
//			rowsName.append("2:");
//			rowsName.append(QString::number(ui.tableWidget_Delivery->rowCount() + 2));
//			range = worksheet->querySubObject("Range(const QString&)", rowsName);
//			range->setProperty("RowHeight", 20);
//			workbook->dynamicCall("SaveAs(const QString&)", QDir::toNativeSeparators(fileName));//保存至fileName
//			workbook->dynamicCall("Close()");//关闭工作簿
//			excel->dynamicCall("Quit()");//关闭excel
//			delete excel;
//			excel = NULL;
//
//			if (QMessageBox::question(this, QStringLiteral("完成"), QStringLiteral("文件已经导出，是否现在打开？"), QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes);
//			else
//				QMessageBox::warning(NULL, QStringLiteral("错误"), QStringLiteral("未能创建 Excel 对象，请安装 Microsoft Excel。"), QMessageBox::Apply);
//		}
//	}
//}


void CSystemMangaer::ImageGrabberReturn()//拍照检视界面-》右下“返回”按钮--》此槽函数
{
	if (m_PreviousIndex == 1)
	{
		ui.tabWidget->setCurrentIndex(3);
	}
	else if (m_PreviousIndex == 2)
	{
		ui.tabWidget->setCurrentIndex(1);
	}
}

void CSystemMangaer::ExportExcel()//信息管理界面-》“查询”界面的左上“导出Excel”按钮-----》此槽函数
{
	int rows = ui.tableWidget_Search->rowCount();
	if (rows == 0)
	{
		return;
	}
	QString filepath = QFileDialog::getSaveFileName(this, ("Save as..."),QString(), tr("EXCEL files (*.xls *.xlsx)"));
	if (filepath.isEmpty())
	{
		return;
	}
	qDebug() << "Export excel:" << filepath.toStdString().c_str();

	int row = ui.tableWidget_Search->rowCount();
	int col = ui.tableWidget_Search->columnCount();
	QList<QString> list;
	//添加列标题  
	QString HeaderRow;
	
	for (int i = 0; i < col-1; i++)//最后一列的选择项舍去
	{
		QString header = ui.tableWidget_Search->horizontalHeaderItem(i)->text().toStdString().c_str();
		if (header.indexOf("\n") != -1);
		{
			header = header.replace("\n", "");
		}
		HeaderRow.append(header + "\t");
	}
	list.push_back(HeaderRow);
	for (int i = 0; i < row; i++)
	{
		//QCheckBox *box = (QCheckBox*)ui.tableWidget_Search->cellWidget(i, col-1);

		QWidget *widget = (QWidget *)ui.tableWidget_Search->cellWidget(i, col - 1);
		QCheckBox *box = (QCheckBox *)widget->children().at(1);
		//box->setChecked(true);


		if (box->isChecked())
		{
			QString rowStr = "";
			for (int j = 0; j < col - 1; j++)
			{
				rowStr += ui.tableWidget_Search->item(i, j)->text() + "\t";
			}
			list.push_back(rowStr);
		}
	}
	QTextEdit textEdit;
	for (int i = 0; i < list.size(); i++)
	{
		textEdit.append(list.at(i));
	}

	QFile file(filepath);
	if (file.open(QFile::WriteOnly | QIODevice::Text))
	{
		QTextStream ts(&file);
		//ts.setCodec("GB2312");//这个地方大家自己判断是否用“utf-8”
		ts.setCodec("utf-8");
		ts << textEdit.document()->toPlainText();
		file.close();
		QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("导出excel成功"));
	}
}

//获取图像数据
QImage matToQImage(const cv::Mat &mat)
{
	QImage image;
	auto channels = mat.channels();
	if (channels == 3)  // RGB image
	{
		image = QImage((const uchar *)(mat.data), mat.cols, mat.rows, mat.cols * mat.channels(), QImage::Format_RGB888)
			.rgbSwapped();
	}
	else if (channels == 4)  // RGBA image
	{
		image = QImage((const uchar *)(mat.data), mat.cols, mat.rows, mat.cols * mat.channels(), QImage::Format_RGB32);
	}
	else  // gray image
	{
		image =
			QImage((const uchar *)(mat.data), mat.cols, mat.rows, mat.cols * mat.channels(), QImage::Format_Indexed8);
	}
	return image;
}

void CSystemMangaer::SoftTriggerCodeCamera()//拍照检视界面-》左下“编码拍照”按钮--》此槽函数
{
	emit SendSoftTrigger(1);
}

void CSystemMangaer::SoftTriggerWholeCamera()//拍照检视界面-》右下“整枪拍照”按钮--》此槽函数
{
	emit SendSoftTrigger(2);
}


//从主界面接收到图像数据
void CSystemMangaer::ReceiveImage(int index, Mat image)
{
	if (index == 1)//相机1
	{
		if (m_bInitAlogSuccess)//VimoOCRModule初始化成功
		{
			ui.lineEdit_Ocr->setText("");//拍照检视界面-的右上“图像识别”编辑框
			ui.lineEdit_XiuZheng->setText("");//拍照检视界面-的右上“人工修正”编辑框
			
			 //4个枪支部件
			ui.lineEdit_QiangGuan->setText("");
			ui.lineEdit_QiangJi->setText("");
			ui.lineEdit_QiangKuang->setText("");
			ui.lineEdit_BeiFen->setText("");

			QString result;
			//cvtColor(image, image, COLOR_GRAY2BGR);
			bool bAlgoSuccess = CAlgoCodeReview::GetInstance()->RunAlog(image, result);//调用OCR检测模块
			if (bAlgoSuccess)
			{
				ui.lineEdit_Ocr->setText(result);//拍照检视界面-的右上“图像识别”编辑框，显示结果
				m_CurDZBianHao = result;////识别的单装编号也是OCR识别的结果
				DoSpeaker();//右边的小铃铛读取结果
			}
		}
		CodeImage = image.clone();
		QImage img = matToQImage(image);//调用matToQImage函数，获取图像数据，行。列，格式等
		ui.label_Image1->SetImage(img);
	}
	else if (index == 2)
	{
		GunImage = image.clone();
		QImage img = matToQImage(image);//调用matToQImage函数，获取图像数据，行。列，格式等
		ui.label_Image2->SetImage(img);//“拍照检视”界面，中间两个显示框加上下面的两个按钮
	}
}


//拍照检视界面的右下“保存”按钮---》此槽函数
void CSystemMangaer::SaveRecognizeResult()
{
	if (m_CurDZBianHao.isEmpty())//判断单装编码不能为空
	{
		QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("识别结果为空，不保存任何数据"));
		return;
	}
	//4个枪的部件号
	QString m_QiangGuanHao = ui.lineEdit_QiangGuan->text();
	QString m_QiangJiHao = ui.lineEdit_QiangJi->text();
	QString m_QiangKuangHao = ui.lineEdit_QiangKuang->text();
	QString m_BeiFenHao = ui.lineEdit_BeiFen->text();

	//message弹窗提示
	QString message = QString::fromLocal8Bit("单装编码:") + m_CurDZBianHao + "\n";
	//QString message_QiangGuanHao = QString::fromLocal8Bit("枪管号:") + m_QiangGuanHao + "\n";
	//QString message_QiangJiHao = QString::fromLocal8Bit("枪击/套筒号:") + m_QiangJiHao + "\n";
	//QString message_QiangKuangHao = QString::fromLocal8Bit("机枪框号:") + m_QiangKuangHao + "\n";
	//QString message_BeiFenHao = QString::fromLocal8Bit("备份枪管号:") + m_BeiFenHao + "\n";

	QString LostMeg;
	QString message_QiangGuanHao = QString::fromLocal8Bit("枪管号:") + m_QiangGuanHao + "\n";
	QString message_QiangJiHao = QString::fromLocal8Bit("枪击/套筒号:") + m_QiangJiHao + "\n";
	QString message_QiangKuangHao = QString::fromLocal8Bit("机枪框号:") + m_QiangKuangHao + "\n";
	QString message_BeiFenHao = QString::fromLocal8Bit("备份枪管号:") + m_BeiFenHao;

	if (m_curMsg.type == 1)//箱装
	{
		bool bCheck = ui.checkBox_QiangGuan->isChecked();
		if (!bCheck)
		{
			LostMeg = QString::fromLocal8Bit("枪管缺失");
		}
		bCheck = ui.checkBox_QiangJi->isChecked();
		if (!bCheck)
		{
			LostMeg.isEmpty() ? LostMeg += QString::fromLocal8Bit("枪机/套筒缺失") : LostMeg += QString::fromLocal8Bit(",枪机/套筒缺失");
		}
		bCheck = ui.checkBox_QiangKuang->isChecked();
		if (!bCheck)
		{
			LostMeg.isEmpty() ? LostMeg += QString::fromLocal8Bit("机枪框缺失"): LostMeg += QString::fromLocal8Bit(",机枪框缺失");
		}
		bCheck = ui.checkBox_BeiFen->isChecked();
		if (!bCheck)
		{
			LostMeg.isEmpty() ? LostMeg += QString::fromLocal8Bit("备份枪管缺失"): LostMeg += QString::fromLocal8Bit(",备份枪管缺失");
		}
	}

	else if (m_curMsg.type == 2)//单装
	{
		bool bCheck = ui.checkBox_QiangGuan->isChecked();
		if (!bCheck)
		{
			LostMeg = QString::fromLocal8Bit("枪管缺失");
		}
		bCheck = ui.checkBox_QiangJi->isChecked();
		if (!bCheck)
		{
			LostMeg.isEmpty() ? LostMeg += QString::fromLocal8Bit("枪机/套筒缺失") : LostMeg += QString::fromLocal8Bit(",枪机/套筒缺失");
		}
		bCheck = ui.checkBox_QiangKuang->isChecked();
		if (!bCheck)
		{
			LostMeg.isEmpty() ? LostMeg += QString::fromLocal8Bit("机枪框缺失") : LostMeg += QString::fromLocal8Bit(",机枪框缺失");
		}
		bCheck = ui.checkBox_BeiFen->isChecked();
		if (!bCheck)
		{
			LostMeg.isEmpty() ? LostMeg += QString::fromLocal8Bit("备份枪管缺失") : LostMeg += QString::fromLocal8Bit(",备份枪管缺失");
		}
	}

	/*bool bCheck = ui.checkBox_QiangGuan->isChecked();
	if (!bCheck)
	{
		LostMeg = QString::fromLocal8Bit("枪管缺失");
	}
	bCheck = ui.checkBox_QiangJi->isChecked();
	if (!bCheck)
	{
		LostMeg.isEmpty() ? LostMeg += QString::fromLocal8Bit("枪机/套筒缺失") : LostMeg += QString::fromLocal8Bit(",枪机/套筒缺失");
	}
	bCheck = ui.checkBox_QiangKuang->isChecked();
	if (!bCheck)
	{
		LostMeg.isEmpty() ? LostMeg += QString::fromLocal8Bit("机枪框缺失") : LostMeg += QString::fromLocal8Bit(",机枪框缺失");
	}
	bCheck = ui.checkBox_BeiFen->isChecked();
	if (!bCheck)
	{
			LostMeg.isEmpty() ? LostMeg += QString::fromLocal8Bit("备份枪管缺失") : LostMeg += QString::fromLocal8Bit(",备份枪管缺失");
	}*/

	QPushButton *okbtn = new QPushButton(QString::fromLocal8Bit("确定"));
	QPushButton *cancelbtn = new QPushButton(QString::fromLocal8Bit("取消"));
	QMessageBox *mymsgbox = new QMessageBox;//创建一个消息框
	
	QDateTime curDateTime = QDateTime::currentDateTime();
	QString JianShiDateTime = curDateTime.toString("yyyy-M-d");//获取当前日期，并转换为字符串

	mymsgbox->setIcon(QMessageBox::Warning);
	mymsgbox->setWindowTitle(QString::fromLocal8Bit("是否保存?"));
	//mymsgbox->setText(message+ LostMeg);
	mymsgbox->setText(message + LostMeg + "\n"+ message_QiangGuanHao + message_QiangJiHao + message_QiangKuangHao + message_BeiFenHao);//增加消息框的内容
	mymsgbox->addButton(okbtn, QMessageBox::AcceptRole);
	mymsgbox->addButton(cancelbtn, QMessageBox::RejectRole);
	mymsgbox->show();

	mymsgbox->exec();//阻塞等待用户输入

    //存放图片
	QString path = CParameterSettings::GetInstance()->GetSavePath();
	path += "/" + QDateTime::currentDateTime().toString("yyyy-MM-dd") + "/" + m_CurDZBianHao;
	QDir dir;
	bool rv = dir.mkpath(path);
	if (!rv)
	{
		QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("创建路径失败"));
		return;
	}

	//QString CodeImagePath = path + "/code.bmp";
	QString CodeImagePath = path + "/code.jpg";
	QByteArray ba = CodeImagePath.toLocal8Bit();
	char *file = ba.data();
	//imwrite(file, CodeImage);


	//QString GunImagePath = path + "/gun.bmp";
	QString GunImagePath = path + "/gun.jpg";
	ba = GunImagePath.toLocal8Bit();
	file = ba.data();
	//imwrite(file, GunImage);

	//QString XuHao = QString::number(m_curMsg.index);

	if (mymsgbox->clickedButton() == okbtn)//点击了OK按钮
	{
		QString sql;
		if (m_curMsg.type == 1)//单装
		{
			//更新数据库
			sql = QString::fromLocal8Bit("update GunManager.dbo.BoxPackedDetailsTable set 单装编号 = \'") + m_CurDZBianHao + "\'";
			sql += QString::fromLocal8Bit(",缺失情况 = \'") + LostMeg + "\'";
			sql += QString::fromLocal8Bit(",枪管号 = \'") + m_QiangGuanHao + "\'";
			sql += QString::fromLocal8Bit(",枪击或套筒号 = \'") + m_QiangJiHao + "\'";
			sql += QString::fromLocal8Bit(",机枪框号 = \'") + m_QiangKuangHao + "\'";
			sql += QString::fromLocal8Bit(",备份枪管号 = \'") + m_BeiFenHao + "\'";
			sql += QString::fromLocal8Bit(",检视时间 = \'") + JianShiDateTime + "\'";
			sql += QString::fromLocal8Bit("where GunManager.dbo.BoxPackedDetailsTable.序号 = ") + QString::number(m_curMsg.index);
            sql += QString::fromLocal8Bit(" and GunManager.dbo.BoxPackedDetailsTable.装箱单号 = \'") + m_curMsg.PackedNum + "\'";//m_curMsg.PackedNum=DanHao
			//sql += QString::fromLocal8Bit(" where GunManager.dbo.BoxPackedDetailsTable.序号 = ") + QString::number(m_curMsg.index);


		}
		else if (m_curMsg.type == 2)//箱装
		{
			//更新数据库
			sql = QString::fromLocal8Bit("update GunManager.dbo.SinglePackedTable set 单装编号 = \'") + m_CurDZBianHao + "\'";
			sql += QString::fromLocal8Bit(",缺失情况 = \'") + LostMeg + "\'";
			sql += QString::fromLocal8Bit(",枪管号 = \'") + m_QiangGuanHao + "\'";
			sql += QString::fromLocal8Bit(",枪击或套筒号 = \'") + m_QiangJiHao + "\'";
			sql += QString::fromLocal8Bit(",机枪框号 = \'") + m_QiangKuangHao + "\'";
			sql += QString::fromLocal8Bit(",备份枪管号 = \'") + m_BeiFenHao + "\'";
			sql += QString::fromLocal8Bit(",检视时间 = \'") + JianShiDateTime + "\'";
			sql += QString::fromLocal8Bit(" where 退役报废文件号 = \'") + m_curMsg.BFWenJianHao + "\'";
			sql += QString::fromLocal8Bit(" and 调拨凭证号 = \'") + m_curMsg.DBPingZhengHao + "\'";
			sql += QString::fromLocal8Bit(" and 装备代码 = \'") + m_curMsg.ZBDaiMa + "\'";
		}
		QString errMsg;
		bool rv = CDatabaseOperator::GetInstance()->execSql(sql, QTableData(), errMsg);
		if (!rv)
		{
			QMessageBox::information(this, QString::fromLocal8Bit("数据库执行错误"), errMsg);
			
		}
		else
		{
			if (m_curMsg.type == 1)//箱装列表
			{
				QTableWidgetItem *item = new QTableWidgetItem(m_CurDZBianHao);
				ui.tableWidget_PackedInfo->setItem(m_curMsg.index - 1, 3, item);
				//ui.tableWidget_PackedInfo->setItem(m_curMsg.index - 1, 3, item);
				item = new QTableWidgetItem(LostMeg);
				//ui.tableWidget_PackedInfo->setItem(m_curMsg.index - 1, 4, item);
				ui.tableWidget_PackedInfo->setItem(m_curMsg.index - 1, 4, item);
				
				item = new QTableWidgetItem(m_QiangGuanHao);
				ui.tableWidget_PackedInfo->setItem(m_curMsg.index - 1, 5, item);
				item = new QTableWidgetItem(m_QiangJiHao);
				ui.tableWidget_PackedInfo->setItem(m_curMsg.index - 1, 6, item);
				item = new QTableWidgetItem(m_QiangKuangHao);
				ui.tableWidget_PackedInfo->setItem(m_curMsg.index - 1, 7, item);
				item = new QTableWidgetItem(m_BeiFenHao);
				ui.tableWidget_PackedInfo->setItem(m_curMsg.index - 1, 8, item);

			}
			else if (m_curMsg.type == 2)//单装
			{
				QTableWidgetItem *item = new QTableWidgetItem(m_CurDZBianHao);
				ui.tableWidget_Single->setItem(m_curMsg.index, 4, item);
				item = new QTableWidgetItem(LostMeg);
				ui.tableWidget_Single->setItem(m_curMsg.index, 5, item);

				item = new QTableWidgetItem(m_QiangGuanHao);
				ui.tableWidget_Single->setItem(m_curMsg.index, 6, item);
				item = new QTableWidgetItem(m_QiangJiHao);
				ui.tableWidget_Single->setItem(m_curMsg.index, 7, item);
				item = new QTableWidgetItem(m_QiangKuangHao);
				ui.tableWidget_Single->setItem(m_curMsg.index, 8, item);
				item = new QTableWidgetItem(m_BeiFenHao);
				ui.tableWidget_Single->setItem(m_curMsg.index, 9, item);


				//////加内容（已加）


			}
			ImageGrabberReturn();
		}
	}
}

void CSystemMangaer::DoCorrection()//拍照检视界面->右下角"修正"按钮--》此槽函数
{
	QString result = ui.lineEdit_XiuZheng->text();
	if (result.isEmpty())
	{
		QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("人工修正内容为空"));
		return;
	}
	m_CurDZBianHao = result;//最终识别的单装编码
	ui.lineEdit_Ocr->setText(result);
	DoSpeaker();
}

void CSystemMangaer::DoSpeaker()//拍照检视界面的小铃铛为信号--》此槽函数
{
	QTextToSpeech *m_speech = new QTextToSpeech();

	QVector<QLocale> Locales = m_speech->availableLocales();//获取支持的文本到语音引擎插件的列表
	m_speech->setLocale(QLocale::Chinese);//设置语言环境
	m_speech->setRate(0.3);//语速：-1----1
	m_speech->setPitch(1.0);//音高：-1---1
	m_speech->setVolume(1.0);//音量：0---1
	//m_speech->say("1234");//开始合成文本
	//m_speech->say(QString::fromLocal8Bit("你好"));//开始合成文本
	if (m_speech->state() == QTextToSpeech::Ready)
	{
		m_speech->say(m_CurDZBianHao);//开始合成文本
		//m_speech->say("你好");//开始合成文本
	}
}