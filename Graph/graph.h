#ifndef _GRAPH_H
#define _GRAPH_H

#include <iostream>
#include <vector>

class Graph {
    public:
        class Node;

        class Trans {
            public:
                Trans(const Node *node, int weight) : node(node), weight(weight) {}

                const Node *node;
                int weight;
        };

        class Node {
            public:
                Node(const std::string& lbl) : label(lbl) {}

                void addTrans(const Node *node, int weight) {
                    trans.emplace_back(node, weight);
                }

                std::vector<Trans> trans;
                std::string label;
        };

        Graph() {}

        void print() const;

        std::vector<Node> nodes;
};

#endif