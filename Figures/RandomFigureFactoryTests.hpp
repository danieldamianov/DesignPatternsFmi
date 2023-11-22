#ifndef __RANDOM_FIGURE_FACTORY_TESTS_HPP
#define __RANDOM_FIGURE_FACTORY_TESTS_HPP

#include "doctest.h"
// TODO:: make my min and max
#include <algorithm>
#include <memory>
#include "StringFigureFactory.h"
#include "FigureFactorySupplier.h"

TEST_CASE("Test random factory")
{
	const double PI = 4 * atan(1);

	FigureFactorySupplier figureFactorySupplier;

	std::unique_ptr<IFigureFactory> randomFigureFactory = figureFactorySupplier.getFactory("RANDOM");

	int triangleCounter = 0;
	int circleCounter = 0;
	int rectangleCounter = 0;

	double trianglePerimeterAverage = 0;
	double circlePerimeterAverage = 0;
	double rectanglePerimeterAverage = 0;

	for (int i = 0; i < 100000; i++)
	{
		std::unique_ptr<Figure> figure = randomFigureFactory->createFigure();
		std::string figureName = figure->getRepresentativeName();

		if (figureName == "circle")
		{
			circleCounter++;
			circlePerimeterAverage += figure->getPerimeter();
		}

		else if (figureName == "triangle")
		{
			triangleCounter++;
			trianglePerimeterAverage += figure->getPerimeter();
		}
		else if (figureName == "rectangle")
		{
			rectangleCounter++;
			rectanglePerimeterAverage += figure->getPerimeter();
		}
	}

	circlePerimeterAverage /= circleCounter;
	trianglePerimeterAverage /= triangleCounter;
	rectanglePerimeterAverage /= rectangleCounter;

	CHECK(triangleCounter > 32000);
	CHECK(triangleCounter < 35000);
	CHECK(rectangleCounter > 32000);
	CHECK(rectangleCounter < 35000);
	CHECK(circleCounter > 32000);
	CHECK(circleCounter < 35000);

	double const avgFrom1To100 = 50.5;
	double expectedAverageCirclePerimeter = avgFrom1To100 * 2 * PI;
	double expectedAverageRectanglePerimeter = avgFrom1To100 * 4;

	double thirdSidesAverage = 0;


	for (int i = 1; i <= 100; i++)
	{
		for (int j = 1; j <= 100; j++)
		{
			thirdSidesAverage += (std::max((abs(i - j) + 1), 1) + std::min((i + j - 1), 100)) / 2.0;
		}
	}

	thirdSidesAverage /= 10000;
	double expectedtrianglePerimeter = thirdSidesAverage + avgFrom1To100 * 2;

	CHECK(circlePerimeterAverage > expectedAverageCirclePerimeter - 3);
	CHECK(circlePerimeterAverage < expectedAverageCirclePerimeter + 3);

	CHECK(trianglePerimeterAverage > expectedtrianglePerimeter - 3);
	CHECK(trianglePerimeterAverage < expectedtrianglePerimeter + 3);

	CHECK(rectanglePerimeterAverage > expectedAverageRectanglePerimeter - 3);
	CHECK(rectanglePerimeterAverage < expectedAverageRectanglePerimeter + 3);
}

#endif