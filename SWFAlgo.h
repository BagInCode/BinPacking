#pragma once
#include "Solver.h"
class SWFAlgo : public Solver
{
public:
	int Solve(int bin_capacity, std::vector<int>& items) override;

	std::string getName() { return "Sorted Worst Fit Algo"; };
	std::string getShortName() { return "swfalgo"; };
};

