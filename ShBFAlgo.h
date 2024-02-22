#pragma once

#include "Solver.h"

class ShBFAlgo : public Solver
{
	int shufles_count = 10;

public:
	ShBFAlgo(int _shufles_count);

	int Solve(int bin_capacity, std::vector<int>& items) override;

	std::string getName() { return "Shufled best Fit Algo (" + std::to_string(shufles_count) + " shufles)"; };
	std::string getShortName() { return "shbfalgo" + std::to_string(shufles_count); };
};

