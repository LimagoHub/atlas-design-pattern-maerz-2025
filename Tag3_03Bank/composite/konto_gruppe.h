//
// Created by JoachimWagner on 30.10.2024.
//

#pragma once

#include "abstract_bank_node.h"
#include <algorithm>
namespace composite {
    class konto_gruppe : public abstract_bank_node  { // Kontogruppe
    public:

        explicit konto_gruppe(const std::string &name) : abstract_bank_node(name) {}

        void print(std::ostream &os) const override {
            os << "Kontogruppe: ";
            abstract_bank_node::print(os);
        }

        auto get_children() const -> Children override {
            return children;
        }

        void append(AbstractNodeShared child) {
            children.push_back(child);
            // https://stackoverflow.com/questions/11711034/stdshared-ptr-of-this
            child->set_parent(shared_from_this());
        }

        void remove(AbstractNodeShared child) {
            const auto position = std::find(children.begin(), children.end(), child);
            if (position != children.end())
                children.erase(position);
        }

        friend std::ostream &operator<<(std::ostream &os, const konto_gruppe &node) {
            node.print(os);
            return os;
        }
        void accept(VISITOR &visitor) override {
            visitor.visit(*this);
        }

    private:
        Children children;
    };
}