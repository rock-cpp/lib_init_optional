# CMakeLists.txt has to be located in the project folder and cmake has to be
# executed from 'project/build' with 'cmake ../'.
cmake_minimum_required(VERSION 2.6)
find_package(Rock)
rock_find_qt4()
rock_init(lib_init_optional 0.1)
rock_standard_layout()
