#pragma once
#include "IFigureFactory.h"
#include <string>

static class FigureFactorySupplier
{
	static IFigureFactory* getFactory(std::string input);

	static void recycleFactory(IFigureFactory* factory);
};

