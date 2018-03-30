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
	idOnServer = -1;//Ϊ-1ʱ ��ʾδ���ܵ����������ص�ID
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
	distributeLocalPort();//���䱾�ض˿�
	if (connectServer()==false)
	{
		QMessageBox::information(this, QString::fromLocal8Bit("ʧ��"), QString::fromLocal8Bit("��¼ʧ��"));
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
		QMessageBox::information(this, QString::fromLocal8Bit("ʧ��"), QString::fromLocal8Bit("����ʧ��"));
	}
	//connect�ɹ�,���������ӷ������ɹ�,�ȴ�������������������
}
void chatOnLine::checkLoginIsSuccess()
{
	//��¼ʧ��
	if (idOnServer==-1)
	{
		timer->stop();
		QMessageBox::information(this, QString::fromLocal8Bit("ʧ��"), QString::fromLocal8Bit("������δ��Ӧ"));
	}
}
void chatOnLine::displayLocalUser()
{
	QHostAddress localhost=QHostAddress::LocalHost;
	QTime nowTime=QTime::currentTime();
	ui.labelUserInfo->setText(userName+QString::fromLocal8Bit(" ��½ʱ��:")+nowTime.toString()+QString::fromLocal8Bit("	�û�ID:")+QString::number(idOnServer));
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
//���ӷ�����
bool  chatOnLine::connectServer()
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
		return false;
	}
	//���ӷ���������ʼ���ܷ��������͵����ݣ�10���Ӻ����Ƿ��¼�ɹ�
	connect(tcpSocket, SIGNAL(readyRead()),
		this, SLOT(readMessgeFromServer()));
	timer->setInterval(10000);
	timer->start();
	connect(timer, SIGNAL(timeout()),
		this, SLOT(checkLoginIsSuccess()));
	return true;
}
//Ϊ��������˿�
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
		QMessageBox::information(this, QString::fromLocal8Bit("�ɹ�"), QString::fromLocal8Bit("��¼�ɹ�"));
		in >> idOnServer;
		displayLocalUser();//��ʾ��¼��Ϣ 
		sendUserMessage(); //������������û���Ϣ
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
	int type = messageType::userIn;//�û���¼��Ϣ
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
	int type = messageType::userOut;//�û���¼��Ϣ
	QByteArray data;
	QDataStream out(&data, QIODevice::WriteOnly);
	out << type;
	out << idOnServer;
	tcpSocket->write(data, data.length());
	tcpSocket->disconnect();//�Ͽ�����
	idOnServer = -1;
	ui.labelUserInfo->setText(QString::fromLocal8Bit("δ��½"));
}
void chatOnLine::closeEvent(QCloseEvent *event)
{
	QMessageBox::StandardButton button;
	QString str = QString::fromLocal8Bit("ȷ���˳�ô?");
	button = QMessageBox::question(this, QString("exit"),
		str,
		QMessageBox::Yes | QMessageBox::No);

	if (button == QMessageBox::No) {
		event->ignore();  //�����˳��źţ������������
	}
	else if (button == QMessageBox::Yes) {
		if (idOnServer!=-1)
			logout();		  //����������͵ǳ���Ϣ
		QTime time;
		event->ignore();		
		time.start();
		while (time.elapsed() < 100)
			QCoreApplication::processEvents();//�ȴ�0.1������˳�(�ȴ��ǳ���Ϣ���͵�������)
		exit(0);	  
	}
}
//������Ի���
void chatOnLine::openChatDlg(QString name,int id)
{	
	//���Ի����Ƿ��Ѿ�����
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
//��˽����Ϣ����������
void chatOnLine::sendPrivateMessageToServer(QString msg, const int toId)
{
	int type = messageType::privateMessageToServer;
	QByteArray data;
	QDataStream out(&data, QIODevice::WriteOnly);
	out << type;
	//��Ҫ�������û�ID
	out << toId;
	//����ID
	out << idOnServer;
	//�����û���
	out << userName.toStdString().c_str();	
	out << msg.toStdString().c_str();
	tcpSocket->write(data, data.length());
	displayMessage(userName,toId,msg);
}
//��ʾ������Ϣ
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
//���մӷ�����������˽����Ϣ
void chatOnLine::readPrivateMessge(QString userName, QString id, QString msg)
{
	openChatDlg(userName,id.toInt());
	//��ʾ������Ϣ
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
//���µ�½
//void chatOnLine::onReLogin()
//{
//	logout();
//	loginDlg *logindlg = new loginDlg;
//	logindlg->show();
//	QTime time;
//	time.start();
//	while (time.elapsed() < 1000)
//		QCoreApplication::processEvents();//�ȴ�0.1������˳�(�ȴ��ǳ���Ϣ���͵�������)
//	this->close();
//}
