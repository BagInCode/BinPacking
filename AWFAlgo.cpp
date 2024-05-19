#include "AWFAlgo.h"

#include "Heap.h"

int AWFAlgo::Solve(int bin_capacity, std::vector<int>& items)
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

	return result.size();

}

