#pragma once

#include "Solver.h";

class AFFAlgo : public Solver
{
public:
	int Solve(int bin_capacity, std::vector<int>& items) override;

	std::string getName() { return "Almost First Fit Algo"; };
	std::string getShortName() { return "affalgo"; };
};

