#pragma once
//https://docs.huihoo.com/qt/solutions/4/qtservice/qtservice-example-server.html
#include <QtNetwork\qtcpserver.h>
#include <QtNetwork\qtcpsocket.h>
#include "window_detective/Logger.h"
#include "ServerThread.h"

class RemoteServer : public QTcpServer
{
	Q_OBJECT
public:
	RemoteServer(QObject* parent);
	~RemoteServer(void);

	void Listen(quint16 port, QObject* parent);

	void RemoteServer::incomingConnection(qintptr socketDescriptor) override
	{
		auto clientThread = new ServerThread(socketDescriptor);
		clientThread->start();
		return;
	//Logger::debug("RemoteServer::incomingConnection");
	//clientSocket = new QTcpSocket(nullptr);
	//clientSocket->setSocketDescriptor(socketDescriptor);
	//connect(clientSocket, SIGNAL(readyRead()), this, SLOT(DataReadyFromClient()));
	//connect(clientSocket, SIGNAL(disconnected()), this, SLOT(ClientDisconnected()));
	//addPendingConnection(clientSocket);
	}
private:
	QTcpSocket* clientSocket;

private slots:
	void DataReadyFromClient();
	void ClientDisconnected();
};

