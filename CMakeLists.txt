cmake_minimum_required(VERSION 3.1)
project("tuple_examples")

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_STANDARD 14)

enable_testing()

add_executable(example1 example1.cpp)
add_test(example1 example1)

add_executable(example2 example2.cpp)
add_test(example2 example2)

add_executable(example3 example3.cpp)
add_test(example3 example3)

add_executable(example4 example4.cpp)
add_test(example4 example4)

add_executable(example5 example5.cpp)
add_test(example5 example5)
