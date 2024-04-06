cmake_minimum_required(VERSION 3.27)
project(cs260 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_INSTALL_PREFIX ${CMAKE_HOME_DIRECTORY}/bin)

add_subdirectory(assignment1)
add_subdirectory(assignment3)
add_subdirectory(assignment4)
add_subdirectory(assignment5)