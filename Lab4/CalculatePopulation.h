#pragma once
#include <iostream>
#include <Lab4/Population.h>
#include <tuple>
#include <algorithm>
#include <string>

namespace Population {
	class CalculatePopulation {
	private:
		float survivePercent; //from 0-1
		float extraSurviveChange;
		std::vector<Population::Person> population;
		std::vector<std::tuple<Population::Person, int>> points; //corresponds to population

		//maybe sorts in wrong direction
		bool compare(std::tuple<Population::Person, int> person0, std::tuple<Population::Person, int> person1) {
			if (std::get<1>(person0) > std::get<1>(person1)) {
				return true;
			}
			else {
				return false;
			}
		}

		void CalculateValues() {
			points.clear();
			int point;
			//calculate values
			for (int i = 0; i < population.size(); i++) {
				for (int j = 0; j < population[i].getValue().size(); j++) {
					point = population[i].getValue()[j] * j;
				}
				points.push_back({ population[i], point });
			}
			std::sort(points.begin(), points.end(), compare);
		}

	public:
		CalculatePopulation(std::vector<Population::Person> population) {
			this->population = population;
			extraSurviveChange = 5.0f;
			survivePercent = 0.5f;
			CalculateValues();
		}

		CalculatePopulation(std::vector<Population::Person> population, float survivePercent, float extraSurviveChange) {
			this->population = population;
			this->survivePercent = survivePercent;
			this->extraSurviveChange = extraSurviveChange;
			CalculateValues();
		}

		std::vector<Population::Person> getPopulation() {
			return this->population;
		}

		std::string ToString() {
			std::string stringValue;
			for (int i = 0; i < population.size(); i++) {
				stringValue += std::string("Person : ")
					+ std::to_string(i)
					+ std::string(" Values: ")
					+ std::to_string(population[i].getValue()[0])
					+ std::to_string(population[i].getValue()[1])
					+ std::to_string(population[i].getValue()[2])
					+ std::string("Generation: ")
					+ std::to_string(population[i].getGeneration())
					+ std::string("\n");
			}
			return stringValue;
		}

		std::vector<Population::Person> Darwin() {
			float survivePos = survivePercent * points.size();
			std::vector<Population::Person> survivors;
			std::vector<Population::Person> nonSurvivors;
			std::vector<Population::Person> newPeople;
			for (int i = 0; i < points.size(); i++) {
				if (points.size() < survivePos) {
					survivors.push_back(population[i]);
				}
				else {
					nonSurvivors.push_back(population[i]);
				}
			}
			for (int i = 0; i < nonSurvivors.size(); i++) {
				if (rand() % 101 < extraSurviveChange) {
					survivors.push_back(nonSurvivors[i]);
				}
			}
			for (int i = 0; i < survivors.size(); i + 2) {
				if (survivors.size() < i) {
					break;
				}
				newPeople.push_back(Population::Person(&survivors[i], &survivors[i + 1]));
			}
			CalculateValues();
		}
	};
}
