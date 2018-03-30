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
		emit finish_signal(1, QString::fromLocal8Bit("输入合法，开始登陆"));
	}
}
bool loginThread::isValid(QString &errorTip)
{
	//端口输入必须为正整数
	QString pattern = "^[0-9]*$";
	QRegExp rx(pattern);
	if (rx.exactMatch(serverPort)==false)
	{
		errorTip = QString::fromLocal8Bit("请输入合法的端口号,端口号必须为正整数");
		return false;
	}
	//检查端口范围
	if (serverPort.toInt() < 0 || serverPort.toInt()>65535)
	{
		errorTip = QString::fromLocal8Bit("端口范围应在0到65535之间");
		return false;
	}
	//检查本机端口是否被占用

	//检查用户名
	pattern = "^.{5,16}[\\u4E00-\\u9FA5A-Za-z0-9_]+$";
	rx.setPattern(pattern);
	if (rx.exactMatch(userName) == false)
	{
		errorTip = QString::fromLocal8Bit("请输入合法的用户名\n可包含中英文、数字以及下划线\n长度在6~16之间");
		return false;
	}
	//检查IP地址
	pattern = "^(25[0-5]|2[0-4][0-9]|[0-1]{1}[0-9]{2}|[1-9]{1}[0-9]{1}|[1-9])\\.(25[0-5]|2[0-4][0-9]|[0-1]{1}[0-9]{2}|[1-9]{1}[0-9]{1}|[1-9]|0)\\.(25[0-5]|2[0-4][0-9]|[0-1]{1}[0-9]{2}|[1-9]{1}[0-9]{1}|[1-9]|0)\\.(25[0-5]|2[0-4][0-9]|[0-1]{1}[0-9]{2}|[1-9]{1}[0-9]{1}|[0-9])$";
	rx.setPattern(pattern);
	if (false==rx.exactMatch(IPaddress))
	{
		errorTip = QString::fromLocal8Bit("请输入合法的ip地址");
		return false;
	}
	return true;
}
