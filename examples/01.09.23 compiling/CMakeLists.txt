cmake_minimum_required(VERSION 3.2)
project(app CXX)

set(CMAKE_CXX_STANDARD 17)
#add_definitions(-DCHECK)

find_package(OpenMP REQUIRED)

include_directories(headers)


set(HEADER_FILES
        headers/output.hpp
        headers/square.hpp
    )

set(SOURCE_FILES
        src/output.cpp
        src/square.cpp
        main.cpp
)


add_executable(HelloCMake ${SOURCE_FILES} ${HEADER_FILES})
target_link_libraries(HelloCMake PRIVATE OpenMP::OpenMP_CXX)
