cmake_minimum_required(VERSION 3.20)
project(ConversionAMovimientoDiscreto)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ConversionAMovimientoDiscreto
        cmake-build-debug/Testing/Temporary/LastTest.log
        cmake-build-debug/cmake_install.cmake
        cmake-build-debug/CMakeCache.txt
        cmake-build-debug/ConversionAMovimientoDiscreto
        cmake-build-debug/ConversionAMovimientoDiscreto.cbp
        cmake-build-debug/Makefile
        main.cpp
        MovimientoDiscreto.cpp
        MovimientoDiscreto.hpp)
