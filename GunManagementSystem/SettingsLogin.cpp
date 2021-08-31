#include <QMessageBox>
#include "SettingsLogin.h"

CSettingsLogin *CSettingsLogin::m_Instance = NULL;
CSettingsLogin::GarbageCollection CSettingsLogin::m_Collection;

CSettingsLogin::CSettingsLogin(QDialog *parent /* = NULL */)
	:QDialog(parent)
{
	ui.setupUi(this);
	this->setFixedSize(this->size());
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