#include "BaseProvider.h"

BaseProvider::BaseProvider(
	const ProviderType& providerType,
	const std::shared_ptr<std::vector<std::shared_ptr<BaseTransporter>>>& transporters)
	: providerType{ providerType }, transporters{ transporters }
{
}

BaseProvider::~BaseProvider() = default;

ProviderType BaseProvider::getProviderType() const
{
	return providerType;
}

std::shared_ptr<std::vector<std::shared_ptr<BaseTransporter>>> BaseProvider::getTransporters() const
{
	return transporters;
}


