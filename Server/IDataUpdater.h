#pragma once
#include <string>
#include "../Shared/Data.h"

class IDataUpdater {
public:
	virtual ~IDataUpdater() = default;

	virtual void updateData(int id, std::string new_text) = 0;
	virtual void updateData(int id, int new_number) = 0;
};