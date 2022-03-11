#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <Lab2\Node.h>
#include <Lab2\TreeSearch.h>

int main() {
    std::vector<Node*> nodes = {
        new Node('A', NULL, 0)
    };
    nodes.insert(nodes.end(), {
        new Node('B', nodes[0], 1),
        new Node('C', nodes[0], 1)
        });
    nodes.insert(nodes.end(), {
        new Node('D', nodes[1], 2),
        new Node('E', nodes[1], 2),
        new Node('F', nodes[2], 2),
        new Node('G', nodes[2], 2)
        });
    nodes.insert(nodes.end(), {
        new Node('H', nodes[3], 3),
        new Node('I', nodes[3], 3),
        new Node('J', nodes[4], 3),
        new Node('K', nodes[4], 3),
        new Node('L', nodes[5], 3),
        new Node('N', nodes[5], 3),
        new Node('M', nodes[6], 3),
        new Node('O', nodes[6], 3)
        });

    char goalState = 'L';
    std::cout << TreeSearch(nodes, goalState, 0)->ToString() << std::endl;
    //PLZ let this be enough
    for (int i = 0; i < nodes.size(); i++) {
        delete nodes[i];
    }
    return 0;
}