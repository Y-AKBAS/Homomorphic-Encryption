
include_directories(${PROJECT_SOURCE_DIR})
add_library(provider "BaseProvider.cpp" "BaseProvider.h" "IProvider.h")
set_property(TARGET provider PROPERTY CXX_STANDARD 17)
