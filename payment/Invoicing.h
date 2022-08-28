#pragma once

#include "user/User.h"

class Invoicing {
private:
	const std::shared_ptr<User> user;
	const double price;
	std::shared_ptr<std::tm> invoicing_time;

public:

	Invoicing(
		const std::shared_ptr<User> user,
		const double& price
	);

};