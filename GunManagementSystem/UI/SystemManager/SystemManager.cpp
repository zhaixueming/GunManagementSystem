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
 //	flags |= Qt::WindowMinimizeButtonHint;//��С
 //	flags |= Qt::WindowMaximizeButtonHint;//���
 //	flags |= Qt::WindowCloseButtonHint;//�ر�
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
	ui.tabWidget->tabBar()->hide();//5.0���� ��5.0���µ�tabBar()���ܱ����ģ���protected�ģ������ⲿ����

	m_bInitAlogSuccess = CAlgoCodeReview::GetInstance()->InitAlgo();//vimoOCRģ��
	if (!m_bInitAlogSuccess)
	{
		QMessageBox::information(this, QString::fromLocal8Bit("����"), QString::fromLocal8Bit("�㷨ģ���ʼ��ʧ��"));
		return;
	}
	//��������ɫ������tabѡ����ɫ��δѡ�л�ɫ
	ui.tabWidget_Storage->setStyleSheet("QTabBar::tab{background-color:rgb(220,200,180);color:rgb(0,0,0);font:25pt '΢���ź�'}\
                                  QTabBar::tab::selected{background-color:rgb(0,170,0);color:rgb(255,255,0);font:25pt '΢���ź�'}\
                                  QTabBar::tab{ width:200 }\
 				                 QTabBar::tab{ height:40 }");

	ui.tabWidget_Information->setStyleSheet("QTabBar::tab{background-color:rgb(220,200,180);color:rgb(0,0,0);font:25pt '΢���ź�'}\
                                  QTabBar::tab::selected{background-color:rgb(0,170,0);color:rgb(255,255,0);font:25pt '΢���ź�'}\
                                  QTabBar::tab{ width:150 }\
 				                 QTabBar::tab{ height:40 }");
	//checkbox����
	//ui.checkBox_QiangGuan->setStyleSheet("QCheckBox::indicator:checked{image:url(:/SysMainWindow/Resources/allow.png);}");
	//ui.checkBox_QiangGuan->setStyleSheet("QCheckBox::indicator{width:50px;height:50px;}");
	/*ui.checkBox_QiangGuan->setStyleSheet("QCheckBox::indicator{width: 177px;height: 66px;color: rgb(0, 0, 0);}");
	ui.checkBox_QiangGuan->setStyleSheet("QCheckBox::indicator:unchecked{image: url(image : url(:D:/documents/smartmoreitem/GunManagementSystem1/GunManagementSystem/GunManagementSystem/Resources/allow.png));}");
		*/

	//��ť����
	ui.pushButton_AddUser->setStyleSheet("QPushButton{font: 75 15pt '΢���ź�';background-color: rgb(255, 5, 5);border:2px groove gray;border-radius:50px;padding:2px 4px;border-style: outset;}"
		"QPushButton:hover{background-color:rgb(255, 0, 0); color: rgb(255, 255, 0);}"
		"QPushButton:pressed{background-color:rgb(210, 20, 20);border-style: inset;}");
	ui.pushButton_QueryUser->setStyleSheet("QPushButton{font: 75 15pt '΢���ź�';background-color: rgb(41, 136, 41);border:2px groove gray;border-radius:50px;padding:2px 4px;border-style: outset;}"
		"QPushButton:hover{background-color:rgb(40, 136, 40); color: rgb(255, 255, 255);}"
		"QPushButton:pressed{background-color:rgb(210, 20, 20);border-style: inset;}");
	ui.pushButton_QueryBox->setStyleSheet("QPushButton{font: 75 15pt '΢���ź�';background-color: rgb(41, 136, 41);border:2px groove gray;border-radius:50px;padding:2px 4px;border-style: outset;}"
		"QPushButton:hover{background-color:rgb(40, 136, 40); color: rgb(255, 255, 255);}"
		"QPushButton:pressed{background-color:rgb(210, 20, 20);border-style: inset;}");
	ui.pushButton_AddBox->setStyleSheet("QPushButton{font: 75 15pt '΢���ź�';background-color: rgb(255, 5, 5);border:2px groove gray;border-radius:50px;padding:2px 4px;border-style: outset;}"
		"QPushButton:hover{background-color:rgb(255, 0, 0); color: rgb(255, 255, 0);}"
		"QPushButton:pressed{background-color:rgb(210, 20, 20);border-style: inset;}");
	ui.pushButton_PrintBox->setStyleSheet("QPushButton{font: 75 15pt '΢���ź�';background-color:rgb(0, 205, 0);border:2px groove gray;border-radius:50px;padding:2px 4px;border-style: outset;}"
		"QPushButton:hover{background-color:rgb(0, 205, 0); color: rgb(255, 255, 0);}"
		"QPushButton:pressed{background-color:rgb(210, 20, 20);border-style: inset;}");
	ui.pushButton_BoxDetailsReturn->setStyleSheet("QPushButton{font: 75 15pt '΢���ź�';background-color:rgb(190, 190, 190);color: rgb(0, 0, 0);border:2px groove gray;border-radius:50px;padding:2px 4px;border-style: outset;}"
		"QPushButton:hover{background-color:gray; color: rgb(10, 10, 10);}"
		"QPushButton:pressed{background-color:rgb(210, 20, 20);border-style: inset;}");
	ui.pushButton_InageGrabberReturn->setStyleSheet("QPushButton{font: 75 15pt '΢���ź�';background-color:rgb(190, 190, 190);color: rgb(0, 0, 0);border:2px groove gray;border-radius:50px;padding:2px 4px;border-style: outset;}"
		"QPushButton:hover{background-color:gray; color: rgb(10, 10, 10);}"
		"QPushButton:pressed{background-color:rgb(210, 20, 20);border-style: inset;}");
	ui.pushButton_Modify->setStyleSheet("QPushButton{font: 75 15pt '΢���ź�';background-color:rgb(190, 190, 190);color: rgb(255, 0, 0);border:2px groove gray;border-radius:50px;padding:2px 4px;border-style: outset;}"
		"QPushButton:hover{background-color:gray; color: rgb(10, 10, 10);}"
		"QPushButton:pressed{background-color:rgb(210, 20, 20);border-style: inset;}");
	ui.pushButton_Save->setStyleSheet("QPushButton{font: 75 15pt '΢���ź�';background-color:rgb(190, 190, 190);color: rgb(34, 139, 34);border:2px groove gray;border-radius:50px;padding:2px 4px;border-style: outset;}"
		"QPushButton:hover{background-color:gray; color: rgb(10, 10, 10);}"
		"QPushButton:pressed{background-color:rgb(210, 20, 20);border-style: inset;}");
	ui.pushButton_QuerySinglePacked->setStyleSheet("QPushButton{font: 75 15pt '΢���ź�';background-color: rgb(41, 136, 41);border:2px groove gray;border-radius:50px;padding:2px 4px;border-style: outset;}"
		"QPushButton:hover{background-color:rgb(40, 136, 40); color: rgb(255, 255, 255);}"
		"QPushButton:pressed{background-color:rgb(210, 20, 20);border-style: inset;}");
	ui.pushButton_AddSinglePacked->setStyleSheet("QPushButton{font: 75 15pt '΢���ź�';background-color: rgb(255, 5, 5);border:2px groove gray;border-radius:50px;padding:2px 4px;border-style: outset;}"
		"QPushButton:hover{background-color:rgb(255, 0, 0); color: rgb(255, 255, 0);}"
		"QPushButton:pressed{background-color:rgb(210, 20, 20);border-style: inset;}");
	ui.pushButton_PrintSinglePacked->setStyleSheet("QPushButton{font: 75 15pt '΢���ź�';background-color:rgb(0, 205, 0);border:2px groove gray;border-radius:50px;padding:2px 4px;border-style: outset;}"
		"QPushButton:hover{background-color:rgb(0, 205, 0); color: rgb(255, 255, 0);}"
		"QPushButton:pressed{background-color:rgb(210, 20, 20);border-style: inset;}");
	ui.pushButton_QueryDeliver->setStyleSheet("QPushButton{font: 75 15pt '΢���ź�';background-color: rgb(41, 136, 41);border:2px groove gray;border-radius:50px;padding:2px 4px;border-style: outset;}"
		"QPushButton:hover{background-color:rgb(40, 136, 40); color: rgb(255, 255, 255);}"
		"QPushButton:pressed{background-color:rgb(210, 20, 20);border-style: inset;}");
	ui.pushButton_Deliver->setStyleSheet("QPushButton{font: 75 15pt '΢���ź�';background-color: rgb(255, 5, 5);border:2px groove gray;border-radius:50px;padding:2px 4px;border-style: outset;}"
		"QPushButton:hover{background-color:rgb(255, 0, 0); color: rgb(255, 255, 0);}"
		"QPushButton:pressed{background-color:rgb(210, 20, 20);border-style: inset;}");
	ui.pushButton_QueryInfo->setStyleSheet("QPushButton{font: 75 20pt '΢���ź�';background-color: rgb(41, 136, 41);border:2px groove gray;border-radius:50px;padding:2px 4px;border-style: outset;}"
		"QPushButton:hover{background-color:rgb(40, 136, 40); color: rgb(255, 255, 255);}"
		"QPushButton:pressed{background-color:rgb(210, 20, 20);border-style: inset;}");
	ui.pushButton_ExportExcel->setStyleSheet("QPushButton{font: 75 20pt '΢���ź�';background-color:rgb(0, 205, 0);border:2px groove gray;border-radius:50px;padding:2px 4px;border-style: outset;}"
		"QPushButton:hover{background-color:rgb(0, 205, 0); color: rgb(255, 255, 0);}"
		"QPushButton:pressed{background-color:rgb(210, 20, 20);border-style: inset;}");


	

	//�����û������б�
	QFont font("΢���ź�", 12);
	ui.tableWidget_User->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui.tableWidget_User->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);//��ͷ�������
	ui.tableWidget_User->setEditTriggers(QAbstractItemView::NoEditTriggers);//��Ԫ�񲻿ɱ༭
	ui.tableWidget_User->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//��������
	ui.tableWidget_User->horizontalHeader()->setFont(font);//�������壬��С
	ui.tableWidget_User->horizontalHeader()->setHighlightSections(false);//ȥ����ͷ����
	ui.tableWidget_User->horizontalHeader()->setStyleSheet("QHeaderView::section{color:rgb(255,255,255);background:rgb(41,136,41);}");//���ñ�ͷ��������ɫ
	ui.tableWidget_User->setColumnCount(10);
	QStringList header;
	header << QString::fromLocal8Bit("����") << QString::fromLocal8Bit("����֤��") << QString::fromLocal8Bit("ʶ�����");
	header << QString::fromLocal8Bit("ʶ��ල") << QString::fromLocal8Bit("������") << QString::fromLocal8Bit("���ල");
	header << QString::fromLocal8Bit("�������") << QString::fromLocal8Bit("����ල") << QString::fromLocal8Bit("�༭");
	header << QString::fromLocal8Bit("ɾ��");
	ui.tableWidget_User->setHorizontalHeaderLabels(header);
	
	//��װ��Ϣ��������
	ui.tableWidget_Box->setColumnCount(12);
	ui.tableWidget_Box->setSelectionBehavior(QAbstractItemView::SelectRows); //����ѡ�еķ�ʽ
	ui.tableWidget_Box->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);
	ui.tableWidget_Box->setEditTriggers(QAbstractItemView::NoEditTriggers);//���ܶԱ�����ݽ����޸�
	ui.tableWidget_Box->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);//�б�ͷ����������Ӧģʽ���û������ã�Ҳ�ɱ��������ó�Ĭ�ϴ�С
	ui.tableWidget_Box->horizontalHeader()->setStretchLastSection(true);//���һ�������ؼ�
	//ui.tableWidget_Box->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	ui.tableWidget_Box->horizontalHeader()->setFont(font);//��������
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
	header << QString::fromLocal8Bit("���۱����ļ���") << QString::fromLocal8Bit("���۱���װ������\n����ƾ֤��");
	header << QString::fromLocal8Bit("װ�䵥��") << QString::fromLocal8Bit("װ������") << QString::fromLocal8Bit("װ��(����)����");
	header << QString::fromLocal8Bit("������λ") << QString::fromLocal8Bit("����λ") << QString::fromLocal8Bit("����ʱ��");
	header << QString::fromLocal8Bit("װ��ʱ��") << QString::fromLocal8Bit("װ������") << QString::fromLocal8Bit("�༭");
	header << QString::fromLocal8Bit("ɾ��");
	ui.tableWidget_Box->setHorizontalHeaderLabels(header);

	//��װ�б���Ϣ��
	ui.tableWidget_PackedInfo->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui.tableWidget_PackedInfo->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);
	ui.tableWidget_PackedInfo->setEditTriggers(QAbstractItemView::NoEditTriggers);
	//ui.tableWidget_PackedInfo->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	ui.tableWidget_PackedInfo->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);//�б�ͷ����������Ӧģʽ���û������ã�Ҳ�ɱ��������ó�Ĭ�ϴ�С
	ui.tableWidget_PackedInfo->horizontalHeader()->setStretchLastSection(true);//���һ�������ؼ�
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
	header <<QString::fromLocal8Bit("װ�䵥��") << QString::fromLocal8Bit("װ������") << QString::fromLocal8Bit("װ��(����)����");
	header << QString::fromLocal8Bit("��װ���")<< QString::fromLocal8Bit("��Ҫ����ȱʧ���")<<QString::fromLocal8Bit("ǹ�ܺ�");
	header <<QString::fromLocal8Bit("ǹ������Ͳ��")<<QString::fromLocal8Bit("��ǹ���")<<QString::fromLocal8Bit("����ǹ�ܺ�");
	header << QString::fromLocal8Bit("����״̬") << QString::fromLocal8Bit("�༭") << QString::fromLocal8Bit("ɾ��");//�޸�..
	ui.tableWidget_PackedInfo->setHorizontalHeaderLabels(header);
	
	//��װ��������
	ui.tableWidget_Single->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui.tableWidget_Single->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);
	ui.tableWidget_Single->setEditTriggers(QAbstractItemView::NoEditTriggers);
	//ui.tableWidget_Single->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	ui.tableWidget_Single->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive); //������
	ui.tableWidget_Single->horizontalHeader()->setStretchLastSection(true);//���һ�������ؼ�
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
	header << QString::fromLocal8Bit("���۱���\n�ļ���") << QString::fromLocal8Bit("���۱���װ������\n����ƾ֤��");
	header << QString::fromLocal8Bit("  װ������  ") << QString::fromLocal8Bit("װ��(����)\n����") << QString::fromLocal8Bit("  ��װ���  ") << QString::fromLocal8Bit("  ��Ҫ����ȱʧ���  ");
	header << QString::fromLocal8Bit("ǹ�ܺ�") << QString::fromLocal8Bit("ǹ������Ͳ��") << QString::fromLocal8Bit("��ǹ���") << QString::fromLocal8Bit("����ǹ�ܺ�");
	header << QString::fromLocal8Bit("  ������λ  ") << QString::fromLocal8Bit("  ����λ  ") << QString::fromLocal8Bit("  ����ʱ��  ");
	header << QString::fromLocal8Bit("  װ��ʱ��  ") << QString::fromLocal8Bit("����״̬") << QString::fromLocal8Bit("�༭") << QString::fromLocal8Bit("ɾ��");
	ui.tableWidget_Single->setHorizontalHeaderLabels(header);

	//���ռ��ӽ������½ǵ��б�򣬴��������û�õ�
	//m_ListViewModel = new QStandardItemModel();
	//ui.listView->setModel(m_ListViewModel);

	//��Ϣ��ѯ��
	ui.tableWidget_Search->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui.tableWidget_Search->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);
	ui.tableWidget_Search->setEditTriggers(QAbstractItemView::NoEditTriggers);
	//ui.tableWidget_Search->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	ui.tableWidget_Search->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive); //������
	ui.tableWidget_Search->horizontalHeader()->setStretchLastSection(true);//���һ�������ؼ�
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
	header << QString::fromLocal8Bit(" ���۱����ļ��� ") << QString::fromLocal8Bit("���۱���װ������\n����ƾ֤��");
	header << QString::fromLocal8Bit("  װ�䵥��  ") << QString::fromLocal8Bit("  װ������  ") << QString::fromLocal8Bit("  װ��(����)����  ");
	header << QString::fromLocal8Bit("  ��װ���  ") << QString::fromLocal8Bit("  ����ʱ��  ") << QString::fromLocal8Bit("  װ��ʱ��  ");
	header << QString::fromLocal8Bit("  ����״̬  ") << QString::fromLocal8Bit("  ����״̬  ") << QString::fromLocal8Bit("  ���ʱ��  ");
	header << QString::fromLocal8Bit("����ʱ��") << QString::fromLocal8Bit("  ����ʱ��  ") << QString::fromLocal8Bit("ѡ��");
	ui.tableWidget_Search->setHorizontalHeaderLabels(header);

	//�����
	
	ui.tableWidget_Delivery->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui.tableWidget_Delivery->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);
	ui.tableWidget_Delivery->setEditTriggers(QAbstractItemView::NoEditTriggers);
	//ui.tableWidget_Delivery->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	ui.tableWidget_Delivery->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive); //������
	ui.tableWidget_Delivery->horizontalHeader()->setStretchLastSection(true);//���һ�������ؼ�
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
	header << QString::fromLocal8Bit(" ���۱����ļ��� ") << QString::fromLocal8Bit("���۱���װ������\n����ƾ֤��");
	header << QString::fromLocal8Bit("  װ�䵥��  ") << QString::fromLocal8Bit("  װ������  ") << QString::fromLocal8Bit("  װ��(����)����  ") << QString::fromLocal8Bit("  ��װ���  ");
	header << QString::fromLocal8Bit("ǹ�ܺ�") << QString::fromLocal8Bit("ǹ������Ͳ��") << QString::fromLocal8Bit("��ǹ���") << QString::fromLocal8Bit("����ǹ�ܺ�");
	header << QString::fromLocal8Bit("  ����ʱ��  ") << QString::fromLocal8Bit("  װ��ʱ��  ");
	header << QString::fromLocal8Bit("  װ������  ") << QString::fromLocal8Bit("  ���ʱ��  ") << QString::fromLocal8Bit("ѡ��");
	ui.tableWidget_Delivery->setHorizontalHeaderLabels(header);
	//ui.tableWidget_Delivery->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

}

