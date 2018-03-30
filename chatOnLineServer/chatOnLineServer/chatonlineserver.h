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
	int idToDistribute;//���û�����ID����0��ʼ
	Ui::chatOnLineServerClass ui;
	QString port;
	//workerThread *worker_thread;//��̨�̣߳���̨�߳��������ɸ����̴߳���ͻ���ͨ��
	int clientNum;//��������
	std::vector<User> Users;//��ǰ�����û���Ϣ��
	std::vector<tcpSocketWithUserID> UsersAndTheirSockets;//��ǰ�����û�socket����,ע�⣺ ��ָ�������е�ָ�������tcpserver����tcpserver���٣�������������
	void setPort(QString port);
	void notifyClientSuccedLogin(int id);//��֪�û���¼�ɹ�
	bool isPortOccupied(QString const port);//�ж϶˿��Ƿ�ռ��
	QTcpServer *tcpServer;
	void newUserIn(const User user); //�����û�����
	void userOut(const int id);//���û��˳�;
	void sendUsersOnLineToEachClient();//���������ߵ��û����͸�ÿ���û�
	void handlePrivateMessageFromClient(QString userName, int fromId,int toID, QString msg);//ת�����Կͻ��˵�˽����Ϣ
private slots:
	void onStartServer();
	void onSetPort();
	void onNewConnection();//�µĿͻ��˽���
	void readMessageFromClient();//����ӿͻ��˽��յ�����
};

#endif // CHATONLINESERVER_H
