#pragma execution_character_set("utf-8")

#include "PrintApi.h"
#include <QtPrintSupport/QPrintPreviewDialog>
#include <QApplication>
#include <QDesktopWidget>
#include <QTextDocument>
#include <QPrinterInfo>
#include "QPainter"

PrintAPI *PrintAPI::_instance = 0;
PrintAPI::PrintAPI(QObject *parent) :
	QObject(parent)
{
}


void PrintAPI::PrintGridA2(QVector<QStringList> content)
{
	QList<int> ColumnWidth;
	ColumnWidth.push_back(60);
	ColumnWidth.push_back(190);
	ColumnWidth.push_back(120);
	ColumnWidth.push_back(200);
	ColumnWidth.push_back(50);
	ColumnWidth.push_back(60);
	ColumnWidth.push_back(190);
	QStringList ColumnNames;
	ColumnNames << tr("���") << tr("װ������") << tr("װ��(����)����");
	ColumnNames << tr("��װ���") << tr("������λ") << tr("����") << tr("��ע");


	//���ԭ������,ȷ��ÿ�ζ����µ�����
	html.clear();

	//����
	html.append("<tr><td align='center' style='vertical-align:middle;font-weight:bold;'>");
	html.append(tr("��A.2 ���۱��Ͼ�еװ��װ���嵥"));
	html.append("</td></tr>");
	html.append("<br><br/>");

	//���ʼ
	html.append("<table border='0.5' cellspacing='0' cellpadding='3'>");
	//��λ����
	html.append("<tr>");
	html.append(QString("<td align='left' style='vertical-align:middle;' colspan='%1'>")
		.arg(5));
	html.append(tr("��λ����:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;���:"));
	html.append("</td>");

	//ʱ��
	html.append(QString("<td align='left' style='vertical-align:middle;' colspan='%1'>")
		.arg(2));
	html.append(tr("ʱ��:&nbsp;&nbsp;&nbsp;&nbsp;��&nbsp;&nbsp;&nbsp;��&nbsp;&nbsp;&nbsp;��"));
	html.append("</td>");
	html.append("</tr>");

	//�ֶ�����
	html.append("<tr>");
	for (int i = 0; i < ColumnNames.size(); i++)
	{
		html.append(QString("<td width='%1' bgcolor='lightgray' align='center' style='vertical-align:middle;'>")
			.arg(ColumnWidth.at(i)));
		html.append(ColumnNames.at(i));
		html.append("</td>");
	}
	html.append("</tr>");
	for (int i = 0; i < content.size(); ++i)
	{
		html.append("<tr>");
		QStringList value = content.at(i);
		for (int j = 0; j < value.size(); j++)
		{
			html.append(QString("<td width='%1' align='center' style='vertical-align:middle'>")
				.arg(ColumnWidth.at(j)));
			html.append(value.at(j));
			html.append("</td>");
		}
		html.append("</tr>");
	}
	
	//������
	html.append("<tr>");
	html.append(QString("<td align='left' style='vertical-align:middle;' colspan='%1'>")
		.arg(3));
	html.append(tr("������:"));
	html.append("</td>");

	//������
	html.append(QString("<td align='left' style='vertical-align:middle;' colspan='%1'>")
		.arg(2));
	html.append(tr("������:"));
	html.append("</td>");

	//������
	html.append(QString("<td align='left' style='vertical-align:middle;' colspan='%1'>")
		.arg(2));
	html.append(tr("������:"));
	html.append("</td>");
	html.append("</tr>");

	html.append("</table>");

	html.append("<tr><td style='font-weight:bold;'>");
	html.append(tr("��д˵��:"));
	html.append("</td></tr>");

	html.append("<tr> <td> &nbsp; &nbsp; ���嵥һʽ���ݣ��������ճ��һ��</td></tr>");
	//html.append(tr("&nbsp;&nbsp;&nbsp;&nbsp;���嵥һʽ���ݣ��������ճ��һ��"));
	//html.append("</td></tr>");

	//���ô�ӡ����ӡ
	QPrinter printer;
	//���������ʽ
	printer.setOutputFormat(QPrinter::NativeFormat);
	//����ֽ�Ź��
	printer.setPageSize(QPrinter::A4);
	//���ú�������ҳ�߾�		
	printer.setOrientation(QPrinter::Landscape);
	printer.setPageMargins(10, 10, 10, 20, QPrinter::Millimeter);

	QPrintPreviewDialog preview(&printer);
	preview.setWindowTitle("��ӡԤ��");
	connect(&preview, SIGNAL(paintRequested(QPrinter *)), this, SLOT(printView(QPrinter *)));
	preview.setGeometry(qApp->desktop()->availableGeometry());
	preview.exec();
}

