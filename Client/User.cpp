#include "User.h"

User::User(const std::shared_ptr<IUserService>& servicer)
	: servicer{servicer} {
}

std::shared_ptr<IUserService> User::getServicer() const {
	return servicer;
}
