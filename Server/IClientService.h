#pragma once

class IClientService {
public:
	virtual ~IClientService() = default;

	virtual void authorize() = 0;
	virtual void handleConnection() = 0;
};