void CSystemMangaer::InitConnections()
{
}

void CSystemMangaer::ReceiveStackWidgetIndex(int index)//������������ť�����źţ�---��ϵͳ������浯��
{
	setWindowState(Qt::WindowMaximized);
	ui.tabWidget->setCurrentIndex(index);//�ര��
	update();
}

void CSystemMangaer::AddUser()//�˺Ź������-�����ϡ��½�����ť--���˲ۺ���
{
	CUserManager::GetInstance()->SetOperatorType(0, QList<QVariant>());//-->���á��û���������
	CUserManager::GetInstance()->exec();
}


void CSystemMangaer::QueryUserInfo()//�˺Ź��������ұߡ���ѯ����ť---���˲ۺ���
{
	QString Name = ui.lineEdit_Name->text();//��ȡ���������
	QString Number = ui.lineEdit_OfficerNumber->text();//��ȡ����ľ���֤��
	QString sql = "select * from GunManager.dbo.UserTable";
	if (!Name.isEmpty() && !Number.isEmpty())//�������������֤�ţ��ͼ���
	{
		sql += QString::fromLocal8Bit(" where ���� like \'%") + Name + QString::fromLocal8Bit("%\' and ����֤�� like \'%") + Number + "%\'";
	}
	else if (!Name.isEmpty())//��������
	{
		sql += QString::fromLocal8Bit(" where ���� like \'%") + Name + "%\'";
	}
	else if (!Number.isEmpty())//���о���֤��
	{
		sql += QString::fromLocal8Bit(" where ����֤�� like \'%") + Number + "%\'";
	}
	m_Password.clear();//ִ����������б����
	QString errMsg;
	QTableData TableData;
	bool rv = CDatabaseOperator::GetInstance()->execSql(sql, TableData, errMsg);
	if (rv)
	{
		//�������
		int r = ui.tableWidget_User->rowCount();
		for (int i = 0; i < r; ++i)
		{
			ui.tableWidget_User->removeRow(0);
		}

		//��������
		ui.tableWidget_User->setRowCount(TableData.size());

		ui.tableWidget_User->setSortingEnabled(false);//�����ͷ�����򣨷񣩣�����������
		
       //�����ͷ����
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
					ui.tableWidget_User->setItem(row, col, item);//Ϊ��Ԫ������Item
				}
				else if (i == 2)
				{
					m_Password.push_back(data);//��������Ԫ��
				}
				else if (i > 2)
				{
					
					if (data == "1")
					{
						item = new QTableWidgetItem(QIcon(":/SysMainWindow/Resources/allow.png"),NULL);//QTableWidgetItem ����洢�˵�Ԫ�����������
						
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
			QPushButton *EditButton = new QPushButton(QString::fromLocal8Bit("�༭"));
			EditButton->setStyleSheet("color:rgb(41,136,41)");
			EditButton->setMinimumHeight(20);
			QPushButton *DeleteButton = new QPushButton(QString::fromLocal8Bit("ɾ��"));
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
		QMessageBox::information(this, QString::fromLocal8Bit("��ѯʧ��"), errMsg);
	}
}

//�༭�û�
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

//ɾ���û�
void CSystemMangaer::DeleteUser()
{
	QPushButton *senderObj = qobject_cast<QPushButton*>(sender());
	if (senderObj == nullptr)
	{
		return;
	}
	int row = ui.tableWidget_User->indexAt(QPoint(senderObj->frameGeometry().x(), senderObj->frameGeometry().y())).row();
	if (QMessageBox::question(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("ȷʵҪɾ����?"), QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes)
	{
		QString name = ui.tableWidget_User->item(row, 0)->text();
		QString number = ui.tableWidget_User->item(row, 1)->text();
		QString sql = "delete from GunManager.dbo.UserTable where " + QString::fromLocal8Bit("���� = \'") + name;
		sql += "\' and " + QString::fromLocal8Bit("����֤�� = \'") + number + "\'";
		QString errMsg;
		bool rv = CDatabaseOperator::GetInstance()->execSql(sql, QTableData(), errMsg);
		if (rv)
		{
			ui.tableWidget_User->removeRow(row);
		}
		else
		{
			QMessageBox::information(this, QString::fromLocal8Bit("ɾ��ʧ��"), errMsg);
		}
	}
}

void CSystemMangaer::AddBoxPacked()//������ӽ���-������װ��⡱��������ϡ��½�����ť--���˲ۺ���
{
	CBoxPacked::GetInstance()->SetOperatorType(0, QList<QVariant>());
	CBoxPacked::GetInstance()->exec();
}

//�޸���װ�����Ϣ
void CSystemMangaer::ModifyBoxPackedInfo()
{
	QPushButton *senderObj = qobject_cast<QPushButton*>(sender());
	if (senderObj == nullptr)
	{
		return;
	}
	int row = ui.tableWidget_Box->indexAt(QPoint(senderObj->frameGeometry().x(), senderObj->frameGeometry().y())).row();
	QList<QVariant> data;
	data.push_back(ui.tableWidget_Box->item(row, 0)->text());  //���۱����ļ���
	data.push_back(ui.tableWidget_Box->item(row, 1)->text());  //����ƾ֤��
	data.push_back(((QToolButton*)ui.tableWidget_Box->cellWidget(row, 2))->text());  //װ�䵥��
	data.push_back(ui.tableWidget_Box->item(row, 3)->text());  //װ������
	data.push_back(ui.tableWidget_Box->item(row, 4)->text());  //װ��������������
	data.push_back(ui.tableWidget_Box->item(row, 5)->text());  //������λ
	data.push_back(ui.tableWidget_Box->item(row, 6)->text());  //����λ
	data.push_back(ui.tableWidget_Box->item(row, 7)->text());  //����ʱ��
	data.push_back(ui.tableWidget_Box->item(row, 8)->text());  //װ��ʱ��
	data.push_back(ui.tableWidget_Box->item(row, 9)->text());  //װ������
	CBoxPacked::GetInstance()->SetOperatorType(1, data);
	CBoxPacked::GetInstance()->exec();
}

//ɾ����װ��Ϣ
void CSystemMangaer::DeleteBoxPackedInfo()
{
	QPushButton *senderObj = qobject_cast<QPushButton*>(sender());
	if (senderObj == nullptr)
	{
		return;
	}
	//int row = senderObj->objectName().toInt();
	int row = ui.tableWidget_Box->indexAt(QPoint(senderObj->frameGeometry().x(), senderObj->frameGeometry().y())).row();
	if (QMessageBox::question(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("ȷʵҪɾ����?"), QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes)
	{
		QString WenJianHao = ui.tableWidget_Box->item(row, 0)->text();
		QString PingZhengHao = ui.tableWidget_Box->item(row, 1)->text();
		QToolButton *button = (QToolButton*)ui.tableWidget_Box->cellWidget(row, 2);
		QString DanHao = button->text();
		QString sql = "delete from GunManager.dbo.BoxPackedTable where " + QString::fromLocal8Bit("���۱����ļ��� = \'") + WenJianHao + "\'";
		sql += QString::fromLocal8Bit(" and ����ƾ֤�� = \'") + PingZhengHao + "\'";
		sql += QString::fromLocal8Bit(" and װ�䵥�� = \'") + DanHao + "\'";
		QString errMsg;
		QTableData TableData;
		bool rv = CDatabaseOperator::GetInstance()->execSql(sql, TableData, errMsg);
		if (!rv)
		{
			QMessageBox::information(this, QString::fromLocal8Bit("��װ��Ϣɾ������"), errMsg);
		}
		else
		{
			sql = "delete from GunManager.dbo.BoxPackedDetailsTable where " + QString::fromLocal8Bit("װ�䵥�� = \'") + DanHao + "\'";
			//sql+= QString::fromLocal8Bit(" and ��� = \'") + PingZhengHao + "\'";
			//
			rv = CDatabaseOperator::GetInstance()->execSql(sql, TableData, errMsg);
			if (rv)
			{
				ui.tableWidget_Box->removeRow(row);
			}
			else
			{
				QMessageBox::information(this, QString::fromLocal8Bit("��װ�б�ɾ������"), errMsg);
			}
		}

	}
}


void CSystemMangaer::QueryBoxPacked()//������ӽ���->����װ��⡱���棬�ұߡ���ѯ����ť�������˲ۺ���
{
	QString errMsg;
	QTableData TableData;
	QString WenJianHao = ui.lineEdit_WenJianHao->text();//��ȡ�ļ���
	QString PingZhengHao = ui.lineEdit_PingZhengHao->text();//��ȡƾ֤��
	QString DanHao = ui.lineEdit_ZhuangXiangDanHao->text();//��ȡװ�䵥��
	QString ChuChangRiQi = ui.dateEdit_BoxCC->dateTime().toString("yyyy-M-d");//��ȡ��������
	QString ZhuangBeiRiQi = ui.dateEdit_BoxZB->dateTime().toString("yyyy-M-d");//��ȡװ������
	//�������ݿ�
	QString sql = "select * from GunManager.dbo.BoxPackedTable where";
	sql += QString::fromLocal8Bit(" ���۱����ļ��� like \'%") + WenJianHao + "%\'";
	sql += QString::fromLocal8Bit(" and ����ƾ֤�� like \'%") + PingZhengHao + "%\'";
	sql += QString::fromLocal8Bit(" and װ�䵥�� like \'%") + DanHao + "%\'";
	if (ChuChangRiQi != "1900-1-1")
	{
		sql += QString::fromLocal8Bit("and ����ʱ�� = \'") + ChuChangRiQi + "\'";
	}
	if (ZhuangBeiRiQi != "1900-1-1")
	{
		sql += QString::fromLocal8Bit("and װ��ʱ�� = \'") + ZhuangBeiRiQi + "\'";
	}
	bool rv = CDatabaseOperator::GetInstance()->execSql(sql, TableData, errMsg);
	if (!rv)
	{
		QMessageBox::information(this, QString::fromLocal8Bit("��ѯ����"), errMsg);
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
					QString sql = "select * from GunManager.dbo.BoxPackedDetailsTable where " + QString::fromLocal8Bit("װ�䵥�� = \'") + DanHao + "\'";
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
			QPushButton *EditButton = new QPushButton(QString::fromLocal8Bit("�༭"));
			EditButton->setStyleSheet("color:rgb(41,136,41)");
			EditButton->setMinimumHeight(20);
			QPushButton *DeleteButton = new QPushButton(QString::fromLocal8Bit("ɾ��"));
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


//���װ�䵥��,������װ���Ž��棬����������װ�б�,Ȼ����б༭��ɾ������
void CSystemMangaer::slotClickToolButton()
{
	QToolButton *senderObj = qobject_cast<QToolButton*>(sender());//�����ź���Դ�Ķ���
	if (senderObj == nullptr)
	{
		return;
	}
	QString text = senderObj->text();
	QString sql = "select * from GunManager.dbo.BoxPackedDetailsTable where " + QString::fromLocal8Bit("װ�䵥�� = \'") + text + "\'";
	QTableData TableData;
	QString errMsg;
	bool rv = CDatabaseOperator::GetInstance()->execSql(sql, TableData, errMsg);
	if (rv)
	{
		if (TableData.size() > 0)
		{
			ui.tabWidget->setCurrentIndex(3);
			int rows = ui.tableWidget_PackedInfo->rowCount();//�������
			for (int i = 0; i < rows; ++i)
			{
				ui.tableWidget_PackedInfo->removeRow(rows);//ɾ����
			}
			ui.tableWidget_PackedInfo->setRowCount(TableData.size());//����
			ui.tableWidget_PackedInfo->setSortingEnabled(false);//����Ϊ�����Զ�����

			for (int row = 0; row < TableData.size(); ++row)
			{
				QList<QVariant> RowData = TableData.at(row);//ÿһ�������м���
				int col = 1;
				for (; col < RowData.size() - 1; ++col)
				{
					QString data = RowData.at(col).toString();
					QTableWidgetItem *item = new QTableWidgetItem(data);
					item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
					ui.tableWidget_PackedInfo->setItem(row, col - 1, item);
				}
				QPushButton *EditButton = new QPushButton(QString::fromLocal8Bit("�༭"));
				EditButton->setStyleSheet("color:rgb(41,136,41)");
				EditButton->setMinimumHeight(20);
				QPushButton *DeleteButton = new QPushButton(QString::fromLocal8Bit("ɾ��"));
				DeleteButton->setStyleSheet("color:rgb(255,0,0)");
				DeleteButton->setMinimumHeight(20);
				//ui.tableWidget_PackedInfo->setCellWidget(row, col - 1, EditButton);
				//ui.tableWidget_PackedInfo->setCellWidget(row, col, DeleteButton);
				ui.tableWidget_PackedInfo->setCellWidget(row, col - 3, EditButton);
				ui.tableWidget_PackedInfo->setCellWidget(row, col-2, DeleteButton);
				connect(EditButton, SIGNAL(clicked()), this, SLOT(EditPackedListInfo()));
				connect(DeleteButton, SIGNAL(clicked()), this, SLOT(DeletePackedListInfo()));
			}
			ui.tableWidget_PackedInfo->setSortingEnabled(true);//�����Զ�����
			ui.tableWidget_PackedInfo->sortByColumn(0, Qt::AscendingOrder);//��������ģʽ
		}
		else
		{
			return;
		}
	}
	else
	{
		QMessageBox::information(this, QString::fromLocal8Bit("��ѯ��װ�б�ʧ��"), errMsg);
	}
}

void CSystemMangaer::BoxDetailsReturn()//װ����Ϣ���� - �����¡����ء���ť--���˲ۺ���
{
	ui.tabWidget->setCurrentIndex(1);
}

//�༭����װ�б�,ǹ֧����ȱʧ�����OCRʶ�����ȣ����ռ��ӽ����£�
void CSystemMangaer::EditPackedListInfo()
{
	QPushButton *senderObj = qobject_cast<QPushButton*>(sender());
	if (senderObj == nullptr)
	{
		return;
	}

	int row = ui.tableWidget_PackedInfo->indexAt(QPoint(senderObj->frameGeometry().x(), senderObj->frameGeometry().y())).row();//��

	QString DanHao = ui.tableWidget_PackedInfo->item(row, 0)->text();//��ȡ��װ�б�ĵ�һ��Ϊ��װ����
	ui.label_DanHao->setText(DanHao);
	ui.lineEdit_Ocr->setText("");//ͼ��ʶ��༭��
	ui.lineEdit_XiuZheng->setText("");//�˹������༭��
	ui.checkBox_QiangGuan->setEnabled(true); //�ɱ༭�����ť�����Դ����¼�
	ui.checkBox_QiangJi->setEnabled(true);
	ui.checkBox_QiangKuang->setEnabled(true);
	ui.checkBox_BeiFen->setEnabled(true);
	ui.checkBox_QiangGuan->setChecked(true);//��ʼĬ�ϸ�ѡ��Ϊѡ��״̬
	ui.checkBox_QiangJi->setChecked(true);
	ui.checkBox_QiangKuang->setChecked(true);
	ui.checkBox_BeiFen->setChecked(true);
	
	//4��ǹ֧�������
	ui.lineEdit_QiangGuan->setText("");//��ʼֵΪ��
	ui.lineEdit_QiangJi->setText("");
	ui.lineEdit_QiangKuang->setText("");
	ui.lineEdit_BeiFen->setText("");

	//m_ListViewModel->removeRows(0, m_ListViewModel->rowCount());
	m_CurDZBianHao.clear();//��װ���
	m_QSQingKuang.clear();//ȱʧ���
	m_curMsg.clear();//��յ�ǰ��Ϣ
	m_curMsg.type = 1;//1Ϊ��װ
	m_curMsg.index = row+1;//���ݿ��-BoxPackedDetailsTable-���
	m_curMsg.PackedNum = DanHao;//���ݿ��- BoxPackedDetailsTable-װ�䵥��
	ui.tabWidget->setCurrentIndex(4);//��4tab
	m_PreviousIndex = 1; //1����װ��Ϣ��
}

//ɾ����װ�б�
void CSystemMangaer::DeletePackedListInfo()
{
	QPushButton *senderObj = qobject_cast<QPushButton*>(sender());
	if (senderObj == nullptr)
	{
		return;
	}
	//int row = senderObj->objectName().toInt();
	int row = ui.tableWidget_PackedInfo->indexAt(QPoint(senderObj->frameGeometry().x(), senderObj->frameGeometry().y())).row();
	
	if (QMessageBox::question(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("ȷʵҪɾ����?"), QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes)
	{
		m_curMsg.index = row+1;
		QString DanHao = ui.tableWidget_PackedInfo->item(row, 0)->text();
		QString BianHao = ui.tableWidget_PackedInfo->item(row, 3)->text();
		//QMessageBox::information(this, "check", QString::fromLocal8Bit("����4��ɶ ") + BianHao);
		QString sql = "delete from GunManager.dbo.BoxPackedDetailsTable where " + QString::fromLocal8Bit("��� = \'") + QString::number(m_curMsg.index) + "\'"; 
		sql += QString::fromLocal8Bit(" and װ�䵥�� = \'") + DanHao + "\'";
		sql += QString::fromLocal8Bit(" and װ�䵥�� = \'") + DanHao + "\'";
		sql += QString::fromLocal8Bit(" and ��װ��� = \'") + BianHao + "\'";
		//QMessageBox::information(this, "check", QString::fromLocal8Bit("����4��ɶ ") + sql);
		//QMessageBox::information(this, "check", QString::fromLocal8Bit("ȷ��ɾ����Ϊ ") + QString::number(m_curMsg.index));
		

		QString errMsg;
		QTableData TableData;
		bool rv = CDatabaseOperator::GetInstance()->execSql(sql, TableData, errMsg);
		if (!rv)
		{
			QMessageBox::information(this, QString::fromLocal8Bit("��װ�б�ɾ������"), errMsg);
		}
		else
		{
			ui.tableWidget_PackedInfo->removeRow(row);
		}
	}
}


void CSystemMangaer::PrintBoxList()//װ����Ϣ��������½ǵ�"��ӡװ���嵥"��ť----���˲ۺ���
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
		oneRow.push_back(QString::fromLocal8Bit("֧"));
		oneRow.push_back("1");
		content.push_back(oneRow);
	}
	PrintAPI::Instance()->PrintGridA2(content);
}

void CSystemMangaer::AddSinglePacked()//������ӽ���-������װ��⡱��������ϡ��½�����ť--���˲ۺ���
{
	CSinglePacked::GetInstance()->exec();
}


//�༭��������ӡ�--��װ���--���༭--������ѡ���Ȩ�ޣ����ռ����£�
void CSystemMangaer::EditSinglePacked()
{
	QPushButton *senderObj = qobject_cast<QPushButton*>(sender());
	if (senderObj == nullptr)
	{
		return;
	}
	int row = ui.tableWidget_Single->indexAt(QPoint(senderObj->frameGeometry().x(), senderObj->frameGeometry().y())).row();
	ui.label_DanHao->setText("");//��װ û����װ����  ��Ϊ��
	ui.lineEdit_Ocr->setText("");
	ui.lineEdit_XiuZheng->setText("");

	//ui.checkBox_QiangGuan->setEnabled(false);//���ɴ���
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
	
	//4��ǹ֧����
	ui.lineEdit_QiangGuan->setText("");
	ui.lineEdit_QiangJi->setText("");
	ui.lineEdit_QiangKuang->setText("");
	ui.lineEdit_BeiFen->setText("");


	m_CurDZBianHao.clear();//��װ������
	m_curMsg.clear();//��յ�ǰ��Ϣ
	m_curMsg.index = row;//���ݿ��-SinglePackedTable-���,ע��:(0----)
	m_curMsg.type = 2;//2Ϊ��װ
	m_curMsg.BFWenJianHao = ui.tableWidget_Single->item(row, 0)->text();//���ݿ�� - SinglePackedTableȡ��1���ļ���
	m_curMsg.DBPingZhengHao = ui.tableWidget_Single->item(row, 1)->text();//���ݿ�� - SinglePackedTableȡ��2��ƾ֤��
	m_curMsg.ZBDaiMa = ui.tableWidget_Single->item(row, 2)->text();//���ݿ�� - SinglePackedTableȡ��3�� װ������
	ui.tabWidget->setCurrentIndex(4);
	m_PreviousIndex = 2;
}

//ɾ����װ��Ϣ
void CSystemMangaer::DeleteSinglePacked()
{
	QPushButton *senderObj = qobject_cast<QPushButton*>(sender());
	if (senderObj == nullptr)
	{
		return;
	}
	//int row = senderObj->objectName().toInt();
	int row = ui.tableWidget_Single->indexAt(QPoint(senderObj->frameGeometry().x(), senderObj->frameGeometry().y())).row();
	if (QMessageBox::question(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("ȷʵҪɾ����?"), QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes)
	{
		QString WenJianHao = ui.tableWidget_Single->item(row, 0)->text();
		QString PingZhengHao = ui.tableWidget_Single->item(row, 1)->text();
		QString DaiMa = ui.tableWidget_Single->item(row, 2)->text();
		QString sql = "delete from GunManager.dbo.SinglePackedTable where " + QString::fromLocal8Bit("���۱����ļ��� = \'") + WenJianHao + "\'";
		sql += QString::fromLocal8Bit(" and ����ƾ֤�� = \'") + PingZhengHao + "\'";
		sql += QString::fromLocal8Bit(" and װ������ = \'") + DaiMa + "\'";
		QString errMsg;
		QTableData TableData;
		bool rv = CDatabaseOperator::GetInstance()->execSql(sql, TableData, errMsg);
		if (!rv)
		{
			QMessageBox::information(this, QString::fromLocal8Bit("��װ��Ϣɾ������"), errMsg);
		}
		else
		{
			ui.tableWidget_Single->removeRow(row);
		}
	}
}

void CSystemMangaer::QuerySinglePacked()//��������ӡ������£���װ���������ұ�"��ѯ"��ť--���˲ۺ���
{
	QString WenJianHao = ui.lineEdit_SingleWJH->text();
	QString PingZhengHao = ui.lineEdit_SinglePZH->text();
	QString DaiMa = ui.lineEdit_SingleDM->text();
	QString ChuChangRiQi = ui.dateEdit_SingleCC->dateTime().toString("yyyy-M-d");
	QString ZhuangBeiRiQi = ui.dateEdit_SingleZB->dateTime().toString("yyyy-M-d");
	QString sql = "select * from GunManager.dbo.SinglePackedTable where";
	sql += QString::fromLocal8Bit(" ���۱����ļ��� like \'%") + WenJianHao + "%\'";
	sql += QString::fromLocal8Bit(" and ����ƾ֤�� like \'%") + PingZhengHao + "%\'";
	sql += QString::fromLocal8Bit(" and װ������ like \'%") + DaiMa + "%\'";
	if (ChuChangRiQi != "1900-1-1")
	{
		sql += QString::fromLocal8Bit("and ����ʱ�� = \'") + ChuChangRiQi + "\'";
	}
	if (ZhuangBeiRiQi != "1900-1-1")
	{
		sql += QString::fromLocal8Bit("and װ��ʱ�� = \'") + ZhuangBeiRiQi + "\'";
	}
	QTableData TableData;
	QString errMsg;
	bool rv = CDatabaseOperator::GetInstance()->execSql(sql, TableData, errMsg);
	if (!rv)
	{
		QMessageBox::information(this, QString::fromLocal8Bit("��ѯ����"), errMsg);
	}
	else if (TableData.size() == 0)
	{
		QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("���޴˼�¼"));
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
			QPushButton *EditButton = new QPushButton(QString::fromLocal8Bit("�༭"));
			EditButton->setStyleSheet("color:rgb(41,136,41)");
			EditButton->setMinimumHeight(20);
			QPushButton *DeleteButton = new QPushButton(QString::fromLocal8Bit("ɾ��"));
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

void CSystemMangaer::PrintSinglePacked()//������ӽ���->"��װ���"����,���½ǡ���ӡ��װ��Ƭ����ť--���˲ۺ���
{
	// ������ӡ������
	int row = ui.tableWidget_Single->currentRow();
	if (row < 0)
	{
		QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("��ѡ��Ҫ��ӡ������"));
		return;
	}

	QStringList content;
	content.push_back(ui.tableWidget_Single->item(row, 0)->text());//���۱����ļ���
	content.push_back(ui.tableWidget_Single->item(row, 1)->text());//����ƾ֤��
	content.push_back(ui.tableWidget_Single->item(row, 2)->text());//װ������
	content.push_back(ui.tableWidget_Single->item(row, 3)->text());//װ������
	content.push_back(ui.tableWidget_Single->item(row, 4)->text());//��װ���
	//content.push_back(ui.tableWidget_Single->item(row, 5)->text());//��Ҫ����ȱʧ���
	content.push_back(ui.tableWidget_Single->item(row, 10)->text());//������λ
	content.push_back(ui.tableWidget_Single->item(row, 11)->text());//����λ
	content.push_back(ui.tableWidget_Single->item(row, 12)->text());//����ʱ��
	content.push_back(ui.tableWidget_Single->item(row, 13)->text());//װ��ʱ��

	PrintAPI::Instance()->PrintGridA3(content);
}


void CSystemMangaer::QueryInformations()//��Ϣ�������->����ѯ���������ұߵ�"��ѯ"��ť---���˲ۺ���
{
	//select t1.���۱����ļ���,t1.����ƾ֤��,t1.װ�䵥��,t1.װ������,t1.װ������,t2.��װ���,t1.����ʱ��,t1.װ��ʱ��,t1.�Ѽ��� as ״̬,t2.��¼ʱ��
	//from BoxPackedTable t1 right join BoxPackedDetailsTable t2 on t1.װ�䵥�� = t2.װ�䵥�� and t1.װ������ = t2.װ������ and t1.װ������ = t2.װ������

	QString sql = QString::fromLocal8Bit("select t1.���۱����ļ���,t1.����ƾ֤��,t1.װ�䵥��,t1.װ������,t1.װ������,t2.��װ���,t1.����ʱ��,t1.װ��ʱ��,t2.����״̬,t2.���ʱ��,t2.����ʱ��,t2.����ʱ��");
	sql += " from GunManager.dbo.BoxPackedTable t1 right join GunManager.dbo.BoxPackedDetailsTable t2 on";
	sql += QString::fromLocal8Bit(" t1.װ�䵥�� = t2.װ�䵥�� and t1.װ������ = t2.װ������ and t1.װ������ = t2.װ������");
	sql += " where " + QString::fromLocal8Bit("t1.���۱����ļ��� like \'%") + ui.lineEdit_BFWenJianHao->text() + "%\'";
	sql += " and " + QString::fromLocal8Bit("t1.����ƾ֤�� like \'%") + ui.lineEdit_DBPingZhengHao->text() + "%\'";
	sql += " and " + QString::fromLocal8Bit("t1.װ�䵥�� like \'%") + ui.lineEdit_XZDanHao->text() + "%\'";
	sql += " and " + QString::fromLocal8Bit("t1.װ������ like \'%") + ui.lineEdit_ZBDaima->text() + "%\'";
	sql += " and " + QString::fromLocal8Bit("t1.װ������ like \'%") + ui.lineEdit_ZBMingCheng->text() + "%\'";
	sql += " and " + QString::fromLocal8Bit("t2.��װ��� like \'%") + ui.lineEdit_DZBianHao->text() + "%\'";//��ӵĵ�װ��Ų�ѯ
	QString RuKuRiQi = ui.dateEdit_InfoRK->dateTime().toString("yyyy-M-d");
	QString RuKuRiQi_end = ui.dateEdit_InfoRK_end->dateTime().toString("yyyy-M-d");
	QString ChuKuRiQi = ui.dateEdit_InfoCK->dateTime().toString("yyyy-M-d");
	QString ChuKuRiQi_end = ui.dateEdit_InfoCK_end->dateTime().toString("yyyy-M-d");
	QString JianShiRiqQi = ui.dateEdit_InfoJS->dateTime().toString("yyyy-M-d");
	QString JianShiRiqQi_end = ui.dateEdit_InfoJS_end->dateTime().toString("yyyy-M-d");


	//sql += " and " + QString::fromLocal8Bit("t2.���ʱ�� BETWEEN \'1995-9-5\' AND \'1995-9-7\' and t2.����ʱ�� BETWEEN \'1995-12-12\' AND \'1996-9-7\'");
	//sql += " and " + QString::fromLocal8Bit("t2.���ʱ�� BETWEEN \'")+ RuKuRiQi+"\' AND \'2025-9-7\'");
	//sql += " and " + QString::fromLocal8Bit("t2.���ʱ�� BETWEEN \'1995-9-5\' AND \'2025-9-7\'");
	//sql += " and " + QString::fromLocal8Bit("t2.���ʱ�� BETWEEN \'") + RuKuRiQi + "\' AND \'" + RuKuRiQi_end + "\'";
	//sql += " and " + QString::fromLocal8Bit("t2.���ʱ�� BETWEEN \'") + RuKuRiQi + "\' AND \'" + RuKuRiQi_end + "\'";
	//sql += " and " + QString::fromLocal8Bit("t2.����ʱ�� BETWEEN \'") + ChuKuRiQi + "\' AND \'" + ChuKuRiQi_end + "\'";
	//if (RuKuRiQi != "1900-1-1"&& RuKuRiQi_end != "1900-1-1")
	//{
	//	sql += " and " + QString::fromLocal8Bit("t2.���ʱ�� = \'") + RuKuRiQi + "\'";
	//}
	//if (ChuKuRiQi != "1900-1-1")
	//{
	//	sql += " and " + QString::fromLocal8Bit("t2.����ʱ�� = \'") + ChuKuRiQi + "\'";
	//}

	if (RuKuRiQi != "1900-1-1"&& RuKuRiQi_end != "1900-1-1")
	{
		sql += " and " + QString::fromLocal8Bit("t2.���ʱ�� BETWEEN \'") + RuKuRiQi + "\' AND \'" + RuKuRiQi_end + "\'";
	}

	if (JianShiRiqQi != "1900-1-1" && JianShiRiqQi_end != "1900-1-1")
	{
		sql += " and " + QString::fromLocal8Bit("t2.����ʱ�� BETWEEN \'") + JianShiRiqQi + "\'AND \'" + JianShiRiqQi_end + "\'";
	}

	if (ChuKuRiQi != "1900-1-1" && ChuKuRiQi_end != "1900-1-1")
	{
		sql += " and " + QString::fromLocal8Bit("t2.����ʱ�� BETWEEN \'") + ChuKuRiQi + "\' AND \'" + ChuKuRiQi_end + "\'";
	}

	QTableData PackedTableData;
	QTableData SingleTableData;
	QString errMsg;
	bool rv = CDatabaseOperator::GetInstance()->execSql(sql, PackedTableData, errMsg);
	if (!rv)
	{
		QMessageBox::information(this, QString::fromLocal8Bit("��װ��Ϣ��ѯʧ��"), errMsg);
		return;
	}

	sql.clear();
	sql = QString::fromLocal8Bit("select ���۱����ļ���,����ƾ֤��,\'-\' as ��װ����,װ������,װ������,��װ���,����ʱ��,װ��ʱ��,����״̬,���ʱ��,����ʱ��,����ʱ�� from GunManager.dbo.SinglePackedTable");
	sql += " where " + QString::fromLocal8Bit("���۱����ļ��� like \'%") + ui.lineEdit_BFWenJianHao->text() + "%\'";
	sql += " and " + QString::fromLocal8Bit("����ƾ֤�� like \'%") + ui.lineEdit_DBPingZhengHao->text() + "%\'";
	sql += " and " + QString::fromLocal8Bit("װ������ like \'%") + ui.lineEdit_ZBDaima->text() + "%\'";
	sql += " and " + QString::fromLocal8Bit("װ������ like \'%") + ui.lineEdit_ZBMingCheng->text() + "%\'";
	sql += " and " + QString::fromLocal8Bit("��װ��� like \'%") + ui.lineEdit_DZBianHao->text() + "%\'";//��ӵĵ�װ��Ų�ѯ
	
	//sql += " and " + QString::fromLocal8Bit("t2.���ʱ�� BETWEEN \'1995-9-5\' AND \'1995-9-7\' and t2.����ʱ�� BETWEEN \'1995-12-12\' AND \'1996-9-7\'");
	//sql += " and " + QString::fromLocal8Bit("���ʱ�� BETWEEN \'1995-09-05\' AND \'1998-09-07\'");
	//sql += " and " + QString::fromLocal8Bit("���ʱ�� BETWEEN \'") + RuKuRiQi + "\' AND \'" + RuKuRiQi_end + "\'";


	//if (RuKuRiQi != "1900-01-01")
	//{
	//	sql += " and " + QString::fromLocal8Bit("���ʱ�� = \'") + RuKuRiQi + "\'";
	//	
	//}
	//if (ChuKuRiQi != "1900-01-01")
	//{
	//	sql += " and " + QString::fromLocal8Bit("����ʱ�� = \'") + ChuKuRiQi + "\'";
	//}

	if (RuKuRiQi != "1900-1-1" && RuKuRiQi_end != "1900-1-1")
	{
		
		sql += " and " + QString::fromLocal8Bit("���ʱ�� BETWEEN \'") + RuKuRiQi + "\' AND \'" + RuKuRiQi_end + "\'";
	}

	if (JianShiRiqQi != "1900-1-1" && JianShiRiqQi_end != "1900-1-1")
	{
		sql += " and " + QString::fromLocal8Bit("����ʱ�� BETWEEN \'") + JianShiRiqQi + "\'AND \'" + JianShiRiqQi_end + "\'";
	}

	if (ChuKuRiQi != "1900-1-1" && ChuKuRiQi_end != "1900-1-1")
	{
		sql += " and " + QString::fromLocal8Bit("����ʱ�� BETWEEN \'") + ChuKuRiQi + "\'AND \'" + ChuKuRiQi_end + "\'";
	}


	rv = CDatabaseOperator::GetInstance()->execSql(sql, SingleTableData, errMsg);
	if (!rv)
	{
		QMessageBox::information(this, QString::fromLocal8Bit("��װ��Ϣ��ѯʧ��"), errMsg);
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
		//����״̬
		QTableWidgetItem *item = new QTableWidgetItem(bChecked?QString::fromLocal8Bit("�Ѽ���"): QString::fromLocal8Bit("δ����"));
		item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
		ui.tableWidget_Search->setItem(row, col, item);

		//����״̬
		QString data = RowData.at(col).toString();
		item = new QTableWidgetItem(data);
		item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
		ui.tableWidget_Search->setItem(row, col+1, item);
		//ui.tableWidget_Search->setItem(row, col, item);
		

		//���ʱ��
		data = RowData.at(col + 1).toString();
		data = data.replace("T", " ");
		item = new QTableWidgetItem(data);
		item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);//������־���
		ui.tableWidget_Search->setItem(row, col + 2, item);

		//����ʱ��
		data = RowData.at(col + 2).toString();
		data = data.replace("T", " ");
		item = new QTableWidgetItem(data);
		item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);//������־���
		//ui.tableWidget_Search->setItem(row, col+2, item);
		ui.tableWidget_Search->setItem(row, col + 3, item);

		//����ʱ��
		data = RowData.at(col + 3).toString();
		data = data.replace("T", " ");
		item = new QTableWidgetItem(data);
		item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);//������־���
		ui.tableWidget_Search->setItem(row, col + 4, item);

		//��ѡ��
		//QCheckBox *checkBox = new QCheckBox(QString::fromLocal8Bit("��ѡ"));
		//ui.tableWidget_Search->setCellWidget(row, col+5, checkBox);
		QCheckBox *checkBox = new QCheckBox(QString::fromLocal8Bit("��ѡ"));
		QHBoxLayout *hLayout = new QHBoxLayout();
		QWidget *widget = new QWidget(ui.tableWidget_Search);
		hLayout->addWidget(checkBox);
		hLayout->setMargin(0);                          // �������, ����CheckBox����������ʾ
		hLayout->setAlignment(checkBox, Qt::AlignCenter);
		widget->setLayout(hLayout);
		ui.tableWidget_Search->setCellWidget(row, col + 5, widget);
	}
	ui.tableWidget_Search->setSortingEnabled(true);
	ui.tableWidget_Search->sortByColumn(0, Qt::AscendingOrder);
	
}


void CSystemMangaer::QueryDeliveryInformations()//��Ϣ�������->�����⡱�������ұߵ�"��ѯ"��ť---���˲ۺ���
{

	QString sql = QString::fromLocal8Bit("select t1.���۱����ļ���,t1.����ƾ֤��,t1.װ�䵥��,t1.װ������,t1.װ������,t2.��װ���,t2.ǹ�ܺ�,t2.ǹ������Ͳ��,t2.��ǹ���,t2.����ǹ�ܺ�,t1.����ʱ��,t1.װ��ʱ��,t1.װ������,t2.���ʱ��");
	sql += " from GunManager.dbo.BoxPackedTable t1 right join GunManager.dbo.BoxPackedDetailsTable t2 on";
	sql += QString::fromLocal8Bit(" t1.װ�䵥�� = t2.װ�䵥�� and t1.װ������ = t2.װ������ and t1.װ������ = t2.װ������");
	sql += " where " + QString::fromLocal8Bit("t1.���۱����ļ��� like \'%") + ui.lineEdit_DeliveryBFWenJianHao->text() + "%\'";
	sql += " and " + QString::fromLocal8Bit("t1.����ƾ֤�� like \'%") + ui.lineEdit_DeliveryDBPingZhengHao->text() + "%\'";
	sql += " and " + QString::fromLocal8Bit("t1.װ�䵥�� like \'%") + ui.lineEdit_DeliveryXZDanHao->text() + "%\'";
	sql += " and " + QString::fromLocal8Bit("t1.װ������ like \'%") + ui.lineEdit_DeliveryZBDaima->text() + "%\'";
	sql += " and " + QString::fromLocal8Bit("t1.װ������ like \'%") + ui.lineEdit_DeliveryZBMingCheng->text() + "%\'";
	sql += " and " + QString::fromLocal8Bit("t2.��װ��� != \'\'");
	sql += " and " + QString::fromLocal8Bit("t2.����״̬ = \'δ����\'");
	QString DeliveryCC = ui.dateEdit_DeliveryCC->dateTime().toString("yyyy-M-d");
	if (DeliveryCC != "1900-1-1")
	{
		sql += " and " + QString::fromLocal8Bit("t1.����ʱ�� = \'") + DeliveryCC + "\'";
	}
	QString DeliveryZB = ui.dateEdit_DeliveryZB->dateTime().toString("yyyy-M-d");
	if (DeliveryZB != "1900-1-1")
	{
		sql += " and " + QString::fromLocal8Bit("t1.װ��ʱ�� = \'") + DeliveryZB + "\'";
	}

	QTableData PackedTableData;
	QTableData SingleTableData;
	QString errMsg;
	bool rv = CDatabaseOperator::GetInstance()->execSql(sql, PackedTableData, errMsg);
	if (!rv)
	{
		QMessageBox::information(this, QString::fromLocal8Bit("��װ��Ϣ��ѯʧ��"), errMsg);
		return;
	}

	sql.clear();
	sql = QString::fromLocal8Bit("select ���۱����ļ���,����ƾ֤��,\'-\' as ��װ����,װ������,װ������,��װ���,ǹ�ܺ�,ǹ������Ͳ��,��ǹ���,����ǹ�ܺ�,����ʱ��,װ��ʱ��,\'-\' as ��װ����,���ʱ�� from GunManager.dbo.SinglePackedTable");
	sql += " where " + QString::fromLocal8Bit("���۱����ļ��� like \'%") + ui.lineEdit_DeliveryBFWenJianHao->text() + "%\'";
	sql += " and " + QString::fromLocal8Bit("����ƾ֤�� like \'%") + ui.lineEdit_DeliveryDBPingZhengHao->text() + "%\'";
	sql += " and " + QString::fromLocal8Bit("װ������ like \'%") + ui.lineEdit_DeliveryZBDaima->text() + "%\'";
	sql += " and " + QString::fromLocal8Bit("װ������ like \'%") + ui.lineEdit_DeliveryZBMingCheng->text() + "%\'";
	sql += " and " + QString::fromLocal8Bit("��װ��� != \'\'");
	sql += " and " + QString::fromLocal8Bit("����״̬ = \'δ����\'");
	if (DeliveryCC != "1900-1-1")
	{
		sql += " and " + QString::fromLocal8Bit("����ʱ�� = \'") + DeliveryCC + "\'";
	}
	if (DeliveryZB != "1900-1-1")
	{
		sql += " and " + QString::fromLocal8Bit("װ��ʱ�� = \'") + DeliveryZB + "\'";
	}

	rv = CDatabaseOperator::GetInstance()->execSql(sql, SingleTableData, errMsg);
	if (!rv)
	{
		QMessageBox::information(this, QString::fromLocal8Bit("��װ��Ϣ��ѯʧ��"), errMsg);
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
		//���ʱ��
		QString data = RowData.at(col).toString();
		data = data.replace("T", " ");
		QTableWidgetItem *item = new QTableWidgetItem(data);
		item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
		ui.tableWidget_Delivery->setItem(row, col++, item);

		//��ѡ��
		/*QCheckBox *checkBox = new QCheckBox(QString::fromLocal8Bit("��ѡ"));
		ui.tableWidget_Delivery->setCellWidget(row, col, checkBox);*/
		  //��QtableWidget�����QCheckBox��ʹ�������ʾ
		QCheckBox *checkBox = new QCheckBox(QString::fromLocal8Bit("��ѡ"));
		QHBoxLayout *hLayout = new QHBoxLayout();
		QWidget *widget = new QWidget(ui.tableWidget_Delivery);
		hLayout->addWidget(checkBox);
		hLayout->setMargin(0);                          // �������, ����CheckBox����������ʾ
		hLayout->setAlignment(checkBox, Qt::AlignCenter);
		widget->setLayout(hLayout);
		ui.tableWidget_Delivery->setCellWidget(row, col, widget);//row��col ��Ԫ����
	}
	ui.tableWidget_Delivery->setSortingEnabled(true);
	ui.tableWidget_Delivery->sortByColumn(0, Qt::AscendingOrder);
	//Remainder();
}

  
void CSystemMangaer::DoDelivery()//��Ϣ�������-�������⡱��������ϡ����⡱��ť-----���˲ۺ���
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
			QString DBPingZhengHao = ui.tableWidget_Delivery->item(i, 1)->text();//ƾ֤��
			QString ZBDaiMa = ui.tableWidget_Delivery->item(i, 3)->text();//װ������
			QString ZBMingCheng = ui.tableWidget_Delivery->item(i, 4)->text();//װ������
			QString DZBianHao = ui.tableWidget_Delivery->item(i, 5)->text();//��װ���
			QString ZXDanHao = ui.tableWidget_Delivery->item(i, 2)->text();  //װ�䵥��
			//װ�䵥��Ϊ"-",��Ϊ��װ��⣬����װ�����д˼�¼�޸�Ϊ"�ѳ���"
			//װ�䵥����ֵ����Ϊ��װ��⣬����װ�����Ϣ���м�¼�޸�Ϊ"�ѳ���"

			//����ʱ��
			/*QDateTime curDateTime = QDateTime::currentDateTime();
			QString ChuKuDateTime = curDateTime.toString("yyyy-MM-dd hh:mm:ss");*/

			QDateTime curDateTime = QDateTime::currentDateTime();
			QString ChuKuDateTime = curDateTime.toString("yyyy-M-d");
			if (ZXDanHao == "-")//��װ���
			{
				sql = QString::fromLocal8Bit("update GunManager.dbo.SinglePackedTable set ����״̬ = '�ѳ���',����ʱ��= \'")+ChuKuDateTime+"\' where";
				sql += QString::fromLocal8Bit(" ���۱����ļ��� = ") + "\'" + BFWenJianHao +"\'";
				sql += QString::fromLocal8Bit(" and ����ƾ֤�� = ") + "\'" + DBPingZhengHao + "\'";
				sql += QString::fromLocal8Bit(" and װ������ = ") + "\'" + ZBDaiMa + "\'";
				sql += QString::fromLocal8Bit(" and װ������ = ") + "\'"+ZBMingCheng + "\'";
				sql += QString::fromLocal8Bit(" and ��װ��� = ") + "\'"+DZBianHao + "\'";
				QString errMsg;
				bool rv = CDatabaseOperator::GetInstance()->execSql(sql, QTableData(), errMsg);
				if (!rv)
				{
					QMessageBox::information(this, QString::fromLocal8Bit("��װ���"), errMsg);
					return;
				}
			}
			else
			{
				sql = QString::fromLocal8Bit("update GunManager.dbo.BoxPackedDetailsTable set ����״̬ = '�ѳ���',����ʱ��= \'") + ChuKuDateTime + "\' where";
				sql += QString::fromLocal8Bit(" GunManager.dbo.BoxPackedDetailsTable.��װ��� in (select ��װ��� from");
				sql += QString::fromLocal8Bit(" GunManager.dbo.BoxPackedTable t1,GunManager.dbo.BoxPackedDetailsTable t2");
				sql += QString::fromLocal8Bit(" where t1.���۱����ļ��� = ") + "\'" + BFWenJianHao + "\'";
				sql += QString::fromLocal8Bit(" and t1.����ƾ֤�� = ") + "\'" + DBPingZhengHao + "\'";
				sql += QString::fromLocal8Bit(" and t1.װ�䵥�� = ") + "\'" + ZXDanHao + "\'";
				sql += QString::fromLocal8Bit(" and t1.װ�䵥�� = t2.װ�䵥�� and t2.��װ��� = \'") + DZBianHao + "\')";
				QString errMsg;
				bool rv = CDatabaseOperator::GetInstance()->execSql(sql, QTableData(), errMsg);
				if (!rv)
				{
					QMessageBox::information(this, QString::fromLocal8Bit("��װ���"), errMsg);
					return;
				}
			}
		}
	}
	ExportGridA9();
}

void CSystemMangaer::Remainder()//��Ϣ�������-�������⡱��������ϡ���ѯ����ť����ʾ�������
{
	QString sql = QString::fromLocal8Bit("select t1.���۱����ļ���,t1.����ƾ֤��,t1.װ�䵥��,t1.װ������,t1.װ������,t2.��װ���,t2.ǹ�ܺ�,t2.ǹ������Ͳ��,t2.��ǹ���,t2.����ǹ�ܺ�,t1.����ʱ��,t1.װ��ʱ��,t1.װ������,t2.���ʱ��");
	sql += " from GunManager.dbo.BoxPackedTable t1 right join GunManager.dbo.BoxPackedDetailsTable t2 on";
	sql += QString::fromLocal8Bit(" t1.װ�䵥�� = t2.װ�䵥�� and t1.װ������ = t2.װ������ and t1.װ������ = t2.װ������");
	sql += " where " + QString::fromLocal8Bit("t2.����״̬ = \'δ����\'");
	//QString sql = QString::fromLocal8Bit("select * from GunManager.dbo.SinglePackedTable");
	//sql += " where " + QString::fromLocal8Bit("����״̬ = \'δ����\'");

	QTableData PackedTableData;
	QTableData SingleTableData;
	QString errMsg;
	bool rv = CDatabaseOperator::GetInstance()->execSql(sql, PackedTableData, errMsg);
	if (!rv)
	{
		QMessageBox::information(this, QString::fromLocal8Bit("��װ��Ϣ��ѯʧ��"), errMsg);
		return;
	}

	sql.clear();
	
	sql = QString::fromLocal8Bit("select * from GunManager.dbo.SinglePackedTable");
	sql += " where " + QString::fromLocal8Bit("����״̬ = \'δ����\'");
	/*sql = QString::fromLocal8Bit("select * from GunManager.dbo.SinglePackedTable");
	sql += " where " + QString::fromLocal8Bit("����״̬= \'") + QString::fromLocal8Bit("δ����\'");*/

	rv = CDatabaseOperator::GetInstance()->execSql(sql, SingleTableData, errMsg);
	if (!rv)
	{
		QMessageBox::information(this, QString::fromLocal8Bit("��װ��Ϣ��ѯʧ��"), errMsg);
		return;
	}
	QTableData AllTableData;
	AllTableData.append(PackedTableData);
	AllTableData.append(SingleTableData);
    int count_Remainder =AllTableData.size();
	QString count = QString::number(count_Remainder);
	ui.label_Remainder->setText(count);

}

