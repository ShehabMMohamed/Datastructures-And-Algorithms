cmake_minimum_required(VERSION 3.6)
project(Datastructures)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp "Data Structures/Stacks.cpp" "Data Structures/Stacks.h" "Advanced Data Structures/AVL_Tree.cpp" "Advanced Data Structures/AVL_Tree.h" "Advanced Data Structures/SkipLists.cpp" "Advanced Data Structures/SkipLists.h" "Advanced Data Structures/RedBlackTrees.cpp" "Advanced Data Structures/RedBlackTrees.h" "Advanced Data Structures/B_Trees.cpp" "Advanced Data Structures/B_Trees.h" "Data Structures/HashTables.cpp" "Data Structures/HashTables.h")
add_executable(Datastructures ${SOURCE_FILES})