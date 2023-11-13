#pragma once
#include "Figure.h"
#include <memory>

class Triangle : public Figure
{

public:
	Triangle(double a, double b, double c)
	{
		this->representativeName = "triangle";
		this->parameters.push_back(a);
		this->parameters.push_back(b);
		this->parameters.push_back(c);
		sortParameters();
	}

	virtual double getPerimeter() const override;
	virtual std::unique_ptr<Figure> clone() const override;
	double getA() const;
	double getB() const;
	double getC() const;
};

