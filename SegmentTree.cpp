#include "SegmentTree.h"

SegmentTree::SegmentTree(int size, int default_value)
{
	Rebuild(size, default_value);
}

void SegmentTree::Rebuild(int size, int default_value)
{
	int actual_size = 1;
	for (; actual_size < size; actual_size *= 2) {}
	actual_size *= 2;

	tree.clear();
	tree.resize(actual_size, default_value);
}

void SegmentTree::UpdatePoint(int position, int delt)
{
	position += tree.size() / 2;
	tree[position] += delt;
	position /= 2;

	for (; position; position /= 2)
	{
		tree[position] = std::max(tree[position * 2], tree[position * 2 + 1]);
	}

	return;
}

int SegmentTree::GetPositionFor(int value)
{
	int position = 1;

	for (; position < tree.size() / 2;)
	{
		if (tree[position * 2] >= value)
		{
			position = position * 2;
		}
		else
		{
			position = position * 2 + 1;
		}
	}

	return position - tree.size() / 2;
}
