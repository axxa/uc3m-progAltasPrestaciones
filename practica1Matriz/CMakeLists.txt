cmake_minimum_required(VERSION 3.15)
project(practica1Matriz)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS_DEBUG "-O3 -g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

add_executable(practica1Matriz matrix.cpp main.cpp)