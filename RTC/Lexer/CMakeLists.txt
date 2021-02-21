cmake_minimum_required(VERSION 3.17)
project(source/InterfaceLexer)

add_library(RLexer SHARED
        ./source/InterfaceLexer/LexerInterface.cpp
        ./source/RLexer/RLexer.cpp
        ./source/RLexer/Lexicons/Symword.cpp)
target_include_directories(RLexer PUBLIC ./include)