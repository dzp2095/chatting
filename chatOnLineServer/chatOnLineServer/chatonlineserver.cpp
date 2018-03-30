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
	QString port = QInputDialog::getText(this, QString::fromLocal8Bit("端口"), QString::fromLocal8Bit("请输入要绑定的端口号"), QLineEdit::Normal);
	if (port.isEmpty() == true)
	{
		for (int i = 8000; i < 65535;i++)
		{
			if (isPortOccupied(QString::number(i))==false)
			{
				QMessageBox::information(this, QString::fromLocal8Bit("注意"), QString::fromLocal8Bit("未输入端口号,自动设置端口"));
				this->port = QString::number(i);
				ui.labelPort->setText(QString::fromLocal8Bit("当前端口").append(QString::number(i)));
				return;
			}
		}		
	}
	//手动设置端口
	else{
		//端口未被占用
		if (isPortOccupied(port) == false)
		{
			this->port = port;
			ui.labelPort->setText(QString::fromLocal8Bit("当前端口").append(port));			
		}
		else{
			for (int i = 8000; i < 65535; i++)
			{
				if (isPortOccupied(QString::number(i)) == false)
				{
					QMessageBox::information(this, QString::fromLocal8Bit("注意"), QString::fromLocal8Bit("您输入的端口号已被占用，为您自动设置端口"));
					this->port = QString::number(i);
					ui.labelPort->setText(QString::fromLocal8Bit("当前端口").append(QString::number(i)));
					return;
				}
			}
		}
		//设置端口
	}
}
void chatOnLineServer::onStartServer()
{
	if (!tcpServer->listen(QHostAddress::Any, port.toInt()))
	{
		exit(1);//监听失败，退出程序
	}
}
void chatOnLineServer::onNewConnection()
{
	
	QTcpSocket *tcpSocket = tcpServer->nextPendingConnection();
	connect(tcpSocket,SIGNAL(readyRead()),
		this,SLOT(readMessageFromClient()));
	int clientID=idToDistribute++;
	UsersAndTheirSockets.push_back(tcpSocketWithUserID(tcpSocket,clientID));
	ui.labelClientNum->setText(QString::fromLocal8Bit("当前在线人数:")+QString::number(++clientNum));//在线人数+1
	notifyClientSuccedLogin(clientID);
}
bool chatOnLineServer::isPortOccupied(QString const port)
{
	QTcpSocket *tcpSocket = new QTcpSocket();
	//尝试性bind，判断端口是否被专用
	if (tcpSocket->bind(QHostAddress::Any, port.toInt(), QAbstractSocket::DontShareAddress) == true)
	{
		tcpSocket->abort();
		delete tcpSocket;
		return false;
	}
	delete tcpSocket;
	return true;
}
//将分配的ID发送给用户
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
	//发送
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
		int fromId;//消息源
		int toId;
		char *nameFrom;
		char *msg;
		in >> toId;//消息去向
		in >> fromId;
		in >> nameFrom;
		in >> msg;
		handlePrivateMessageFromClient(QString(nameFrom),fromId,toId, QString(msg));//处理信息并转发
	}
	}
}
void chatOnLineServer::newUserIn(const User user)
{
	//加入用户组
	Users.push_back(user);
	//显示新加入用户的信息
	QTreeWidgetItem *item = new QTreeWidgetItem(ui.treeWidget);
	item->setText(0,user.userName);	
	item->setText(1, user.IPaddress);
	item->setText(2, user.port);
	item->setText(3, QString::number(user.id));
	item->setText(4, QTime::currentTime().toString());
	//更新用户组信息发送给每个用户
	sendUsersOnLineToEachClient();
}
//处理用户登出
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
	//刷新所有客户端用户组
	sendUsersOnLineToEachClient();
}
void chatOnLineServer::sendUsersOnLineToEachClient()
{
	int messagetype = messageType::usersOnLine;
	QByteArray data;
	QDataStream out(&data, QIODevice::WriteOnly);
	out << messagetype;
	//封装用户组信息
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
			out << fromID;//消息来源
			out << userName.toStdString().c_str();
			out << msg.toStdString().c_str();
			u.tcpSokect->write(data, data.length());
			break;
		}
	}
}