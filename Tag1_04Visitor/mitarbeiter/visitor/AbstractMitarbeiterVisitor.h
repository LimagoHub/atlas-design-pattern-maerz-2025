//
// Created by JoachimWagner on 31.03.2025.
//

#pragma once
#include "MitarbeiterVisitor.h"
namespace mitarbeiter::visitor {

    class AbstractMitarbeiterVisitor : public MitarbeiterVisitor{
    public:
        void visit(LohnEmpfaenger &lohn_empfaenger) override {
            // OK
        }

        void visit(GehaltsEmpfaenger &gehalts_empfaenger) override {
            //ok
        }
    };

} // mitarbeiter
