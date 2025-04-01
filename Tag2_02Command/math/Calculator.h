//
// Created by JoachimWagner on 29.10.2024.
//

#pragma once
#include <memory>
#include <iostream>
#include "CalculatorMemento.h"

namespace math {

    class Calculator {


        class ConcreteCalculatorMemento : public CalculatorMemento {
            const double memory;
        public:
            explicit ConcreteCalculatorMemento(const double memory) : memory(memory) {}

            [[nodiscard]] auto getMemory() const ->double {
                return memory;
            }
        };
        double memory{0};

        Calculator() {}


        void setMemory(double memory) {
            Calculator::memory = memory;
        }
    public:
        [[nodiscard]] static auto getInstance()->std::shared_ptr<Calculator>  {
            static std::shared_ptr<Calculator> instance{new Calculator{}};

            return instance;
        }

        auto setMemento(const std::shared_ptr<CalculatorMemento> &calculatorMemento) -> void {
            auto memento = static_cast<ConcreteCalculatorMemento*>(calculatorMemento.get());

            Calculator::memory = memento->getMemory();
        }

        [[nodiscard]] auto getMemento()->std::shared_ptr<CalculatorMemento> {
            return std::make_shared<ConcreteCalculatorMemento>(Calculator::memory);
        }

        double getMemory() const {
            return memory;
        }

        auto print() const->void{
            std::cout << memory << std::endl;
        }
        auto clear()-> void {
            memory = 0;
        }

        auto add(double value)-> void {
            memory += value;
        }
        auto sub(double value)-> void {
            memory -= value;
        }
        auto mult(double value)-> void {
            memory *= value;
        }
        auto div(double value)-> void {
            memory /= value;
        }
    };

} // math
