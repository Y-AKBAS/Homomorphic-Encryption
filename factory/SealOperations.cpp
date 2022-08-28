#include "SealOperations.h"

SealOperations::SealOperations(
	std::unique_ptr<seal::Encryptor>& encryptorPtr,
	std::unique_ptr<seal::Decryptor>& decryptorPtr,
	std::shared_ptr<seal::Evaluator> evaluatorPtr
) :
	encryptorPtr{ std::move(encryptorPtr) },
	decryptorPtr{ std::move(decryptorPtr) },
	evaluatorPtr{ evaluatorPtr } {}

SealOperations::~SealOperations() = default;

std::unique_ptr<seal::Ciphertext> SealOperations::encrypt(const seal::Plaintext& plainText) const {
	std::unique_ptr<seal::Ciphertext> cipherPtr = std::make_unique<seal::Ciphertext>();
	encryptorPtr->encrypt(plainText, *cipherPtr);
	return std::move(cipherPtr);
}

// TODO: size should be set dynamically
std::unique_ptr<seal::Ciphertext> SealOperations::encrypt(const std::uint64_t& number) const
{
	const std::unique_ptr<seal::Plaintext> plainText = std::make_unique<seal::Plaintext>(seal::util::uint_to_hex_string(&number, std::size_t(1)));
	return encrypt(*plainText);
}

std::unique_ptr<seal::Plaintext> SealOperations::decrypt(const seal::Ciphertext& cipherText) const {
	std::unique_ptr<seal::Plaintext> plainPtr = std::make_unique<seal::Plaintext>();
	decryptorPtr->decrypt(cipherText, *plainPtr);
	return std::move(plainPtr);
}

std::shared_ptr<seal::Evaluator> SealOperations::getEvalutor() const {
	return evaluatorPtr;
}

std::uint64_t SealOperations::hex_string_to_uint64(const std::string& str, const std::size_t number_size) const {
	const char* c_str = str.c_str();
	std::uint64_t* number;
	seal::util::hex_string_to_uint(c_str, str.length(), number_size, number);
	return *number;
}
