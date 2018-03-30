#include "serverworker.h"

ServerWorker::ServerWorker(QObject *parent)
	: QTcpServer(parent)
{

}

ServerWorker::~ServerWorker()
{

}
bool ServerWorker::isPortOccupied(QString port)
{
	return false;
}