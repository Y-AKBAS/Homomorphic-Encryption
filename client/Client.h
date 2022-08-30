#pragma once

#include "searching/Searching.h"
#include "searching/SearchResult.h"
#include "factory/SealOperations.h"
#include "user/User.h"
#include "booking/Booking.h"
#include "payment/BasePayment.h"

#include <vector>

class Client {
public:

	Client(
		const std::optional<std::shared_ptr<User>>& user
	);

	std::optional< std::shared_ptr<std::vector<std::shared_ptr<SearchResult>>>> search(
		const std::shared_ptr<Searching>& searching) const;

	std::shared_ptr<BookingResult> onBooking(const std::shared_ptr<SearchResult>& searchResult) const;

	std::shared_ptr<BookingResult> book(
		const std::shared_ptr<seal::Ciphertext>& encrypted_user_id,
		const std::shared_ptr<BaseProvider>& provider,
		const std::shared_ptr<BaseTransporter>& transporter,
		const std::string& from,
		const std::string& to,
		const double& price,
		std::shared_ptr<std::tm>& booked_for_time = utils::Timer::getCurrentTm()
	) const;

	std::optional<std::shared_ptr<PaymentResult>> pay(
		const double price,
		const PaymentMethod& paymentMethod = PaymentMethod::UNKNOWN
	) const;

	std::optional<std::shared_ptr<User>> login(
		const std::wstring& first_name,
		const std::wstring& last_name,
		const std::wstring& email,
		const std::shared_ptr<Address>& addressPtr
	) const;

	std::shared_ptr<seal::Ciphertext> encryptUserId() const;

private:

	static const std::unique_ptr<const SealOperations> sealOperations;
	std::optional<std::shared_ptr<User>> user;
};
