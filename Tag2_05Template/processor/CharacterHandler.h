//
// Created by JoachimWagner on 01.04.2025.
//

#pragma once

namespace processor {

    class CharacterHandler {
    public:
        virtual ~CharacterHandler() = default;

        virtual void init() = 0;

        virtual void process(char c) = 0;

        virtual void dispose() = 0;
    };

} // process
