#pragma once
#include <string>
#include <memory>
#include <exception>
#include "../Shared/NetworkExceptions.h"
#include "User.h"

class IConnectionProvider {
public:
	virtual ~IConnectionProvider() = default;

	virtual void establishConnection(const std::string& ip = "127.0.0.1", const std::string& port = "26997") = 0;
	virtual void closeConnection() = 0;
	virtual void getData() = 0;
	virtual std::shared_ptr<User> log(std::string username, std::string password) = 0;	
};