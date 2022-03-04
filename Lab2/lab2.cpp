#pragma once
#include <iostream>
#include <string>
#include <vector>

/*
class Node : # Node has only PARENT_NODE, STATE, DEPTH
    def __init__(self, state, parent = None, depth = 0) :
    self.STATE = state
    self.PARENT_NODE = parent
    self.DEPTH = depth

    def path(self) : # Create a list of nodes from the root to this node.
    current_node = self
    path = [self]
    while current_node.PARENT_NODE:  # while current node has parent
        current_node = current_node.PARENT_NODE  # make parent the current node
        path.append(current_node)   # add current node to path
        return path

        def display(self) :
        print(self)

        def __repr__(self) :
        return 'State: ' + str(self.STATE) + ' - Depth: ' + str(self.DEPTH)
*/



class Node {


public:

    char state;
    
    Node* parent = NULL;

    int depth;
    Node* currentNode;

    Node(char state, Node* parent, int depth) {
        this->state = state; this->parent = parent; this->depth = depth;
    }
    ~Node() {
        delete this;
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
        std::string returnString = "State: " + state;
        returnString += " Depth: ";
        returnString += depth;
        return returnString;
    }
};

//I can't read the og TREE_SEARCH in python, sooo... I'll write my own
Node TreeSearch(std::vector<Node> nodes, char goalState, int indexOfStartNode) {
    Node startNode = nodes[indexOfStartNode];
    std::vector<Node> fringe;

    if (startNode.state == goalState) {
        return startNode;
    }

    for (int i = 0; i < nodes.size(); i++) {
        if (nodes[i].parent->state == startNode.state) {
            fringe.push_back(nodes[i]);
        }
    }

    int runs = 0;
    while (fringe.size() != 0) {
        std::cout << runs << std::endl;
        char fringeNodeState = fringe.back().state;
        int fringeNodeIndex = fringe.size() - 1;
        if (fringeNodeState == goalState) {
            return fringe.back();
        }
        else {
            for (int i = 0; i < nodes.size(); i++) {
                if (nodes[i].parent->state == fringeNodeState) {
                    fringe.push_back(nodes[i]);
                }
            }
            fringe.erase(fringe.begin() + fringeNodeIndex);
        }
    }



}

int main() {
    std::vector<Node> nodes = {
    Node('A', NULL, 0) //Startnode
    };
    nodes.insert(nodes.end(), {
        Node('B', &nodes[0], 1),
        Node('C', &nodes[0], 1) });
    nodes.insert(nodes.end(), {
        Node('D', &nodes[1], 2),
        Node('E', &nodes[1], 2),
        Node('F', &nodes[2], 2),
        Node('G', &nodes[2], 2)
        });
    nodes.insert(nodes.end(), {
        Node('H', &nodes[3], 3),
        Node('I', &nodes[3], 3),
        Node('J', &nodes[4], 3),
        Node('K', &nodes[4], 3),
        Node('L', &nodes[5], 3),
        Node('N', &nodes[5], 3),
        Node('M', &nodes[6], 3),
        Node('O', &nodes[6], 3)
        });

    char goalState = 'L';
    std::cout << TreeSearch(nodes, goalState, 0).ToString() << std::endl;
    
}