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
//���пͻ��˷�����
void clientNetWorker::run()
{
	QString msg;
	//Ϊ��������˿�
	distributeLocalPort();
	//��ʾ��¼��Ϣ

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
//���ӷ�����
bool clientNetWorker::connectServer()
{
	//�Ͽ���������
	tcpSocket->abort();
	//����Զ������
	try
	{
		tcpSocket->connectToHost(QHostAddress(IPaddress), serverPort.toInt());
	}
	catch (QAbstractSocket::SocketError e)
	{
		emit connectToServerSignal(false, QString::fromLocal8Bit("���ӷ�����ʧ��,�볢�����µ�½"));
		return false;
	}
	emit connectToServerSignal(true, QString::fromLocal8Bit("��½�ɹ�"));
	return true;
}
//Ϊ��������˿�
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