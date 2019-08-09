#pragma once
#include <string>
#include <memory>
#include <thread>
#include <vector>
#include "IClientService.h"
#include "../Shared/NetworkExceptions.h"

class IListeningProvider {
public:
	virtual ~IListeningProvider() = default;

	virtual void startListening(const std::string& port = "26997") = 0;

protected:
	std::vector<std::shared_ptr<IClientService>> connectionHandlers;
	std::vector<std::thread> connectionThreads;
};