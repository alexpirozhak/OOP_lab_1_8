cmake_minimum_required(VERSION 3.27)
project(OOP_lab_1_8)

set(CMAKE_CXX_STANDARD 23)

add_executable(OOP_lab_1_8 main.cpp
        Account.cpp
)

add_subdirectory(Google_tests)
