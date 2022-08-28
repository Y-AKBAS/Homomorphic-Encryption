
cmake_minimum_required (VERSION 3.8)

project ("ThesisEncryption" CXX)

add_executable (${PROJECT_NAME} "ThesisEncryption.cpp" "ThesisEncryption.h")

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)
set_directory_properties(PROPERTIES LINKER_LANGUAGE CXX)

find_package(SEAL 4.0 REQUIRED)

set(Boost_INCLUDE_DIR C:/MyBoost/include/boost-1_77)
set(Boost_LIBRARY_DIR C:/MyBoost/lib)
find_package(Boost 1.77 REQUIRED)

add_subdirectory(transporter)
add_subdirectory(provider)
add_subdirectory(factory)
add_subdirectory(user)
add_subdirectory(booking)
add_subdirectory(payment)
add_subdirectory(searching)
add_subdirectory(demo)
add_subdirectory(utils)
add_subdirectory(client)

target_link_directories(${PROJECT_NAME} PUBLIC ${Boost_LIBRARY_DIR} utils transporter factory provider user searching booking payment demo client)
target_include_directories(${PROJECT_NAME} PUBLIC ${Boost_INCLUDE_DIR} utils transporter factory provider user searching booking payment demo client)
target_link_libraries(${PROJECT_NAME} SEAL::seal Boost::boost utils transporter factory provider user searching booking payment demo client)


# TODO: Add tests and install targets if needed.
