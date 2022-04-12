#pragma once
#include <iostream>
#include <Lab4/Population.h>
#include <tuple>
#include <algorithm>

namespace Population {
	class CalculatePopulation {
	private:
		float survivePercent;
		float extraSurviveChange;
		std::vector<Population::Person> population;
		std::vector<std::tuple<Population::Person, int>> points; //corresponds to population

		bool compare(std::tuple<Population::Person, int> person0, std::tuple<Population::Person, int> person1) {
			if (std::get<1>(person0) > std::get<1>(person1)) {
				return true;
			}
			else {
				return false;
			}
		}

	public:
		CalculatePopulation(std::vector<Population::Person> population) {
			this->population = population;

			//calculate values
			for (int i = 0; i < population.size(); i++) {
				int point;
				for (int j = 0; j < population[i].getValue().size(); j++) {
					point = population[i].getValue()[j] * j;
				}
				points.push_back({population[i], point});
			}
			std::sort(points.begin(), points.end(), compare);
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
		}

	};
}
