#include "SysMainWindow.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	SysMainWindow w;
	w.show();
	return a.exec();
}