void PrintAPI::PrintGridA3(QStringList content)
{
	if (content.size() != 9)
	{
		return;
	}

	QList<int> ColumnWidth;
	ColumnWidth.push_back(150);
	ColumnWidth.push_back(250);
	ColumnWidth.push_back(150);
	ColumnWidth.push_back(250);
	QStringList ColumnNames;
	ColumnNames << tr("װ������") << content.at(0) << tr("װ��(����)����") << content.at(1);
	//���ԭ������,ȷ��ÿ�ζ����µ�����
	html.clear();

	//����
	html.append("<tr><td align='center' style='vertical-align:middle;font-weight:bold;'>");
	html.append(tr("��A.3 ���۱��Ͼ�еװ����װ��Ƭ"));
	html.append("</td></tr>");
	html.append("<br><br/>");


	//���ʼ
	html.append("<table border='0.5' cellspacing='0' cellpadding='3'>");

	//�ֶ����Ƶ�һ��
	html.append("<tr>");
	for (int i = 0; i < ColumnWidth.size(); i++)
	{
		html.append(QString("<td width='%1' align='center' style='vertical-align:middle;'>")
			.arg(ColumnWidth.at(i)));
		html.append(ColumnNames.at(i));
		html.append("</td>");
	}
	html.append("</tr>");

	//�ڶ���
	//��װ���
	html.append("<tr>");
	html.append(QString("<td align='center' style='vertical-align:middle;' colspan='%1'>")
		.arg(1));
	html.append(tr("��װ���"));
	html.append("</td>");

	html.append(QString("<td align='center' style='vertical-align:middle;' colspan='%1'>")
		.arg(3));
	html.append(content.at(2));
	html.append("</td></tr>");

	//������
	//���۱����ļ���
	html.append("<tr>");
	html.append(QString("<td align='center' style='vertical-align:middle;' colspan='%1'>")
		.arg(1));
	html.append(tr("���۱����ļ���"));
	html.append("</td>");

	html.append(QString("<td align='center' style='vertical-align:middle;' colspan='%1'>")
		.arg(3));
	html.append(content.at(3));
	html.append("</td></tr>");

	//������
	//���۱���װ���������ƾ֤��
	html.append("<tr>");
	html.append(QString("<td align='center' style='vertical-align:middle;' colspan='%1'>")
		.arg(1));
	html.append(tr("���۱���װ���������ƾ֤��"));
	html.append("</td>");

	html.append(QString("<td align='center' style='vertical-align:middle;' colspan='%1'>")
		.arg(3));
	html.append(content.at(4));
	html.append("</td></tr>");

	//������
	//����ʱ��
	html.append("<tr>");
	html.append(QString("<td align='center' style='vertical-align:middle;' colspan='%1'>")
		.arg(1));
	html.append(tr("����ʱ��"));
	html.append("</td>");

	html.append(QString("<td align='center' style='vertical-align:middle;' colspan='%1'>")
		.arg(1));
	html.append(content.at(5));
	html.append("</td>");

	//װ��ʱ��
	html.append(QString("<td align='center' style='vertical-align:middle;' colspan='%1'>")
		.arg(1));
	html.append(tr("װ��ʱ��"));
	html.append("</td>");

	html.append(QString("<td align='center' style='vertical-align:middle;' colspan='%1'>")
		.arg(1));
	html.append(content.at(6));
	html.append("</td></tr>");

	//������
	//������λ
	html.append("<tr>");
	html.append(QString("<td align='center' style='vertical-align:middle;' colspan='%1'>")
		.arg(1));
	html.append(tr("������λ"));
	html.append("</td>");

	html.append(QString("<td align='center' style='vertical-align:middle;' colspan='%1'>")
		.arg(1));
	html.append(content.at(7));
	html.append("</td>");

	//����λ
	html.append(QString("<td align='center' style='vertical-align:middle;' colspan='%1'>")
		.arg(1));
	html.append(tr("����λ"));
	html.append("</td>");

	html.append(QString("<td align='center' style='vertical-align:middle;' colspan='%1'>")
		.arg(1));
	html.append(content.at(8));
	html.append("</td></tr>");
	html.append("</table>");

	//������ ������  ������
	html.append("<tr> <td>");
	html.append(tr("������:&nbsp; &nbsp; &nbsp; &nbsp;&nbsp; &nbsp; &nbsp; &nbsp;"));
	html.append(tr("������:&nbsp; &nbsp; &nbsp; &nbsp;&nbsp; &nbsp; &nbsp; &nbsp;"));
	html.append(tr("������:</td></tr>"));
	//ʱ��
	html.append("<tr> <td>&nbsp; &nbsp; &nbsp; &nbsp;&nbsp;&nbsp; &nbsp; &nbsp; &nbsp;&nbsp; &nbsp; &nbsp; &nbsp;&nbsp; &nbsp; &nbsp; &nbsp;&nbsp; &nbsp; &nbsp; &nbsp; ʱ��:</td></tr>");

	html.append("<tr><td style='font-weight:bold;'>");
	html.append(tr("��д˵��:"));
	html.append("</td></tr>");

	html.append("<tr> <td> &nbsp; &nbsp; 1.�����۱����ļ��š���дս��½��(ԭ�ܲ�������)�ļ���;</td></tr>");
	html.append("<tr> <td> &nbsp; &nbsp; 2.������λ����д���۱���װ���������ƾ֤����ȷ��װ�����յ�λ��</td></tr>");
	//���ô�ӡ����ӡ
	QPrinter printer;
	//���������ʽ
	printer.setOutputFormat(QPrinter::NativeFormat);
	//����ֽ�Ź��
	printer.setPageSize(QPrinter::A4);
	//���ú�������ҳ�߾�		
	printer.setOrientation(QPrinter::Landscape);
	printer.setPageMargins(10, 10, 10, 20, QPrinter::Millimeter);


	QPrintPreviewDialog preview(&printer);
	preview.setWindowTitle("��ӡԤ��");
	connect(&preview, SIGNAL(paintRequested(QPrinter *)), this, SLOT(printView(QPrinter *)));
	preview.setGeometry(qApp->desktop()->availableGeometry());
	preview.exec();
}

