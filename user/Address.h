#pragma once

#include <string>

class Address {
private:
	const std::wstring street;
	const std::wstring house_number;
	const std::wstring postal_code;
	const std::wstring city;
	const std::wstring country;

public:

	Address(
		const std::wstring& street,
		const std::wstring& house_number,
		const std::wstring& postal_code,
		const std::wstring& city,
		const std::wstring& country
	);

	~Address();
};