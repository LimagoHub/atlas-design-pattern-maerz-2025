//
// Created by JoachimWagner on 15.01.2025.
//

#pragma once

#include "NodeVisitor.h"
//#include "abstract_node.h"

#include <vector>
#include <memory>

namespace composite {

    class abstract_node;

    class IteratorVisitor : public NodeVisitor {
    public:

        using Nodes = std::vector<std::shared_ptr<abstract_node>>;

        auto visit_node(abstract_node& item) -> void override;

        auto get_nodes() -> Nodes& {
            return nodes;
        }

    private:
        Nodes nodes;
    };

} // composite