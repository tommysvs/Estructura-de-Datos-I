#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <limits>
#include "graph.h"

Graph::Node *Graph::nodeById(long node_id) {
    auto it = std::find_if(nodes.begin(), nodes.end(), [node_id](const Node& n) {
        return n.id == node_id;
    });

    return (it != nodes.end())? &(*it) : nullptr;
}

void Graph::dijsktra(long src_id, std::vector<long>& costv, std::vector<long>& pathv) {
    std::unordered_set<long> vertex_set;

    costv.resize(nodes.size());
    pathv.resize(nodes.size());
    for(const auto& n : nodes) {
        costv[n.id] = std::numeric_limits<int>::max();
        pathv[n.id] = -1;
        vertex_set.insert(n.id);
    }
    costv[src_id] = 0;

    while(!vertex_set.empty()) {
        auto it = vertex_set.begin();
        long min_id = *it;
        it++;
        
        while(it != vertex_set.end()) {
            long node_id = *it ++;

            if(costv[min_id] > costv[node_id])
                min_id = node_id;
        }

        vertex_set.erase(min_id);
        Node *u = nodeById(min_id);

        for(const auto& edge : u->edges) {
            const Node *v = edge.node;
            int alt = costv[u->id] + edge.weight;
            if(alt < costv[v->id]) {
                costv[v->id] = alt;
                pathv[v->id] = u->id;
            }
        }
    }
}

void Graph::print() const {
    for(const auto& n : nodes) {
        std::cout << n.label << '\n';

        for(const auto& t : n.edges) {
            std::cout << t.node->label << ", " << t.weight << '\n';
        }
    }
}

void Graph::genDotOutput() const {
    std::cout << "graph {\n";
    for(const auto& n : nodes) {
        for(const auto& t : n.edges) {
            std::cout << "    " << n.label << " -- " << t.node->label << " [ label=\"" << t.weight << "\"" << ", weight=\"" << t.weight << "\" ];\n";
        }
    }

    std::cout << "}\n";
}