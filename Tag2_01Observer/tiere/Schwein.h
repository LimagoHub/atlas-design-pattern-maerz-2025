//
// Created by JoachimWagner on 14.01.2025.
//

#pragma once


#include <string>
#include <ostream>
#include <functional>
#include "../propertchange/PropertyChangedEvent.h"

namespace tiere {
    class Tier {
    };

    class Schwein : public Tier {  // Observable


        inline static const unsigned MAX_WEIGHT{20};
        std::vector<std::function<void(Schwein *)>> listeners;
        std::vector<std::function<void(const PropertyChangedEvent<Schwein> &event)>> propertyChangedEventListeners;

        std::string name;
        int gewicht;

        inline void setGewicht(int gewicht) {
            if(Schwein::gewicht == gewicht) return;
            PropertyChangedEvent<Schwein> event{this, "gewicht", Schwein::gewicht, gewicht};
            Schwein::gewicht = gewicht;
            if (gewicht > MAX_WEIGHT) firePigTooFatEvent();
            firePropertyChangedEvent(event);
        }

        void firePigTooFatEvent() {
            for (const auto &listener: listeners) {
                listener(this);
            }
        }

        void firePropertyChangedEvent(const PropertyChangedEvent<Schwein> &event) {
            for (const auto &listener: propertyChangedEventListeners) {
                listener(event);
            }
        }

    public:
        explicit Schwein(const std::string &name) : name(name), gewicht(10) {}


        void addPigTooFatListener(const std::function<void(Schwein *)> &listener) {
            listeners.emplace_back(listener);
        }


        void addPropertyChangedEventListener(const std::function<void(const PropertyChangedEvent<Schwein>)> &listener) {
            propertyChangedEventListeners.emplace_back(listener);
        }


        const std::string &getName() const {
            return name;
        }

        void setName(const std::string &name) {
            PropertyChangedEvent<Schwein> event{this, "name", Schwein::name, name};

            Schwein::name = name;
            firePropertyChangedEvent(event);
        }

        int getGewicht() const {
            return gewicht;
        }

        void fuettern() {
            setGewicht(getGewicht() + 1);
        }

        bool operator==(const Schwein &rhs) const {
            return name == rhs.name &&
                   gewicht == rhs.gewicht;
        }

        bool operator!=(const Schwein &rhs) const {
            return !(rhs == *this);
        }

        friend std::ostream &operator<<(std::ostream &os, const Schwein &schwein) {
            os << "name: " << schwein.name << " gewicht: " << schwein.gewicht;
            return os;
        }

    };
}
