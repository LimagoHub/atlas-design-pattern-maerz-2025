//
// Created by JoachimWagner on 31.03.2025.
//

#pragma once

#include "Calculator.h"

namespace math {

    class CalculatorImpl : public Calculator {



    public:
        auto add(double a, double b) -> double override {
            return a + b;
        }

        auto sub(double a, double b) -> double override {
            return a - b;
        }


    };

} // math
