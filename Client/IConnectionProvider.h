#pragma once
#include <string>
#include <memory>
#include <exception>
#include "User.h"

class ConnectionError : public std::runtime_error {
public:
	ConnectionError(const char* c) : std::runtime_error(c) { }
};

class InitializationError : public std::runtime_error {
public:
	InitializationError(const char* c) : std::runtime_error(c) { }
};

class IConnectionProvider {
public:
	virtual void establishConnection(const std::string& ip, const std::string& port) = 0;
	virtual void closeConnection() = 0;
	virtual void getData() = 0;
	virtual std::shared_ptr<User> log(std::string username, std::string password) = 0;	
};