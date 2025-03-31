cmake_minimum_required(VERSION 3.30)
project(Tag1_06TrafficLight)

set(CMAKE_CXX_STANDARD 17)

add_executable(Tag1_06TrafficLight
        main.cpp trafficlight/state/TrafficLightState.h trafficlight/state/AbstractTrafficLightState.h trafficlight/TrafficLight.cpp)
