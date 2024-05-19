#pragma once
#include "Solver.h"
class ASWFAlgo : public Solver
{
public:
	int Solve(int bin_capacity, std::vector<int>& items) override;

	std::string getName() { return "Sorted Almost Worst Fit Algo"; };
	std::string getShortName() { return "sawfalgo"; };
};

