#pragma once
#include <iostream>
#include <fstream>

class ClassicItem
{
	int weight = 0;

public:
	ClassicItem();
	ClassicItem(int _weight);

	~ClassicItem();

	int Weight();

	void print(std::ostream& out, bool value_only);
};

