#include "chatonline.h"
#include <QMessageBox>
#include <QHostAddress>
#include <QTime>
#include <QTimer>
#include <QCloseEvent>
#include "loginDlg.h"
#include "chatdialog.h"
chatOnLine::chatOnLine(QWidget *parent,QString userName, QString IPaddress, QString port)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->userName = userName;
	this->IPaddress = IPaddress;
	this->serverPort = port;
	idOnServer = -1;//为-1时 表示未接受到服务器返回的ID
	tcpSocket = new QTcpSocket(this);	
	timer = new QTimer();
	connect(ui.actionLogOut, SIGNAL(triggered()),
		this, SLOT(logout()));
	connect(ui.treeWidget, SIGNAL(itemDoubleClicked(QTreeWidgetItem*, int)),
		this, SLOT(onOpenDlg(QTreeWidgetItem *, int)));
	//connect(ui.actionLogin, SIGNAL(triggered()),
	//	this, SLOT(onReLogin()));
	initClient();
}

void chatOnLine::initClient()
{
	distributeLocalPort();//分配本地端口
	if (connectServer()==false)
	{
		QMessageBox::information(this, QString::fromLocal8Bit("失败"), QString::fromLocal8Bit("登录失败"));
	}
}
chatOnLine::~chatOnLine()
{
	delete timer;
	delete tcpSocket;
}
void chatOnLine::finishConnect(bool isSuccess,QString msg)
{
	if (isSuccess==false)
	{
		QMessageBox::information(this, QString::fromLocal8Bit("失败"), QString::fromLocal8Bit("连接失败"));
	}
	//connect成功,不代表连接服务器成功,等待服务器发送来的数据
}
void chatOnLine::checkLoginIsSuccess()
{
	//登录失败
	if (idOnServer==-1)
	{
		timer->stop();
		QMessageBox::information(this, QString::fromLocal8Bit("失败"), QString::fromLocal8Bit("服务器未响应"));
	}
}
void chatOnLine::displayLocalUser()
{
	QHostAddress localhost=QHostAddress::LocalHost;
	QTime nowTime=QTime::currentTime();
	ui.labelUserInfo->setText(userName+QString::fromLocal8Bit(" 登陆时间:")+nowTime.toString()+QString::fromLocal8Bit("	用户ID:")+QString::number(idOnServer));
}

