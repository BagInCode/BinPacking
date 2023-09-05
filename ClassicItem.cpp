#include "ClassicItem.h"

ClassicItem::ClassicItem() 
{

}

ClassicItem::ClassicItem(int _weight)
{
	weight = _weight;
}

ClassicItem::~ClassicItem()
{

}

int ClassicItem::Weight()
{
	return weight;
}

void ClassicItem::print(std::ostream& out, bool value_only = true)
{
	if (value_only)
	{
		out << weight;
	}
	else
	{
		out << "Item: " << weight << "\n";
	}

	return;
}
