#ifndef __RECTANGLE_TESTS_HPP
#define __RECTANGLE_TESTS_HPP

#include "doctest.h"
#include <memory>
#include "StringFigureFactory.h"
#include "NonPositiveParameterException.h"

TEST_CASE("Test rectangle for valid parameters. ")
{
	std::unique_ptr<IFigureFactory> factory1 = std::make_unique<StringFigureFactory>("rectangle 1 2");
	std::unique_ptr<IFigureFactory> factory2 = std::make_unique<StringFigureFactory>("rectangle 0 2");
	std::unique_ptr<IFigureFactory> factory3 = std::make_unique<StringFigureFactory>("rectangle 1 0");
	std::unique_ptr<IFigureFactory> factory4 = std::make_unique<StringFigureFactory>("rectangle -1 2");
	std::unique_ptr<IFigureFactory> factory5 = std::make_unique<StringFigureFactory>("rectangle 1 -2");
	std::unique_ptr<IFigureFactory> factory6 = std::make_unique<StringFigureFactory>("rectangle -1 -2");
	std::unique_ptr<IFigureFactory> factory7 = std::make_unique<StringFigureFactory>("rectangle 0 0");

	REQUIRE_NOTHROW(factory1->createFigure());
	REQUIRE_THROWS_AS(factory2->createFigure(), NonPositiveParameterException);
	REQUIRE_THROWS_AS(factory3->createFigure(), NonPositiveParameterException);
	CHECK(factory4->createFigure() == nullptr);
	CHECK(factory5->createFigure() == nullptr);
	CHECK(factory6->createFigure() == nullptr);
	REQUIRE_THROWS_AS(factory7->createFigure(), NonPositiveParameterException);
}

#endif