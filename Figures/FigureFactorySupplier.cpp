#include "FigureFactorySupplier.h"
#include <sstream>
#include <iostream>
#include <fstream>
#include <memory>
#include "StreamFigureFactory.h"
#include "RandomFigureFactory.h"

// options for initializing the figures:
// 1 option:STDIN
// 2 option:FILE {fileName}
// 3 option:RANDOM

std::unique_ptr<IFigureFactory> FigureFactorySupplier::getFactory(std::string input)
{
	std::string option = getOption(input);

	if (option == "STDIN")
	{
		return std::make_unique<StreamFigureFactory>(std::cin);
	}
	else if (option == "FILE")
	{
		std::string fileName = getFileName(input);
		std::unique_ptr<std::ifstream> ptr = std::make_unique<std::ifstream>(fileName);
		
		return std::make_unique<StreamFigureFactory>((std::move(ptr)));
	}
	else if (option == "RANDOM")
	{
		return std::make_unique<RandomFigureFactory>();
	}

	return nullptr;
}

std::string FigureFactorySupplier::getOption(std::string input)
{
	size_t spacePos = input.find(' ');
	return (spacePos != std::string::npos) ? input.substr(0, spacePos) : input;
}

std::string FigureFactorySupplier::getFileName(std::string input)
{
	size_t spacePos = input.find(' ');
	std::string secondHalf = input.substr(spacePos + 1);

	return secondHalf;
}

