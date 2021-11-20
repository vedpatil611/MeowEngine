cmake_minimum_required(VERSION 3.5)

add_library(stb_image stb_image.cpp)
set_property(TARGET stb_image PROPERTY POSITION_INDEPENDENT_CODE ON)

