//
// Created by JoachimWagner on 14.01.2025.
//

#pragma once
#include "AbstractQuery.h"
namespace command {

    class PrintCommand :public AbstractQuery{
    public:
        auto execute() -> void override {
            Calc::getInstance()->print();
        }
    };

} // command