//����Ϊcsv��ʽ��ȫ�̵ǼǱ�
void CSystemMangaer::ExportGridA9()
{
	//��ȡ������csv�ļ�
	QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath(),tr("Files (*.csv)"));
	if (fileName.isEmpty())
	{
		return;
	}

	// ��.csv�ļ�
	QFile file(fileName);
	if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
	{
		qDebug() << "Open file failed!";
		return;
	}

	//int row = ui.tableWidget_Delivery->rowCount();//���������
	//int col = ui.tableWidget_Delivery->columnCount();

	QTextStream out(&file);
	//QString str;
   //��ͷ 
	out << QString::fromLocal8Bit("���۱���ǹе���ٴ������ȫ���̵ǼǱ�\n");
	//��һ��
	out << QString::fromLocal8Bit("ǹе����,,,,,,,,,")<< QString::fromLocal8Bit("��λ,,") << QString::fromLocal8Bit("����,,") << QString::fromLocal8Bit("��Դ,,,,,,") << QString::fromLocal8Bit("�ļ���,,\n");

	//�ڶ���
	out << QString::fromLocal8Bit("���,")<< QString::fromLocal8Bit("ǹе����,,,,")<< QString::fromLocal8Bit("������¼,,,,") << QString::fromLocal8Bit("����װ���¼,,,,") << QString::fromLocal8Bit("װж�����¼,,,,,,") << QString::fromLocal8Bit("Ͷ¯������¼,,,,") << QString::fromLocal8Bit("��ע\n");
	//������
	out << QString::fromLocal8Bit(",��ǹ��,") << QString::fromLocal8Bit("ǹ�ܺ�,") << QString::fromLocal8Bit("��ǹ�Ż���Ͳ��,") << QString::fromLocal8Bit("��ǹ���,");
	out << QString::fromLocal8Bit("����,") << QString::fromLocal8Bit("�����,") << QString::fromLocal8Bit("�����,") << QString::fromLocal8Bit("�ල��,");
	out << QString::fromLocal8Bit("����,") << QString::fromLocal8Bit("��(��)��,") << QString::fromLocal8Bit("����װ����,") << QString::fromLocal8Bit("�ල��,");
	out << QString::fromLocal8Bit("����,") << QString::fromLocal8Bit("���䳵��,") << QString::fromLocal8Bit("װ����,") << QString::fromLocal8Bit("Ѻ����,") << QString::fromLocal8Bit("ж����,") << QString::fromLocal8Bit("�ල��,");
	out << QString::fromLocal8Bit("����,") << QString::fromLocal8Bit("������,") << QString::fromLocal8Bit("�˲���,") << QString::fromLocal8Bit("������\n");

	//for (int i = 0; i < col; i++)
	//{
	//	//out << QString::fromLocal8Bit("����") << "\n";
	//	//out << ui.tableWidget_Delivery->header(i, Qt::Horizontal, Qt::DisplayRole).toString() << ",";
	//	if (i == (col - 1))
	//	{
	//		out << "\n";
	//	}
	//}

	//��ȡ�������
	int row = ui.tableWidget_Delivery->rowCount();//���������
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
				out << rowStr << ",";// д���ļ�
			}
			//out << "\n" << ",";
			out << "\n" ;
		}
		
	}
	QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("����ɹ���"));
	//QMessageBox::information(this, QString::fromLocal8Bit("�������ݳɹ�"), QString::fromLocal8Bit("��Ϣ�ѱ�����%1��").arg(fileName), QString::fromLocal8Bit("ȷ��"));
	file.close();

}


 //����xls��ʽ�������
