cmake_minimum_required(VERSION 3.6)
project(Datastructures)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp MyLinkedList.cpp MyLinkedList.h BST.cpp BST.h sorting_algorithms.cpp)
add_executable(Datastructures ${SOURCE_FILES})