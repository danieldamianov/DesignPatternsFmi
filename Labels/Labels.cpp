// Figures.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "TextTransformationDecorator.h"
#include "CapitalizeTransformation.h"
#include "LeftTrimTransformation.h"
#include "RichLabel.h"

// Uncomment these lines and comment the main function to execute the unit tests.
/*
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "RichLabelTests.hpp"
*/

int main()
{
	CapitalizeTransformation capitalizeTransformation;
	LeftTrimTransformation leftTrimTransformation;

	// TODO::MAKE SMARTPOINTER!
	// todo:: work in github repo
	Label* richLabel = new RichLabel(Color::Blue , Font::BookmanOldStyle, "     test");
	richLabel = new TextTransformationDecorator(*richLabel, leftTrimTransformation);
	richLabel = new TextTransformationDecorator(*richLabel, capitalizeTransformation);

	std::cout << richLabel->getText() << std::endl;

	// TODO::DELETE THESE
	return 0;
}