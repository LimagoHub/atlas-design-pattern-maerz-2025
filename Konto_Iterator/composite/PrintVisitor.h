//
// Created by JoachimWagner on 15.01.2025.
//

#pragma once

#include "NodeVisitor.h"
#include "abstract_node.h"

namespace composite {

    class PrintVisitor : public NodeVisitor {
    public:

        auto visit_node(abstract_node& item) -> void override {
            //std::cout << "Print Visitor:  ";
            item.print_info(std::cout);
            std::cout << std::endl;
        }
    };

} // composite