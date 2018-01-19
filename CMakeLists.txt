cmake_minimum_required(VERSION 3.6)
project(DS_Second_Project)

set(CMAKE_CXX_STANDARD 14)

add_executable(main main.cpp adjMatrix.h adjList.h constantsCalculation.h quickSort.h InsertionSort.h bubbleSort.h mergeSort.h optimumBubble.h constantsClass.h cmake-build-debug/DFS.h)

add_executable(testt test.cpp)