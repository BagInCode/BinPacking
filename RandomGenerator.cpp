#include "RandomGenerator.h"

BaseRandomGenerator::BaseRandomGenerator()
{

}

BaseRandomGenerator::BaseRandomGenerator(int _min_value, int _max_value)
{
	min_value = _min_value;
	max_value = _max_value;
}

BaseRandomGenerator::~BaseRandomGenerator()
{

}

void BaseRandomGenerator::UpdateRange(int _min_value, int _max_value)
{
	min_value = _min_value;
	max_value = _max_value;
}


/// NormalRandomGenerator 

NormalRandomGenerator::NormalRandomGenerator()
{
	min_value = 0;
	max_value = 10;
	distribution = std::normal_distribution<>((min_value + max_value) / 2, (max_value - min_value) / 5);	
}

NormalRandomGenerator::NormalRandomGenerator(int _min_value, int _max_value)
{
	distribution = std::normal_distribution<>((_min_value + _max_value) / 2, (_max_value - _min_value) / 5);
	min_value = _min_value;
	max_value = _max_value;
}

NormalRandomGenerator::~NormalRandomGenerator()
{

}

void NormalRandomGenerator::UpdateRange(int _min_value, int _max_value)
{
	distribution = std::normal_distribution<>((_min_value + _max_value) / 2., (_max_value - _min_value) / 5.);
	min_value = _min_value;
	max_value = _max_value;
}

int NormalRandomGenerator::Generate()
{
	while (true)
	{
		int number = std::round(distribution(generator));

		if (number >= min_value && number <= max_value)
		{
			return number;
		}
	}
}

/// UniformRandomGenerator

UniformRandomGenerator::UniformRandomGenerator()
{
	min_value = 0;
	max_value = 10;
	distribution = std::uniform_int_distribution<>(min_value, max_value);
}

UniformRandomGenerator::UniformRandomGenerator(int _min_value, int _max_value)
{
	distribution = std::uniform_int_distribution<>(_min_value, _max_value);
	min_value = _min_value;
	max_value = _max_value;
}

UniformRandomGenerator::~UniformRandomGenerator()
{

}

void UniformRandomGenerator::UpdateRange(int _min_value, int _max_value)
{
	distribution = std::uniform_int_distribution<>(_min_value, _max_value);
	min_value = _min_value;
	max_value = _max_value;
}

int UniformRandomGenerator::Generate()
{
	return distribution(generator);
}

/// ExponentialRandomGenerator

ExponentialRandomGenerator::ExponentialRandomGenerator()
{
	min_value = 0;
	max_value = 11;
	distribution = std::exponential_distribution<>(1);
}

ExponentialRandomGenerator::ExponentialRandomGenerator(int _min_value, int _max_value, bool _to_the_min = true)
{
	distribution = std::exponential_distribution<>(1);
	min_value = _min_value;
	max_value = _max_value;
	to_the_min = _to_the_min;
}

ExponentialRandomGenerator::~ExponentialRandomGenerator()
{

}

void ExponentialRandomGenerator::UpdateRange(int _min_value, int _max_value)
{
	distribution = std::exponential_distribution<>(1);
	min_value = _min_value;
	max_value = _max_value;
}

int ExponentialRandomGenerator::Generate()
{
	while (true)
	{
		double number = 5;
		
		while (number > 4)
		{
			number = distribution(generator);
		}

		if (!to_the_min)
		{
			number = 4 - number;
		}

		int result = int(number / 4. * (max_value - min_value + 1)) + min_value;

		if (min_value <= result && result <= max_value)
		{
			return result;
		}
	}
}
