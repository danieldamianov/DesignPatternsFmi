#include "Triangle.h"
#include "TriangleInequalityException.h"

void Triangle::ensureTriangleInequality(double a, double b, double c)
{
	if (a >= b + c || b >= a + c || c >= a + b)
	{
		throw TriangleInequalityException(
			std::string("Tirangle inequality not satisfied! Invalid sides: ")
			+ std::to_string(a)
			+ " "
			+ std::to_string(b)
			+ " "
			+ std::to_string(c));
	}
}

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
