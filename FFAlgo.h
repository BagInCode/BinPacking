#pragma once

#include "Solver.h";

class FFAlgo : public Solver
{
public:
	int Solve(int bin_capacity, std::vector<int>& items) override;

	std::string getName() { return "First Fit Algo"; };
	std::string getShortName() { return "ffalgo"; };
};

