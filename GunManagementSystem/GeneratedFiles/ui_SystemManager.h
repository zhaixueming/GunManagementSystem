/********************************************************************************
** Form generated from reading UI file 'SystemManager.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYSTEMMANAGER_H
#define UI_SYSTEMMANAGER_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <mylabel.h>

QT_BEGIN_NAMESPACE

class Ui_SystemManager
{
public:
    QGridLayout *gridLayout_4;
    QTabWidget *tabWidget;
    QWidget *tab_1;
    QGridLayout *gridLayout_3;
    QPushButton *pushButton_AddUser;
    QSpacerItem *horizontalSpacer;
    QLineEdit *lineEdit_Name;
    QLineEdit *lineEdit_OfficerNumber;
    QPushButton *pushButton_QueryUser;
    QTableWidget *tableWidget_User;
    QWidget *tab_2;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget_Storage;
    QWidget *tab_Ephor1;
    QGridLayout *gridLayout_10;
    QPushButton *pushButton_AddBox;
    QSpacerItem *horizontalSpacer_11;
    QGridLayout *gridLayout_9;
    QLineEdit *lineEdit_WenJianHao;
    QLineEdit *lineEdit_PingZhengHao;
    QLineEdit *lineEdit_ZhuangXiangDanHao;
    QLabel *label_7;
    QDateEdit *dateEdit_BoxCC;
    QLabel *label_8;
    QDateEdit *dateEdit_BoxZB;
    QPushButton *pushButton_QueryBox;
    QTableWidget *tableWidget_Box;
    QWidget *tab_Ephor2;
    QGridLayout *gridLayout_12;
    QPushButton *pushButton_AddSinglePacked;
    QSpacerItem *horizontalSpacer_13;
    QGridLayout *gridLayout_11;
    QLineEdit *lineEdit_SingleWJH;
    QLineEdit *lineEdit_SinglePZH;
    QLineEdit *lineEdit_SingleDM;
    QLabel *label_5;
    QDateEdit *dateEdit_SingleCC;
    QLabel *label_6;
    QDateEdit *dateEdit_SingleZB;
    QPushButton *pushButton_QuerySinglePacked;
    QTableWidget *tableWidget_Single;
    QPushButton *pushButton_PrintSinglePacked;
    QSpacerItem *horizontalSpacer_5;
    QWidget *tab_3;
    QFormLayout *formLayout_2;
    QTabWidget *tabWidget_Information;
    QWidget *tab_Info1;
    QFormLayout *formLayout;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_12;
    QPushButton *pushButton_ExportExcel;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit_BFWenJianHao;
    QLineEdit *lineEdit_DBPingZhengHao;
    QLineEdit *lineEdit_XZDanHao;
    QLineEdit *lineEdit_ZBDaima;
    QLineEdit *lineEdit_ZBMingCheng;
    QLineEdit *lineEdit_DZBianHao;
    QHBoxLayout *horizontalLayout_11;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_12;
    QDateEdit *dateEdit_InfoRK;
    QLabel *label;
    QDateEdit *dateEdit_InfoRK_end;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_13;
    QDateEdit *dateEdit_InfoJS;
    QLabel *label_2;
    QDateEdit *dateEdit_InfoJS_end;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_11;
    QDateEdit *dateEdit_InfoCK;
    QLabel *label_3;
    QDateEdit *dateEdit_InfoCK_end;
    QPushButton *pushButton_QueryInfo;
    QTableWidget *tableWidget_Search;
    QLabel *label_29;
    QWidget *tab_Info2;
    QGridLayout *gridLayout_13;
    QPushButton *pushButton_Deliver;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_6;
    QLineEdit *lineEdit_DeliveryBFWenJianHao;
    QLineEdit *lineEdit_DeliveryDBPingZhengHao;
    QLineEdit *lineEdit_DeliveryXZDanHao;
    QLineEdit *lineEdit_DeliveryZBDaima;
    QLineEdit *lineEdit_DeliveryZBMingCheng;
    QLabel *label_10;
    QDateEdit *dateEdit_DeliveryCC;
    QLabel *label_9;
    QDateEdit *dateEdit_DeliveryZB;
    QPushButton *pushButton_QueryDeliver;
    QTableWidget *tableWidget_Delivery;
    QWidget *tab_4;
    QGridLayout *gridLayout_5;
    QTableWidget *tableWidget_PackedInfo;
    QPushButton *pushButton_16;
    QSpacerItem *horizontalSpacer_12;
    QPushButton *pushButton_25;
    QWidget *tab;
    QGridLayout *gridLayout_8;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_6;
    MyLabel *label_Image2;
    QPushButton *pushButton_CodeGrab;
    MyLabel *label_Image1;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_GunGrab;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_7;
    QLabel *label_26;
    QLineEdit *lineEdit_Ocr;
    QPushButton *pushButton_Speaker;
    QLabel *label_27;
    QLineEdit *lineEdit_XiuZheng;
    QCheckBox *checkBox_QiangGuan;
    QLineEdit *lineEdit_QiangGuan;
    QCheckBox *checkBox_QiangJi;
    QLineEdit *lineEdit_QiangJi;
    QCheckBox *checkBox_QiangKuang;
    QLineEdit *lineEdit_QiangKuang;
    QCheckBox *checkBox_BeiFen;
    QLineEdit *lineEdit_BeiFen;
    QLabel *label_28;
    QLabel *label_DanHao;
    QPushButton *pushButton_Save;
    QPushButton *pushButton_Modify;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_26;

    void setupUi(QDialog *SystemManager)
    {
        if (SystemManager->objectName().isEmpty())
            SystemManager->setObjectName(QString::fromUtf8("SystemManager"));
        SystemManager->resize(1755, 668);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/SysMainWindow/Resources/login-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        SystemManager->setWindowIcon(icon);
        gridLayout_4 = new QGridLayout(SystemManager);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        tabWidget = new QTabWidget(SystemManager);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab_1 = new QWidget();
        tab_1->setObjectName(QString::fromUtf8("tab_1"));
        gridLayout_3 = new QGridLayout(tab_1);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        pushButton_AddUser = new QPushButton(tab_1);
        pushButton_AddUser->setObjectName(QString::fromUtf8("pushButton_AddUser"));
        pushButton_AddUser->setMinimumSize(QSize(75, 30));
        pushButton_AddUser->setMaximumSize(QSize(75, 30));
        pushButton_AddUser->setStyleSheet(QString::fromUtf8("font: 75 15pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(255, 255, 0);\n"
"background-color: rgb(255, 0, 0);\n"
""));
        pushButton_AddUser->setFlat(false);

        gridLayout_3->addWidget(pushButton_AddUser, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(713, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 0, 1, 1, 1);

        lineEdit_Name = new QLineEdit(tab_1);
        lineEdit_Name->setObjectName(QString::fromUtf8("lineEdit_Name"));
        lineEdit_Name->setMinimumSize(QSize(100, 30));
        lineEdit_Name->setMaximumSize(QSize(100, 30));
        lineEdit_Name->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout_3->addWidget(lineEdit_Name, 0, 2, 1, 1);

        lineEdit_OfficerNumber = new QLineEdit(tab_1);
        lineEdit_OfficerNumber->setObjectName(QString::fromUtf8("lineEdit_OfficerNumber"));
        lineEdit_OfficerNumber->setMinimumSize(QSize(200, 30));
        lineEdit_OfficerNumber->setMaximumSize(QSize(200, 30));
        lineEdit_OfficerNumber->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout_3->addWidget(lineEdit_OfficerNumber, 0, 3, 1, 1);

        pushButton_QueryUser = new QPushButton(tab_1);
        pushButton_QueryUser->setObjectName(QString::fromUtf8("pushButton_QueryUser"));
        pushButton_QueryUser->setMinimumSize(QSize(75, 30));
        pushButton_QueryUser->setMaximumSize(QSize(75, 30));
        pushButton_QueryUser->setStyleSheet(QString::fromUtf8("font: 75 15pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"background-color: rgb(41, 136, 41);\n"
"color: rgb(255, 255, 255);"));

        gridLayout_3->addWidget(pushButton_QueryUser, 0, 4, 1, 1);

        tableWidget_User = new QTableWidget(tab_1);
        tableWidget_User->setObjectName(QString::fromUtf8("tableWidget_User"));
        tableWidget_User->setSortingEnabled(true);

        gridLayout_3->addWidget(tableWidget_User, 1, 0, 1, 5);

        tabWidget->addTab(tab_1, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayout = new QGridLayout(tab_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tabWidget_Storage = new QTabWidget(tab_2);
        tabWidget_Storage->setObjectName(QString::fromUtf8("tabWidget_Storage"));
        tabWidget_Storage->setTabShape(QTabWidget::Triangular);
        tab_Ephor1 = new QWidget();
        tab_Ephor1->setObjectName(QString::fromUtf8("tab_Ephor1"));
        gridLayout_10 = new QGridLayout(tab_Ephor1);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        pushButton_AddBox = new QPushButton(tab_Ephor1);
        pushButton_AddBox->setObjectName(QString::fromUtf8("pushButton_AddBox"));
        pushButton_AddBox->setMinimumSize(QSize(75, 30));
        pushButton_AddBox->setMaximumSize(QSize(75, 30));
        pushButton_AddBox->setStyleSheet(QString::fromUtf8("font: 75 15pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(255, 255, 0);\n"
"background-color: rgb(255, 0, 0);\n"
""));
        pushButton_AddBox->setFlat(false);

        gridLayout_10->addWidget(pushButton_AddBox, 0, 0, 1, 1);

        horizontalSpacer_11 = new QSpacerItem(63, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_10->addItem(horizontalSpacer_11, 0, 1, 1, 1);

        gridLayout_9 = new QGridLayout();
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        lineEdit_WenJianHao = new QLineEdit(tab_Ephor1);
        lineEdit_WenJianHao->setObjectName(QString::fromUtf8("lineEdit_WenJianHao"));
        lineEdit_WenJianHao->setMinimumSize(QSize(150, 30));
        lineEdit_WenJianHao->setMaximumSize(QSize(150, 30));
        lineEdit_WenJianHao->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout_9->addWidget(lineEdit_WenJianHao, 0, 0, 1, 1);

        lineEdit_PingZhengHao = new QLineEdit(tab_Ephor1);
        lineEdit_PingZhengHao->setObjectName(QString::fromUtf8("lineEdit_PingZhengHao"));
        lineEdit_PingZhengHao->setMinimumSize(QSize(150, 30));
        lineEdit_PingZhengHao->setMaximumSize(QSize(150, 30));
        lineEdit_PingZhengHao->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout_9->addWidget(lineEdit_PingZhengHao, 0, 1, 1, 1);

        lineEdit_ZhuangXiangDanHao = new QLineEdit(tab_Ephor1);
        lineEdit_ZhuangXiangDanHao->setObjectName(QString::fromUtf8("lineEdit_ZhuangXiangDanHao"));
        lineEdit_ZhuangXiangDanHao->setMinimumSize(QSize(150, 30));
        lineEdit_ZhuangXiangDanHao->setMaximumSize(QSize(150, 30));
        lineEdit_ZhuangXiangDanHao->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout_9->addWidget(lineEdit_ZhuangXiangDanHao, 0, 2, 1, 1);

        label_7 = new QLabel(tab_Ephor1);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMaximumSize(QSize(80, 16777215));
        label_7->setStyleSheet(QString::fromUtf8("font: 75 15pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(41, 136, 41);"));
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_9->addWidget(label_7, 0, 3, 1, 1);

        dateEdit_BoxCC = new QDateEdit(tab_Ephor1);
        dateEdit_BoxCC->setObjectName(QString::fromUtf8("dateEdit_BoxCC"));
        dateEdit_BoxCC->setMaximumSize(QSize(140, 16777215));
        dateEdit_BoxCC->setStyleSheet(QString::fromUtf8("font: 75 15pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        dateEdit_BoxCC->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        dateEdit_BoxCC->setCalendarPopup(true);
        dateEdit_BoxCC->setDate(QDate(1900, 1, 1));

        gridLayout_9->addWidget(dateEdit_BoxCC, 0, 4, 1, 1);

        label_8 = new QLabel(tab_Ephor1);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMaximumSize(QSize(80, 16777215));
        label_8->setStyleSheet(QString::fromUtf8("font: 75 15pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(41, 136, 41);"));
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_9->addWidget(label_8, 0, 5, 1, 1);

        dateEdit_BoxZB = new QDateEdit(tab_Ephor1);
        dateEdit_BoxZB->setObjectName(QString::fromUtf8("dateEdit_BoxZB"));
        dateEdit_BoxZB->setMaximumSize(QSize(140, 16777215));
        dateEdit_BoxZB->setStyleSheet(QString::fromUtf8("font: 75 15pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        dateEdit_BoxZB->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        dateEdit_BoxZB->setCalendarPopup(true);
        dateEdit_BoxZB->setDate(QDate(1900, 1, 1));

        gridLayout_9->addWidget(dateEdit_BoxZB, 0, 6, 1, 1);

        pushButton_QueryBox = new QPushButton(tab_Ephor1);
        pushButton_QueryBox->setObjectName(QString::fromUtf8("pushButton_QueryBox"));
        pushButton_QueryBox->setMinimumSize(QSize(75, 30));
        pushButton_QueryBox->setMaximumSize(QSize(75, 30));
        pushButton_QueryBox->setStyleSheet(QString::fromUtf8("font: 75 15pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"background-color: rgb(41, 136, 41);\n"
"color: rgb(255, 255, 255);"));

        gridLayout_9->addWidget(pushButton_QueryBox, 0, 7, 1, 1);


        gridLayout_10->addLayout(gridLayout_9, 0, 2, 1, 1);

        tableWidget_Box = new QTableWidget(tab_Ephor1);
        tableWidget_Box->setObjectName(QString::fromUtf8("tableWidget_Box"));
        tableWidget_Box->setSortingEnabled(true);

        gridLayout_10->addWidget(tableWidget_Box, 1, 0, 1, 3);

        tabWidget_Storage->addTab(tab_Ephor1, QString());
        tab_Ephor2 = new QWidget();
        tab_Ephor2->setObjectName(QString::fromUtf8("tab_Ephor2"));
        gridLayout_12 = new QGridLayout(tab_Ephor2);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        pushButton_AddSinglePacked = new QPushButton(tab_Ephor2);
        pushButton_AddSinglePacked->setObjectName(QString::fromUtf8("pushButton_AddSinglePacked"));
        pushButton_AddSinglePacked->setMinimumSize(QSize(75, 30));
        pushButton_AddSinglePacked->setMaximumSize(QSize(75, 30));
        pushButton_AddSinglePacked->setStyleSheet(QString::fromUtf8("font: 75 15pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(255, 255, 0);\n"
"background-color: rgb(255, 0, 0);\n"
""));
        pushButton_AddSinglePacked->setFlat(false);

        gridLayout_12->addWidget(pushButton_AddSinglePacked, 0, 0, 1, 1);

        horizontalSpacer_13 = new QSpacerItem(63, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_12->addItem(horizontalSpacer_13, 0, 1, 1, 2);

        gridLayout_11 = new QGridLayout();
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        lineEdit_SingleWJH = new QLineEdit(tab_Ephor2);
        lineEdit_SingleWJH->setObjectName(QString::fromUtf8("lineEdit_SingleWJH"));
        lineEdit_SingleWJH->setMinimumSize(QSize(150, 30));
        lineEdit_SingleWJH->setMaximumSize(QSize(150, 30));
        lineEdit_SingleWJH->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout_11->addWidget(lineEdit_SingleWJH, 0, 0, 1, 1);

        lineEdit_SinglePZH = new QLineEdit(tab_Ephor2);
        lineEdit_SinglePZH->setObjectName(QString::fromUtf8("lineEdit_SinglePZH"));
        lineEdit_SinglePZH->setMinimumSize(QSize(150, 30));
        lineEdit_SinglePZH->setMaximumSize(QSize(150, 30));
        lineEdit_SinglePZH->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout_11->addWidget(lineEdit_SinglePZH, 0, 1, 1, 1);

        lineEdit_SingleDM = new QLineEdit(tab_Ephor2);
        lineEdit_SingleDM->setObjectName(QString::fromUtf8("lineEdit_SingleDM"));
        lineEdit_SingleDM->setMinimumSize(QSize(150, 30));
        lineEdit_SingleDM->setMaximumSize(QSize(150, 30));
        lineEdit_SingleDM->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout_11->addWidget(lineEdit_SingleDM, 0, 2, 1, 1);

        label_5 = new QLabel(tab_Ephor2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMaximumSize(QSize(80, 16777215));
        label_5->setStyleSheet(QString::fromUtf8("font: 75 15pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(41, 136, 41);"));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_11->addWidget(label_5, 0, 3, 1, 1);

        dateEdit_SingleCC = new QDateEdit(tab_Ephor2);
        dateEdit_SingleCC->setObjectName(QString::fromUtf8("dateEdit_SingleCC"));
        dateEdit_SingleCC->setMaximumSize(QSize(140, 16777215));
        dateEdit_SingleCC->setStyleSheet(QString::fromUtf8("font: 75 15pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        dateEdit_SingleCC->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        dateEdit_SingleCC->setCalendarPopup(true);
        dateEdit_SingleCC->setDate(QDate(1900, 1, 1));

        gridLayout_11->addWidget(dateEdit_SingleCC, 0, 4, 1, 1);

        label_6 = new QLabel(tab_Ephor2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMaximumSize(QSize(80, 16777215));
        label_6->setStyleSheet(QString::fromUtf8("font: 75 15pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(41, 136, 41);"));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_11->addWidget(label_6, 0, 5, 1, 1);

        dateEdit_SingleZB = new QDateEdit(tab_Ephor2);
        dateEdit_SingleZB->setObjectName(QString::fromUtf8("dateEdit_SingleZB"));
        dateEdit_SingleZB->setMaximumSize(QSize(140, 16777215));
        dateEdit_SingleZB->setStyleSheet(QString::fromUtf8("font: 75 15pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        dateEdit_SingleZB->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        dateEdit_SingleZB->setCalendarPopup(true);
        dateEdit_SingleZB->setDate(QDate(1900, 1, 1));

        gridLayout_11->addWidget(dateEdit_SingleZB, 0, 6, 1, 1);

        pushButton_QuerySinglePacked = new QPushButton(tab_Ephor2);
        pushButton_QuerySinglePacked->setObjectName(QString::fromUtf8("pushButton_QuerySinglePacked"));
        pushButton_QuerySinglePacked->setMinimumSize(QSize(75, 30));
        pushButton_QuerySinglePacked->setMaximumSize(QSize(75, 30));
        pushButton_QuerySinglePacked->setStyleSheet(QString::fromUtf8("font: 75 15pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"background-color: rgb(41, 136, 41);\n"
"color: rgb(255, 255, 255);"));

        gridLayout_11->addWidget(pushButton_QuerySinglePacked, 0, 7, 1, 1);


        gridLayout_12->addLayout(gridLayout_11, 0, 3, 1, 1);

        tableWidget_Single = new QTableWidget(tab_Ephor2);
        tableWidget_Single->setObjectName(QString::fromUtf8("tableWidget_Single"));
        tableWidget_Single->setSortingEnabled(true);

        gridLayout_12->addWidget(tableWidget_Single, 1, 0, 1, 4);

        pushButton_PrintSinglePacked = new QPushButton(tab_Ephor2);
        pushButton_PrintSinglePacked->setObjectName(QString::fromUtf8("pushButton_PrintSinglePacked"));
        pushButton_PrintSinglePacked->setMinimumSize(QSize(141, 30));
        pushButton_PrintSinglePacked->setMaximumSize(QSize(141, 30));
        pushButton_PrintSinglePacked->setStyleSheet(QString::fromUtf8("font: 75 15pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(41, 136, 41);"));

        gridLayout_12->addWidget(pushButton_PrintSinglePacked, 2, 0, 1, 2);

        horizontalSpacer_5 = new QSpacerItem(1539, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_12->addItem(horizontalSpacer_5, 2, 2, 1, 2);

        tabWidget_Storage->addTab(tab_Ephor2, QString());

        gridLayout->addWidget(tabWidget_Storage, 0, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        formLayout_2 = new QFormLayout(tab_3);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        tabWidget_Information = new QTabWidget(tab_3);
        tabWidget_Information->setObjectName(QString::fromUtf8("tabWidget_Information"));
        tabWidget_Information->setTabShape(QTabWidget::Triangular);
        tab_Info1 = new QWidget();
        tab_Info1->setObjectName(QString::fromUtf8("tab_Info1"));
        formLayout = new QFormLayout(tab_Info1);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        pushButton_ExportExcel = new QPushButton(tab_Info1);
        pushButton_ExportExcel->setObjectName(QString::fromUtf8("pushButton_ExportExcel"));
        pushButton_ExportExcel->setMinimumSize(QSize(100, 30));
        pushButton_ExportExcel->setMaximumSize(QSize(100, 30));
        pushButton_ExportExcel->setStyleSheet(QString::fromUtf8("font: 75 15pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(0, 170, 0);"));

        horizontalLayout_12->addWidget(pushButton_ExportExcel);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lineEdit_BFWenJianHao = new QLineEdit(tab_Info1);
        lineEdit_BFWenJianHao->setObjectName(QString::fromUtf8("lineEdit_BFWenJianHao"));
        lineEdit_BFWenJianHao->setMinimumSize(QSize(130, 30));
        lineEdit_BFWenJianHao->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout->addWidget(lineEdit_BFWenJianHao);

        lineEdit_DBPingZhengHao = new QLineEdit(tab_Info1);
        lineEdit_DBPingZhengHao->setObjectName(QString::fromUtf8("lineEdit_DBPingZhengHao"));
        lineEdit_DBPingZhengHao->setMinimumSize(QSize(130, 30));
        lineEdit_DBPingZhengHao->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout->addWidget(lineEdit_DBPingZhengHao);

        lineEdit_XZDanHao = new QLineEdit(tab_Info1);
        lineEdit_XZDanHao->setObjectName(QString::fromUtf8("lineEdit_XZDanHao"));
        lineEdit_XZDanHao->setMinimumSize(QSize(130, 30));
        lineEdit_XZDanHao->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout->addWidget(lineEdit_XZDanHao);

        lineEdit_ZBDaima = new QLineEdit(tab_Info1);
        lineEdit_ZBDaima->setObjectName(QString::fromUtf8("lineEdit_ZBDaima"));
        lineEdit_ZBDaima->setMinimumSize(QSize(130, 30));
        lineEdit_ZBDaima->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout->addWidget(lineEdit_ZBDaima);

        lineEdit_ZBMingCheng = new QLineEdit(tab_Info1);
        lineEdit_ZBMingCheng->setObjectName(QString::fromUtf8("lineEdit_ZBMingCheng"));
        lineEdit_ZBMingCheng->setMinimumSize(QSize(130, 30));
        lineEdit_ZBMingCheng->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout->addWidget(lineEdit_ZBMingCheng);

        lineEdit_DZBianHao = new QLineEdit(tab_Info1);
        lineEdit_DZBianHao->setObjectName(QString::fromUtf8("lineEdit_DZBianHao"));
        lineEdit_DZBianHao->setMinimumSize(QSize(130, 30));
        lineEdit_DZBianHao->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout->addWidget(lineEdit_DZBianHao);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_12 = new QLabel(tab_Info1);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setMaximumSize(QSize(80, 16777215));
        label_12->setStyleSheet(QString::fromUtf8("font: 75 15pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(41, 136, 41);"));
        label_12->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_12);

        dateEdit_InfoRK = new QDateEdit(tab_Info1);
        dateEdit_InfoRK->setObjectName(QString::fromUtf8("dateEdit_InfoRK"));
        dateEdit_InfoRK->setMaximumSize(QSize(140, 16777215));
        dateEdit_InfoRK->setStyleSheet(QString::fromUtf8("font: 75 15pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        dateEdit_InfoRK->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        dateEdit_InfoRK->setCalendarPopup(true);
        dateEdit_InfoRK->setDate(QDate(1900, 1, 1));

        horizontalLayout_3->addWidget(dateEdit_InfoRK);

        label = new QLabel(tab_Info1);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_3->addWidget(label);

        dateEdit_InfoRK_end = new QDateEdit(tab_Info1);
        dateEdit_InfoRK_end->setObjectName(QString::fromUtf8("dateEdit_InfoRK_end"));
        dateEdit_InfoRK_end->setMaximumSize(QSize(140, 16777215));
        dateEdit_InfoRK_end->setStyleSheet(QString::fromUtf8("font: 75 15pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        dateEdit_InfoRK_end->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        dateEdit_InfoRK_end->setCalendarPopup(true);
        dateEdit_InfoRK_end->setDate(QDate(1900, 1, 1));

        horizontalLayout_3->addWidget(dateEdit_InfoRK_end);


        horizontalLayout_11->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_13 = new QLabel(tab_Info1);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setMaximumSize(QSize(80, 16777215));
        label_13->setStyleSheet(QString::fromUtf8("font: 75 15pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(41, 136, 41);"));
        label_13->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(label_13);

        dateEdit_InfoJS = new QDateEdit(tab_Info1);
        dateEdit_InfoJS->setObjectName(QString::fromUtf8("dateEdit_InfoJS"));
        dateEdit_InfoJS->setMaximumSize(QSize(140, 16777215));
        dateEdit_InfoJS->setStyleSheet(QString::fromUtf8("font: 75 15pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        dateEdit_InfoJS->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        dateEdit_InfoJS->setCalendarPopup(true);
        dateEdit_InfoJS->setDate(QDate(1900, 1, 1));

        horizontalLayout_4->addWidget(dateEdit_InfoJS);

        label_2 = new QLabel(tab_Info1);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_4->addWidget(label_2);

        dateEdit_InfoJS_end = new QDateEdit(tab_Info1);
        dateEdit_InfoJS_end->setObjectName(QString::fromUtf8("dateEdit_InfoJS_end"));
        dateEdit_InfoJS_end->setMaximumSize(QSize(140, 16777215));
        dateEdit_InfoJS_end->setStyleSheet(QString::fromUtf8("font: 75 15pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        dateEdit_InfoJS_end->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        dateEdit_InfoJS_end->setCalendarPopup(true);
        dateEdit_InfoJS_end->setDate(QDate(1900, 1, 1));

        horizontalLayout_4->addWidget(dateEdit_InfoJS_end);


        horizontalLayout_11->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_11 = new QLabel(tab_Info1);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setMaximumSize(QSize(80, 16777215));
        label_11->setStyleSheet(QString::fromUtf8("font: 75 15pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(41, 136, 41);"));
        label_11->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(label_11);

        dateEdit_InfoCK = new QDateEdit(tab_Info1);
        dateEdit_InfoCK->setObjectName(QString::fromUtf8("dateEdit_InfoCK"));
        dateEdit_InfoCK->setMaximumSize(QSize(140, 16777215));
        dateEdit_InfoCK->setStyleSheet(QString::fromUtf8("font: 75 15pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        dateEdit_InfoCK->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        dateEdit_InfoCK->setCalendarPopup(true);
        dateEdit_InfoCK->setDate(QDate(1900, 1, 1));

        horizontalLayout_5->addWidget(dateEdit_InfoCK);

        label_3 = new QLabel(tab_Info1);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_5->addWidget(label_3);

        dateEdit_InfoCK_end = new QDateEdit(tab_Info1);
        dateEdit_InfoCK_end->setObjectName(QString::fromUtf8("dateEdit_InfoCK_end"));
        dateEdit_InfoCK_end->setMaximumSize(QSize(140, 16777215));
        dateEdit_InfoCK_end->setStyleSheet(QString::fromUtf8("font: 75 15pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        dateEdit_InfoCK_end->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        dateEdit_InfoCK_end->setCalendarPopup(true);
        dateEdit_InfoCK_end->setDate(QDate(1900, 1, 1));

        horizontalLayout_5->addWidget(dateEdit_InfoCK_end);


        horizontalLayout_11->addLayout(horizontalLayout_5);


        verticalLayout->addLayout(horizontalLayout_11);


        horizontalLayout_12->addLayout(verticalLayout);

        pushButton_QueryInfo = new QPushButton(tab_Info1);
        pushButton_QueryInfo->setObjectName(QString::fromUtf8("pushButton_QueryInfo"));
        pushButton_QueryInfo->setMinimumSize(QSize(75, 30));
        pushButton_QueryInfo->setMaximumSize(QSize(75, 30));
        pushButton_QueryInfo->setStyleSheet(QString::fromUtf8("font: 75 15pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"background-color: rgb(41, 136, 41);\n"
"color: rgb(255, 255, 255);"));

        horizontalLayout_12->addWidget(pushButton_QueryInfo);


        verticalLayout_2->addLayout(horizontalLayout_12);

        tableWidget_Search = new QTableWidget(tab_Info1);
        tableWidget_Search->setObjectName(QString::fromUtf8("tableWidget_Search"));
        tableWidget_Search->setSortingEnabled(true);

        verticalLayout_2->addWidget(tableWidget_Search);


        formLayout->setLayout(0, QFormLayout::SpanningRole, verticalLayout_2);

        label_29 = new QLabel(tab_Info1);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setMinimumSize(QSize(80, 30));
        label_29->setMaximumSize(QSize(80, 30));
        label_29->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(85, 170, 0);"));

        formLayout->setWidget(1, QFormLayout::FieldRole, label_29);

        tabWidget_Information->addTab(tab_Info1, QString());
        tab_Info2 = new QWidget();
        tab_Info2->setObjectName(QString::fromUtf8("tab_Info2"));
        gridLayout_13 = new QGridLayout(tab_Info2);
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        pushButton_Deliver = new QPushButton(tab_Info2);
        pushButton_Deliver->setObjectName(QString::fromUtf8("pushButton_Deliver"));
        pushButton_Deliver->setMinimumSize(QSize(75, 30));
        pushButton_Deliver->setMaximumSize(QSize(75, 30));
        pushButton_Deliver->setStyleSheet(QString::fromUtf8("font: 75 15pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(255, 255, 0);\n"
"background-color: rgb(255, 0, 0);\n"
""));
        pushButton_Deliver->setFlat(false);

        gridLayout_13->addWidget(pushButton_Deliver, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);

        lineEdit_DeliveryBFWenJianHao = new QLineEdit(tab_Info2);
        lineEdit_DeliveryBFWenJianHao->setObjectName(QString::fromUtf8("lineEdit_DeliveryBFWenJianHao"));
        lineEdit_DeliveryBFWenJianHao->setMinimumSize(QSize(200, 30));
        lineEdit_DeliveryBFWenJianHao->setMaximumSize(QSize(200, 30));
        lineEdit_DeliveryBFWenJianHao->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout_2->addWidget(lineEdit_DeliveryBFWenJianHao);

        lineEdit_DeliveryDBPingZhengHao = new QLineEdit(tab_Info2);
        lineEdit_DeliveryDBPingZhengHao->setObjectName(QString::fromUtf8("lineEdit_DeliveryDBPingZhengHao"));
        lineEdit_DeliveryDBPingZhengHao->setMinimumSize(QSize(200, 30));
        lineEdit_DeliveryDBPingZhengHao->setMaximumSize(QSize(200, 30));
        lineEdit_DeliveryDBPingZhengHao->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout_2->addWidget(lineEdit_DeliveryDBPingZhengHao);

        lineEdit_DeliveryXZDanHao = new QLineEdit(tab_Info2);
        lineEdit_DeliveryXZDanHao->setObjectName(QString::fromUtf8("lineEdit_DeliveryXZDanHao"));
        lineEdit_DeliveryXZDanHao->setMinimumSize(QSize(200, 30));
        lineEdit_DeliveryXZDanHao->setMaximumSize(QSize(200, 30));
        lineEdit_DeliveryXZDanHao->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout_2->addWidget(lineEdit_DeliveryXZDanHao);

        lineEdit_DeliveryZBDaima = new QLineEdit(tab_Info2);
        lineEdit_DeliveryZBDaima->setObjectName(QString::fromUtf8("lineEdit_DeliveryZBDaima"));
        lineEdit_DeliveryZBDaima->setMinimumSize(QSize(200, 30));
        lineEdit_DeliveryZBDaima->setMaximumSize(QSize(200, 30));
        lineEdit_DeliveryZBDaima->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout_2->addWidget(lineEdit_DeliveryZBDaima);

        lineEdit_DeliveryZBMingCheng = new QLineEdit(tab_Info2);
        lineEdit_DeliveryZBMingCheng->setObjectName(QString::fromUtf8("lineEdit_DeliveryZBMingCheng"));
        lineEdit_DeliveryZBMingCheng->setMinimumSize(QSize(200, 30));
        lineEdit_DeliveryZBMingCheng->setMaximumSize(QSize(200, 30));
        lineEdit_DeliveryZBMingCheng->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout_2->addWidget(lineEdit_DeliveryZBMingCheng);

        label_10 = new QLabel(tab_Info2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setMaximumSize(QSize(80, 16777215));
        label_10->setStyleSheet(QString::fromUtf8("font: 75 15pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(41, 136, 41);"));
        label_10->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_10);

        dateEdit_DeliveryCC = new QDateEdit(tab_Info2);
        dateEdit_DeliveryCC->setObjectName(QString::fromUtf8("dateEdit_DeliveryCC"));
        dateEdit_DeliveryCC->setMaximumSize(QSize(140, 16777215));
        dateEdit_DeliveryCC->setStyleSheet(QString::fromUtf8("font: 75 15pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        dateEdit_DeliveryCC->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        dateEdit_DeliveryCC->setCalendarPopup(true);
        dateEdit_DeliveryCC->setDate(QDate(1900, 1, 1));

        horizontalLayout_2->addWidget(dateEdit_DeliveryCC);

        label_9 = new QLabel(tab_Info2);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setMaximumSize(QSize(80, 16777215));
        label_9->setStyleSheet(QString::fromUtf8("font: 75 15pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(41, 136, 41);"));
        label_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_9);

        dateEdit_DeliveryZB = new QDateEdit(tab_Info2);
        dateEdit_DeliveryZB->setObjectName(QString::fromUtf8("dateEdit_DeliveryZB"));
        dateEdit_DeliveryZB->setMaximumSize(QSize(140, 16777215));
        dateEdit_DeliveryZB->setStyleSheet(QString::fromUtf8("font: 75 15pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        dateEdit_DeliveryZB->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        dateEdit_DeliveryZB->setCalendarPopup(true);
        dateEdit_DeliveryZB->setDate(QDate(1900, 1, 1));

        horizontalLayout_2->addWidget(dateEdit_DeliveryZB);

        pushButton_QueryDeliver = new QPushButton(tab_Info2);
        pushButton_QueryDeliver->setObjectName(QString::fromUtf8("pushButton_QueryDeliver"));
        pushButton_QueryDeliver->setMinimumSize(QSize(75, 30));
        pushButton_QueryDeliver->setMaximumSize(QSize(75, 30));
        pushButton_QueryDeliver->setStyleSheet(QString::fromUtf8("font: 75 15pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"background-color: rgb(41, 136, 41);\n"
"color: rgb(255, 255, 255);"));

        horizontalLayout_2->addWidget(pushButton_QueryDeliver);


        gridLayout_13->addLayout(horizontalLayout_2, 0, 1, 1, 1);

        tableWidget_Delivery = new QTableWidget(tab_Info2);
        tableWidget_Delivery->setObjectName(QString::fromUtf8("tableWidget_Delivery"));
        tableWidget_Delivery->setSortingEnabled(true);

        gridLayout_13->addWidget(tableWidget_Delivery, 1, 0, 1, 2);

        tabWidget_Information->addTab(tab_Info2, QString());

        formLayout_2->setWidget(0, QFormLayout::SpanningRole, tabWidget_Information);

        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        gridLayout_5 = new QGridLayout(tab_4);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        tableWidget_PackedInfo = new QTableWidget(tab_4);
        tableWidget_PackedInfo->setObjectName(QString::fromUtf8("tableWidget_PackedInfo"));

        gridLayout_5->addWidget(tableWidget_PackedInfo, 0, 0, 1, 4);

        pushButton_16 = new QPushButton(tab_4);
        pushButton_16->setObjectName(QString::fromUtf8("pushButton_16"));
        pushButton_16->setMinimumSize(QSize(141, 30));
        pushButton_16->setMaximumSize(QSize(141, 30));
        pushButton_16->setStyleSheet(QString::fromUtf8("font: 75 15pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(41, 136, 41);"));

        gridLayout_5->addWidget(pushButton_16, 1, 0, 1, 2);

        horizontalSpacer_12 = new QSpacerItem(959, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_12, 1, 2, 1, 1);

        pushButton_25 = new QPushButton(tab_4);
        pushButton_25->setObjectName(QString::fromUtf8("pushButton_25"));
        pushButton_25->setMinimumSize(QSize(75, 30));
        pushButton_25->setMaximumSize(QSize(75, 30));
        pushButton_25->setStyleSheet(QString::fromUtf8("font: 75 15pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout_5->addWidget(pushButton_25, 1, 3, 1, 1);

        tabWidget->addTab(tab_4, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout_8 = new QGridLayout(tab);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_6 = new QGridLayout(groupBox);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        label_Image2 = new MyLabel(groupBox);
        label_Image2->setObjectName(QString::fromUtf8("label_Image2"));
        label_Image2->setStyleSheet(QString::fromUtf8("background-image: url(:/SysMainWindow/Resources/background.png);"));

        gridLayout_6->addWidget(label_Image2, 0, 2, 1, 2);

        pushButton_CodeGrab = new QPushButton(groupBox);
        pushButton_CodeGrab->setObjectName(QString::fromUtf8("pushButton_CodeGrab"));
        pushButton_CodeGrab->setMinimumSize(QSize(100, 30));
        pushButton_CodeGrab->setMaximumSize(QSize(100, 30));
        pushButton_CodeGrab->setStyleSheet(QString::fromUtf8("font: 75 15pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(255, 255, 0);\n"
"background-color: rgb(255, 0, 0);\n"
""));
        pushButton_CodeGrab->setFlat(false);

        gridLayout_6->addWidget(pushButton_CodeGrab, 1, 0, 1, 1);

        label_Image1 = new MyLabel(groupBox);
        label_Image1->setObjectName(QString::fromUtf8("label_Image1"));
        label_Image1->setStyleSheet(QString::fromUtf8("background-image: url(:/SysMainWindow/Resources/background.png);"));

        gridLayout_6->addWidget(label_Image1, 0, 0, 1, 2);

        horizontalSpacer_3 = new QSpacerItem(603, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_3, 1, 1, 1, 2);

        pushButton_GunGrab = new QPushButton(groupBox);
        pushButton_GunGrab->setObjectName(QString::fromUtf8("pushButton_GunGrab"));
        pushButton_GunGrab->setMinimumSize(QSize(100, 30));
        pushButton_GunGrab->setMaximumSize(QSize(100, 30));
        pushButton_GunGrab->setStyleSheet(QString::fromUtf8("font: 75 15pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(255, 255, 0);\n"
"background-color: rgb(255, 0, 0);\n"
""));
        pushButton_GunGrab->setFlat(false);

        gridLayout_6->addWidget(pushButton_GunGrab, 1, 3, 1, 1);


        gridLayout_8->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(tab);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(346, 0));
        groupBox_2->setMaximumSize(QSize(346, 16777215));
        gridLayout_7 = new QGridLayout(groupBox_2);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        label_26 = new QLabel(groupBox_2);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setMinimumSize(QSize(80, 30));
        label_26->setMaximumSize(QSize(80, 30));
        label_26->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(85, 170, 0);"));

        gridLayout_7->addWidget(label_26, 0, 0, 1, 1);

        lineEdit_Ocr = new QLineEdit(groupBox_2);
        lineEdit_Ocr->setObjectName(QString::fromUtf8("lineEdit_Ocr"));
        lineEdit_Ocr->setMinimumSize(QSize(150, 30));
        lineEdit_Ocr->setMaximumSize(QSize(500, 30));
        lineEdit_Ocr->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lineEdit_Ocr->setReadOnly(true);

        gridLayout_7->addWidget(lineEdit_Ocr, 0, 1, 1, 4);

        pushButton_Speaker = new QPushButton(groupBox_2);
        pushButton_Speaker->setObjectName(QString::fromUtf8("pushButton_Speaker"));
        pushButton_Speaker->setMinimumSize(QSize(30, 30));
        pushButton_Speaker->setStyleSheet(QString::fromUtf8("image: url(:/SysMainWindow/Resources/speaker.png);"));

        gridLayout_7->addWidget(pushButton_Speaker, 0, 5, 1, 1);

        label_27 = new QLabel(groupBox_2);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setMinimumSize(QSize(80, 30));
        label_27->setMaximumSize(QSize(80, 30));
        label_27->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(85, 170, 0);"));

        gridLayout_7->addWidget(label_27, 1, 0, 1, 1);

        lineEdit_XiuZheng = new QLineEdit(groupBox_2);
        lineEdit_XiuZheng->setObjectName(QString::fromUtf8("lineEdit_XiuZheng"));
        lineEdit_XiuZheng->setMinimumSize(QSize(150, 30));
        lineEdit_XiuZheng->setMaximumSize(QSize(500, 30));
        lineEdit_XiuZheng->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout_7->addWidget(lineEdit_XiuZheng, 1, 1, 1, 5);

        checkBox_QiangGuan = new QCheckBox(groupBox_2);
        checkBox_QiangGuan->setObjectName(QString::fromUtf8("checkBox_QiangGuan"));
        checkBox_QiangGuan->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(85, 170, 0);"));

        gridLayout_7->addWidget(checkBox_QiangGuan, 2, 0, 1, 1);

        lineEdit_QiangGuan = new QLineEdit(groupBox_2);
        lineEdit_QiangGuan->setObjectName(QString::fromUtf8("lineEdit_QiangGuan"));
        lineEdit_QiangGuan->setMinimumSize(QSize(150, 30));
        lineEdit_QiangGuan->setMaximumSize(QSize(500, 30));
        lineEdit_QiangGuan->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout_7->addWidget(lineEdit_QiangGuan, 2, 2, 1, 4);

        checkBox_QiangJi = new QCheckBox(groupBox_2);
        checkBox_QiangJi->setObjectName(QString::fromUtf8("checkBox_QiangJi"));
        checkBox_QiangJi->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(85, 170, 0);"));

        gridLayout_7->addWidget(checkBox_QiangJi, 3, 0, 1, 2);

        lineEdit_QiangJi = new QLineEdit(groupBox_2);
        lineEdit_QiangJi->setObjectName(QString::fromUtf8("lineEdit_QiangJi"));
        lineEdit_QiangJi->setMinimumSize(QSize(150, 30));
        lineEdit_QiangJi->setMaximumSize(QSize(500, 30));
        lineEdit_QiangJi->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout_7->addWidget(lineEdit_QiangJi, 3, 2, 1, 4);

        checkBox_QiangKuang = new QCheckBox(groupBox_2);
        checkBox_QiangKuang->setObjectName(QString::fromUtf8("checkBox_QiangKuang"));
        checkBox_QiangKuang->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(85, 170, 0);"));

        gridLayout_7->addWidget(checkBox_QiangKuang, 4, 0, 1, 2);

        lineEdit_QiangKuang = new QLineEdit(groupBox_2);
        lineEdit_QiangKuang->setObjectName(QString::fromUtf8("lineEdit_QiangKuang"));
        lineEdit_QiangKuang->setMinimumSize(QSize(150, 30));
        lineEdit_QiangKuang->setMaximumSize(QSize(500, 30));
        lineEdit_QiangKuang->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout_7->addWidget(lineEdit_QiangKuang, 4, 2, 1, 4);

        checkBox_BeiFen = new QCheckBox(groupBox_2);
        checkBox_BeiFen->setObjectName(QString::fromUtf8("checkBox_BeiFen"));
        checkBox_BeiFen->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(85, 170, 0);"));

        gridLayout_7->addWidget(checkBox_BeiFen, 5, 0, 1, 2);

        lineEdit_BeiFen = new QLineEdit(groupBox_2);
        lineEdit_BeiFen->setObjectName(QString::fromUtf8("lineEdit_BeiFen"));
        lineEdit_BeiFen->setMinimumSize(QSize(150, 30));
        lineEdit_BeiFen->setMaximumSize(QSize(500, 30));
        lineEdit_BeiFen->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout_7->addWidget(lineEdit_BeiFen, 5, 2, 1, 4);

        label_28 = new QLabel(groupBox_2);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setMinimumSize(QSize(80, 30));
        label_28->setMaximumSize(QSize(100, 30));
        label_28->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(85, 170, 0);"));

        gridLayout_7->addWidget(label_28, 6, 0, 1, 2);

        label_DanHao = new QLabel(groupBox_2);
        label_DanHao->setObjectName(QString::fromUtf8("label_DanHao"));
        label_DanHao->setMinimumSize(QSize(80, 30));
        label_DanHao->setMaximumSize(QSize(200, 30));
        label_DanHao->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(0, 0, 0);"));

        gridLayout_7->addWidget(label_DanHao, 6, 2, 1, 2);

        pushButton_Save = new QPushButton(groupBox_2);
        pushButton_Save->setObjectName(QString::fromUtf8("pushButton_Save"));
        pushButton_Save->setMinimumSize(QSize(75, 30));
        pushButton_Save->setMaximumSize(QSize(75, 30));
        pushButton_Save->setStyleSheet(QString::fromUtf8("font: 75 15pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(0, 170, 0);"));

        gridLayout_7->addWidget(pushButton_Save, 7, 0, 1, 1);

        pushButton_Modify = new QPushButton(groupBox_2);
        pushButton_Modify->setObjectName(QString::fromUtf8("pushButton_Modify"));
        pushButton_Modify->setMinimumSize(QSize(75, 30));
        pushButton_Modify->setMaximumSize(QSize(75, 30));
        pushButton_Modify->setStyleSheet(QString::fromUtf8("font: 75 15pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(255, 0, 0);"));

        gridLayout_7->addWidget(pushButton_Modify, 7, 1, 1, 2);

        horizontalSpacer_2 = new QSpacerItem(76, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_7->addItem(horizontalSpacer_2, 7, 3, 1, 1);

        pushButton_26 = new QPushButton(groupBox_2);
        pushButton_26->setObjectName(QString::fromUtf8("pushButton_26"));
        pushButton_26->setMinimumSize(QSize(75, 30));
        pushButton_26->setMaximumSize(QSize(75, 30));
        pushButton_26->setStyleSheet(QString::fromUtf8("font: 75 15pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout_7->addWidget(pushButton_26, 7, 4, 1, 2);


        gridLayout_8->addWidget(groupBox_2, 0, 1, 1, 1);

        tabWidget->addTab(tab, QString());

        gridLayout_4->addWidget(tabWidget, 0, 0, 1, 1);

        QWidget::setTabOrder(lineEdit_Name, lineEdit_OfficerNumber);
        QWidget::setTabOrder(lineEdit_OfficerNumber, pushButton_QueryUser);
        QWidget::setTabOrder(pushButton_QueryUser, tableWidget_User);
        QWidget::setTabOrder(tableWidget_User, tabWidget_Storage);
        QWidget::setTabOrder(tabWidget_Storage, pushButton_AddBox);
        QWidget::setTabOrder(pushButton_AddBox, lineEdit_WenJianHao);
        QWidget::setTabOrder(lineEdit_WenJianHao, lineEdit_PingZhengHao);
        QWidget::setTabOrder(lineEdit_PingZhengHao, lineEdit_ZhuangXiangDanHao);
        QWidget::setTabOrder(lineEdit_ZhuangXiangDanHao, dateEdit_BoxCC);
        QWidget::setTabOrder(dateEdit_BoxCC, dateEdit_BoxZB);
        QWidget::setTabOrder(dateEdit_BoxZB, pushButton_QueryBox);
        QWidget::setTabOrder(pushButton_QueryBox, tableWidget_Box);
        QWidget::setTabOrder(tableWidget_Box, pushButton_AddSinglePacked);
        QWidget::setTabOrder(pushButton_AddSinglePacked, lineEdit_SingleWJH);
        QWidget::setTabOrder(lineEdit_SingleWJH, lineEdit_SinglePZH);
        QWidget::setTabOrder(lineEdit_SinglePZH, lineEdit_SingleDM);
        QWidget::setTabOrder(lineEdit_SingleDM, dateEdit_SingleCC);
        QWidget::setTabOrder(dateEdit_SingleCC, dateEdit_SingleZB);
        QWidget::setTabOrder(dateEdit_SingleZB, pushButton_QuerySinglePacked);
        QWidget::setTabOrder(pushButton_QuerySinglePacked, tableWidget_Single);
        QWidget::setTabOrder(tableWidget_Single, pushButton_PrintSinglePacked);
        QWidget::setTabOrder(pushButton_PrintSinglePacked, tabWidget_Information);
        QWidget::setTabOrder(tabWidget_Information, pushButton_ExportExcel);
        QWidget::setTabOrder(pushButton_ExportExcel, lineEdit_BFWenJianHao);
        QWidget::setTabOrder(lineEdit_BFWenJianHao, lineEdit_DBPingZhengHao);
        QWidget::setTabOrder(lineEdit_DBPingZhengHao, lineEdit_XZDanHao);
        QWidget::setTabOrder(lineEdit_XZDanHao, lineEdit_ZBDaima);
        QWidget::setTabOrder(lineEdit_ZBDaima, lineEdit_ZBMingCheng);
        QWidget::setTabOrder(lineEdit_ZBMingCheng, lineEdit_DZBianHao);
        QWidget::setTabOrder(lineEdit_DZBianHao, dateEdit_InfoRK);
        QWidget::setTabOrder(dateEdit_InfoRK, dateEdit_InfoRK_end);
        QWidget::setTabOrder(dateEdit_InfoRK_end, dateEdit_InfoJS);
        QWidget::setTabOrder(dateEdit_InfoJS, dateEdit_InfoJS_end);
        QWidget::setTabOrder(dateEdit_InfoJS_end, dateEdit_InfoCK);
        QWidget::setTabOrder(dateEdit_InfoCK, dateEdit_InfoCK_end);
        QWidget::setTabOrder(dateEdit_InfoCK_end, pushButton_QueryInfo);
        QWidget::setTabOrder(pushButton_QueryInfo, lineEdit_DeliveryBFWenJianHao);
        QWidget::setTabOrder(lineEdit_DeliveryBFWenJianHao, lineEdit_DeliveryDBPingZhengHao);
        QWidget::setTabOrder(lineEdit_DeliveryDBPingZhengHao, lineEdit_DeliveryXZDanHao);
        QWidget::setTabOrder(lineEdit_DeliveryXZDanHao, lineEdit_DeliveryZBDaima);
        QWidget::setTabOrder(lineEdit_DeliveryZBDaima, lineEdit_DeliveryZBMingCheng);
        QWidget::setTabOrder(lineEdit_DeliveryZBMingCheng, dateEdit_DeliveryCC);
        QWidget::setTabOrder(dateEdit_DeliveryCC, dateEdit_DeliveryZB);
        QWidget::setTabOrder(dateEdit_DeliveryZB, pushButton_QueryDeliver);
        QWidget::setTabOrder(pushButton_QueryDeliver, tableWidget_Delivery);
        QWidget::setTabOrder(tableWidget_Delivery, tableWidget_PackedInfo);
        QWidget::setTabOrder(tableWidget_PackedInfo, pushButton_16);
        QWidget::setTabOrder(pushButton_16, pushButton_25);
        QWidget::setTabOrder(pushButton_25, pushButton_CodeGrab);
        QWidget::setTabOrder(pushButton_CodeGrab, pushButton_GunGrab);
        QWidget::setTabOrder(pushButton_GunGrab, lineEdit_Ocr);
        QWidget::setTabOrder(lineEdit_Ocr, pushButton_Speaker);
        QWidget::setTabOrder(pushButton_Speaker, lineEdit_XiuZheng);
        QWidget::setTabOrder(lineEdit_XiuZheng, checkBox_QiangGuan);
        QWidget::setTabOrder(checkBox_QiangGuan, lineEdit_QiangGuan);
        QWidget::setTabOrder(lineEdit_QiangGuan, checkBox_QiangJi);
        QWidget::setTabOrder(checkBox_QiangJi, lineEdit_QiangJi);
        QWidget::setTabOrder(lineEdit_QiangJi, checkBox_QiangKuang);
        QWidget::setTabOrder(checkBox_QiangKuang, lineEdit_QiangKuang);
        QWidget::setTabOrder(lineEdit_QiangKuang, checkBox_BeiFen);
        QWidget::setTabOrder(checkBox_BeiFen, lineEdit_BeiFen);
        QWidget::setTabOrder(lineEdit_BeiFen, pushButton_Save);
        QWidget::setTabOrder(pushButton_Save, pushButton_Modify);
        QWidget::setTabOrder(pushButton_Modify, pushButton_26);
        QWidget::setTabOrder(pushButton_26, pushButton_Deliver);
        QWidget::setTabOrder(pushButton_Deliver, tabWidget);
        QWidget::setTabOrder(tabWidget, tableWidget_Search);
        QWidget::setTabOrder(tableWidget_Search, pushButton_AddUser);

        retranslateUi(SystemManager);
        QObject::connect(pushButton_AddUser, SIGNAL(clicked()), SystemManager, SLOT(AddUser()));
        QObject::connect(pushButton_QueryUser, SIGNAL(clicked()), SystemManager, SLOT(QueryUserInfo()));
        QObject::connect(pushButton_AddBox, SIGNAL(clicked()), SystemManager, SLOT(AddBoxPacked()));
        QObject::connect(pushButton_QueryBox, SIGNAL(clicked()), SystemManager, SLOT(QueryBoxPacked()));
        QObject::connect(pushButton_25, SIGNAL(clicked()), SystemManager, SLOT(BoxDetailsReturn()));
        QObject::connect(pushButton_26, SIGNAL(clicked()), SystemManager, SLOT(ImageGrabberReturn()));
        QObject::connect(pushButton_AddSinglePacked, SIGNAL(clicked()), SystemManager, SLOT(AddSinglePacked()));
        QObject::connect(pushButton_QuerySinglePacked, SIGNAL(clicked()), SystemManager, SLOT(QuerySinglePacked()));
        QObject::connect(pushButton_PrintSinglePacked, SIGNAL(clicked()), SystemManager, SLOT(PrintSinglePacked()));
        QObject::connect(pushButton_16, SIGNAL(clicked()), SystemManager, SLOT(PrintBoxList()));
        QObject::connect(pushButton_QueryInfo, SIGNAL(clicked()), SystemManager, SLOT(QueryInformations()));
        QObject::connect(pushButton_CodeGrab, SIGNAL(clicked()), SystemManager, SLOT(SoftTriggerCodeCamera()));
        QObject::connect(pushButton_GunGrab, SIGNAL(clicked()), SystemManager, SLOT(SoftTriggerWholeCamera()));
        QObject::connect(pushButton_ExportExcel, SIGNAL(clicked()), SystemManager, SLOT(ExportExcel()));
        QObject::connect(pushButton_QueryDeliver, SIGNAL(clicked()), SystemManager, SLOT(QueryDeliveryInformations()));
        QObject::connect(pushButton_Deliver, SIGNAL(clicked()), SystemManager, SLOT(DoDelivery()));
        QObject::connect(pushButton_Save, SIGNAL(clicked()), SystemManager, SLOT(SaveRecognizeResult()));
        QObject::connect(pushButton_Modify, SIGNAL(clicked()), SystemManager, SLOT(DoCorrection()));
        QObject::connect(pushButton_Speaker, SIGNAL(clicked()), SystemManager, SLOT(DoSpeaker()));

        tabWidget->setCurrentIndex(2);
        tabWidget_Storage->setCurrentIndex(0);
        tabWidget_Information->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(SystemManager);
    } // setupUi

    void retranslateUi(QDialog *SystemManager)
    {
        SystemManager->setWindowTitle(QCoreApplication::translate("SystemManager", "\346\236\252\346\224\257\344\277\241\346\201\257\346\231\272\350\203\275\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));
        pushButton_AddUser->setText(QCoreApplication::translate("SystemManager", "\346\226\260\345\273\272", nullptr));
        lineEdit_Name->setPlaceholderText(QCoreApplication::translate("SystemManager", "\345\247\223\345\220\215", nullptr));
        lineEdit_OfficerNumber->setPlaceholderText(QCoreApplication::translate("SystemManager", "\345\206\233\345\256\230\350\257\201\345\217\267", nullptr));
        pushButton_QueryUser->setText(QCoreApplication::translate("SystemManager", "\346\237\245\350\257\242", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_1), QCoreApplication::translate("SystemManager", "\350\264\246\345\217\267\347\256\241\347\220\206", nullptr));
        pushButton_AddBox->setText(QCoreApplication::translate("SystemManager", "\346\226\260\345\273\272", nullptr));
        lineEdit_WenJianHao->setPlaceholderText(QCoreApplication::translate("SystemManager", "\351\200\200\345\275\271\346\212\245\345\272\237\346\226\207\344\273\266\345\217\267", nullptr));
        lineEdit_PingZhengHao->setPlaceholderText(QCoreApplication::translate("SystemManager", "\350\260\203\346\213\250\345\207\255\350\257\201\345\217\267", nullptr));
        lineEdit_ZhuangXiangDanHao->setPlaceholderText(QCoreApplication::translate("SystemManager", "\350\243\205\347\256\261\345\215\225\345\217\267", nullptr));
        label_7->setText(QCoreApplication::translate("SystemManager", "\345\207\272\345\216\202\346\227\266\351\227\264", nullptr));
        label_8->setText(QCoreApplication::translate("SystemManager", "\350\243\205\345\244\207\346\227\266\351\227\264", nullptr));
        pushButton_QueryBox->setText(QCoreApplication::translate("SystemManager", "\346\237\245\350\257\242", nullptr));
        tabWidget_Storage->setTabText(tabWidget_Storage->indexOf(tab_Ephor1), QCoreApplication::translate("SystemManager", "\347\256\261\350\243\205\345\205\245\345\272\223", nullptr));
        pushButton_AddSinglePacked->setText(QCoreApplication::translate("SystemManager", "\346\226\260\345\273\272", nullptr));
        lineEdit_SingleWJH->setPlaceholderText(QCoreApplication::translate("SystemManager", "\351\200\200\345\275\271\346\212\245\345\272\237\346\226\207\344\273\266\345\217\267", nullptr));
        lineEdit_SinglePZH->setPlaceholderText(QCoreApplication::translate("SystemManager", "\350\260\203\346\213\250\345\207\255\350\257\201\345\217\267", nullptr));
        lineEdit_SingleDM->setPlaceholderText(QCoreApplication::translate("SystemManager", "\350\243\205\345\244\207\344\273\243\347\240\201", nullptr));
        label_5->setText(QCoreApplication::translate("SystemManager", "\345\207\272\345\216\202\346\227\266\351\227\264", nullptr));
        label_6->setText(QCoreApplication::translate("SystemManager", "\350\243\205\345\244\207\346\227\266\351\227\264", nullptr));
        pushButton_QuerySinglePacked->setText(QCoreApplication::translate("SystemManager", "\346\237\245\350\257\242", nullptr));
        pushButton_PrintSinglePacked->setText(QCoreApplication::translate("SystemManager", "\346\211\223\345\215\260\345\215\225\350\243\205\345\215\241\347\211\207", nullptr));
        tabWidget_Storage->setTabText(tabWidget_Storage->indexOf(tab_Ephor2), QCoreApplication::translate("SystemManager", "\345\215\225\350\243\205\345\205\245\345\272\223", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("SystemManager", "\347\274\226\347\240\201\346\243\200\350\247\206", nullptr));
        pushButton_ExportExcel->setText(QCoreApplication::translate("SystemManager", "\345\257\274\345\207\272Excel", nullptr));
        lineEdit_BFWenJianHao->setPlaceholderText(QCoreApplication::translate("SystemManager", "\351\200\200\345\275\271\346\212\245\345\272\237\346\226\207\344\273\266\345\217\267", nullptr));
        lineEdit_DBPingZhengHao->setPlaceholderText(QCoreApplication::translate("SystemManager", "\350\260\203\346\213\250\345\207\255\350\257\201\345\217\267", nullptr));
        lineEdit_XZDanHao->setPlaceholderText(QCoreApplication::translate("SystemManager", "\350\243\205\347\256\261\345\215\225\345\217\267", nullptr));
        lineEdit_ZBDaima->setPlaceholderText(QCoreApplication::translate("SystemManager", "\350\243\205\345\244\207\344\273\243\347\240\201", nullptr));
        lineEdit_ZBMingCheng->setPlaceholderText(QCoreApplication::translate("SystemManager", "\350\243\205\345\244\207\345\220\215\347\247\260", nullptr));
        lineEdit_DZBianHao->setText(QString());
        lineEdit_DZBianHao->setPlaceholderText(QCoreApplication::translate("SystemManager", "\345\215\225\350\243\205\347\274\226\345\217\267", nullptr));
        label_12->setText(QCoreApplication::translate("SystemManager", "\345\205\245\345\272\223\346\227\266\351\227\264", nullptr));
        label->setText(QCoreApplication::translate("SystemManager", "\342\200\224\342\200\224", nullptr));
        label_13->setText(QCoreApplication::translate("SystemManager", "\346\243\200\350\247\206\346\227\266\351\227\264", nullptr));
        label_2->setText(QCoreApplication::translate("SystemManager", "\342\200\224\342\200\224", nullptr));
        label_11->setText(QCoreApplication::translate("SystemManager", "\345\207\272\345\272\223\346\227\266\351\227\264", nullptr));
        label_3->setText(QCoreApplication::translate("SystemManager", "\342\200\224\342\200\224", nullptr));
        pushButton_QueryInfo->setText(QCoreApplication::translate("SystemManager", "\346\237\245\350\257\242", nullptr));
        label_29->setText(QString());
        tabWidget_Information->setTabText(tabWidget_Information->indexOf(tab_Info1), QCoreApplication::translate("SystemManager", "\346\237\245\350\257\242", nullptr));
        pushButton_Deliver->setText(QCoreApplication::translate("SystemManager", "\345\207\272\345\272\223", nullptr));
        lineEdit_DeliveryBFWenJianHao->setPlaceholderText(QCoreApplication::translate("SystemManager", "\351\200\200\345\275\271\346\212\245\345\272\237\346\226\207\344\273\266\345\217\267", nullptr));
        lineEdit_DeliveryDBPingZhengHao->setPlaceholderText(QCoreApplication::translate("SystemManager", "\350\260\203\346\213\250\345\207\255\350\257\201\345\217\267", nullptr));
        lineEdit_DeliveryXZDanHao->setPlaceholderText(QCoreApplication::translate("SystemManager", "\350\243\205\347\256\261\345\215\225\345\217\267", nullptr));
        lineEdit_DeliveryZBDaima->setPlaceholderText(QCoreApplication::translate("SystemManager", "\350\243\205\345\244\207\344\273\243\347\240\201", nullptr));
        lineEdit_DeliveryZBMingCheng->setPlaceholderText(QCoreApplication::translate("SystemManager", "\350\243\205\345\244\207\345\220\215\347\247\260", nullptr));
        label_10->setText(QCoreApplication::translate("SystemManager", "\345\207\272\345\216\202\346\227\266\351\227\264", nullptr));
        label_9->setText(QCoreApplication::translate("SystemManager", "\350\243\205\345\244\207\346\227\266\351\227\264", nullptr));
        pushButton_QueryDeliver->setText(QCoreApplication::translate("SystemManager", "\346\237\245\350\257\242", nullptr));
        tabWidget_Information->setTabText(tabWidget_Information->indexOf(tab_Info2), QCoreApplication::translate("SystemManager", "\345\207\272\345\272\223", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("SystemManager", "\344\277\241\346\201\257\347\256\241\347\220\206", nullptr));
        pushButton_16->setText(QCoreApplication::translate("SystemManager", "\346\211\223\345\215\260\350\243\205\347\256\261\346\270\205\345\215\225", nullptr));
        pushButton_25->setText(QCoreApplication::translate("SystemManager", "\350\277\224\345\233\236", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("SystemManager", "\350\243\205\347\256\261\344\277\241\346\201\257", nullptr));
        groupBox->setTitle(QString());
        label_Image2->setText(QString());
        pushButton_CodeGrab->setText(QCoreApplication::translate("SystemManager", "\347\274\226\347\240\201\346\213\215\347\205\247", nullptr));
        label_Image1->setText(QString());
        pushButton_GunGrab->setText(QCoreApplication::translate("SystemManager", "\346\225\264\346\236\252\346\213\215\347\205\247", nullptr));
        groupBox_2->setTitle(QString());
        label_26->setText(QCoreApplication::translate("SystemManager", "\345\233\276\345\203\217\350\257\206\345\210\253", nullptr));
        lineEdit_Ocr->setPlaceholderText(QString());
        pushButton_Speaker->setText(QString());
        label_27->setText(QCoreApplication::translate("SystemManager", "\344\272\272\345\267\245\344\277\256\346\255\243", nullptr));
        lineEdit_XiuZheng->setPlaceholderText(QString());
        checkBox_QiangGuan->setText(QCoreApplication::translate("SystemManager", "\346\236\252   \347\256\241", nullptr));
        lineEdit_QiangGuan->setPlaceholderText(QString());
        checkBox_QiangJi->setText(QCoreApplication::translate("SystemManager", "\346\236\252\346\234\272/\345\245\227\347\255\222", nullptr));
        lineEdit_QiangJi->setPlaceholderText(QString());
        checkBox_QiangKuang->setText(QCoreApplication::translate("SystemManager", "\346\234\272 \346\236\252 \346\241\206", nullptr));
        lineEdit_QiangKuang->setPlaceholderText(QString());
        checkBox_BeiFen->setText(QCoreApplication::translate("SystemManager", "\345\244\207\344\273\275\346\236\252\347\256\241", nullptr));
        lineEdit_BeiFen->setPlaceholderText(QString());
        label_28->setText(QCoreApplication::translate("SystemManager", "\350\243\205\347\256\261\345\215\225\345\217\267\357\274\232", nullptr));
        label_DanHao->setText(QString());
        pushButton_Save->setText(QCoreApplication::translate("SystemManager", "\344\277\235\345\255\230", nullptr));
        pushButton_Modify->setText(QCoreApplication::translate("SystemManager", "\344\277\256\346\255\243", nullptr));
        pushButton_26->setText(QCoreApplication::translate("SystemManager", "\350\277\224\345\233\236", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("SystemManager", "\346\213\215\347\205\247-\346\243\200\350\247\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SystemManager: public Ui_SystemManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSTEMMANAGER_H
