cmake_minimum_required(VERSION 3.2...3.27.5)

project(long_numbers)

enable_testing()
add_subdirectory(lib/googletest)

set(LIBRARY "long_numbers")

add_library(${LIBRARY} "")

add_subdirectory(src)
add_subdirectory(tests)