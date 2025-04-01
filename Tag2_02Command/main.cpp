#include <iostream>
#include "command/CommandFactory.h"

using COMMAND = std::shared_ptr<command::Command>;

int main() {
    std::string line;

    while(true) {
        std::cout << "#>";
        std::getline(std::cin, line);

        if(line == "ende") break;

        COMMAND command = command::CommandFactory::create(line);
        if(command.get() == nullptr) {
            std::cout << "Unbekannter Befehl" << std::endl;
            continue;
        }
        command->execute();
    }

    return 0;
}