//void CSystemMangaer::DoDelivery()//��Ϣ�������-������ѯ����������ϡ����⡱��ť-----���˲ۺ���
//{
//	int rows = ui.tableWidget_Delivery->rowCount();
//	if (rows == 0)
//	{
//		return;
//	}
//	QString filepath = QFileDialog::getSaveFileName(this, ("Save as..."), QString(), tr("EXCEL files (*.xls *.xlsx)"));
//	if (filepath.isEmpty())
//	{
//		QMessageBox::critical(0, tr("����"), tr("Ҫ������ļ�������Ϊ�գ�"));
//		return;
//	}
//	qDebug() << "Export excel:" << filepath.toStdString().c_str();
//
//	int row = ui.tableWidget_Delivery->rowCount();
//	int col = ui.tableWidget_Delivery->columnCount();
//	QList<QString> list;
//	����б���  
//	QString HeaderRow;
//	for (int i = 0; i < col - 1; i++)//��ͷ���������һ��
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
//			for (int j = 0; j < col - 1; j++)//����
//			{
//				rowStr += ui.tableWidget_Delivery->item(i, j)->text() + "\t";
//			}
//			list.push_back(rowStr);
//		}
//	}
//	�����������ӵ����ı���
//	QTextEdit textEdit;
//	for (int i = 0; i < list.size(); i++)
//	{
//		textEdit.append(list.at(i));
//	}
//	д���ļ���
//	QFile file(filepath);
//	if (file.open(QFile::WriteOnly | QIODevice::Text))
//	{
//		QTextStream ts(&file);
//		ts.setCodec("GB2312");//����ط�����Լ��ж��Ƿ��á�utf-8��
//		ts << textEdit.document()->toPlainText();
//		file.close();
//		QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("����excel�ɹ�"));
//	}
//}



