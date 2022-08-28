#pragma once

#include "Address.h"

#include <map>
#include <memory>

class User {
private:
	static std::uint64_t user_count;
	const std::uint64_t user_id;
	const std::wstring first_name;
	const std::wstring last_name;
	const std::wstring email;
	const std::shared_ptr<Address> addressPtr;

	User(
		const std::wstring& first_name,
		const std::wstring& last_name,
		const std::wstring& email,
		const std::shared_ptr<Address>& addressPtr
	);

public:

	static std::shared_ptr<User> createUser(
		const std::wstring& first_name,
		const std::wstring& last_name,
		const std::wstring& email,
		const std::shared_ptr<Address>& addressPtr
	);

	std::uint64_t getUserCount() const;
	std::uint64_t getUserId() const;
	std::wstring getFirstName() const;
	std::wstring getLastName() const;
	std::wstring getEmail() const;
	std::shared_ptr<Address> getAddress()const;

};