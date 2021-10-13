#pragma once
#include "ui_SinglePacked.h"
#include "DatabaseOperator.h"

class CSinglePacked :public QDialog
{
	Q_OBJECT
public:
	static CSinglePacked *GetInstance();
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

	//«π÷ß¿‡–Õ
	QMap<QString, QString> m_GunTypeInfos;
private slots:
	void ConfirmModification();
};
