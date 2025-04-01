cmake_minimum_required(VERSION 3.30)
project(Tag2_01Observer)

set(CMAKE_CXX_STANDARD 17)

add_executable(Tag2_01Observer main.cpp
        tiere/Schwein.h
        propertchange/PropertyChangedEvent.h)
