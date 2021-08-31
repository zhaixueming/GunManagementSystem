#pragma once
#include "ui_UserManager.h"
#include "DatabaseOperator.h"

class CUserManager :public QDialog//�û�������
{
	Q_OBJECT
public:
	static CUserManager *GetInstance();
	void SetOperatorType(int index,QList<QVariant> Data);
	~CUserManager();
private:
	CUserManager(QDialog *parent = NULL);
	class GarbageCollection
	{
	public:
		~GarbageCollection()
		{
			if (CUserManager::m_Instance)
			{
				delete CUserManager::m_Instance;
				CUserManager::m_Instance = NULL;
			}
		}
	};
private:
	Ui::UserManager ui;
	static CUserManager *m_Instance;
	static GarbageCollection m_Collection;
	int m_Type;
	QString m_OldPassword;
private:
	void ClearController();//��տ���
	void SetControllerVisble(bool bVisble);//�ɼ�����
	void SetControllerEnabled(bool bEnabled);
	void SetData(QList<QVariant> data);
	bool CheckRepeat(QString &errMsg);
private slots:
	void SetModifyPasswordChecked(bool checked);//�޸�����
	void ShowPassword(bool checked);//��ʾ����
	void ConfirmModification();//ȷ���޸�
};
