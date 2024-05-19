#include "AShFFAlgo.h"

#include <algorithm>

#include "SegmentTree.h"

AShFFAlgo::AShFFAlgo(int _shufles_count)
{
	shufles_count = _shufles_count;
}

int AShFFAlgo::Solve(int bin_capacity, std::vector<int>& items)
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

		optimal_result = std::min(optimal_result, (int)result.size());
		std::random_shuffle(items.begin(), items.end());
	}

	return optimal_result;
}
