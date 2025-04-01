//
// Created by JoachimWagner on 14.01.2025.
//

#pragma once


#include <string>
#include <ostream>
#include "SchweineMemento.h"
#include <memory>
class Schwein {
    std::string name;
    unsigned gewicht;


    void setGewicht(unsigned int gewicht) {
        Schwein::gewicht = gewicht;
    }

    class MySchweineMemento : public SchweineMemento {
        const std::string name;
        const unsigned gewicht;

    public:
        MySchweineMemento(const std::string &name, const unsigned int gewicht) : name(name), gewicht(gewicht) {}

        const std::string &getName() const {
            return name;
        }

        const unsigned int getGewicht() const {
            return gewicht;
        }
    };


public:



    std::shared_ptr<SchweineMemento>  getMemento() const {
        return std::make_shared<MySchweineMemento>(name, gewicht);
    }

    void setMemento(std::shared_ptr<SchweineMemento> memento) {
        auto myMemento = std::dynamic_pointer_cast<MySchweineMemento>(memento);
        setName(myMemento->getName());
        setGewicht(myMemento->getGewicht());
    }
    explicit Schwein(const std::string &name = "Miss Piggy") : name{name}, gewicht{10} {}

    const std::string &getName() const {
        return name;
    }

    void setName(const std::string &name) {
        Schwein::name = name;
    }

    unsigned int getGewicht() const {
        return gewicht;
    }

    void fuettern() {
        setGewicht(getGewicht() + 1);
    }

    friend std::ostream &operator<<(std::ostream &os, const Schwein &schwein) {
        os << "name: " << schwein.name << " gewicht: " << schwein.gewicht;
        return os;
    }

    bool operator==(const Schwein &rhs) const {
        return name == rhs.name &&
               gewicht == rhs.gewicht;
    }

    bool operator!=(const Schwein &rhs) const {
        return !(rhs == *this);
    }
};
