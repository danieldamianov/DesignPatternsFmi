#pragma once
#include "Figure.h"

class IFigureFactory
{
protected:
	mutable int* a;
	// TODO :: CHECK FOR NERAVENSTVO NA TRIAGALNIKA


	IFigureFactory()
	{
		(*this).a = new int[10000];
	}

public:
	virtual Figure* createFigure() = 0;

	// TODO: CHECK IN ALL PLACES OF CODE IF I RECYCLE ALL THE FIGURES!!!!
	void recycleFigure(Figure* figure);

	virtual ~IFigureFactory() { delete[] a; };
};

