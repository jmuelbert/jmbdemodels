cmake_minimum_required(VERSION 3.15)
project(jmbdemodels CXX)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_library(jmbdemodels hello.cpp)