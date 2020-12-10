#ifndef _GRAPH_H
#define _GRAPH_H

#include <iostream>
#include <vector>

class Graph {
    public:
        class Node;

        class Edge {
            public:
                Edge(const Node *node, int weight) : node(node), weight(weight) {}

                const Node *node;
                int weight;
        };

        class Node {
            public:
                Node(long id, const std::string& lbl) : id(id), label(lbl) {}

                void addEdge(const Node *node, int weight) {
                    edges.emplace_back(node, weight);
                }

                std::vector<Edge> edges;
                std::string label;
                long id;
        };

        Graph() {}

        void addNode(long id, const std::string& lbl) {
            nodes.emplace_back(id, lbl);
        }

        void dijsktra(long src_id, std::vector<long>& costv, std::vector<long>& pathv);

        Node *nodeById(long node_id);
        void genDotOutput() const;
        void print() const;

        std::vector<Node> nodes;
};

#endif