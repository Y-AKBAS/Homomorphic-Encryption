
link_libraries(${PROJECT_NAME} utils SEAL::seal)
include_directories(${PROJECT_SOURCE_DIR})
add_library(booking "Booking.cpp" "Booking.h")
set_property(TARGET booking PROPERTY CXX_STANDARD 17)
