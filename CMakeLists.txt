cmake_minimum_required(VERSION 3.13)

project(CppQuickSamples)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wextra -g3 -ggdb")

add_executable(Function Function.cpp)
add_executable(NonCopyableClass NonCopyableClass.cpp)
add_executable(DefaultMethodsClass DefaultMethodsClass.cpp)
add_executable(TemplateFunction TemplateFunction.cpp)
add_executable(Test1 Test1.cpp)
add_executable(MoveWithVectorFun Experiments/MoveWithVectorFun.cpp)
add_executable(MoveWithMapFun Experiments/MoveWithMapFun.cpp)
add_executable(StringStream Experiments/StringStream.cpp)
add_executable(StructuredBinding Experiments/StructuredBinding.cpp)

