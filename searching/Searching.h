#pragma once

#include "transporter/ITransporter.h"
#include "utils/Timer.h"

#include <optional>
#include <string>
#include <chrono>
#include <memory>


class Searching {
public:
	~Searching();
	Searching(
		const std::optional<std::string>& from,
		const std::optional<std::string>& to,
		const std::optional<std::shared_ptr<std::tm>>& when = std::make_optional<std::shared_ptr<std::tm>>(utils::Timer::getCurrentTm()),
		const std::optional<ClimateFriendlinessDegree>& climateFriendlinessDegree = ClimateFriendlinessDegree::VERY_FRIENDLY,
		const std::optional<TransporterType>& transporterType = TransporterType::UNKNOWN
	);

	std::optional<std::string> getFrom() const;
	std::optional<std::string> getTo() const;
	std::optional<std::shared_ptr<std::tm>> getWhen() const;
	std::optional<ClimateFriendlinessDegree> getClimateFriendlinessDegree() const;
	std::optional<TransporterType> getTransporterType() const;

private:
	const std::optional<ClimateFriendlinessDegree> climateFriendlinessDegree;
	const std::optional<TransporterType> transporterType;
	const std::optional<std::string> from;
	const std::optional<std::string> to;
	const std::optional<std::shared_ptr<std::tm>> when;
};