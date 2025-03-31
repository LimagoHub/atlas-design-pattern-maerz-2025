cmake_minimum_required(VERSION 3.30)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled main.cpp
        math/CalculatorImpl.h
        client/CalcClient.h
        math/CalculatorLogger.h
        math/CalculatorFactory.h
)
