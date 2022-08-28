
#include "SealEncryptionFactory.h"

namespace factory {

	SealEncryptionFactory::SealEncryptionFactory() = default;
	SealEncryptionFactory::~SealEncryptionFactory() = default;

	std::unique_ptr<const SealOperations> SealEncryptionFactory::createDefaultBfvSchema(
		const int plain_modulos,
		const std::size_t poly_modulus_degree) {

		// Create SealContext
		const std::unique_ptr<seal::EncryptionParameters> enc_params
			= std::make_unique<seal::EncryptionParameters>(seal::scheme_type::bfv);

		const std::unique_ptr<const std::vector<seal::Modulus>> coeff_modulus_ptr =
			std::make_unique<std::vector<seal::Modulus>>(seal::CoeffModulus::BFVDefault(poly_modulus_degree));

		enc_params->set_plain_modulus(plain_modulos);
		enc_params->set_coeff_modulus(*coeff_modulus_ptr);
		enc_params->set_poly_modulus_degree(poly_modulus_degree);

		std::unique_ptr<seal::SEALContext> sealContext =
			std::make_unique<seal::SEALContext>(*enc_params);

		const char* var = sealContext->parameter_error_message();

		if (var != "valid") {
			std::cerr << "Default BFV Enc_Parameters are not valid" << std::endl;
		}

		// Create public and secret Key
		const std::unique_ptr<const seal::KeyGenerator> keygenPtr =
			std::make_unique<seal::KeyGenerator>(*sealContext);

		const std::unique_ptr<seal::PublicKey> publicKey = std::make_unique<seal::PublicKey>();
		keygenPtr->create_public_key(*publicKey);

		const std::unique_ptr<const seal::SecretKey> secretKey =
			std::make_unique<seal::SecretKey>(keygenPtr->secret_key());

		// Create SealOperations
		return std::make_unique<SealOperations>(
			std::make_unique<seal::Encryptor>(*sealContext, *publicKey),
			std::make_unique<seal::Decryptor>(*sealContext, *secretKey),
			std::make_shared<seal::Evaluator>(*sealContext)
			);
	}
}