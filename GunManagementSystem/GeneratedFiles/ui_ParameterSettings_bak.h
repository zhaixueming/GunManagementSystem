/********************************************************************************
** Form generated from reading UI file 'ParameterSettings_bak.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARAMETERSETTINGS_BAK_H
#define UI_PARAMETERSETTINGS_BAK_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_ParameterSetting
{
public:
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QLabel *label_20;
    QLineEdit *lineEdit_15;
    QLabel *label_21;
    QLineEdit *lineEdit_16;
    QLabel *label_22;
    QLineEdit *lineEdit_17;
    QPushButton *pushButton_23;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label_23;
    QComboBox *comboBox_3;
    QPushButton *pushButton_15;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QSpacerItem *horizontalSpacer;
    QLabel *label_Info;

    void setupUi(QDialog *ParameterSetting)
    {
        if (ParameterSetting->objectName().isEmpty())
            ParameterSetting->setObjectName(QString::fromUtf8("ParameterSetting"));
        ParameterSetting->resize(844, 160);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/SysMainWindow/Resources/settings.ico"), QSize(), QIcon::Normal, QIcon::Off);
        ParameterSetting->setWindowIcon(icon);
        gridLayout_3 = new QGridLayout(ParameterSetting);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        groupBox_2 = new QGroupBox(ParameterSetting);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_20 = new QLabel(groupBox_2);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setMinimumSize(QSize(60, 30));
        label_20->setMaximumSize(QSize(60, 30));
        label_20->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout_2->addWidget(label_20, 0, 0, 1, 1);

        lineEdit_15 = new QLineEdit(groupBox_2);
        lineEdit_15->setObjectName(QString::fromUtf8("lineEdit_15"));
        lineEdit_15->setMinimumSize(QSize(170, 30));
        lineEdit_15->setMaximumSize(QSize(170, 30));
        lineEdit_15->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout_2->addWidget(lineEdit_15, 0, 1, 1, 1);

        label_21 = new QLabel(groupBox_2);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setMinimumSize(QSize(60, 30));
        label_21->setMaximumSize(QSize(60, 30));
        label_21->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout_2->addWidget(label_21, 0, 2, 1, 1);

        lineEdit_16 = new QLineEdit(groupBox_2);
        lineEdit_16->setObjectName(QString::fromUtf8("lineEdit_16"));
        lineEdit_16->setMinimumSize(QSize(170, 30));
        lineEdit_16->setMaximumSize(QSize(170, 30));
        lineEdit_16->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout_2->addWidget(lineEdit_16, 0, 3, 1, 1);

        label_22 = new QLabel(groupBox_2);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setMinimumSize(QSize(40, 30));
        label_22->setMaximumSize(QSize(40, 30));
        label_22->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout_2->addWidget(label_22, 0, 4, 1, 1);

        lineEdit_17 = new QLineEdit(groupBox_2);
        lineEdit_17->setObjectName(QString::fromUtf8("lineEdit_17"));
        lineEdit_17->setMinimumSize(QSize(170, 30));
        lineEdit_17->setMaximumSize(QSize(170, 30));
        lineEdit_17->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout_2->addWidget(lineEdit_17, 0, 5, 1, 1);

        pushButton_23 = new QPushButton(groupBox_2);
        pushButton_23->setObjectName(QString::fromUtf8("pushButton_23"));
        pushButton_23->setMinimumSize(QSize(100, 30));
        pushButton_23->setMaximumSize(QSize(100, 30));
        pushButton_23->setStyleSheet(QString::fromUtf8("font: 75 15pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(0, 170, 0);"));

        gridLayout_2->addWidget(pushButton_23, 0, 6, 1, 1);


        gridLayout_3->addWidget(groupBox_2, 0, 0, 1, 2);

        groupBox = new QGroupBox(ParameterSetting);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_23 = new QLabel(groupBox);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setMinimumSize(QSize(80, 30));
        label_23->setMaximumSize(QSize(80, 30));
        label_23->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout->addWidget(label_23, 0, 0, 1, 1);

        comboBox_3 = new QComboBox(groupBox);
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));
        comboBox_3->setMinimumSize(QSize(200, 30));
        comboBox_3->setMaximumSize(QSize(200, 30));
        comboBox_3->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(85, 170, 0);"));

        gridLayout->addWidget(comboBox_3, 0, 1, 1, 1);

        pushButton_15 = new QPushButton(groupBox);
        pushButton_15->setObjectName(QString::fromUtf8("pushButton_15"));
        pushButton_15->setMinimumSize(QSize(100, 30));
        pushButton_15->setMaximumSize(QSize(100, 30));
        pushButton_15->setStyleSheet(QString::fromUtf8("font: 75 15pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout->addWidget(pushButton_15, 0, 2, 1, 1);

        radioButton_3 = new QRadioButton(groupBox);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));
        radioButton_3->setMinimumSize(QSize(100, 30));
        radioButton_3->setMaximumSize(QSize(100, 30));
        radioButton_3->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(85, 170, 0);"));

        gridLayout->addWidget(radioButton_3, 0, 3, 1, 1);

        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setMinimumSize(QSize(80, 30));
        radioButton->setMaximumSize(QSize(80, 30));
        radioButton->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(85, 170, 0);"));

        gridLayout->addWidget(radioButton, 0, 4, 1, 1);

        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setMinimumSize(QSize(80, 30));
        radioButton_2->setMaximumSize(QSize(80, 30));
        radioButton_2->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(85, 170, 0);"));

        gridLayout->addWidget(radioButton_2, 0, 5, 1, 1);


        gridLayout_3->addWidget(groupBox, 1, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(127, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 1, 1, 1, 1);

        label_Info = new QLabel(ParameterSetting);
        label_Info->setObjectName(QString::fromUtf8("label_Info"));
        label_Info->setMinimumSize(QSize(60, 30));
        label_Info->setMaximumSize(QSize(1000, 30));
        label_Info->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"background-color: rgb(255, 255, 0);"));

        gridLayout_3->addWidget(label_Info, 2, 0, 1, 2);


        retranslateUi(ParameterSetting);

        QMetaObject::connectSlotsByName(ParameterSetting);
    } // setupUi

    void retranslateUi(QDialog *ParameterSetting)
    {
        ParameterSetting->setWindowTitle(QCoreApplication::translate("ParameterSetting", "\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        groupBox_2->setTitle(QString());
        label_20->setText(QCoreApplication::translate("ParameterSetting", "\346\225\260\346\215\256\345\272\223", nullptr));
        lineEdit_15->setPlaceholderText(QString());
        label_21->setText(QCoreApplication::translate("ParameterSetting", "\347\224\250\346\210\267\345\220\215", nullptr));
        lineEdit_16->setText(QString());
        lineEdit_16->setPlaceholderText(QString());
        label_22->setText(QCoreApplication::translate("ParameterSetting", "\345\257\206\347\240\201", nullptr));
        lineEdit_17->setText(QString());
        lineEdit_17->setPlaceholderText(QString());
        pushButton_23->setText(QCoreApplication::translate("ParameterSetting", "\347\231\273\345\275\225", nullptr));
        groupBox->setTitle(QString());
        label_23->setText(QCoreApplication::translate("ParameterSetting", "\347\233\270\346\234\272\351\200\211\346\213\251", nullptr));
        pushButton_15->setText(QCoreApplication::translate("ParameterSetting", "\346\211\223\345\274\200\347\233\270\346\234\272", nullptr));
        radioButton_3->setText(QCoreApplication::translate("ParameterSetting", "\350\207\252\347\224\261\351\207\207\351\233\206", nullptr));
        radioButton->setText(QCoreApplication::translate("ParameterSetting", "\350\275\257\350\247\246\345\217\221", nullptr));
        radioButton_2->setText(QCoreApplication::translate("ParameterSetting", "\347\241\254\350\247\246\345\217\221", nullptr));
        label_Info->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ParameterSetting: public Ui_ParameterSetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARAMETERSETTINGS_BAK_H
