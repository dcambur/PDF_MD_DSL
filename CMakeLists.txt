cmake_minimum_required(VERSION 3.17)
project(PDF_MD_DSL)

set(CMAKE_CXX_STANDARD 14)

include_directories(tokens.h)
add_executable(PDF_MD_DSL lex.cpp)
