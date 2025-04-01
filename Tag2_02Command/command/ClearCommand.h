//
// Created by JoachimWagner on 01.04.2025.
//

#pragma once
#include "AbstractCommand.h"
#include "../math/Calculator.h"

using Calc=math::Calculator;

namespace command {

    class ClearCommand: public AbstractCommand {
    private:
        double oldValue;
    public:
        auto undo() -> void override {
            Calc::getInstance()->setMemory(oldValue);
        }

        auto isQuery() -> bool override {
            return false;
        }

        auto execute() -> void override {
            oldValue = Calc::getInstance()->getMemory();
            Calc::getInstance()->clear();
        }
    };

} // command
