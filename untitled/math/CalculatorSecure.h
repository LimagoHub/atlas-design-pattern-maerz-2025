//
// Created by JoachimWagner on 31.03.2025.
//

#pragma once

#include <memory>
#include <iostream>
#include "Calculator.h"

namespace math {

    class CalculatorSecure: public Calculator {
    private:
        std::unique_ptr<Calculator> calculator_;


    public:
        explicit CalculatorSecure(std::unique_ptr<Calculator> calculator) : calculator_(std::move(calculator)) {}

        auto add(double a, double b) -> double override {
            std::cout << "Du kommst hier rein" << std::endl;
            return calculator_->add(a,b);
        }

        auto sub(double a, double b) -> double override {
            return calculator_->sub(a, b);
        }
    };

} // math
