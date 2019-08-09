#pragma once
#include <string>
#include "../Shared/NetworkExceptions.h"

class IListeningProvider {
public:
	virtual ~IListeningProvider() = default;

	virtual void startListening(const std::string& port) = 0;
};