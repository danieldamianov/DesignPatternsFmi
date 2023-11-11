#include "Triangle.h"

double Triangle::getPerimeter() const
{
	return this->getA() + this->getB() + this->getC();
}

std::unique_ptr<Figure> Triangle::clone() const
{
	return std::unique_ptr<Triangle>(new Triangle(this->getA(), this->getB(), this->getC()));
}

double Triangle::getA() const
{
	return this->parameters[0];
}

double Triangle::getB() const
{
	return this->parameters[1];
}

double Triangle::getC() const
{
	return this->parameters[2];
}
