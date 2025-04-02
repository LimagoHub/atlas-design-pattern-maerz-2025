//
// Created by JoachimWagner on 01.04.2025.
//

#pragma once
#include "AbstractCounter.h"
namespace processor {

    class CharacterCounter: public AbstractCounter{

        void process(char c) override {
            incrementCounter();
        }


    };

} // processor
