
/*

Job:
Get the all Items over the river without breaking these rules
Wolf must not be alone with the sheep
Sheep must not be alone with the cabbage

Now, a TreeSearch Algorithm seems a bit weird way of doing it
But in a sense, with a different perspective, I see the posibility

Instead of Node, I'll be using chars
A Node will have a Value, A is the Farmer, B is the Wolf, and must not be alone with C, the Sheep, Which must not be alone with D, the Cabbage
This File will thereby contain a different TreeSearch Algorithm than TreeSearch.h
*/

#pragma once
#include <iostream>
#include <string>
#include <vector>

enum Type {
	Farmer,
	Wolf,
	Sheep,
	Cabbage
};

class Node {
private:
	Type type;

public:
	Node(Type type) {
		this->type = type;
	}

	bool compare(Node* node) {
		if (this->type = Farmer) {

		}
		else if (this->type == Wolf) {
			if (node->type == Sheep) {
				return false;
			}
			else return true;
		}
		else if (this->type == Sheep) {
			if (node->type == Cabbage) {
				return false;
			}
			else return true;
		}
	}

	Type getType() {
		return type;
	}

	std::string ToString() {
		if (this->type == Type::Farmer) {
			return std::string("Farmer");
		}
		else if (this->type == Type::Wolf) {
			return std::string("Wolf");
		}
		else if (this->type == Type::Sheep) {
			return std::string("Sheep");
		}
		else if (this->type == Type::Cabbage) {
			return std::string("Cabbage");
		}
		return std::string("Couldn't figure out the type");
	}

	~Node() {
		std::cout << "DELETED" << std::endl;
	}
	
};

class Shore {
public:
	Node* animals[4] = {};
	bool startShore;
	Shore(bool startShore) {
		if (startShore) {
			animals[0] = new Node(Type::Farmer);
			animals[1] = new Node(Type::Wolf);
			animals[2] = new Node(Type::Sheep);
			animals[3] = new Node(Type::Cabbage);
		}
		this->startShore = startShore;
	}

	Node* Remove(Type type) {
		for (unsigned int i = 0; i < 4; i++) {
			if (animals[i]->getType() == type) {
				return animals[i];
			}
		}
	}

	void Add(Node* animal0, Node* animal1) {
		for (unsigned int i = 0; i < 4; i++) {
			if (animals[i] != NULL && animals[i+1] != NULL) {
				animals[i] = animal0; animals[i + 1] = animal1;
				return;
			}
		}
		std::cout << "NO SPACE" << std::endl;
	}

	void Add(Node* animal) {
		for (unsigned int i = 0; i < 4; i++) {
			if (animals[i] != NULL) {
				animals[i] = animal;
				return;
			}
		}
		std::cout << "NO SPACE" << std::endl;
	}

	//return true if the shore does not break the rule
	bool CheckShore() {
		for (unsigned int i = 0; i < 4; i++) {
			for (unsigned int j = 0; j < 4; j++) {
				if (i == j) {
					continue;
				}
				else {
					if (!animals[i]->compare(animals[j])) {
						return false;
					}
				}
			}
		}
		return true;
	}

	~Shore() {
		delete animals[0]; delete animals[1]; delete animals[2]; delete animals[3];
	}

};

class Boat {
private:
	Node* spaces [2] = { };

public:
	Boat() {

	}

	void PickUp(Type animal0, Type animal1, Shore* shore) {
		spaces[0] = shore->Remove(animal0); spaces[1] = shore->Remove(animal1);
	}

	void DropOf(Shore* shore, Type type) {
		for (unsigned int i = 0; i < 2; i++) {
			if (spaces[i]->getType() == type) {
				shore->Add(spaces[i]);
				spaces[i] = NULL;
				return;
			}
		}
		std::cout << "That animal is not on the ship" << std::endl;
	}
};

//returns a vector of chars containing the route the "AI" took
std::vector<Node*> TreeSearch() {
	Shore StartShore = Shore(true);
	Shore EndShore = Shore(false);
	Boat boat = Boat();

	
	while (true) {
		//Compare first shipment
		unsigned int i = 0;
		unsigned int j = 0;
		while (true) {
			if (StartShore.animals[i]->compare(StartShore.animals[j])) {
				
			}
		}
		


		//---
		boat.PickUp()
	}
	


}


int main() {



	return 0;
}
