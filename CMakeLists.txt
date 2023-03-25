cmake_minimum_required(VERSION 3.21)
project(TEB1013_FinalProject_Q1)

set(CMAKE_CXX_STANDARD 17)

if (WIN32)
    set(CMAKE_EXE_LINKER_FLAGS "-static")
endif (WIN32)

add_executable(TEB1013_FinalProject_Q1 main.cpp common.cpp common.h question1.cpp question1.h common.inl)
