#pragma once
#include "ui_AdminWithEphorLogin.h"

class CAdminWithEphorLogin :public QDialog
{
	Q_OBJECT
public:
	static CAdminWithEphorLogin *GetInstance();
	void ClearInfor();
	~CAdminWithEphorLogin();
protected:
	void closeEvent(QCloseEvent *event);
private:
	CAdminWithEphorLogin(QDialog *parent = NULL);
	class GarbageCollection
	{
	public:
		~GarbageCollection()
		{
			if (CAdminWithEphorLogin::m_Instance)
			{
				delete CAdminWithEphorLogin::m_Instance;
				CAdminWithEphorLogin::m_Instance = nullptr;
			}
		}
	};
private:
	Ui::AdminWithEphorLogin ui;
	static CAdminWithEphorLogin *m_Instance;
	static GarbageCollection m_garbage_collection;
private slots:
	void slotLogin();
};