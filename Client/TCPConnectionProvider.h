#pragma once
#include <winsock2.h>
#include "IConnectionProvider.h"
#include "User.h"

class TCPConnectionProvider : public IConnectionProvider {
public:
	void establishConnection(const std::string& ip, const std::string& port) override;
	void closeConnection() override;
	void getData() override;
	std::shared_ptr<User> log(std::string username, std::string password) override;

private:
	SOCKET winSocket;
};