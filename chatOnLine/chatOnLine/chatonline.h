#ifndef CHATONLINE_H
#define CHATONLINE_H

#include <QtWidgets/QMainWindow>
#include "ui_chatonline.h"
#include "clientNetWorker.h"
#include "global.h"
#include <chatdialog.h>
//私聊对话框以及对方的ID
struct chatDialogWithID
{
	chatDialogWithID(chatDialog *dlg,int id=0):dialog(dlg),oppsiteID(id){};
	chatDialog *dialog;
	int oppsiteID;
};
class chatOnLine : public QMainWindow
{
	Q_OBJECT

public:
	chatOnLine(QWidget *parent,QString userName, QString IPaddress, QString port);
	~chatOnLine();

private:
	Ui::chatOnLineClass ui;
	QString userName;
	QString IPaddress;
	QString serverPort;//服务器端口
	QString localPort;
	int idOnServer;//服务器分配的id
	QTcpSocket *tcpSocket;
	QTimer *timer;
	std::vector<chatDialogWithID> chatdlgsAndOppositeId;//正在聊天中的对话框

	void closeEvent(QCloseEvent *event);       //关闭窗口
	void sendUserMessage();  //发送本用户的信息到服务器
	void displayLocalUser(); //显示本用户信息
	void initClient();	
	bool connectServer();//与服务器进行连接
	static bool isPortOccupied(QString  const port);//判断端口是否被占用
	void distributeLocalPort();
	void run();
	QString getLocalPort(){ return localPort; };
	void displayOtherUsersOnLine(std::vector<User> users);
	void displayUser(User user);
	void readPrivateMessge(QString userName,QString id,QString msg);
	void openChatDlg(QString name,int id);// 打开聊天窗口
	void displayMessage(QString name, int id,QString msg);//显示聊天信息
private slots:
	void finishConnect(bool success,QString msg);//连接服务器完成后处理客户端信息
	void readMessgeFromServer();//处理来自服务器的信息
	void checkLoginIsSuccess();//检查登录是否成功
	//void onReLogin();//重新登陆
	void logout();  //通知服务器本用户下线
	void onOpenDlg(QTreeWidgetItem *item, int);
	void sendPrivateMessageToServer(const QString msg, const int id);
	void chatDlgClosed(const int id);//处理聊天窗口关闭
};

#endif // CHATONLINE_H
