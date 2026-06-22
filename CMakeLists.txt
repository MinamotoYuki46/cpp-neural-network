cmake_minimum_required(VERSION 3.26)

project(
    "cpp-neural-network"
    VERSION 0.1.0
    DESCRIPTION "NN from scratch with modern C++23"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(cpp_neural_network INTERFACE)

target_include_directories(cpp_neural_network INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_executable(phase0 examples/phase0.cpp)

target_link_libraries(phase0 PRIVATE cpp_neural_network)

target_compile_options(phase0 PRIVATE
    -Wall
    -Wextra
    -Wpedantic
    -Wconversion
)
