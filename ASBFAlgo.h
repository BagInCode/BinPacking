#pragma once
#include "Solver.h"
class ASBFAlgo : public Solver
{
public:
	int Solve(int bin_capacity, std::vector<int>& items) override;

	std::string getName() { return "Almost Sorted Best Fit Algo"; };
	std::string getShortName() { return "sabfalgo"; };

};

