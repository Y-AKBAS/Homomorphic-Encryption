
include_directories(${PROJECT_SOURCE_DIR})
link_libraries(${PROJECT_NAME} SEAL::seal utils)
add_library(client "Client.h" "Client.cpp")
set_property(TARGET client PROPERTY CXX_STANDARD 17)
