#pragma once
#include "IFigureFactory.h"

class StringFigureFactory : public IFigureFactory
{
private:
	std::string input;

public:
	StringFigureFactory(std::string input) : input(input)
	{

	}

	virtual Figure* createFigure() override;
};

