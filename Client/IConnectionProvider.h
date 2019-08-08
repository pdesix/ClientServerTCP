#pragma once
#include <string>

class IConnectionProvider {
public:
	virtual void Connect() = 0;
	virtual void Disconnect() = 0;
	virtual void GetData() = 0;
	virtual User* Log(std::string username, std::string password) = 0;	
};