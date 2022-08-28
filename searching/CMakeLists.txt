
include_directories(${PROJECT_SOURCE_DIR})
add_library(searching "Searching.h" "Searching.cpp" "SearchResult.h" "SearchResult.cpp")
set_property(TARGET searching PROPERTY CXX_STANDARD 17)
