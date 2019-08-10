#pragma once
#include <vector>
#include <string>
#include <memory>
#include "../Shared/Data.h"

class IDataReader { 
public:
	virtual ~IDataReader() = default;

	virtual std::vector<Data> readData() = 0;
	virtual int checkUserData(const std::string& username, const std::string& password) = 0;
};