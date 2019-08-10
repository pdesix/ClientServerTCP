#pragma once
#include <iostream>
#include <memory>
#include "IUserService.h"

class User {
public:
	User(const std::shared_ptr<IUserService>&);
	virtual std::shared_ptr<IUserService> getServicer() const final;

protected:
	std::shared_ptr<IUserService> servicer;
	std::string name;
};