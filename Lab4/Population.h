#pragma once
#include <iostream>
#include <vector>
#include <ctime>

namespace Population {
	class Person {
	private:
		int values[3];
		std::vector<Person*> children;
		std::vector<Person*> parents;
		int generation = 0;
	public:
		//used for first generation
		Person(int value0, int value1, int value2) {
			this->values[0] = value0; this->values[1] = value1; this->values[2] = value2;
		}

		Person(Person* parent0, Person* parent1) {
			//genetic inheritence
			srand(time(NULL));
			for (int i = 0; i < 3; i++) {
				int randomInt = rand() % 2;
				if (randomInt == 0) {
					values[i] = parent0->getValue()[i];
				}
				else {
					values[i] = parent1->getValue()[i];
				}
			}
			//inlcude random mutation
			for (int i = 0; i < 3; i++) {
				int randomInt = rand() % 101;
				if (randomInt <= 5) {
					if (values[i] == 1) {
						values[i] = 0;
					}
					else if (values[i] == 0) {
						values[i] = 1;
					}
				}
			}
			//add parents
			parents.push_back(parent0); parents.push_back(parent1);
			//add children to children
			parent0->addChild(this); parent1->addChild(this);
			//add generation
			generation = parent0->getGeneration();
			if (generation < parent1->getGeneration()) {
				generation = parent1->getGeneration();
			}
			generation++;
		}

		void addChild(Person* child) {
			children.push_back(child);
		}

		std::vector<int> getValue() {
			
			return {values[0], values[1], values[2]};
		}

		int getGeneration() {
			return generation;
		}
	};
}
