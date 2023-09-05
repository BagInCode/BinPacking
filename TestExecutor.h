#pragma once

#include "TestsDescription.h"
#include "Solver.h"
#include "RandomGenerator.h"

class TestExecutor
{
	void ReadFormFile(std::string input_filename, int& bin_capacity, std::vector<int>& items);
	void WriteResults(std::string input_filename, std::ofstream& out, int result, long long time);

	void MeasureTestExecution(Solver& solver, std::string input_filename, std::ofstream& out);
public:
	enum Strategy
	{
		SmallOnly,
		Partially,
		Full
	};

	void RunAllTests(Solver& solver, Strategy strategy);

};

