#pragma once
#include <QCloseEvent>
#include "ui_SettingsLogin.h"

class CSettingsLogin :public QDialog
{
	Q_OBJECT
public:
	static CSettingsLogin *GetInstance();
	void ClearInformation();
	~CSettingsLogin();
private:
	CSettingsLogin(QDialog *parent = NULL);
	class GarbageCollection
	{
	public:
		~GarbageCollection()
		{
			if (CSettingsLogin::m_Instance)
			{
				delete CSettingsLogin::m_Instance;
				CSettingsLogin::m_Instance = NULL;
			}
		}
	};
private:
	Ui::SettingLogin ui;
	static CSettingsLogin *m_Instance;
	static GarbageCollection m_Collection;
protected:
	void closeEvent(QCloseEvent *ev);
private slots:
	void Login();
};
