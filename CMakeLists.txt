cmake_minimum_required(VERSION 3.20)

project(op_lab5_array_exceptions LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(lab5_array_exceptions
    src/main.cpp
    src/array_task.cpp
)

target_include_directories(lab5_array_exceptions PRIVATE include)

