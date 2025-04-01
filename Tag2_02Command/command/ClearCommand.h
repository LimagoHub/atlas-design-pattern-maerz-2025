//
// Created by JoachimWagner on 29.10.2024.
//

#pragma once
#include "../math/Calculator.h"

#include "AbstractQuery.h"

using Calc=math::Calculator;

namespace command {

    class ClearCommand : public AbstractCommand {

    public:
        ClearCommand()=default;
        ~ClearCommand() override = default;


        void doAction() override {
            Calc ::getInstance()->clear();
        }


    };
}