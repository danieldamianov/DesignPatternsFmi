#pragma once
#include "IFigureFactory.h"
#include <random>

class RandomFigureFactory : public IFigureFactory
{
private:
	static const int minSizeOfParameters;
	static const int maxSizeOfParameters;
	static int max(int a, int b);
	static int min(int a, int b);

	std::random_device dev;
	std::mt19937 rng;

    int getRandomNumberInRange(int minValue, int limit);

public:

	RandomFigureFactory() : rng(dev())
	{ }

	virtual std::unique_ptr<Figure> createFigure() override;

};

