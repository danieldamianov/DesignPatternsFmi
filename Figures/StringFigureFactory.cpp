#include "StringFigureFactory.h"
#include "StreamFigureFactory.h"
#include <sstream>

std::unique_ptr<Figure> StringFigureFactory::createFigure()
{
    // the string stream object is automatically freed at the end of this method
    std::istringstream stream(this->input);

    std::unique_ptr<IFigureFactory> streamFactory = std::make_unique<StreamFigureFactory>(stream);

    std::unique_ptr<Figure> figure = streamFactory->createFigure();

    return figure;
}
