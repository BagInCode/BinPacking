#include "ASBFAlgo.h"

#include <set>

int ASBFAlgo::Solve(int bin_capacity, std::vector<int>& items)
{
	std::sort(items.begin(), items.end());
	std::reverse(items.begin(), items.end());

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
			continue;
		}

		int position = it->second;
		bins.erase({ result[position].getCapacity(), position });

		auto it2 = bins.lower_bound({ item, 0 });

		if (it2 == bins.end())
		{
			result[position].addItem(item);
			bins.insert({ result[position].getCapacity(), position });
		}
		else
		{
			int position2 = it2->second;
			bins.erase({ result[position2].getCapacity(), position2 });
			result[position2].addItem(item);
			bins.insert({ result[position2].getCapacity(), position2 });
			bins.insert({ result[position].getCapacity(), position });
		}
	}

	return result.size();
}
