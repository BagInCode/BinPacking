#pragma once
#include <random>
#include <string>

class BaseRandomGenerator
{
protected:
	std::mt19937 generator;
	int min_value;
	int max_value;

public:
	BaseRandomGenerator();
	BaseRandomGenerator(int _min_value, int _max_value);
	~BaseRandomGenerator();

	virtual void UpdateRange(int _min_value, int _max_value);
	virtual int Generate() { return 0; };
	virtual std::string getName() { return "Base distribution"; };
	virtual std::string getShortName() { return "base"; };
	virtual std::pair<int, int> getRange() { return { min_value, max_value }; };
};

class NormalRandomGenerator : public BaseRandomGenerator
{
	std::normal_distribution<> distribution;

public:
	NormalRandomGenerator();
	NormalRandomGenerator(int _min_value, int _max_value);
	~NormalRandomGenerator();

	void UpdateRange(int _min_value, int _max_value);
	int Generate();
	std::string getName() { return "Normal distribution"; };
	std::string getShortName() { return "normal"; };
};

class UniformRandomGenerator : public BaseRandomGenerator
{
	std::uniform_int_distribution<> distribution;

public:
	UniformRandomGenerator();
	UniformRandomGenerator(int _min_value, int _max_value);
	~UniformRandomGenerator();

	void UpdateRange(int _min_value, int _max_value);
	int Generate();
	std::string getName() { return "Uniform distribution"; };
	std::string getShortName() { return "uniform"; };
};

class ExponentialRandomGenerator : public BaseRandomGenerator
{
	std::exponential_distribution<> distribution;
	bool to_the_min = true;

public:
	ExponentialRandomGenerator();
	ExponentialRandomGenerator(int _min_value, int _max_value, bool _to_the_min);
	~ExponentialRandomGenerator();

	void UpdateRange(int _min_value, int _max_value);
	int Generate();
	std::string getName() { return std::string("Exponential ") + 
								   (to_the_min ? std::string("(to the min)") : std::string("(to the max)")) + 
								   std::string(" distribution"); };
	std::string getShortName() { return std::string("exponential_") + 
		                                (to_the_min ? std::string("to_the_min") : std::string("to_the_max")); };
	std::pair<int, int> getRange() { return{ min_value, max_value }; };
};
