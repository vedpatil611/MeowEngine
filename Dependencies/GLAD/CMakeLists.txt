cmake_minimum_required(VERSION 3.5)

add_library(glad src/glad.c)
target_include_directories(glad PRIVATE include)
set_property(TARGET glad PROPERTY POSITION_INDEPENDENT_CODE ON)

