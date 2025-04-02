//
// Created by JoachimWagner on 01.04.2025.
//

#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include "CharacterHandler.h"

namespace processor {

    class FileProcessor {
        std::vector<std::reference_wrapper<CharacterHandler>> handlers;

        void init() {
            for (auto const handler: handlers) {
                handler.get().init();
            }
        }

        void process(char c) {
            for (auto const handler: handlers) {
                handler.get().process(c);
            }
        }

        void dispose() {
            for (auto const handler: handlers) {
                handler.get().dispose();
            }
        }
    public:
        void addHandler(CharacterHandler &handler){
            handlers.push_back(std::ref(handler));
        }
        void run(std::string filename) {
            std::fstream fin(filename, std::ios::in);
            if(! fin.is_open()) {
                std::cout << "Fehler beim Oeffnen von " << filename << std::endl;
                return;
            }
            int ch;

            init();
            while( EOF != (ch = fin.get())){
                process((char) ch);
            }

            dispose();
            fin.close();
        }



    };

} // processor
