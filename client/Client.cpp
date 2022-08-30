#include "Client.h"
#include "user/UserOperations.h"
#include "utils/StringUtils.h"
#include "factory/SealEncryptionFactory.h"


Client::Client(const std::optional<std::shared_ptr<User>>& user)
	:user{ user }
{
}

std::optional<std::shared_ptr<std::vector<std::shared_ptr<SearchResult>>>> Client::search(
	const std::shared_ptr<Searching>& searching) const
{
	const std::optional<std::string> from = searching->getFrom();
	const std::optional<std::string> to = searching->getTo();
	const std::optional<std::shared_ptr<std::tm>> when = searching->getWhen();

	if (!(from && to && when)) {
		return std::nullopt;
	}

	const std::optional<ClimateFriendlinessDegree> cfd = searching->getClimateFriendlinessDegree();
	const std::optional<TransporterType> transporterType = searching->getTransporterType();

	// Do your db call here and fill the search results

	const std::shared_ptr<std::vector<std::shared_ptr<SearchResult>>> vec =
		std::make_shared<std::vector<std::shared_ptr<SearchResult>>>();

	vec->emplace_back(std::make_shared<SearchResult>(
		std::make_shared<BaseTransporter>(*cfd, *transporterType),
		std::make_shared<BaseProvider>(ProviderType::DB, nullptr),
		*when, *from, *to, 24.39, std::nullopt));

	return std::make_optional<std::shared_ptr<std::vector<std::shared_ptr<SearchResult>>>>(vec);
}

std::shared_ptr<BookingResult> Client::onBooking(const std::shared_ptr<SearchResult>& searchResult) const
{
	if (!user && UserOperations::getUser(*user)) {
		return std::make_shared<BookingResult>();
	}

	return std::make_shared<BookingResult>(
		BookingResultCode::REDIRECT_TO_PAYMENT,
		std::nullopt);
}

std::shared_ptr<seal::Ciphertext> Client::encryptUserId() const {

	if (user) {
		const auto id = (*user)->getUserId();
		const auto cipherText = sealOperations->encrypt(id);
		return std::make_shared<seal::Ciphertext>(*cipherText);
	}

	return nullptr;
}


std::shared_ptr<BookingResult> Client::book(
	const std::shared_ptr<seal::Ciphertext>& encrypted_user_id,
	const std::shared_ptr<BaseProvider>& provider,
	const std::shared_ptr<BaseTransporter>& transporter,
	const std::string& from,
	const std::string& to,
	const double& price,
	std::shared_ptr<std::tm>& booked_for_time) const
{
	if (!user && UserOperations::getUser(*user)) {
		return std::make_shared<BookingResult>();
	}

	const auto bookingPtr = std::make_shared<Booking>(
		encrypted_user_id, provider, transporter, from, to, price, booked_for_time
		);

	return std::make_shared<BookingResult>(
		BookingResultCode::BOOKING_SUCCESSFULL,
		std::make_optional<std::shared_ptr<Booking>>(bookingPtr)
		);
}

std::optional<std::shared_ptr<PaymentResult>> Client::pay(
	const double price,
	const PaymentMethod& paymentMethod) const
{

	if (paymentMethod == PaymentMethod::UNKNOWN && !user && UserOperations::getUser(*user)) {
		return std::make_optional<std::shared_ptr<PaymentResult>>(
			std::make_shared<PaymentResult>(PaymentResultCode::FAILED, std::nullopt)
			);
	}

	const auto invoicingPtr = std::make_shared<Invoicing>(*user, price);
	const auto basePaymentPtr = std::make_shared<BasePayment>(invoicingPtr, paymentMethod);
	const auto paymentResultPtr = std::make_shared<PaymentResult>(
		PaymentResultCode::SUCCESSFUL, std::make_optional<>(basePaymentPtr));

	return std::make_optional<std::shared_ptr<PaymentResult>>(paymentResultPtr);
}

// TODO: Check if user exists in the db first.
std::optional<std::shared_ptr<User>> Client::login(
	const std::wstring& first_name,
	const std::wstring& last_name,
	const std::wstring& email,
	const std::shared_ptr<Address>& addressPtr) const
{
	if (!user) {
		bool isFieldMissing = utils::isEmptyOrNull({ first_name, last_name, email });
		if (isFieldMissing)
		{
			return std::nullopt;
		}
		return std::make_optional<std::shared_ptr<User>>(
			User::createUser(first_name, last_name, email, addressPtr));
	}

	return user;
}



const std::unique_ptr<const SealOperations> Client::sealOperations = factory::SealEncryptionFactory::createDefaultBfvSchema();
