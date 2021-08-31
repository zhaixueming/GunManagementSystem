/********************************************************************************
** Form generated from reading UI file 'AdminLogin.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINLOGIN_H
#define UI_ADMINLOGIN_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_Admin_Login
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_3;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_5;
    QGridLayout *gridLayout_2;
    QLabel *label_3;
    QLineEdit *lineEdit_AdminPwd;
    QLineEdit *lineEdit_Admin;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_Login;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QDialog *Admin_Login)
    {
        if (Admin_Login->objectName().isEmpty())
            Admin_Login->setObjectName(QString::fromUtf8("Admin_Login"));
        Admin_Login->resize(669, 379);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/SysMainWindow/Resources/login-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        Admin_Login->setWindowIcon(icon);
        gridLayout = new QGridLayout(Admin_Login);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox = new QGroupBox(Admin_Login);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(651, 361));
        groupBox->setMaximumSize(QSize(651, 361));
        groupBox->setStyleSheet(QString::fromUtf8("background-color: rgb(84, 130, 53);"));
        gridLayout_3 = new QGridLayout(groupBox);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalSpacer = new QSpacerItem(236, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 0, 0, 1, 2);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(141, 135));
        label_2->setMaximumSize(QSize(141, 135));
        label_2->setStyleSheet(QString::fromUtf8("image: url(:/SysMainWindow/Resources/81logo.png);"));

        gridLayout_3->addWidget(label_2, 0, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(236, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 0, 3, 1, 2);

        horizontalSpacer_5 = new QSpacerItem(186, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_5, 1, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setMinimumSize(QSize(61, 25));
        label_3->setMaximumSize(QSize(61, 25));
        label_3->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(255, 255, 255);"));

        gridLayout_2->addWidget(label_3, 0, 0, 1, 1);

        lineEdit_AdminPwd = new QLineEdit(groupBox);
        lineEdit_AdminPwd->setObjectName(QString::fromUtf8("lineEdit_AdminPwd"));
        sizePolicy.setHeightForWidth(lineEdit_AdminPwd->sizePolicy().hasHeightForWidth());
        lineEdit_AdminPwd->setSizePolicy(sizePolicy);
        lineEdit_AdminPwd->setMinimumSize(QSize(171, 30));
        lineEdit_AdminPwd->setMaximumSize(QSize(171, 30));
        lineEdit_AdminPwd->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lineEdit_AdminPwd->setEchoMode(QLineEdit::Password);

        gridLayout_2->addWidget(lineEdit_AdminPwd, 1, 1, 1, 1);

        lineEdit_Admin = new QLineEdit(groupBox);
        lineEdit_Admin->setObjectName(QString::fromUtf8("lineEdit_Admin"));
        sizePolicy.setHeightForWidth(lineEdit_Admin->sizePolicy().hasHeightForWidth());
        lineEdit_Admin->setSizePolicy(sizePolicy);
        lineEdit_Admin->setMinimumSize(QSize(171, 30));
        lineEdit_Admin->setMaximumSize(QSize(171, 30));
        lineEdit_Admin->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout_2->addWidget(lineEdit_Admin, 0, 1, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        label_4->setMinimumSize(QSize(61, 25));
        label_4->setMaximumSize(QSize(61, 25));
        label_4->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(255, 255, 255);"));

        gridLayout_2->addWidget(label_4, 1, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 1, 1, 1, 3);

        horizontalSpacer_6 = new QSpacerItem(187, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_6, 1, 4, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(236, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_3, 2, 0, 1, 2);

        pushButton_Login = new QPushButton(groupBox);
        pushButton_Login->setObjectName(QString::fromUtf8("pushButton_Login"));
        pushButton_Login->setStyleSheet(QString::fromUtf8("font: 75 24pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(255, 255, 0);\n"
"background-color: rgb(255, 0, 0);\n"
""));
        pushButton_Login->setCheckable(false);
        pushButton_Login->setChecked(false);
        pushButton_Login->setAutoRepeat(true);
        pushButton_Login->setAutoExclusive(true);

        gridLayout_3->addWidget(pushButton_Login, 2, 2, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(236, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_4, 2, 3, 1, 2);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);

        QWidget::setTabOrder(lineEdit_Admin, lineEdit_AdminPwd);
        QWidget::setTabOrder(lineEdit_AdminPwd, pushButton_Login);

        retranslateUi(Admin_Login);
        QObject::connect(pushButton_Login, SIGNAL(clicked()), Admin_Login, SLOT(slotLogin()));

        QMetaObject::connectSlotsByName(Admin_Login);
    } // setupUi

    void retranslateUi(QDialog *Admin_Login)
    {
        Admin_Login->setWindowTitle(QCoreApplication::translate("Admin_Login", "\350\272\253\344\273\275\351\252\214\350\257\201", nullptr));
        groupBox->setTitle(QString());
        label_2->setText(QString());
        label_3->setText(QCoreApplication::translate("Admin_Login", "<html><head/><body><p>\347\256\241\347\220\206\345\221\230<br/></p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("Admin_Login", "<html><head/><body><p>\345\257\206\347\240\201<br/></p></body></html>", nullptr));
        pushButton_Login->setText(QCoreApplication::translate("Admin_Login", "\347\231\273 \345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Admin_Login: public Ui_Admin_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINLOGIN_H
