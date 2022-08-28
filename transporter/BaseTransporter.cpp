#include "BaseTransporter.h"

BaseTransporter::BaseTransporter(
	const ClimateFriendlinessDegree cfDegree, const TransporterType tType)
	: climateFriendlinessDegree {cfDegree}, transporterType{tType}
{
}

BaseTransporter::~BaseTransporter() = default;

ClimateFriendlinessDegree BaseTransporter::getClimateFriendliness()
{
	return climateFriendlinessDegree;
}

TransporterType BaseTransporter::getTransporterType()
{
	return transporterType;
}
