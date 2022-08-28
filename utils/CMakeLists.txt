
link_libraries(${PROJECT_NAME} SEAL::seal Boost::boost)
add_library(utils "Timer.h" "Timer.cpp" "StringUtils.h" "StringUtils.cpp")
set_property(TARGET utils PROPERTY CXX_STANDARD 17)
