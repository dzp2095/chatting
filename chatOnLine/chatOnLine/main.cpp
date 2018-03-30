#include "loginDlg.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	loginDlg w;
	w.show();
	return a.exec();
}
