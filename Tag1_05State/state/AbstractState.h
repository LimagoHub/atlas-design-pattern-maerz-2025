//
// Created by JoachimWagner on 31.03.2025.
//

#pragma once
#include <stdexcept>
#include "State.h"
#include "../FrontController.h"

class AbstractState: public State{

    FrontController * frontController;

public:
    explicit AbstractState(FrontController *frontController) : frontController(frontController) {}

    void drucken() override {
        throw std::logic_error("Diese Funktion macht hier keinen Sinn.");
    }

    void changeToA() override {
        throw std::logic_error("Diese Funktion macht hier keinen Sinn.");
    }

    void changeToB() override {
        throw std::logic_error("Diese Funktion macht hier keinen Sinn.");
    }

protected:
    FrontController *getFrontController() const {
        return frontController;
    }
};
