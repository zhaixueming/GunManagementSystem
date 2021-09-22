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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserManager
{
public:
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox_3;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_2;
    QCheckBox *checkBox_BianMaJianShiCaoZuo;
    QCheckBox *checkBox_BianMaJianShiJianDu;
    QCheckBox *checkBox_XinXiGuanLiCaoZuo;
    QCheckBox *checkBox_XinXiGuanLiJianDu;
    QGridLayout *gridLayout;
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
        UserManager->resize(351, 368);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/SysMainWindow/Resources/login-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        UserManager->setWindowIcon(icon);
        gridLayout_3 = new QGridLayout(UserManager);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        groupBox_3 = new QGroupBox(UserManager);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        layoutWidget = new QWidget(groupBox_3);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 30, 301, 68));
        gridLayout_2 = new QGridLayout(layoutWidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        checkBox_BianMaJianShiCaoZuo = new QCheckBox(layoutWidget);
        checkBox_BianMaJianShiCaoZuo->setObjectName(QString::fromUtf8("checkBox_BianMaJianShiCaoZuo"));
        checkBox_BianMaJianShiCaoZuo->setMinimumSize(QSize(150, 30));
        checkBox_BianMaJianShiCaoZuo->setMaximumSize(QSize(200, 30));
        checkBox_BianMaJianShiCaoZuo->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout_2->addWidget(checkBox_BianMaJianShiCaoZuo, 0, 0, 1, 1);

        checkBox_BianMaJianShiJianDu = new QCheckBox(layoutWidget);
        checkBox_BianMaJianShiJianDu->setObjectName(QString::fromUtf8("checkBox_BianMaJianShiJianDu"));
        checkBox_BianMaJianShiJianDu->setMinimumSize(QSize(200, 30));
        checkBox_BianMaJianShiJianDu->setMaximumSize(QSize(200, 30));
        checkBox_BianMaJianShiJianDu->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout_2->addWidget(checkBox_BianMaJianShiJianDu, 0, 1, 1, 1);

        checkBox_XinXiGuanLiCaoZuo = new QCheckBox(layoutWidget);
        checkBox_XinXiGuanLiCaoZuo->setObjectName(QString::fromUtf8("checkBox_XinXiGuanLiCaoZuo"));
        checkBox_XinXiGuanLiCaoZuo->setMinimumSize(QSize(200, 30));
        checkBox_XinXiGuanLiCaoZuo->setMaximumSize(QSize(200, 30));
        checkBox_XinXiGuanLiCaoZuo->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout_2->addWidget(checkBox_XinXiGuanLiCaoZuo, 1, 0, 1, 1);

        checkBox_XinXiGuanLiJianDu = new QCheckBox(layoutWidget);
        checkBox_XinXiGuanLiJianDu->setObjectName(QString::fromUtf8("checkBox_XinXiGuanLiJianDu"));
        checkBox_XinXiGuanLiJianDu->setMinimumSize(QSize(200, 30));
        checkBox_XinXiGuanLiJianDu->setMaximumSize(QSize(200, 30));
        checkBox_XinXiGuanLiJianDu->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout_2->addWidget(checkBox_XinXiGuanLiJianDu, 1, 1, 1, 1);


        gridLayout_3->addWidget(groupBox_3, 0, 0, 1, 3);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_27 = new QLabel(UserManager);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setMinimumSize(QSize(80, 30));
        label_27->setMaximumSize(QSize(70, 30));
        label_27->setLayoutDirection(Qt::LeftToRight);
        label_27->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(41, 136, 41);"));
        label_27->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_27, 0, 0, 1, 1);

        lineEdit_XingMing = new QLineEdit(UserManager);
        lineEdit_XingMing->setObjectName(QString::fromUtf8("lineEdit_XingMing"));
        lineEdit_XingMing->setMinimumSize(QSize(200, 30));
        lineEdit_XingMing->setMaximumSize(QSize(250, 30));
        lineEdit_XingMing->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lineEdit_XingMing->setReadOnly(false);

        gridLayout->addWidget(lineEdit_XingMing, 0, 1, 1, 1);

        label_29 = new QLabel(UserManager);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setMinimumSize(QSize(80, 30));
        label_29->setMaximumSize(QSize(70, 30));
        label_29->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(41, 136, 41);"));
        label_29->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_29, 1, 0, 1, 1);

        lineEdit_JunGuanZheng = new QLineEdit(UserManager);
        lineEdit_JunGuanZheng->setObjectName(QString::fromUtf8("lineEdit_JunGuanZheng"));
        lineEdit_JunGuanZheng->setMinimumSize(QSize(200, 30));
        lineEdit_JunGuanZheng->setMaximumSize(QSize(250, 30));
        lineEdit_JunGuanZheng->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lineEdit_JunGuanZheng->setEchoMode(QLineEdit::Normal);
        lineEdit_JunGuanZheng->setReadOnly(false);

        gridLayout->addWidget(lineEdit_JunGuanZheng, 1, 1, 1, 1);

        label_JiuMiMa = new QLabel(UserManager);
        label_JiuMiMa->setObjectName(QString::fromUtf8("label_JiuMiMa"));
        label_JiuMiMa->setMinimumSize(QSize(80, 30));
        label_JiuMiMa->setMaximumSize(QSize(70, 30));
        label_JiuMiMa->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(41, 136, 41);"));
        label_JiuMiMa->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_JiuMiMa, 2, 0, 1, 1);

        lineEdit_JiuMiMa = new QLineEdit(UserManager);
        lineEdit_JiuMiMa->setObjectName(QString::fromUtf8("lineEdit_JiuMiMa"));
        lineEdit_JiuMiMa->setMinimumSize(QSize(200, 30));
        lineEdit_JiuMiMa->setMaximumSize(QSize(250, 30));
        lineEdit_JiuMiMa->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lineEdit_JiuMiMa->setEchoMode(QLineEdit::Password);
        lineEdit_JiuMiMa->setReadOnly(true);

        gridLayout->addWidget(lineEdit_JiuMiMa, 2, 1, 1, 1);

        label_26 = new QLabel(UserManager);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setMinimumSize(QSize(80, 30));
        label_26->setMaximumSize(QSize(70, 30));
        label_26->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(41, 136, 41);"));
        label_26->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_26, 3, 0, 1, 1);

        lineEdit_MiMa = new QLineEdit(UserManager);
        lineEdit_MiMa->setObjectName(QString::fromUtf8("lineEdit_MiMa"));
        lineEdit_MiMa->setMinimumSize(QSize(200, 30));
        lineEdit_MiMa->setMaximumSize(QSize(250, 30));
        lineEdit_MiMa->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lineEdit_MiMa->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(lineEdit_MiMa, 3, 1, 1, 1);

        label_28 = new QLabel(UserManager);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setMinimumSize(QSize(80, 30));
        label_28->setMaximumSize(QSize(70, 30));
        label_28->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(41, 136, 41);"));
        label_28->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_28, 4, 0, 1, 1);

        lineEdit_QueRenMiMa = new QLineEdit(UserManager);
        lineEdit_QueRenMiMa->setObjectName(QString::fromUtf8("lineEdit_QueRenMiMa"));
        lineEdit_QueRenMiMa->setMinimumSize(QSize(200, 30));
        lineEdit_QueRenMiMa->setMaximumSize(QSize(250, 30));
        lineEdit_QueRenMiMa->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lineEdit_QueRenMiMa->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(lineEdit_QueRenMiMa, 4, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout, 1, 0, 1, 3);

        checkBox_XianShi = new QCheckBox(UserManager);
        checkBox_XianShi->setObjectName(QString::fromUtf8("checkBox_XianShi"));
        checkBox_XianShi->setMinimumSize(QSize(100, 30));
        checkBox_XianShi->setMaximumSize(QSize(100, 30));
        checkBox_XianShi->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout_3->addWidget(checkBox_XianShi, 2, 0, 1, 1);

        checkBox_XiuGaiMiMa = new QCheckBox(UserManager);
        checkBox_XiuGaiMiMa->setObjectName(QString::fromUtf8("checkBox_XiuGaiMiMa"));
        checkBox_XiuGaiMiMa->setMinimumSize(QSize(100, 30));
        checkBox_XiuGaiMiMa->setMaximumSize(QSize(100, 30));
        checkBox_XiuGaiMiMa->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout_3->addWidget(checkBox_XiuGaiMiMa, 2, 1, 1, 1);

        pushButton_QueDing = new QPushButton(UserManager);
        pushButton_QueDing->setObjectName(QString::fromUtf8("pushButton_QueDing"));
        pushButton_QueDing->setMinimumSize(QSize(75, 30));
        pushButton_QueDing->setMaximumSize(QSize(75, 30));
        pushButton_QueDing->setStyleSheet(QString::fromUtf8("font: 75 15pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(41, 136, 41);"));

        gridLayout_3->addWidget(pushButton_QueDing, 2, 2, 1, 1);

        QWidget::setTabOrder(checkBox_BianMaJianShiCaoZuo, checkBox_BianMaJianShiJianDu);
        QWidget::setTabOrder(checkBox_BianMaJianShiJianDu, checkBox_XinXiGuanLiCaoZuo);
        QWidget::setTabOrder(checkBox_XinXiGuanLiCaoZuo, checkBox_XinXiGuanLiJianDu);
        QWidget::setTabOrder(checkBox_XinXiGuanLiJianDu, lineEdit_XingMing);
        QWidget::setTabOrder(lineEdit_XingMing, lineEdit_JunGuanZheng);
        QWidget::setTabOrder(lineEdit_JunGuanZheng, lineEdit_JiuMiMa);
        QWidget::setTabOrder(lineEdit_JiuMiMa, lineEdit_MiMa);
        QWidget::setTabOrder(lineEdit_MiMa, lineEdit_QueRenMiMa);
        QWidget::setTabOrder(lineEdit_QueRenMiMa, checkBox_XianShi);
        QWidget::setTabOrder(checkBox_XianShi, checkBox_XiuGaiMiMa);
        QWidget::setTabOrder(checkBox_XiuGaiMiMa, pushButton_QueDing);

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
        checkBox_BianMaJianShiCaoZuo->setText(QCoreApplication::translate("UserManager", "\347\274\226\347\240\201\346\243\200\350\247\206\346\223\215\344\275\234", nullptr));
        checkBox_BianMaJianShiJianDu->setText(QCoreApplication::translate("UserManager", "\347\274\226\347\240\201\346\243\200\350\247\206\347\233\221\347\235\243", nullptr));
        checkBox_XinXiGuanLiCaoZuo->setText(QCoreApplication::translate("UserManager", "\344\277\241\346\201\257\347\256\241\347\220\206\346\223\215\344\275\234", nullptr));
        checkBox_XinXiGuanLiJianDu->setText(QCoreApplication::translate("UserManager", "\344\277\241\346\201\257\347\256\241\347\220\206\347\233\221\347\235\243", nullptr));
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
