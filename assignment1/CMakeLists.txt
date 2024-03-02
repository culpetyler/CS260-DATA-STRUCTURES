cmake_minimum_required(VERSION 3.27)
project(assignment1)

add_executable(${PROJECT_NAME} source/main.cpp source/marblebag.cpp)

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX})