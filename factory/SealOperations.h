#pragma once

#include <memory>
#include "seal/seal.h"

class SealOperations {
private:
	const std::unique_ptr<seal::Encryptor> encryptorPtr;
	const std::unique_ptr<seal::Decryptor> decryptorPtr;
	const std::shared_ptr<seal::Evaluator> evaluatorPtr;

public:
	SealOperations(
		std::unique_ptr<seal::Encryptor>& encryptorPtr,
		std::unique_ptr<seal::Decryptor>& decryptorPtr,
		std::shared_ptr<seal::Evaluator> evaluatorPtr);

	~SealOperations();

	std::unique_ptr<seal::Ciphertext> encrypt(const seal::Plaintext& plainText) const;
	std::unique_ptr<seal::Ciphertext> encrypt(const std::uint64_t& number) const;
	std::unique_ptr<seal::Plaintext> SealOperations::decrypt(const seal::Ciphertext& cipherText) const;
	std::shared_ptr<seal::Evaluator> getEvalutor() const;
	std::uint64_t hex_string_to_uint64(const std::string& str, const std::size_t number_size) const;

};