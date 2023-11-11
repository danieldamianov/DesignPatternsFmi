#pragma once
#include "IFigureFactory.h"

class RandomFigureFactory : public IFigureFactory
{
	virtual Figure* createFigure() override;

    int getRandomNumberFromOneToLimit(int limit);
};

