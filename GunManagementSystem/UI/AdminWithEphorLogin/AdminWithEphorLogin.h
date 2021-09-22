#pragma once
#include "ui_AdminWithEphorLogin.h"

class CAdminWithEphorLogin :public QDialog
{
	Q_OBJECT
public:
	static CAdminWithEphorLogin *GetInstance();
	//flag 1  编码检视 
	//flag 2  信息管理
	void SetLoginFlag(int flag);
	void ClearInfor();
	~CAdminWithEphorLogin();
protected:
	void closeEvent(QCloseEvent *event);
private:
	CAdminWithEphorLogin(QDialog *parent = NULL);
	bool CheckCodeOperator(QString &errMsg);
	bool CheckInfoOperpator(QString &errMsg);
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
	int m_Flag;
private slots:
	void slotLogin();
};