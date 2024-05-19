#pragma once

#include "Solver.h"

class AShBFAlgo : public Solver
{
	int shufles_count = 10;

public:
	AShBFAlgo(int _shufles_count);

	int Solve(int bin_capacity, std::vector<int>& items) override;

	std::string getName() { return "Shufled Almost Best Fit Algo (" + std::to_string(shufles_count) + " shufles)"; };
	std::string getShortName() { return "shabfalgo" + std::to_string(shufles_count); };
};

