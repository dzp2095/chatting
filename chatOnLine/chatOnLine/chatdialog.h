#ifndef CHATDIALOG_H
#define CHATDIALOG_H

#include <QDialog>
#include "ui_chatdialog.h"
#include <QTcpSocket>
class chatDialog : public QDialog
{
	Q_OBJECT

public:
	chatDialog(QWidget *parent = 0,QString oppositeUserName=NULL, QString oppositeID=NULL );
	~chatDialog();
	Ui::chatDialog ui;
private:	
	QTcpSocket tcpSocket;//����ͨѶ���׽���
	QString oppositeUserName;//�Է����û���
	QString oppositeID;//�Է���ID
	void closeEvent(QCloseEvent *event);       //�رնԻ���
signals:
	void sendPrivateMessageSignal(QString msg,const int id);
	void closeChatDialogSignal(const int id);
private slots:
	void on_btnSend();
};

#endif // CHATDIALOG_H
