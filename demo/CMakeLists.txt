
link_libraries(${PROJECT_NAME} SEAL::seal Boost::boost)
include_directories(${PROJECT_SOURCE_DIR})
add_library(demo "FactoryDemo.cpp" "FactoryDemo.h" "ClientDemo.h" "ClientDemo.cpp")
set_property(TARGET demo PROPERTY CXX_STANDARD 17)
