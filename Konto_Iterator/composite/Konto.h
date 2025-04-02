//
// Created by JoachimWagner on 15.01.2025.
//

#pragma once
#include "abstract_node.h"


namespace composite {

    class Konto : public abstract_node{

        double saldo{ 0 };

    public:
        Konto(const std::string &name, double saldo = 0)
                : abstract_node(name), saldo(saldo) {
        }

        auto accept(NodeVisitor& v) -> void override {
            v.visit_konto(*this);
        }

        auto print_info(std::ostream &os) const -> void override {
            os << std::string{"Konto: "};
            os << std::string{ "name: " } << this->get_name();
            os << std::string{ ", saldo: " } << this->get_saldo();
        }

        auto get_saldo() const -> double {
            return saldo;
        }

        auto set_saldo(double saldo) -> void {
            this->saldo = saldo;
        }
    };

} // composite
