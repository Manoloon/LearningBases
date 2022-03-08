cmake_minimum_required(VERSION 3.20)
project(LearningBases)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -fconcepts")
add_executable(LearningBases main.cpp Src/concepts.h Src/containers.h Src/moveSemantics.h)
