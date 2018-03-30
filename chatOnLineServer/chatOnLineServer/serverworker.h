#ifndef SERVERWORKER_H
#define SERVERWORKER_H
#include <QString>
#include <QTcpServer>
class ServerWorker : public QTcpServer
{
	Q_OBJECT

public:
	ServerWorker(QObject *parent);
	~ServerWorker();
	static bool isPortOccupied(QString port);//判断端口是否被占用
private:
	QString port;
};

#endif // SERVERWORKER_H
