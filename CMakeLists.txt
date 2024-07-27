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


if(BUILD_TESTS)
  enable_testing()
  add_subdirectory(third-party/gtest)
  file(GLOB BANKING_TEST_SOURCES tests/*.cpp)
  add_executable(check ${BANKING_TEST_SOURCES})
  target_link_libraries(check matrix_lib gtest_main gmock_main)
  add_test(NAME check COMMAND check)
endif()
