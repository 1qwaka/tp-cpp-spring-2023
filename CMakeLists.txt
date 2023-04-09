cmake_minimum_required(VERSION 2.8.12)
project(hw2)

set(SOURCE_EXE ./src/main.cpp)

set (CMAKE_CXX_STANDARD 17)

add_executable(calculator ${SOURCE_EXE})


include_directories(inc)

