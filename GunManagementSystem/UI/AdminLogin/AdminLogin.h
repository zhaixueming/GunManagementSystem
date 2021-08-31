#pragma once
#include "ui_AdminLogin.h"

class CAdminLogin :public QDialog
{
	Q_OBJECT
public:
	static CAdminLogin *GetInstance();//单例
	void ClearInfor();
	~CAdminLogin();
protected:
	void closeEvent(QCloseEvent *event);
private:
	CAdminLogin(QDialog *parent = NULL);
	class GarbageCollection
	{
	public:
		~GarbageCollection()
		{
			if (CAdminLogin::m_Instance)
			{
				delete CAdminLogin::m_Instance;
				CAdminLogin::m_Instance = nullptr;
			}
		}
	};
private:
	Ui::Admin_Login ui;
	static CAdminLogin *m_Instance;//单例模式
	static GarbageCollection m_garbage_collection;
private slots:
	void slotLogin();//身份验证槽函数
};

