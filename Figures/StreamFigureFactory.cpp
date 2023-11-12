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
        double radius;

        this->stream >> radius;

        figure = new Circle(radius);
    }
    else if (figureType == "rectangle")
    {
        double a;
        double b;

        this->stream >> a >> b;
        figure = new Rectangle(a, b);
    }
    else if (figureType == "triangle")
    {
        double x;
        double y;
        double z;

        this->stream >> x >> y >> z;
        figure = new Triangle(x, y, z);
    }
    else // THINK AGAIN IF THIS IS THE PROPER INPLEMENTATION!
    {
        throw InvalidFigureTypeException("Stream provided an invalid figure type!");
    }

    return figure;
}
