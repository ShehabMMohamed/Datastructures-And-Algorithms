cmake_minimum_required(VERSION 3.6)
project(Datastructures)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp DS/MyStack.cpp DS/MyStack.h DS/AVL_Tree.cpp DS/AVL_Tree.h)
add_executable(Datastructures ${SOURCE_FILES})