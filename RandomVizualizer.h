#pragma once
#include <iostream>
#include <map>

#include "RandomGenerator.h"

class RandomVizualizer
{
	const int test_count = 1000000;
	int min_value;
	int max_value;

public:
	RandomVizualizer();
	~RandomVizualizer();

	void PrintGraphic(std::ostream& out, std::map<int, int>& destribution);
	void PrintTable(std::ostream& out, std::map<int, int>& destribution);
	void Vizualize(std::ostream& out, BaseRandomGenerator& _generator);
};

void vizualizeAllDistribution();

