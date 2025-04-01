#include <iostream>
#include "tiere/Schwein.h"
class Metzger {
public:
    void schlachten(tiere::Tier * schwein) {
        std::cout << "messer wetz " << std::endl;
    }
};

template<class T>
class Spediteuer {
public:
    void fahren (T *ware) {
        std::cout << "Wir fahren auf der Autobahn" << std::endl;
    }
};

int main() {
    Metzger metzger;
    Spediteuer<tiere::Schwein> spediteuer;
    tiere::Schwein piggy{"Miss Piggy"};

    // Register PropChanged
    piggy.addPropertyChangedEventListener([](const PropertyChangedEvent<tiere::Schwein> &event){
        std::cout << event << std::endl;
    });

    piggy.addPigTooFatListener([&metzger](tiere::Schwein *s){metzger.schlachten(s);});
    piggy.addPigTooFatListener([&spediteuer](tiere::Schwein *s){spediteuer.fahren(s);});

    for (int i = 0; i < 11; ++i) {
        piggy.fuettern();
    }
    return 0;
}
