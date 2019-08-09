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
	void setConnectionProvider(const IConnectionProvider&);

private:
	ConsoleApplication() = default;
	ConsoleApplication(const ConsoleApplication&) = delete;
	ConsoleApplication(ConsoleApplication&&) = delete;

	std::unique_ptr<IConnectionProvider> connector;
	std::shared_ptr<User> currentUser;
};