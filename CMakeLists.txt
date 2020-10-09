cmake_minimum_required(VERSION 3.17)
project(RedText)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(Lexer)
add_subdirectory(Parser)

add_executable(RedText main.cpp)
target_link_libraries(RedText RLexer RParser)
target_include_directories(RedText PUBLIC ./)