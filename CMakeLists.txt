cmake_minimum_required(VERSION 4.2)
project(MathSolver)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(MathSolverLib
        src/include_src/details/BigInt.cpp
        src/include_src/details/BigFixed.cpp
        src/include_src/details/RealNumber.cpp)
target_include_directories(MathSolverLib PUBLIC includes)

add_executable(AppTest
        src/test.cpp)
target_link_libraries(AppTest PUBLIC MathSolverLib)

add_executable(MathSolver
        src/main.cpp)
target_link_libraries(MathSolver PUBLIC MathSolverLib)
