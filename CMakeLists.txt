cmake_minimum_required(VERSION 3.6)
project(Datastructures)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp DS/MyLinkedList.cpp DS/MyLinkedList.h DS/MyBST.cpp DS/MyBST.h sorting_algorithms.cpp DS/MyStack.cpp DS/MyStack.h DS/MyHeap.cpp DS/MyHeap.h traversing_algorithms.cpp)
add_executable(Datastructures ${SOURCE_FILES})