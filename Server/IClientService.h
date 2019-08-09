#pragma once

class IClientService {
public:
	virtual ~IClientService() = default;

	virtual void handleConnection() = 0;
};