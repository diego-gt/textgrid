cmake_minimum_required(VERSION 3.20)

project(textgrid VERSION 0.2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(textgrid
    include/Visibility.hpp
    include/TextCell.hpp
    include/TextGrid.hpp
    src/TextCell.cpp
    src/TextGrid.cpp)

add_executable(demo
    src/main.cpp)

target_include_directories(textgrid PUBLIC include)

target_link_libraries(demo PRIVATE textgrid)

