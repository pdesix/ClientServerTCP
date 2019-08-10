#pragma once
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <winsock2.h>
#include <iostream>
#include "IConnectionProvider.h"
#include "User.h"

class TCPConnectionProvider : public IConnectionProvider {
public:
	void establishConnection(const std::string& ip = "127.0.0.1", const std::string& port = "26997") override;
	void closeConnection() override;
	void getData() override;
	std::shared_ptr<User> log(std::string username, std::string password) override;
	~TCPConnectionProvider();

private:
	SOCKET winSocket;
};