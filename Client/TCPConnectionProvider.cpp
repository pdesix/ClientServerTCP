#include "TCPConnectionProvider.h"

void TCPConnectionProvider::establishConnection(const std::string& ip = "127.0.0.1", const std::string& port = "27086") {
	WSADATA wsaData;

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != NO_ERROR)
		throw InitializationError("Error occured while initializing WinSock DLL.");

	winSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (winSocket == INVALID_SOCKET)
	{
		WSACleanup();
		throw InitializationError("Error occured while initializing TCP socket.");
	}

	sockaddr_in service;
	memset(&service, 0, sizeof(service));
	service.sin_family = AF_INET;
	service.sin_addr.s_addr = inet_addr(ip.c_str());
	service.sin_port = htons(static_cast<u_short>(std::stoi(port)));

	if (connect(winSocket, (SOCKADDR*)& service, sizeof(service)) == SOCKET_ERROR)
	{
		WSACleanup();
		throw ConnectionError(("Error occured while connecting with server: " + ip + ":" + port + ".").c_str());
	}
}

void TCPConnectionProvider::closeConnection() {
	closesocket(winSocket);
	WSACleanup();
}