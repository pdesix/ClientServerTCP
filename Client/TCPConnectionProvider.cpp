#include "TCPConnectionProvider.h"

void TCPConnectionProvider::establishConnection(const std::string& ip, const std::string& port) {
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

void TCPConnectionProvider::getData() {
}

std::shared_ptr<User> TCPConnectionProvider::log(std::string username, std::string password) {
	std::int32_t dataLength = username.length();
	send(winSocket, (char*)& dataLength, sizeof(std::int32_t), 0);
	send(winSocket, username.c_str(), dataLength, 0);
	dataLength = password.length();
	send(winSocket, (char*) & dataLength, sizeof(std::int32_t), 0);
	send(winSocket, password.c_str(), dataLength, 0);
	std::int32_t responseCode;
	recv(winSocket, (char*)& responseCode, sizeof(std::int32_t), 0);
	std::cout << "Received response code: " << responseCode;
	return nullptr;
}

TCPConnectionProvider::~TCPConnectionProvider() {
	closeConnection();
}