#pragma once

class IClientService {
public:
	virtual void Authorize() = 0;
	virtual void HandleConnection() = 0;
};