#pragma once
#include "IFigureFactory.h"

class RandomFigureFactory : public IFigureFactory
{
private:
	static const int minSizeOfParameters;
	static const int maxSizeOfParameters;

    int getRandomNumberFromOneToLimit(int limit);
public:

	virtual Figure* createFigure() override;

};

