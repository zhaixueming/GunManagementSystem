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

CDatabaseOperator *CDatabaseOperator::GetInstance()//����ģʽ
{
	if (m_Instance == NULL)
	{
		m_Instance = new CDatabaseOperator();
	}
	return m_Instance;
}

void CDatabaseOperator::InitVariabled()
{
	m_db = QSqlDatabase::addDatabase("QODBC");//addDatabase����������
	m_bConnected = false;


	m_db.setHostName("local");                        //ѡ�񱾵�������127.0.1.1  
	m_db.setDatabaseName("GunManager");                            //��������Դ����  
	m_db.setUserName("sa");                               //���õ�¼�û�  
	//m_db.setPassword("k-touch1234");   
	m_db.setPassword("zhai6688/");//��������                   
	m_bConnected = m_db.open();    //�����ݿ�����
}

bool CDatabaseOperator::ConnectDatabase( QString DatabaseName, QString UserName, QString Password, QString &errMsg)
{
	qDebug() << "connect database:" << DatabaseName << "," << UserName;
	qDebug() << "ODBC driver?" << m_db.isValid();
	QString dsn = QString::fromLocal8Bit("QTDSN");      //����Դ����  
	m_db.setHostName("local");                        //ѡ�񱾵�������127.0.1.1  
	m_db.setDatabaseName(DatabaseName);                            //��������Դ����  
	m_db.setUserName(UserName);                               //��¼�û�  
	m_db.setPassword(Password);                           //����  
	m_bConnected = m_db.open();
	if (!m_bConnected)                                      //�����ݿ�  
	{
		qDebug() << m_db.lastError().text();
		errMsg = m_db.lastError().text();
		return false;                                   //��ʧ��  
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
	qDebug() << "exec sql:" << sql;//sql��ѯָ��
	bool rv = false;
	if (m_db.isOpen())//�������ݿ�����
	{
		QSqlQuery query(m_db);//��ѯ���ݿ�
		rv = query.exec(sql);//��ѯ�Ľ����
		if (rv)
		{
			while (query.next())//next() ��queryָ����һ����¼��ÿִ��һ�θú�������ָ�����ڵ���һ����¼��
			{
				int count = query.record().count(); //��ȡÿ����¼�����ԣ����У��ĸ���
				QList<QVariant> OneRowData;
				for (int i = 0; i < count; ++i)
				{
					OneRowData.push_back(query.value(i));//value(int n) ��������Ե�ֵ������n��ʾ���ѯ�ĵ�n������
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
		errMsg = QString::fromLocal8Bit("���ݿ�δ����");
	}
	return rv;
}