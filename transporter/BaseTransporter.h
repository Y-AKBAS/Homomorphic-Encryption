#pragma once

#include "ITransporter.h"


class BaseTransporter : public ITransporter {

private:
	ClimateFriendlinessDegree climateFriendlinessDegree;
	TransporterType transporterType;

public:
	BaseTransporter(
		const ClimateFriendlinessDegree cfDegree = ClimateFriendlinessDegree::UNKNOWN,
		const TransporterType tType = TransporterType::UNKNOWN);
	virtual ~BaseTransporter() override;
	virtual ClimateFriendlinessDegree getClimateFriendliness() override;
	virtual TransporterType getTransporterType() override;
};