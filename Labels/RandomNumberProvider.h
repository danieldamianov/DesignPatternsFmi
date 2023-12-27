#pragma once
#include "memory"
#include <random>

class RandomNumberProvider
{
public:
	// TODO:: CHANGE
//private:
	static std::unique_ptr<RandomNumberProvider> instance;

	std::random_device dev;
	std::mt19937 rng;

	RandomNumberProvider();
public:
	static RandomNumberProvider& getInstance();

	int getRandomNumberInRange(int minValue, int limit);
};

