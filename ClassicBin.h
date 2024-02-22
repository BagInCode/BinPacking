#pragma once

#include <vector>
#include <iostream>

class ClassicBin
{
	int capacity = 0;
	std::vector<int> items;

public:
	ClassicBin();
	ClassicBin(int _capacity);

	bool addItem(int item);

	void print(std::ostream& out, bool value_only);

	int getCapacity();

};

