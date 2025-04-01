//
// Created by JoachimWagner on 14.01.2025.
//

#pragma once
#include "AbstractCommand.h"

#include "../math/Calculator.h"
#include "../math/CalculatorMemento.h"

using Calc=math::Calculator;

namespace command {

    class AddCommand:public AbstractCommand {
        double value{0};
    public:
        AddCommand()=default;
        ~AddCommand() override = default;

        auto parse(const StringVector &tokens)->void override {
            value = std::stod(tokens[1]);
        }

        void doAction() override {
            Calc::getInstance()->add(value);
        }


    };

} // command
