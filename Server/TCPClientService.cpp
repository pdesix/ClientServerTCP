#include "TCPClientService.h"
#include <iostream>

TCPClientService::TCPClientService(std::shared_ptr<SOCKET>& socket) 
	: winSocketPtr(socket) {
}

void TCPClientService::handleConnection() {
	std::cout << "Handled connection from socket...\n";
	char recvbuf[5] = "xdxd";
	int bytesRecv = send(*winSocketPtr, recvbuf, 4, 0);

	while (!(bytesRecv == -1 || bytesRecv == WSAECONNRESET) ) {
		bytesRecv = send(*winSocketPtr, recvbuf, 4, 0);
	}
	std::cout << "Connection closed\n";
}