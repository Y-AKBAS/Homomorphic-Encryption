
add_library(transporter "BaseTransporter.cpp" "BaseTransporter.h" "ITransporter.h")
set_property(TARGET transporter PROPERTY CXX_STANDARD 17)
