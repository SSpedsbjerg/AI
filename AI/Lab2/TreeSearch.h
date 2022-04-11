#pragma once
#include "Node.h"
#include <iostream>
#include <vector>

namespace lab2 {
    //I can't read the og TREE_SEARCH in python, sooo... I'll write my own
    lab2::Node* TreeSearch(std::vector<lab2::Node*> nodes, char goalState, int indexOfStartNode) {
        
        lab2::Node* startNode = nodes[indexOfStartNode];
        std::vector<lab2::Node*> fringe;

        if (startNode->state == goalState) {
            return startNode;
        }

        //cant be sure how many children a Node might have, so I'll go through all instead of jumping out when reaching 2 children
        for (unsigned int i = 1; i < nodes.size(); i++) {
            if (nodes[i]->parent->state == startNode->state) {
                fringe.push_back(nodes[i]);
            }
        }

        unsigned int runs = 0;
        while (fringe.size() != 0) {
            std::cout << runs << std::endl;
            char fringeNodeState = fringe.back()->state;
            int fringeNodeIndex = fringe.size() - 1;
            if (fringeNodeState == goalState) {
                return fringe.back();
            }
            else {
                for (unsigned int i = 0; i < nodes.size(); i++) {
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

    /*
    So... I've completed Exercise 1 inside the TreeSearch Algorithm
    */
}






