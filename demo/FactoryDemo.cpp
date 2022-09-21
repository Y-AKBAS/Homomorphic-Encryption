#include "FactoryDemo.h"
#include <memory>
#include "seal/seal.h"
#include "factory/SealEncryptionFactory.h"
#include "factory/SealOperations.h"


namespace demo {

	void defaulBfvDemo() {
		const std::unique_ptr<factory::SealEncryptionFactory> factoryPtr = std::make_unique<factory::SealEncryptionFactory>();

		const std::unique_ptr<const SealOperations> sealOperations = factoryPtr->createDefaultBfvSchema();

		const std::uint64_t number = 6;
		std::cout << "std::uint64_t to encrypt: " << number << std::endl;
		const std::unique_ptr<seal::Plaintext> plainText = std::make_unique<seal::Plaintext>(seal::util::uint_to_hex_string(&number, std::size_t(1)));
		std::unique_ptr<seal::Ciphertext> cipherText = sealOperations->encrypt(*plainText);
		std::cout << "Encrypted text: " << cipherText->data() << std::endl;
		const std::shared_ptr<seal::Evaluator> evaluator = sealOperations->getEvalutor();
		evaluator->square_inplace(*cipherText);
		std::cout << "Encrypted text after square: " << cipherText->data() << std::endl;

		const std::unique_ptr<seal::Plaintext> decryptedPlaintext = sealOperations->decrypt(*cipherText);
		std::uint64_t squared_number = sealOperations->hex_string_to_uint64(
			decryptedPlaintext->to_string(), std::size_t(1));
		std::cout << "Decrypted text after square: " << squared_number << std::endl;
	}
}