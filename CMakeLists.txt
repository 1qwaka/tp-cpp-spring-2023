cmake_minimum_required(VERSION 2.8.12)
project(hw1)

set(SOURCE_EXE ./src/main.cpp)

set (CMAKE_CXX_STANDARD 17)

add_executable(main.exe ${SOURCE_EXE})

add_library(tsvparser ./src/TSVParser.cpp)
add_library(principalsparser ./src/PrincipalsParser.cpp)
add_library(titlebasicsparser ./src/TitleBasicsParser.cpp)
add_library(akasparser ./src/AkasParser.cpp)
add_library(splitter ./src/splitter.cpp)
add_library(args ./src/args.cpp)

include_directories(inc)

target_link_libraries(main.exe principalsparser titlebasicsparser akasparser tsvparser splitter args)
