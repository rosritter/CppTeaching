cmake_minimum_required(VERSION 3.2)
project(app CXX)

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES
        main.cpp
)

add_executable(prog ${SOURCE_FILES})
