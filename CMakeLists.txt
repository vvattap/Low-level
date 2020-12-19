cmake_minimum_required(VERSION 3.17)
project(Lab5 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Lab5
        Calc.h
        ConvertProb.c
        SafeCalcProb.c)
