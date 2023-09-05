#pragma once

#include "Solver.h";

class StupidSolution : public Solver
{
	int Factorial(int n);
public:
	void GenerateOrder(int order_id, std::vector<int> base_order, std::vector<int>& result);
	int Solve(int bin_capacity, std::vector<int>& items);

	std::string getName() { return "Stupid Solution"; };
	std::string getShortName() { return "stupid"; };
};

