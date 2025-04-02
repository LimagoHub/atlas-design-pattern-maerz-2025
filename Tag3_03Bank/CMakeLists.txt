cmake_minimum_required(VERSION 3.28)
project(Tag3_03Bank)

set(CMAKE_CXX_STANDARD 17)

add_executable(Tag3_03Bank main.cpp
        composite/visitor/konto_visitor.h
        composite/visitor/abstract_konto_visitor.h
        composite/visitor/PrintVisitor.h
        composite/visitor/konto_gruppen_visitor.h
        composite/Iterator.h)
