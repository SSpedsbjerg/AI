#pragma once
#include <iostream>
#include "Map.h"
#include <vector>
#include <string>
#include "Node.h"
#include <algorithm>
#include "Map.h"

/*

namespace lab3 {
    class AStar;
}

class AStar {
private:
    std::vector<lab3::Node*> PriorityQueue;
    lab3::Map map;
    lab3::Node* startNode;
    lab3::Node* currentNode;
    std::vector<lab3::Node*> usedNodes;

    bool compareNode(lab3::Node N1, lab3::Node N2) {
        float distanceToN1 = N1.getDistance(currentNode) + N1.distanceToTarget;
        float distanceToN2 = N2.getDistance(currentNode) + N2.distanceToTarget;
        return (distanceToN1 < distanceToN2);
    }

    //TODO: tror ikke den søger efter Nodens position
    void SortPriorityQueue() {
        std::sort(PriorityQueue.begin(), PriorityQueue.begin() + PriorityQueue.size(), compareNode);
    }

public:
    AStar(lab3::Map map, std::string startPoint) {
        this->map = map;
        for (int i = 0; i < map.nodes.size(); i++) {
            if (map.nodes[i]->state == startPoint) {
                startNode = map.nodes[i];
                currentNode = startNode;
            }
        }
    }

    void Start() {
        while (currentNode->distanceToTarget != 0.0f) {
            SortPriorityQueue();
            std::cout << "Current Node: " + currentNode->ToString() << std::endl;
            currentNode = PriorityQueue[0];
        }
    }

};

*/