cmake_minimum_required(VERSION 3.5)

project(sudoku_solver LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(sudoku_solver main.cpp sudoku.h sudoku.cpp)
