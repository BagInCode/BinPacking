#include "SFFAlgo.h"

#include <algorithm>

#include "SegmentTree.h"

int SFFAlgo::Solve(int bin_capacity, std::vector<int>& items)
{
	std::sort(items.begin(), items.end());
	std::reverse(items.begin(), items.end());

	SegmentTree segmentTree = SegmentTree(items.size(), bin_capacity);
	std::vector<ClassicBin> result;

	for (auto item : items)
	{
		int position = segmentTree.GetPositionFor(item);
		segmentTree.UpdatePoint(position, -item);

		if (position == result.size())
		{
			result.push_back(ClassicBin(bin_capacity));
		}

		std::cout << "For item " << item << " set position " << position << "\n";

		result[position].addItem(item);
	}

	return result.size();
}
