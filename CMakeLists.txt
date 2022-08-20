cmake_minimum_required(VERSION 3.20)

project(textgrid VERSION 0.2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(textgrid
    include/Utilities.hpp
    include/Visibility.hpp
    include/Types.hpp
    include/Cell.hpp
    include/Grid.hpp
    src/Utilities.cpp
    src/Cell.cpp
    )

add_executable(demo
    src/demo.cpp)

target_include_directories(textgrid PUBLIC include)

target_link_libraries(demo PRIVATE textgrid)

