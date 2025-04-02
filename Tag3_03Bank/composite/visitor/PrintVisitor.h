//
// Created by JoachimWagner on 30.10.2024.
//

#pragma once

#include <iostream>
#include "abstract_konto_visitor.h"

namespace composite::visitor {

    class PrintVisitor: public abstract_konto_visitor{
    public:
        ~PrintVisitor() override = default;

        void visit(konto &konto) override {
            std::cout << konto << std::endl;
        }

        void visit(konto_gruppe &konto_gruppe) override {
            std::cout << konto_gruppe << std::endl;
        }
    };

}
