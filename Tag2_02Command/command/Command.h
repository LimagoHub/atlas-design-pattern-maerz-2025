//
// Created by JoachimWagner on 01.04.2025.
//

#pragma once
#include <vector>
#include <string>

namespace command {
    using StringVector=std::vector<std::string>;
    class Command {
    public:
        virtual ~Command()= default;
        virtual auto parse(StringVector tokens)->void = 0;
        virtual auto execute() -> void = 0;
        virtual auto undo()->void = 0;
        virtual auto isQuery()->bool = 0;
    };

} // command
