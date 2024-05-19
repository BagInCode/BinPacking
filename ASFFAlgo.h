#pragma once

#include "Solver.h"

class ASFFAlgo : public Solver
{
public:
	int Solve(int bin_capacity, std::vector<int>& items) override;

	std::string getName() { return "Almost Sorted First Fit Algo"; };
	std::string getShortName() { return "saffalgo"; };
};

