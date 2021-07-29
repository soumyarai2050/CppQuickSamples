cmake_minimum_required(VERSION 3.13)

project(CppQuickSamples)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g3 -ggdb")

add_executable(LogicalProblemSimpleFunction LogicalProblemSimpleFunction.cpp)
add_executable(LogicalProblemTemplateFunction LogicalProblemTemplateFunction.cpp)