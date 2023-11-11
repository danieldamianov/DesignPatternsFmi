#include "StreamFigureFactory.h"
#include "InvalidFigureTypeException.h"
#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"

// TODO :: add validation of the int parameters!
Figure* StreamFigureFactory::createFigure()
{
    Figure* figure = nullptr;
    std::string figureType;

    this->stream >> figureType;

    if (figureType == "circle")
    {
        int radius;

        this->stream >> radius;

        figure = new Circle(radius);
    }
    else if (figureType == "rectangle")
    {
        int a;
        int b;

        this->stream >> a >> b;
        figure = new Rectangle(a, b);
    }
    else if (figureType == "triangle")
    {
        int x;
        int y;
        int z;

        this->stream >> x >> y >> z;
        figure = new Triangle(x, y, z);
    }
    else // THINK AGAIN IF THIS IS THE PROPER INPLEMENTATION!
    {
        throw new InvalidFigureTypeException("Stream provided an invalid figure type!");
    }

    return figure;
}
