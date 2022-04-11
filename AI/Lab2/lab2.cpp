#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "C:\Users\simon\Documents\GitHub\AI\AI\Lab2\Node.h"
#include "C:\Users\simon\Documents\GitHub\AI\AI\Lab2\TreeSearch.h"

/*
int main() {
    std::vector<lab2::Node*> nodes = {
        new lab2::Node('A', NULL, 0)
    };
    nodes.insert(nodes.end(), {
        new lab2::Node('B', nodes[0], 1),
        new lab2::Node('C', nodes[0], 1)
        });
    nodes.insert(nodes.end(), {
        new lab2::Node('D', nodes[1], 2),
        new lab2::Node('E', nodes[1], 2),
        new lab2::Node('F', nodes[2], 2),
        new lab2::Node('G', nodes[2], 2)
        });
    nodes.insert(nodes.end(), {
        new lab2::Node('H', nodes[3], 3),
        new lab2::Node('I', nodes[3], 3),
        new lab2::Node('J', nodes[4], 3),
        new lab2::Node('K', nodes[4], 3),
        new lab2::Node('L', nodes[5], 3),
        new lab2::Node('N', nodes[5], 3),
        new lab2::Node('M', nodes[6], 3),
        new lab2::Node('O', nodes[6], 3)
        });

    char goalState = 'L';
    std::cout << lab2::TreeSearch(nodes, goalState, 0)->ToString() << std::endl;
    //PLZ let this be enough
    for (int i = 0; i < nodes.size(); i++) {
        delete nodes[i];
    }
    return 0;
}
*/