/********************************************************************************
** Form generated from reading UI file 'ParameterSettings.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARAMETERSETTINGS_H
#define UI_PARAMETERSETTINGS_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_ParameterSetting
{
public:
    QGroupBox *groupBox;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout;
    QLabel *label_23;
    QComboBox *comboBox_Camera1;
    QPushButton *pushButton_OpenCamera1;
    QRadioButton *radioButton_FreeRun1;
    QRadioButton *radioButton_SoftTrigger1;
    QRadioButton *radioButton_ExternalTrigger1;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_3;
    QComboBox *comboBox_Camera2;
    QLabel *label_24;
    QRadioButton *radioButton_SoftTrigger2;
    QRadioButton *radioButton_FreeRun2;
    QRadioButton *radioButton_ExternalTrigger2;
    QPushButton *pushButton_OpenCamera2;
    QGroupBox *groupBox_5;
    QPushButton *pushButton_SaveImagePath;
    QLabel *label_25;
    QLineEdit *lineEdit_SaveImagePath;
    QCheckBox *checkBox_Debug;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_Login;
    QLineEdit *lineEdit_UserName;
    QLineEdit *lineEdit_Password;
    QLineEdit *lineEdit_DatabaseName;
    QPushButton *pushButton_SaveConfig;
    QLabel *label_Info;

    void setupUi(QDialog *ParameterSetting)
    {
        if (ParameterSetting->objectName().isEmpty())
            ParameterSetting->setObjectName(QString::fromUtf8("ParameterSetting"));
        ParameterSetting->resize(831, 347);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/SysMainWindow/Resources/settings.ico"), QSize(), QIcon::Normal, QIcon::Off);
        ParameterSetting->setWindowIcon(icon);
        groupBox = new QGroupBox(ParameterSetting);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(9, 65, 810, 211));
        groupBox_3 = new QGroupBox(groupBox);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 10, 790, 62));
        gridLayout = new QGridLayout(groupBox_3);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_23 = new QLabel(groupBox_3);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setMinimumSize(QSize(80, 30));
        label_23->setMaximumSize(QSize(80, 30));
        label_23->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout->addWidget(label_23, 0, 0, 1, 1);

        comboBox_Camera1 = new QComboBox(groupBox_3);
        comboBox_Camera1->setObjectName(QString::fromUtf8("comboBox_Camera1"));
        comboBox_Camera1->setMinimumSize(QSize(300, 30));
        comboBox_Camera1->setMaximumSize(QSize(300, 30));
        comboBox_Camera1->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(85, 170, 0);"));

        gridLayout->addWidget(comboBox_Camera1, 0, 1, 1, 1);

        pushButton_OpenCamera1 = new QPushButton(groupBox_3);
        pushButton_OpenCamera1->setObjectName(QString::fromUtf8("pushButton_OpenCamera1"));
        pushButton_OpenCamera1->setMinimumSize(QSize(100, 30));
        pushButton_OpenCamera1->setMaximumSize(QSize(100, 30));
        pushButton_OpenCamera1->setStyleSheet(QString::fromUtf8("font: 75 15pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout->addWidget(pushButton_OpenCamera1, 0, 2, 1, 1);

        radioButton_FreeRun1 = new QRadioButton(groupBox_3);
        radioButton_FreeRun1->setObjectName(QString::fromUtf8("radioButton_FreeRun1"));
        radioButton_FreeRun1->setMinimumSize(QSize(100, 30));
        radioButton_FreeRun1->setMaximumSize(QSize(100, 30));
        radioButton_FreeRun1->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(85, 170, 0);"));

        gridLayout->addWidget(radioButton_FreeRun1, 0, 3, 1, 1);

        radioButton_SoftTrigger1 = new QRadioButton(groupBox_3);
        radioButton_SoftTrigger1->setObjectName(QString::fromUtf8("radioButton_SoftTrigger1"));
        radioButton_SoftTrigger1->setMinimumSize(QSize(80, 30));
        radioButton_SoftTrigger1->setMaximumSize(QSize(80, 30));
        radioButton_SoftTrigger1->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(85, 170, 0);"));

        gridLayout->addWidget(radioButton_SoftTrigger1, 0, 4, 1, 1);

        radioButton_ExternalTrigger1 = new QRadioButton(groupBox_3);
        radioButton_ExternalTrigger1->setObjectName(QString::fromUtf8("radioButton_ExternalTrigger1"));
        radioButton_ExternalTrigger1->setMinimumSize(QSize(80, 30));
        radioButton_ExternalTrigger1->setMaximumSize(QSize(80, 30));
        radioButton_ExternalTrigger1->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(85, 170, 0);"));

        gridLayout->addWidget(radioButton_ExternalTrigger1, 0, 5, 1, 1);

        groupBox_4 = new QGroupBox(groupBox);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(10, 78, 790, 62));
        gridLayout_3 = new QGridLayout(groupBox_4);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        comboBox_Camera2 = new QComboBox(groupBox_4);
        comboBox_Camera2->setObjectName(QString::fromUtf8("comboBox_Camera2"));
        comboBox_Camera2->setMinimumSize(QSize(300, 30));
        comboBox_Camera2->setMaximumSize(QSize(300, 30));
        comboBox_Camera2->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(85, 170, 0);"));

        gridLayout_3->addWidget(comboBox_Camera2, 0, 1, 1, 1);

        label_24 = new QLabel(groupBox_4);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setMinimumSize(QSize(80, 30));
        label_24->setMaximumSize(QSize(80, 30));
        label_24->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout_3->addWidget(label_24, 0, 0, 1, 1);

        radioButton_SoftTrigger2 = new QRadioButton(groupBox_4);
        radioButton_SoftTrigger2->setObjectName(QString::fromUtf8("radioButton_SoftTrigger2"));
        radioButton_SoftTrigger2->setMinimumSize(QSize(80, 30));
        radioButton_SoftTrigger2->setMaximumSize(QSize(80, 30));
        radioButton_SoftTrigger2->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(85, 170, 0);"));

        gridLayout_3->addWidget(radioButton_SoftTrigger2, 0, 4, 1, 1);

        radioButton_FreeRun2 = new QRadioButton(groupBox_4);
        radioButton_FreeRun2->setObjectName(QString::fromUtf8("radioButton_FreeRun2"));
        radioButton_FreeRun2->setMinimumSize(QSize(100, 30));
        radioButton_FreeRun2->setMaximumSize(QSize(100, 30));
        radioButton_FreeRun2->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(85, 170, 0);"));

        gridLayout_3->addWidget(radioButton_FreeRun2, 0, 3, 1, 1);

        radioButton_ExternalTrigger2 = new QRadioButton(groupBox_4);
        radioButton_ExternalTrigger2->setObjectName(QString::fromUtf8("radioButton_ExternalTrigger2"));
        radioButton_ExternalTrigger2->setMinimumSize(QSize(80, 30));
        radioButton_ExternalTrigger2->setMaximumSize(QSize(80, 30));
        radioButton_ExternalTrigger2->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(85, 170, 0);"));

        gridLayout_3->addWidget(radioButton_ExternalTrigger2, 0, 5, 1, 1);

        pushButton_OpenCamera2 = new QPushButton(groupBox_4);
        pushButton_OpenCamera2->setObjectName(QString::fromUtf8("pushButton_OpenCamera2"));
        pushButton_OpenCamera2->setMinimumSize(QSize(100, 30));
        pushButton_OpenCamera2->setMaximumSize(QSize(100, 30));
        pushButton_OpenCamera2->setStyleSheet(QString::fromUtf8("font: 75 15pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout_3->addWidget(pushButton_OpenCamera2, 0, 2, 1, 1);

        groupBox_5 = new QGroupBox(groupBox);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(10, 140, 790, 62));
        pushButton_SaveImagePath = new QPushButton(groupBox_5);
        pushButton_SaveImagePath->setObjectName(QString::fromUtf8("pushButton_SaveImagePath"));
        pushButton_SaveImagePath->setGeometry(QRect(402, 20, 100, 30));
        pushButton_SaveImagePath->setMinimumSize(QSize(100, 30));
        pushButton_SaveImagePath->setMaximumSize(QSize(100, 30));
        pushButton_SaveImagePath->setStyleSheet(QString::fromUtf8("font: 75 15pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        label_25 = new QLabel(groupBox_5);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(10, 20, 80, 30));
        label_25->setMinimumSize(QSize(80, 30));
        label_25->setMaximumSize(QSize(80, 30));
        label_25->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lineEdit_SaveImagePath = new QLineEdit(groupBox_5);
        lineEdit_SaveImagePath->setObjectName(QString::fromUtf8("lineEdit_SaveImagePath"));
        lineEdit_SaveImagePath->setGeometry(QRect(96, 19, 300, 31));
        checkBox_Debug = new QCheckBox(ParameterSetting);
        checkBox_Debug->setObjectName(QString::fromUtf8("checkBox_Debug"));
        checkBox_Debug->setGeometry(QRect(614, 310, 99, 29));
        checkBox_Debug->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(85, 170, 0);"));
        groupBox_2 = new QGroupBox(ParameterSetting);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(9, 9, 648, 50));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        pushButton_Login = new QPushButton(groupBox_2);
        pushButton_Login->setObjectName(QString::fromUtf8("pushButton_Login"));
        pushButton_Login->setMinimumSize(QSize(100, 30));
        pushButton_Login->setMaximumSize(QSize(100, 30));
        pushButton_Login->setStyleSheet(QString::fromUtf8("font: 75 15pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(0, 170, 0);"));

        gridLayout_2->addWidget(pushButton_Login, 0, 3, 1, 1);

        lineEdit_UserName = new QLineEdit(groupBox_2);
        lineEdit_UserName->setObjectName(QString::fromUtf8("lineEdit_UserName"));
        lineEdit_UserName->setMinimumSize(QSize(170, 30));
        lineEdit_UserName->setMaximumSize(QSize(170, 30));
        lineEdit_UserName->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout_2->addWidget(lineEdit_UserName, 0, 1, 1, 1);

        lineEdit_Password = new QLineEdit(groupBox_2);
        lineEdit_Password->setObjectName(QString::fromUtf8("lineEdit_Password"));
        lineEdit_Password->setMinimumSize(QSize(170, 30));
        lineEdit_Password->setMaximumSize(QSize(170, 30));
        lineEdit_Password->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lineEdit_Password->setEchoMode(QLineEdit::Password);

        gridLayout_2->addWidget(lineEdit_Password, 0, 2, 1, 1);

        lineEdit_DatabaseName = new QLineEdit(groupBox_2);
        lineEdit_DatabaseName->setObjectName(QString::fromUtf8("lineEdit_DatabaseName"));
        lineEdit_DatabaseName->setMinimumSize(QSize(170, 30));
        lineEdit_DatabaseName->setMaximumSize(QSize(170, 30));
        lineEdit_DatabaseName->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout_2->addWidget(lineEdit_DatabaseName, 0, 0, 1, 1);

        pushButton_SaveConfig = new QPushButton(ParameterSetting);
        pushButton_SaveConfig->setObjectName(QString::fromUtf8("pushButton_SaveConfig"));
        pushButton_SaveConfig->setGeometry(QRect(719, 310, 100, 30));
        pushButton_SaveConfig->setMinimumSize(QSize(100, 30));
        pushButton_SaveConfig->setMaximumSize(QSize(100, 30));
        pushButton_SaveConfig->setStyleSheet(QString::fromUtf8("font: 75 15pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        label_Info = new QLabel(ParameterSetting);
        label_Info->setObjectName(QString::fromUtf8("label_Info"));
        label_Info->setGeometry(QRect(20, 280, 781, 30));
        label_Info->setMinimumSize(QSize(60, 30));
        label_Info->setMaximumSize(QSize(1000, 30));
        label_Info->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 0);"));

        retranslateUi(ParameterSetting);
        QObject::connect(pushButton_Login, SIGNAL(clicked()), ParameterSetting, SLOT(ConnectDatabase()));
        QObject::connect(pushButton_OpenCamera1, SIGNAL(clicked()), ParameterSetting, SLOT(Camera1Controller()));
        QObject::connect(pushButton_OpenCamera2, SIGNAL(clicked()), ParameterSetting, SLOT(Camera2Controller()));
        QObject::connect(pushButton_SaveImagePath, SIGNAL(clicked()), ParameterSetting, SLOT(BrowseSavePath()));
        QObject::connect(pushButton_SaveConfig, SIGNAL(clicked()), ParameterSetting, SLOT(SaveConfig()));

        QMetaObject::connectSlotsByName(ParameterSetting);
    } // setupUi

    void retranslateUi(QDialog *ParameterSetting)
    {
        ParameterSetting->setWindowTitle(QCoreApplication::translate("ParameterSetting", "\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        groupBox->setTitle(QString());
        groupBox_3->setTitle(QCoreApplication::translate("ParameterSetting", "\347\274\226\347\240\201\346\213\215\347\205\247", nullptr));
        label_23->setText(QCoreApplication::translate("ParameterSetting", "\347\233\270\346\234\272\351\200\211\346\213\251", nullptr));
        pushButton_OpenCamera1->setText(QCoreApplication::translate("ParameterSetting", "\346\211\223\345\274\200\347\233\270\346\234\272", nullptr));
        radioButton_FreeRun1->setText(QCoreApplication::translate("ParameterSetting", "\350\207\252\347\224\261\351\207\207\351\233\206", nullptr));
        radioButton_SoftTrigger1->setText(QCoreApplication::translate("ParameterSetting", "\350\275\257\350\247\246\345\217\221", nullptr));
        radioButton_ExternalTrigger1->setText(QCoreApplication::translate("ParameterSetting", "\347\241\254\350\247\246\345\217\221", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("ParameterSetting", "\346\225\264\346\212\242\346\213\215\347\205\247", nullptr));
        label_24->setText(QCoreApplication::translate("ParameterSetting", "\347\233\270\346\234\272\351\200\211\346\213\251", nullptr));
        radioButton_SoftTrigger2->setText(QCoreApplication::translate("ParameterSetting", "\350\275\257\350\247\246\345\217\221", nullptr));
        radioButton_FreeRun2->setText(QCoreApplication::translate("ParameterSetting", "\350\207\252\347\224\261\351\207\207\351\233\206", nullptr));
        radioButton_ExternalTrigger2->setText(QCoreApplication::translate("ParameterSetting", "\347\241\254\350\247\246\345\217\221", nullptr));
        pushButton_OpenCamera2->setText(QCoreApplication::translate("ParameterSetting", "\346\211\223\345\274\200\347\233\270\346\234\272", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("ParameterSetting", "\345\255\230\345\202\250\345\233\276\347\211\207", nullptr));
        pushButton_SaveImagePath->setText(QCoreApplication::translate("ParameterSetting", "\346\265\217\350\247\210...", nullptr));
        label_25->setText(QCoreApplication::translate("ParameterSetting", "\345\233\276\345\203\217\350\267\257\345\276\204\357\274\232", nullptr));
        checkBox_Debug->setText(QCoreApplication::translate("ParameterSetting", "\350\260\203\350\257\225\346\250\241\345\274\217", nullptr));
        groupBox_2->setTitle(QString());
        pushButton_Login->setText(QCoreApplication::translate("ParameterSetting", "\347\231\273\345\275\225", nullptr));
        lineEdit_UserName->setText(QCoreApplication::translate("ParameterSetting", "11789", nullptr));
        lineEdit_UserName->setPlaceholderText(QCoreApplication::translate("ParameterSetting", "\347\224\250\346\210\267\345\220\215", nullptr));
        lineEdit_Password->setText(QCoreApplication::translate("ParameterSetting", "199512", nullptr));
        lineEdit_Password->setPlaceholderText(QCoreApplication::translate("ParameterSetting", "\345\257\206\347\240\201", nullptr));
        lineEdit_DatabaseName->setText(QCoreApplication::translate("ParameterSetting", "GunManager", nullptr));
        lineEdit_DatabaseName->setPlaceholderText(QCoreApplication::translate("ParameterSetting", "\346\225\260\346\215\256\345\272\223", nullptr));
        pushButton_SaveConfig->setText(QCoreApplication::translate("ParameterSetting", "\344\277\235\345\255\230\351\205\215\347\275\256", nullptr));
        label_Info->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ParameterSetting: public Ui_ParameterSetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARAMETERSETTINGS_H
