//
// Created by JoachimWagner on 29.10.2024.
//

#pragma once


#pragma once
#include "AbstractTrafficLightState.h"
namespace trafficlight::state {
    class OffState : public AbstractTrafficLightState {



    public:
        using AbstractTrafficLightState::AbstractTrafficLightState;

        void switchOn() override {
            getTrafficLight()->current = getTrafficLight()->red;
        }


    };
}