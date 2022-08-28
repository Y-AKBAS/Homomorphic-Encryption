#include <stdexcept>
#include "Searching.h"
#include "utils/Timer.h"

Searching::~Searching() = default;

Searching::Searching(
	const std::optional<std::string>& from,
	const std::optional<std::string>& to,
	const std::optional<std::shared_ptr<std::tm>>& when,
	const std::optional<ClimateFriendlinessDegree>& climateFriendlinessDegree,
	const std::optional<TransporterType>& transporterType
) :
	from{ from },
	to{ to },
	when{ when ? when : std::make_optional<std::shared_ptr<std::tm>>(utils::Timer::getCurrentTm()) },
	climateFriendlinessDegree{ climateFriendlinessDegree },
	transporterType{ transporterType }
{
	bool has_from_and_to = from && to;
	if (!has_from_and_to) {
		throw std::invalid_argument("from and to arguments cannot be missing");
	}
}

std::optional<std::string> Searching::getFrom() const
{
	return from;
}

std::optional<std::string> Searching::getTo() const
{
	return to;
}

std::optional<std::shared_ptr<std::tm>> Searching::getWhen() const
{
	return when;
}

std::optional<ClimateFriendlinessDegree> Searching::getClimateFriendlinessDegree() const
{
	return climateFriendlinessDegree;
}

std::optional<TransporterType> Searching::getTransporterType() const
{
	return transporterType;
}
