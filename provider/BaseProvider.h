#pragma once

#include "IProvider.h"

class BaseProvider : public IProvider {
private:
	const ProviderType providerType;
	const std::shared_ptr<std::vector<std::shared_ptr<BaseTransporter>>>& transporters;
public:
	BaseProvider(const ProviderType& providerType,
		const std::shared_ptr<std::vector<std::shared_ptr<BaseTransporter>>>& transporters);
	virtual ~BaseProvider();
	virtual ProviderType getProviderType() const override;
	virtual std::shared_ptr<std::vector<std::shared_ptr<BaseTransporter>>> getTransporters() const override;
};
