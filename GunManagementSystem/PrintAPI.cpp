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
	ColumnNames << tr("序号") << tr("装备代码") << tr("装备(部件)名称");
	ColumnNames << tr("单装编号") << tr("计量单位") << tr("数量") << tr("备注");


	//清空原有数据,确保每次都是新的数据
	html.clear();

	//标题
	html.append("<tr><td align='center' style='vertical-align:middle;font-weight:bold;'>");
	html.append(tr("表A.2 退役报废军械装备装箱清单"));
	html.append("</td></tr>");
	html.append("<br><br/>");

	//表格开始
	html.append("<table border='0.5' cellspacing='0' cellpadding='3'>");
	//单位名称
	html.append("<tr>");
	html.append(QString("<td align='left' style='vertical-align:middle;' colspan='%1'>")
		.arg(5));
	html.append(tr("单位名称:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;箱号:"));
	html.append("</td>");

	//时间
	html.append(QString("<td align='left' style='vertical-align:middle;' colspan='%1'>")
		.arg(2));
	html.append(tr("时间:&nbsp;&nbsp;&nbsp;&nbsp;年&nbsp;&nbsp;&nbsp;月&nbsp;&nbsp;&nbsp;日"));
	html.append("</td>");
	html.append("</tr>");

	//字段名称
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
	
	//负责人
	html.append("<tr>");
	html.append(QString("<td align='left' style='vertical-align:middle;' colspan='%1'>")
		.arg(3));
	html.append(tr("负责人:"));
	html.append("</td>");

	//经办人
	html.append(QString("<td align='left' style='vertical-align:middle;' colspan='%1'>")
		.arg(2));
	html.append(tr("经办人:"));
	html.append("</td>");

	//验收人
	html.append(QString("<td align='left' style='vertical-align:middle;' colspan='%1'>")
		.arg(2));
	html.append(tr("验收人:"));
	html.append("</td>");
	html.append("</tr>");

	html.append("</table>");

	html.append("<tr><td style='font-weight:bold;'>");
	html.append(tr("填写说明:"));
	html.append("</td></tr>");

	html.append("<tr> <td> &nbsp; &nbsp; 该清单一式两份，箱内外各粘贴一份</td></tr>");
	//html.append(tr("&nbsp;&nbsp;&nbsp;&nbsp;该清单一式两份，箱内外各粘贴一份"));
	//html.append("</td></tr>");

	//调用打印机打印
	QPrinter printer;
	//设置输出格式
	printer.setOutputFormat(QPrinter::NativeFormat);
	//设置纸张规格
	printer.setPageSize(QPrinter::A4);
	//设置横向纵向及页边距		
	printer.setOrientation(QPrinter::Landscape);
	printer.setPageMargins(10, 10, 10, 20, QPrinter::Millimeter);

	QPrintPreviewDialog preview(&printer);
	preview.setWindowTitle("打印预览");
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
	ColumnNames << tr("装备代码") << content.at(0) << tr("装备(部件)名称") << content.at(1);
	//清空原有数据,确保每次都是新的数据
	html.clear();

	//标题
	html.append("<tr><td align='center' style='vertical-align:middle;font-weight:bold;'>");
	html.append(tr("表A.3 退役报废军械装备单装卡片"));
	html.append("</td></tr>");
	html.append("<br><br/>");


	//表格开始
	html.append("<table border='0.5' cellspacing='0' cellpadding='3'>");

	//字段名称第一行
	html.append("<tr>");
	for (int i = 0; i < ColumnWidth.size(); i++)
	{
		html.append(QString("<td width='%1' align='center' style='vertical-align:middle;'>")
			.arg(ColumnWidth.at(i)));
		html.append(ColumnNames.at(i));
		html.append("</td>");
	}
	html.append("</tr>");

	//第二行
	//单装编号
	html.append("<tr>");
	html.append(QString("<td align='center' style='vertical-align:middle;' colspan='%1'>")
		.arg(1));
	html.append(tr("单装编号"));
	html.append("</td>");

	html.append(QString("<td align='center' style='vertical-align:middle;' colspan='%1'>")
		.arg(3));
	html.append(content.at(2));
	html.append("</td></tr>");

	//第三行
	//退役报废文件号
	html.append("<tr>");
	html.append(QString("<td align='center' style='vertical-align:middle;' colspan='%1'>")
		.arg(1));
	html.append(tr("退役报废文件号"));
	html.append("</td>");

	html.append(QString("<td align='center' style='vertical-align:middle;' colspan='%1'>")
		.arg(3));
	html.append(content.at(3));
	html.append("</td></tr>");

	//第四行
	//退役报废装备处理调拨凭证号
	html.append("<tr>");
	html.append(QString("<td align='center' style='vertical-align:middle;' colspan='%1'>")
		.arg(1));
	html.append(tr("退役报废装备处理调拨凭证号"));
	html.append("</td>");

	html.append(QString("<td align='center' style='vertical-align:middle;' colspan='%1'>")
		.arg(3));
	html.append(content.at(4));
	html.append("</td></tr>");

	//第五行
	//出厂时间
	html.append("<tr>");
	html.append(QString("<td align='center' style='vertical-align:middle;' colspan='%1'>")
		.arg(1));
	html.append(tr("出厂时间"));
	html.append("</td>");

	html.append(QString("<td align='center' style='vertical-align:middle;' colspan='%1'>")
		.arg(1));
	html.append(content.at(5));
	html.append("</td>");

	//装备时间
	html.append(QString("<td align='center' style='vertical-align:middle;' colspan='%1'>")
		.arg(1));
	html.append(tr("装备时间"));
	html.append("</td>");

	html.append(QString("<td align='center' style='vertical-align:middle;' colspan='%1'>")
		.arg(1));
	html.append(content.at(6));
	html.append("</td></tr>");

	//第六行
	//隶属单位
	html.append("<tr>");
	html.append(QString("<td align='center' style='vertical-align:middle;' colspan='%1'>")
		.arg(1));
	html.append(tr("隶属单位"));
	html.append("</td>");

	html.append(QString("<td align='center' style='vertical-align:middle;' colspan='%1'>")
		.arg(1));
	html.append(content.at(7));
	html.append("</td>");

	//管理单位
	html.append(QString("<td align='center' style='vertical-align:middle;' colspan='%1'>")
		.arg(1));
	html.append(tr("管理单位"));
	html.append("</td>");

	html.append(QString("<td align='center' style='vertical-align:middle;' colspan='%1'>")
		.arg(1));
	html.append(content.at(8));
	html.append("</td></tr>");
	html.append("</table>");

	//负责人 经办人  验收人
	html.append("<tr> <td>");
	html.append(tr("负责人:&nbsp; &nbsp; &nbsp; &nbsp;&nbsp; &nbsp; &nbsp; &nbsp;"));
	html.append(tr("经办人:&nbsp; &nbsp; &nbsp; &nbsp;&nbsp; &nbsp; &nbsp; &nbsp;"));
	html.append(tr("验收人:</td></tr>"));
	//时间
	html.append("<tr> <td>&nbsp; &nbsp; &nbsp; &nbsp;&nbsp;&nbsp; &nbsp; &nbsp; &nbsp;&nbsp; &nbsp; &nbsp; &nbsp;&nbsp; &nbsp; &nbsp; &nbsp;&nbsp; &nbsp; &nbsp; &nbsp; 时间:</td></tr>");

	html.append("<tr><td style='font-weight:bold;'>");
	html.append(tr("填写说明:"));
	html.append("</td></tr>");

	html.append("<tr> <td> &nbsp; &nbsp; 1.“退役报废文件号”填写战区陆军(原总部、军区)文件号;</td></tr>");
	html.append("<tr> <td> &nbsp; &nbsp; 2.“管理单位”填写退役报废装备处理调拨凭证中明确的装备接收单位。</td></tr>");
	//调用打印机打印
	QPrinter printer;
	//设置输出格式
	printer.setOutputFormat(QPrinter::NativeFormat);
	//设置纸张规格
	printer.setPageSize(QPrinter::A4);
	//设置横向纵向及页边距		
	printer.setOrientation(QPrinter::Landscape);
	printer.setPageMargins(10, 10, 10, 20, QPrinter::Millimeter);


	QPrintPreviewDialog preview(&printer);
	preview.setWindowTitle("打印预览");
	connect(&preview, SIGNAL(paintRequested(QPrinter *)), this, SLOT(printView(QPrinter *)));
	preview.setGeometry(qApp->desktop()->availableGeometry());
	preview.exec();
}

