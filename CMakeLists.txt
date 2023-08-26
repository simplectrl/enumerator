cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")

add_executable(enum enum.cpp)
add_executable(enum_v1 enum_v1.cpp)

add_executable(test_enum test_enum.cpp)
add_executable(test_enum_v1 test_enum_v1.cpp)
add_executable(test_perfomance perfomance_enum.cpp)
add_executable(test_perfomance_v1 perfomance_enum_v1.cpp)

enable_testing()  # This line enables testing