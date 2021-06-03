cmake_minimum_required(VERSION 3.17)
project(Lab2_vector)

set(CMAKE_CXX_STANDARD 14)

add_executable(Lab2_vector Array/DynArray.h Array/DynArray.cpp main.cpp List/LinkedList.cpp List/LinkedList.h List/ListSeq.cpp List/ListSeq.h Sequence.cpp Sequence.h Array/ArrSeq.cpp Array/ArrSeq.h Library.cpp Library.h)