#include "ClassicBin.h"

ClassicBin::ClassicBin()
{

}

ClassicBin::ClassicBin(int _capacity)
{
	capacity = _capacity;
}

bool ClassicBin::addItem(int item)
{
	if (item > capacity)
	{
		return false;
	}

	items.push_back(item);
	capacity -= item;
	return true;
}

void ClassicBin::print(std::ostream& out, bool value_only = true)
{
	if (value_only)
	{
		out << "[ ";

		for (size_t i = 0; i < items.size(); i++)
		{
			out << items[i] << " ";
		}

		out << "]";
	}
	else
	{
		out << "Bin: [\n";

		for (size_t i = 0; i < items.size(); i++)
		{
			out << "Item: " << items[i] << "\n";
		}

		out << "]\n";
	}
}
