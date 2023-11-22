#ifndef __STREAM_FIGURE_FACTORY_TESTS_HPP
#define __STREAM_FIGURE_FACTORY_TESTS_HPP

#include "doctest.h"
#include <iostream>
#include <sstream>
#include <memory>
#include "StreamFigureFactory.h"

TEST_CASE("Test stream factory")
{
	std::string testString = std::string("circle 5") + "\n" +
		std::string("triangle 5 6 7") + "\n" +
		std::string("rectangle 5 4") + "\n" +
		std::string("circle 9") + "\n" +
		std::string("triangle 9 8 7") + "\n" +
		std::string("rectangle 5 2") + "\n";

	std::unique_ptr<std::istream> stream = std::make_unique<std::istringstream>(testString);

	std::vector<std::unique_ptr<Figure>> figures;

	std::unique_ptr<StreamFigureFactory> streamFigureFactory = std::make_unique<StreamFigureFactory>(std::move(stream));

	for (int i = 0; i < 6; i++)
	{
		std::unique_ptr<Figure> figure = streamFigureFactory->createFigure();

		figures.push_back(std::move(figure));
	}

	std::string result;

	std::string expectedResult = std::string("circle 5.000000") + "\n" +
		std::string("triangle 5.000000 6.000000 7.000000") + "\n" +
		std::string("rectangle 4.000000 5.000000") + "\n" +
		std::string("circle 9.000000") + "\n" +
		std::string("triangle 7.000000 8.000000 9.000000") + "\n" +
		std::string("rectangle 2.000000 5.000000") + "\n";

	for (int i = 0; i < 6; i++)
	{
		result += figures[i]->toString();
		result += '\n';
	}

	CHECK(result == expectedResult);
}

/*circlePerimeterAverage /= circleCounter;
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
*///CHECK(rectanglePerimeterAverage < expectedAverageRectanglePerimeter + 3);

#endif
