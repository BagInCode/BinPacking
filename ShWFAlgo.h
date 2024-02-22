#pragma once
#include "Solver.h"
class ShWFAlgo : public Solver
{
	int shufles_count = 10;

public:
	ShWFAlgo(int _shufles_count);

	int Solve(int bin_capacity, std::vector<int>& items) override;

	std::string getName() { return "Shufled Worst Fit Algo (" + std::to_string(shufles_count) + " shufles)"; };
	std::string getShortName() { return "shwfalgo" + std::to_string(shufles_count); };
};

