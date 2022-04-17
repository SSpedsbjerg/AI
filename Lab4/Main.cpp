#pragma once
#include <iostream>
#include <lab4/Population.h>
#include <Lab4/CalculatePopulation.h>
#include <vector>

int main() {
	std::vector<Population::Person> population;

	int popSize = 50;
	int runs = 100;

	for (int i = 0; i < popSize; i++) {
		population.push_back(Population::Person());
	}

	Population::CalculatePopulation calculator = Population::CalculatePopulation(population, 0.5f, 5.0f);
	for (int i = 0; i < runs; i++) {
		calculator.Darwin();
		std::cout << calculator.ToString() << std::endl;
	}
	return 0;
}