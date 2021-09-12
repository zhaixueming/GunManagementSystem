#pragma once
#include <QObject>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlRecord>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlDriver>
#include <QDebug>
#include <QMessageBox>

typedef QList<QList<QVariant >> QTableData;

class CDatabaseOperator:public QObject
{
	Q_OBJECT
public:
	static CDatabaseOperator *GetInstance();
	bool ConnectDatabase(QString DatabaseName, QString UserName, QString Password,QString &errMsg);
	QString GetDatabaseName();
	bool DisconnectDatabase(QString &errMsg);
	bool execSql(QString sql, QTableData &TableData,QString &errMsg);
	bool GetConnectStatus() { return m_bConnected; }//
	~CDatabaseOperator();
private:
	CDatabaseOperator(QObject *parent = NULL);
	void InitVariabled();
	class GarbageCollection
	{
	public:
		~GarbageCollection()
		{
			if (CDatabaseOperator::m_Instance)
			{
				delete CDatabaseOperator::m_Instance;
				CDatabaseOperator::m_Instance = NULL;
			}
		}
	};
private:
	static CDatabaseOperator *m_Instance;
	static GarbageCollection m_Collection;
	QSqlDatabase m_db;
	bool m_bConnected;//连接成功标志
};