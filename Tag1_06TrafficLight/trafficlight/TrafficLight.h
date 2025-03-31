//
// Created by JoachimWagner on 28.10.2024.
//

#pragma once

#include <string>
#include <memory>



namespace trafficlight::state {
    class GreenState;
    class RedState;
    class OffState;
    class AbstractTrafficLightColorState;
    class TrafficLightState;

}
namespace trafficlight {
    using TRAFFIC_LIGHT_STATE =  std::shared_ptr<trafficlight::state::TrafficLightState>;
    class TrafficLight {
    private:
        const TRAFFIC_LIGHT_STATE red;
        const TRAFFIC_LIGHT_STATE green;
        const TRAFFIC_LIGHT_STATE off;

        TRAFFIC_LIGHT_STATE current;
    public:
        TrafficLight();

        std::string getColor();
        void nextColor();
        void switchOff();
        void switchOn();


        friend class trafficlight::state::RedState;
        friend class trafficlight::state::GreenState;
        friend class trafficlight::state::OffState;
        friend class trafficlight::state::AbstractTrafficLightColorState;

    };

} // trafficlight
