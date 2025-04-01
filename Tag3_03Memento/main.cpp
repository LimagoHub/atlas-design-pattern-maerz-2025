#include <iostream>
#include "tiere/Schwein.h"
int main() {
    Schwein piggy{"Miss Piggy"};
    std::cout << piggy << "\n";

    auto memento = piggy.getMemento();
    piggy.fuettern();
    std::cout << piggy << "\n";

    piggy.setMemento(memento);
    std::cout << piggy << "\n";
    return 0;
}
