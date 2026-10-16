cmake_minimum_required(VERSION 3.16)

project(Kamotsu LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(Kamotsu SHARED

  kamotsu.cpp
  kamotsu.h
)

target_compile_definitions(Kamotsu PRIVATE KAMOTSU_LIBRARY)
