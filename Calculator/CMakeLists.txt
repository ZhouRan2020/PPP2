cmake_minimum_required(VERSION 3.23)
project(calculator)

set(CMAKE_CXX_STANDARD 11)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}")

message(STATUS "win 64 build start")

add_executable(calculator calculator_main.cpp)

