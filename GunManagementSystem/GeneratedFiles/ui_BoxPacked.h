/********************************************************************************
** Form generated from reading UI file 'BoxPacked.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOXPACKED_H
#define UI_BOXPACKED_H

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
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_BoxPackedDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label_29;
    QLineEdit *lineEdit_WenJianHao;
    QLabel *label_30;
    QLineEdit *lineEdit_PingZhengHao;
    QLabel *label_31;
    QLineEdit *lineEdit_DanHao;
    QLabel *label_32;
    QLineEdit *lineEdit_DaiMa;
    QLabel *label_33;
    QLineEdit *lineEdit_MingCheng;
    QLabel *label_LiShuDanWei;
    QLineEdit *lineEdit_LiShuDanWei;
    QLabel *label_35;
    QLineEdit *lineEdit_GuanLiDanWei;
    QLabel *label_39;
    QLabel *label_37;
    QDateEdit *dateEdit_ChuChang;
    QLabel *label_38;
    QDateEdit *dateEdit_ZhuangBei;
    QLabel *label_36;
    QSpinBox *spinBox;
    QPushButton *pushButton_QueDing;
    QComboBox *comboBox_GunType;

    void setupUi(QDialog *BoxPackedDialog)
    {
        if (BoxPackedDialog->objectName().isEmpty())
            BoxPackedDialog->setObjectName(QString::fromUtf8("BoxPackedDialog"));
        BoxPackedDialog->resize(636, 358);
        BoxPackedDialog->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        gridLayout = new QGridLayout(BoxPackedDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_29 = new QLabel(BoxPackedDialog);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setMinimumSize(QSize(100, 30));
        label_29->setMaximumSize(QSize(100, 30));
        label_29->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(41, 136, 41);"));
        label_29->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_29, 0, 0, 1, 1);

        lineEdit_WenJianHao = new QLineEdit(BoxPackedDialog);
        lineEdit_WenJianHao->setObjectName(QString::fromUtf8("lineEdit_WenJianHao"));
        lineEdit_WenJianHao->setMinimumSize(QSize(200, 30));
        lineEdit_WenJianHao->setMaximumSize(QSize(250, 30));
        lineEdit_WenJianHao->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lineEdit_WenJianHao->setEchoMode(QLineEdit::Normal);
        lineEdit_WenJianHao->setReadOnly(false);

        gridLayout->addWidget(lineEdit_WenJianHao, 0, 1, 1, 1);

        label_30 = new QLabel(BoxPackedDialog);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setMinimumSize(QSize(100, 30));
        label_30->setMaximumSize(QSize(100, 30));
        label_30->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(41, 136, 41);"));
        label_30->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_30, 0, 2, 1, 1);

        lineEdit_PingZhengHao = new QLineEdit(BoxPackedDialog);
        lineEdit_PingZhengHao->setObjectName(QString::fromUtf8("lineEdit_PingZhengHao"));
        lineEdit_PingZhengHao->setMinimumSize(QSize(200, 30));
        lineEdit_PingZhengHao->setMaximumSize(QSize(250, 30));
        lineEdit_PingZhengHao->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lineEdit_PingZhengHao->setEchoMode(QLineEdit::Normal);
        lineEdit_PingZhengHao->setReadOnly(false);

        gridLayout->addWidget(lineEdit_PingZhengHao, 0, 3, 1, 2);

        label_31 = new QLabel(BoxPackedDialog);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setMinimumSize(QSize(100, 30));
        label_31->setMaximumSize(QSize(100, 30));
        label_31->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(41, 136, 41);"));
        label_31->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_31, 1, 0, 1, 1);

        lineEdit_DanHao = new QLineEdit(BoxPackedDialog);
        lineEdit_DanHao->setObjectName(QString::fromUtf8("lineEdit_DanHao"));
        lineEdit_DanHao->setMinimumSize(QSize(200, 30));
        lineEdit_DanHao->setMaximumSize(QSize(250, 30));
        lineEdit_DanHao->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lineEdit_DanHao->setEchoMode(QLineEdit::Normal);
        lineEdit_DanHao->setReadOnly(false);

        gridLayout->addWidget(lineEdit_DanHao, 1, 1, 1, 1);

        label_32 = new QLabel(BoxPackedDialog);
        label_32->setObjectName(QString::fromUtf8("label_32"));
        label_32->setMinimumSize(QSize(100, 30));
        label_32->setMaximumSize(QSize(100, 30));
        label_32->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(41, 136, 41);"));
        label_32->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_32, 1, 2, 1, 1);

        lineEdit_DaiMa = new QLineEdit(BoxPackedDialog);
        lineEdit_DaiMa->setObjectName(QString::fromUtf8("lineEdit_DaiMa"));
        lineEdit_DaiMa->setMinimumSize(QSize(200, 30));
        lineEdit_DaiMa->setMaximumSize(QSize(250, 30));
        lineEdit_DaiMa->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lineEdit_DaiMa->setEchoMode(QLineEdit::Normal);
        lineEdit_DaiMa->setReadOnly(false);

        gridLayout->addWidget(lineEdit_DaiMa, 1, 3, 1, 2);

        label_33 = new QLabel(BoxPackedDialog);
        label_33->setObjectName(QString::fromUtf8("label_33"));
        label_33->setMinimumSize(QSize(100, 30));
        label_33->setMaximumSize(QSize(100, 30));
        label_33->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(41, 136, 41);"));
        label_33->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_33, 2, 0, 1, 1);

        lineEdit_MingCheng = new QLineEdit(BoxPackedDialog);
        lineEdit_MingCheng->setObjectName(QString::fromUtf8("lineEdit_MingCheng"));
        lineEdit_MingCheng->setMinimumSize(QSize(200, 30));
        lineEdit_MingCheng->setMaximumSize(QSize(250, 30));
        lineEdit_MingCheng->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lineEdit_MingCheng->setEchoMode(QLineEdit::Normal);
        lineEdit_MingCheng->setReadOnly(false);

        gridLayout->addWidget(lineEdit_MingCheng, 2, 1, 1, 1);

        label_LiShuDanWei = new QLabel(BoxPackedDialog);
        label_LiShuDanWei->setObjectName(QString::fromUtf8("label_LiShuDanWei"));
        label_LiShuDanWei->setMinimumSize(QSize(100, 30));
        label_LiShuDanWei->setMaximumSize(QSize(100, 30));
        label_LiShuDanWei->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(41, 136, 41);"));
        label_LiShuDanWei->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_LiShuDanWei, 2, 2, 1, 1);

        lineEdit_LiShuDanWei = new QLineEdit(BoxPackedDialog);
        lineEdit_LiShuDanWei->setObjectName(QString::fromUtf8("lineEdit_LiShuDanWei"));
        lineEdit_LiShuDanWei->setMinimumSize(QSize(200, 30));
        lineEdit_LiShuDanWei->setMaximumSize(QSize(250, 30));
        lineEdit_LiShuDanWei->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lineEdit_LiShuDanWei->setEchoMode(QLineEdit::Normal);
        lineEdit_LiShuDanWei->setReadOnly(false);

        gridLayout->addWidget(lineEdit_LiShuDanWei, 2, 3, 1, 2);

        label_35 = new QLabel(BoxPackedDialog);
        label_35->setObjectName(QString::fromUtf8("label_35"));
        label_35->setMinimumSize(QSize(100, 30));
        label_35->setMaximumSize(QSize(100, 30));
        label_35->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(41, 136, 41);"));
        label_35->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_35, 3, 0, 1, 1);

        lineEdit_GuanLiDanWei = new QLineEdit(BoxPackedDialog);
        lineEdit_GuanLiDanWei->setObjectName(QString::fromUtf8("lineEdit_GuanLiDanWei"));
        lineEdit_GuanLiDanWei->setMinimumSize(QSize(200, 30));
        lineEdit_GuanLiDanWei->setMaximumSize(QSize(250, 30));
        lineEdit_GuanLiDanWei->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lineEdit_GuanLiDanWei->setEchoMode(QLineEdit::Normal);
        lineEdit_GuanLiDanWei->setReadOnly(false);

        gridLayout->addWidget(lineEdit_GuanLiDanWei, 3, 1, 1, 1);

        label_39 = new QLabel(BoxPackedDialog);
        label_39->setObjectName(QString::fromUtf8("label_39"));
        label_39->setMinimumSize(QSize(100, 30));
        label_39->setMaximumSize(QSize(100, 30));
        label_39->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(41, 136, 41);"));
        label_39->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_39, 3, 2, 1, 1);

        label_37 = new QLabel(BoxPackedDialog);
        label_37->setObjectName(QString::fromUtf8("label_37"));
        label_37->setMinimumSize(QSize(100, 30));
        label_37->setMaximumSize(QSize(100, 30));
        label_37->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(41, 136, 41);"));
        label_37->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_37, 4, 0, 1, 1);

        dateEdit_ChuChang = new QDateEdit(BoxPackedDialog);
        dateEdit_ChuChang->setObjectName(QString::fromUtf8("dateEdit_ChuChang"));
        dateEdit_ChuChang->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        dateEdit_ChuChang->setDateTime(QDateTime(QDate(1900, 1, 1), QTime(0, 0, 0)));
        dateEdit_ChuChang->setCalendarPopup(true);
        dateEdit_ChuChang->setDate(QDate(1900, 1, 1));

        gridLayout->addWidget(dateEdit_ChuChang, 4, 1, 1, 1);

        label_38 = new QLabel(BoxPackedDialog);
        label_38->setObjectName(QString::fromUtf8("label_38"));
        label_38->setMinimumSize(QSize(100, 30));
        label_38->setMaximumSize(QSize(100, 30));
        label_38->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(41, 136, 41);"));
        label_38->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_38, 4, 2, 1, 1);

        dateEdit_ZhuangBei = new QDateEdit(BoxPackedDialog);
        dateEdit_ZhuangBei->setObjectName(QString::fromUtf8("dateEdit_ZhuangBei"));
        dateEdit_ZhuangBei->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        dateEdit_ZhuangBei->setDateTime(QDateTime(QDate(1900, 1, 1), QTime(0, 0, 0)));
        dateEdit_ZhuangBei->setCalendarPopup(true);
        dateEdit_ZhuangBei->setDate(QDate(1900, 1, 1));

        gridLayout->addWidget(dateEdit_ZhuangBei, 4, 3, 1, 2);

        label_36 = new QLabel(BoxPackedDialog);
        label_36->setObjectName(QString::fromUtf8("label_36"));
        label_36->setMinimumSize(QSize(100, 30));
        label_36->setMaximumSize(QSize(100, 30));
        label_36->setStyleSheet(QString::fromUtf8("color: rgb(41, 136, 41);"));
        label_36->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_36, 5, 2, 1, 1);

        spinBox = new QSpinBox(BoxPackedDialog);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setMinimumSize(QSize(0, 30));
        spinBox->setMaximumSize(QSize(16777215, 30));
        spinBox->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        spinBox->setMinimum(1);
        spinBox->setMaximum(10000000);

        gridLayout->addWidget(spinBox, 5, 3, 1, 1);

        pushButton_QueDing = new QPushButton(BoxPackedDialog);
        pushButton_QueDing->setObjectName(QString::fromUtf8("pushButton_QueDing"));
        pushButton_QueDing->setMinimumSize(QSize(75, 30));
        pushButton_QueDing->setMaximumSize(QSize(75, 30));
        pushButton_QueDing->setStyleSheet(QString::fromUtf8("font: 75 15pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(41, 136, 41);"));

        gridLayout->addWidget(pushButton_QueDing, 5, 4, 1, 1);

        comboBox_GunType = new QComboBox(BoxPackedDialog);
        comboBox_GunType->setObjectName(QString::fromUtf8("comboBox_GunType"));
        comboBox_GunType->setEnabled(true);
        comboBox_GunType->setMaximumSize(QSize(200, 30));
        comboBox_GunType->setStyleSheet(QString::fromUtf8(""));
        comboBox_GunType->setEditable(false);

        gridLayout->addWidget(comboBox_GunType, 3, 3, 1, 2);

        QWidget::setTabOrder(lineEdit_WenJianHao, lineEdit_PingZhengHao);
        QWidget::setTabOrder(lineEdit_PingZhengHao, lineEdit_DanHao);
        QWidget::setTabOrder(lineEdit_DanHao, lineEdit_DaiMa);
        QWidget::setTabOrder(lineEdit_DaiMa, lineEdit_MingCheng);
        QWidget::setTabOrder(lineEdit_MingCheng, lineEdit_LiShuDanWei);
        QWidget::setTabOrder(lineEdit_LiShuDanWei, lineEdit_GuanLiDanWei);
        QWidget::setTabOrder(lineEdit_GuanLiDanWei, comboBox_GunType);
        QWidget::setTabOrder(comboBox_GunType, dateEdit_ChuChang);
        QWidget::setTabOrder(dateEdit_ChuChang, dateEdit_ZhuangBei);
        QWidget::setTabOrder(dateEdit_ZhuangBei, spinBox);
        QWidget::setTabOrder(spinBox, pushButton_QueDing);

        retranslateUi(BoxPackedDialog);
        QObject::connect(pushButton_QueDing, SIGNAL(clicked()), BoxPackedDialog, SLOT(ConfirmModification()));

        QMetaObject::connectSlotsByName(BoxPackedDialog);
    } // setupUi

    void retranslateUi(QDialog *BoxPackedDialog)
    {
        BoxPackedDialog->setWindowTitle(QCoreApplication::translate("BoxPackedDialog", "\347\256\261\350\243\205\344\277\241\346\201\257", nullptr));
        label_29->setText(QCoreApplication::translate("BoxPackedDialog", "\346\212\245\345\272\237\346\226\207\344\273\266\345\217\267", nullptr));
        lineEdit_WenJianHao->setPlaceholderText(QString());
        label_30->setText(QCoreApplication::translate("BoxPackedDialog", "\350\260\203\346\213\250\345\207\255\350\257\201\345\217\267", nullptr));
        lineEdit_PingZhengHao->setPlaceholderText(QString());
        label_31->setText(QCoreApplication::translate("BoxPackedDialog", "\350\243\205\347\256\261\345\215\225\345\217\267", nullptr));
        lineEdit_DanHao->setPlaceholderText(QString());
        label_32->setText(QCoreApplication::translate("BoxPackedDialog", "\350\243\205\345\244\207\344\273\243\347\240\201", nullptr));
        lineEdit_DaiMa->setPlaceholderText(QString());
        label_33->setText(QCoreApplication::translate("BoxPackedDialog", "\350\243\205\345\244\207\345\220\215\347\247\260", nullptr));
        lineEdit_MingCheng->setPlaceholderText(QString());
        label_LiShuDanWei->setText(QCoreApplication::translate("BoxPackedDialog", "\351\232\266\345\261\236\345\215\225\344\275\215", nullptr));
        lineEdit_LiShuDanWei->setPlaceholderText(QString());
        label_35->setText(QCoreApplication::translate("BoxPackedDialog", "\347\256\241\347\220\206\345\215\225\344\275\215", nullptr));
        lineEdit_GuanLiDanWei->setPlaceholderText(QString());
        label_39->setText(QCoreApplication::translate("BoxPackedDialog", "\346\236\252\346\224\257\347\261\273\345\236\213", nullptr));
        label_37->setText(QCoreApplication::translate("BoxPackedDialog", "\345\207\272\345\216\202\346\227\266\351\227\264", nullptr));
        dateEdit_ChuChang->setDisplayFormat(QCoreApplication::translate("BoxPackedDialog", "yyyy-M-d", nullptr));
        label_38->setText(QCoreApplication::translate("BoxPackedDialog", "\350\243\205\345\244\207\346\227\266\351\227\264", nullptr));
        dateEdit_ZhuangBei->setDisplayFormat(QCoreApplication::translate("BoxPackedDialog", "yyyy-M-d", nullptr));
        label_36->setText(QCoreApplication::translate("BoxPackedDialog", "\350\243\205\347\256\261\346\225\260\351\207\217", nullptr));
        pushButton_QueDing->setText(QCoreApplication::translate("BoxPackedDialog", "\346\267\273\345\212\240", nullptr));
        comboBox_GunType->setCurrentText(QString());
    } // retranslateUi

};

namespace Ui {
    class BoxPackedDialog: public Ui_BoxPackedDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOXPACKED_H
