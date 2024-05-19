#pragma once
#include "Solver.h"
class AWFAlgo : public Solver
{
public:
	int Solve(int bin_capacity, std::vector<int>& items) override;

	std::string getName() { return "Almost Worst Fit Algo"; };
	std::string getShortName() { return "awfalgo"; };

};

