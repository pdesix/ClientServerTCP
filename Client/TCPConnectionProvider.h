#pragma once
#include "IConnectionProvider.h"
#include "User.h"

class TCPConnectionProvider : public IConnectionProvider {
public:
	void connect() override;
	void disconnect() override;
	void getData() override;
	std::shared_ptr<User> log(std::string username, std::string password) override;

private:
};