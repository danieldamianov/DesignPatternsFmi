#pragma once
#include "IFigureFactory.h"
#include <istream>

class StreamFigureFactory : public IFigureFactory
{
private:
	std::istream& stream;

public:

	StreamFigureFactory(std::istream& stream) : stream(stream)
	{

	}

	virtual Figure* createFigure() override;
};

