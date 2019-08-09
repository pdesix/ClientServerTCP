#pragma once
#include <memory>
#include <iostream>
#include "IListeningProvider.h"

class ConsoleApplication final {
public:
	static ConsoleApplication& getInstance();
	void run();

private:
	ConsoleApplication() = default;
	ConsoleApplication(const ConsoleApplication&) = delete;
	ConsoleApplication(ConsoleApplication&&) = delete;

	std::unique_ptr<IListeningProvider> listener;
};