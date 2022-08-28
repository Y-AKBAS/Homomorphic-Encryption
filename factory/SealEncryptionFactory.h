#pragma once

#include <memory>
#include <seal/seal.h>
#include "SealOperations.h"

namespace factory {

	class SealEncryptionFactory {

	public:
		SealEncryptionFactory();
		~SealEncryptionFactory();

		static std::unique_ptr<const SealOperations> createDefaultBfvSchema(
			const int plain_modulos = 1024,
			const std::size_t poly_modulus_degree = 16384);

		static std::unique_ptr<SealOperations> createDefaultCKKSSchema();

	};

}