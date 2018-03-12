cmake_minimum_required(VERSION 3.9)
project(P3_Program)

set(CMAKE_CXX_STANDARD 14)

add_executable(P3_Program main.cpp BinarySearchTree.cpp BinarySearchTree.h dsexceptions.h AvlTree.cpp AvlTree.h SplayTree.cpp SplayTree.h RedditDataGeneration.h RedditElement.cpp RedditElement.h)