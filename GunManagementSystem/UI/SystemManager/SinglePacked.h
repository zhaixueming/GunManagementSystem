#pragma once
#include "ui_SinglePacked.h"
#include "DatabaseOperator.h"

class CSinglePacked :public QDialog
{
	Q_OBJECT
public:
	static CSinglePacked *GetInstance();

	//连接 单装 枪支类型
	QString ConnectGunType2();

	~CSinglePacked();
private:
	CSinglePacked(QDialog *parent = NULL);
	class GarbageCollection
	{
	public:
		~GarbageCollection()
		{
			if (CSinglePacked::m_Instance)
			{
				delete CSinglePacked::m_Instance;
				CSinglePacked::m_Instance = NULL;
			}
		}
	};
private:
	void InitVariables();
	void SetControllerEnabled(bool enabled);
	void SetControllContent(QList<QVariant> data);
	bool CheckSinglePackedRepeat(QString &errMsg);
private:
	Ui::SinglePackedDialog ui;
	static CSinglePacked *m_Instance;
	static GarbageCollection m_Collection;

	//枪支类型
	QMap<QString, QString> m_GunTypeInfos;
private slots:
	void ConfirmModification();
};
