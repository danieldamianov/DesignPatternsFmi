#pragma once
#include "IFigureFactory.h"
#include <string>
#include <fstream>


static class FigureFactorySupplier
{
private:
	static std::ifstream* fileStream;

public:

	static IFigureFactory* getFactory(std::string input);

	static void recycleFactory(IFigureFactory* factory);
};

