#pragma once
#include <string>

class IDataUpdater {
public:
	virtual void UpdateData(int id, std::string new_text) = 0;
	virtual void UpdateData(int id, int new_number) = 0;
};