#include "chatdialog.h"
#include <QCloseEvent>
chatDialog::chatDialog(QWidget *parent, QString oppositeUserName, QString oppositeID)
	: QDialog(parent)
{
	ui.setupUi(this);
	//��ģ̬�Ի���
	this->oppositeUserName = oppositeUserName;
	this->oppositeID = oppositeID;
	this->setModal(false);
	ui.label->setText(QString::fromLocal8Bit("�� ")+oppositeUserName+QString::fromLocal8Bit(" ������")+QString::fromLocal8Bit("  �Է���IDΪ ")+oppositeID);
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