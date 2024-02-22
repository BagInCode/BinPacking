#pragma once
#include "Solver.h"
class SBFAlgo : public Solver
{
public:
	int Solve(int bin_capacity, std::vector<int>& items) override;

	std::string getName() { return "Sorted Best Fit Algo"; };
	std::string getShortName() { return "sbfalgo"; };

};

