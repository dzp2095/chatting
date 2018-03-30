#ifndef LOGINTHREAD_H
#define LOGINTHREAD_H

#include <QThread>
#include "clientNetWorker.h"
class loginThread : public QThread
{
	Q_OBJECT

public:
	loginThread(QObject *parent,QString userName,QString IPaddress,QString port);
	~loginThread();
	void run();
	loginThread& operator=(const loginThread&)=delete;
	loginThread(const loginThread&) = delete;
private:
	bool isValid(QString &errorTip);
	QString userName;
	QString IPaddress;
	QString serverPort;//服务器端口
	class clientNetWorker *client;
signals:
	void finish_signal(const int, const QString);//code 为状态码 0表示登录失败  1表示登录成功	
};

#endif // LOGINTHREAD_H
