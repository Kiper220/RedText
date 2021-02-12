cmake_minimum_required(VERSION 3.17)
project(EvoStudio)

set(CMAKE_CXX_STANDARD 17)
find_package(PkgConfig REQUIRED)
pkg_check_modules(libnotify)

add_executable(EvoStudio main.cpp)
target_link_libraries(EvoStudio)