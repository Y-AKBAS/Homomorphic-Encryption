
link_libraries(${PROJECT_NAME})
add_library(user "User.cpp" "User.h" "Address.h" "Address.cpp" "UserOperations.h" "UserOperations.cpp")
set_property(TARGET user PROPERTY CXX_STANDARD 17)
