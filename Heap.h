#pragma once

#include <vector>

class Heap
{
	//                    pos, cap
	std::vector<std::pair<int, int>> heap;

public:
	Heap();

	void addBin(std::pair<int, int> bin);
	
	std::pair<int, int> getTop();
	
	void eraseTop();

	void printHeap();

private: 
	void updateTopBottom();
	void updateBottomTop();
};

