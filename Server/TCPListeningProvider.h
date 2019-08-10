#pragma once
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <winsock2.h>
#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include "IListeningProvider.h"
#include "FileDatabase.h"
#include "TCPClientService.h"

class TCPListeningProvider : public IListeningProvider {
public:
	TCPListeningProvider();
	virtual void startListening(const std::string& port = "26997") override;

private:
	virtual void acceptConnection(std::shared_ptr<SOCKET>& socketPtr);
	 
	// I'm going to put here a database connector and try to establish connection between client and server and process basic commands
	SOCKET winSocket;
	std::shared_ptr<FileDatabase> fileDatabase;
};