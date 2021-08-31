/********************************************************************************
** Form generated from reading UI file 'UserManager.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERMANAGER_H
#define UI_USERMANAGER_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_UserManager
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_5;
    QCheckBox *checkBox_ShiBieCaoZuo;
    QSpacerItem *horizontalSpacer_4;
    QCheckBox *checkBox_ShiBieJianDu;
    QCheckBox *checkBox_RuKuCaoZuo;
    QCheckBox *checkBox_RuKuJianDu;
    QCheckBox *checkBox_ChuKuCaoZuo;
    QCheckBox *checkBox_ChuKuJianDu;
    QLabel *label_27;
    QLineEdit *lineEdit_XingMing;
    QLabel *label_29;
    QLineEdit *lineEdit_JunGuanZheng;
    QLabel *label_JiuMiMa;
    QLineEdit *lineEdit_JiuMiMa;
    QLabel *label_26;
    QLineEdit *lineEdit_MiMa;
    QLabel *label_28;
    QLineEdit *lineEdit_QueRenMiMa;
    QCheckBox *checkBox_XianShi;
    QCheckBox *checkBox_XiuGaiMiMa;
    QPushButton *pushButton_QueDing;

    void setupUi(QDialog *UserManager)
    {
        if (UserManager->objectName().isEmpty())
            UserManager->setObjectName(QString::fromUtf8("UserManager"));
        UserManager->resize(305, 368);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/SysMainWindow/Resources/login-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        UserManager->setWindowIcon(icon);
        gridLayout = new QGridLayout(UserManager);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox_3 = new QGroupBox(UserManager);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_5 = new QGridLayout(groupBox_3);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        checkBox_ShiBieCaoZuo = new QCheckBox(groupBox_3);
        checkBox_ShiBieCaoZuo->setObjectName(QString::fromUtf8("checkBox_ShiBieCaoZuo"));
        checkBox_ShiBieCaoZuo->setMinimumSize(QSize(100, 30));
        checkBox_ShiBieCaoZuo->setMaximumSize(QSize(100, 30));
        checkBox_ShiBieCaoZuo->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout_5->addWidget(checkBox_ShiBieCaoZuo, 0, 0, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(51, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_4, 0, 1, 1, 1);

        checkBox_ShiBieJianDu = new QCheckBox(groupBox_3);
        checkBox_ShiBieJianDu->setObjectName(QString::fromUtf8("checkBox_ShiBieJianDu"));
        checkBox_ShiBieJianDu->setMinimumSize(QSize(100, 30));
        checkBox_ShiBieJianDu->setMaximumSize(QSize(100, 30));
        checkBox_ShiBieJianDu->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout_5->addWidget(checkBox_ShiBieJianDu, 0, 2, 1, 1);

        checkBox_RuKuCaoZuo = new QCheckBox(groupBox_3);
        checkBox_RuKuCaoZuo->setObjectName(QString::fromUtf8("checkBox_RuKuCaoZuo"));
        checkBox_RuKuCaoZuo->setMinimumSize(QSize(100, 30));
        checkBox_RuKuCaoZuo->setMaximumSize(QSize(100, 30));
        checkBox_RuKuCaoZuo->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout_5->addWidget(checkBox_RuKuCaoZuo, 1, 0, 1, 1);

        checkBox_RuKuJianDu = new QCheckBox(groupBox_3);
        checkBox_RuKuJianDu->setObjectName(QString::fromUtf8("checkBox_RuKuJianDu"));
        checkBox_RuKuJianDu->setMinimumSize(QSize(100, 30));
        checkBox_RuKuJianDu->setMaximumSize(QSize(100, 30));
        checkBox_RuKuJianDu->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout_5->addWidget(checkBox_RuKuJianDu, 1, 2, 1, 1);

        checkBox_ChuKuCaoZuo = new QCheckBox(groupBox_3);
        checkBox_ChuKuCaoZuo->setObjectName(QString::fromUtf8("checkBox_ChuKuCaoZuo"));
        checkBox_ChuKuCaoZuo->setMinimumSize(QSize(100, 30));
        checkBox_ChuKuCaoZuo->setMaximumSize(QSize(100, 30));
        checkBox_ChuKuCaoZuo->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout_5->addWidget(checkBox_ChuKuCaoZuo, 2, 0, 1, 1);

        checkBox_ChuKuJianDu = new QCheckBox(groupBox_3);
        checkBox_ChuKuJianDu->setObjectName(QString::fromUtf8("checkBox_ChuKuJianDu"));
        checkBox_ChuKuJianDu->setMinimumSize(QSize(100, 30));
        checkBox_ChuKuJianDu->setMaximumSize(QSize(100, 30));
        checkBox_ChuKuJianDu->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout_5->addWidget(checkBox_ChuKuJianDu, 2, 2, 1, 1);


        gridLayout->addWidget(groupBox_3, 0, 0, 1, 4);

        label_27 = new QLabel(UserManager);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setMinimumSize(QSize(80, 30));
        label_27->setMaximumSize(QSize(70, 30));
        label_27->setLayoutDirection(Qt::LeftToRight);
        label_27->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(41, 136, 41);"));
        label_27->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_27, 1, 0, 1, 1);

        lineEdit_XingMing = new QLineEdit(UserManager);
        lineEdit_XingMing->setObjectName(QString::fromUtf8("lineEdit_XingMing"));
        lineEdit_XingMing->setMinimumSize(QSize(200, 30));
        lineEdit_XingMing->setMaximumSize(QSize(250, 30));
        lineEdit_XingMing->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lineEdit_XingMing->setReadOnly(false);

        gridLayout->addWidget(lineEdit_XingMing, 1, 1, 1, 3);

        label_29 = new QLabel(UserManager);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setMinimumSize(QSize(80, 30));
        label_29->setMaximumSize(QSize(70, 30));
        label_29->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(41, 136, 41);"));
        label_29->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_29, 2, 0, 1, 1);

        lineEdit_JunGuanZheng = new QLineEdit(UserManager);
        lineEdit_JunGuanZheng->setObjectName(QString::fromUtf8("lineEdit_JunGuanZheng"));
        lineEdit_JunGuanZheng->setMinimumSize(QSize(200, 30));
        lineEdit_JunGuanZheng->setMaximumSize(QSize(250, 30));
        lineEdit_JunGuanZheng->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lineEdit_JunGuanZheng->setEchoMode(QLineEdit::Normal);
        lineEdit_JunGuanZheng->setReadOnly(false);

        gridLayout->addWidget(lineEdit_JunGuanZheng, 2, 1, 1, 3);

        label_JiuMiMa = new QLabel(UserManager);
        label_JiuMiMa->setObjectName(QString::fromUtf8("label_JiuMiMa"));
        label_JiuMiMa->setMinimumSize(QSize(80, 30));
        label_JiuMiMa->setMaximumSize(QSize(70, 30));
        label_JiuMiMa->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(41, 136, 41);"));
        label_JiuMiMa->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_JiuMiMa, 3, 0, 1, 1);

        lineEdit_JiuMiMa = new QLineEdit(UserManager);
        lineEdit_JiuMiMa->setObjectName(QString::fromUtf8("lineEdit_JiuMiMa"));
        lineEdit_JiuMiMa->setMinimumSize(QSize(200, 30));
        lineEdit_JiuMiMa->setMaximumSize(QSize(250, 30));
        lineEdit_JiuMiMa->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lineEdit_JiuMiMa->setEchoMode(QLineEdit::Password);
        lineEdit_JiuMiMa->setReadOnly(true);

        gridLayout->addWidget(lineEdit_JiuMiMa, 3, 1, 1, 3);

        label_26 = new QLabel(UserManager);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setMinimumSize(QSize(80, 30));
        label_26->setMaximumSize(QSize(70, 30));
        label_26->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(41, 136, 41);"));
        label_26->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_26, 4, 0, 1, 1);

        lineEdit_MiMa = new QLineEdit(UserManager);
        lineEdit_MiMa->setObjectName(QString::fromUtf8("lineEdit_MiMa"));
        lineEdit_MiMa->setMinimumSize(QSize(200, 30));
        lineEdit_MiMa->setMaximumSize(QSize(250, 30));
        lineEdit_MiMa->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lineEdit_MiMa->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(lineEdit_MiMa, 4, 1, 1, 3);

        label_28 = new QLabel(UserManager);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setMinimumSize(QSize(80, 30));
        label_28->setMaximumSize(QSize(70, 30));
        label_28->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(41, 136, 41);"));
        label_28->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_28, 5, 0, 1, 1);

        lineEdit_QueRenMiMa = new QLineEdit(UserManager);
        lineEdit_QueRenMiMa->setObjectName(QString::fromUtf8("lineEdit_QueRenMiMa"));
        lineEdit_QueRenMiMa->setMinimumSize(QSize(200, 30));
        lineEdit_QueRenMiMa->setMaximumSize(QSize(250, 30));
        lineEdit_QueRenMiMa->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lineEdit_QueRenMiMa->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(lineEdit_QueRenMiMa, 5, 1, 1, 3);

        checkBox_XianShi = new QCheckBox(UserManager);
        checkBox_XianShi->setObjectName(QString::fromUtf8("checkBox_XianShi"));
        checkBox_XianShi->setMinimumSize(QSize(100, 30));
        checkBox_XianShi->setMaximumSize(QSize(100, 30));
        checkBox_XianShi->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout->addWidget(checkBox_XianShi, 6, 0, 1, 2);

        checkBox_XiuGaiMiMa = new QCheckBox(UserManager);
        checkBox_XiuGaiMiMa->setObjectName(QString::fromUtf8("checkBox_XiuGaiMiMa"));
        checkBox_XiuGaiMiMa->setMinimumSize(QSize(100, 30));
        checkBox_XiuGaiMiMa->setMaximumSize(QSize(100, 30));
        checkBox_XiuGaiMiMa->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout->addWidget(checkBox_XiuGaiMiMa, 6, 2, 1, 1);

        pushButton_QueDing = new QPushButton(UserManager);
        pushButton_QueDing->setObjectName(QString::fromUtf8("pushButton_QueDing"));
        pushButton_QueDing->setMinimumSize(QSize(75, 30));
        pushButton_QueDing->setMaximumSize(QSize(75, 30));
        pushButton_QueDing->setStyleSheet(QString::fromUtf8("font: 75 15pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(41, 136, 41);"));

        gridLayout->addWidget(pushButton_QueDing, 6, 3, 1, 1);


        retranslateUi(UserManager);
        QObject::connect(checkBox_XiuGaiMiMa, SIGNAL(clicked(bool)), UserManager, SLOT(SetModifyPasswordChecked(bool)));
        QObject::connect(pushButton_QueDing, SIGNAL(clicked()), UserManager, SLOT(ConfirmModification()));
        QObject::connect(checkBox_XianShi, SIGNAL(clicked(bool)), UserManager, SLOT(ShowPassword(bool)));

        QMetaObject::connectSlotsByName(UserManager);
    } // setupUi

    void retranslateUi(QDialog *UserManager)
    {
        UserManager->setWindowTitle(QCoreApplication::translate("UserManager", "\347\224\250\346\210\267\347\256\241\347\220\206", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("UserManager", "\346\235\203\351\231\220", nullptr));
        checkBox_ShiBieCaoZuo->setText(QCoreApplication::translate("UserManager", "\350\257\206\345\210\253\346\223\215\344\275\234", nullptr));
        checkBox_ShiBieJianDu->setText(QCoreApplication::translate("UserManager", "\350\257\206\345\210\253\347\233\221\347\235\243", nullptr));
        checkBox_RuKuCaoZuo->setText(QCoreApplication::translate("UserManager", "\345\205\245\345\272\223\346\223\215\344\275\234", nullptr));
        checkBox_RuKuJianDu->setText(QCoreApplication::translate("UserManager", "\345\205\245\345\272\223\347\233\221\347\235\243", nullptr));
        checkBox_ChuKuCaoZuo->setText(QCoreApplication::translate("UserManager", "\345\207\272\345\272\223\346\223\215\344\275\234", nullptr));
        checkBox_ChuKuJianDu->setText(QCoreApplication::translate("UserManager", "\345\207\272\345\272\223\347\233\221\347\235\243", nullptr));
        label_27->setText(QCoreApplication::translate("UserManager", "\345\247\223\345\220\215", nullptr));
        lineEdit_XingMing->setPlaceholderText(QString());
        label_29->setText(QCoreApplication::translate("UserManager", "\345\206\233\345\256\230\350\257\201\345\217\267", nullptr));
        lineEdit_JunGuanZheng->setPlaceholderText(QString());
        label_JiuMiMa->setText(QCoreApplication::translate("UserManager", "\346\227\247\345\257\206\347\240\201", nullptr));
        lineEdit_JiuMiMa->setPlaceholderText(QString());
        label_26->setText(QCoreApplication::translate("UserManager", "\345\257\206\347\240\201", nullptr));
        lineEdit_MiMa->setPlaceholderText(QString());
        label_28->setText(QCoreApplication::translate("UserManager", "\347\241\256\350\256\244\345\257\206\347\240\201", nullptr));
        lineEdit_QueRenMiMa->setPlaceholderText(QString());
        checkBox_XianShi->setText(QCoreApplication::translate("UserManager", "\346\230\276\347\244\272\345\257\206\347\240\201", nullptr));
        checkBox_XiuGaiMiMa->setText(QCoreApplication::translate("UserManager", "\344\277\256\346\224\271\345\257\206\347\240\201", nullptr));
        pushButton_QueDing->setText(QCoreApplication::translate("UserManager", "\346\267\273\345\212\240", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserManager: public Ui_UserManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERMANAGER_H
