#include "StupidSolution.h"

#include "FFAlgo.h"

int StupidSolution::Factorial(int n)
{
	int result = 1;
	for (; n > 1; result *= n--) {};

	return result;
}

void StupidSolution::GenerateOrder(int order_id, std::vector<int> base_order, std::vector<int>& result)
{
	result.clear();

	int fact = Factorial(base_order.size() - 1);

	for (int i = base_order.size() - 1; i; i--)
	{
		int pos = order_id / fact;
		order_id %= fact;
		fact /= i;

		result.push_back(base_order[pos]);
		base_order.erase(base_order.begin() + pos);
	}

	result.push_back(base_order[0]);

	return;
}

int StupidSolution::Solve(int bin_capacity, std::vector<int>& items)
{
	int count_orders = Factorial(items.size());
	FFAlgo solver = FFAlgo();
	int result = items.size();

	int total_weight = 0;
	for (auto item : items)
	{
		total_weight += item;
	}

	int ever_best = total_weight / bin_capacity + (total_weight % bin_capacity ? 1 : 0);

	for (int i = 0; i < count_orders; i++)
	{
		std::vector <int> order;
		GenerateOrder(i, items, order);

		result = std::min(result, solver.Solve(bin_capacity, order));

		if (result == ever_best)
		{
			return result;
		}
	}

	return result;
}
