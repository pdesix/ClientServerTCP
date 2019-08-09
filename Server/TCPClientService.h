#pragma once
#include <winsock2.h>
#include <Ws2tcpip.h>
#include "IClientService.h"

class TCPClientService : public IClientService {
public:
	TCPClientService(SOCKET& socket);
	virtual void handleConnection() override;


private:
	SOCKET& winSocket;;
};