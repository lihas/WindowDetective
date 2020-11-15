#pragma once
#include <qthread.h>
#include <QtNetwork\qtcpsocket.h>
#include "window_detective/Logger.h"

class ServerThread : public QThread
{
	Q_OBJECT
public:
	ServerThread(qintptr descriptor, QObject *parent = nullptr);
	~ServerThread(void);
private:
	qintptr socketDescriptor;
	QTcpSocket* clientSocket;
protected:
	void run() Q_DECL_OVERRIDE
{
	Logger::debug("ServerThread::run() Thread start");
	clientSocket = new QTcpSocket(this);
	clientSocket->setSocketDescriptor(socketDescriptor);
	connect(clientSocket, SIGNAL(readyRead()), this, SLOT(DataReadyFromClient()), Qt::DirectConnection);
	connect(clientSocket, SIGNAL(disconnected()), this, SLOT(ClientDisconnected()), Qt::DirectConnection);
	//connect(clientSocket, QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error), this, &ServerThread::error);
	QObject::connect(clientSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(displayError(ServerThread::SocketError)), Qt::DirectConnection);
	exec();
}
private slots:
	void DataReadyFromClient();
	void ClientDisconnected();
	void SocketError(QAbstractSocket::SocketError socketError);
};

