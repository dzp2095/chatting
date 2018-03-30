#ifndef CHATONLINE_H
#define CHATONLINE_H

#include <QtWidgets/QMainWindow>
#include "ui_chatonline.h"
#include "clientNetWorker.h"
#include "global.h"
#include <chatdialog.h>
//˽�ĶԻ����Լ��Է���ID
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
	QString serverPort;//�������˿�
	QString localPort;
	int idOnServer;//�����������id
	QTcpSocket *tcpSocket;
	QTimer *timer;
	std::vector<chatDialogWithID> chatdlgsAndOppositeId;//���������еĶԻ���

	void closeEvent(QCloseEvent *event);       //�رմ���
	void sendUserMessage();  //���ͱ��û�����Ϣ��������
	void displayLocalUser(); //��ʾ���û���Ϣ
	void initClient();	
	bool connectServer();//���������������
	static bool isPortOccupied(QString  const port);//�ж϶˿��Ƿ�ռ��
	void distributeLocalPort();
	void run();
	QString getLocalPort(){ return localPort; };
	void displayOtherUsersOnLine(std::vector<User> users);
	void displayUser(User user);
	void readPrivateMessge(QString userName,QString id,QString msg);
	void openChatDlg(QString name,int id);// �����촰��
	void displayMessage(QString name, int id,QString msg);//��ʾ������Ϣ
private slots:
	void finishConnect(bool success,QString msg);//���ӷ�������ɺ���ͻ�����Ϣ
	void readMessgeFromServer();//�������Է���������Ϣ
	void checkLoginIsSuccess();//����¼�Ƿ�ɹ�
	//void onReLogin();//���µ�½
	void logout();  //֪ͨ���������û�����
	void onOpenDlg(QTreeWidgetItem *item, int);
	void sendPrivateMessageToServer(const QString msg, const int id);
	void chatDlgClosed(const int id);//�������촰�ڹر�
};

#endif // CHATONLINE_H
