#pragma once
#include <vector>
#include <string>
#include <memory>

class IDataReader { 
public:
	virtual ~IDataReader() = default;

	virtual std::vector<Data> readData() = 0;
	virtual std::shared_ptr<User> getUserData(std::string username) = 0;
};