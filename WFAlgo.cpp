#include "WFAlgo.h"

#include "Heap.h"

int WFAlgo::Solve(int bin_capacity, std::vector<int>& items)
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
		}
		else
		{
			int pos = bin.first;
			result[pos].addItem(item);
			heap.eraseTop();
			heap.addBin({ pos, result[pos].getCapacity() });
		}
	}

	return result.size();

}

