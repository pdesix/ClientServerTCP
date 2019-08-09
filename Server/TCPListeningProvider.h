#pragma once
#include <winsock2.h>
#include <thread>
#include <mutex>
#include "IListeningProvider.h"

class TCPListeningProvider : public IListeningProvider {
public:
	virtual void startListening(const std::string& port) override;

private:
	virtual void processConnection(SOCKET socket) = 0;
	 
	// I'm going to put here a database connector and try to establish connection between client and server and process basic commands
	SOCKET winSocket;
};