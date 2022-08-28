

link_libraries(${PROJECT_NAME} SEAL::seal)
include_directories(${PROJECT_SOURCE_DIR})
add_library(payment "Invoicing.cpp" "Invoicing.h" "IPayment.h" "BasePayment.h" "BasePayment.cpp")
set_property(TARGET payment PROPERTY CXX_STANDARD 17)
