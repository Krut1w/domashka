cmake_minimum_required(VERSION 3.10)
project(obuchaika)

SET(CMAKE_CXX_FLAGS "-finput-charset=utf-8 -fexec-charset=windows-1251")

set(SOURCES 
	menu.cpp
	menu_functions.cpp
	menu_items.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})