//
// Created by JoachimWagner on 02.04.2025.
//

#pragma once
#include "AbstractNode.h"

class Leaf:public AbstractNode {

public:
    using AbstractNode::AbstractNode;

    void print(std::ostream &os) const override {
        os << std::string{"Leaf: "};
        AbstractNode::print(os);
    }
};
