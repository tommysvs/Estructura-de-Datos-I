#include <iostream>
#include "graph.h"

int main() {
    Graph g;

    g.addNode(0, "A");
    g.addNode(1, "B");
    g.addNode(2, "C");
    g.addNode(3, "D");
    g.addNode(4, "E");

    Graph::Node *pna = g.nodeById(0);
    Graph::Node *pnb = g.nodeById(1);
    Graph::Node *pnc = g.nodeById(2);
    Graph::Node *pnd = g.nodeById(3);
    Graph::Node *pne = g.nodeById(4);

    //Node A
    pna->addEdge(pna, 100);
    pna->addEdge(pnc, 10);
    pna->addEdge(pnd, 5);

    //Node B
    pnb->addEdge(pna, 100);
    pnb->addEdge(pnc, 20);
    pnb->addEdge(pne, 100);

    //Node C
    pnc->addEdge(pna, 10);
    pnc->addEdge(pnb, 20);
    pnc->addEdge(pne, 20);

    //Node D
    pnd->addEdge(pna, 5);
    pnd->addEdge(pne, 20);

    //Node E
    pne->addEdge(pnb, 100);
    pne->addEdge(pnc, 20);
    pne->addEdge(pnd, 20);

    g.genDotOutput();

    std::vector<long> costv;
    std::vector<long> pathv;
    g.dijsktra(0, costv, pathv);

    for(long cost : costv) {
        std::cout << "Min cost: " << cost << '\n';
    }

    for(long p : pathv) {
        if(p < 0) 
            continue;

        Graph::Node *n = g.nodeById(p);
        std::cout << "Path: " << n->label << '\n';
    }
}