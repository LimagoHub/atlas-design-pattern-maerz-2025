cmake_minimum_required(VERSION 3.30)
project(Tag2_05Template)

set(CMAKE_CXX_STANDARD 17)

add_executable(Tag2_05Template main.cpp
        processor/FileProcessor.h
        processor/CharacterCounter.h
        processor/CharacterHandler.h
        processor/AbstractCounter.h)
