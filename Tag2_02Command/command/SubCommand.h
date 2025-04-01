//
// Created by JoachimWagner on 29.10.2024.
//

#pragma once


#include "../math/Calculator.h"

#include "Command.h"

using Calc=math::Calculator;

namespace command {

    class SubCommand : public Command {
        double value{0};
    public:
        SubCommand()=default;
        ~SubCommand() override = default;

        auto parse(StringVector tokens)->void override {
            value = std::stod(tokens[1]);
        }

        auto undo() -> void override {
            Calc::getInstance()->add(value);
        }

        auto isQuery()->bool override {
            return false;
        }

        auto execute()->void override {
            Calc::getInstance()->sub(value);
        }
    };
}