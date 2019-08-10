#pragma once
#include <memory>
#include <iostream>
#include "User.h"
#include "IConnectionProvider.h"
#include "IUserService.h"

class ConsoleApplication final {
public:
	static ConsoleApplication& getInstance();
	void run();
	void setConnectionProvider(std::shared_ptr<IConnectionProvider>& provider);

private:
	ConsoleApplication() : connector(nullptr) { }
	ConsoleApplication(const ConsoleApplication&) = delete;
	ConsoleApplication(ConsoleApplication&&) = delete;

	std::shared_ptr<IConnectionProvider> connector;
	std::shared_ptr<User> currentUser;
};