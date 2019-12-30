cmake_minimum_required(VERSION 3.13)
project(mivne)

set(CMAKE_CXX_STANDARD 98)

add_executable(mivne main.cpp Graph_Node.cpp Rooted_Tree.h Dynamic_Graph.h
        Graph_Edge.cpp Graph_Edge.h Dynamic_Graph.cpp Rooted_Tree.cpp)