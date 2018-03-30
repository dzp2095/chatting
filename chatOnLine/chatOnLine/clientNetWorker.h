#ifndef CLIENTLOGIN_H
#define CLIENTLOGIN_H

#include <QObject>
#include<QThread>
#include <QTcpSocket>
class clientNetWorker : public QThread
{
	Q_OBJECT

public:
	clientNetWorker(QObject *parent,QString userName,QString IPaddress,QString port);
	~clientNetWorker();
	bool connectServer();//与服务器进行连接
	static bool isPortOccupied(QString  const port);//判断端口是否被占用
	void distributeLocalPort();
	void run();
	QString getLocalPort(){ return localPort; };
private:
	QString userName;
	QString IPaddress;
	QString serverPort;
	QString localPort;

	QTcpSocket *tcpSocket;
private slots:
	//void rcvServerData();
signals :
	void connectToServerSignal(bool success,QString msg);
};

#endif // CLIENTLOGIN_H
