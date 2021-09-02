#include "DatabaseOperator.h"

CDatabaseOperator *CDatabaseOperator::m_Instance = NULL;
CDatabaseOperator::GarbageCollection CDatabaseOperator::m_Collection;

CDatabaseOperator::CDatabaseOperator(QObject *parent)
	:QObject(parent)
{
	InitVariabled();
}

CDatabaseOperator::~CDatabaseOperator()
{

}

CDatabaseOperator *CDatabaseOperator::GetInstance()//单例模式
{
	if (m_Instance == NULL)
	{
		m_Instance = new CDatabaseOperator();
	}
	return m_Instance;
}

void CDatabaseOperator::InitVariabled()
{
	m_db = QSqlDatabase::addDatabase("QODBC");//addDatabase（驱动名）
	m_bConnected = false;


	m_db.setHostName("local");                        //选择本地主机，127.0.1.1  
	m_db.setDatabaseName("GunManager");                            //设置数据源名称  
	m_db.setUserName("sa");                               //设置登录用户  
	//m_db.setPassword("k-touch1234");   
	m_db.setPassword("zhai6688/");//设置密码                   
	m_bConnected = m_db.open();    //打开数据可连接
}

bool CDatabaseOperator::ConnectDatabase( QString DatabaseName, QString UserName, QString Password, QString &errMsg)
{
	qDebug() << "connect database:" << DatabaseName << "," << UserName;
	qDebug() << "ODBC driver?" << m_db.isValid();
	QString dsn = QString::fromLocal8Bit("QTDSN");      //数据源名称  
	m_db.setHostName("local");                        //选择本地主机，127.0.1.1  
	m_db.setDatabaseName(DatabaseName);                            //设置数据源名称  
	m_db.setUserName(UserName);                               //登录用户  
	m_db.setPassword(Password);                           //密码  
	m_bConnected = m_db.open();
	if (!m_bConnected)                                      //打开数据库  
	{
		qDebug() << m_db.lastError().text();
		errMsg = m_db.lastError().text();
		return false;                                   //打开失败  
	}
	else
		qDebug() << "database open success!";
	return true;
}

QString CDatabaseOperator::GetDatabaseName()
{
	if (m_db.isOpen())
	{
		return m_db.databaseName();
	}
	return NULL;
}

bool CDatabaseOperator::DisconnectDatabase(QString &errMsg)
{
	qDebug() << "close database";
	if (m_db.isOpen())
	{
		m_db.close();
		return true;
	}
	else
	{
		qDebug() << m_db.lastError().text();
		errMsg = m_db.lastError().text();
		return false;
	}
}

bool CDatabaseOperator::execSql(QString sql, QTableData &TableData, QString &errMsg)
{
	qDebug() << "exec sql:" << sql;//sql查询指令
	bool rv = false;
	if (m_db.isOpen())//若打开数据可连接
	{
		QSqlQuery query(m_db);//查询数据库
		rv = query.exec(sql);//查询的结果集
		if (rv)
		{
			while (query.next())//next() ：query指向下一条记录，每执行一次该函数，便指向相邻的下一条记录。
			{
				int count = query.record().count(); //获取每条记录中属性（即列）的个数
				QList<QVariant> OneRowData;
				for (int i = 0; i < count; ++i)
				{
					OneRowData.push_back(query.value(i));//value(int n) ：获得属性的值。其中n表示你查询的第n个属性
				}
				TableData.push_back(OneRowData);
			}
		}
		else
		{
			errMsg = query.lastError().text();
		}
	}
	else
	{
		errMsg = QString::fromLocal8Bit("数据库未连接");
	}
	return rv;
}