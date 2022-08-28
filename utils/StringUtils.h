#pragma once

#include <string>
#include <vector>
#include <memory>

#include <boost/uuid/uuid_generators.hpp> // generators
#include "boost/lexical_cast.hpp"
#include <boost/uuid/uuid_io.hpp>         // streaming operators etc.



namespace utils {
	// vars

	const std::unique_ptr<boost::uuids::random_generator> uuidGenPtr =
		std::make_unique<boost::uuids::random_generator>();

	//functions
	bool isEmptyOrNull(const std::vector<std::string>& vec);
	bool isEmptyOrNull(const std::vector<std::wstring>& vec);
	std::string generateUUID();
}