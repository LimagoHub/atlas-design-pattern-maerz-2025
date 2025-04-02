//
// Created by JoachimWagner on 15.01.2025.
//

#pragma once

#include "NodeVisitor.h"
#include "abstract_node.h"

namespace composite {

    class AddSaldoVisitor : public NodeVisitor {
    public:

        AddSaldoVisitor(double val = 0) : add_value(val) {}

        auto set_value(double val) -> void {
            add_value = val;
        }

        auto visit_konto(Konto& item) -> void override {
            item.set_saldo(item.get_saldo() + add_value);
        }
    private:
        double add_value{ 0 };
    };

} // composite