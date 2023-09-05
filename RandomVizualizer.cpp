#include "RandomVizualizer.h"

#include <map>
#include <vector>
#include <iomanip>
#include <string>

RandomVizualizer::RandomVizualizer()
{

}

RandomVizualizer::~RandomVizualizer()
{

}

void RandomVizualizer::PrintGraphic(std::ostream& out, std::map<int, int>& destribution)
{
	int number_length = std::max(int(log10(abs(max_value))) + 1 + (max_value < 0 ? 1 : 0),
								 int(log10(abs(min_value))) + 1 + (min_value < 0 ? 1 : 0));

	out << "\n Graphic:\n";

	for (int i = min_value; i <= max_value; i++)
	{
		out << std::setw(number_length) << i << ": " << std::string(destribution[i] / ((test_count / 10) / (max_value - min_value + 1)), '*') << "\n";
	}

	return;
}

void RandomVizualizer::PrintTable(std::ostream& out, std::map<int, int>& destribution)
{
	int number_length = std::max(int(log10(abs(max_value))) + 1 + (max_value < 0 ? 1 : 0),
					             int(log10(abs(min_value))) + 1 + (min_value < 0 ? 1 : 0));

	for (int i = min_value; i <= max_value; i++)
	{
		number_length = std::max(number_length, int(log10(destribution[i])) + 1);
	}

	out << "\n Table:\n";

	for (int i = min_value; i <= max_value; i++)
	{
		out << " | " << std::setw(number_length) << i;
	} out << " |\n";

	out << " " << std::string((number_length + 3) * (max_value - min_value + 1) + 1, '-') << "\n";

	for (int i = min_value; i <= max_value; i++)
	{
		out << " | " << std::setw(number_length) << destribution[i];
	} out << " |\n";

	return;
}

void RandomVizualizer::Vizualize(std::ostream& out, BaseRandomGenerator& generator)
{
	min_value = generator.getRange().first;
	max_value = generator.getRange().second;

	std::map<int, int> result_distribution;

	for (int i = 0; i < test_count; i++)
	{
		result_distribution[generator.Generate()]++;
	}

	out << "\n\n" << generator.getName() << " result:\n";

	PrintTable(out, result_distribution);
	PrintGraphic(out, result_distribution);

	return;
}

void vizualizeAllDistribution()
{
	UniformRandomGenerator uniform = UniformRandomGenerator(0, 10);
	NormalRandomGenerator normal = NormalRandomGenerator(0, 10);
	ExponentialRandomGenerator exp_to_the_min = ExponentialRandomGenerator(0, 10, true);
	ExponentialRandomGenerator exp_to_the_max = ExponentialRandomGenerator(0, 10, false);

	RandomVizualizer vizualizer = RandomVizualizer();

	vizualizer.Vizualize(std::cout, uniform);
	vizualizer.Vizualize(std::cout, normal);
	vizualizer.Vizualize(std::cout, exp_to_the_min);
	vizualizer.Vizualize(std::cout, exp_to_the_max);

	return;
}
