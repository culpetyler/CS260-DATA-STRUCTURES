cmake_minimum_required(VERSION 3.27)
project(assignment5)

add_executable(${PROJECT_NAME} source/main.cpp)

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX})