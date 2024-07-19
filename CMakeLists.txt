cmake_minimum_required(VERSION 3.4)
project(matrix)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add subdirectories for your application and library
add_subdirectory(matrix_application)
add_subdirectory(matrix_lib)
