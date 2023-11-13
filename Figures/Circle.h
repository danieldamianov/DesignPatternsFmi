#pragma once
#include "Figure.h"
#include <cmath>
#include <memory>

class Circle : public Figure
{
private:
	static const double PI;

public:
	Circle(double radius)
	{
		this->representativeName = "circle";
		this->parameters.push_back(radius);
		sortParameters();
	}

	virtual double getPerimeter() const override;

	virtual std::unique_ptr<Figure> clone() const override;

	double getRadius() const;
};

