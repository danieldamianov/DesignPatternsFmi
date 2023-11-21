#ifndef __TRIANGLE_TESTS_HPP
#define __TRIANGLE_TESTS_HPP

#include "doctest.h"
#include <memory>
#include "StringFigureFactory.h"
#include "FigureFactorySupplier.h"

TEST_CASE("Test cloning triangle")
{
	std::unique_ptr<IFigureFactory> factory = std::make_unique<StringFigureFactory>("triangle 4 3 6");
	std::unique_ptr<Figure> triangle = factory->createFigure();
	std::unique_ptr<Figure> clonedTriangle = triangle->clone();

	CHECK(triangle->equals(*clonedTriangle));
}

TEST_CASE("Test equal function")
{
	std::unique_ptr<IFigureFactory> factory1 = std::make_unique<StringFigureFactory>("triangle 4 3 6");
	std::unique_ptr<IFigureFactory> factory2 = std::make_unique<StringFigureFactory>("triangle 6 3 4");
	std::unique_ptr<IFigureFactory> factory3 = std::make_unique<StringFigureFactory>("triangle 6 9 4");

	std::unique_ptr<Figure> triangle1 = factory1->createFigure();
	std::unique_ptr<Figure> triangle2 = factory2->createFigure();
	std::unique_ptr<Figure> triangle3 = factory3->createFigure();

	CHECK(triangle1->equals(*triangle2));
	CHECK(triangle1->equals(*triangle3) == false);
}

#endif