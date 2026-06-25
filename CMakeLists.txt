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

add_library(cpp_neural_network
    src/core/matrix.cpp
)

target_include_directories(cpp_neural_network PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)


target_compile_options(cpp_neural_network PRIVATE
    -Wall
    -Wextra
    -Wpedantic
    -Wconversion
)


add_executable(phase0 examples/phase0.cpp)
target_link_libraries(phase0 PRIVATE cpp_neural_network)

add_executable(phase1_matrix examples/phase1_matrix.cpp)
target_link_libraries(phase1_matrix PRIVATE cpp_neural_network)

add_executable(phase2_operator examples/phase2_operator.cpp)
target_link_libraries(phase2_operator PRIVATE cpp_neural_network)