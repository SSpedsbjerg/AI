#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Node.h"
/*
namespace lab3 {
    class Map;
}

class lab3::Map {
public:
    std::vector<lab3::Node*> nodes;

    Map() {
        nodes.insert(nodes.end(), {
            new lab3::Node(std::string("A")),//0
            new lab3::Node(std::string("B")),//1 
            new lab3::Node(std::string("C")),//2
            new lab3::Node(std::string("D")),//3
            new lab3::Node(std::string("E")),//4
            new lab3::Node(std::string("F")),//5
            new lab3::Node(std::string("G")),//6
            new lab3::Node(std::string("H")),//7
            new lab3::Node(std::string("I")),//8
            new lab3::Node(std::string("J")),//9
            new lab3::Node(std::string("K")),//10
            new lab3::Node(std::string("L"))//11
            });

        nodes[0]->AddDistanceToTarget(6.0f);
        nodes[0]->AddAdjacentNode(nodes[1], 1.0f);//A->B
        nodes[0]->AddAdjacentNode(nodes[2], 2.0f);//A->C
        nodes[0]->AddAdjacentNode(nodes[3], 4.0f);//A->D
        nodes[1]->AddDistanceToTarget(5.0f);
        nodes[1]->AddAdjacentNode(nodes[5], 5.0f);//B->F
        nodes[1]->AddAdjacentNode(nodes[4], 4.0f);//B->E
        nodes[2]->AddDistanceToTarget(5.0f);
        nodes[2]->AddAdjacentNode(nodes[4], 1.0f);//C->E
        nodes[3]->AddDistanceToTarget(2.0f);
        nodes[3]->AddAdjacentNode(nodes[7], 1.0f);//D->H
        nodes[3]->AddAdjacentNode(nodes[8], 4.0f);//D->I
        nodes[3]->AddAdjacentNode(nodes[9], 2.0f);//D->J
        nodes[4]->AddDistanceToTarget(4.0f);
        nodes[4]->AddAdjacentNode(nodes[6], 2.0f);//E->G
        nodes[4]->AddAdjacentNode(nodes[7], 3.0f);//E->H
        nodes[5]->AddDistanceToTarget(5.0f);
        nodes[5]->AddAdjacentNode(nodes[6], 1.0f);//F->G
        nodes[6]->AddDistanceToTarget(4.0f);
        nodes[6]->AddAdjacentNode(nodes[10], 6.0f);//G->K
        nodes[7]->AddDistanceToTarget(1.0f);
        nodes[7]->AddAdjacentNode(nodes[10], 6.0f);//H->K
        nodes[7]->AddAdjacentNode(nodes[11], 5.0f);//H->I
        nodes[8]->AddDistanceToTarget(2.0f);
        nodes[8]->AddAdjacentNode(nodes[11], 3.0f);//I->L
        nodes[9]->AddDistanceToTarget(1.0f);
        nodes[10]->AddDistanceToTarget(0.0f);
        nodes[11]->AddDistanceToTarget(0.0f);

    }

    Map(std::vector<std::string> stateNames) {
        for (int i = 0; i < stateNames.size(); i++) {
            nodes.push_back(new lab3::Node(std::string(stateNames[i])));
        }
    }

    ~Map() {
        for (int i = 0; i < nodes.size(); i++) {
            delete nodes[i];
        }
    }
};*/