//
// Created by JoachimWagner on 01.04.2025.
//

#pragma once

#include <memory>
#include <iostream>
#include "Command.h"
#include <stack>
namespace command {
    using CommandPointer = std::shared_ptr<Command>;
    class CommandHistory {
        std::stack<CommandPointer> undoStack;
        std::stack<CommandPointer> redoStack;
    public:
        auto add(const CommandPointer &command)-> void {
            if(command->isQuery()) return;
            // Do action here
        }

        auto undo() -> void {
            std::cout << "Can't undo" << std::endl;
        }

        auto redo() -> void {
            std::cout << "Can't redo" << std::endl;
        }
    };

} // command