//�޸ģ�׼������xls��ȫ�̼�¼��
//void CSystemMangaer::DoDelivery()//��Ϣ�������-������ѯ����������ϡ����⡱��ť-----���˲ۺ���
//{
//	QString fileName = QFileDialog::getSaveFileName(this, QStringLiteral("����"),
//		QString(), QStringLiteral("Excel �ļ�(*.xls *.xlsx)"));
//	if (fileName != "")
//	{
//		QAxObject *excel = new QAxObject;
//		if (excel->setControl("Excel.Application")) //����Excel�ؼ�
//		{
//			excel->dynamicCall("SetVisible (bool Visible)", "false");//����ʾ����
//			excel->setProperty("DisplayAlerts", false);//����ʾ�κξ�����Ϣ
//			QAxObject *workbooks = excel->querySubObject("WorkBooks");//��ȡ����������
//			workbooks->dynamicCall("Add");//�½�һ��������
//			QAxObject *workbook = excel->querySubObject("ActiveWorkBook");//��ȡ��ǰ������
//			QAxObject *worksheet = workbook->querySubObject("Worksheets(int)", 1);
//
//			int i, j;
//			int colount = ui.tableWidget_Delivery->columnCount();
//			int rowcount = ui.tableWidget_Delivery->rowCount();
//
//			QAxObject *cell, *col;
//			//������
//			cell = worksheet->querySubObject("Cells(int,int)", 1, 1);
//			cell->dynamicCall("SetValue(const QString&)", QStringLiteral("��־��Ϣ"));
//			cell->querySubObject("Font")->setProperty("Size", 15);
//			//�����и�
//			worksheet->querySubObject("Range(const QString&)", "1:1")->setProperty("RowHeight", 30);
//			//�ϲ�������
//			QString cellTitle;
//			cellTitle.append("A1:");
//			cellTitle.append(QChar(colount - 1 + 'A'));
//			cellTitle.append(QString::number(1));
//			QAxObject *range = worksheet->querySubObject("Range(const QString&)", cellTitle);
//			range->setProperty("WrapText", true);
//			range->setProperty("MergeCells", true);
//			range->setProperty("HorizontalAlignment", -4108);
//			range->setProperty("VerticalAlignment", -4108);
//			//�б���
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
//				//QTableView ��ȡ���ͷ��������Ϣ
//				//columnName = ui.tableWidget_Delivery->header(i, Qt::Horizontal, Qt::DisplayRole).toString();
//				//columnName = ui.tableWidget_Delivery->horizontalHeader();
//				cell->dynamicCall("SetValue(const QString&)", columnName);
//				cell->querySubObject("Font")->setProperty("Bold", true);
//				cell->querySubObject("Interior")->setProperty("Color", QColor(191, 191, 191));
//				cell->setProperty("HorizontalAlignment", -4108);//xlCenter
//				cell->setProperty("VerticalAlignment", -4108);//xlCenter
//			}
//			//QTableView ��ȡ������ݲ���
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
//			//������
//			QString lrange;
//			lrange.append("A2:");
//			lrange.append(colount - 1 + 'A');
//			lrange.append(QString::number(ui.tableWidget_Delivery->rowCount() + 2));
//			range = worksheet->querySubObject("Range(const QString&)", lrange);
//			range->querySubObject("Borders")->setProperty("LineStyle", QString::number(1));
//			range->querySubObject("Borders")->setProperty("Color", QColor(0, 0, 0));
//			//�����������и�
//			QString rowsName;
//			rowsName.append("2:");
//			rowsName.append(QString::number(ui.tableWidget_Delivery->rowCount() + 2));
//			range = worksheet->querySubObject("Range(const QString&)", rowsName);
//			range->setProperty("RowHeight", 20);
//			workbook->dynamicCall("SaveAs(const QString&)", QDir::toNativeSeparators(fileName));//������fileName
//			workbook->dynamicCall("Close()");//�رչ�����
//			excel->dynamicCall("Quit()");//�ر�excel
//			delete excel;
//			excel = NULL;
//
//			if (QMessageBox::question(this, QStringLiteral("���"), QStringLiteral("�ļ��Ѿ��������Ƿ����ڴ򿪣�"), QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes);
//			else
//				QMessageBox::warning(NULL, QStringLiteral("����"), QStringLiteral("δ�ܴ��� Excel �����밲װ Microsoft Excel��"), QMessageBox::Apply);
//		}
//	}
//}


