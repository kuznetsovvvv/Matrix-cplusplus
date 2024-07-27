cmake_minimum_required(VERSION 3.4)
project(matrix)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add subdirectories for your application and library
add_subdirectory(matrix_application)
add_subdirectory(matrix_lib)

if(BUILD_TESTS)
  add_compile_options(--coverage)
endif()

add_library(matrix_lib STATIC ${CMAKE_CURRENT_SOURCE_DIR}/matrix_lib/cmatrix.cpp )
target_include_directories(matrix_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/matrix_lib)
target_link_libraries(matrix_lib gcov)

if(BUILD_TESTS)
  enable_testing()
  add_subdirectory(third-party/gtest)
  file(GLOB BANKING_TEST_SOURCES tests/*.cpp)
  add_executable(check ${BANKING_TEST_SOURCES})
  target_link_libraries(check banking gtest_main gmock_main)
  add_test(NAME check COMMAND check)
endif()
