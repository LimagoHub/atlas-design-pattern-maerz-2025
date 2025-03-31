//
// Created by JoachimWagner on 31.03.2025.
//

#pragma once
#include <vector>
#include <memory>

class AttributedCharacter {

    static inline std::vector< std::shared_ptr<AttributedCharacter> > characters;

    const char c;
    const bool bold;

    AttributedCharacter(const char c, const bool bold) : c(c), bold(bold) {}

public:
    AttributedCharacter(const AttributedCharacter& other) = delete;
    void operator = (const AttributedCharacter& other) = delete;
    AttributedCharacter(AttributedCharacter&& other) = delete;
    void operator = (AttributedCharacter&& other) = delete;

    virtual ~AttributedCharacter() = default;

    static std::shared_ptr<AttributedCharacter>  get_instance(const char c, const bool bold){
        for(auto ac: characters)
        {
            if (ac->c == c && ac->bold == bold) return ac;

        }
        std::shared_ptr<AttributedCharacter> result = std::shared_ptr<AttributedCharacter>(new AttributedCharacter{c,bold});
        characters.push_back(result);
        return result;
    }

    const char getC() const {
        return c;
    }

    const bool getBold() const {
        return bold;
    }

};
