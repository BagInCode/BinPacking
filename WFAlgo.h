#pragma once
#include "Solver.h"
class WFAlgo : public Solver
{
public:
	int Solve(int bin_capacity, std::vector<int>& items) override;

	std::string getName() { return "Worst Fit Algo"; };
	std::string getShortName() { return "wfalgo"; };

};

