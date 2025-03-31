//
// Created by JoachimWagner on 31.03.2025.
//

#pragma once
#include <vector>
#include "../mitarbeiter/AbstractMitarbeiter.h"
using MITARBEITER=mitarbeiter::AbstractMitarbeiter;
#include "../mitarbeiter/visitor/MitarbeiterVisitor.h"

using VISITOR=mitarbeiter::visitor::MitarbeiterVisitor;

namespace firma {

    class Firma {
    private:
        std::vector<std::reference_wrapper<MITARBEITER>> mitarbeiters;
    public:
        void add_mitarbeiter(MITARBEITER &mitarbeiter) {
            mitarbeiters.push_back(std::ref(mitarbeiter));
        }

        void remove_mitarbeiter(MITARBEITER &mitarbeiter) {
            // TODO Implement later
        }


        void print () const {
            for(auto & item: mitarbeiters) {
                std::cout << item.get() << std::endl;
            }
        }

        void iterate(VISITOR &visitor) {
            for(auto & item: mitarbeiters) {
                //visitor.visit(item.get());
                item.get().accept(visitor);
            }
        }
    };

} // firma