void CSystemMangaer::ImageGrabberReturn()//���ռ��ӽ���-�����¡����ء���ť--���˲ۺ���
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

void CSystemMangaer::ExportExcel()//��Ϣ�������-������ѯ����������ϡ�����Excel����ť-----���˲ۺ���
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
	//����б���  
	QString HeaderRow;
	
	for (int i = 0; i < col-1; i++)//���һ�е�ѡ������ȥ
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
		//ts.setCodec("GB2312");//����ط�����Լ��ж��Ƿ��á�utf-8��
		ts.setCodec("utf-8");
		ts << textEdit.document()->toPlainText();
		file.close();
		QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("����excel�ɹ�"));
	}
}

//��ȡͼ������
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

void CSystemMangaer::SoftTriggerCodeCamera()//���ռ��ӽ���-�����¡��������ա���ť--���˲ۺ���
{
	emit SendSoftTrigger(1);
}

void CSystemMangaer::SoftTriggerWholeCamera()//���ռ��ӽ���-�����¡���ǹ���ա���ť--���˲ۺ���
{
	emit SendSoftTrigger(2);
}


//����������յ�ͼ������
void CSystemMangaer::ReceiveImage(int index, Mat image)
{
	if (index == 1)//���1
	{
		if (m_bInitAlogSuccess)//VimoOCRModule��ʼ���ɹ�
		{
			ui.lineEdit_Ocr->setText("");//���ռ��ӽ���-�����ϡ�ͼ��ʶ�𡱱༭��
			ui.lineEdit_XiuZheng->setText("");//���ռ��ӽ���-�����ϡ��˹��������༭��
			
			 //4��ǹ֧����
			ui.lineEdit_QiangGuan->setText("");
			ui.lineEdit_QiangJi->setText("");
			ui.lineEdit_QiangKuang->setText("");
			ui.lineEdit_BeiFen->setText("");

			QString result;
			//cvtColor(image, image, COLOR_GRAY2BGR);
			bool bAlgoSuccess = CAlgoCodeReview::GetInstance()->RunAlog(image, result);//����OCR���ģ��
			if (bAlgoSuccess)
			{
				ui.lineEdit_Ocr->setText(result);//���ռ��ӽ���-�����ϡ�ͼ��ʶ�𡱱༭����ʾ���
				m_CurDZBianHao = result;////ʶ��ĵ�װ���Ҳ��OCRʶ��Ľ��
				DoSpeaker();//�ұߵ�С������ȡ���
			}
		}
		CodeImage = image.clone();
		QImage img = matToQImage(image);//����matToQImage��������ȡͼ�����ݣ��С��У���ʽ��
		ui.label_Image1->SetImage(img);
	}
	else if (index == 2)
	{
		GunImage = image.clone();
		QImage img = matToQImage(image);//����matToQImage��������ȡͼ�����ݣ��С��У���ʽ��
		ui.label_Image2->SetImage(img);//�����ռ��ӡ����棬�м�������ʾ����������������ť
	}
}


