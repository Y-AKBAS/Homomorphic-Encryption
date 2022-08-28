

link_libraries(${PROJECT_NAME} SEAL::seal)
include_directories(${PROJECT_SOURCE_DIR})
add_library(demo "FactoryDemo.cpp" "FactoryDemo.h")
set_property(TARGET demo PROPERTY CXX_STANDARD 17)

