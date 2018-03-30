#include "workerThread.h"
#include <QException>
workerThread::workerThread(QObject *parent)
	: QThread(parent)
{
	tcpServer = new QTcpServer();
	tcpSocket = new QTcpSocket();
}

workerThread::~workerThread()
{
	delete tcpServer;
	delete tcpSocket;
}
void workerThread::setPort(QString port)
{
	this->port = port;
}
//启动服务器
void workerThread::run()
{
	if (!tcpServer->listen(QHostAddress::Any,port.toInt()))
	{
		quit();//监听失败，退出程序
	}
}
bool workerThread::isPortOccupied(QString const port)
{
	//尝试性bind，判断端口是否被专用
	if (tcpSocket->bind(QHostAddress::Any, port.toInt(), QAbstractSocket::DontShareAddress) == true)
	{
		tcpSocket->abort();
		return false;
	}
	return true;
}