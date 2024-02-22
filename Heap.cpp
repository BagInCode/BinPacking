#include "Heap.h"

#include <algorithm>
#include <iostream>

Heap::Heap()
{
	heap.push_back({ -1, -1 });
}

void Heap::addBin(std::pair<int, int> bin)
{
	heap.push_back(bin);

	updateBottomTop();
}

std::pair<int, int> Heap::getTop()
{
	if (heap.size() < 2)
	{
		return { -1, -1 };
	}

	return heap[1];
}

void Heap::eraseTop()
{
	if (heap.size() < 2)
	{
		return;
	}

	auto lastElement = heap.back();
	heap[1] = lastElement;
	heap.pop_back();

	updateTopBottom();
}

void Heap::updateTopBottom()
{
	if (heap.size() < 2)
	{
		return;
	}

	int pos = 1;

	for (; pos * 2 < heap.size(); )
	{
		int leftSonCapacity = heap[pos * 2].second;
		int rightSonCapacity = -1;
		if (pos * 2 + 1 < heap.size())
		{
			rightSonCapacity = heap[pos * 2 + 1].second;
		} 

		if (leftSonCapacity > rightSonCapacity && leftSonCapacity > heap[pos].second)
		{
			std::swap(heap[pos], heap[pos * 2]);
			pos *= 2;
		}
		else if (rightSonCapacity > leftSonCapacity && rightSonCapacity > heap[pos].second)
		{
			std::swap(heap[pos], heap[pos * 2 + 1]);
			pos *= 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void Heap::updateBottomTop()
{
	if (heap.size() < 2)
	{
		return;
	}

	int pos = heap.size() - 1;

	for (; pos > 1; pos /= 2)
	{
		if (heap[pos / 2].second < heap[pos].second)
		{
			std::swap(heap[pos / 2], heap[pos]);
		}
		else
		{
			break;
		}
	}
}

void Heap::printHeap()
{
	if (heap.size() < 2)
	{
		std::cout << "\nHeap is empty\n";
	}

	std::cout << "\nHeap size: " << heap.size() - 1 << "\nHeap:\n";

	int step = 1;
	for (int i = 1; i < heap.size(); i++)
	{
		std::cout << "{" << heap[i].first << ", " << heap[i].second << "} ";

		if (i == step)
		{
			std::cout << "\n";
			step = step * 2 + 1;
		}
	}
}