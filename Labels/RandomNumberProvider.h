#pragma once
#include "memory"
#include <random>
#include "IRandomFunctionProvider.h"

class RandomNumberProvider : public IRandomFunctionProvider
{
//public:
	// TODO:: See if it gives compilation error
private:
	static std::shared_ptr<RandomNumberProvider> instance;

	std::random_device dev;
	std::mt19937 rng;

	RandomNumberProvider();
public:
	static std::weak_ptr<RandomNumberProvider> getInstance();

	virtual int getRandomNumberInRange(int minValue, int limit) override;
};
