#include <iostream>
#include <memory>
#include "composite/Node.h"
#include "composite/Leaf.h"

void travers(std::shared_ptr<AbstractNode> node){
    std::cout << *node << std::endl;
    for(auto & child : node->getChildren()){
        travers(child);
    }
}

int main() {
    auto root = std::make_shared<Node>("Root");

    auto e1 = std::make_shared<Node>("E1");
    auto e2 = std::make_shared<Node>("E2");
    auto e3 = std::make_shared<Node>("E3");


    root->append(e1);
    root->append(e2);
    root->append(e3);

    auto e3_1 =  std::make_shared<Node>("E3_1");
    auto e3_2 =  std::make_shared<Node>("E3_2");
    auto e3_3 =  std::make_shared<Node>("E3_3");

    e3->append(e3_1);
    e3->append(e3_2);
    e3->append(e3_3);

    auto e2_1 =  std::make_shared<Leaf>("E2_1");
    auto e2_2 =  std::make_shared<Leaf>("E2_2");

    e2->append(e2_1);
    e2->append(e2_2);

    travers(root);
    return 0;
}
