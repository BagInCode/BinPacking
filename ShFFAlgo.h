#pragma once

#include "Solver.h"

class ShFFAlgo : public Solver
{
	int shufles_count = 10;

public:
	ShFFAlgo(int _shufles_count);

	int Solve(int bin_capacity, std::vector<int>& items) override;

	std::string getName() { return "Shufled First Fit Algo (" + std::to_string(shufles_count) + " shufles)"; };
	std::string getShortName() { return "shffalgo"+std::to_string(shufles_count); };
};

