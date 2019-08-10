#include "TCPClientService.h"
#include <iostream>

void TCPClientService::setDatabaseConnector(std::shared_ptr<IDataReader> reader, std::shared_ptr<IDataUpdater> updater) {
	dataReader = reader;
	dataUpdater = updater;
}

TCPClientService::TCPClientService(std::shared_ptr<SOCKET>& socket)
	: winSocketPtr(socket) {
}

void TCPClientService::handleConnection() {
	std::int32_t dataLength;
	recv(*winSocketPtr, (char*)&dataLength, sizeof(std::int32_t), 0);
	char* username{ new char[dataLength + 1] };
	recv(*winSocketPtr, username, dataLength, 0);
	recv(*winSocketPtr, (char*)& dataLength, sizeof(std::int32_t), 0);
	username[dataLength] = '\0';
	char* password{ new char[dataLength + 1] };
	recv(*winSocketPtr, password, dataLength, 0);
	password[dataLength] = '\0';
	std::cout << "Received username: " << username << "; password: " << password << "\n";
	std::int32_t responseCode{ dataReader->checkUserData(std::string(username), std::string(password)) };
	send(*winSocketPtr, (char*)& responseCode, sizeof(std::int32_t), 0);
	std::cout << "Responded: " << responseCode << "\n";
	delete[] username;
	delete[] password;
}