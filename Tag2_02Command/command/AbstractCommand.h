//
// Created by JoachimWagner on 01.04.2025.
//

#pragma once
#include "Command.h"
#include <stdexcept>
namespace command {

    class AbstractCommand : public Command{
    public:
        auto parse(StringVector tokens) -> void override {
            // ok
        }

        auto undo() -> void override {
            throw std::logic_error{"Upps"};
        }

        auto isQuery() -> bool override {
            return true;
        }
    };

} // command
