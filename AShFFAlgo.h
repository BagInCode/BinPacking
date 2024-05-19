#pragma once

#include "Solver.h"

class AShFFAlgo : public Solver
{
	int shufles_count = 10;

public:
	AShFFAlgo(int _shufles_count);

	int Solve(int bin_capacity, std::vector<int>& items) override;

	std::string getName() { return "Shufled Almost First Fit Algo (" + std::to_string(shufles_count) + " shufles)"; };
	std::string getShortName() { return "shaffalgo"+std::to_string(shufles_count); };
};

