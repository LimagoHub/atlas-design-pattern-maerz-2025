//
// Created by JoachimWagner on 14.01.2025.
//

#pragma once

#include <memory>
#include <iostream>
#include <stack>
#include "Command.h"

namespace command {
    using CommandPointer = std::shared_ptr<Command>;

    class CommandHistory {
        std::stack<CommandPointer> undoStack;
        std::stack<CommandPointer> redoStack;
    public:
        virtual ~CommandHistory()=default;
        CommandHistory()=default;

        auto add(const CommandPointer &c )->void{
            if(c->isQuery()) return;
            std::stack<CommandPointer>().swap(redoStack);// Loescht den RedoStack
            undoStack.push(c);
        }

        auto undo()->void {
            if(undoStack.empty()){
                std::cout << "Can't undo" << std::endl;
            }
            else {
                auto command = undoStack.top();
                undoStack.pop();
                command->undo();
                redoStack.push(command);
            }
        }

        auto redo() ->void{
            if(redoStack.empty()){
                std::cout << "Can't redo" << std::endl;
            }
            else {
                auto command = redoStack.top();
                redoStack.pop();
                command->execute();
                undoStack.push(command);
            }
        }



    };

} // command
