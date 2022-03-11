#pragma once
#include <Node.h>
//I can't read the og TREE_SEARCH in python, sooo... I'll write my own
Node* TreeSearch(std::vector<Node*> nodes, char goalState, int indexOfStartNode) {
    Node* startNode = nodes[indexOfStartNode];
    std::vector<Node*> fringe;

    if (startNode->state == goalState) {
        return startNode;
    }

    for (int i = 1; i < nodes.size(); i++) {
        if (nodes[i]->parent->state != startNode->state) {

        }
        if (nodes[i]->parent->state == startNode->state) {
            fringe.push_back(nodes[i]);
        }
    }

    int runs = 0;
    while (fringe.size() != 0) {
        std::cout << runs << std::endl;
        char fringeNodeState = fringe.back()->state;
        int fringeNodeIndex = fringe.size() - 1;
        if (fringeNodeState == goalState) {
            return fringe.back();
        }
        else {
            for (int i = 0; i < nodes.size(); i++) {
                if (nodes[i]->state == startNode->state) {
                    continue;
                }
                else if (nodes[i]->parent->state == fringeNodeState) {
                    fringe.push_back(nodes[i]);
                }
            }
            fringe.erase(fringe.begin() + fringeNodeIndex);
        }
    }
}