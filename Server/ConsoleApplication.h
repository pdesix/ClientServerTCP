#pragma once
#include <memory>
#include <iostream>
#include "IListeningProvider.h"
#include "TCPListeningProvider.h"

class ConsoleApplication final {
public:
	static ConsoleApplication& getInstance();
	void run();

private:
	ConsoleApplication() : listener{ std::make_unique<TCPListeningProvider>() } { }
	ConsoleApplication(const ConsoleApplication&) = delete;
	ConsoleApplication(ConsoleApplication&&) = delete;

	std::unique_ptr<IListeningProvider> listener;
};