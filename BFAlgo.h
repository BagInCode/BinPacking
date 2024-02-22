#pragma once
#include "Solver.h"
class BFAlgo : public Solver
{
public:
	int Solve(int bin_capacity, std::vector<int>& items) override;

	std::string getName() { return "Best Fit Algo"; };
	std::string getShortName() { return "bfalgo"; };

};

