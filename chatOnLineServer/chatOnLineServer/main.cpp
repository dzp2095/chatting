#include "chatonlineserver.h"
#include <QtWidgets/QApplication>
#include<QString>
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	chatOnLineServer w;
	w.show();
	return a.exec();
}
