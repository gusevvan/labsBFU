cmake_minimum_required(VERSION 3.20)
project(problem4)

set(CMAKE_CXX_STANDARD 14)

include_directories(./inc)

add_executable(problem4 main.cpp)

file(COPY ./input.txt DESTINATION ".")