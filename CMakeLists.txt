cmake_minimum_required(VERSION 3.6)
project(Datastructures)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp "Data Structures/Stacks.h" "Data Structures/Stacks.cpp" "Advanced Data Structures/AVL_Tree.cpp" "Advanced Data Structures/AVL_Tree.h")
add_executable(Datastructures ${SOURCE_FILES})
