cmake_minimum_required(VERSION 2.8.12)
project(hw1)

set(SOURCE_EXE ./src/main.cpp)

add_executable(main.exe ${SOURCE_EXE})

add_library(tsvparser ./src/TSVParser.cpp)
add_library(splitter ./src/splitter.cpp)

include_directories(inc)

target_link_libraries(main tsvparser)