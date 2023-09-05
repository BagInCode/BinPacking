#include "ShFFAlgo.h"

#include <algorithm>

#include "SegmentTree.h"

ShFFAlgo::ShFFAlgo(int _shufles_count)
{
	shufles_count = _shufles_count;
}

int ShFFAlgo::Solve(int bin_capacity, std::vector<int>& items)
{
	std::sort(items.begin(), items.end());
	std::reverse(items.begin(), items.end());
	
	int optimal_result = items.size();

	for (int iteration = 0; iteration < shufles_count; iteration++)
	{
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

			result[position].addItem(item);
		}

		optimal_result = std::min(optimal_result, (int)result.size());
		std::random_shuffle(items.begin(), items.end());
	}

	return optimal_result;
}
