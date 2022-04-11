#include <iostream>
#include <vector>
#include <string>
/*
namespace lab3 {
    class Distance;
    class Node;
}

//used for keeping track of the distance between nodes

struct Distance {
public:
    float length;
    Node* nodeA;
    Node* nodeB;

    Distance(float length, Node* A, Node* B) {
        this->length = length;
        nodeA = A;
        nodeB = B;
    }
};

class Node {
public:
    std::string state;
    std::vector<Node*> adjacentNodes;
    std::vector<Distance> distances;
    float distanceToTarget;

    Node(std::string state) {
        this->state = state;
    }

    float getDistance(Node* node0) {
        for (int i = 0; i < distances.size(); i++) {
            if (distances[i].nodeA == node0 && distances[i].nodeB == this ||
                distances[i].nodeA == this && distances[i].nodeB == node0
                ) {
                return distances[i].length;
            }
        }
    }

    Node* AddDistanceToTarget(float distanceToTarget) {
        this->distanceToTarget = distanceToTarget;
        return this;
    }

    //create a reference from this node to another, and the other way around aswell
    void AddAdjacentNode(Node* node, float distanceToNode) {
        //check if the node is already added
        for (int i = 0; i < adjacentNodes.size(); i++) {
            if (adjacentNodes[i] == node) {
                return;
            }
        }
        //add node
        adjacentNodes.push_back(node);
        distances.push_back(Distance(distanceToNode, this, node));

        //check if this node is added on the referenced node adjacent nodes
        for (int i = 0; i < node->adjacentNodes.size(); i++) {
            if (node->adjacentNodes[i] == this) {
                return;
            }
        }
        node->adjacentNodes.push_back(this);
        node->distances.push_back(Distance(distanceToNode, this, node));
    }

    std::string ToString() {
        std::string returnString = "State: ";
        returnString.append(state);
        return returnString;
    }
};*/