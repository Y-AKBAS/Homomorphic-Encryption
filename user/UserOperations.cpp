
#include "UserOperations.h"

UserOperations::UserOperations() = default;
UserOperations::~UserOperations() = default;


void UserOperations::addUser(const std::shared_ptr<User>& userPtr) {
	user_map.insert({ userPtr->getUserId(), userPtr });
}

std::optional<std::shared_ptr<User>> UserOperations::getUser(const std::shared_ptr<User>& userPtr) {

	const auto it = user_map.find(userPtr->getUserId());
	const auto endIt = user_map.end();

	return it != endIt ? std::make_optional(it->second) : std::nullopt;
}
