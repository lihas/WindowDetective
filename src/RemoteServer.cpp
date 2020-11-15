#include "RemoteServer.h"


RemoteServer::RemoteServer(QObject* parent) : 
	QTcpServer(parent),
	clientSocket(nullptr)
{

}


RemoteServer::~RemoteServer(void)
{
}

void RemoteServer::Listen(quint16 port, QObject* parent)
{
	listen(QHostAddress::Any, port);
}


void RemoteServer::DataReadyFromClient()
{
	Logger::debug("ServerThread::DataReadyFromClient() incoming data");

	auto clientSocket = (QTcpSocket*)sender();
	while(clientSocket->canReadLine())
	{
		QStringList tokens = QString(clientSocket->readLine()).split(QRegExp("[ \r\n]+"));
		if(tokens[0].toUpper() == "GET")
		{
			//QTextStream os(clientSocket);
			////os.setAutoDetectUnicode(true);
			//os << "HTTP/1.0 200 Ok\n"
			//	"Content-Type: text/html; charset=\"utf-8\"\n"
			//	"\n"
			//	"Hola world! <br />"
			//	<<QDateTime::currentDateTime().toString() << "\n\n\n";
			//os.flush();
			QString data;
			auto* s = "HTTP/1.0 200 Ok\n"
			"Content-Type: text/html; charset=\"utf-8\"\n"
			"\n"
			"Hola world! <br />";
			data.append(s);
			data.append(QDateTime::currentDateTime().toString() );
			data.append("\n");
			clientSocket->write(data.toUtf8());
		}
	}
	
}

void RemoteServer::ClientDisconnected()
{
	Logger::debug("ServerThread::ClientDisconnected() client disconnected");
	clientSocket->close();
	clientSocket->deleteLater();
}

