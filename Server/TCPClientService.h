#pragma once
#include <winsock2.h>
#include <memory>
#include "IClientService.h"
#include "IDataReader.h"
#include "IDataUpdater.h"

class TCPClientService : public IClientService {
public:
	TCPClientService(std::shared_ptr<SOCKET>& socket);
	virtual void handleConnection() override;
	void setDatabaseConnector(std::shared_ptr<IDataReader> reader, std::shared_ptr<IDataUpdater> updater);

private:
	std::shared_ptr<SOCKET> winSocketPtr;
	std::shared_ptr<IDataReader> dataReader;
	std::shared_ptr<IDataUpdater> dataUpdater;
};