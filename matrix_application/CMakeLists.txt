cmake_minimum_required(VERSION 3.4)
project(matrix_application)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add the main application source file
add_executable(matrix matrix.cpp)

# Include directory for the matrix library
target_include_directories(matrix PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../matrix_lib)

# Link against the matrix library
target_link_libraries(matrix matrix_lib)  # Link here!
