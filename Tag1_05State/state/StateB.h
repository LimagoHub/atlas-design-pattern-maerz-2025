//
// Created by JoachimWagner on 31.03.2025.
//

#pragma once

#include <iostream>
#include "AbstractState.h"

class StateB: public AbstractState{
public:

    explicit StateB(FrontController *frontController) : AbstractState(frontController) {}

    void drucken() override {
        std::cout << "Hier druckt B" << std::endl;
    }

    void changeToA() override {
        getFrontController()->current = getFrontController()->stateA;
    }
};
