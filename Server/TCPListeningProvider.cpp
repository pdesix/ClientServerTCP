#include "TCPListeningProvider.h"


void TCPListeningProvider::startListening(const std::string& port) {
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
	service.sin_addr.s_addr = inet_addr("127.0.0.1");
	service.sin_port = htons(static_cast<u_short>(std::stoi(port)));

	if (bind(winSocket, (SOCKADDR*)& service, sizeof(service)) == SOCKET_ERROR)
	{
		WSACleanup();
		throw InitializationError("Error occured while binding port to TCP socket.");
	}

	if (listen(winSocket, 1) == SOCKET_ERROR)
	{
		closesocket(winSocket);
		WSACleanup();
		throw InitializationError("Error listening on socket.\n");
	}
	
	std::cout << "Listening for incoming connections...\n";
	while (true)
	{
		SOCKET acceptSocket = SOCKET_ERROR;
		while (acceptSocket == SOCKET_ERROR)
		{
			acceptSocket = accept(winSocket, NULL, NULL);
		}
		acceptConnection(acceptSocket);
		std::cout << "New connection has been initialized...";
	}
}

void TCPListeningProvider::acceptConnection(SOCKET& socket) {
	//connectionHandlers.push_back(std::make_shared<TCPClientService>(socket));
	//std::shared_ptr<TCPClientService> lastThreadHandler{ std::make_shared<TCPClientService>(connectionHandlers[connectionHandlers.size() - 1]) };
	//connectionThreads.push_back(std::thread(&TCPClientService::handleConnection, lastThreadHandler));
}