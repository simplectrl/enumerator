cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(enum main.cpp)
add_executable(enum_test test.cpp)

add_test(NAME enum_test COMMAND test)