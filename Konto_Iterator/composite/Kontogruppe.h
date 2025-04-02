//
// Created by JoachimWagner on 15.01.2025.
//

#pragma once
#include "abstract_node.h"
#include <ostream>
namespace composite {

    class Kontogruppe : public abstract_node{
    public:

        explicit Kontogruppe(const std::string &name) : abstract_node(name) {}

        void print_info(std::ostream &os) const override {
            os << "Kontogruppe: ";
            os << std::string{ "name: " } << this->get_name();
        }

        auto get_children() const -> const  Children& override {
            return children;
        }

        void append(AbstractNodeShared child) {
            children.push_back(child);
            child->set_parent(shared_from_this());
        }

        auto accept(NodeVisitor& v) -> void override {
            v.visit_kontogruppe(*this);
        }

    private:
        Children children;
    };

} // composite