void PrintAPI::PrintGridA9()
{
	//表A.9 退役报废枪械销毁处理情况全过程登记表
	//调用打印机打印
	QPrinter printer;
	//设置输出格式
	printer.setOutputFormat(QPrinter::NativeFormat);
	//设置纸张规格
	printer.setPageSize(QPrinter::A4);
	//设置横向纵向及页边距		
	printer.setOrientation(QPrinter::Landscape);
	printer.setPageMargins(10, 10, 10, 20, QPrinter::Millimeter);


	QPrintPreviewDialog preview(&printer);
	preview.setWindowTitle("打印预览");
	connect(&preview, SIGNAL(paintRequested(QPrinter *)), this, SLOT(plotPic(QPrinter *)));
	preview.setGeometry(qApp->desktop()->availableGeometry());
	preview.exec();
}

void PrintAPI::PrintA4(QString title, QString subTitle, QList<QString> columnNames,
	QList<int> columnWidths, QStringList content, bool landscape, bool check,
	QPrinter::PageSize pageSize)
{
	//计算行数列数
	int columnCount = columnNames.count();
	int rowCount = content.count();

	//清空原有数据,确保每次都是新的数据
	html.clear();

	//表格开始
	html.append("<table border='0.5' cellspacing='0' cellpadding='3'>");

	//标题占一行,居中显示
	if (title.length() > 0)
	{
		html.append(QString("<tr><td align='center' style='vertical-align:middle;font-weight:bold;' colspan='%1'>")
			.arg(columnCount));
		html.append(title);
		html.append("</td></tr>");
	}

	//副标题占一行,左对齐显示
	if (subTitle.length() > 0) 
	{
		html.append(QString("<tr><td align='left' style='vertical-align:middle;' colspan='%1'>")
			.arg(columnCount));
		html.append(subTitle);
		html.append("</td></tr>");
	}

	//循环写入字段名,字段名占一行,居中显示
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

	//循环一行行构建数据
	for (int i = 0; i < rowCount; i++)
	{
		QStringList value = content.at(i).split(";");
		html.append("<tr>");

		if (check) 
		{
			if (value.at(value.count() - 1) == "历史记录") 
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

	//调用打印机打印
	QPrinter printer;
	//设置输出格式
	printer.setOutputFormat(QPrinter::NativeFormat);
	//设置纸张规格
	printer.setPageSize(pageSize);
	//设置横向纵向及页边距
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
	preview.setWindowTitle("打印预览");
	connect(&preview, SIGNAL(paintRequested(QPrinter *)), this, SLOT(printView(QPrinter *)));
	preview.setGeometry(qApp->desktop()->availableGeometry());
	preview.exec();
}

//表A.4 退役报废军械装备（部件）交接汇总表
void PrintAPI::PrintA4(QString title, QList<QString> columnNames, QList<int> columnWidths,
	QStringList subTitle1, QStringList subTitle2,
	QStringList content, bool landscape, bool check,
	QPrinter::PageSize pageSize)
{
	//计算列数
	int columnCount = columnNames.count();

	//清空原有数据,确保每次都是新的数据
	html.clear();

	//表格开始
	html.append("<table border='0.5' cellspacing='0' cellpadding='3'>");

	//标题占一行,居中显示
	if (title.length() > 0) {
		html.append(QString("<tr><td align='center' style='vertical-align:middle;font-weight:bold;' colspan='%1'>")
			.arg(columnCount));
		html.append(title);
		html.append("</td></tr>");
	}

	//循环添加副标题/字段名/内容
	int count = content.count();
	for (int i = 0; i < count; i++) {
		//加个空行隔开
		html.append(QString("<tr><td colspan='%1'>").arg(columnCount));
		html.append("</td></tr>");

		//副标题1
		if (subTitle1.count() > 0 && subTitle1.count() > i) {
			if (subTitle1.at(i).length() > 0) {
				html.append(QString("<tr><td align='left' style='vertical-align:middle;' colspan='%1'>")
					.arg(columnCount));
				html.append(subTitle1.at(i));
				html.append("</td></tr>");
			}
		}

		//副标题2
		if (subTitle2.count() > 0 && subTitle2.count() > i) {
			if (subTitle2.at(i).length() > 0) {
				html.append(QString("<tr><td align='left' style='vertical-align:middle;' colspan='%1'>")
					.arg(columnCount));
				html.append(subTitle2.at(i));
				html.append("</td></tr>");
			}
		}

		//逐个添加字段名称
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

		//逐个添加数据
		int rowCount = list.count();
		for (int j = 0; j < rowCount; j++) {
			html.append("<tr>");

			QString temp = list.at(j);
			QStringList value = temp.split("|");
			int valueCount = value.count();

			if (check) {
				//如果是历史记录则文字红色
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

	//调用打印机打印
	QPrinter printer;
	//设置输出格式
	printer.setOutputFormat(QPrinter::NativeFormat);
	//设置纸张规格
	printer.setPageSize(pageSize);
	//设置横向纵向及页边距
	if (landscape) {
		printer.setOrientation(QPrinter::Landscape);
		printer.setPageMargins(10, 10, 10, 12, QPrinter::Millimeter);
	}
	else {
		printer.setOrientation(QPrinter::Portrait);
		printer.setPageMargins(10, 10, 10, 16, QPrinter::Millimeter);
	}

	QPrintPreviewDialog preview(&printer);
	preview.setWindowTitle("打印预览");
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
	QPainter painter(printer);				//指定绘图设备为一个QPrinter对象
	QRect rect = painter.viewport();         //获得QPainter对象的视图矩形区域
	QImage img("D:\\SmartMore\\Code\\枪支信息管理系统\\GunManagementSystem\\x64\\Release\\A9.bmp");
	QSize size = img.size();				//获得图像的大小
	/* 按照图形的比例大小重新设置视图矩形区域 */
	size.scale(rect.size(), Qt::KeepAspectRatio);
	painter.setViewport(rect.x(), rect.y(), size.width(), size.height());
	painter.setWindow(img.rect());          //设置QPainter窗口大小为图像的大小
	painter.drawImage(0, 0, img);
}