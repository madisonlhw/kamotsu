cmake_minimum_required(VERSION 3.16)

project(Kamotsu VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(exiv2 REQUIRED CONFIG NAMES exiv2)
find_package(nlohmann_json 3.12.0 REQUIRED)

add_library(Kamotsu SHARED
  # Headers
  include/Kamotsu/kamotsu.h
  include/Kamotsu/airline.h
  include/Kamotsu/airport.h
  include/Kamotsu/typecode.h
  include/Kamotsu/aircraft.h

  # Source Files
  src/kamotsu.cpp
  src/airline.cpp
  src/airport.cpp
  src/typecode.cpp
  src/aircraft.cpp
)

target_compile_definitions(Kamotsu PRIVATE KAMOTSU_LIBRARY)
target_include_directories(Kamotsu PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)
target_link_libraries(Kamotsu PRIVATE Exiv2::exiv2lib nlohmann_json::nlohmann_json)