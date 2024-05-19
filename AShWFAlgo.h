#pragma once
#include "Solver.h"
class AShWFAlgo : public Solver
{
	int shufles_count = 10;

public:
	AShWFAlgo(int _shufles_count);

	int Solve(int bin_capacity, std::vector<int>& items) override;

	std::string getName() { return "Shufled Almost Worst Fit Algo (" + std::to_string(shufles_count) + " shufles)"; };
	std::string getShortName() { return "shawfalgo" + std::to_string(shufles_count); };
};

