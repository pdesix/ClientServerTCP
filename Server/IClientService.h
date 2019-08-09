#pragma once

class IClientService {
public:
	virtual void authorize() = 0;
	virtual void handleConnection() = 0;
};