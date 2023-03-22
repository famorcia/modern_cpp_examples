cmake_minimum_required (VERSION 3.0)
project (cpp_examples)

set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wextra -Wall -Werror")

add_subdirectory(c++11)
add_subdirectory(c++14)
add_subdirectory(c++17)
add_subdirectory(c++20)
add_subdirectory(corso)

