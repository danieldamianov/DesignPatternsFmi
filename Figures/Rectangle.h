#pragma once
#include "Figure.h"
#include <memory>

class Rectangle : public Figure
{
public:
	Rectangle(double x, double y)
	{
		this->representativeName = "rectangle";
		this->parameters.push_back(x);
		this->parameters.push_back(y);
		sortParameters();
	}

	virtual double getPerimeter() const override;
	virtual std::unique_ptr<Figure> clone() const override;
	double getX() const;
	double getY() const;
};

