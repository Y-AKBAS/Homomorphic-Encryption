#include "Booking.h"
#include "Booking.h"
#include "utils/Timer.h"
#include "utils/StringUtils.h"

BookingResult::BookingResult() :
	resultCode{ BookingResultCode::LOGIN_REQUIRED }, booking{ std::nullopt }
{
}

BookingResult::BookingResult(
	const BookingResultCode& resultCode,
	const std::optional<std::shared_ptr<Booking>>& booking) :
	resultCode{ resultCode }, booking{ booking } {}

Booking::Booking(
	const std::shared_ptr<seal::Ciphertext>& encrypted_user_id,
	const std::shared_ptr<BaseProvider>& provider,
	const std::shared_ptr<BaseTransporter>& transporter,
	const std::string& from,
	const std::string& to,
	const double& price,
	std::shared_ptr<std::tm>& booked_for_time)
	: encrypted_user_id{ encrypted_user_id },
	provider{ provider },
	transporter{ transporter },
	from{ from },
	to{ to },
	price{ price },
	booked_for_time{ booked_for_time },
	booking_time{ utils::Timer::getCurrentTm() },
	booking_number{ utils::generateUUID() }
{
}

bool Booking::getIsBooked() const {
	return isBooked;
}

void Booking::setIsBooked() {
	this->isBooked = true;
}

std::string Booking::getBookingNumber() const {
	return booking_number;
}
