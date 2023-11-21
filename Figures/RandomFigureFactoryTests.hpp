#ifndef __RANDOM_FIGURE_FACTORY_TESTS_HPP
#define __RANDOM_FIGURE_FACTORY_TESTS_HPP

#include "doctest.h"
#include <memory>
#include "StringFigureFactory.h"
#include "FigureFactorySupplier.h"

TEST_CASE("Test circle radius")
{
	const double PI = 4 * atan(1);

	FigureFactorySupplier figureFactorySupplier;

	std::unique_ptr<IFigureFactory> randomFigureFactory = figureFactorySupplier.getFactory("RANDOM");

	int triangleCounter = 0;
	int circleCounter = 0;
	int rectangleCounter = 0;

	double trianglePerimeterSum = 0;
	double circlePerimeterSum = 0;
	double rectanglePerimeterSum = 0;

	for (int i = 0; i < 10000; i++)
	{
		std::unique_ptr<Figure> figure = randomFigureFactory->createFigure();
		std::string figureName = figure->getRepresentativeName();

		if (figureName == "circle")
		{
			circleCounter++;
			circlePerimeterSum += figure->getPerimeter();
		}

		else if (figureName == "triangle")
		{
			triangleCounter++;
			trianglePerimeterSum += figure->getPerimeter();
		}
		else if (figureName == "rectangle")
		{
			rectangleCounter++;
			rectanglePerimeterSum += figure->getPerimeter();
		}
	}

	circlePerimeterSum /= circleCounter;
	trianglePerimeterSum /= triangleCounter;
	rectanglePerimeterSum /= rectangleCounter;

	CHECK(triangleCounter > 3000);
	CHECK(triangleCounter < 4000);
	CHECK(rectangleCounter > 3000);
	CHECK(rectangleCounter < 4000);
	CHECK(circleCounter > 3000);
	CHECK(circleCounter < 4000);

	double expectedAverageCirclePerimeter = 0;

	for (int i = 0; i < 100; i++)
	{
		expectedAverageCirclePerimeter += 2 * PI * i;
	}

	expectedAverageCirclePerimeter /= 100;
	
	//CHECK(circleCounter > 3000 && circleCounter < 4000);
	//CHECK(rectangleCounter > 3000 && rectangleCounter < 4000 );

	CHECK(true);
}

#endif