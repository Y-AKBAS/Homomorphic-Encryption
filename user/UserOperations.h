#pragma once

#include "User.h"
#include <memory>
#include <optional>

class UserOperations {
private:
	static std::map < std::uint64_t, std::shared_ptr<User>> user_map;
	UserOperations();

public:
	~UserOperations();
	static void addUser(const std::shared_ptr<User>& userPtr);
	static std::optional<std::shared_ptr<User>> getUser(const std::shared_ptr<User>& userPtr);
};