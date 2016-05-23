rock_library(lib_init
    SOURCES Dummy.cpp
    HEADERS Dummy.hpp)

rock_executable(lib_init_bin Main.cpp
    DEPS lib_init)

