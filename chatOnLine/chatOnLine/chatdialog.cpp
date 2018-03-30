#include "chatdialog.h"
#include <QCloseEvent>
chatDialog::chatDialog(QWidget *parent, QString oppositeUserName, QString oppositeID)
	: QDialog(parent)
{
	ui.setupUi(this);
	//非模态对话框
	this->oppositeUserName = oppositeUserName;
	this->oppositeID = oppositeID;
	this->setModal(false);
	ui.label->setText(QString::fromLocal8Bit("与 ")+oppositeUserName+QString::fromLocal8Bit(" 聊天中")+QString::fromLocal8Bit("  对方的ID为 ")+oppositeID);
	connect(ui.btnSend, SIGNAL(clicked()),
		this, SLOT(on_btnSend()));
}

chatDialog::~chatDialog()
{

}
void chatDialog::on_btnSend()
{
	QString msg = ui.textEdit->toPlainText();
	ui.textEdit->clear();
	emit sendPrivateMessageSignal(msg,oppositeID.toInt());
}
void chatDialog::closeEvent(QCloseEvent *event)
{
	emit closeChatDialogSignal(oppositeID.toInt());
	event->accept();
}