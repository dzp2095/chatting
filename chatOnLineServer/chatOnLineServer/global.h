#ifndef GLOBAL_H
#define GLOBAL_H
enum messageType
{
	succedLogin,//登录成功
	usersOnLine,//发送正在线上的用户
	userIn,//用户上线
	userOut,//用户离线
	serverQuit,//服务器关闭
	privateMessageToServer,
	privateMessageFromServer
};
struct tcpSocketWithUserID
{
	tcpSocketWithUserID(QTcpSocket *tcpSokect=NULL,int id=0):tcpSokect(tcpSokect),id(id){}
	QTcpSocket *tcpSokect;//与用户建立连接的套接字
	int id;//用户ID
};
struct User
{
	User(QString userName = NULL, QString IPaddress = NULL, QString port = NULL, int id = -1) :userName(userName), IPaddress(IPaddress), port(port), id(id){};
	QString userName;//用户名
	QString IPaddress;//ip地址
	QString port;//所使用的端口
	int id;
	friend QDataStream & operator<<(QDataStream &out, User &user){
		out << user.id << user.userName.toStdString().c_str() << user.IPaddress.toStdString().c_str() << user.port.toStdString().c_str();
		return out;

	}
	friend  QDataStream &operator>>(QDataStream &in, User &user){
		in >> user.id;
		char * userName;
		in >> userName;
		user.userName = QString(userName);
		char * IPaddress;
		in >> IPaddress;
		user.IPaddress = QString(IPaddress);
		char* port;
		in >> port;
		user.port = QString(port);
		return in;
	}
};
#endif
