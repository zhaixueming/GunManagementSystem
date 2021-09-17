#include <QMessageBox>
#include "SettingsLogin.h"

CSettingsLogin *CSettingsLogin::m_Instance = NULL;
CSettingsLogin::GarbageCollection CSettingsLogin::m_Collection;

CSettingsLogin::CSettingsLogin(QDialog *parent /* = NULL */)
	:QDialog(parent)
{
	ui.setupUi(this);
	this->setFixedSize(this->size());
	ui.pushButton_QueDing->setStyleSheet("QPushButton{font: 75 15pt 'Î¢ÈíÑÅºÚ';background-color:rgb(190, 190, 190);color: rgb(34, 139, 34);border:2px groove gray;border-radius:50px;padding:2px 4px;border-style: outset;}"
		"QPushButton:hover{background-color:gray; color: rgb(10, 10, 10);}"
		"QPushButton:pressed{background-color:rgb(210, 20, 20);border-style: inset;}");
}


CSettingsLogin::~CSettingsLogin()
{

}

CSettingsLogin *CSettingsLogin::GetInstance()
{
	if (m_Instance == NULL)
	{
		m_Instance = new CSettingsLogin();
	}
	return m_Instance;
}

void CSettingsLogin::closeEvent(QCloseEvent *ev)
{
	done(0);
}

void CSettingsLogin::Login()
{
	QString text = ui.lineEdit->text();
	if (text == "qwerty123456")
	{
		done(1);
	}
	else
	{
		QMessageBox::information(this, NULL, QString::fromLocal8Bit("¿ÚÁî´íÎó"));
	}
}

void CSettingsLogin::ClearInformation()
{
	ui.lineEdit->setText("");
}