#include "clientNetWorker.h"
#include <QHostInfo>
clientNetWorker::clientNetWorker(QObject *parent,QString userName,QString IPaddress,QString port)
	: QThread(parent)
{
	this->userName = userName;
	this->IPaddress = IPaddress;
	this->serverPort = port;
	tcpSocket = new QTcpSocket();
}

clientNetWorker::~clientNetWorker()
{

}
//运行客户端服务器
void clientNetWorker::run()
{
	QString msg;
	//为本机分配端口
	distributeLocalPort();
	//显示登录信息

	if (connectServer()==false)
	{
		return;
	}

}
bool clientNetWorker::isPortOccupied(const QString port)
{
	QTcpSocket *tcpSocket=new QTcpSocket();
	if (tcpSocket->bind(QHostAddress::LocalHost,port.toInt(),QAbstractSocket::DontShareAddress) == false)
	{
		tcpSocket->abort();
		delete tcpSocket;
		return true;
	}
	return false;
}
//连接服务器
bool clientNetWorker::connectServer()
{
	//断开已有连接
	tcpSocket->abort();
	//连接远程主机
	try
	{
		tcpSocket->connectToHost(QHostAddress(IPaddress), serverPort.toInt());
	}
	catch (QAbstractSocket::SocketError e)
	{
		emit connectToServerSignal(false, QString::fromLocal8Bit("连接服务器失败,请尝试重新登陆"));
		return false;
	}
	emit connectToServerSignal(true, QString::fromLocal8Bit("登陆成功"));
	return true;
}
//为本机分配端口
void clientNetWorker::distributeLocalPort()
{
	for (int i = 8000; i < 65535;i++)
	{
		if (isPortOccupied(QString::number(i))==false)
		{
			localPort = QString::number(i);
			return;
		}
	}
}