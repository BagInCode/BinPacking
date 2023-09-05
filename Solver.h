#pragma once

#include <string>
#include <vector>

#include "ClassicBin.h"
#include "ClassicItem.h"
#include "TestsDescription.h"

class Solver
{
public:
	virtual int Solve(int bin_capacity, std::vector<int>& items) { return 0; };

	virtual std::string getName() { return "Base Solver"; };
	virtual std::string getShortName() { return "solver"; };
};

