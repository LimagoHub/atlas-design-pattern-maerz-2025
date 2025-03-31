#include <iostream>
#include <chrono>
#include "math/CalculatorFactory.h"

#include "client/CalcClient.h"

int main() {

    auto start_ = std::chrono::high_resolution_clock::now();
    // ....
    auto end_ = std::chrono::high_resolution_clock::now();

    std::cout << "Duration: " << std::chrono::duration_cast<std::chrono::milliseconds>(end_-start_).count() << std::endl;

    math::CalculatorFactory::setLogger(true);
    math::CalculatorFactory::setSecure(true);
    auto calculator = math::CalculatorFactory::create();


    CalcClient client{std::move(calculator)};
    client.go();

    return 0;
}

