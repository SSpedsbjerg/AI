#pragma once
#include <iostream>
#include <vector>
#include <string>

namespace lab2 {
    class Node {
    public:
        char state;
        Node* parent = NULL;
        int depth;
        Node* currentNode;

        Node(char state, Node* parent, int depth) {
            this->state = state; this->parent = parent; this->depth = depth;
        }

        //create a list of nodes from the root to this node
        std::vector<Node*> Path() {
            std::vector<Node*> path;
            currentNode = this;
            while (currentNode->parent != NULL) {
                currentNode = currentNode->parent;
                path.push_back(currentNode);
            }
            return path;
        }

        std::string ToString() {
            std::string returnString = "State: ";
            returnString.push_back(state);
            returnString.append(" depth: ");
            returnString.push_back(*(std::to_string(depth).c_str()));
            return returnString;
        }
    };
}

