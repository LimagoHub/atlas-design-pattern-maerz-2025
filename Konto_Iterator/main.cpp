#include <iostream>
#include "composite/abstract_node.h"
#include "composite/Kontogruppe.h"
#include "composite/Konto.h"

#include "composite/IteratorVisitor.h"
#include "composite/PrintVisitor.h"
#include "composite/AddSaldoVisitor.h"

using Kontogruppe = composite::Kontogruppe;
using Konto = composite::Konto;
using node_shared_ptr = composite::abstract_node::AbstractNodeShared;
using PrintVisitor = composite::PrintVisitor;

void travers(std::shared_ptr<composite::abstract_node> myNode) {
    std::cout << *myNode << std::endl;
    for(auto & child : myNode->get_children()){
        travers(child);
    }
}
int main() {
    auto root =std::make_shared<Kontogruppe>("root #0");

    auto e1 = std::make_shared<Kontogruppe>("e1 #1");
    auto e2 = std::make_shared<Kontogruppe>("e2 #2");
    auto e3 = std::make_shared<Kontogruppe>("e3 #5");

    auto e3_1 = std::make_shared<Kontogruppe>("e3_1 #6");
    auto e3_2 = std::make_shared<Kontogruppe>("e3_2 #7");
    auto e3_3 = std::make_shared<Kontogruppe>("e3_3 #8");

    auto e2_1 = std::make_shared<Konto>("e2_1 #3", 10);
    auto e2_2 = std::make_shared<Konto>("e2_2 #4", 100);

    root->append(e1);
    root->append(e2);
    root->append(e3);

    e3->append(e3_1);
    e3->append(e3_2);
    e3->append(e3_3);

    e2->append(e2_1);
    e2->append(e2_2);

    //travers(root);
    //root->print();

    PrintVisitor print_visitor;
    std::cout << std::endl << std::string(80, '=') << " print visitor" << std::endl;
    root->iterate(print_visitor);

    std::vector<std::pair<node_shared_ptr, std::string>> nodes{
        {root, "root #0..#8"},
        {e1, "e1 #1"},
        {e2, "e2 #2..#4"},
        {e3, "e3 #5..#8"},
        {e2_1, "e2_1 #3"},
        {e2_2, "e2_2 #4"}
    };
    for (auto& item : nodes)
    {
        std::cout << std::endl << std::string(80, '=') << " run iterator \"" << item.second << '"' << std::endl;
        for (auto& item : *item.first)
        {
            std::cout << item << std::endl;
        }
    }

    return 0;
}

