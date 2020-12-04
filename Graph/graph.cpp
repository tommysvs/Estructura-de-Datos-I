#include <iostream>
#include "graph.h"

void Graph::print() const {
    for(const auto& n : nodes) {
        std::cout << n.label << '\n';

        for(const auto& t : n.trans) {
            std::cout << t.node->label << ", " << t.weight << '\n';
        }
    }
}