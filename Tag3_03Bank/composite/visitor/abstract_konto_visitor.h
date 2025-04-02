//
// Created by JoachimWagner on 30.10.2024.
//

#pragma once
#include "konto_visitor.h"
#include "../konto.h"
#include "../konto_gruppe.h"
namespace composite::visitor {
    class abstract_konto_visitor: public konto_visitor {
    public:
        virtual ~abstract_konto_visitor() = default;

        void init() override {
            // NOP
        }

        void dispose() override {
            // NOP
        }

        void visit(konto &konto) override {
            // NOP
        }

        void visit(konto_gruppe &konto) override {
            // NOP
        }
    };
}
