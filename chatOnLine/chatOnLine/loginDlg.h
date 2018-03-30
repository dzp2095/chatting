#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "ui_login.h"
#include "loginThread.h"
#include <QString>
#include <QMessageBox>
class loginDlg : public QDialog
{
	Q_OBJECT

public:
	loginDlg(QWidget *parent = 0);
	~loginDlg();
private:
	Ui::login ui;
	loginThread *loginTrd;
	void setIsLogin(bool);
	QString userName;
	QString IPAdress;
	QString port;
private slots:
	void on_btnlogin();
	void finishLogin(const int code, const QString messageStr);
};

#endif // LOGIN_H
