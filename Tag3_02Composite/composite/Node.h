//
// Created by JoachimWagner on 02.04.2025.
//

#pragma once
#include "AbstractNode.h"
// KontoGruppe
class Node : public AbstractNode{

public:
    using AbstractNode::AbstractNode;

    void print(std::ostream &os) const override {
        os << std::string{"Node: "};
        AbstractNode::print(os);
    }

    auto getChildren() const -> const Children & override {
        return children;
    }

    auto append(AbstractNodeShared child)-> void {

        // Pruefungen
        child->setParent(weak_from_this());
        children.push_back(child);
    }

private:
    Children children;
};
