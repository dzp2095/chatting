#include "loginDlg.h"
#include "chatonline.h"
using namespace std;
loginDlg::loginDlg(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	ui.labelTips->setVisible(false);

	connect(ui.btnLogin, SIGNAL(clicked()),
		this,SLOT(on_btnlogin()));
}

loginDlg::~loginDlg()
{

}
void loginDlg::setIsLogin(bool tag)
{
	ui.labelTips->setVisible(tag);
	ui.btnLogin->setEnabled(!tag);
	ui.lineEditAddress->setEnabled(!tag);
	ui.lineEditPort->setEnabled(!tag);
	ui.lineEditUserName->setEnabled(!tag);
}
void loginDlg::on_btnlogin()
{
	userName =  ui.lineEditUserName->text();
	IPAdress = ui.lineEditAddress->text();
	port = ui.lineEditPort->text();
	if (userName.isEmpty()==false && false==IPAdress.isEmpty() && false==ui.lineEditPort->text().isEmpty())
	{
		setIsLogin(true);
		loginTrd=new loginThread(this,userName,IPAdress,port);
		connect(loginTrd, SIGNAL(finish_signal(const int,const QString)),
			this, SLOT(finishLogin(const int,const QString)));
		loginTrd->start();
	}
	else
		QMessageBox::warning(this,QString::fromLocal8Bit("��������"),QString::fromLocal8Bit("��������������Ϣ��"));	
}
void loginDlg::finishLogin(const int code,const QString messageStr)
{
	setIsLogin(false);
	delete loginTrd;
	//��¼ʧ��
	if (code == 0)
	{
		QMessageBox::warning(this, QString::fromLocal8Bit("��¼ʧ��"), messageStr);
		return;
	}
	if (code == 1)
	{		
		chatOnLine *mainWindow;
		mainWindow = new chatOnLine(NULL,userName, IPAdress, port);
		mainWindow->show();
		this->accept();
	}
}
