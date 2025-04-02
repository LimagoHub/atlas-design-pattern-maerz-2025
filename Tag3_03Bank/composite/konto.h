//
// Created by JoachimWagner on 30.10.2024.
//

#pragma once

#include <ostream>
#include "abstract_bank_node.h"

namespace composite {

    class konto : public abstract_bank_node { // Konto
        double saldo_;
    public:
        konto(const std::string &name, double saldo = 0)
                : abstract_bank_node(name), saldo_{saldo} {
        }

        auto print(std::ostream &os) const -> void override {
            os << std::string{"Konto: "};

            abstract_bank_node::print(os);
            os << ", Saldo = " << saldo_;
        }

        void accept(VISITOR &visitor) override {
            visitor.visit(*this);
        }

        friend std::ostream &operator<<(std::ostream &os, const konto &konto) {
            os << static_cast<const abstract_bank_node &>(konto);
            konto.print(os);
            return os;
        }

        double getSaldo() const {
            return saldo_;
        }

        void setSaldo(double saldo) {
            saldo_ = saldo;
        }
    };

}
