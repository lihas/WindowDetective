#pragma once

#include <QtWidgets>
#include "window_detective/include.h"
#include "ui/forms/ui_RemoteConnectionDialog.h"
#include "RemoteServer.h"

class MainWindow;  // Forward declaration

class RemoteConnectionDialog : public QDialog, private Ui::RemoteConnectionDialog
{
	Q_OBJECT
public:
	RemoteConnectionDialog(MainWindow* mainWindow, QWidget* parent = nullptr);
	~RemoteConnectionDialog(void);
private:
	RemoteServer* remoteServer;
private slots:
	void ConnectToRemoteServerButtonClicked();
	void StartServerButtonClicked();
};

