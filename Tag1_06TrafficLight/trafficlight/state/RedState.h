//
// Created by JoachimWagner on 25.12.2023.
//

#pragma once
#include "AbstractTrafficLightColorState.h"
namespace trafficlight::state {
    class RedState : public AbstractTrafficLightColorState {



    public:
        using AbstractTrafficLightColorState::AbstractTrafficLightColorState;

        std::string getColor() {
            return "RED";
        }

        void nextColor() {
            getTrafficLight()->current = getTrafficLight()->green;
        }


    };
}
