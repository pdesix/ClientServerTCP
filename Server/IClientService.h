#pragma once
#include "IDataReader.h"
#include "IDataUpdater.h"

class IClientService {
public:
	virtual ~IClientService() = default;

	virtual void handleConnection() = 0;
};