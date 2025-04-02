//
// Created by JoachimWagner on 02.04.2025.
//

#pragma once
#include "AbstractNode.h"


// Konto
class Leaf:public AbstractNode {
private:
    double saldo{0};
public:
    using AbstractNode::AbstractNode;

    void print(std::ostream &os) const override {
        os << std::string{"Leaf: "};
        AbstractNode::print(os);
    }
};
