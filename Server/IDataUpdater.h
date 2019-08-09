#pragma once
#include <string>

class IDataUpdater {
public:
	virtual void updateData(int id, std::string new_text) = 0;
	virtual void updateData(int id, int new_number) = 0;
};