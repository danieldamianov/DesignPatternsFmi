#pragma once
#include "Figure.h"

class IFigureFactory
{
protected:
	// TODO :: CHECK FOR NERAVENSTVO NA TRIAGALNIKA

public:
	virtual Figure* createFigure() = 0;

	// TODO: CHECK IN ALL PLACES OF CODE IF I RECYCLE ALL THE FIGURES!!!!
	void recycleFigure(Figure* figure);

	virtual ~IFigureFactory() { }
};

