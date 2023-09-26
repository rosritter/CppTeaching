cmake_minimum_required (VERSION 3.14)
project(cpp_template VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR})
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_BINARY_DIR})

################################
# build type
################################

# Set a default build type if not passed
set(default_build_type "Release")
if(NOT CMAKE_BUILD_TYPE)
  message(STATUS "Setting build type to '${default_build_type}' as none was specified.")
  set(CMAKE_BUILD_TYPE "${default_build_type}" CACHE STRING "Choose the type of build." FORCE)
  # Set the possible values of build type for cmake-gui
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS
    "Debug" "Release")
endif()



################################
# src
################################


add_executable(cmatrix
  ${CMAKE_CURRENT_SOURCE_DIR}/matrixMult/main.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/matrixMult/func.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/matrixMult/func.hpp
)
