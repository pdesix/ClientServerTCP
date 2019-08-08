#pragma once
#include <vector>
#include <string>

class IDataReader { 
public:
	virtual std::vector<Data> ReadData() = 0;
	virtual User* GetUserData(std::string username) = 0;
};