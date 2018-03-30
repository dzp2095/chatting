#include "chatonlineserver.h"
#include <QString>
#include <QInputDialog>
#include <QMessageBox>
#include<QTime>
chatOnLineServer::chatOnLineServer(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);	
	tcpServer = new QTcpServer();
	onSetPort();
	connect(ui.actionSetPort, SIGNAL(triggered()),
		this, SLOT(onSetPort()));
	connect(tcpServer, SIGNAL(newConnection()),
		this, SLOT(onNewConnection()));
	connect(ui.actionStart, SIGNAL(triggered()),
		this, SLOT(onStartServer()));
	clientNum = 0;
	idToDistribute = 0;
}

chatOnLineServer::~chatOnLineServer()
{
	delete tcpServer;
}
void chatOnLineServer::onSetPort()
{
	QString port = QInputDialog::getText(this, QString::fromLocal8Bit("�˿�"), QString::fromLocal8Bit("������Ҫ�󶨵Ķ˿ں�"), QLineEdit::Normal);
	if (port.isEmpty() == true)
	{
		for (int i = 8000; i < 65535;i++)
		{
			if (isPortOccupied(QString::number(i))==false)
			{
				QMessageBox::information(this, QString::fromLocal8Bit("ע��"), QString::fromLocal8Bit("δ����˿ں�,�Զ����ö˿�"));
				this->port = QString::number(i);
				ui.labelPort->setText(QString::fromLocal8Bit("��ǰ�˿�").append(QString::number(i)));
				return;
			}
		}		
	}
	//�ֶ����ö˿�
	else{
		//�˿�δ��ռ��
		if (isPortOccupied(port) == false)
		{
			this->port = port;
			ui.labelPort->setText(QString::fromLocal8Bit("��ǰ�˿�").append(port));			
		}
		else{
			for (int i = 8000; i < 65535; i++)
			{
				if (isPortOccupied(QString::number(i)) == false)
				{
					QMessageBox::information(this, QString::fromLocal8Bit("ע��"), QString::fromLocal8Bit("������Ķ˿ں��ѱ�ռ�ã�Ϊ���Զ����ö˿�"));
					this->port = QString::number(i);
					ui.labelPort->setText(QString::fromLocal8Bit("��ǰ�˿�").append(QString::number(i)));
					return;
				}
			}
		}
		//���ö˿�
	}
}
void chatOnLineServer::onStartServer()
{
	if (!tcpServer->listen(QHostAddress::Any, port.toInt()))
	{
		exit(1);//����ʧ�ܣ��˳�����
	}
}
void chatOnLineServer::onNewConnection()
{
	
	QTcpSocket *tcpSocket = tcpServer->nextPendingConnection();
	connect(tcpSocket,SIGNAL(readyRead()),
		this,SLOT(readMessageFromClient()));
	int clientID=idToDistribute++;
	UsersAndTheirSockets.push_back(tcpSocketWithUserID(tcpSocket,clientID));
	ui.labelClientNum->setText(QString::fromLocal8Bit("��ǰ��������:")+QString::number(++clientNum));//��������+1
	notifyClientSuccedLogin(clientID);
}
bool chatOnLineServer::isPortOccupied(QString const port)
{
	QTcpSocket *tcpSocket = new QTcpSocket();
	//������bind���ж϶˿��Ƿ�ר��
	if (tcpSocket->bind(QHostAddress::Any, port.toInt(), QAbstractSocket::DontShareAddress) == true)
	{
		tcpSocket->abort();
		delete tcpSocket;
		return false;
	}
	delete tcpSocket;
	return true;
}
//�������ID���͸��û�
void chatOnLineServer::notifyClientSuccedLogin(int id)
{
	QTcpSocket *clientSocket;
	for (auto u:UsersAndTheirSockets)
	{
		if (u.id==id)
		{
			clientSocket = u.tcpSokect;
		}
	}	
	Users.resize(clientNum);	
	QByteArray data;
	QDataStream out(&data, QIODevice::WriteOnly);
	out << messageType::succedLogin;
	out << id;
	//����
	clientSocket->write(data,data.length());
}
void chatOnLineServer::readMessageFromClient()
{
	QTcpSocket *tcpSocket = dynamic_cast<QTcpSocket*>(sender());
	QByteArray datagram = tcpSocket->readAll();
	QDataStream in(&datagram, QIODevice::ReadOnly);
	int type;
	in >> type;
	switch (type)
	{
	case messageType::userIn:
	{
		User user;
		in >> user;
		newUserIn(user);
		break;
	}
	case messageType::userOut:
	{
		int userId;
		in >> userId;
		userOut(userId);
		break;
	}
	case messageType::privateMessageToServer:
	{
		int fromId;//��ϢԴ
		int toId;
		char *nameFrom;
		char *msg;
		in >> toId;//��Ϣȥ��
		in >> fromId;
		in >> nameFrom;
		in >> msg;
		handlePrivateMessageFromClient(QString(nameFrom),fromId,toId, QString(msg));//������Ϣ��ת��
	}
	}
}
void chatOnLineServer::newUserIn(const User user)
{
	//�����û���
	Users.push_back(user);
	//��ʾ�¼����û�����Ϣ
	QTreeWidgetItem *item = new QTreeWidgetItem(ui.treeWidget);
	item->setText(0,user.userName);	
	item->setText(1, user.IPaddress);
	item->setText(2, user.port);
	item->setText(3, QString::number(user.id));
	item->setText(4, QTime::currentTime().toString());
	//�����û�����Ϣ���͸�ÿ���û�
	sendUsersOnLineToEachClient();
}
//�����û��ǳ�
void chatOnLineServer::userOut(const int id)
{
	ui.labelClientNum->setText(QString::number(--clientNum));
	QTreeWidgetItem *item = ui.treeWidget->findItems(QString::number(id), Qt::MatchExactly, 3).first();
	if (item != NULL)
		delete item;
	for (std::vector<User>::iterator itr = Users.begin(); itr != Users.end();itr++)
	{
		if (itr->id==id)
		{
			Users.erase(itr);
			break;
		}
	}
	for (std::vector<tcpSocketWithUserID>::iterator itr = UsersAndTheirSockets.begin(); itr != UsersAndTheirSockets.end();itr++)
	{
		if (itr->id == id)
		{
			UsersAndTheirSockets.erase(itr);
			break;
		}
	}
	//ˢ�����пͻ����û���
	sendUsersOnLineToEachClient();
}
void chatOnLineServer::sendUsersOnLineToEachClient()
{
	int messagetype = messageType::usersOnLine;
	QByteArray data;
	QDataStream out(&data, QIODevice::WriteOnly);
	out << messagetype;
	//��װ�û�����Ϣ
	for (auto u :Users)
	{
		out << u;
	}
	for (auto u:UsersAndTheirSockets)
	{
		u.tcpSokect->write(data,data.length());
	}
}
void chatOnLineServer::handlePrivateMessageFromClient(QString userName, int fromID,int toID, QString msg)
{
	for (auto u : UsersAndTheirSockets)
	{
		if (u.id==toID)
		{
			int messagetype = messageType::privateMessageFromServer;
			QByteArray data;
			QDataStream out(&data, QIODevice::WriteOnly);
			out << messagetype;
			out << fromID;//��Ϣ��Դ
			out << userName.toStdString().c_str();
			out << msg.toStdString().c_str();
			u.tcpSokect->write(data, data.length());
			break;
		}
	}
}