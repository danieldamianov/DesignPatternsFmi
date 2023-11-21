#ifndef __CIRCLE_TESTS_HPP
#define __CIRCLE_TESTS_HPP

#include "doctest.h"
#include <memory>
#include "StringFigureFactory.h"
#include "FigureFactorySupplier.h"

TEST_CASE("Test circle radius")
{
	const double PI = 4 * atan(1);

	std::unique_ptr<IFigureFactory> factory = std::make_unique<StringFigureFactory>("circle 4");
	std::unique_ptr<Figure> circle = factory->createFigure();

	CHECK_EQ(circle->getRepresentativeName(), "circle");
	CHECK(Figure::checkDoublesForEquality(circle->getPerimeter(), 2 * PI * 4));
}

#endif