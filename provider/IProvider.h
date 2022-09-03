#pragma once


#include <string>
#include <memory>
#include <vector>
#include "transporter/BaseTransporter.h"

enum class ProviderType {
	DB,
	FLIXBUS,
	BLABLA,
	BUCHBINDER
};

class IProvider {
public:
	virtual ~IProvider() = default;
	virtual ProviderType getProviderType() const = 0;
	virtual std::shared_ptr<std::vector<std::shared_ptr<BaseTransporter>>> getTransporters() const = 0;
};