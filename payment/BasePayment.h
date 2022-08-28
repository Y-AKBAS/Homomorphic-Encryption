#pragma once

#include "IPayment.h"
#include "Invoicing.h"
#include <optional>

class BasePayment;

enum class PaymentResultCode {
	FAILED,
	SUCCESSFUL
};

struct PaymentResult {

	PaymentResult();
	PaymentResult(
		const PaymentResultCode& paymentResultCode,
		const std::optional<std::shared_ptr<BasePayment>>& basePayment
	);

	const PaymentResultCode paymentResultCode;
	const std::optional<std::shared_ptr<BasePayment>> basePayment;
};

class BasePayment : public IPayment {
public:
	virtual ~BasePayment();
	BasePayment(
		const std::shared_ptr<Invoicing>& invoicing,
		const PaymentMethod& paymentMethod = PaymentMethod::UNKNOWN);
	PaymentMethod getPaymentMethod() const override;

private:
	const PaymentMethod paymentMethod;
	const std::shared_ptr<Invoicing> invoicing;
};