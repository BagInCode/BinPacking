#include "TestGenerator.h"

#include <iostream>
#include <fstream>


TestGenerator::TestGenerator()
{

}

TestGenerator::~TestGenerator()
{

}

void TestGenerator::GenerateTest(std::string filename, TestDescription test_description, BaseRandomGenerator& generator)
{
	int bin_capacity = test_description.bin_capacity;
	std::vector < int > items;

	for (int i = 0; i < test_description.item_count; i++)
	{
		items.push_back(generator.Generate());
	}

	if (ValidateTest(filename, test_description, bin_capacity, items))
	{
		WriteTest(filename, bin_capacity, items);
	}

	return;
}

void TestGenerator::Generate()
{
	UniformRandomGenerator uniform_generator;
	NormalRandomGenerator normal_generator;
	ExponentialRandomGenerator exponential_to_the_min_generator;
	ExponentialRandomGenerator exponential_to_the_max_generator = ExponentialRandomGenerator(1, 1, false);

	for (int block_id = 0; block_id < tests.size(); block_id++)
	{
		uniform_generator.UpdateRange(tests[block_id].item_min_weight, tests[block_id].item_max_weight);
		normal_generator.UpdateRange(tests[block_id].item_min_weight, tests[block_id].item_max_weight);
		exponential_to_the_max_generator.UpdateRange(tests[block_id].item_min_weight, tests[block_id].item_max_weight);
		exponential_to_the_min_generator.UpdateRange(tests[block_id].item_min_weight, tests[block_id].item_max_weight);

		for (int subtest_id = 0; subtest_id < tests[block_id].tests_by_template; subtest_id++)
		{
			std::string filename_uniform = GenerateTestFilename(block_id, subtest_id, uniform_generator);
			std::string filename_normal = GenerateTestFilename(block_id, subtest_id, normal_generator);
			std::string filename_exp_min = GenerateTestFilename(block_id, subtest_id, exponential_to_the_min_generator);
			std::string filename_exp_max = GenerateTestFilename(block_id, subtest_id, exponential_to_the_max_generator);

			GenerateTest(filename_uniform, tests[block_id], uniform_generator);
			GenerateTest(filename_normal, tests[block_id], normal_generator);
			GenerateTest(filename_exp_min, tests[block_id], exponential_to_the_min_generator);
			GenerateTest(filename_exp_max, tests[block_id], exponential_to_the_max_generator);
		}

		std::cout << "\t block #" << block_id << " created\n";
	}

}

bool TestGenerator::ValidateTest(std::string filename, TestDescription test_description, int bin_capacity, std::vector<int>& items)
{
	if (bin_capacity != test_description.bin_capacity)
	{
		std::cout << "Error during " << filename << " generation: incorrect bin capacity. ";
		std::cout << "Must be " << test_description.bin_capacity << ", actualy is " << bin_capacity << ".\n";
		return false;
	}

	if (items.size() != test_description.item_count)
	{
		std::cout << "Error during " << filename << " generation: incorrect item count. ";
		std::cout << "Must be " << test_description.item_count << ", actualy is " << items.size() << ".\n";
		return false;
	}

	for (int i = 0; i < items.size(); i++)
	{
		if (items[i] > bin_capacity)
		{
			std::cout << "Error during " << filename << " generation: item greather then bin. ";
			std::cout << "Item weight " << items[i] << ", bin capacity " << bin_capacity << ".\n";
			return false;
		}

		if (test_description.item_min_weight > items[i] || items[i] > test_description.item_max_weight)
		{
			std::cout << "Error during " << filename << " generation: item out of weight range. ";
			std::cout << "Item weight " << items[i] << ", range [" << test_description.item_min_weight << ", " << test_description.item_max_weight << "].\n";
			return false;
		}
	}

	return true;
}

void TestGenerator::WriteTest(std::string filename, int bin_capacity, std::vector<int>& items)
{
	std::ofstream out(filename);

	out << bin_capacity << " " << items.size() << "\n";

	for (int i = 0; i < items.size(); i++)
	{
		out << items[i] << "\n";
	}

	out.close();
	return;
}
