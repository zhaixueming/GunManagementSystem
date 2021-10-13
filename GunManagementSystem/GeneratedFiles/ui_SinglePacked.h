/********************************************************************************
** Form generated from reading UI file 'SinglePacked.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SINGLEPACKED_H
#define UI_SINGLEPACKED_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_SinglePackedDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label_29;
    QLineEdit *lineEdit_WenJianHao;
    QLabel *label_30;
    QLineEdit *lineEdit_PingZhengHao;
    QLabel *label_32;
    QLineEdit *lineEdit_DaiMa;
    QLabel *label_33;
    QLineEdit *lineEdit_MingCheng;
    QLabel *label_LiShuDanWei;
    QLineEdit *lineEdit_LiShuDanWei;
    QLabel *label_35;
    QLineEdit *lineEdit_GuanLiDanWei;
    QLabel *label_37;
    QDateEdit *dateEdit_ChuChang;
    QLabel *label_38;
    QDateEdit *dateEdit_ZhuangBei;
    QLabel *label_36;
    QComboBox *comboBox_GunType;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_QueDing;

    void setupUi(QDialog *SinglePackedDialog)
    {
        if (SinglePackedDialog->objectName().isEmpty())
            SinglePackedDialog->setObjectName(QString::fromUtf8("SinglePackedDialog"));
        SinglePackedDialog->resize(638, 212);
        gridLayout = new QGridLayout(SinglePackedDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_29 = new QLabel(SinglePackedDialog);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setMinimumSize(QSize(100, 30));
        label_29->setMaximumSize(QSize(100, 30));
        label_29->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(41, 136, 41);"));
        label_29->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_29, 0, 0, 1, 1);

        lineEdit_WenJianHao = new QLineEdit(SinglePackedDialog);
        lineEdit_WenJianHao->setObjectName(QString::fromUtf8("lineEdit_WenJianHao"));
        lineEdit_WenJianHao->setMinimumSize(QSize(200, 30));
        lineEdit_WenJianHao->setMaximumSize(QSize(250, 30));
        lineEdit_WenJianHao->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lineEdit_WenJianHao->setEchoMode(QLineEdit::Normal);
        lineEdit_WenJianHao->setReadOnly(false);

        gridLayout->addWidget(lineEdit_WenJianHao, 0, 1, 1, 1);

        label_30 = new QLabel(SinglePackedDialog);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setMinimumSize(QSize(100, 30));
        label_30->setMaximumSize(QSize(100, 30));
        label_30->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(41, 136, 41);"));
        label_30->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_30, 0, 2, 1, 1);

        lineEdit_PingZhengHao = new QLineEdit(SinglePackedDialog);
        lineEdit_PingZhengHao->setObjectName(QString::fromUtf8("lineEdit_PingZhengHao"));
        lineEdit_PingZhengHao->setMinimumSize(QSize(200, 30));
        lineEdit_PingZhengHao->setMaximumSize(QSize(250, 30));
        lineEdit_PingZhengHao->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lineEdit_PingZhengHao->setEchoMode(QLineEdit::Normal);
        lineEdit_PingZhengHao->setReadOnly(false);

        gridLayout->addWidget(lineEdit_PingZhengHao, 0, 3, 1, 2);

        label_32 = new QLabel(SinglePackedDialog);
        label_32->setObjectName(QString::fromUtf8("label_32"));
        label_32->setMinimumSize(QSize(100, 30));
        label_32->setMaximumSize(QSize(100, 30));
        label_32->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(41, 136, 41);"));
        label_32->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_32, 1, 0, 1, 1);

        lineEdit_DaiMa = new QLineEdit(SinglePackedDialog);
        lineEdit_DaiMa->setObjectName(QString::fromUtf8("lineEdit_DaiMa"));
        lineEdit_DaiMa->setMinimumSize(QSize(200, 30));
        lineEdit_DaiMa->setMaximumSize(QSize(250, 30));
        lineEdit_DaiMa->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lineEdit_DaiMa->setEchoMode(QLineEdit::Normal);
        lineEdit_DaiMa->setReadOnly(false);

        gridLayout->addWidget(lineEdit_DaiMa, 1, 1, 1, 1);

        label_33 = new QLabel(SinglePackedDialog);
        label_33->setObjectName(QString::fromUtf8("label_33"));
        label_33->setMinimumSize(QSize(100, 30));
        label_33->setMaximumSize(QSize(100, 30));
        label_33->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(41, 136, 41);"));
        label_33->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_33, 1, 2, 1, 1);

        lineEdit_MingCheng = new QLineEdit(SinglePackedDialog);
        lineEdit_MingCheng->setObjectName(QString::fromUtf8("lineEdit_MingCheng"));
        lineEdit_MingCheng->setMinimumSize(QSize(200, 30));
        lineEdit_MingCheng->setMaximumSize(QSize(250, 30));
        lineEdit_MingCheng->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lineEdit_MingCheng->setEchoMode(QLineEdit::Normal);
        lineEdit_MingCheng->setReadOnly(false);

        gridLayout->addWidget(lineEdit_MingCheng, 1, 3, 1, 2);

        label_LiShuDanWei = new QLabel(SinglePackedDialog);
        label_LiShuDanWei->setObjectName(QString::fromUtf8("label_LiShuDanWei"));
        label_LiShuDanWei->setMinimumSize(QSize(100, 30));
        label_LiShuDanWei->setMaximumSize(QSize(100, 30));
        label_LiShuDanWei->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(41, 136, 41);"));
        label_LiShuDanWei->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_LiShuDanWei, 2, 0, 1, 1);

        lineEdit_LiShuDanWei = new QLineEdit(SinglePackedDialog);
        lineEdit_LiShuDanWei->setObjectName(QString::fromUtf8("lineEdit_LiShuDanWei"));
        lineEdit_LiShuDanWei->setMinimumSize(QSize(200, 30));
        lineEdit_LiShuDanWei->setMaximumSize(QSize(250, 30));
        lineEdit_LiShuDanWei->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lineEdit_LiShuDanWei->setEchoMode(QLineEdit::Normal);
        lineEdit_LiShuDanWei->setReadOnly(false);

        gridLayout->addWidget(lineEdit_LiShuDanWei, 2, 1, 1, 1);

        label_35 = new QLabel(SinglePackedDialog);
        label_35->setObjectName(QString::fromUtf8("label_35"));
        label_35->setMinimumSize(QSize(100, 30));
        label_35->setMaximumSize(QSize(100, 30));
        label_35->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(41, 136, 41);"));
        label_35->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_35, 2, 2, 1, 1);

        lineEdit_GuanLiDanWei = new QLineEdit(SinglePackedDialog);
        lineEdit_GuanLiDanWei->setObjectName(QString::fromUtf8("lineEdit_GuanLiDanWei"));
        lineEdit_GuanLiDanWei->setMinimumSize(QSize(200, 30));
        lineEdit_GuanLiDanWei->setMaximumSize(QSize(250, 30));
        lineEdit_GuanLiDanWei->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lineEdit_GuanLiDanWei->setEchoMode(QLineEdit::Normal);
        lineEdit_GuanLiDanWei->setReadOnly(false);

        gridLayout->addWidget(lineEdit_GuanLiDanWei, 2, 3, 1, 2);

        label_37 = new QLabel(SinglePackedDialog);
        label_37->setObjectName(QString::fromUtf8("label_37"));
        label_37->setMinimumSize(QSize(100, 30));
        label_37->setMaximumSize(QSize(100, 30));
        label_37->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(41, 136, 41);"));
        label_37->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_37, 3, 0, 1, 1);

        dateEdit_ChuChang = new QDateEdit(SinglePackedDialog);
        dateEdit_ChuChang->setObjectName(QString::fromUtf8("dateEdit_ChuChang"));
        dateEdit_ChuChang->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        dateEdit_ChuChang->setDateTime(QDateTime(QDate(1900, 1, 1), QTime(0, 0, 0)));
        dateEdit_ChuChang->setCalendarPopup(true);
        dateEdit_ChuChang->setDate(QDate(1900, 1, 1));

        gridLayout->addWidget(dateEdit_ChuChang, 3, 1, 1, 1);

        label_38 = new QLabel(SinglePackedDialog);
        label_38->setObjectName(QString::fromUtf8("label_38"));
        label_38->setMinimumSize(QSize(100, 30));
        label_38->setMaximumSize(QSize(100, 30));
        label_38->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(41, 136, 41);"));
        label_38->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_38, 3, 2, 1, 1);

        dateEdit_ZhuangBei = new QDateEdit(SinglePackedDialog);
        dateEdit_ZhuangBei->setObjectName(QString::fromUtf8("dateEdit_ZhuangBei"));
        dateEdit_ZhuangBei->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        dateEdit_ZhuangBei->setDateTime(QDateTime(QDate(1900, 1, 1), QTime(0, 0, 0)));
        dateEdit_ZhuangBei->setCalendarPopup(true);
        dateEdit_ZhuangBei->setDate(QDate(1900, 1, 1));

        gridLayout->addWidget(dateEdit_ZhuangBei, 3, 3, 1, 2);

        label_36 = new QLabel(SinglePackedDialog);
        label_36->setObjectName(QString::fromUtf8("label_36"));
        label_36->setMinimumSize(QSize(100, 30));
        label_36->setMaximumSize(QSize(100, 30));
        label_36->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(41, 136, 41);"));
        label_36->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_36, 4, 0, 1, 1);

        comboBox_GunType = new QComboBox(SinglePackedDialog);
        comboBox_GunType->setObjectName(QString::fromUtf8("comboBox_GunType"));

        gridLayout->addWidget(comboBox_GunType, 4, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(223, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 4, 2, 1, 2);

        pushButton_QueDing = new QPushButton(SinglePackedDialog);
        pushButton_QueDing->setObjectName(QString::fromUtf8("pushButton_QueDing"));
        pushButton_QueDing->setMinimumSize(QSize(75, 30));
        pushButton_QueDing->setMaximumSize(QSize(75, 30));
        pushButton_QueDing->setStyleSheet(QString::fromUtf8("font: 75 15pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(41, 136, 41);"));

        gridLayout->addWidget(pushButton_QueDing, 4, 4, 1, 1);


        retranslateUi(SinglePackedDialog);
        QObject::connect(pushButton_QueDing, SIGNAL(clicked()), SinglePackedDialog, SLOT(ConfirmModification()));

        QMetaObject::connectSlotsByName(SinglePackedDialog);
    } // setupUi

    void retranslateUi(QDialog *SinglePackedDialog)
    {
        SinglePackedDialog->setWindowTitle(QCoreApplication::translate("SinglePackedDialog", "\345\215\225\350\243\205\344\277\241\346\201\257", nullptr));
        label_29->setText(QCoreApplication::translate("SinglePackedDialog", "\346\212\245\345\272\237\346\226\207\344\273\266\345\217\267", nullptr));
        lineEdit_WenJianHao->setPlaceholderText(QString());
        label_30->setText(QCoreApplication::translate("SinglePackedDialog", "\350\260\203\346\213\250\345\207\255\350\257\201\345\217\267", nullptr));
        lineEdit_PingZhengHao->setPlaceholderText(QString());
        label_32->setText(QCoreApplication::translate("SinglePackedDialog", "\350\243\205\345\244\207\344\273\243\347\240\201", nullptr));
        lineEdit_DaiMa->setPlaceholderText(QString());
        label_33->setText(QCoreApplication::translate("SinglePackedDialog", "\350\243\205\345\244\207\345\220\215\347\247\260", nullptr));
        lineEdit_MingCheng->setPlaceholderText(QString());
        label_LiShuDanWei->setText(QCoreApplication::translate("SinglePackedDialog", "\351\232\266\345\261\236\345\215\225\344\275\215", nullptr));
        lineEdit_LiShuDanWei->setPlaceholderText(QString());
        label_35->setText(QCoreApplication::translate("SinglePackedDialog", "\347\256\241\347\220\206\345\215\225\344\275\215", nullptr));
        lineEdit_GuanLiDanWei->setPlaceholderText(QString());
        label_37->setText(QCoreApplication::translate("SinglePackedDialog", "\345\207\272\345\216\202\346\227\266\351\227\264", nullptr));
        dateEdit_ChuChang->setDisplayFormat(QCoreApplication::translate("SinglePackedDialog", "yyyy-M-d", nullptr));
        label_38->setText(QCoreApplication::translate("SinglePackedDialog", "\350\243\205\345\244\207\346\227\266\351\227\264", nullptr));
        dateEdit_ZhuangBei->setDisplayFormat(QCoreApplication::translate("SinglePackedDialog", "yyyy-M-d", nullptr));
        label_36->setText(QCoreApplication::translate("SinglePackedDialog", "\347\256\241\347\220\206\345\215\225\344\275\215", nullptr));
        pushButton_QueDing->setText(QCoreApplication::translate("SinglePackedDialog", "\346\267\273\345\212\240", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SinglePackedDialog: public Ui_SinglePackedDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SINGLEPACKED_H