void PrintAPI::PrintGridA9()
{
	//��A.9 ���۱���ǹе���ٴ������ȫ���̵ǼǱ�
	//���ô�ӡ����ӡ
	QPrinter printer;
	//���������ʽ
	printer.setOutputFormat(QPrinter::NativeFormat);
	//����ֽ�Ź��
	printer.setPageSize(QPrinter::A4);
	//���ú�������ҳ�߾�		
	printer.setOrientation(QPrinter::Landscape);
	printer.setPageMargins(10, 10, 10, 20, QPrinter::Millimeter);


	QPrintPreviewDialog preview(&printer);
	preview.setWindowTitle("��ӡԤ��");
	connect(&preview, SIGNAL(paintRequested(QPrinter *)), this, SLOT(plotPic(QPrinter *)));
	preview.setGeometry(qApp->desktop()->availableGeometry());
	preview.exec();
}

void PrintAPI::PrintA4(QString title, QString subTitle, QList<QString> columnNames,
	QList<int> columnWidths, QStringList content, bool landscape, bool check,
	QPrinter::PageSize pageSize)
{
	//������������
	int columnCount = columnNames.count();
	int rowCount = content.count();

	//���ԭ������,ȷ��ÿ�ζ����µ�����
	html.clear();

	//���ʼ
	html.append("<table border='0.5' cellspacing='0' cellpadding='3'>");

	//����ռһ��,������ʾ
	if (title.length() > 0)
	{
		html.append(QString("<tr><td align='center' style='vertical-align:middle;font-weight:bold;' colspan='%1'>")
			.arg(columnCount));
		html.append(title);
		html.append("</td></tr>");
	}

	//������ռһ��,�������ʾ
	if (subTitle.length() > 0) 
	{
		html.append(QString("<tr><td align='left' style='vertical-align:middle;' colspan='%1'>")
			.arg(columnCount));
		html.append(subTitle);
		html.append("</td></tr>");
	}

	//ѭ��д���ֶ���,�ֶ���ռһ��,������ʾ
	if (columnCount > 0)
	{
		html.append("<tr>");
		for (int i = 0; i < columnCount; i++)
		{
			html.append(QString("<td width='%1' bgcolor='lightgray' align='center' style='vertical-align:middle;'>")
				.arg(columnWidths.at(i)));
			html.append(columnNames.at(i));
			html.append("</td>");
		}
		html.append("</tr>");
	}

	//ѭ��һ���й�������
	for (int i = 0; i < rowCount; i++)
	{
		QStringList value = content.at(i).split(";");
		html.append("<tr>");

		if (check) 
		{
			if (value.at(value.count() - 1) == "��ʷ��¼") 
			{
				for (int j = 0; j < columnCount; j++)
				{
					html.append(QString("<td width='%1' align='center' style='vertical-align:middle;'>"
						"<font color='red'>").arg(columnWidths.at(j)));
					html.append(value.at(j));
					html.append("</font></td>");
				}
			}
			else
			{
				for (int j = 0; j < columnCount; j++)
				{
					html.append(QString("<td width='%1' align='center' style='vertical-align:middle;'>")
						.arg(columnWidths.at(j)));
					html.append(value.at(j));
					html.append("</td>");
				}
			}
		}
		else 
		{
			for (int j = 0; j < columnCount; j++)
			{
				html.append(QString("<td width='%1' align='center' style='vertical-align:middle;'>")
					.arg(columnWidths.at(j)));
				html.append(value.at(j));
				html.append("</td>");
			}
		}
		html.append("</tr>");
	}
	html.append("</table>");

	//���ô�ӡ����ӡ
	QPrinter printer;
	//���������ʽ
	printer.setOutputFormat(QPrinter::NativeFormat);
	//����ֽ�Ź��
	printer.setPageSize(pageSize);
	//���ú�������ҳ�߾�
	if (landscape) 
	{
		printer.setOrientation(QPrinter::Landscape);
		printer.setPageMargins(10, 10, 10, 12, QPrinter::Millimeter);
	}
	else 
	{
		printer.setOrientation(QPrinter::Portrait);
		printer.setPageMargins(10, 10, 10, 16, QPrinter::Millimeter);
	}

	QPrintPreviewDialog preview(&printer);
	preview.setWindowTitle("��ӡԤ��");
	connect(&preview, SIGNAL(paintRequested(QPrinter *)), this, SLOT(printView(QPrinter *)));
	preview.setGeometry(qApp->desktop()->availableGeometry());
	preview.exec();
}

