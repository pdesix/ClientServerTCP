#pragma once
#include <stdexcept>

class ConnectionError : public std::runtime_error {
public:
	ConnectionError(const char* c) : std::runtime_error(c) { }
};

class InitializationError : public std::runtime_error {
public:
	InitializationError(const char* c) : std::runtime_error(c) { }
};