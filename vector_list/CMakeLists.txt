cmake_minimum_required(VERSION 3.2...3.27.5)

project(containers)

enable_testing()
add_subdirectory(lib/googletest)

set(CONTAINERS_LIB "containers_lib")
add_library(${CONTAINERS_LIB} "")

add_subdirectory(src)
add_subdirectory(test)