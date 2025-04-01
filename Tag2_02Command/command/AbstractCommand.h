//
// Created by JoachimWagner on 14.01.2025.
//

#pragma once
#include "AbstractCommand.h"

#include "../math/Calculator.h"
#include "../math/CalculatorMemento.h"
#include "Command.h"

using Calc=math::Calculator;
using CalcMementoPointer=std::shared_ptr<math::CalculatorMemento>;
namespace command {


        class AbstractCommand:public Command {
            CalcMementoPointer memento;

        public:
            AbstractCommand()=default;
            ~AbstractCommand() override = default;

            auto parse(const StringVector &tokens)->void override {
                // Ok
            }

            auto undo() -> void override {
                Calc ::getInstance()->setMemento(memento);
            }

            auto isQuery()->bool final {
                return false;
            }



            auto execute()->void final  {
                memento = Calc ::getInstance()->getMemento();
                doAction();
            }
        protected:
            virtual void doAction() = 0;

        };



} // command
