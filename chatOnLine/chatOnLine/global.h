#ifndef GLOBAL_H
#define GLOBAL_H
#include <QDataStream>
enum messageType
{
	succedLogin,//��¼�ɹ�
	usersOnLine,//�����������ϵ��û�
	userIn,//�û�����
	userOut,//�û�����
	serverQuit,//�������ر�
	privateMessageToServer,
	privateMessageFromServer
};
struct User
{
	User(QString userName = NULL, QString IPaddress = NULL, QString port = NULL, int id = -1) :userName(userName), IPaddress(IPaddress), port(port), id(id){};
	QString userName;//�û���
	QString IPaddress;//ip��ַ
	QString port;//��ʹ�õĶ˿�
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
