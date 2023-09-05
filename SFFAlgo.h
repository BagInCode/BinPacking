#pragma once

#include "Solver.h"

class SFFAlgo : public Solver
{
public:
	int Solve(int bin_capacity, std::vector<int>& items) override;

	std::string getName() { return "Sorted First Fit Algo"; };
	std::string getShortName() { return "sffalgo"; };
};

