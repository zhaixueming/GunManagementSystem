/********************************************************************************
** Form generated from reading UI file 'SettingsLogin.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSLOGIN_H
#define UI_SETTINGSLOGIN_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SettingLogin
{
public:
    QGridLayout *gridLayout;
    QLabel *label_20;
    QLineEdit *lineEdit;
    QPushButton *pushButton_23;

    void setupUi(QDialog *SettingLogin)
    {
        if (SettingLogin->objectName().isEmpty())
            SettingLogin->setObjectName(QString::fromUtf8("SettingLogin"));
        SettingLogin->resize(420, 48);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/SysMainWindow/Resources/password.ico"), QSize(), QIcon::Normal, QIcon::Off);
        SettingLogin->setWindowIcon(icon);
        gridLayout = new QGridLayout(SettingLogin);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_20 = new QLabel(SettingLogin);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setMinimumSize(QSize(40, 30));
        label_20->setMaximumSize(QSize(40, 30));
        label_20->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout->addWidget(label_20, 0, 0, 1, 1);

        lineEdit = new QLineEdit(SettingLogin);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setMinimumSize(QSize(300, 30));
        lineEdit->setMaximumSize(QSize(300, 30));
        lineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lineEdit->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(lineEdit, 0, 1, 1, 1);

        pushButton_23 = new QPushButton(SettingLogin);
        pushButton_23->setObjectName(QString::fromUtf8("pushButton_23"));
        pushButton_23->setMinimumSize(QSize(50, 30));
        pushButton_23->setMaximumSize(QSize(50, 30));
        pushButton_23->setStyleSheet(QString::fromUtf8("font: 75 15pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(0, 170, 0);"));

        gridLayout->addWidget(pushButton_23, 0, 2, 1, 1);


        retranslateUi(SettingLogin);
        QObject::connect(pushButton_23, SIGNAL(clicked()), SettingLogin, SLOT(Login()));

        QMetaObject::connectSlotsByName(SettingLogin);
    } // setupUi

    void retranslateUi(QDialog *SettingLogin)
    {
        SettingLogin->setWindowTitle(QCoreApplication::translate("SettingLogin", "\345\217\243\344\273\244", nullptr));
        label_20->setText(QCoreApplication::translate("SettingLogin", "\345\217\243\344\273\244", nullptr));
        lineEdit->setPlaceholderText(QString());
        pushButton_23->setText(QCoreApplication::translate("SettingLogin", "\347\241\256\350\256\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingLogin: public Ui_SettingLogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSLOGIN_H
