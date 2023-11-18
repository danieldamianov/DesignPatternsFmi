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

//std::ifstream* FigureFactorySupplier::fileStream = nullptr;

// if the input option is Invalid, nullptr will be returned!!!
// TODO:: CHeck for this!!!
IFigureFactory* FigureFactorySupplier::getFactory(std::string input)
{
	// TODO ADD THIS VALIDATION TOO!!!!
	/*if (validInput(input) == false)
	{
		return nullptr;
	}*/

	IFigureFactory* result = nullptr;

	std::string option = getOption(input);

	// THINK ABOUT WHO SHOULD CLOSE THE FILE IN THE NEXT OPTIONS!!!
	if (option == "STDIN")
	{
		result = new StreamFigureFactory(std::cin);
	}
	else if (option == "FILE")
	{
		std::string fileName = getFileName(input);

		// This will be closed in the recycle factory method!
		std::unique_ptr<std::ifstream> fileStream = std::make_unique<std::ifstream>(new std::ifstream(fileName));

		result = new StreamFigureFactory(std::move(fileStream));
	}
	else if (option == "RANDOM")
	{
		result = new RandomFigureFactory();
	}

	return result;
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

// TODO:: This should ALWAYS BE CALLED
void FigureFactorySupplier::recycleFactory(IFigureFactory* factory)
{
	if (fileStream != nullptr)
	{
		fileStream->close();
		delete fileStream;
	}

	fileStream = nullptr;

	delete factory;
}


