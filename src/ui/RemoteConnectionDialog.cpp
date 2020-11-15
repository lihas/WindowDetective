#include "RemoteConnectionDialog.h"
#include "window_detective/Logger.h"


RemoteConnectionDialog::RemoteConnectionDialog(MainWindow* mainWindow, QWidget* parent) :
	QDialog(parent)
{
	setupUi(this);

	connect(connectToRemoteServerButton, SIGNAL(clicked()), this, SLOT(ConnectToRemoteServerButtonClicked()));
	connect(startServerButton, SIGNAL(clicked()), this, SLOT(StartServerButtonClicked()));

	//remoteServer = new RemoteServer(this);
	remoteServer = new RemoteServer(nullptr);
}


RemoteConnectionDialog::~RemoteConnectionDialog(void)
{
}

void RemoteConnectionDialog::StartServerButtonClicked()
{
	auto portNum = serverListenPortInput->value();
	remoteServer->Listen(portNum, this);
}

void RemoteConnectionDialog::ConnectToRemoteServerButtonClicked()
{
	Logger::debug("RemoteConnectionDialog::ConnectToRemoteServerButtonClicked");
}