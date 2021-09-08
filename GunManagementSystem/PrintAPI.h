#pragma once
#include <QObject>
#include <QMutex>
#include <QStringList>
#include <QtPrintSupport/QPrinter>

class PrintAPI : public QObject
{
	Q_OBJECT
private:
	explicit PrintAPI(QObject *parent = 0);//表明显式
	static PrintAPI *_instance;
	QStringList html;
public:
	static PrintAPI *Instance() {
		static QMutex mutex;
		if (!_instance) {
			QMutexLocker locker(&mutex);
			if (!_instance) {
				_instance = new PrintAPI;
			}
		}
		return _instance;
	}

	void PrintGridA2(QVector<QStringList> content);//表A.2 退役报废军械装备装箱清单
	void PrintGridA3(QStringList content);//表A.3 退役报废军械装备单装卡片
	void PrintGridA9();//表A.9 退役报废枪械销毁处理情况全过程登记表
	void PrintA4(QString title, QString subTitle,
		QList<QString> columnNames, QList<int> columnWidths,
		QStringList content, bool landscape, bool check,
		QPrinter::PageSize pageSize = QPrinter::A4);//表A.4 退役报废军械装备（部件）交接汇总表

	void PrintA4(QString title, QList<QString> columnNames, QList<int> columnWidths,
		QStringList subTitle1, QStringList subTitle2,
		QStringList content, bool landscape, bool check,
		QPrinter::PageSize pageSize = QPrinter::A4);//表A.5 退役报废军械装备（部件）交接明细表

signals:

private slots:
	void printView(QPrinter *printer);
	void plotPic(QPrinter *printer);
};


