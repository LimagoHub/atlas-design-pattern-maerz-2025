//
// Created by JoachimWagner on 31.03.2025.
//

#pragma once


#include <iostream>
#include <memory>
#include "../math/Calculator.h"

class CalcClient {

private:
    std::unique_ptr<math::Calculator> calculator_;

public:

    explicit CalcClient(std::unique_ptr<math::Calculator> calculator) : calculator_(std::move(calculator)) {}

public :
    auto  go() -> void {

        std::cout << calculator_->add(3,4) << std::endl;
    }

};
