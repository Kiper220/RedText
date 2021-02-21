cmake_minimum_required(VERSION 3.17)
project(Lexer)

add_library(RParser SHARED Parser.cpp)
target_link_libraries(RParser RLexer)
target_include_directories(RParser PUBLIC ../include ../Lexer)