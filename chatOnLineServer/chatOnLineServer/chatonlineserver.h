#ifndef CHATONLINESERVER_H
#define CHATONLINESERVER_H
#include <QtWidgets/QMainWindow>
#include "ui_chatonlineserver.h"
#include <QTcpServer>
#include "serverworker.h"
#include <vector>
#include "global.h"
#include <QTcpSocket>
#include <map>
class chatOnLineServer : public QMainWindow
{
	Q_OBJECT
public:
	chatOnLineServer(QWidget *parent = 0);
	~chatOnLineServer();
	chatOnLineServer(chatOnLineServer&)=delete;
	chatOnLineServer&operator=(const chatOnLineServer) = delete;
friend class ServerWorker;
private:
	int idToDistribute;//给用户分配ID，从0开始
	Ui::chatOnLineServerClass ui;
	QString port;
	//workerThread *worker_thread;//后台线程，后台线程中有若干个子线程处理客户端通信
	int clientNum;//在线人数
	std::vector<User> Users;//当前在线用户信息组
	std::vector<tcpSocketWithUserID> UsersAndTheirSockets;//当前在线用户socket连接,注意： 该指针数组中的指针从属于tcpserver，由tcpserver销毁，无需主动销毁
	void setPort(QString port);
	void notifyClientSuccedLogin(int id);//告知用户登录成功
	bool isPortOccupied(QString const port);//判断端口是否被占用
	QTcpServer *tcpServer;
	void newUserIn(const User user); //有新用户加入
	void userOut(const int id);//有用户退出;
	void sendUsersOnLineToEachClient();//把所有在线的用户发送给每个用户
	void handlePrivateMessageFromClient(QString userName, int fromId,int toID, QString msg);//转发来自客户端的私聊信息
private slots:
	void onStartServer();
	void onSetPort();
	void onNewConnection();//新的客户端接入
	void readMessageFromClient();//处理从客户端接收的数据
};

#endif // CHATONLINESERVER_H