bool  chatOnLine::isPortOccupied(const QString port)
{
	QTcpSocket *tcpSocket = new QTcpSocket();
	if (tcpSocket->bind(QHostAddress::LocalHost, port.toInt(), QAbstractSocket::DontShareAddress) == false)
	{
		tcpSocket->abort();
		delete tcpSocket;
		return true;
	}
	return false;
}
//连接服务器
bool  chatOnLine::connectServer()
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
		return false;
	}
	//连接服务器，开始接受服务器发送的数据，10秒钟后检查是否登录成功
	connect(tcpSocket, SIGNAL(readyRead()),
		this, SLOT(readMessgeFromServer()));
	timer->setInterval(10000);
	timer->start();
	connect(timer, SIGNAL(timeout()),
		this, SLOT(checkLoginIsSuccess()));
	return true;
}
//为本机分配端口
void  chatOnLine::distributeLocalPort()
{
	for (int i = 8000; i < 65535; i++)
	{
		if (isPortOccupied(QString::number(i)) == false)
		{
			localPort = QString::number(i);
			return;
		}
	}
}
void chatOnLine::readMessgeFromServer()
{
	QByteArray datagram = tcpSocket->readAll();
	QDataStream in(&datagram, QIODevice::ReadOnly);
	int type;  
	in >> type;
	switch (type)
	{
	case messageType::succedLogin:
	{
		QMessageBox::information(this, QString::fromLocal8Bit("成功"), QString::fromLocal8Bit("登录成功"));
		in >> idOnServer;
		displayLocalUser();//显示登录信息 
		sendUserMessage(); //向服务器发送用户信息
		break;
	}
	case messageType::usersOnLine:
	{
		std::vector<User> users;
		while (!in.atEnd())
		{
			User user;
			in >> user;
			if (user.id!=-1)
				users.push_back(user);			
		}
		displayOtherUsersOnLine(users);
		break;
	}
	case messageType::privateMessageFromServer:
	{
		int fromId;
		char *nameFrom;
		char *msg;
		in >> fromId;
		in >> nameFrom;
		in >> msg;
		readPrivateMessge(QString(nameFrom), QString::number(fromId), QString(msg));
		break;
	}
	}
}
void chatOnLine::displayOtherUsersOnLine(std::vector<User> users)
{
	ui.treeWidget->clear();
	for (auto u:users)
	{
		if (this->idOnServer!=u.id)		
			displayUser(u);
	}
}
void chatOnLine::displayUser(User user)
{
	QTreeWidgetItem *item = new QTreeWidgetItem(ui.treeWidget);
	item->setText(0, user.userName);
	item->setText(1, QString::number(user.id));
}
void chatOnLine::sendUserMessage()
{
	int type = messageType::userIn;//用户登录信息
	QHostAddress localhost=QHostAddress::LocalHost;
	QString localAddress = localhost.toString();
	User user=User(userName,localAddress,localPort,idOnServer);

	QByteArray data;
	QDataStream out(&data, QIODevice::WriteOnly);
	out << type;
	out << user;
	tcpSocket->write(data, data.length());
}
void chatOnLine::logout()
{
	int type = messageType::userOut;//用户登录信息
	QByteArray data;
	QDataStream out(&data, QIODevice::WriteOnly);
	out << type;
	out << idOnServer;
	tcpSocket->write(data, data.length());
	tcpSocket->disconnect();//断开连接
	idOnServer = -1;
	ui.labelUserInfo->setText(QString::fromLocal8Bit("未登陆"));
}
void chatOnLine::closeEvent(QCloseEvent *event)
{
	QMessageBox::StandardButton button;
	QString str = QString::fromLocal8Bit("确定退出么?");
	button = QMessageBox::question(this, QString("exit"),
		str,
		QMessageBox::Yes | QMessageBox::No);

	if (button == QMessageBox::No) {
		event->ignore();  //忽略退出信号，程序继续运行
	}
	else if (button == QMessageBox::Yes) {
		if (idOnServer!=-1)
			logout();		  //向服务器发送登出信息
		QTime time;
		event->ignore();		
		time.start();
		while (time.elapsed() < 100)
			QCoreApplication::processEvents();//等待0.1秒后再退出(等待登出信息发送到服务器)
		exit(0);	  
	}
}
//打开聊天对话框
void chatOnLine::openChatDlg(QString name,int id)
{	
	//检查对话框是否已经存在
	for (std::vector<chatDialogWithID>::iterator itr = chatdlgsAndOppositeId.begin(); itr != chatdlgsAndOppositeId.end(); itr++)
	{
		if (itr->oppsiteID == id)
		{
			return;
		}
	}
	chatDialog *chatdialog = new chatDialog(NULL, name,QString::number(id));
	chatdlgsAndOppositeId.push_back(chatDialogWithID(chatdialog, id));

	connect(chatdialog, SIGNAL(sendPrivateMessageSignal(QString, const int)),
		this, SLOT(sendPrivateMessageToServer(QString, const int)));
	connect(chatdialog, SIGNAL(closeChatDialogSignal(const int)),
		this, SLOT(chatDlgClosed(const int)));
	chatdialog->show();
}
void chatOnLine::onOpenDlg(QTreeWidgetItem *item, int)
{
	openChatDlg(item->text(0),item->text(1).toInt());	
}
//将私聊信息发往服务器
void chatOnLine::sendPrivateMessageToServer(QString msg, const int toId)
{
	int type = messageType::privateMessageToServer;
	QByteArray data;
	QDataStream out(&data, QIODevice::WriteOnly);
	out << type;
	//需要发往的用户ID
	out << toId;
	//本机ID
	out << idOnServer;
	//本机用户名
	out << userName.toStdString().c_str();	
	out << msg.toStdString().c_str();
	tcpSocket->write(data, data.length());
	displayMessage(userName,toId,msg);
}
//显示聊天信息
void chatOnLine::displayMessage(QString name, int id, QString msg)
{
	chatDialog *dlg;
	for (std::vector<chatDialogWithID>::iterator itr = chatdlgsAndOppositeId.begin(); itr != chatdlgsAndOppositeId.end(); itr++)
	{
		if (itr->oppsiteID == id)
		{
			dlg = itr->dialog;
			break;
		}
	}
	QTime time = QTime::currentTime();
	dlg->ui.textBrowser->append(name + "   " + time.toString());
	dlg->ui.textBrowser->append(msg);
}
//接收从服务器发来的私聊信息
void chatOnLine::readPrivateMessge(QString userName, QString id, QString msg)
{
	openChatDlg(userName,id.toInt());
	//显示聊天信息
	displayMessage(userName,id.toInt(), msg);	
}
void chatOnLine::chatDlgClosed(const int id)
{
	for (std::vector<chatDialogWithID>::iterator itr = chatdlgsAndOppositeId.begin(); itr != chatdlgsAndOppositeId.end();itr++)
	{
		if (itr->oppsiteID==id)
		{
			chatdlgsAndOppositeId.erase(itr);
			break;
		}
	}
}
//重新登陆
//void chatOnLine::onReLogin()
//{
//	logout();
//	loginDlg *logindlg = new loginDlg;
//	logindlg->show();
//	QTime time;
//	time.start();
//	while (time.elapsed() < 1000)
//		QCoreApplication::processEvents();//等待0.1秒后再退出(等待登出信息发送到服务器)
//	this->close();
//}
