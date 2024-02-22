#include "BFAlgo.h"

#include <set>

int BFAlgo::Solve(int bin_capacity, std::vector<int>& items)
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

	return result.size();

}
