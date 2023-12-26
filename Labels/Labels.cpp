// Figures.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "TextTransformationDecoratorBase.h"
#include "TextTransformationDecoratorMovedObject.h"
#include "TextTransformationDecoratorSharedObject.h"
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
	std::unique_ptr<TextTransformation> capitalizeTransformation
		= std::make_unique<CapitalizeTransformation>();
	std::unique_ptr<TextTransformation> leftTrimTransformation
		= std::make_unique<LeftTrimTransformation>();

	// TODO::MAKE SMARTPOINTER!
	// todo:: work in github repo
	std::shared_ptr<Label> richLabel = std::make_shared<RichLabel>
		(Color::Blue, Font::BookmanOldStyle, "     test");

	if (true)
	{
		std::unique_ptr<Label> decorator = std::make_unique<TextTransformationDecoratorSharedObject>
			(richLabel, std::move(leftTrimTransformation));

		decorator = std::make_unique<TextTransformationDecoratorMovedObject>
			(std::move(decorator), std::move(capitalizeTransformation));

		std::cout << decorator->getText() << std::endl;
	}
	std::cout << richLabel->getText(); // should print "    test"
	// TODO::DELETE THESE
	return 0;
}