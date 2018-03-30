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
//����������
void workerThread::run()
{
	if (!tcpServer->listen(QHostAddress::Any,port.toInt()))
	{
		quit();//����ʧ�ܣ��˳�����
	}
}
bool workerThread::isPortOccupied(QString const port)
{
	//������bind���ж϶˿��Ƿ�ר��
	if (tcpSocket->bind(QHostAddress::Any, port.toInt(), QAbstractSocket::DontShareAddress) == true)
	{
		tcpSocket->abort();
		return false;
	}
	return true;
}