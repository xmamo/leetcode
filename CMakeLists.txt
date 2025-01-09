cmake_minimum_required(VERSION 3.14 FATAL_ERROR)
project(leetcode)

# Set the default C++ standard:

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Enable compiler warnings:

if(NOT "${CMAKE_CXX_COMPILER_FRONTEND_VARIANT}" STREQUAL "")
    set(cxx_compiler "${CMAKE_CXX_COMPILER_FRONTEND_VARIANT}")
elseif(NOT "${CMAKE_CXX_SIMULATE_ID}" STREQUAL "")
    set(cxx_compiler "${CMAKE_CXX_SIMULATE_ID}")
else()
    set(cxx_compiler "${CMAKE_CXX_COMPILER_ID}")
endif()

if(cxx_compiler MATCHES "^(GNU|(ARM|Apple)?Clang|Intel(LLVM)?)$")
    set(cxx_flags "-Wall -Wextra -pedantic-errors -fno-rtti")
elseif(cxx_compiler STREQUAL "MSVC")
    set(cxx_flags "/W4 /GR-")
endif()

if(NOT "{cxx_flags}" STREQUAL "")
    if("${CMAKE_CXX_FLAGS}" STREQUAL "")
        set(CMAKE_CXX_FLAGS "${cxx_flags}")
    else()
        string(APPEND CMAKE_CXX_FLAGS " ${cxx_flags}")
    endif()
endif()

# Add the executables:

file(GLOB files *.cpp)

foreach(file IN LISTS files)
    get_filename_component(target "${file}" NAME_WLE)
    add_executable("${target}" "${file}")
endforeach()
