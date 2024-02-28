cmake_minimum_required(VERSION 3.27)
project(assignment1)

add_executable(assignment1 source/main.cpp source/marblebag.cpp)
target_compile_features(assignment1 PUBLIC cxx_std_17)