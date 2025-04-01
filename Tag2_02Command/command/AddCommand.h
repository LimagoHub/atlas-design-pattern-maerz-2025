//
// Created by JoachimWagner on 01.04.2025.
//

#pragma once
#include "Command.h"
#include "../math/Calculator.h"

namespace command {

    using Calc=math::Calculator;

    class AddCommand: public Command{

    private:
        double value;
    public:
        auto parse(StringVector tokens) -> void override {
            value = std::stod(tokens[1]);
        }

        auto execute() -> void override {
            Calc::getInstance()->add(value);
        }

        auto undo() -> void override {
            Calc::getInstance()->sub(value);
        }

        auto isQuery() -> bool override {
            return false;
        }
    };

} // command
