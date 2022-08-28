#include "User.h"
#include "UserOperations.h"

User::User(
	const std::wstring& first_name,
	const std::wstring& last_name,
	const std::wstring& email,
	const std::shared_ptr<Address>& addressPtr) :
	first_name{ first_name },
	last_name{ last_name },
	email{ email },
	addressPtr{ addressPtr },
	user_id{ ++user_count }
{};

std::shared_ptr<User> User::createUser(
	const std::wstring& first_name,
	const std::wstring& last_name,
	const std::wstring& email,
	const std::shared_ptr<Address>& addressPtr)
{
	const std::shared_ptr<User> userPtr(new User(
		first_name,
		last_name,
		email,
		addressPtr
	));

	UserOperations::addUser(userPtr);

	return userPtr;
}

std::uint64_t User::getUserCount() const {
	return user_count;
}

std::uint64_t User::getUserId() const {
	return user_id;
}

std::wstring User::getFirstName() const {
	return first_name;
}

std::wstring User::getLastName() const {
	return last_name;
}

std::wstring User::getEmail() const {
	return email;
}

std::shared_ptr<Address> User::getAddress() const {
	return addressPtr;
}