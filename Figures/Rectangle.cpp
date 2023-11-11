#include "Rectangle.h"
#include "memory"

double Rectangle::getPerimeter() const
{
	return this->getX() + this->getY();
}

std::unique_ptr<Figure> Rectangle::clone() const
{
	return std::unique_ptr<Rectangle>(new Rectangle(this->getX(), this->getY()));
}

double Rectangle::getX() const
{
	return this->parameters[0];
}

double Rectangle::getY() const
{
	return this->parameters[1];
}
