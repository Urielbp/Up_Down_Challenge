cmake_minimum_required(VERSION 3.14)
project(Up_Down_Challenge C)

set(CMAKE_C_STANDARD 99)

add_executable(Up_Down_Challenge main.c aStar.c aStar.h heap.c heap.h state.c state.h)