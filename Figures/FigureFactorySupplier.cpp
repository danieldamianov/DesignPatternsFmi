#include "FigureFactorySupplier.h"
#include <sstream>
#include <iostream>
#include "StreamFigureFactory.h"

// options for initializing the figures:
// 1 option:STDIN
// 2 option:FILE {fileName}
// 3 option:RANDOM {numberOfFigures}

IFigureFactory* FigureFactorySupplier::getFactory(std::string input)
{
    IFigureFactory* result;

    std::istringstream inputStream(input);
    std::string option;
    inputStream >> option;

    // THINK ABOUT WHO SHOULD CLOSE THE FILE IN THE NEXT OPTIONS!!!
    if (option == "STDIN")
    {
        result = new StreamFigureFactory(std::cin);
    }
}

void FigureFactorySupplier::recycleFactory(IFigureFactory* factory)
{
    delete factory;
}


