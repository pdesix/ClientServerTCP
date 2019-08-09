#pragma once
#include <string>
#include <memory>
#include "User.h"

class IConnectionProvider {
public:
	virtual void connect() = 0;
	virtual void disconnect() = 0;
	virtual void getData() = 0;
	virtual std::shared_ptr<User> log(std::string username, std::string password) = 0;	
};