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
	QString serverPort;//�������˿�
	class clientNetWorker *client;
signals:
	void finish_signal(const int, const QString);//code Ϊ״̬�� 0��ʾ��¼ʧ��  1��ʾ��¼�ɹ�	
};

#endif // LOGINTHREAD_H
