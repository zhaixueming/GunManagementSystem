#pragma once
#include "ui_BoxPacked.h"
#include "DatabaseOperator.h"
#include "AlgoOCR_CodeReview.h"


//typedef enmu
//{
//	DEFUALT=0,
//	81SHIBUQIANG,
//	95SHIBUQIANG,
//	95-1SHIBUQIANG,
//	54SHISHOUQIANG,
//	92SHISHOUQIANG
//}m_GunType;



class CBoxPacked :public QDialog
{
	Q_OBJECT
public:
	static CBoxPacked *GetInstance();
	void SetOperatorType(int type, QList<QVariant> data);
	~CBoxPacked();
private:
	CBoxPacked(QDialog *parent = NULL);
	class GarbageCollection
	{
	public:
		~GarbageCollection()
		{
			if (CBoxPacked::m_Instance)
			{
				delete CBoxPacked::m_Instance;
				CBoxPacked::m_Instance = NULL;
			}
		}
	};
private:
	void InitVariables();
	void SetControllerEnabled(bool enabled);
	void SetControllContent(QList<QVariant> data);
	bool CheckBoxRepeat(QString &errMsg);
	bool CheckBoxDetailsRepeat(QString &errMsg);
private:
	Ui::BoxPackedDialog ui;
	static CBoxPacked *m_Instance;
	static GarbageCollection m_Collection;
	int m_Type;

	//枪支类型
	//QMap<QString, QString> m_GunTypeInfos;

private slots:
	//连接枪型
	void ConnectGunType();

	void ConfirmModification();
	
};
