#include "TestExecutor.h"

#include <chrono>

void TestExecutor::ReadFormFile(std::string input_filename, int& bin_capacity, std::vector<int>& items)
{
	std::ifstream in(input_filename);
	items.clear();

	int items_count;
	in >> bin_capacity >> items_count;

	for (int i = 0; i < items_count; i++)
	{
		int x;
		in >> x;
		items.push_back(x);
	}

	in.close();
	return;
}

void TestExecutor::WriteResults(std::string input_filename, std::ofstream& out, int result, long long time)
{
	out << input_filename << " " << result << " " << time << "\n";
	return;
}

void TestExecutor::MeasureTestExecution(Solver& solver, std::string input_filename, std::ofstream& out)
{
	int bin_capacity, result;
	std::vector < int > items;

	ReadFormFile(input_filename, bin_capacity, items);
	
	auto start = std::chrono::steady_clock::now();
	result = solver.Solve(bin_capacity, items);
	auto stop = std::chrono::steady_clock::now();
	
	WriteResults(input_filename, out, result, 
		std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count());
}

void TestExecutor::RunAllTests(Solver& solver, Strategy strategy)
{
	std::string output_filename = ".\\Output\\" + solver.getShortName() + "_output.txt";
	std::ofstream out(output_filename);

	int divisior = (strategy == Strategy::Partially ? 5 : 1);

	UniformRandomGenerator uniform_generator;
	NormalRandomGenerator normal_generator;
	ExponentialRandomGenerator exponential_to_the_min_generator;
	ExponentialRandomGenerator exponential_to_the_max_generator = ExponentialRandomGenerator(1, 1, false);

	std::cout << "\nExecuting tests for " << solver.getName() << " starts!";

	for (int block_id = 0; block_id < tests.size(); block_id++)
	{
		int tests_to_run = tests[block_id].tests_by_template;
		
		if (tests[block_id].item_count > 12)
		{
			if (strategy == Strategy::SmallOnly) continue;

			tests_to_run /= divisior;
		}

		std::cout << "\n\t" << solver.getName() << " Block #" << block_id << (divisior == 5 ? " (partially)" : "") << " started Progress : ";

		for (int subtest_id = 0; subtest_id < tests_to_run; subtest_id++)
		{
			std::string filename_uniform = GenerateTestFilename(block_id, subtest_id, uniform_generator);
			std::string filename_normal  = GenerateTestFilename(block_id, subtest_id, normal_generator);
			std::string filename_exp_min = GenerateTestFilename(block_id, subtest_id, exponential_to_the_min_generator);
			std::string filename_exp_max = GenerateTestFilename(block_id, subtest_id, exponential_to_the_max_generator);

			MeasureTestExecution(solver, filename_uniform, out);
			MeasureTestExecution(solver, filename_normal, out);
			MeasureTestExecution(solver, filename_exp_min, out);
			MeasureTestExecution(solver, filename_exp_max, out);

			std::cout << "\n\t\t" << block_id << ":" << subtest_id << " done";

			/*if (int(subtest_id * 1. / tests_to_run * 20) !=
				int((subtest_id - 1) * 1. / tests_to_run * 20))
			{
				std::cout << "#";
			}*/
		}
	}
}