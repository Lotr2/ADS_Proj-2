cmake_minimum_required(VERSION 3.29)
project(untitled7)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled7 main.cpp
        SudokuGrid.h
        SudokuGrid.cpp
        SudokuGame.h
        SudokuGame.cpp)
