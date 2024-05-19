#include "ASFFAlgo.h"

#include <algorithm>

#include "SegmentTree.h"

int ASFFAlgo::Solve(int bin_capacity, std::vector<int>& items)
{
	std::sort(items.begin(), items.end());
	std::reverse(items.begin(), items.end());

	SegmentTree segmentTree = SegmentTree(items.size(), bin_capacity);
	std::vector<ClassicBin> result;

	for (auto item : items)
	{
		int position = segmentTree.GetPositionFor(item);

		if (position == result.size())
		{
			segmentTree.UpdatePoint(position, -item);
			result.push_back(ClassicBin(bin_capacity));
			result[position].addItem(item);
			continue;
		}

		segmentTree.UpdatePoint(position, -result[position].getCapacity());

		int position2 = segmentTree.GetPositionFor(item);

		if (position2 == result.size())
		{
			result[position].addItem(item);
			segmentTree.UpdatePoint(position, result[position].getCapacity());
		}
		else
		{
			result[position2].addItem(item);
			segmentTree.UpdatePoint(position2, -item);
			segmentTree.UpdatePoint(position, result[position].getCapacity());
		}
	}

	return result.size();
}
