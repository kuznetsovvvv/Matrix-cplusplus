cmake_minimum_required(VERSION 3.4)
project(matrix)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../matrix_lib matrix_lib_dir)
add_executable(matrix ${CMAKE_CURRENT_SOURCE_DIR}/matrix.cpp)
target_include_directories(matrix_lib PUBLIC
${CMAKE_CURRENT_SOURCE_DIR}/../matrix_lib
)
target_link_libraries(matrix matrix_lib)
