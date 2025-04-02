//
// Created by JoachimWagner on 01.04.2025.
//

#pragma once
#include "CharacterHandler.h"
namespace processor {

    class LineCounter: public CharacterHandler{
        size_t counter;
    public:
        void init() override {
            counter = 0;
        }

        void process(char c) override {
            if(c == '\n')
                counter ++;
        }

        void dispose() override {
           std::cout << counter << std::endl;
        }
    };

} // processor
