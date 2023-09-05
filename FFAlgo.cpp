#include "FFAlgo.h"

#include "SegmentTree.h"

int FFAlgo::Solve(int bin_capacity, std::vector<int>& items)
{
	SegmentTree segmentTree = SegmentTree(items.size(), bin_capacity);
	std::vector<ClassicBin> result;

	for (auto item: items)
	{
		int position = segmentTree.GetPositionFor(item);
		segmentTree.UpdatePoint(position, -item);

		if (position == result.size())
		{
			result.push_back(ClassicBin(bin_capacity));
		}

		result[position].addItem(item);
	}

	return result.size();
}
