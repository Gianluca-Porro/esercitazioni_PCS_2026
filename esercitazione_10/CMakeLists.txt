cmake_minimum_required(VERSION 3.20)

project(esercitazione10)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow")

add_executable(main main.cpp gradiente_coniugato.hpp)
add_test(NAME main COMMAND main)

enable_testing()

include_directories(${CMAKE_SOURCE_DIR})