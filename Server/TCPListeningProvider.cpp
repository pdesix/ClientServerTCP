#include "TCPListeningProvider.h"

TCPListeningProvider::TCPListeningProvider()
	: fileDatabase(new FileDatabase()) {
}

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
		throw InitializationError("Error listening on socket.");
	}
	
	std::cout << "Listening for incoming connections...\n";
	while (true)
	{
		std::shared_ptr<SOCKET> acceptSocketPtr{ std::make_shared<SOCKET>() };
		*acceptSocketPtr = SOCKET_ERROR;
		while (*acceptSocketPtr == SOCKET_ERROR)
		{
			*acceptSocketPtr = accept(winSocket, NULL, NULL);
		}

		acceptConnection(acceptSocketPtr);
		std::cout << "New connection has been initialized...\n";
	}
}

void TCPListeningProvider::acceptConnection(std::shared_ptr<SOCKET>& socketPtr) {
	std::shared_ptr<TCPClientService> service{ std::make_shared<TCPClientService>(socketPtr) };
	service->setDatabaseConnector(fileDatabase,fileDatabase);
	connectionHandlers.push_back(service);
	std::shared_ptr<IClientService>& lastThreadHandler = connectionHandlers[connectionHandlers.size() - 1];
	connectionThreads.push_back(std::thread(&IClientService::handleConnection, lastThreadHandler));
}