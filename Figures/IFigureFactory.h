#pragma once
#include "Figure.h"

class IFigureFactory
{
protected:

	static bool validateInput(std::string input);

public:
	virtual std::unique_ptr<Figure> createFigure() = 0;

	virtual ~IFigureFactory() { }
};

