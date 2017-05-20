cmake_minimum_required(VERSION 3.7)
project(DateOverloaded)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Date.cpp Date.h)
add_executable(DateOverloaded ${SOURCE_FILES})