//
// Created by JoachimWagner on 01.04.2025.
//

#pragma once
#include "AbstractCommand.h"
#include "../math/Calculator.h"

namespace command {
    using Calc=math::Calculator;
    class PrintCommand: public AbstractCommand{
    public:
        auto execute() -> void override {
            Calc::getInstance()->print();
        }
    };

} // command
