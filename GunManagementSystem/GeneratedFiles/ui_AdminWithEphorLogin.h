/********************************************************************************
** Form generated from reading UI file 'AdminWithEphorLogin.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINWITHEPHORLOGIN_H
#define UI_ADMINWITHEPHORLOGIN_H

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

class Ui_AdminWithEphorLogin
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_3;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_2;
    QGridLayout *gridLayout_2;
    QLabel *label_3;
    QLineEdit *lineEdit_Operator;
    QLabel *label_6;
    QLineEdit *lineEdit_Ephor;
    QLabel *label_4;
    QLineEdit *lineEdit_OperatorPwd;
    QLabel *label_5;
    QLineEdit *lineEdit_EphorPwd;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_Login;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QDialog *AdminWithEphorLogin)
    {
        if (AdminWithEphorLogin->objectName().isEmpty())
            AdminWithEphorLogin->setObjectName(QString::fromUtf8("AdminWithEphorLogin"));
        AdminWithEphorLogin->resize(669, 379);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/SysMainWindow/Resources/login-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        AdminWithEphorLogin->setWindowIcon(icon);
        gridLayout = new QGridLayout(AdminWithEphorLogin);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox = new QGroupBox(AdminWithEphorLogin);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(651, 361));
        groupBox->setMaximumSize(QSize(651, 361));
        groupBox->setStyleSheet(QString::fromUtf8("background-color: rgb(84, 130, 53);"));
        gridLayout_3 = new QGridLayout(groupBox);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalSpacer = new QSpacerItem(236, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 0, 0, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(141, 135));
        label_2->setMaximumSize(QSize(141, 135));
        label_2->setStyleSheet(QString::fromUtf8("image: url(:/SysMainWindow/Resources/81logo.png);"));

        gridLayout_3->addWidget(label_2, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(236, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 0, 2, 1, 1);

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

        lineEdit_Operator = new QLineEdit(groupBox);
        lineEdit_Operator->setObjectName(QString::fromUtf8("lineEdit_Operator"));
        sizePolicy.setHeightForWidth(lineEdit_Operator->sizePolicy().hasHeightForWidth());
        lineEdit_Operator->setSizePolicy(sizePolicy);
        lineEdit_Operator->setMinimumSize(QSize(171, 30));
        lineEdit_Operator->setMaximumSize(QSize(171, 30));
        lineEdit_Operator->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout_2->addWidget(lineEdit_Operator, 0, 1, 1, 1);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);
        label_6->setMinimumSize(QSize(61, 25));
        label_6->setMaximumSize(QSize(61, 25));
        label_6->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(255, 255, 255);"));

        gridLayout_2->addWidget(label_6, 0, 2, 1, 1);

        lineEdit_Ephor = new QLineEdit(groupBox);
        lineEdit_Ephor->setObjectName(QString::fromUtf8("lineEdit_Ephor"));
        sizePolicy.setHeightForWidth(lineEdit_Ephor->sizePolicy().hasHeightForWidth());
        lineEdit_Ephor->setSizePolicy(sizePolicy);
        lineEdit_Ephor->setMinimumSize(QSize(171, 30));
        lineEdit_Ephor->setMaximumSize(QSize(171, 30));
        lineEdit_Ephor->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout_2->addWidget(lineEdit_Ephor, 0, 3, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        label_4->setMinimumSize(QSize(61, 25));
        label_4->setMaximumSize(QSize(61, 25));
        label_4->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(255, 255, 255);"));

        gridLayout_2->addWidget(label_4, 1, 0, 1, 1);

        lineEdit_OperatorPwd = new QLineEdit(groupBox);
        lineEdit_OperatorPwd->setObjectName(QString::fromUtf8("lineEdit_OperatorPwd"));
        sizePolicy.setHeightForWidth(lineEdit_OperatorPwd->sizePolicy().hasHeightForWidth());
        lineEdit_OperatorPwd->setSizePolicy(sizePolicy);
        lineEdit_OperatorPwd->setMinimumSize(QSize(171, 30));
        lineEdit_OperatorPwd->setMaximumSize(QSize(171, 30));
        lineEdit_OperatorPwd->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lineEdit_OperatorPwd->setEchoMode(QLineEdit::Password);

        gridLayout_2->addWidget(lineEdit_OperatorPwd, 1, 1, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);
        label_5->setMinimumSize(QSize(61, 25));
        label_5->setMaximumSize(QSize(61, 25));
        label_5->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(255, 255, 255);"));

        gridLayout_2->addWidget(label_5, 1, 2, 1, 1);

        lineEdit_EphorPwd = new QLineEdit(groupBox);
        lineEdit_EphorPwd->setObjectName(QString::fromUtf8("lineEdit_EphorPwd"));
        sizePolicy.setHeightForWidth(lineEdit_EphorPwd->sizePolicy().hasHeightForWidth());
        lineEdit_EphorPwd->setSizePolicy(sizePolicy);
        lineEdit_EphorPwd->setMinimumSize(QSize(171, 30));
        lineEdit_EphorPwd->setMaximumSize(QSize(171, 30));
        lineEdit_EphorPwd->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lineEdit_EphorPwd->setEchoMode(QLineEdit::Password);

        gridLayout_2->addWidget(lineEdit_EphorPwd, 1, 3, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 1, 0, 1, 3);

        horizontalSpacer_3 = new QSpacerItem(236, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_3, 2, 0, 1, 1);

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

        gridLayout_3->addWidget(pushButton_Login, 2, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(236, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_4, 2, 2, 1, 1);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);

        QWidget::setTabOrder(lineEdit_Operator, lineEdit_OperatorPwd);
        QWidget::setTabOrder(lineEdit_OperatorPwd, lineEdit_Ephor);
        QWidget::setTabOrder(lineEdit_Ephor, lineEdit_EphorPwd);
        QWidget::setTabOrder(lineEdit_EphorPwd, pushButton_Login);

        retranslateUi(AdminWithEphorLogin);
        QObject::connect(pushButton_Login, SIGNAL(clicked()), AdminWithEphorLogin, SLOT(slotLogin()));

        QMetaObject::connectSlotsByName(AdminWithEphorLogin);
    } // setupUi

    void retranslateUi(QDialog *AdminWithEphorLogin)
    {
        AdminWithEphorLogin->setWindowTitle(QCoreApplication::translate("AdminWithEphorLogin", "\350\272\253\344\273\275\351\252\214\350\257\201", nullptr));
        groupBox->setTitle(QString());
        label_2->setText(QString());
        label_3->setText(QCoreApplication::translate("AdminWithEphorLogin", "<html><head/><body><p>\346\223\215\344\275\234\345\221\230</p></body></html>", nullptr));
        lineEdit_Operator->setText(QString());
        label_6->setText(QCoreApplication::translate("AdminWithEphorLogin", "<html><head/><body><p>\347\233\221\347\235\243\345\221\230</p></body></html>", nullptr));
        lineEdit_Ephor->setText(QString());
        label_4->setText(QCoreApplication::translate("AdminWithEphorLogin", "<html><head/><body><p>\345\257\206\347\240\201<br/></p></body></html>", nullptr));
        lineEdit_OperatorPwd->setText(QString());
        label_5->setText(QCoreApplication::translate("AdminWithEphorLogin", "<html><head/><body><p>\345\257\206\347\240\201<br/></p></body></html>", nullptr));
        lineEdit_EphorPwd->setText(QString());
        pushButton_Login->setText(QCoreApplication::translate("AdminWithEphorLogin", "\347\231\273 \345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminWithEphorLogin: public Ui_AdminWithEphorLogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINWITHEPHORLOGIN_H
