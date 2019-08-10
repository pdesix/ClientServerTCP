#pragma once
#include <winsock2.h>
#include <Ws2tcpip.h>
#include <memory>
#include "IClientService.h"

class TCPClientService : public IClientService {
public:
	TCPClientService(std::shared_ptr<SOCKET>& socket);
	virtual void handleConnection() override;


private:
	std::shared_ptr<SOCKET> winSocketPtr;
};