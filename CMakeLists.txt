cmake_minimum_required(VERSION 3.6)
project(csce310)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    homework01/program1/csce310hw001pt01.cpp
    homework01/program1/csce310hw001pt01.h
    homework01/program1/test01.cpp
    homework01/program2/csce310hw001pt02.cpp
    homework01/program2/csce310hw001pt02.h
    homework01/program2/test02.cpp)

add_executable(csce310 ${SOURCE_FILES})


set(HOMEWORK01PROGRAM1SOURCEFILES
        homework01/program1/csce310hw001pt01.cpp
        homework01/program1/csce310hw001pt01.h)

add_executable(csce310homework01program1 ${HOMEWORK01PROGRAM1SOURCEFILES})