cmake_minimum_required(VERSION 3.26)
project(OOPCES)

set(CMAKE_CXX_STANDARD 20)

add_executable(OOPCES main.cpp
        LinkList.h
        Node.h
        Tantanic.cpp
        Tantanic.h
        TantanicTest.cpp
)
