/********************************************************************************
** Form generated from reading UI file 'SysMainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYSMAINWINDOW_H
#define UI_SYSMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SysMainWindowClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QLabel *label_logo;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_5;
    QGridLayout *gridLayout;
    QPushButton *pushButton_AcManager;
    QPushButton *pushButton_CodeReview;
    QPushButton *pushButton_InfoManager;
    QSpacerItem *horizontalSpacer_6;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SysMainWindowClass)
    {
        if (SysMainWindowClass->objectName().isEmpty())
            SysMainWindowClass->setObjectName(QString::fromUtf8("SysMainWindowClass"));
        SysMainWindowClass->resize(885, 503);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/SysMainWindow/Resources/login-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        SysMainWindowClass->setWindowIcon(icon);
        SysMainWindowClass->setStyleSheet(QString::fromUtf8(""));
        SysMainWindowClass->setIconSize(QSize(24, 24));
        centralWidget = new QWidget(SysMainWindowClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_3 = new QGridLayout(centralWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8(""));

        gridLayout_2->addWidget(label, 0, 0, 1, 3);

        horizontalSpacer = new QSpacerItem(218, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 1, 0, 1, 1);

        label_logo = new QLabel(centralWidget);
        label_logo->setObjectName(QString::fromUtf8("label_logo"));
        label_logo->setMinimumSize(QSize(141, 141));
        label_logo->setMaximumSize(QSize(141, 141));
        label_logo->setStyleSheet(QString::fromUtf8("image: url(:/SysMainWindow/Resources/81logo.png);"));

        gridLayout_2->addWidget(label_logo, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(318, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 1, 2, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 1, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_5, 1, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(50);
        gridLayout->setVerticalSpacing(6);
        pushButton_AcManager = new QPushButton(centralWidget);
        pushButton_AcManager->setObjectName(QString::fromUtf8("pushButton_AcManager"));
        pushButton_AcManager->setMinimumSize(QSize(251, 251));
        pushButton_AcManager->setMaximumSize(QSize(251, 251));
        pushButton_AcManager->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(pushButton_AcManager, 0, 0, 1, 1);

        pushButton_CodeReview = new QPushButton(centralWidget);
        pushButton_CodeReview->setObjectName(QString::fromUtf8("pushButton_CodeReview"));
        pushButton_CodeReview->setMinimumSize(QSize(251, 251));
        pushButton_CodeReview->setMaximumSize(QSize(251, 251));
        pushButton_CodeReview->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(pushButton_CodeReview, 0, 1, 1, 1);

        pushButton_InfoManager = new QPushButton(centralWidget);
        pushButton_InfoManager->setObjectName(QString::fromUtf8("pushButton_InfoManager"));
        pushButton_InfoManager->setMinimumSize(QSize(251, 251));
        pushButton_InfoManager->setMaximumSize(QSize(251, 251));
        pushButton_InfoManager->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(pushButton_InfoManager, 0, 2, 1, 1);


        gridLayout_3->addLayout(gridLayout, 1, 1, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_6, 1, 2, 1, 1);

        SysMainWindowClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(SysMainWindowClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        SysMainWindowClass->setStatusBar(statusBar);

        retranslateUi(SysMainWindowClass);
        QObject::connect(pushButton_AcManager, SIGNAL(clicked()), SysMainWindowClass, SLOT(slotAccountManager()));
        QObject::connect(pushButton_CodeReview, SIGNAL(clicked()), SysMainWindowClass, SLOT(slotCodeReview()));
        QObject::connect(pushButton_InfoManager, SIGNAL(clicked()), SysMainWindowClass, SLOT(slotInfoManager()));

        QMetaObject::connectSlotsByName(SysMainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *SysMainWindowClass)
    {
        SysMainWindowClass->setWindowTitle(QCoreApplication::translate("SysMainWindowClass", "\346\236\252\346\224\257\344\277\241\346\201\257\346\231\272\350\203\275\347\256\241\347\220\206\347\263\273\347\273\237_V0.0.1", nullptr));
        label->setText(QCoreApplication::translate("SysMainWindowClass", "<html><head/><body><p align=\"center\"><span style=\" font-size:22pt; font-weight:600; color:#548234;\">\346\236\252 \346\224\257 \344\277\241 \346\201\257 \346\231\272 \350\203\275 \347\256\241 \347\220\206 \347\263\273 \347\273\237</span></p></body></html>", nullptr));
        label_logo->setText(QString());
        pushButton_AcManager->setText(QCoreApplication::translate("SysMainWindowClass", "\350\264\246\345\217\267\347\256\241\347\220\206", nullptr));
        pushButton_CodeReview->setText(QCoreApplication::translate("SysMainWindowClass", "\347\274\226\347\240\201\346\243\200\350\247\206", nullptr));
        pushButton_InfoManager->setText(QCoreApplication::translate("SysMainWindowClass", "\344\277\241\346\201\257\347\256\241\347\220\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SysMainWindowClass: public Ui_SysMainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSMAINWINDOW_H
