cmake_minimum_required(VERSION 3.17)
project(Konto_Iterator)

set(CMAKE_CXX_STANDARD 17)

add_executable(Konto_Iterator main.cpp
        composite/abstract_node.h
        "composite/Konto.h"
        "composite/Kontogruppe.h"
        "composite/NodeVisitor.h"
        "composite/NodeVisitor.cpp"
        "composite/IteratorVisitor.h" "composite/IteratorVisitor.cpp" "composite/PrintVisitor.h" "composite/AddSaldoVisitor.h")
