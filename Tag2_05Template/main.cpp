#include <iostream>
#include "processor/FileProcessor.h"
#include "processor/CharacterCounter.h"
#include "processor/LineCounter.h"
using Processor = processor::FileProcessor;
int main() {

    auto cc = processor::CharacterCounter{};
    auto lc = processor::LineCounter{};

    Processor fileProcessor;
    fileProcessor.addHandler(cc);
    fileProcessor.addHandler(lc);
    fileProcessor.run("..\\data\\blind.txt");
    return 0;
}
