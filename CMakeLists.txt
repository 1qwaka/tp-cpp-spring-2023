cmake_minimum_required(VERSION 2.8.12)
project(hw2)

set(SOURCE_EXE ./src/main.cpp)

set (CMAKE_CXX_STANDARD 17)

add_executable(calculator ${SOURCE_EXE})

add_library(token ./src/token.cpp)
add_library(tokenizer ./src/tokenizer.cpp)
add_library(expression_transformer ./src/expression_transformer.cpp)
add_library(expression_tree ./src/expression_tree.cpp)
add_library(calculatables ./src/calculatables.cpp)

include_directories(inc)

target_link_libraries(calculator tokenizer expression_transformer expression_tree calculatables token)
