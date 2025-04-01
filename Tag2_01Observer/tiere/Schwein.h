//
// Created by JoachimWagner on 01.04.2025.
//

#pragma once

#include <string>
#include <ostream>
#include <functional>
#include <vector>
namespace tiere {


    class Tier {};


    class Schwein: public Tier {

        std::vector<std::function<void(Schwein*)>> listeners;

        std::string name;
        int gewicht;

        void setGewicht(int gewicht) {
            Schwein::gewicht = gewicht;
            if(gewicht>20) firePigTooFatEvent();

            // Fire PropChanged
        }

        void firePigTooFatEvent(){
            for (const auto & listener:listeners) {
                listener(this);
            }
        }

    public:
        explicit Schwein(const std::string &name="Nobody") : name(name), gewicht(10) {}

        void addPigTooFatListener(const std::function<void(Schwein*)> &listener) {
            listeners.emplace_back(listener);
        }

        const std::string &getName() const {
            return name;
        }

        void setName(const std::string &name) {
            Schwein::name = name;
            // Fire PropChanged
        }

        int getGewicht() const {
            return gewicht;
        }

        void fuettern() {
            setGewicht(getGewicht() + 1);
        }



        friend std::ostream &operator<<(std::ostream &os, const Schwein &schwein) {
            os <<  " name: " << schwein.name << " gewicht: " << schwein.gewicht;
            return os;
        }
    };

} // tiere
