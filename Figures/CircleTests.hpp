#ifndef __LIST_TESTS_HPP
#define __LIST_TESTS_HPP

#include "doctest.h"
#include <memory>
#include "StringFigureFactory.h"

TEST_CASE("Test circle radius")
{
	IFigureFactory* factory = new StringFigureFactory("circle 4");

	const double PI = 4 * atan(1);

	Figure* circle = factory->createFigure();
	CHECK_EQ(circle->getRepresentativeName(), "circle");
	CHECK(Figure::checkDoublesForEquality(circle->getPerimeter(), 2 * PI * 4));

	factory->recycleFigure(circle);

	delete factory;
}

TEST_CASE("Test cloning triangle")
{
	IFigureFactory* factory = new StringFigureFactory("triangle 4 3 6");
	Figure* triangle = factory->createFigure();

	std::unique_ptr<Figure> clonedTriangle = triangle->clone();

	CHECK(triangle->equals(*clonedTriangle));

	factory->recycleFigure(triangle);
	delete factory;
}

TEST_CASE("Test equal function")
{
	IFigureFactory* factory1 = new StringFigureFactory("triangle 4 3 6");
	IFigureFactory* factory2 = new StringFigureFactory("triangle 6 3 4");
	IFigureFactory* factory3 = new StringFigureFactory("triangle 6 10 4");

	Figure* triangle1 = factory1->createFigure();
	Figure* triangle2 = factory2->createFigure();
	Figure* triangle3 = factory3->createFigure();

	CHECK(triangle1->equals(*triangle2));
	CHECK(triangle1->equals(*triangle3) == false);

	factory1->recycleFigure(triangle1);
	factory2->recycleFigure(triangle2);
	factory3->recycleFigure(triangle3);

	delete factory1;
	delete factory2;
	delete factory3;
}

#endif