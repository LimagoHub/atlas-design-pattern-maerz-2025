//
// Created by JoachimWagner on 25.12.2023.
//

#pragma once
#include <stdexcept>
#include "../TrafficLight.h"
#include "TrafficLightState.h"


namespace trafficlight::state {
class AbstractTrafficLightState : public TrafficLightState {
    private:
        trafficlight::TrafficLight *trafficLight_;
    protected:

        trafficlight::TrafficLight *getTrafficLight() const {
            return trafficLight_;
        }

public:
    explicit AbstractTrafficLightState(trafficlight::TrafficLight *trafficLight) : trafficLight_(trafficLight) {}

    ~AbstractTrafficLightState() override = default;

        std::string getColor() override{
            throw std::logic_error("Diese Funktion macht hier keinen Sinn.");
        }

        void nextColor() override {
            throw std::logic_error("Diese Funktion macht hier keinen Sinn.");
        }

        void switchOn() override {
            throw std::logic_error("Diese Funktion macht hier keinen Sinn.");
        }

        void switchOff() override {
            throw std::logic_error("Diese Funktion macht hier keinen Sinn.");
        }


};
}
