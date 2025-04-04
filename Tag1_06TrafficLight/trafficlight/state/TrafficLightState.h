//
// Created by JoachimWagner on 25.12.2023.
//

#pragma once
#include <string>
namespace trafficlight::state {

    class TrafficLightState {
            public:
            virtual ~TrafficLightState() = default;

            virtual std::string getColor() = 0;    // Business
            virtual void nextColor() = 0; // Statuswechsel

            virtual void switchOff() = 0;
            virtual void switchOn() = 0;

    };

}
