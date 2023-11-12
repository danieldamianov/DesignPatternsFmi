#include "FigureFactorySupplier.h"
#include <sstream>
#include <iostream>
#include <fstream>
#include "StreamFigureFactory.h"
#include "RandomFigureFactory.h"

// options for initializing the figures:
// 1 option:STDIN
// 2 option:FILE {fileName}
// 3 option:RANDOM {numberOfFigures}

std::ifstream* FigureFactorySupplier::fileStream = nullptr;

// if the input option is Invalid, nullptr will be returned!!!
// TODO:: CHeck for this!!!
IFigureFactory* FigureFactorySupplier::getFactory(std::string input)
{
    IFigureFactory* result = nullptr;

    std::istringstream inputStream(input);
    std::string option;
    inputStream >> option;

    // THINK ABOUT WHO SHOULD CLOSE THE FILE IN THE NEXT OPTIONS!!!
    if (option == "STDIN")
    {
        result = new StreamFigureFactory(std::cin);
    }
    else if (option == "FILE")
    {
        std::string fileName;
        inputStream >> fileName;

        // This will be closed in the recycle factory method!
        fileStream = new std::ifstream(fileName);

        result = new StreamFigureFactory(*fileStream);
    } 
    else if (option == "RANDOM")
    {
        result = new RandomFigureFactory();
    }

    return result;
}

// TODO:: This should ALWAYS BE CALLED
void FigureFactorySupplier::recycleFactory(IFigureFactory* factory)
{
    if (fileStream != nullptr)
    {
        fileStream->close();
        delete fileStream;
    }

    delete factory;
}


