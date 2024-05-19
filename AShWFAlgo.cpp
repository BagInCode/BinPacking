#include "AShWFAlgo.h"

#include "Heap.h"

AShWFAlgo::AShWFAlgo(int _shufles_count)
{
	shufles_count = _shufles_count;
}

int AShWFAlgo::Solve(int bin_capacity, std::vector<int>& items)
{
	std::sort(items.begin(), items.end());
	std::reverse(items.begin(), items.end());
	
	int optimal_result = items.size();

	for (int iteration = 0; iteration < shufles_count; iteration++)
	{
		Heap heap;
		std::vector<ClassicBin> result;

		for (auto item : items)
		{
			auto bin = heap.getTop();

			if (bin.second < item)
			{
				result.push_back(ClassicBin(bin_capacity));
				result.back().addItem(item);
				heap.addBin({ result.size() - 1, bin_capacity - item });
				continue;
			}

			heap.eraseTop();
			auto bin2 = heap.getTop();

			if (bin2.second < item)
			{
				int pos = bin.first;
				result[pos].addItem(item);
				heap.addBin({ pos, result[pos].getCapacity() });
			}
			else
			{
				int pos = bin2.first;
				result[pos].addItem(item);
				heap.eraseTop();
				heap.addBin({ pos, result[pos].getCapacity() });
				heap.addBin(bin);
			}
		}

		optimal_result = std::min(optimal_result, (int)result.size());
		std::random_shuffle(items.begin(), items.end());
	}

	return optimal_result;
}

