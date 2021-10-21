cmake_minimum_required(VERSION 3.16)
project(main)

set(CMAKE_CXX_STANDARD 17)

add_executable(main main.cpp lib.cpp lib.h)

include_directories(../class_Ellipse/)

target_link_libraries(main class_Ellipse)