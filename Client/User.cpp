#include "User.h"

User::User(const std::shared_ptr<IUserService>& servicer)
	: servicer{servicer} {
}

std::shared_ptr<const IUserService> User::getServicer() const {
	return servicer;
}
