#include "Circle.h"
#include <memory>

const double Circle::PI = 4 * atan(1);

double Circle::getPerimeter() const
{
    return 2 * PI * this->getRadius();
}

std::unique_ptr<Figure> Circle::clone() const
{
    return std::make_unique<Circle>(this->getRadius());
}

double Circle::getRadius() const
{
    return this->parameters[0];
}

