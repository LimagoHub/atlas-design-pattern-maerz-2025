//
// Created by JoachimWagner on 01.04.2025.
//

#pragma once
#include <string>
#include <variant>
#include <ostream>

template<class T>
class PropertyChangedEvent {
    const T *source; // Sender
    const std::string propertyName;
    const std::variant<std::string, int > oldValue;
    const std::variant<std::string, int > newValue;

public:
    PropertyChangedEvent(const T *source,
                         std::string propertyName,
                         std::variant<std::string,  int> oldValue,
                         std::variant<std::string, int> newValue) :

            source(source), propertyName(propertyName), oldValue(oldValue), newValue(newValue) {}

    const T *getSource() const {
        return source;
    }

    const std::string &getPropertyName() const {
        return propertyName;
    }

    const std::variant<std::string, int> &getOldValue() const {
        return oldValue;
    }

    const std::variant<std::string, int> &getNewValue() const {
        return newValue;
    }

    friend std::ostream &operator<<(std::ostream &os, const PropertyChangedEvent<T> &event) {
        os << "source: " << *(event.source) << " propertyName: " << event.propertyName;
        if(std::holds_alternative<int>(event.oldValue)) {
            os << " oldValue: " << std::get<int>(event.oldValue) <<
               " newValue: "  << std::get<int>(event.newValue);
        } else {
            os << " oldValue: " << std::get<std::string>(event.oldValue) <<
               " newValue: "  << std::get<std::string>(event.newValue);
        }


        return os;
    }

};
