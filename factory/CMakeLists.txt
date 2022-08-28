
link_libraries(${PROJECT_NAME} SEAL::seal)
add_library(factory "SealEncryptionFactory.cpp" "SealEncryptionFactory.h" "SealOperations.cpp" "SealOperations.h")
set_property(TARGET factory PROPERTY CXX_STANDARD 17)
