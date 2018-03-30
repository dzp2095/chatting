#ifndef WORKERTHREAD_H
#define WORKERTHREAD_H

#include <QThread>
#include <QTcpServer>
#include "serverworker.h"
#include <QTcpSocket>
class workerThread : public QThread
{
	Q_OBJECT

public:
	workerThread(QObject *parent);
	~workerThread();
	void setPort(QString port);
	void run();
	bool isPortOccupied(QString const port);//�ж϶˿��Ƿ�ռ��
	QTcpServer *tcpServer;
private:
	QString port;
	QTcpSocket *tcpSocket;
};

#endif // WORKERTHREAD_H
