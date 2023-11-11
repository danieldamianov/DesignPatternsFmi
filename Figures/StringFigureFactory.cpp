#include "StringFigureFactory.h"
#include "StreamFigureFactory.h"
#include <sstream>

Figure* StringFigureFactory::createFigure()
{
    // the string stream object is automatically freed at the end of this method
    std::istringstream stream(this->input);

    IFigureFactory* streamFactory = new StreamFigureFactory(stream);

    Figure* figure = streamFactory->createFigure();

    delete streamFactory;

    // the recycle method of the StringFigureFactory should be caled in order to delete the created figure
    return figure;
}
