#include "ShBFAlgo.h"

#include <algorithm>
#include <set>

ShBFAlgo::ShBFAlgo(int _shufles_count)
{
	shufles_count = _shufles_count;
}

int ShBFAlgo::Solve(int bin_capacity, std::vector<int>& items)
{
	std::sort(items.begin(), items.end());
	std::reverse(items.begin(), items.end());

	int optimal_result = items.size();

	for (int iteration = 0; iteration < shufles_count; iteration++)
	{
		std::set<std::pair<int, int>> bins;
		std::vector<ClassicBin> result;

		for (auto item : items)
		{
			auto it = bins.lower_bound({ item, 0 });

			if (it == bins.end())
			{
				result.push_back(ClassicBin(bin_capacity));
				result.back().addItem(item);
				bins.insert({ bin_capacity - item, result.size() - 1 });
			}
			else
			{
				int position = it->second;
				bins.erase({ result[position].getCapacity(), position });
				result[position].addItem(item);
				bins.insert({ result[position].getCapacity(), position });
			}
		}

		optimal_result = std::min(optimal_result, (int)result.size());
		std::random_shuffle(items.begin(), items.end());
	}

	return optimal_result;
}
