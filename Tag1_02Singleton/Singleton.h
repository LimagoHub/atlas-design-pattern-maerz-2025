//
// Created by JoachimWagner on 13.01.2025.
//

#pragma once


#include <iostream>

class Singleton {
    Singleton() = default;

public:
    Singleton(Singleton const&)               = delete;
    auto operator=(Singleton const&)->void    = delete;

    Singleton(Singleton &&)               = delete;
    auto operator=(Singleton &&)->void    = delete;

    static auto create ()-> Singleton& {
        static Singleton instance ; // Lazy + Threadsafe
        return instance;
    }
    auto log(std::string message)->void{
        std::cout << message << std::endl;
    }
};
