//
// Created by JoachimWagner on 14.01.2025.
//

#pragma once

#include <regex>
#include "Command.h"
#include "AddCommand.h"
#include "PrintCommand.h"
#include "ClearCommand.h"
#include "../../../atlas-design-pattern-maerz-2025/Tag2_02Command/command/SubCommand.h"
#include <memory>

namespace command {
    using COMMAND = std::shared_ptr<command::Command>;
    class CommandFactory {
    public:
        static COMMAND create(std::string line) {
            COMMAND result;
            const StringVector tokens =tokenizeLine(line);

            if(tokens[0] == "Add"){
                result = std::make_shared<AddCommand>();
                result->parse(tokens);
            }
            if(tokens[0] == "Print"){
                result = std::make_shared<PrintCommand>();
                result->parse(tokens);
            }
            if(tokens[0] == "Clear"){
                result = std::make_shared<ClearCommand>();
                result->parse(tokens);
            }
            if(tokens[0] == "Sub"){
                result = std::make_shared<SubCommand>();
                result->parse(tokens);
            }
            return result;
        }

    private:
        static StringVector tokenizeLine(const std::string &line) {
            auto const regex = std::regex{R"(\s+)"};
            auto const result = StringVector(
                    std::sregex_token_iterator{std::begin(line), std::end(line), regex, -1},
                    std::sregex_token_iterator{}
            );
            return result;
        }
    };

} // command
