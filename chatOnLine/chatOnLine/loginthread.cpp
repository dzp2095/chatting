#include "loginthread.h"
#include <QRegExp>
using namespace std;
loginThread::loginThread(QObject *parent, QString userName, QString IPaddress, QString port)
	: QThread(parent)
{
	 this->userName=userName;
	 this->IPaddress=IPaddress;
	 this->serverPort=port;
	 client = new clientNetWorker(NULL,userName, IPaddress,port);
}

loginThread::~loginThread()
{
	delete client;
}
void loginThread::run()
{
	QString messageStr;
	if (isValid(messageStr) == false)
	{
		emit finish_signal(0, messageStr);
		return;
	}
	else
	{
		emit finish_signal(1, QString::fromLocal8Bit("����Ϸ�����ʼ��½"));
	}
}
bool loginThread::isValid(QString &errorTip)
{
	//�˿��������Ϊ������
	QString pattern = "^[0-9]*$";
	QRegExp rx(pattern);
	if (rx.exactMatch(serverPort)==false)
	{
		errorTip = QString::fromLocal8Bit("������Ϸ��Ķ˿ں�,�˿ںű���Ϊ������");
		return false;
	}
	//���˿ڷ�Χ
	if (serverPort.toInt() < 0 || serverPort.toInt()>65535)
	{
		errorTip = QString::fromLocal8Bit("�˿ڷ�ΧӦ��0��65535֮��");
		return false;
	}
	//��鱾���˿��Ƿ�ռ��

	//����û���
	pattern = "^.{5,16}[\\u4E00-\\u9FA5A-Za-z0-9_]+$";
	rx.setPattern(pattern);
	if (rx.exactMatch(userName) == false)
	{
		errorTip = QString::fromLocal8Bit("������Ϸ����û���\n�ɰ�����Ӣ�ġ������Լ��»���\n������6~16֮��");
		return false;
	}
	//���IP��ַ
	pattern = "^(25[0-5]|2[0-4][0-9]|[0-1]{1}[0-9]{2}|[1-9]{1}[0-9]{1}|[1-9])\\.(25[0-5]|2[0-4][0-9]|[0-1]{1}[0-9]{2}|[1-9]{1}[0-9]{1}|[1-9]|0)\\.(25[0-5]|2[0-4][0-9]|[0-1]{1}[0-9]{2}|[1-9]{1}[0-9]{1}|[1-9]|0)\\.(25[0-5]|2[0-4][0-9]|[0-1]{1}[0-9]{2}|[1-9]{1}[0-9]{1}|[0-9])$";
	rx.setPattern(pattern);
	if (false==rx.exactMatch(IPaddress))
	{
		errorTip = QString::fromLocal8Bit("������Ϸ���ip��ַ");
		return false;
	}
	return true;
}
