#pragma once

enum class PaymentMethod {
	UNKNOWN,
	PAYPAL,
	VISA,
	MASTER,
	GIROPAY,
	KLARNA
};

class IPayment {
public:
	virtual ~IPayment() = default;
	virtual PaymentMethod getPaymentMethod() const = 0;
};
