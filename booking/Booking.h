#pragma once

#include "provider/BaseProvider.h"
#include "transporter/BaseTransporter.h"
#include "user/User.h"
#include "seal/Ciphertext.h"
#include "utils/Timer.h"

#include <chrono>
#include <optional>

class Booking;

enum class BookingResultCode {
	LOGIN_REQUIRED,
	REDIRECT_TO_PAYMENT,
	BOOKING_SUCCESSFULL,
	BOOKING_FAILED
};

struct BookingResult {
	const BookingResultCode resultCode;
	const std::optional<std::shared_ptr<Booking>> booking;

	BookingResult();
	BookingResult(
		const BookingResultCode& resultCode,
		const std::optional<std::shared_ptr<Booking>>& booking);
};

class Booking {
private:
	std::string booking_number;
	bool isBooked;
	const std::shared_ptr<seal::Ciphertext> encrypted_user_id;
	const std::shared_ptr<BaseProvider> provider;
	const std::shared_ptr<BaseTransporter> transporter;
	const std::string from;
	const std::string to;
	const double price;
	std::shared_ptr<std::tm> booking_time;
	std::shared_ptr<std::tm> booked_for_time;

public:
	Booking(
		const std::shared_ptr<seal::Ciphertext>& encrypted_user_id,
		const std::shared_ptr<BaseProvider>& provider,
		const std::shared_ptr<BaseTransporter>& transporter,
		const std::string& from,
		const std::string& to,
		const double& price,
		std::shared_ptr<std::tm>& booked_for_time = utils::Timer::getCurrentTm()
	);

	bool getIsBooked() const;
	void setIsBooked();
	std::string getBookingNumber() const;
	void setBookingNumber();

};