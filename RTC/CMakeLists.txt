cmake_minimum_required(VERSION 3.17)
project(RTC)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(Lexer)
add_subdirectory(Parser)

add_executable(RTC main.cpp)
target_link_libraries(RTC RLexer RParser)
target_include_directories(RTC PUBLIC ./)