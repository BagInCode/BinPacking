#pragma once
#include "Solver.h"
class ABFAlgo : public Solver
{
public:
	int Solve(int bin_capacity, std::vector<int>& items) override;

	std::string getName() { return "Almost Best Fit Algo"; };
	std::string getShortName() { return "abfalgo"; };

};