//��A.4 ���۱��Ͼ�еװ�������������ӻ��ܱ�
void PrintAPI::PrintA4(QString title, QList<QString> columnNames, QList<int> columnWidths,
	QStringList subTitle1, QStringList subTitle2,
	QStringList content, bool landscape, bool check,
	QPrinter::PageSize pageSize)
{
	//��������
	int columnCount = columnNames.count();

	//���ԭ������,ȷ��ÿ�ζ����µ�����
	html.clear();

	//���ʼ
	html.append("<table border='0.5' cellspacing='0' cellpadding='3'>");

	//����ռһ��,������ʾ
	if (title.length() > 0) {
		html.append(QString("<tr><td align='center' style='vertical-align:middle;font-weight:bold;' colspan='%1'>")
			.arg(columnCount));
		html.append(title);
		html.append("</td></tr>");
	}

	//ѭ����Ӹ�����/�ֶ���/����
	int count = content.count();
	for (int i = 0; i < count; i++) {
		//�Ӹ����и���
		html.append(QString("<tr><td colspan='%1'>").arg(columnCount));
		html.append("</td></tr>");

		//������1
		if (subTitle1.count() > 0 && subTitle1.count() > i) {
			if (subTitle1.at(i).length() > 0) {
				html.append(QString("<tr><td align='left' style='vertical-align:middle;' colspan='%1'>")
					.arg(columnCount));
				html.append(subTitle1.at(i));
				html.append("</td></tr>");
			}
		}

		//������2
		if (subTitle2.count() > 0 && subTitle2.count() > i) {
			if (subTitle2.at(i).length() > 0) {
				html.append(QString("<tr><td align='left' style='vertical-align:middle;' colspan='%1'>")
					.arg(columnCount));
				html.append(subTitle2.at(i));
				html.append("</td></tr>");
			}
		}

		//�������ֶ�����
		if (columnCount > 0) {
			html.append("<tr>");
			for (int i = 0; i < columnCount; i++) {
				html.append(QString("<td width='%1' bgcolor='lightgray' align='center' style='vertical-align:middle;'>")
					.arg(columnWidths.at(i)));
				html.append(columnNames.at(i));
				html.append("</td>");
			}
			html.append("</tr>");
		}

		QStringList list = content.at(i).split(";");

		//����������
		int rowCount = list.count();
		for (int j = 0; j < rowCount; j++) {
			html.append("<tr>");

			QString temp = list.at(j);
			QStringList value = temp.split("|");
			int valueCount = value.count();

			if (check) {
				//�������ʷ��¼�����ֺ�ɫ
				if (value.at(valueCount - 1) == "1") {
					for (int k = 0; k < valueCount - 1; k++) {
						html.append(QString("<td width='%1' align='center' style='vertical-align:middle;'>"
							"<font color='red'>").arg(columnWidths.at(k)));
						html.append(value.at(k));
						html.append("</font></td>");
					}
				}
				else {
					for (int k = 0; k < valueCount - 1; k++) {
						html.append(QString("<td width='%1' align='center' style='vertical-align:middle;'>")
							.arg(columnWidths.at(k)));
						html.append(value.at(k));
						html.append("</td>");
					}
				}
			}
			else {
				for (int k = 0; k < valueCount; k++) {
					html.append(QString("<td width='%1' align='center' style='vertical-align:middle;'>")
						.arg(columnWidths.at(k)));
					html.append(value.at(k));
					html.append("</td>");
				}
			}

			html.append("</tr>");
		}
	}

	html.append("</table>");

	//���ô�ӡ����ӡ
	QPrinter printer;
	//���������ʽ
	printer.setOutputFormat(QPrinter::NativeFormat);
	//����ֽ�Ź��
	printer.setPageSize(pageSize);
	//���ú�������ҳ�߾�
	if (landscape) {
		printer.setOrientation(QPrinter::Landscape);
		printer.setPageMargins(10, 10, 10, 12, QPrinter::Millimeter);
	}
	else {
		printer.setOrientation(QPrinter::Portrait);
		printer.setPageMargins(10, 10, 10, 16, QPrinter::Millimeter);
	}

	QPrintPreviewDialog preview(&printer);
	preview.setWindowTitle("��ӡԤ��");
	connect(&preview, SIGNAL(paintRequested(QPrinter *)), this, SLOT(printView(QPrinter *)));
	preview.setGeometry(qApp->desktop()->availableGeometry());
	preview.exec();
}

void PrintAPI::printView(QPrinter *printer)
{
	QTextDocument txt;
	txt.setHtml(html.join(""));
	txt.print(printer);
}

void PrintAPI::plotPic(QPrinter *printer)
{
	QPainter painter(printer);				//ָ����ͼ�豸Ϊһ��QPrinter����
	QRect rect = painter.viewport();         //���QPainter�������ͼ��������
	QImage img("D:\\SmartMore\\Code\\ǹ֧��Ϣ����ϵͳ\\GunManagementSystem\\x64\\Release\\A9.bmp");
	QSize size = img.size();				//���ͼ��Ĵ�С
	/* ����ͼ�εı�����С����������ͼ�������� */
	size.scale(rect.size(), Qt::KeepAspectRatio);
	painter.setViewport(rect.x(), rect.y(), size.width(), size.height());
	painter.setWindow(img.rect());          //����QPainter���ڴ�СΪͼ��Ĵ�С
	painter.drawImage(0, 0, img);
}