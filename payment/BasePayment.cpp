#include "BasePayment.h"

PaymentResult::PaymentResult()
	: paymentResultCode{ PaymentResultCode::FAILED }, basePayment{ std::nullopt } {}

PaymentResult::PaymentResult(
	const PaymentResultCode& paymentResultCode,
	const std::optional<std::shared_ptr<BasePayment>>& basePayment)
	: paymentResultCode{ paymentResultCode }, basePayment{ basePayment }
{
}

BasePayment::~BasePayment() = default;

BasePayment::BasePayment(
	const std::shared_ptr<Invoicing>& invoicing,
	const PaymentMethod& paymentMethod)
	: paymentMethod{ paymentMethod }, invoicing{ invoicing } {}

PaymentMethod BasePayment::getPaymentMethod() const {
	return paymentMethod;
}