//���ռ��ӽ�������¡����桱��ť---���˲ۺ���
void CSystemMangaer::SaveRecognizeResult()
{
	if (m_CurDZBianHao.isEmpty())//�жϵ�װ���벻��Ϊ��
	{
		QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("ʶ����Ϊ�գ��������κ�����"));
		return;
	}
	//4��ǹ�Ĳ�����
	QString m_QiangGuanHao = ui.lineEdit_QiangGuan->text();
	QString m_QiangJiHao = ui.lineEdit_QiangJi->text();
	QString m_QiangKuangHao = ui.lineEdit_QiangKuang->text();
	QString m_BeiFenHao = ui.lineEdit_BeiFen->text();

	//message������ʾ
	QString message = QString::fromLocal8Bit("��װ����:") + m_CurDZBianHao + "\n";
	//QString message_QiangGuanHao = QString::fromLocal8Bit("ǹ�ܺ�:") + m_QiangGuanHao + "\n";
	//QString message_QiangJiHao = QString::fromLocal8Bit("ǹ��/��Ͳ��:") + m_QiangJiHao + "\n";
	//QString message_QiangKuangHao = QString::fromLocal8Bit("��ǹ���:") + m_QiangKuangHao + "\n";
	//QString message_BeiFenHao = QString::fromLocal8Bit("����ǹ�ܺ�:") + m_BeiFenHao + "\n";

	QString LostMeg;
	QString message_QiangGuanHao = QString::fromLocal8Bit("ǹ�ܺ�:") + m_QiangGuanHao + "\n";
	QString message_QiangJiHao = QString::fromLocal8Bit("ǹ��/��Ͳ��:") + m_QiangJiHao + "\n";
	QString message_QiangKuangHao = QString::fromLocal8Bit("��ǹ���:") + m_QiangKuangHao + "\n";
	QString message_BeiFenHao = QString::fromLocal8Bit("����ǹ�ܺ�:") + m_BeiFenHao;

	if (m_curMsg.type == 1)//��װ
	{
		bool bCheck = ui.checkBox_QiangGuan->isChecked();
		if (!bCheck)
		{
			LostMeg = QString::fromLocal8Bit("ǹ��ȱʧ");
		}
		bCheck = ui.checkBox_QiangJi->isChecked();
		if (!bCheck)
		{
			LostMeg.isEmpty() ? LostMeg += QString::fromLocal8Bit("ǹ��/��Ͳȱʧ") : LostMeg += QString::fromLocal8Bit(",ǹ��/��Ͳȱʧ");
		}
		bCheck = ui.checkBox_QiangKuang->isChecked();
		if (!bCheck)
		{
			LostMeg.isEmpty() ? LostMeg += QString::fromLocal8Bit("��ǹ��ȱʧ"): LostMeg += QString::fromLocal8Bit(",��ǹ��ȱʧ");
		}
		bCheck = ui.checkBox_BeiFen->isChecked();
		if (!bCheck)
		{
			LostMeg.isEmpty() ? LostMeg += QString::fromLocal8Bit("����ǹ��ȱʧ"): LostMeg += QString::fromLocal8Bit(",����ǹ��ȱʧ");
		}
	}

	else if (m_curMsg.type == 2)//��װ
	{
		bool bCheck = ui.checkBox_QiangGuan->isChecked();
		if (!bCheck)
		{
			LostMeg = QString::fromLocal8Bit("ǹ��ȱʧ");
		}
		bCheck = ui.checkBox_QiangJi->isChecked();
		if (!bCheck)
		{
			LostMeg.isEmpty() ? LostMeg += QString::fromLocal8Bit("ǹ��/��Ͳȱʧ") : LostMeg += QString::fromLocal8Bit(",ǹ��/��Ͳȱʧ");
		}
		bCheck = ui.checkBox_QiangKuang->isChecked();
		if (!bCheck)
		{
			LostMeg.isEmpty() ? LostMeg += QString::fromLocal8Bit("��ǹ��ȱʧ") : LostMeg += QString::fromLocal8Bit(",��ǹ��ȱʧ");
		}
		bCheck = ui.checkBox_BeiFen->isChecked();
		if (!bCheck)
		{
			LostMeg.isEmpty() ? LostMeg += QString::fromLocal8Bit("����ǹ��ȱʧ") : LostMeg += QString::fromLocal8Bit(",����ǹ��ȱʧ");
		}
	}

	/*bool bCheck = ui.checkBox_QiangGuan->isChecked();
	if (!bCheck)
	{
		LostMeg = QString::fromLocal8Bit("ǹ��ȱʧ");
	}
	bCheck = ui.checkBox_QiangJi->isChecked();
	if (!bCheck)
	{
		LostMeg.isEmpty() ? LostMeg += QString::fromLocal8Bit("ǹ��/��Ͳȱʧ") : LostMeg += QString::fromLocal8Bit(",ǹ��/��Ͳȱʧ");
	}
	bCheck = ui.checkBox_QiangKuang->isChecked();
	if (!bCheck)
	{
		LostMeg.isEmpty() ? LostMeg += QString::fromLocal8Bit("��ǹ��ȱʧ") : LostMeg += QString::fromLocal8Bit(",��ǹ��ȱʧ");
	}
	bCheck = ui.checkBox_BeiFen->isChecked();
	if (!bCheck)
	{
			LostMeg.isEmpty() ? LostMeg += QString::fromLocal8Bit("����ǹ��ȱʧ") : LostMeg += QString::fromLocal8Bit(",����ǹ��ȱʧ");
	}*/

	QPushButton *okbtn = new QPushButton(QString::fromLocal8Bit("ȷ��"));
	QPushButton *cancelbtn = new QPushButton(QString::fromLocal8Bit("ȡ��"));
	QMessageBox *mymsgbox = new QMessageBox;//����һ����Ϣ��
	
	QDateTime curDateTime = QDateTime::currentDateTime();
	QString JianShiDateTime = curDateTime.toString("yyyy-M-d");//��ȡ��ǰ���ڣ���ת��Ϊ�ַ���

	mymsgbox->setIcon(QMessageBox::Warning);
	mymsgbox->setWindowTitle(QString::fromLocal8Bit("�Ƿ񱣴�?"));
	//mymsgbox->setText(message+ LostMeg);
	mymsgbox->setText(message + LostMeg + "\n"+ message_QiangGuanHao + message_QiangJiHao + message_QiangKuangHao + message_BeiFenHao);//������Ϣ�������
	mymsgbox->addButton(okbtn, QMessageBox::AcceptRole);
	mymsgbox->addButton(cancelbtn, QMessageBox::RejectRole);
	mymsgbox->show();

	mymsgbox->exec();//�����ȴ��û�����

    //���ͼƬ
	QString path = CParameterSettings::GetInstance()->GetSavePath();
	path += "/" + QDateTime::currentDateTime().toString("yyyy-MM-dd") + "/" + m_CurDZBianHao;
	QDir dir;
	bool rv = dir.mkpath(path);
	if (!rv)
	{
		QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("����·��ʧ��"));
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

	if (mymsgbox->clickedButton() == okbtn)//�����OK��ť
	{
		QString sql;
		if (m_curMsg.type == 1)//��װ
		{
			//�������ݿ�
			sql = QString::fromLocal8Bit("update GunManager.dbo.BoxPackedDetailsTable set ��װ��� = \'") + m_CurDZBianHao + "\'";
			sql += QString::fromLocal8Bit(",ȱʧ��� = \'") + LostMeg + "\'";
			sql += QString::fromLocal8Bit(",ǹ�ܺ� = \'") + m_QiangGuanHao + "\'";
			sql += QString::fromLocal8Bit(",ǹ������Ͳ�� = \'") + m_QiangJiHao + "\'";
			sql += QString::fromLocal8Bit(",��ǹ��� = \'") + m_QiangKuangHao + "\'";
			sql += QString::fromLocal8Bit(",����ǹ�ܺ� = \'") + m_BeiFenHao + "\'";
			sql += QString::fromLocal8Bit(",����ʱ�� = \'") + JianShiDateTime + "\'";
			sql += QString::fromLocal8Bit("where GunManager.dbo.BoxPackedDetailsTable.��� = ") + QString::number(m_curMsg.index);
            sql += QString::fromLocal8Bit(" and GunManager.dbo.BoxPackedDetailsTable.װ�䵥�� = \'") + m_curMsg.PackedNum + "\'";//m_curMsg.PackedNum=DanHao
			//sql += QString::fromLocal8Bit(" where GunManager.dbo.BoxPackedDetailsTable.��� = ") + QString::number(m_curMsg.index);


		}
		else if (m_curMsg.type == 2)//��װ
		{
			//�������ݿ�
			sql = QString::fromLocal8Bit("update GunManager.dbo.SinglePackedTable set ��װ��� = \'") + m_CurDZBianHao + "\'";
			sql += QString::fromLocal8Bit(",ȱʧ��� = \'") + LostMeg + "\'";
			sql += QString::fromLocal8Bit(",ǹ�ܺ� = \'") + m_QiangGuanHao + "\'";
			sql += QString::fromLocal8Bit(",ǹ������Ͳ�� = \'") + m_QiangJiHao + "\'";
			sql += QString::fromLocal8Bit(",��ǹ��� = \'") + m_QiangKuangHao + "\'";
			sql += QString::fromLocal8Bit(",����ǹ�ܺ� = \'") + m_BeiFenHao + "\'";
			sql += QString::fromLocal8Bit(",����ʱ�� = \'") + JianShiDateTime + "\'";
			sql += QString::fromLocal8Bit(" where ���۱����ļ��� = \'") + m_curMsg.BFWenJianHao + "\'";
			sql += QString::fromLocal8Bit(" and ����ƾ֤�� = \'") + m_curMsg.DBPingZhengHao + "\'";
			sql += QString::fromLocal8Bit(" and װ������ = \'") + m_curMsg.ZBDaiMa + "\'";
		}
		QString errMsg;
		bool rv = CDatabaseOperator::GetInstance()->execSql(sql, QTableData(), errMsg);
		if (!rv)
		{
			QMessageBox::information(this, QString::fromLocal8Bit("���ݿ�ִ�д���"), errMsg);
			
		}
		else
		{
			if (m_curMsg.type == 1)//��װ�б�
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
			else if (m_curMsg.type == 2)//��װ
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


				//////�����ݣ��Ѽӣ�


			}
			ImageGrabberReturn();
		}
	}
}

void CSystemMangaer::DoCorrection()//���ռ��ӽ���->���½�"����"��ť--���˲ۺ���
{
	QString result = ui.lineEdit_XiuZheng->text();
	if (result.isEmpty())
	{
		QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("�˹���������Ϊ��"));
		return;
	}
	m_CurDZBianHao = result;//����ʶ��ĵ�װ����
	ui.lineEdit_Ocr->setText(result);
	DoSpeaker();
}

void CSystemMangaer::DoSpeaker()//���ռ��ӽ����С����Ϊ�ź�--���˲ۺ���
{
	QTextToSpeech *m_speech = new QTextToSpeech();

	QVector<QLocale> Locales = m_speech->availableLocales();//��ȡ֧�ֵ��ı����������������б�
	m_speech->setLocale(QLocale::Chinese);//�������Ի���
	m_speech->setRate(0.3);//���٣�-1----1
	m_speech->setPitch(1.0);//���ߣ�-1---1
	m_speech->setVolume(1.0);//������0---1
	//m_speech->say("1234");//��ʼ�ϳ��ı�
	//m_speech->say(QString::fromLocal8Bit("���"));//��ʼ�ϳ��ı�
	if (m_speech->state() == QTextToSpeech::Ready)
	{
		m_speech->say(m_CurDZBianHao);//��ʼ�ϳ��ı�
		//m_speech->say("���");//��ʼ�ϳ��ı�
	}
}