cmake_minimum_required (VERSION 2.6)
project (cpp11_examples)

set( CMAKE_VERBOSE_MAKEFILE on)

#message("test:","${PROJECT_SOURCE_DIR}/src/Lock/CMutex.cpp")

add_definitions(-g -Wall -Werror -std=c++11)

include_directories("${PROJECT_SOURCE_DIR}")

add_executable(01_cplusplus   01_cplusplus/main.cpp)
add_executable(02_auto        02_auto/main.cpp)
add_executable(03_range_for   03_range_for/main.cpp)
add_executable(04_right_angle_brackets   04_right_angle_brackets/main.cpp)
add_executable(07_enum_class 07_enum_class/main.cpp)
add_executable(08_constexpr 08_constexpr/main.cpp)
add_executable(simple 3th_party_examples/thread/simple.cpp)
target_link_libraries( simple pthread)

set(FILENAME call_once)
add_executable(${FILENAME} 3th_party_examples/thread/${FILENAME}.cpp)
target_link_libraries( ${FILENAME} pthread )

set(FILENAME get_id)
add_executable(${FILENAME} 3th_party_examples/thread/${FILENAME}.cpp)
target_link_libraries( ${FILENAME} pthread )


