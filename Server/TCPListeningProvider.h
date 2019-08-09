#pragma once
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <winsock2.h>
#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include "IListeningProvider.h"
#include "TCPClientService.h"

class TCPListeningProvider : public IListeningProvider {
public:
	virtual void startListening(const std::string& port = "26997") override;

private:
	virtual void acceptConnection(SOCKET& socket);
	 
	// I'm going to put here a database connector and try to establish connection between client and server and process basic commands
	SOCKET winSocket;
};