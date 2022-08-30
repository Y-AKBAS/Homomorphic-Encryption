#include "ClientDemo.h"
#include "client/Client.h"
#include <string>

namespace demo {

	void simulateClientProcess()
	{
		std::cout << "Client with not logged in user is being created..." << std::endl;
		std::unique_ptr<Client> client = std::make_unique<Client>(std::nullopt);

		const std::string from = "Leipzig";
		const std::string to = "Halle";
		std::cout << "A default trip search from: " << from << " to: " << to << " will be done..." << std::endl;
		const std::shared_ptr<Searching> defaultSearch = std::make_shared<Searching>(from, to);

		const std::optional<std::shared_ptr<std::vector<std::shared_ptr<SearchResult>>>>
			searchResult = client->search(defaultSearch);

		if (searchResult) {
			const std::shared_ptr<BookingResult> onBookingResult = client->onBooking((*searchResult)->at(0));

			if (onBookingResult->resultCode == BookingResultCode::LOGIN_REQUIRED) {
				std::cout << "For booking login is required" << std::endl;
				const std::wstring firstName = L"Yasin";
				const std::wstring lastName = L"Akbas";
				const std::wstring email = L"any@gmail.com";
				const std::wstring street = L"any street";
				const std::wstring house_number = L"any house number";
				const std::wstring postal_code = L"any postal code";
				const std::wstring city = L"any city";
				const std::wstring country = L"any country";

				const std::optional<std::shared_ptr<User>> user = client->login(firstName, lastName, email,
					std::make_shared<Address>(street, house_number, postal_code, city, country));

				if (user) {
					std::wcout << "User: "
						<< user.value()->getFirstName()
						<< " " << user.value()->getLastName()
						<< " logged in" << std::endl;

					const auto encrpyted_user_id = client->encryptUserId();
					const auto provider = std::make_shared<BaseProvider>(ProviderType::DB,
						nullptr);
					const auto transporter = std::make_shared<BaseTransporter>();

					std::cout << "user id: " << user.value()->getUserId() << std::endl;
					std::cout << "encrypted user id: " << encrpyted_user_id->data() << std::endl;
					std::cout << "Booking will be done with encrypted user id" << std::endl;

					const double price = 9.0;
					const auto bookingResultPtr = client->book(
						encrpyted_user_id,
						provider,
						transporter,
						from,
						to,
						9.0
					);

					if (bookingResultPtr->resultCode == BookingResultCode::BOOKING_SUCCESSFULL) {
						client->pay(price, PaymentMethod::PAYPAL);
					}

				}

			}
		}
		else {
			std::cout << "Sorry, no results found" << std::endl;
		}

	}

} // namespace