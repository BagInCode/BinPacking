#pragma once

#include <string>
#include <vector>

#include "RandomGenerator.h"
#include "TestsDescription.h"

class TestGenerator
{

	void GenerateTest(std::string filename, TestDescription test_description, BaseRandomGenerator& generator);

	bool ValidateTest(std::string filename, TestDescription test_description, int bin_capacity, std::vector<int>& items);
	void WriteTest(std::string filename, int bin_capacity, std::vector<int>& items);

public:

	TestGenerator();
	~TestGenerator();
	void Generate();
};

