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
	virtual ~IPayment() = 0;
	virtual PaymentMethod getPaymentMethod() const = 0;
};
