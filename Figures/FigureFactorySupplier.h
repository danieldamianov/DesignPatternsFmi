#pragma once
#include "IFigureFactory.h"
#include <string>
#include <fstream>

class FigureFactorySupplier
{
private:
	static std::string getOption(std::string);

	static std::string getFileName(std::string);
public:

	std::unique_ptr<IFigureFactory> getFactory(std::string input);
};

