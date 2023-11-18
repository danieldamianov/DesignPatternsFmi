#pragma once
#include "IFigureFactory.h"
#include <string>
#include <fstream>

// TODO:: Change it not to be static!

static class FigureFactorySupplier
{
private:
	static std::ifstream* fileStream;

	static std::string getOption(std::string);

	static std::string getFileName(std::string);
public:

	static IFigureFactory* getFactory(std::string input);

	static void recycleFactory(IFigureFactory* factory);
};

