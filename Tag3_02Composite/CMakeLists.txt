cmake_minimum_required(VERSION 3.30)
project(Tag3_02Composite)

set(CMAKE_CXX_STANDARD 17)

add_executable(Tag3_02Composite main.cpp
        composite/AbstractNode.h
        composite/Leaf.h
        composite/Node.h)
