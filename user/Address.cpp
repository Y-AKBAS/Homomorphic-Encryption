#include "Address.h"

Address::Address(
	const std::wstring& street,
	const std::wstring& house_number,
	const std::wstring& postal_code,
	const std::wstring& city,
	const std::wstring& country
) :
	street{ street },
	house_number{ house_number },
	postal_code{ postal_code },
	city{ city },
	country{ country } {}

Address::~Address() = default;
