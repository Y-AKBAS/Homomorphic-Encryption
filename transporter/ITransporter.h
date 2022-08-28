#pragma once


enum class ClimateFriendlinessDegree {
	UNKNOWN,
	VERY_FRIENDLY,
	FRIENDLY,
	NOT_FRIENDLY,
	HARMFUL
};

enum class TransporterType {
	UNKNOWN,
	BICYCLE,
	SCOOTER,
	BUS,
	TRAM,
	S_BAHN,
	REGIONAL_TRAIN,
	IC,
	ICE,
	PLANE,
	SHIP
};

class ITransporter {
public:
	virtual ~ITransporter() = 0;
	virtual ClimateFriendlinessDegree getClimateFriendliness() = 0;
	virtual TransporterType getTransporterType() = 0;
};