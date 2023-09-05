#pragma once

#include <vector>

class SegmentTree
{
	std::vector<int> tree;

public:
	SegmentTree() = default;
	SegmentTree(int size, int default_value);

	void Rebuild(int size, int default_value);

	void UpdatePoint(int position, int value);

	int GetPositionFor(int value);
};

