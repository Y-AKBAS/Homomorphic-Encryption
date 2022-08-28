#pragma once


#include "transporter/BaseTransporter.h"
#include "provider/BaseProvider.h"

#include <optional>
#include <string>
#include <chrono>
#include <memory>
#include <vector>

struct SearchResult
{
	SearchResult(
		const std::shared_ptr<BaseTransporter>& transporter,
		const std::shared_ptr<BaseProvider>& provider,
		const std::shared_ptr<std::tm>& when,
		const std::string& from,
		const std::string& to,
		const double& price,
		const std::optional<std::vector<std::shared_ptr<SearchResult>>>& change
	);

	const std::shared_ptr<BaseTransporter>& transporter;
	const std::shared_ptr<BaseProvider>& provider;
	const std::shared_ptr<std::tm> when;
	const std::string from;
	const std::string to;
	const double price;
	const std::optional<std::vector<std::shared_ptr<SearchResult>>> change;
};
